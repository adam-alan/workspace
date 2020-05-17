//
// Created by zhuxingtian on 19-10-14.
//

#include "Log.h"
#include <cstdlib>
#include <unistd.h>
#include <string.h>
#include <cstdio>
#include <stdarg.h>
#include <iostream>

namespace lodestar{
    #define MAX_LINE_LENGTH 256
    #define DEFAULT_ROLL_SIZE 10*1024*1024


    class TimeStamp;
    LogFileManager::LogFileManager():
    mLogFileName(),
    mLogFile(nullptr),
    mMaxLogFileSize(DEFAULT_ROLL_SIZE),
    mWritentoFileSize(0),
    mIsToFile(false)
    {
    }
    LogFileManager::~LogFileManager() {
        this->unInit();
    }
    void LogFileManager::init(std::string logFileName,FILE * logFile,int64_t maxLogFileSize) {
        if (not logFileName.empty()) {

            this->mIsToFile = true;
            this->mLogFileName = logFileName;
            this->mMaxLogFileSize = maxLogFileSize;
            if (not this->createNewFile()) {
                perror("fopen");
                return;
            }
        }
    }
    void LogFileManager::unInit() {
        this->closeLogFile();
    }

    bool LogFileManager::createNewFile() {
        if (mLogFile != nullptr) {
            ::fclose(mLogFile);
        }
        TimeStamp now = TimeStamp::now();
        std::string timeString{now.toFormatedString(false)};
        std::string newFileName{"." + timeString + "." + mLogFileName + ".log"};
        mLogFile = ::fopen(newFileName.c_str(),"w+");
        return mLogFile != nullptr;
    }

    bool LogFileManager::writeToFile(const std::string &data) {


        if (mIsToFile != false and mLogFile != nullptr) {

            if (this->mWritentoFileSize >= this->mMaxLogFileSize) {
                if (not createNewFile()) {
                    return false;
                }
            }
            std::string localData{data};
            int ret{0};

            while (true) {

                ret = ::fwrite(localData.data(), sizeof(char),1,mLogFile);
                if (ret < 0) {
                    return false;
                } else if (ret <= localData.size()){
                    localData.erase(0,ret);
                }
                if (localData.size() == 0) {
                    break;
                }
            }
            ::fflush(mLogFile);
        } else {

            std::string localData{data};
            int ret{0};

            while (true) {
                ret = ::fwrite(localData.c_str(), 1,localData.size(),stdout);
                if (ret < 0) {
                    return false;
                } else if (ret <= localData.size()){
                    localData.erase(0,ret);
                }
                if (localData.size() == 0) {
                    break;
                }
            }
            ::fflush(stdout);
        }
        return true;
    }

    bool LogFileManager::hasLogFile() {
        return mLogFile != nullptr;
    }

    void LogFileManager::closeLogFile() {
        ::fclose(mLogFile);
    }


    std::unique_ptr<LogFileManager> Logger::mLogFileManager = std::make_unique<LogFileManager>();
    bool Logger::mIsRunning = false;
    bool Logger::mIsTruncateLongLog = false;

    std::unique_ptr<std::thread> Logger::mWriteThread;
    BlockQuene<std::string> Logger::blockQuene;

    void Logger::init(const std::string logFileName = "",bool truncateLongLog = false, int maxLogFileSize = DEFAULT_ROLL_SIZE)
    {
        if (not logFileName.empty()) {
            mLogFileManager->init(logFileName, nullptr,maxLogFileSize);
        }
        mWriteThread = std::make_unique<std::thread>(writeThreadFunc);
    }

    void Logger::unInit() {
        mWriteThread->join();
    }


    bool Logger::getIsRunning() {
        return mIsRunning;
    }



    void Logger::makeLinePreFix(lodestar::LogLevel logLevel,std::string & preFix) {
        TimeStamp now(TimeStamp::now());
        auto timeString = now.toFormatedString(false);
        preFix += "[" + timeString + "] ";

        std::ostringstream osThreadID;
        osThreadID << mWriteThread->get_id();
        std::string threadIDString{osThreadID.str().c_str()};

        preFix += "[" + threadIDString + "] ";
        switch (logLevel) {
            case LogLevel::LOG_LEVEL_TRACE:
                preFix += "[TRACE] ";
                break;
            case LogLevel::LOG_LEVEL_DEBUG:
                preFix += "[DEBUG] ";
                break;
            case LogLevel::LOG_LEVEL_INFO:
                preFix += "[INFO] ";
                break;
            case LogLevel::LOG_LEVEL_WARNING:
                preFix += "[WARNING] ";
                break;
            case LogLevel::LOG_LEVEL_ERROR:
                preFix += "[ERROR] ";
                break;
            case LogLevel::LOG_LEVEL_FATAL:
                preFix += "[FATAL] ";
                break;
            case LogLevel::LOG_LEVEL_SYSERROR:
                preFix += "[SYSERROR] ";
                break;
            case LogLevel::LOG_LEVEL_CRITICAL:
                preFix += "[CRITICAL] ";
                break;
        }

    }

    void Logger::writeThreadFunc() {
        mIsRunning = true;
        while (true) {
            std::string line{blockQuene.get()};
            if (!mLogFileManager->writeToFile(line)) {
                perror("fwrite");
                break;
            }
        }
        mIsRunning = false;
    }
    bool Logger::output(LogLevel logLevel, const std::string funcName, int lineNo, const char *fmt, ...) {

        std::string prelogContent;
        makeLinePreFix(logLevel,prelogContent);

        //std::cout << prelogContent << std::endl;
        std::string logContent;
        va_list ap;
        va_start(ap,fmt);
        int logMsgLength = vsnprintf(nullptr,0,fmt,ap);
        va_end(ap);

        if (static_cast<int>(logContent.capacity()) <= logMsgLength + 1) {
            logContent.resize(logMsgLength + 1);
        }

        va_list aq;
        va_start(aq,fmt);
        vsnprintf((char*)logContent.data(),logContent.capacity(),fmt,aq);
        va_end(aq);

        std::string logContentFormal;
        logContent.append(logContent.c_str(),logMsgLength);
        if (mIsTruncateLongLog) {
            logContent.substr(0,MAX_LINE_LENGTH);
        }

        logContent = prelogContent + logContent;
        logContent += " [" + funcName + ":" + std::to_string(lineNo) + "]";
        logContent += '\n';

        //std::cout << logContent << std::endl;


        blockQuene.put(logContent);

        if (logLevel == LogLevel::LOG_LEVEL_FATAL) {
            std::cout << logContent << std::endl;
            exit(-1);
        }
        return true;
    }

    bool Logger::outputBinary(unsigned char *buffer, size_t size) {
        std::ostringstream os;
        static const size_t PRINTSIZE = 512;
        char sizeBuf[PRINTSIZE * 3 + 8];

        size_t lSize(0);
        size_t lPrintBufSize(0);
        int index(0);

        os << "address[" << buffer << "] size[" << size << "] \n";
        while (true) {
            memset(sizeBuf,0, sizeof(sizeBuf));
            if (size > lSize) {
                lPrintBufSize = (size - lSize);
                lPrintBufSize = (lPrintBufSize > PRINTSIZE) ? PRINTSIZE :lPrintBufSize;

            }
        }
    }
}
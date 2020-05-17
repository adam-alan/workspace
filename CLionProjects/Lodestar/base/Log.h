//
// Created by zhuxingtian on 19-10-14.
//

#ifndef LODESTAR_LOG_H
#define LODESTAR_LOG_H

#include <string>
#include <cstdio>
#include <thread>
#include <mutex>
#include <list>
#include <condition_variable>
#include <sstream>
#include "BlockQuene.h"
#include "NoCopyable.h"
namespace lodestar {

    enum class LogLevel {
        LOG_LEVEL_TRACE,
        LOG_LEVEL_DEBUG,
        LOG_LEVEL_INFO,
        LOG_LEVEL_WARNING,
        LOG_LEVEL_ERROR,
        LOG_LEVEL_SYSERROR,
        LOG_LEVEL_FATAL,
        LOG_LEVEL_CRITICAL
    };

    class LogFileManager:NoCopyable{
    public:
        LogFileManager();
        ~LogFileManager();
        void init(std::string mLogFileName,FILE * mLogFile,int64_t mMaxLogFileSize);
        void unInit();
        bool createNewFile();
        bool writeToFile(const std::string & data);
        void closeLogFile();
        bool hasLogFile();
        int64_t getMaxLogFileSize();

    private:
        std::string mLogFileName;
        FILE * mLogFile;
        int64_t mMaxLogFileSize;
        long mWritentoFileSize;
        bool mIsToFile;
    };

    class Logger {
    public:
        static void init(const std::string logFileName,bool truncateLongLog,int maxLogFileSize);
        static void unInit();

        static bool getIsRunning();
        static bool output(LogLevel logLevel,const std::string funcName,int lineNo,const char * fmt,...);
        static bool outputBinary(unsigned char * buffer,size_t size);

        Logger() = delete;
        Logger(const Logger &) = delete;
        Logger operator=(const Logger &) = delete;
        ~Logger() = delete;

    private:
        static void makeLinePreFix(LogLevel logLevel,std::string & line);
        static void writeThreadFunc();

    private:
        static std::unique_ptr<LogFileManager> mLogFileManager;
        static bool mIsRunning;
        static bool mIsTruncateLongLog;

        static std::unique_ptr<std::thread> mWriteThread;
        static BlockQuene<std::string> blockQuene;
    };


    #define LOG_TRACE(...)       Logger::output(LogLevel::LOG_LEVEL_TRACE, __FILE__, __LINE__, __VA_ARGS__)
    #define LOG_DEBUG(...)       Logger::output(LogLevel::LOG_LEVEL_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
    #define LOG_INFO(...)        Logger::output(LogLevel::LOG_LEVEL_INFO, __FILE__,  __LINE__, __VA_ARGS__)
    #define LOG_WARNING(...)     Logger::output(LogLevel::LOG_LEVEL_WARNING, __FILE__,__LINE__, __VA_ARGS__)
    #define LOG_ERROR(...)       Logger::output(LogLevel::LOG_LEVEL_ERROR, __FILE__, __LINE__, __VA_ARGS__)
    #define LOG_SYS_ERROR(...)   Logger::output(LogLevel::LOG_LEVEL_SYSERROR, __FILE__, __LINE__, __VA_ARGS__)
    #define LOG_FATAL(...)       Logger::output(LogLevel::LOG_LEVEL_FATAL, __FILE__, __LINE__,__VA_ARGS__)

    //#define LOG_CRITICAL Log::outPut(LOG_LEVEL_CRITICAL, __FILE__, __LINE__, fmt,__VA_ARGS__)

}

#endif //LODESTAR_LOG_H

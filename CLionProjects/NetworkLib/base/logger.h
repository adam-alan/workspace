//
// Created by zhuxingtian on 20-1-7.
//

#ifndef NETWORKLIB_LOGGER_H
#define NETWORKLIB_LOGGER_H

#include <functional>

using OutputFuncor = std::function<void(const char*,int)>;
using FlushFuncor = std::function<void()>;
enum class LogLevel{
    TRACE,
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL,
    NUM_LOG_LEVELS
};

class Logger {

    static void SetLogLevel(LogLevel loglevel);
    static void SetOutputFuncor(OutputFuncor output_funcor);
    static void SetFlushFuncor(FlushFuncor flush_funcor);
};


#endif //NETWORKLIB_LOGGER_H

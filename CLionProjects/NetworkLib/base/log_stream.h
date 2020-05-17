//
// Created by zhuxingtian on 20-1-7.
//

#ifndef NETWORKLIB_LOG_STREAM_H
#define NETWORKLIB_LOG_STREAM_H

#include <cstdint>
#include <string>

class LogStream{
public:

    template <typename T>
    LogStream & operator<<(T var){
        string.append(std::to_string(var)) ;
       return *this;
    }

    LogStream & operator<<(const char* var){
        string.append(std::string(var)) ;
        return *this;
    }

    LogStream & operator<<(const char var){
        string.push_back(var) ;
        return *this;
    }

private:

    std::string string;
};


#endif //NETWORKLIB_LOG_STREAM_H

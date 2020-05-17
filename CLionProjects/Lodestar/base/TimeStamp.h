//
// Created by zhuxingtian on 19-9-11.
//

#ifndef LODESTAR_TIMESTAMP_H
#define LODESTAR_TIMESTAMP_H


#include "Copyable.h"
#include <string>

namespace lodestar {
    class TimeStamp : public Copyable{
    public:
        TimeStamp();
        explicit TimeStamp(int64_t microSecondsSinceEpoch);
        ~TimeStamp() = default;
        void swap(TimeStamp & other);
        std::string toString()const ;
        std::string toFormatedString(bool showMicroSeconds);

        bool valid() const ;
        int64_t getMicroSecondsSinceEpoch() const ;
        time_t secondsSinceEpoch() const ;

        //get time of now
        static TimeStamp now();
        static TimeStamp invalid();
        static TimeStamp fromUnixTime(time_t time);
        static TimeStamp fromUnixTime(time_t time,int microSeconds);
        static const int kMicroSecondsPerSecond = 1000 * 1000;

    private:
        int64_t microSecondsSinceEpoch;         //to record the u_seconds
    };

}


#endif //LODESTAR_TIMESTAMP_H

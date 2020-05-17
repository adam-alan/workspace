//
// Created by zhuxingtian on 19-9-11.
//

#include "TimeStamp.h"

#include <sys/time.h>
namespace lodestar{
    TimeStamp::TimeStamp()
            :microSecondsSinceEpoch(0)
    {
    }

    TimeStamp::TimeStamp(int64_t microSecondsSinceEpoch)
            : microSecondsSinceEpoch(microSecondsSinceEpoch)
    {
    }

    TimeStamp TimeStamp::now() {
        struct timeval tv{0,0};
        ::gettimeofday(&tv, nullptr);
        int64_t seconds = tv.tv_sec;
        return TimeStamp(seconds*kMicroSecondsPerSecond + tv.tv_usec);
    }

    inline TimeStamp TimeStamp::invalid() {
        return TimeStamp();
    }

    inline int64_t TimeStamp::getMicroSecondsSinceEpoch() const {
        return this->microSecondsSinceEpoch;
    }

    std::string TimeStamp::toString() const {
        char buf[32];
        int64_t seconds{this->microSecondsSinceEpoch / kMicroSecondsPerSecond};
        int64_t microseconds{this->microSecondsSinceEpoch % kMicroSecondsPerSecond};
        snprintf(buf, sizeof(buf)-1,"%ld.%06ld",seconds,microseconds);
        return std::string{buf};
    }

    TimeStamp TimeStamp::fromUnixTime(time_t time) {
        return TimeStamp{fromUnixTime(time,0)};
    }

    TimeStamp TimeStamp::fromUnixTime(time_t time, int microSeconds) {
        return TimeStamp{static_cast<int64_t >(time*kMicroSecondsPerSecond)+microSeconds};
    }

    std::string TimeStamp::toFormatedString(bool showMicroseconds) {
        char buf[64];
        auto  seconds{static_cast<time_t >(this->microSecondsSinceEpoch / kMicroSecondsPerSecond)};
        tm tm_time{0,0};
        ::gmtime_r(&seconds,&tm_time);

        if (showMicroseconds){
            int microseconds = static_cast<int>(this->microSecondsSinceEpoch % kMicroSecondsPerSecond);
            snprintf(buf, sizeof(buf),"%4d-%02d-%02d %02d:%02d:%02d.%06d",
                     tm_time.tm_year + 1900, tm_time.tm_mon + 1, tm_time.tm_mday,
                     tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec,
                     microseconds);
        } else {
            snprintf(buf, sizeof(buf),"%4d-%02d-%02d %02d:%02d:%02d",
                     tm_time.tm_year + 1900, tm_time.tm_mon + 1, tm_time.tm_mday,
                     tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec);
        }
        return std::string(buf);
    }

    time_t TimeStamp::secondsSinceEpoch() const {
        return (this->microSecondsSinceEpoch / kMicroSecondsPerSecond);
    }

    void TimeStamp::swap(TimeStamp &other) {
        std::swap(*this,other);
    }

    bool TimeStamp::valid() const {
        return (this->microSecondsSinceEpoch > 0);
    }
}

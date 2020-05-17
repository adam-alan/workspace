//
// Created by zhuxingtian on 19-9-4.
//

#ifndef LODESTAR_CHANNEL_H
#define LODESTAR_CHANNEL_H

#include <functional>
#include <memory>
#include "../base/TimeStamp.h"
#include "../base/NoCopyable.h"
#include "EventLoop.h"

namespace lodestar{
    class TimeStamp;
    class EventLoop;

    class Channel:NoCopyable{
    public:
        using EventCallBack = std::function<void()>;
        using ReadCallBack = std::function<void(TimeStamp)>;
        Channel(EventLoop *loop,int fd);
        ~Channel();
        void handleEvent(TimeStamp receiveTime);

        void setReadCallBack(ReadCallBack readCallBack);
        void setWrtieCallBack(EventCallBack writeCallBack);
        void setErrorCallBack(EventCallBack errorCallBack);
        void setCloseCallBack(EventCallBack closeCallBack);

        void bindingObject(std::shared_ptr<void> & object);

        int getFd() const ;

        int getEvents() const ;
        void setEvents(int events);

        int getRevents() const ;
        void setRevents(int revents);
        void addRevents(int revents);
        bool isNoneEvent();

        void enableReading();       //can read
        void disableReading();      //cann't read
        void enableWriting();       //can write
        void disableWriting();      //cann't write
        void disableAll();          //cann't all

        void doNotLogHup();

        bool isWriteing();
        bool isReading();

        int getIndexInPoll() const ;
        void setIndexInPoll(int index);
        EventLoop * getEventloop()const ;

        void remove();
    private:
        void update();
        void handleEventWithGuard(TimeStamp receiveTime);
        bool loghup;
        EventLoop * eventLoop;
        const int fd;
        int events;
        int revents;
        int index;

        static const int kNoneEvent;
        static const int kReadEvent;
        static const int kWriteEvent;

        std::weak_ptr<void> bindedObject;
        bool binded;

        bool eventHanding;
        bool addedToLoop;
        EventCallBack writeCallBack;
        EventCallBack errorCallBack;
        EventCallBack closeCallBack;
        ReadCallBack readCallBack;

    };


}
#endif //LODESTAR_CHANNEL_H

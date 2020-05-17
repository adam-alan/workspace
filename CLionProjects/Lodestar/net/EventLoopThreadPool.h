//
// Created by zhuxingtian on 19-10-21.
//

#ifndef LODESTAR_EVENTLOOPTHREADPOOL_H
#define LODESTAR_EVENTLOOPTHREADPOOL_H

#include <vector>
#include <functional>
#include <memory>
#include <string>
#include "EventLoopThread.h"

namespace lodestar{

    class EventLoop;
    class EventLoopThread;
    class EventLoopThreadPool {
    public:
        using ThreadInitCallBack = std::function<void(EventLoop*)>;

        EventLoopThreadPool();

        ~EventLoopThreadPool();

        void init(EventLoop * baseLoop,int numThreads);

        void start(const ThreadInitCallBack & callBack);

        void stop();

        EventLoop * getNextLoop();

        EventLoop * getLoopForHash(size_t hashCode);

        std::vector<EventLoop*> getAllEventLoops();

        bool getStarted() const ;

        const std::string & getName () const ;

        const std::string infor()const ;

    private:
       EventLoop * baseEventLoop;

       std::string name;

       bool started;

       int numThreads;

       int next;

       std::vector<std::unique_ptr<EventLoopThread>> eventLoopThreadArray;

       std::vector<EventLoop*> eventLoopArray;
    };

}



#endif //LODESTAR_EVENTLOOPTHREADPOOL_H

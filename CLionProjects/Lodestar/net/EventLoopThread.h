//
// Created by zhuxingtian on 19-10-21.
//

#ifndef LODESTAR_EVENTLOOPTHREAD_H
#define LODESTAR_EVENTLOOPTHREAD_H

#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <string>

namespace lodestar{
    class EventLoop;
    class EventLoopThread {
    public:
        using ThreadInitCallback = std::function<void(EventLoop*)>;
        EventLoopThread(const ThreadInitCallback & callback = threadInitCallback);
        EventLoop * startLoop();
        void stopLoop();
        ~EventLoopThread();
    private:
        void threadFunc();
        EventLoop * eventLoop;
        bool exiting;
        std::unique_ptr<std::thread> thread;
        std::mutex mutex;
        std::condition_variable conditionVariable;
        ThreadInitCallback  threadInitCallback;
    };

}


#endif //LODESTAR_EVENTLOOPTHREAD_H

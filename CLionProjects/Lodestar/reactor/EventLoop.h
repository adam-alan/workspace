//
// Created by zhuxingtian on 19-9-4.
//

#ifndef LODESTAR_EVENTLOOP_H
#define LODESTAR_EVENTLOOP_H

#include <thread>
#include <mutex>
#include <atomic>
#include <vector>
#include <queue>
#include <memory>
#include "Channel.h"
#include "poller/Poller.h"


namespace lodestar{
    class Channel;
    class Poller;

    class EventLoop {
    public:
        using Functor = std::function<void()>;
        EventLoop();
        ~EventLoop();
        void assertInLoopThread();
        void loop();
        void quit();

        bool isInLoopThread() const;
        std::thread::id getThreadID() const ;

        bool hasChannel(Channel * channel);
        void updateChannel(Channel * channel);
        void removeChannel(Channel * channel);
        TimeStamp getPollerReturnTime()const ;

        void wakeup();
        void runInLoop(Functor functor);
        void queueInLoop(Functor functor);
        size_t getQueueSize()const ;


    private:

        void abortNotInLoopThread();
        void handleRead();
        void doWaitingFunctors();
        void printActivechannels()const ;


        std::atomic_bool isLooping;
        std::atomic_bool isQuit;

        std::thread::id threadID;
        std::unique_ptr<Poller> poller;
        std::vector<Channel*> activeChannelArray;

        int wakeupFd;
        std::unique_ptr<Channel> wakeupChannel;

        TimeStamp pollReturnTime;
        mutable std::mutex mutex;
        std::queue<Functor> waitingFunctorQueue;
        std::atomic_bool isRunningFunctors;
        std::atomic_bool eventHanding;

        Channel * currentActiveChannel;
    };


}

#endif //LODESTAR_EVENTLOOP_H

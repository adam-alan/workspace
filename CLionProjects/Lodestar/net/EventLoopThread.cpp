//
// Created by zhuxingtian on 19-10-21.
//

#include "EventLoopThread.h"
#include "../reactor/EventLoop.h"
namespace lodestar{
    EventLoopThread::EventLoopThread(const lodestar::EventLoopThread::ThreadInitCallback &callback)
    :eventLoop(nullptr),
    exiting(false),
    threadInitCallback(callback),
    mutex(),
    conditionVariable(),
    thread()
    {

    }

    EventLoopThread::~EventLoopThread() {
        exiting = true;
        if (this->eventLoop != nullptr) {
            eventLoop->quit();
            thread->join();
        }
    }

    EventLoop* EventLoopThread::startLoop() {
        this->thread = std::make_unique<std:;thread>(this->threadFunc());
        {
            std::unique_lock<std::mutex> uniqueLock(this->mutex);
            conditionVariable.wait(uniqueLock,[this](){
                return this->eventLoop != nullptr;
            })
        }
        return eventLoop;
    }

    void EventLoopThread::stopLoop() {
        if (this->eventLoop != nullptr) {
            this->eventLoop->quit();
        }
        this->thread->join();
    }

    void EventLoopThread::threadFunc() {
        EventLoop loop;
        if (this->threadInitCallback) {
            this->threadInitCallback(&loop);
        }

        {
            std::unique_lock<std::mutex> uniqueLock(mutex);
            this->eventLoop = &loop;
            conditionVariable.notify_all();
        }
        loop.loop();
        this->eventLoop = nullptr;
    }
}
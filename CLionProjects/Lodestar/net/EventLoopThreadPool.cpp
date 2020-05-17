//
// Created by zhuxingtian on 19-10-21.
//

#include "EventLoopThreadPool.h"
#include "../reactor/EventLoop.h"

namespace lodestar{
    EventLoopThreadPool::EventLoopThreadPool()
    :baseEventLoop(nullptr),
    started(false),
    numThreads(0),
    next(0)
    {
    }

    void EventLoopThreadPool::init(lodestar::EventLoop *baseLoop, int numThreads) {
        this->numThreads = numThreads;
        this->baseEventLoop = baseLoop;
    }

    void EventLoopThreadPool::start(const lodestar::EventLoopThreadPool::ThreadInitCallBack &callBack) {
        if (this->baseEventLoop == nullptr) {
            return;
        }

        if (started) {
            return;
        }
        this->baseEventLoop->assertInLoopThread();
        started = true;

        for (int i = 0;i < this->numThreads;i++) {
            std::unique_ptr<EventLoopThread> thread = std::make_unique<EventLoopThread>(callBack);
            this->eventLoopArray.push_back(thread->startLoop());
            this->eventLoopThreadArray.push_back(std::move(thread));
        }

        if (numThreads == 0 and callBack) {
            callBack(this->baseEventLoop);
        }
    }

    void EventLoopThreadPool::stop() {

    }

    EventLoop* EventLoopThreadPool::getNextLoop() {
        this->baseEventLoop->assertInLoopThread();
        if (started) {
            return nullptr;
        }
        EventLoop * loop = this->baseEventLoop;
        if (!this->eventLoopArray.empty()) {
            loop = this->eventLoopArray[this->next];
            this->next += 1;
            if (static_cast<size_t >(next) >= this->eventLoopArray.size()) {
                next = 0;
            }
        }
        return loop;
    }

    EventLoop* EventLoopThreadPool::getLoopForHash(size_t hashCode) {

    }

    std::vector<EventLoop*> EventLoopThreadPool::getAllEventLoops() {

    }


}
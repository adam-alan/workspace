//
// Created by zhuxingtian on 19-9-4.
//

#include <assert.h>
#include <sys/eventfd.h>
#include "EventLoop.h"
#include <algorithm>
#include "../base/Log.h"
#include "../base/SocketAPI.h"

namespace lodestar {
    thread_local EventLoop * thisThreadEventLoop = nullptr;
    const int kPollTimeMs = 10000;


    int createEventFd() {
        int eventfd = ::eventfd(0,EFD_NONBLOCK bitor EFD_CLOEXEC);
        if (eventfd < 0) {
            LOG_SYS_ERROR("Failed in eventfd");
            exit(EXIT_FAILURE);
        }
        return eventfd;
    }

    EventLoop::EventLoop()
    :
    isLooping(false),
    isQuit(false),
    isRunningFunctors(false),
    eventHanding(false),
    threadID(std::this_thread::get_id()),
    poller(Poller::newDefaultPoller(this)),
    wakeupFd(createEventFd()),
    wakeupChannel(std::make_unique<Channel>(this,wakeupFd)),
    currentActiveChannel(nullptr)
    {

        if (thisThreadEventLoop){
            LOG_FATAL("Another EventLoop exists in this thread");
        } else {
            thisThreadEventLoop = this;
        }
        this->wakeupChannel->setReadCallBack(std::bind(&EventLoop::handleRead,this));
        this->wakeupChannel->enableReading();
    }

    EventLoop::~EventLoop() {
        this->assertInLoopThread();
        LOG_DEBUG("EventLoop 0X%X destructs.",this);
        wakeupChannel->disableAll();
        wakeupChannel->remove();

        thisThreadEventLoop = nullptr;

    }

    void EventLoop::abortNotInLoopThread() {

    }

    bool EventLoop::isInLoopThread() const {
        return threadID == std::this_thread::get_id();
    }

    void EventLoop::assertInLoopThread() {

    }

    void EventLoop::loop() {
        assert(!this->isLooping);
        assertInLoopThread();
        this->isLooping = true;
        this->isQuit = false;


        while (!this->isQuit) {
            this->activeChannelArray.clear();
            this->pollReturnTime = this->poller->poll(kPollTimeMs,&this->activeChannelArray);

            for (auto & iter:this->activeChannelArray) {
                this->currentActiveChannel = iter;
                this->currentActiveChannel->handleEvent(this->pollReturnTime);
            }
            this->currentActiveChannel = nullptr;
            this->doWaitingFunctors();
        }
    }

    void EventLoop::quit() {
        this->isQuit = true;
        if (!isInLoopThread()) {
            wakeup();
        }
    }

    void EventLoop::runInLoop(Functor functor) {
        if (isInLoopThread()) {
            functor();
        } else {
            queueInLoop(functor);
        }
    }

    void EventLoop::queueInLoop(EventLoop::Functor functor) {
        {
            std::lock_guard<std::mutex> lockGuard(this->mutex);
            this->waitingFunctorQueue.push(std::move(functor));
        }

        if (!this->isInLoopThread() or this->isRunningFunctors) {
            wakeup();
        }
    }

    size_t EventLoop::getQueueSize() const {
        std::lock_guard<std::mutex> lockGuard(this->mutex);
        return this->waitingFunctorQueue.size();
    }

    void EventLoop::doWaitingFunctors() {
        std::queue<Functor> functorQueue;
        this->isRunningFunctors = true;
        {
            std::lock_guard<std::mutex> lockGuard(this->mutex);
            functorQueue.swap(this->waitingFunctorQueue);
        }

        while (!functorQueue.empty()) {
            auto functor = functorQueue.front();
            functorQueue.pop();
            functor();
        }
        this->isRunningFunctors = false;
    }

    void EventLoop::wakeup() {
        uint64_t one = 1;
        ssize_t n = socketAPI::write(wakeupFd,&one, sizeof(one));
        if (n != sizeof(one)) {
            LOG_ERROR("EventLoop::wakeup() writes %d bytes instead of 8",n);
        }
    }

    void EventLoop::handleRead() {
        uint64_t one = 1;
        ssize_t n = socketAPI::read(wakeupFd,&one, sizeof(one));
        if (n != sizeof(one)) {
            LOG_ERROR("EventLoop::wakeup() reads %d bytes instead of 8",n);
        }
    }

    void EventLoop::updateChannel(Channel *channel) {
        assert(channel->getEventloop() == this);
        assertInLoopThread();
        poller->updateChannel(channel);
    }

    void EventLoop::removeChannel(Channel *channel) {
        assert(channel->getEventloop() == this);
        assertInLoopThread();
        if (eventHanding) {
            assert(currentActiveChannel == channel or
            std::find(activeChannelArray.begin(),activeChannelArray.end(),channel) == activeChannelArray.end())
        }
        poller->removeChannel(channel);
    }

    bool EventLoop::hasChannel(Channel *channel) {
        assertInLoopThread();
        return poller->hasChannel(channel);
    }

    std::thread::id EventLoop::getThreadID() const {
        return this->threadID;
    }

    TimeStamp EventLoop::getPollerReturnTime() const {
        return this->pollReturnTime;
    }

}

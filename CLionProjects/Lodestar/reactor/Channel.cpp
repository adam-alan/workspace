//
// Created by zhuxingtian on 19-9-4.
//

#include "Channel.h"
#include <assert.h>
#include <poll.h>
#include "../base/Log.h"

namespace lodestar{
    const int Channel::kNoneEvent = 0;
    const int Channel::kReadEvent = POLLIN | POLLPRI;
    const int Channel::kWriteEvent = POLLOUT;


    Channel::Channel(lodestar::EventLoop *loop, int fd):
    eventLoop(loop),
    fd(fd),
    events(0),
    revents(0),
    index(-1),
    bindedObject(),
    binded(false),
    eventHanding(false),
    addedToLoop(false),
    loghup(true),
    readCallBack(),
    writeCallBack(),
    closeCallBack(),
    errorCallBack()
    {

    }

    Channel::~Channel() {
        assert(!this->eventHanding);
        assert(!this->addedToLoop);
        if (eventLoop->isInLoopThread()){

        }
    }


    void Channel::handleEvent(lodestar::TimeStamp receiveTime) {
        if (this->binded) {
            std::shared_ptr<void> bindedObj{this->bindedObject.lock()};
            if (bindedObj) {
                this->handleEventWithGuard(receiveTime);
            }
        } else {
            this->handleEventWithGuard(receiveTime);
        }
    }

    void Channel::handleEventWithGuard(lodestar::TimeStamp receiveTime) {
        this->eventHanding = true;
        if ((this->revents & POLLHUP) && !(this->revents & POLLIN)) {
            if (this->loghup) {
                LOG_WARNING("fd = %d Channel::handle_event() POLLHUP",this->fd);
            }
            if (this->closeCallBack) {
                closeCallBack();
            }
        }

        switch (revents) {

            case POLLERR | POLLNVAL:
                if (this->errorCallBack) {
                    this->errorCallBack();
                }

            case POLLIN | POLLPRI | POLLRDHUP:
                if (this->readCallBack) {
                    readCallBack(receiveTime);
                }

            case POLLOUT:
                if (this->writeCallBack) {
                    this->writeCallBack();
                }
        }
        eventHanding = false;
    }

    inline void Channel::enableReading() {
        this->events |= kReadEvent;
        this->update();
    }
    inline void Channel::disableReading() {
        this->events &= ~kReadEvent;
        this->update();
    }

    inline void Channel::enableWriting() {
        this->events |= kWriteEvent;
        this->update();
    }

    inline void Channel::disableWriting() {
        this->events &= ~kWriteEvent;
        this->update();
    }

    inline void Channel::disableAll() {
        this->events = kNoneEvent;
    }

    inline void Channel::bindingObject(std::shared_ptr<void> &object) {
        this->bindedObject = object;
        this->binded = true;
    }

    inline void Channel::update() {
        this->addedToLoop = true;
        this->eventLoop->updateChannel(this);
    }

    inline void Channel::remove() {
        assert(!this->isNoneEvent());
        this->eventLoop->removeChannel(this);
    }
    inline void Channel::doNotLogHup() {
        this->loghup = false;
    }
    inline bool Channel::isNoneEvent() {
        return this->events & kNoneEvent;
    }

    inline bool Channel::isReading() {
        return this->events & kReadEvent;
    }

    inline bool Channel::isWriteing() {
        return this->events & kWriteEvent;
    }



    inline void Channel::setEvents(int events) {
        this->events = events;
    }

    inline int Channel::getEvents() const {
        return this->events;
    }

    inline void Channel::setRevents(int revents) {
        this->revents = revents;
    }

    inline int Channel::getRevents() const {
        return this->revents;
    }

    inline void Channel::addRevents(int revents) {
        this->revents |= revents;
    }

    inline int Channel::getFd() const {
        return this->fd;
    }

    inline void Channel::setIndexInPoll(int index) {
        this->index = index;
    }

    inline int Channel::getIndexInPoll() const {
        return this->index;
    }

    EventLoop* Channel::getEventloop() const {
        return this->eventLoop;
    }


    inline void Channel::setReadCallBack(lodestar::Channel::ReadCallBack readCallBack) {
        this->readCallBack = readCallBack;
    }

    inline void Channel::setWrtieCallBack(lodestar::Channel::EventCallBack writeCallBack) {
        this->writeCallBack = writeCallBack;
    }

    void Channel::setCloseCallBack(lodestar::Channel::EventCallBack closeCallBack) {
        this->closeCallBack = closeCallBack;
    }

    inline void Channel::setErrorCallBack(lodestar::Channel::EventCallBack errorCallBack) {
        this->errorCallBack = errorCallBack;
    }

}

//
// Created by zhuxingtian on 19-9-5.
//

#ifndef LODESTAR_POLLER_H
#define LODESTAR_POLLER_H

#include <vector>
#include <map>
#include "../../base/NoCopyable.h"
#include "../../reactor/Channel.h"

namespace lodestar{
    class Channel;
    class EventLoop;
    class Poller: private NoCopyable{
    public:

        Poller(EventLoop * eventLoop);
        virtual ~Poller() = default;
        virtual TimeStamp poll(int timeOutMs,ChannelList * activeChannelList) = 0;

        virtual void updateChannel(Channel * channel) = 0;

        virtual void removeChannel(Channel * channel) = 0;

        virtual bool hasChannel(Channel *channel) const;

        static Poller * newDefaultPoller(EventLoop * eventLoop);

        void assertInLoopThread()const {
            this->ownerLoop->assertInLoopThread();
        }

    protected:
        std::map<int,Channel*> channelMap;
    private:
        EventLoop * ownerLoop;
    };



}


#endif //NETBASE_POLLER_H

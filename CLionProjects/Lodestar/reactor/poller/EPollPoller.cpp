//
// Created by zhuxingtian on 19-10-23.
//

#include "EPollPoller.h"
#include <assert.h>

namespace lodestar{
    const int kNewChannel = -1;
    const int kAddedChannel = 1;
    const int kDeletedChannel = 2;

    void EPollPoller::updateChannel(lodestar::Channel *channel) {
        Poller::assertInLoopThread();

        if (channel->getIndexInPoll() == kNewChannel or channel->getIndexInPoll() == kDeletedChannel) {
            if (channel->getIndexInPoll() == kNewChannel) {
                assert(channelMap.find(channel->getFd()) == channelMap.end());
                channelMap[channel->getFd()] = channel;
            } else {
                assert(channelMap.find(channel->getFd()) != channelMap.end());
                assert(channelMap[channel->getFd()] == channel);
            }
            channel->setIndexInPoll(kAddedChannel);
        }
    }
}
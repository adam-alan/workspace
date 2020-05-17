//
// Created by zhuxingtian on 19-9-5.
//

#include "../Channel.h"
#include "../poller/Poller.h"

namespace lodestar{
    bool Poller::hasChannel(lodestar::Channel *channel) const {
        auto iter = channelMap.find(channel->getFd());
        return (iter != channelMap.end() and iter->second == channel);
    }
}
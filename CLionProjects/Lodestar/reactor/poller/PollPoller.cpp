//
// Created by zhuxingtian on 19-9-6.
//

#include "PollPoller.h"
#include "../../reactor/EventLoop.h"
#include <assert.h>
#include <stdexcept>
namespace lodestar{

    void PollPoller::updateChannel(lodestar::Channel *channel) {
        if (channel->getIndexInPoll() < 0) {

            assert(channelMap.find(channel->getFd()) == channelMap.end());
            struct pollfd pollerfd{
                channel->getFd(),
                static_cast<short>(channel->getEvents()),
                0
            };
            pollfdArray.push_back(pollerfd);
            channel->setIndexInPoll(pollfdArray.size() - 1);
            channelMap.insert(std::pair<int,Channel*>(channel->getFd(),channel));
        }  else {

            assert(channelMap.find(channel->getFd()) != channelMap.end());
            assert(channelMap[channel->getFd()] == channel);
            assert(channel->getIndexInPoll() >= 0 and channel->getIndexInPoll() < pollfdArray.size());
            assert(pollfdArray[channel->getIndexInPoll()].fd == channel->getFd() or
                           pollfdArray[channel->getIndexInPoll()].fd == -channel->getFd() - 1);
            pollfdArray[channel->getIndexInPoll()].fd = channel->getFd();
            pollfdArray[channel->getIndexInPoll()].events = channel->getEvents();
            pollfdArray[channel->getIndexInPoll()].revents = 0;
            if (channel->isNoneEvent()) {
                pollfdArray[channel->getIndexInPoll()].fd = -channel->getFd() - 1;
            }
        }
    }

    void PollPoller::removeChannel(lodestar::Channel *channel) {
        Poller::assertInLoopThread();
        assert(channelMap.find(channel->getFd()) != channelMap.end());
        assert(channelMap[channel->getFd()] == channel);
        assert(channel->isNoneEvent());
        assert(pollfdArray[channel->getIndexInPoll()].fd == channel->getFd() or
               pollfdArray[channel->getIndexInPoll()].fd == -channel->getFd() - 1);
        assert(channel->getIndexInPoll() >= 0 and channel->getIndexInPoll() < pollfdArray.size());

        auto n = channelMap.erase(channel->getFd());
        assert(n == 1);
        if (channel->getIndexInPoll() == pollfdArray.size() - 1) {
            pollfdArray.pop_back();
        } else {
            auto channelFdAtEnd = pollfdArray.back().fd;
            std::swap(pollfdArray[channel->getIndexInPoll()],pollfdArray.back());
            if (channelFdAtEnd < 0) {
                channelFdAtEnd = -channelFdAtEnd - 1;
            }
            channelMap[channelFdAtEnd]->setIndexInPoll(channel->getIndexInPoll());
            pollfdArray.pop_back();
        }
    }

    void PollPoller::fillActiveChannelArray(int numEvents, std::vector<lodestar::Channel *> &activeChannelArray) {
        for (auto iter = pollfdArray.cbegin();iter!= pollfdArray.cend() and numEvents > 0; iter++) {
            if (iter->revents > 0) {
                numEvents -= 1;
                auto keyValue = channelMap.find(iter->fd);
                assert(keyValue != channelMap.end());
                assert(keyValue->second->getFd() == iter->fd);
                keyValue->second->setRevents(iter->revents);
                activeChannelArray.push_back(keyValue->second);
            }
        }
    }
}


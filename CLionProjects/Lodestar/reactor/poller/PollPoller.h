//
// Created by zhuxingtian on 19-9-6.
//

#ifndef LODESTAR_POLLPOLLER_H
#define LODESTAR_POLLPOLLER_H

#include "Poller.h"
#include <sys/poll.h>

namespace lodestar {
    class PollPoller: public Poller{
    public:
        PollPoller(EventLoop * eventLoop);
        ~PollPoller() override ;

        TimeStamp poll(int timeOutMs,ChannelList * activeChannelList) override ;
        virtual void updateChannel(Channel * channel) override ;
        virtual void removeChannel(Channel * channel) override ;
        virtual bool hasChannel(Channel * channel) const override ;

    private:
        void fillActiveChannelArray(int numEvents,std::vector<Channel*> & activeChannelArray);
        std::vector<pollfd> pollfdArray;
    };


}



#endif //LODESTAR_POLLPOLLER_H

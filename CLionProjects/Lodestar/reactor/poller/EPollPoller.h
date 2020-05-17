//
// Created by zhuxingtian on 19-10-23.
//

#ifndef LODESTAR_EPOLLPOLLER_H
#define LODESTAR_EPOLLPOLLER_H

#include "Poller.h"
#include <sys/epoll.h>

namespace lodestar{
    class EPollPoller: public Poller{
    public:
        EPollPoller(EventLoop * eventLoop);
        ~EPollPoller() override;

        TimeStamp poll(int timeOutMs,ChannelList * activeChannelList) override ;
        virtual void updateChannel(Channel * channel) override ;
        virtual void removeChannel(Channel * channel) override ;
        virtual bool hasChannel(Channel * channel) const override ;

    private:
        void fillActiveChannelArray(int numEvents,std::vector<Channel*> & activeChannelArray);

        std::vector<epoll_event> epollEventArray;
        int epollFd;


    };
}



#endif //LODESTAR_EPOLLPOLLER_H

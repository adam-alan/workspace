//
// Created by zhuxingtian on 19-10-14.
//

#ifndef LODESTAR_SOCKET_H
#define LODESTAR_SOCKET_H
#include <string>
#include "SocketAPI.h"

namespace lodestar{
    using std::string;
    class Socket {
    public:
        explicit Socket(int inputSockfd);
        ~Socket();


        int getSocketFd() const;
        bool getTcpInfoString(const std::string & tcpInfo) const;
        void listen();
        int accept();
        void shutdownWrite();
        void setTcpNoDelay(bool on);
        void setReuseAddr(bool on);
        void setReuPort(bool on);
        void setKeepAlive(bool on);

    private:
        const int sockfd;
    };



}



#endif //LODESTAR_SOCKET_H

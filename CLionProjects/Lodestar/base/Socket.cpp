//
// Created by zhuxingtian on 19-10-14.
//

#include "Socket.h"

namespace lodestar{
    Socket::Socket(int inputSockfd):sockfd(inputSockfd) {
        socketAPI::close(this->sockfd);
    }


    bool Socket::getTcpInfoString(const std::string &tcpInfo) const {
        return false;
    }

    void Socket::listen() {
        socketAPI::listen(this->sockfd);
    }

    int Socket::accept() {

    }

    void Socket::shutdownWrite() {
        socketAPI::shutdownWrite(this->sockfd);
    }

    void Socket::setTcpNoDelay(bool on) {
        int optval = on ? 1 : 0;
        ::setsockopt(this->sockfd,IPPROTO_TCP,TCP_NODELAY,&optval, static_cast<socklen_t >(sizeof(optval)));
    }

    void Socket::setReuseAddr(bool on) {
        socketAPI::setReuseAddr((this->sockfd,on));
    }

    void Socket::setReuPort(bool on) {
        socketAPI::setReusePort(this->sockfd,on);
    }

    void Socket::setKeepAlive(bool on) {
        int optval = on ? 1 : 0;
        ::setsockopt(this->sockfd,SOL_SOCKET,SO_KEEPALIVE,&optval, static_cast<socklen_t>(sizeof(optval)));
    }

}
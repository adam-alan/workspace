//
// Created by zhuxingtian on 19-10-17.
//

#ifndef LODESTAR_SOCKETAPI_H
#define LODESTAR_SOCKETAPI_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <string>
#include <sys/uio.h>
#include <sys/types.h>
#include <unistd.h>
namespace lodestar{

    namespace socketAPI{
        int createSocket();
        int createNonBlockingSocket();

        void setNonBlockAndCloseOnExec(int sockfd);
        void setReuseAddr(int sockfd, bool on);
        void setReusePort(int sockfd,bool on);

        int connect(int sockfd, const struct sockaddr_in & sockaddrIn);
        void bind(int sockfd, const struct sockaddr_in & sockaddrIn);
        void listen(int sockfd);
        int accept(int sockfd,sockaddr_in & sockaddrIn);


        int32_t read(int sockdf,void * buf,int count);
        ssize_t readv(int sockfd, const iovec * iovec,int iovCount);
        int32_t write(int sockfd,void * buf,int count);
        void close(int sockfd);
        void shutdownWrite(int sockfd);

        void toIPPort(char * buf,size_t size, const sockaddr_in & sockaddrIn);
        void toIP(char * buf,size_t size, const sockaddr_in & sockaddr);
        void fromIPPort(const char *ip,uint16_t port,sockaddr_in * sockaddrIn);

        int getSocketError(int sockfd);
        struct sockaddr_in getLocalAddr(int sockfd);
        struct sockaddr_in getPeerAddr(int sockfd);
        bool isSelfConnect(int sockfd);


        const struct sockaddr * sockaddr_cast(const struct sockaddr_in *sockaddrIn);
        struct sockaddr * sockaddr_cast(const struct sockaddr_in *sockaddrIn);

        const struct sockaddr_in * sockaddr_in_cast(const struct sockaddr *sockAddr);
        struct sockaddr_in * sockaddr_in_cast(const struct sockaddr *sockAddr);

    }

}

#endif //LODESTAR_SOCKETAPI_H

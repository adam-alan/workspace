//
// Created by zhuxingtian on 20-1-1.
//

#ifndef NETWORKLIB_SOCKET_NATIVE_API_H
#define NETWORKLIB_SOCKET_NATIVE_API_H


#include <arpa/inet.h>
#include <sys/uio.h>
#include <cstdint>

namespace native_api {
    //endian interface
    inline int16_t HostToNetwork16(int16_t x) ;

    inline int32_t HostToNetwork32(int32_t x) ;

    inline int64_t HostToNetwork64(int64_t x) ;

    inline int16_t NetworkToHost16(int16_t x) ;

    inline int32_t NetworkToHost32(int32_t x) ;

    inline int64_t NetworkToHost64(int64_t x) ;

    //socket interface
    int MakeNonBlocking(sa_family_t family);
    void SetNonBlockAndCloseOnExec(int sockfd);
    int Connect(int socket_fd, const sockaddr * sock_addr);
    void Bind(int socket_fd, const sockaddr * sock_addr);
    void Listen(int socket_fd);
    int Accept(int socket_fd, sockaddr * sock_addr);
    int Close(int socket_fd);
    void ShutdownWrite(int socket_fd);
    //io interface
    ssize_t ReadVector(int socket_fd, const struct iovec *iov, int iov_cnt);
    ssize_t Read(int socket_fd,void * buf,size_t size);
    ssize_t Write(int socket_fd, const void * buf,size_t size);
    //domain interface

    //get ip:port string by sockaddr
    //void ToIpPort(char * buf,size_t size, const sockaddr * addr_in);
    //get ip string by sockaddr
    void ToIp(char * buf,size_t size, const sockaddr * addr);

    //get sockaddr_in6 by ip string and port number
    void FromIpPort(const char * ip,const uint16_t port,sockaddr_in6 * addr_in6);
    //get sockaddr_in by ip string and port number
    void FromIpPort(const char * ip,const uint16_t port,sockaddr_in * addr_in);

    //socketopt interface
    int GetSocketError(int socket_fd);

    void GetLocalAddr(int socket_fd, sockaddr_in * addr_in);
    void GetLocalAddr(int socket_fd, sockaddr_in6 * addr_in6);

    void GetPeerAddr(int socket_fd, sockaddr_in * addr_in);
    void GetPeerAddr(int socket_fd, sockaddr_in6 * addr_in6);

    bool IsSelfConnect(int socket_fd);

    //sock_addr cast
    const sockaddr* sockaddr_cast(const sockaddr_in * addr_in);
    const sockaddr* sockaddr_cast(const sockaddr_in6 * addr_in6);
    const sockaddr_in * sockaddr_in_cast(const sockaddr * addr);
    const sockaddr_in6 * sockaddr_in6_cast(const sockaddr * addr);


}


#endif //NETWORKLIB_SOCKET_NATIVE_API_H

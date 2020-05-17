//
// Created by zhuxingtian on 20-1-1.
//

#include "socket_native_api.h"
#include <cassert>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
namespace native_api {

    inline int16_t HostToNetwork16(int16_t x) {
        return htobe16(x);
    }

    inline int32_t HostToNetwork32(int32_t x) {
        return htobe32(x);
    }

    inline int64_t HostToNetwork64(int64_t x) {
        return htobe64(x);
    }

    inline int16_t NetworkToHost16(int16_t x){
        return be16toh(x);
    }

    inline int32_t NetworkToHost32(int32_t x) {
        return be32toh(x);
    }

    inline int64_t NetworkToHost64(int64_t x) {
        return be64toh(x);
    }

    int MakeNonBlocking(sa_family_t family) {
        int socket_fd = socket(family, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, IPPROTO_TCP);
        if (socket_fd < 0) {

        }
        return socket_fd;
    }

    void SetNonBlockAndCloseOnExec(int socket_fd) {
        int flag = fcntl(socket_fd, F_GETFL, 0);
        flag |= O_NONBLOCK;
        int ret = fcntl(socket_fd, F_SETFL, flag);
        flag = fcntl(socket_fd, F_GETFL, 0);
        flag |= FD_CLOEXEC;
        ret = fcntl(socket_fd, F_SETFL, flag);
    }

    int Connect(int socket_fd, const sockaddr *sock_addr) {
        int ret;
        switch (sock_addr->sa_family){
            case AF_INET:
                ret = connect(socket_fd, sock_addr, static_cast<socklen_t>(sizeof(sockaddr_in)));
                break;
            case AF_INET6:
                ret = connect(socket_fd, sock_addr, static_cast<socklen_t>(sizeof(sockaddr_in6)));
                break;
        }
        return ret;
    }

    void Bind(int socket_fd, const sockaddr *sock_addr) {
        int ret;
        switch (sock_addr->sa_family){
            case AF_INET:
                ret = bind(socket_fd, sock_addr, static_cast<socklen_t>(sizeof(sockaddr_in)));
                break;
            case AF_INET6:
                ret = bind(socket_fd, sock_addr, static_cast<socklen_t>(sizeof(sockaddr_in6)));
                break;
        }
        if (ret < 0) {

        }

    }
    void Listen(int socket_fd) {
        int ret = listen(socket_fd, SOMAXCONN);
        if (ret < 0) {

        }
    }

    int Close(int socket_fd) {
        int ret = close(socket_fd);
        if (ret < 0) {

        }
    }

    void ShutdownWrite(int socket_fd) {
        int ret = shutdown(socket_fd, SHUT_WR);
        if (ret < 0){

        }
    }
    void ToIp(char *buf, size_t size, const sockaddr *addr) {
        switch (addr->sa_family) {
            case AF_INET:
                assert(size >= INET_ADDRSTRLEN);
                const sockaddr_in * addr_in;
                addr_in = (sockaddr_in *) addr;
                inet_ntop(AF_INET,&addr_in->sin_addr,buf, static_cast<socklen_t>(size));
                break;
            case AF_INET6:
                assert(size >= INET6_ADDRSTRLEN);
                const sockaddr_in6 * addr_in6 = (sockaddr_in6*)addr;
                inet_ntop(AF_INET6,&addr_in6->sin6_addr,buf, static_cast<socklen_t>(size));
                break;
        }
    }

    void FromIpPort(const char *ip, const uint16_t port, sockaddr_in6 *addr_in6) {
        addr_in6->sin6_family = AF_INET6;
        addr_in6->sin6_port = HostToNetwork16(port);
        inet_pton(AF_INET6, ip, &addr_in6->sin6_addr);
    }

    void FromIpPort(const char *ip, const uint16_t port, sockaddr_in *addr_in) {
        addr_in->sin_family = AF_INET;
        addr_in->sin_port = HostToNetwork16(port);
        inet_pton(AF_INET, ip, &addr_in->sin_addr);
    }


    inline ssize_t ReadVector(int socket_fd, const struct iovec *iov, int iov_cnt) {
        return readv(socket_fd, iov, iov_cnt);
    }
    ssize_t Read(int socket_fd, void *buf, size_t size) {
        return read(socket_fd, buf, size);
    }

    ssize_t Write(int socket_fd, const void *buf, size_t size) {
        return write(socket_fd, buf, size);
    }

    int GetSocketError(int socket_fd) {
        int optval;
        socklen_t optlen = static_cast<socklen_t >(sizeof(optval));
        if (getsockopt(socket_fd, SOL_SOCKET, SO_ERROR,&optval, &optlen) < 0) {
            return errno;
        }
        return optval;
    }


    void GetLocalAddr(int socket_fd, sockaddr_in *addr_in) {

    }

    void GetLocalAddr(int socket_fd, sockaddr_in6 *addr_in6) {

    }
}
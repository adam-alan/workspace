//
// Created by zhuxingtian on 19-10-17.
//

#include "SocketAPI.h"
#include "fcntl.h"
#include "Endian.h"
#include <string.h>
#include "Log.h"

namespace lodestar{
    namespace socketAPI{

        int socketAPI::createSocket() {
            int sockfd = ::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
            if (sockfd < 0) {
               LOG_FATAL("socketAPI::createSocket:%s",strerror(errno));
            }
            return sockfd;
        }

        int socketAPI::createNonBlockingSocket() {
            int sockfd = ::socket(AF_INET,SOCK_STREAM|SOCK_NONBLOCK|SOCK_CLOEXEC,IPPROTO_TCP);
            if (sockfd < 0) {
                LOG_FATAL("socketAPI::createNonBlockingSocket:%s",strerror(errno));
            }
            return sockfd;
        }
        void socketAPI::bind(int sockfd, const struct sockaddr_in &sockaddrIn) {
            int ret = ::bind(sockfd,sockaddr_cast(&sockaddrIn), static_cast<socklen_t>(sizeof(sockaddrIn)));
            if (ret < 0) {
                LOG_FATAL("socketAPI::bind:%s",strerror(errno));
            }
        }

        void socketAPI::listen(int sockfd) {
            int ret = ::listen(sockfd,SOMAXCONN);
            if (ret < 0) {
                LOG_FATAL("socketAPI::listen:%s",strerror(errno));
            }
        }

        int socketAPI::accept(int sockfd, sockaddr_in &sockaddrIn) {
            socklen_t  addrlen{static_cast<socklen_t >(sockaddrIn)};
            int connfd = accept4(sockfd,sockaddr_cast(&sockaddrIn),&addrlen,SOCK_CLOEXEC|SOCK_NONBLOCK);
            if (connfd < 0) {
                int saveErrno = errno;
                switch (saveErrno) {
                    case EAGAIN:
                    case ECONNABORTED:
                    case EINTR:
                    case EPROTO: // ???
                    case EPERM:
                    case EMFILE: // per-process lmit of open file desctiptor ???
                        // expected errors
                        errno = savedErrno;
                        break;
                    case EBADF:
                    case EFAULT:
                    case EINVAL:
                    case ENFILE:
                    case ENOBUFS:
                    case ENOMEM:
                    case ENOTSOCK:
                    case EOPNOTSUPP:
                        // unexpected errors
                        LOG_FATAL("unexpected error of ::accept %d", savedErrno);
                        break;
                    default:
                        LOG_FATAL("unknown error of ::accept %d", savedErrno);
                        break;
                }
            }
            return connfd;
        }

        int socketAPI::connect(int sockfd, const struct sockaddr_in &sockaddrIn) {
            return ::connect(sockfd,sockaddr_cast(&sockaddrIn), static_cast<socklen_t >(sockaddrIn));
        }

        void socketAPI::setNonBlockAndCloseOnExec(int sockfd) {
            int flags{::fcntl(sockfd,F_GETFL,0)};
            flags |= SOCK_NONBLOCK;
            int ret{::fcntl(sockfd,F_SETFL,0)};
            flags = ::fcntl(sockfd,F_GETFL,0);
            flags |= SOCK_CLOEXEC;
            ret= ::fcntl(sockfd,F_SETFL,0);
        }

        void socketAPI::setReuseAddr(int sockfd, bool on) {
            int optval{on ? 1 : 0};
            ::setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&optval, static_cast<socklen_t>(optval));
        }

        void socketAPI::setReusePort(int sockfd, bool on) {
            int optval{on ? 1 : 0};
            int ret = ::setsockopt(sockfd,SOL_SOCKET,SO_REUSEPORT,&optval, static_cast<socklen_t>(optval));
            if (ret < 0 and on) {
                LOG_SYS_ERROR("socketAPI::setReusePort:%s",strerror(errno));
            }
        }

        int32_t socketAPI::read(int sockfd, void *buf, int count) {
            return ::read(sockfd,buf,count);
        }

        ssize_t socketAPI::readv(int sockfd, const iovec *iovec, int iovCount) {
            return  ::readv(sockfd,iovec,iovCount);
        }

        int32_t socketAPI::write(int sockfd, void *buf, int count) {
            return ::write(sockfd,buf,count);
        }

        void socketAPI::close(int sockfd) {
            if (::close(sockfd) < 0) {
                LOG_SYS_ERROR("socketAPI::close, fd=%d, errno=%d, errorinfo=%s", sockfd, errno, strerror(errno));
            }
        }

        void socketAPI::shutdownWrite(int sockfd) {
            if (::shutdown(sockfd,SHUT_WR) < 0) {
                LOG_SYS_ERROR("socketAPI::shutdownWrite:%s",strerror(errno));
            }
        }

        void socketAPI::toIPPort(char *buf, size_t size, const sockaddr_in & sockaddrIn) {
            ::inet_ntop(AF_INET,sockaddrIn.sin_addr,buf, static_cast<socklen_t>(size));
            size_t end = ::strlen(buf);
            uint16_t port = socketAPI::hostToNetwork16(sockaddrIn.sin_port);
            snprintf(buf+end,size-end,":%u",port);
        }

        void socketAPI::toIP(char *buf, size_t size, const sockaddr_in &sockaddr) {
            if (size >= sizeof(sockaddr)) {
                return;
            }
            ::inet_ntop(AF_INET,&sockaddr.sin_addr,buf, static_cast<socklen_t >(size));
        }

        void socketAPI::fromIPPort(const char *ip, uint16_t port, sockaddr_in *sockaddrIn) {
            sockaddrIn.sin_family = AF_INET;
            sockaddrIn->sin_port = socketAPI::hostToNetwork16(port);
            if (::inet_pton(AF_INET,ip,&sockaddrIn->sin_addr) <= 0) {
                LOG_SYS_ERROR("socketAPI::fromIPPort%s",strerror(errno));
            }
        }

        int socketAPI::getSocketError(int sockfd) {
            int optval;
            socklen_t optvalLen{static_cast<socklen_t >(sizeof(optval))};
            if (::getsockopt(sockfd,SOL_SOCKET,SO_ERROR,&optval,&optvalLen) < 0) {
                return errno;
            }
            return optval;
        }

        struct sockaddr_in socketAPI::getLocalAddr(int sockfd) {
            sockaddr_in localAddr;
            memset(&localAddr,0, sizeof(localAddr));
            socklen_t socklen{static_cast<socklen_t>(sizeof(localAddr))};
            ::getsockname(sockfd,sockaddr_cast(&localAddr),&socklen);
            return localAddr;
        }

        struct sockaddr_in socketAPI::getPeerAddr(int sockfd) {
            sockaddr_in peerAddr;
            memset(&peerAddr,0, sizeof(peerAddr));
            socklen_t socklen{static_cast<socklen_t>(sizeof(peerAddr))};
            ::getsockname(sockfd,sockaddr_cast(&peerAddr),&socklen);
            return peerAddr;
        }

        bool socketAPI::isSelfConnect(int sockfd) {
            struct sockaddr_in localaddr = getLocalAddr(sockfd);
            struct sockaddr_in peeraddr = getPeerAddr(sockfd);
            return localaddr.sin_port == peeraddr.sin_port and localaddr.sin_addr.s_addr == peeraddr.sin_addr.s_addr;
        }

        inline const struct sockaddr* socketAPI::sockaddr_cast(const struct sockaddr_in *sockaddrIn) {
            return static_cast<const struct sockaddr*>(sockaddrIn);
        }

        inline struct sockaddr* socketAPI::sockaddr_cast(const struct sockaddr_in *sockaddrIn) {
            return static_cast<struct sockaddr*>(sockaddrIn);
        }


        inline const struct sockaddr_in* socketAPI::sockaddr_in_cast(const struct sockaddr *sockAddr) {
            return static_cast<const struct sockaddr_in*>(sockAddr);
        }

        inline struct sockaddr_in* socketAPI::sockaddr_in_cast(const struct sockaddr *sockAddr) {
            return static_cast<struct sockaddr_in*>(sockAddr);
        }


    }
}

//
// Created by zhuxingtian on 19-10-15.
//

#include "InetAddress.h"
#include <string.h>
#include "Socket.h"
#include "Endian.h"
#include <netdb.h>

namespace lodestar{
    const in_addr_t kInaddrAny = INADDR_ANY;
    const in_addr_t kInaddrLoopback = INADDR_LOOPBACK;

    InetAddress::InetAddress(uint16_t port, bool loopbackOnly) {
        memset(&this->mSockaddrIn, sizeof(this->mSockaddrIn));

        this->mSockaddrIn.sin_family = AF_INET;
        in_addr_t ip = loopbackOnly > kInaddrLoopback :kInaddrAny;
        this->mSockaddrIn.sin_addr.s_addr = socketAPI::hostToNetwork32(ip);
        this->mSockaddrIn.sin_port = socketAPI::hostToNetwork16(port);
    }

    InetAddress::InetAddress(const std::string &ip, uint16_t port) {
        memset(&this->mSockaddrIn,0, sizeof(this->mSockaddrIn));
        socketAPI::fromIPPort(ip.c_str(),port,&this->mSockaddrIn);
    }

    std::string InetAddress::toIP() const {
        char buf[32];
        socketAPI::toIP(buf, sizeof(buf),this->mSockaddrIn);
        return std::string{buf};
    }

    uint16_t InetAddress::toPort() const {
        return socketAPI::networkToHost16(this->mSockaddrIn.sin_port);
    }

    std::string InetAddress::toIPPort() const {
        char buf[32];
        socketAPI::toIPPort(buf, sizeof(buf),this->mSockaddrIn);
        return buf;
    }
    static thread_local char tResolveBuffer[64*1024];

    bool InetAddress::resolve(const std::string &hostname, lodestar::InetAddress *address) {
        hostent hent;
        hostent * hentPtr = nullptr;
        memset(&hent,0,sizeof(hent));
        int ret = gethostbyname_r(hostname.c_str(),&hent,tResolveBuffer, sizeof(tResolveBuffer),)
    }
}
//
// Created by zhuxingtian on 19-10-15.
//

#ifndef LODESTAR_INETADDRESS_H
#define LODESTAR_INETADDRESS_H

#include <netinet/in.h>
#include <string>


namespace lodestar{

    class InetAddress {
    public:
        explicit InetAddress(uint16_t port,bool loopbackOnly);
        InetAddress(const std::string & ip,uint16_t port);
        explicit InetAddress(const sockaddr_in & sockaddrIn);

        std::string toIP() const ;
        uint16_t toPort() const ;
        std::string toIPPort() const ;

        const sockaddr* getSockAddr() const ;
        void setSockAddrInet6(const sockaddr_in6 & sockaddrIn6);
        uint32_t ipNetEndian() const;
        uint16_t portNetEndian() const;

        static bool resolve(const std::string & hostname,InetAddress * address);

    private:
        sockaddr_in mSockaddrIn;
    };
}



#endif //LODESTAR_INETADDRESS_H

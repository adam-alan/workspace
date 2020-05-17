//
// Created by zhuxingtian on 20-1-3.
//

#ifndef NETWORKLIB_INET_ADDRESS_H
#define NETWORKLIB_INET_ADDRESS_H


#include <stdint-gcc.h>
#include <netinet/in.h>
#include <string>



class InetAddress {
public:
    explicit InetAddress(uint16_t port = 0, bool loopback_only = false, bool ipv6 = false);
    InetAddress(const sockaddr_in & addr_in);
    InetAddress(const sockaddr_in6 & addr_in6);
    sa_family_t family() const ;


};


#endif //NETWORKLIB_INET_ADDRESS_H

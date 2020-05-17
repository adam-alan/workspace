#include <iostream>
#include <string>
#include <vector>
#include <netdb.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
int main() {
    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
    hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
    hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
    hints.ai_protocol = 0;          /* Any protocol */
    hints.ai_canonname = nullptr;
    hints.ai_addr = nullptr;
    hints.ai_next = nullptr;

    struct addrinfo *res;
    int val = getaddrinfo("www.zhihu.com", nullptr,&hints,&res);
    if (val != 0) {
        fprintf(stderr, "%s\n", gai_strerror(val));
        exit(EXIT_FAILURE);
    }

    /*auto f = [](std::string string)->std::string {
        return string.substr(0,1);
    };

    std::cout << f("Hello, World!") << std::endl;
    */
    std::cout << sizeof(sockaddr) << std::endl;
    for (addrinfo * iter = res; iter != nullptr; iter = iter->ai_next){
        if (iter->ai_family == AF_INET) {

            sockaddr_in *In = (sockaddr_in *) (iter->ai_addr);
            char ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &In->sin_addr, ip, sizeof(sockaddr_in));
            std::cout << "ipv4\t" << ip << std::endl;

        }
        if (iter->ai_family == AF_INET6) {
            sockaddr_in6 * In6 = (sockaddr_in6*)(iter->ai_addr);;
            char ip6[INET6_ADDRSTRLEN];
            inet_ntop(AF_INET6, &In6->sin6_addr, ip6, sizeof(sockaddr_in6));
            std::cout << "ipv6\t" << ip6 <<std::endl;
        }
    }
    freeaddrinfo(res);
    return 0;
}
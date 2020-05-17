#include <iostream>
#include <string>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, const char** argv) {

    hostent host;
    host = *gethostbyname("cn.bing.com");
    std::cout << *host.h_name << std::endl;
    std::cout << host.h_addrtype << std::endl;
    
    for (int i = 0; host.h_aliases[i];i++){
        std::cout << *host.h_aliases[i] << std::endl;
    }

    for (int i = 0; host.h_length;i++){
        std::cout << host.h_addr_list[i] << std::endl;
    }

    return 0;
}
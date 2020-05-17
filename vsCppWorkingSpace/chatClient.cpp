# include <sys/socket.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <iostream>
# include <cassert>
# include <cstring>
# include <unistd.h>
using userId = unsigned long;

struct message
{
    char text[1024];
    userId sendUserid;
    userId recvUserid;
};

int
main(int argc, char const *argv[])
{
    int sock = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0){
        perror("socket");
        exit(1);
    }
    sockaddr_in sockAddr;
    
    ::memset(&sockAddr, 0, sizeof(sockAddr));

    sockAddr.sin_family = AF_INET;
    sockAddr.sin_addr.s_addr = ::inet_addr("127.0.0.1");
    sockAddr.sin_port = htons(10000);

    int ret = ::connect(sock, (sockaddr *)(&sockAddr), sizeof(sockAddr));
    if (ret < 0){
        perror("connect");
        exit(1);
    }
    message msg{"hahaha", 1, 2};
    userId uid;
    std::cin >> uid;
    
    write(sock, &uid, sizeof(uid));
    write(sock, &msg, sizeof(msg));
    return 0;
}



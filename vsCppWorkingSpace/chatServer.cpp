# include <sys/socket.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <iostream>
# include <cassert>
# include <cstring>
# include <netdb.h>
# include <unistd.h>
# include <map>
using userId = unsigned long;

struct message
{
    char text[1024];
    userId sendUserid;
    userId recvUserid;
};

std::map<int, int> usrToSock;

int
main(int argc, char const *argv[])
{
    int listenSock = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listenSock < 0){
        perror("socket");
        exit(1);
    }
    sockaddr_in sockAddr;
    
    ::memset(&sockAddr, 0, sizeof(sockAddr));

    sockAddr.sin_family = AF_INET;
    sockAddr.sin_addr.s_addr = ::inet_addr("127.0.0.1");
    sockAddr.sin_port = htons(10000);

    int ret = ::bind(listenSock, (sockaddr *)(&sockAddr), sizeof(sockAddr));
    if (ret < 0){
        perror("bind");
        exit(1);
    }

    ret = listen(listenSock, 1024);
    if (ret < 0){
        perror("listen");
        exit(1);
    }
 
    while (true){
        sockaddr_in clientAddr;
        socklen_t len;
        int clientSock = ::accept(listenSock, (sockaddr *)(&clientAddr),&len);
        if (clientSock < 0){
            perror("accept");
            exit(1);
        }
        userId uid;
        message msg;
        read(clientSock, &uid, sizeof(userId));
        read(clientSock, &msg, sizeof(message));
        printf("connect usrid is %lu\n", uid);
        printf("usrid is %lu send message to usrid is %lu,the message is %s\n",msg.sendUserid,msg.text, msg.recvUserid);
        if (::strcmp(msg.text,"quit") == 0){
            close(usrToSock.at(msg.sendUserid));
        }

        write(usrToSock.at(msg.recvUserid), &msg, sizeof(message));
    }
    return 0;
}
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MESSAGELEN 1024

using std::string;

const int servPort = 10000;

struct usrInfor
{
    struct sockaddr_in sockaddr;
    int usrNum;
};

int main(int argc, char const *argv[])
{

    int listenfd;
    int connfd;

    struct sockaddr_in servaddr;
    struct sockaddr_in cliaddr;
    struct usrInfor usr[1024];
    pid_t pid;
    
    
    memset(&servaddr, 0, sizeof(struct sockaddr_in));
    servaddr.sin_port = htons(servPort);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if ((listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        perror("socket");
        exit(1);
    }

    if ((bind(listenfd, (struct sockaddr *)&servaddr, (socklen_t)sizeof(struct sockaddr_in))) < 0)
    {
        perror("bind");
        exit(1);
    }

    if ((listen(listenfd, 1024)) < 0)
    {

        perror("listen");
        exit(1);
    }
    //int connectNum = 0;

    while (true)
    {
        int clilen = sizeof(cliaddr);
        if ((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, (socklen_t *)&clilen)) < 0)
        {
            perror("accept");
            exit(1);
        }
        char str[40];
        inet_ntop(AF_INET, &cliaddr.sin_addr, str, 40);
        printf("%s,%u connected\n", str, cliaddr.sin_port);

        //int num;
        //read(connfd, &num, sizeof(int));

        //memcpy(&usr[i].sockaddr, &cliaddr, sizeof(struct sockaddr));
        //memcpy(&usr[i].usrNum, &num, sizeof(int));

        //connectNum += 1;
        string message;
        read(connfd, (char *)&message, 1024);
        printf("%s\n", message.c_str());
        close(connfd);
    }

    return 0;
}
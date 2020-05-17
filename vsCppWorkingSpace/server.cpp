#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
# include <string>
#define MAXLINE 1024

struct UserInfor{
    int num;
    std::string name;
};



int main()
{
    int serverfd;
    char message[MAXLINE];
    struct sockaddr_in serveraddr;
    struct sockaddr_in clientaddr;
    pid_t childpid;
    socklen_t len;
    serverfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverfd < 0)
    {
        perror("socket");
        exit(1);
    }
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(30000);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(serverfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    listen(serverfd, 1024);
    for (;;)
    {
        int connfd = accept(serverfd, nullptr, nullptr);
        if (connfd < 0)
        {
            perror("accept");
            exit(1);
        }
        UserInfor usr;
        int len = read(connfd, &usr, MAXLINE);
        
    
        //memset(&usr, 0, sizeof(usr));
        //memcpy(&usr, message, sizeof(usr));

        printf("%d %s\n", usr.num, usr.name.c_str());
        
        close(connfd);
    }
    return 0;
}

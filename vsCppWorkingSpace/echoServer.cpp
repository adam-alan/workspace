# include <arpa/inet.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <sys/select.h>
# include <netdb.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>

# define MESSAGELEN 1024 

const int servPort = 10000;



int main(int argc, char const *argv[])
{

    int listenfd;
    int connfd;
   
    struct sockaddr_in servaddr;
    struct sockaddr_in cliaddr;
   
    pid_t pid;

    memset(&servaddr, 0, sizeof(struct sockaddr_in));
    servaddr.sin_port = htons(servPort);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);


    if ((listenfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)) < 0){
        perror("socket");
        exit(1);
    }
    
    if ((bind(listenfd,(struct sockaddr *)&servaddr,(socklen_t)sizeof(struct sockaddr_in))) < 0){
        perror("bind");
        exit(1);
    }


    if ((listen(listenfd,1024)) < 0){

        perror("listen");
        exit(1);
    }

    while (1){
        int clilen = sizeof(cliaddr);
        if ((connfd = accept(listenfd, (struct sockaddr *)&cliaddr,(socklen_t *) &clilen)) < 0)
        {
            perror("accept");
            exit(1);
        }
        pid = fork();
        if (pid == 0)
        {
            close(listenfd);
            void str_echo(int sockfd);
            str_echo(connfd);
            printf("client closed");
            close(connfd);
            exit(0);
        }
    }

    return 0;
}



void str_echo(int sockfd){
    ssize_t n;

    char message[MESSAGELEN];
 
    while ((n = read(sockfd, message, MESSAGELEN)) > 0){
        write(STDOUT_FILENO, message, MESSAGELEN);
        write(sockfd, message, MESSAGELEN);
    }
    
}
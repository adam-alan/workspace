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

const int servPort = 8880;

int main(int argc, char const *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)) < 0){
        perror("socket");
        exit(1);
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(servPort);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if ((connect(sockfd,(struct sockaddr*)&servaddr,(socklen_t)sizeof(struct sockaddr_in)) < 0)){
        perror("connect");
        exit(1);
    }
    void str_cli(FILE * fp,int sockfd);
    str_cli(stdin,sockfd);

    return 0;
}


void str_cli(FILE * fp,int sockfd)
{
    char message[MESSAGELEN];
    ssize_t n;
    memset(message, '\0', MESSAGELEN);

    while ((n = read(STDIN_FILENO, message, MESSAGELEN)) > 0){
        write(sockfd, message, MESSAGELEN);
    }
    
}
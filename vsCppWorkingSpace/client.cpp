# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <string>


# define MAXLINE 1024

struct UserInfor{
    int num;
    std::string name;
};


int main(){
    int clientfd;
    char message[MAXLINE];
    struct sockaddr_in serveraddr;
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(30000);
    memset(message, L'\0', MAXLINE);
    clientfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( clientfd < 0){
        perror("socket");
        exit(1);
    }
    if ((connect(clientfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr))) < 0){
        perror("connect");
        exit(1);
    }

    UserInfor usr = {1, "dfgdfgdfg"};
    //memcpy(message, &usr, sizeof(usr));
    //message[sizeof(usr)] = '\0';
   
    printf("%d %s\n", usr.num, usr.name.c_str());
    write(clientfd, &usr,sizeof(usr));
    close(clientfd);
    return 0;
}
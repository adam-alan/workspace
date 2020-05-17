# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <netdb.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define MAXLINE 1024


int main() {
    int serverfd;
    char message[MAXLINE];
    struct sockaddr_in serveraddr;
    struct sockaddr_in clientaddr;
    pid_t childpid;
    socklen_t len;
    serverfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverfd < 0) {
        perror("socket");
        exit(1);
    }
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(30000);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(serverfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr));
    listen(serverfd, 1024);
    for (;;) {
        int connfd = accept(serverfd, (struct sockaddr *) &clientaddr, (socklen_t *) &len);
        if (connfd < 0) {
            perror("accept");
            exit(1);
        }

        if ((childpid = fork()) == 0) {
            close(serverfd);
            printf("%s\n", inet_ntoa(clientaddr.sin_addr));
            read(connfd, message, MAXLINE);
            message[strlen(message)] = '\0';
            printf("%lu\n%s\n", strlen(message), message);
            exit(0);
        }
        close(connfd);
    }
    return 0;
}

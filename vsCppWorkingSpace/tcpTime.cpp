
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define LISTENQ 1024
# define MAXLINE 4096
int open_listenfd(char * service);

int open_clientfd(char * hostname,char * service);


int main(){
    
    int clientfd;
    char buf[MAXLINE];
    clientfd = open_clientfd("localhost", "13");
    write(clientfd, buf, MAXLINE);
    return 0;
}



int open_clientfd(char * hostname,char * service){
    int clientfd;
    struct addrinfo hints,*listp,*p;

    memset(&hints,0, sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_NUMERICSERV;
    hints.ai_flags |= AI_ADDRCONFIG;
    getaddrinfo(hostname,service,&hints,&listp);

    for (p = listp;p != NULL;p = p->ai_next){
        if ( ( clientfd = socket(p->ai_family,p->ai_socktype,p->ai_protocol)) < 0){
            continue;
        }

        if ( connect(clientfd,p->ai_addr,p->ai_addrlen) != -1){
            break;
        }
        close(clientfd);
    }
    freeaddrinfo(listp);
    if ( p == NULL){
        return -1;
    } else {
        return clientfd;
    }
}


int open_listenfd(char * service){
    struct addrinfo hints,*p,*listp;
    int listenfd,optval = 1;

    memset(&hints,0, sizeof(struct addrinfo));
    hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
    hints.ai_flags |= AI_NUMERICSERV;
    getaddrinfo(NULL,service,&hints,&listp);

    for (p = listp;p != NULL;p = p->ai_next){
        if ( (listenfd = socket(p->ai_family,p->ai_socktype,p->ai_protocol)) < 0){
            continue;
        }
        setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,(const void *)&optval, sizeof(int));

        if (bind(listenfd,p->ai_addr,p->ai_addrlen) == 0){
            break;
        }
        close(listenfd);
    }

    freeaddrinfo(listp);
    if (p == NULL){
        return -1;
    }

    if (listen(listenfd,LISTENQ) < 0){
        return -1;
    }

    return listenfd;
}

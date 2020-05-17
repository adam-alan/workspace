//
// Created by zhuxingtian on 19-6-12.
//

#ifndef NET_SOCKETPACKAGE_H
#define NET_SOCKETPACKAGE_H

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define LISTENQ 1024

extern int open_listenfd(char * service);

extern int open_clientfd(char * hostname,char * service);



#endif //NET_SOCKETPACKAGE_H

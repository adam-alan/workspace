//
// Created by zhuxingtian on 19-6-23.
//

#ifndef NETWORKING_SOCKET_H
#define NETWORKING_SOCKET_H



class Socket {
public:

    virtual int socket() = 0;
    Socket(const Socket & socket) = delete;
};


#endif //NETWORKING_SOCKET_H

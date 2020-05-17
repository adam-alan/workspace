# include <sys/poll.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <cstring>
# include <cassert>
# include <sys/msg.h>
# include <iostream>
# include <unistd.h>


0int main(int argc, char const *argv[])
{
    //申请socket
    ::pollfd listened;
    listened.fd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    assert(listened.fd > 0);
    listened.events = POLLRDNORM;
    sockaddr_in listenSock;
    memset(&servaddr, 0, sizeof(struct sockaddr_in));

    listenSock.sin_family = AF_INET;
    listenSock.sin_port = ::htons(10000);
    listenSock.sin_addr.s_addr = ::htonl(INADDR_ANY);

    assert(::bind(listened.fd, (sockaddr *)(&listenSock), sizeof(listenSock)) > 0);
    assert(::listen(listened.fd, 1024) > 0);

    pollfd client[1024];
    char buf[1024];
    memset(buf, '\0', 1024);
    for (auto &&iter : client)
    {
        iter.fd = -1;
    }
    int maxNum = 0;
    while (true)
    {
        int nReady = ::poll(client, maxNum + 1, -1);
        
        //有客户连接
        if (listened.revents bitand POLLIN)
        {
            socklen_t clilen = sizeof(sockaddr_in);
            sockaddr_in cliAddr;
            int conSock = ::accept(listened.fd, (sockaddr *)(&cliAddr), &clilen);
            int conIndex = 0;
            for (conIndex = 0; conIndex < 1024; conIndex++)
            {
                if (client[conIndex].fd == -1)
                {
                    client[conIndex].fd = conSock;
                    client[conIndex].events = POLLIN bitor POLLOUT;
                    break;
                }
            }
            assert(conIndex != 1024);
            if (conIndex >= maxNum)
            {
                maxNum = conIndex;
            }
            if (--nReady <= 0)
            {
                continue;
            }
        }

        for (int i = 0; i < maxNum;i++)
        {
            if (client[i].fd == -1)
            {
                continue;
            }
            int n = 0;
            //有客户准备好读
            if (client[i].revents & (POLLIN bitor POLLERR))
            {
                if ( (n = ::read(client[i].fd,buf,1024)) < 0) 
                {
                    if (::errno == ECONNRESET) 
                    {
                        ::close(client[i].fd);
                        client[i].fd = -1;
                    } 
                    else {
                        ::perror("read");
                    }
                } 
                else if (n == 0)
                {
                    ::close(client[i].fd);
                    client[i].fd = -1;
                }
                else
                {
                    ::write(client[i].fd, buf, 1024);
                }
                
                if (--nReady < 0)
                {
                    break;
                }
            }
        }
    }

    return 0;
}

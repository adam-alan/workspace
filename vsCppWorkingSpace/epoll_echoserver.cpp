# include <sys/epoll.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <vector>
# include <unistd.h>
# include <iostream>
# include <string.h>

int main(int argc, const char** argv) {
    int listen_socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sockaddr_in listen_sockaddr;
    
    listen_sockaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    listen_sockaddr.sin_family = AF_INET;
    listen_sockaddr.sin_port = htobe16(8880);
    ::bind(listen_socket, (sockaddr*)&listen_sockaddr, sizeof(listen_sockaddr));
    ::listen(listen_socket, 1024);
    std::vector<epoll_event> events(1024);
    int epollfd = ::epoll_create1(EPOLL_CLOEXEC);
    epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = listen_socket;

    ::epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_socket, &event);

    while (true){
        ::epoll_wait(epollfd, events.data(), events.size(), -1);
        for (auto item:events) {
            if (item.events == EPOLLIN) {
                if (item.data.fd == listen_socket) {
                    int conn = ::accept(listen_socket, nullptr, nullptr);
                    epoll_event event;
                    event.events = EPOLLIN;
                    event.data.fd = conn;
                    ::epoll_ctl(epollfd, EPOLL_CTL_ADD, conn, &event);
                } else {
                    char buf[1024];
                    ::memset(buf, '\0', sizeof(buf));
                    int bytes = ::recv(item.data.fd, buf, 1024, 0);
                    if (bytes == 0) {
                        ::close(item.data.fd);
                        ::epoll_ctl(epollfd, EPOLL_CTL_DEL, item.data.fd, nullptr);
                    }
                    ::printf("%s\n", buf);
                }
            }
        }
    }
    ::close(listen_socket);
    ::close(epollfd);
    return 0;
}
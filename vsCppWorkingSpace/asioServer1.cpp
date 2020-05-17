#include <boost/asio.hpp>
#include <memory>
#include <thread>
#include <functional>

using namespace boost::asio;

using socket_ptr = std::shared_ptr<ip::tcp::socket>;

void client_session(socket_ptr sock) {
    while (true) {
        char data[512];
        size_t len = sock->read_some(buffer(data));
        if (len > 0) {
            write(*sock, buffer("ok", 2));
        }
    }
}

int main(int argc, const char **argv){
    io_service service;
    ip::tcp::endpoint ep(ip::tcp::v4(), 2001);
    ip::tcp::acceptor acc(service, ep);
    while (true) {
        socket_ptr sock(new ip::tcp::socket(service));
        acc.accept(*sock);
        std::thread(std::bind(client_session, sock));
    }
    return 0;
}
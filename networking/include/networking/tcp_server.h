#ifndef BASIC_SERVER_CLIENT_TCP_SERVER_H
#define BASIC_SERVER_CLIENT_TCP_SERVER_H

#include <boost/asio.hpp>
#include "networking/tcp_connection.h"


enum class IPv {
    v4,
    v6
};

class TCPServer {
public:
    TCPServer(IPv ip_version, int port);

    int run();

private:
    void start_accept();

private:
    IPv _ip_version;
    int _port;

    boost::asio::io_context _io_context;
    boost::asio::ip::tcp::acceptor _acceptor;

    std::vector<tcp_connection::pointer> _connections {};
};


#endif //BASIC_SERVER_CLIENT_TCP_SERVER_H

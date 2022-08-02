#include <iostream>

#include "networking/tcp_server.h"


using boost::asio::ip::tcp;

TCPServer::TCPServer(IPv ip_version, int port) : _ip_version(ip_version), _port(port),
        _acceptor(_io_context, tcp::endpoint(ip_version == IPv::v4 ? tcp::v4() : tcp::v6(), _port)) {


}

int TCPServer::run() {

    try {
        start_accept();
        _io_context.run();
    } catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}

void TCPServer::start_accept() {
    // create connection
    auto connection = tcp_connection::create(_io_context);

    _connections.push_back(connection);
    // async accept the connection
    _acceptor.async_accept(connection->socket(), [connection, this](const boost::system::error_code& error) {
        if (!error) {
            connection->start();
        }

        start_accept();
    });

}

#ifndef BASIC_SERVER_CLIENT_TCP_CONNECTION_H
#define BASIC_SERVER_CLIENT_TCP_CONNECTION_H

#include <memory>

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class tcp_connection : public std::enable_shared_from_this<tcp_connection> {
public:
    using pointer = std::shared_ptr<tcp_connection>;
    static pointer create(boost::asio::io_context& io_context) {
        return pointer(new tcp_connection(io_context));
    }

    tcp::socket& socket() {
        return _socket;
    }

    void start();

private:
    explicit tcp_connection(boost::asio::io_context& io_context);

private:
    tcp::socket _socket;
    std::string _message {"Hello, client!\n"};
};


#endif //BASIC_SERVER_CLIENT_TCP_CONNECTION_H

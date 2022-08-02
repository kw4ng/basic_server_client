#include <iostream>
#include "networking/tcp_connection.h"

tcp_connection::tcp_connection(boost::asio::io_context &io_context) : _socket(io_context){

}

void tcp_connection::start() {
    auto strong_this = shared_from_this();

    boost::asio::async_write(_socket, boost::asio::buffer(_message),
                                [strong_this](const boost::system::error_code &error, size_t bytes_transferred) {
         if (error) {
             std::cout << "Failed to send message!\n";
         } else {
             std::cout << "Sent " << bytes_transferred << " bytes of data!\n";
         }
     });


    boost::asio::streambuf buffer;
    _socket.async_receive(buffer.prepare(512), [this](const boost::system::error_code& error, size_t bytes_transferred) {
        if (error == boost::asio::error::eof) {
            // clean connection cut off
            std::cout << "Client disconnected properly!\n";
        } else if (error) {
            std::cout << "Client disconnected in bad way!\n";
        }
    });
}
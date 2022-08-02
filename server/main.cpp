#include <iostream>

#include <boost/asio.hpp>
#include <networking/tcp_server.h>

using boost::asio::ip::tcp;

int main(int argc, char** argv) {

//    try {
//        boost::asio::io_context io_context;
//
//        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 1337));
//
//        while(true) {
//            std::cout << "Accepting connections on port 1337!\n";
//            tcp::socket socket(io_context);
//            acceptor.accept(socket);
//
//            std::cout << "Client connected! Sending message!\n";
//            std::string hello_message = "Hello, client!\n";
//            boost::system::error_code error;
//
//            boost::asio::write(socket, boost::asio::buffer(hello_message), error);
//        }
//    } catch (std::exception& e) {
//        std::cerr << e.what() << std::endl;
//    }

    TCPServer server(IPv::v4, 1337);

    server.run();

    return 0;
}

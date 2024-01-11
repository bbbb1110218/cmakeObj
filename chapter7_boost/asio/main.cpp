#include <iostream>
#include <boost/asio.hpp>
#include <cstring>

const char *msg = "Service Got the message!\n";

int main() {
    boost::asio::io_service io_service;

    // 创建一个监听 54321 端口的 acceptor
    boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 54321));

    // 等待连接
    while(1){   
        boost::asio::ip::tcp::socket socket(io_service);
        acceptor.accept(socket);
        while(1){
                            // 从 socket 中读取一行数据
            boost::asio::streambuf buf;
            boost::asio::read_until(socket, buf, '\n');

            // 将数据写入 socket
            std::string data = boost::asio::buffer_cast<const char*>(buf.data());
            std::cout << data << std::endl;

            boost::asio::write(socket, boost::asio::buffer("Server Got the message!\n"));
            //相应客户端
            if(data.substr(0,4) == "exit" || data.substr(0,4) == "quit" || data.substr(0,4) == "EXIT" || data.substr(0,4) == "QUIT"){
                std::cout << "Client exit" << std::endl;
                break;
            }

        }
    


        
        socket.write_some(boost::asio::buffer(std::string("Server Got the message!\n")));
        socket.close();
    }

    // 从这里开始，你可以使用 socket 来读写数据

    return 0;
}
#include <iostream>
#include <boost/asio.hpp>
#include <thread>
#include <cstring>
#include <pthread.h>

const char *msg = "Service Got the message!\n";

void handle_client(boost::asio::ip::tcp::socket *socket) {
    while(1){
        // 从 socket 中读取一行数据
        boost::asio::streambuf buf;
        boost::asio::read_until(socket, buf, '\n');

        // 将数据写入 socket
        std::string data = boost::asio::buffer_cast<const char*>(buf.data());
        std::cout << data << std::endl;

        boost::asio::write(*socket, boost::asio::buffer("Server Got the message!\n"));
        //相应客户端
        if(data.substr(0,4) == "exit" || data.substr(0,4) == "quit" || data.substr(0,4) == "EXIT" || data.substr(0,4) == "QUIT"){
            break;
        }
    }
}

int main() {
    boost::asio::io_service io_service;

    // 创建一个监听 54321 端口的 acceptor
    boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 54321));

    // 等待连接
    while(1){   
        boost::asio::ip::tcp::socket socket(io_service);
        acceptor.accept(socket);

        // 创建一个新的线程处理连接
        std::thread client_thread(handle_client, &socket);
        client_thread.detach();
        // pthread_t t;
        // pthread_create(&t,NULL,handle_client,socket);
        // t.detach();
    }

    return 0;
}
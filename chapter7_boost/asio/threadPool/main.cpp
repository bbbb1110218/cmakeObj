
#include <iostream>
#include <boost/asio.hpp>
#include <thread>
#include <vector>
#include <queue>
#include <condition_variable>
#include <atomic>

#define PORT 54322

class ThreadPool {
public:
    ThreadPool(size_t threads) : stop(false) {
        for(size_t i = 0;i<threads;++i)
            workers.emplace_back([this] {
                for(;;) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(this->queue_mutex);
                        this->condition.wait(lock, [this]{ return this->stop || !this->tasks.empty(); });
                        if(this->stop && this->tasks.empty())
                            return;
                        task = std::move(this->tasks.front());
                        this->tasks.pop();
                    }
                    task();
                }
            });
    }

    template<class F>
    void enqueue(F&& f) {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            if(stop)
                throw std::runtime_error("enqueue on stopped ThreadPool");
            tasks.emplace(std::forward<F>(f));
        }
        condition.notify_one();
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all();
        for(std::thread &worker: workers)
            worker.join();
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;
    std::condition_variable condition;
    std::atomic<bool> stop;
};

void handle_client(boost::asio::ip::tcp::socket socket) {
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
            socket.close();
            break;
        }
        if(data.substr(0,4) == "KILL" || data.substr(0,4) == "kill" || data.substr(0,4) == "Kill"){
            std::cout << "Client exit" << std::endl;
            //TODO::Unfinished
            break;
        }
    }
}

int main() {
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), PORT));
    ThreadPool pool(4); // 创建一个有4个线程的线程池

    while (1) {
        auto socket = std::make_shared<boost::asio::ip::tcp::socket>(io_service);
        acceptor.accept(*socket);
        pool.enqueue([socket]() {
            handle_client(std::move(*socket));
        });
    }

    return 0;
}
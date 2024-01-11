#include <iostream>
// #include <boost/timer/timer.hpp>
#include <boost/json.hpp>

int main(){
    // boost::timer::cpu_timer  t;
    // t.start();

    // std::cout << "Hello World!" << std::endl;



    // // std::cout << "Timer elapsed: " << t.elapsed() << std::endl;

    // if(t.is_stopped())
    //     std::cout << "Timer is stopped" << std::endl;
    // else{
    //     std::cout << "Timer is not stopped" << std::endl;
    // }

    boost::json::value jv = boost::json::parse(R"({"pi": 3.141592653589793238462643383})");
    std::cout << jv << std::endl;

    return 0;
}
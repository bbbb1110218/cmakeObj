#include <iostream>

#define NEEDDEBUG std::cout << "debug info:: " \
              << "File : ["   \
              << __FILE__    \
              << "]"   \
              << " LINE: ["   \
              << __LINE__   \
              <<"] \n"  


int main(){

    NEEDDEBUG;

    NEEDDEBUG;
    return 0;
}
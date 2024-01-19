#include <iostream>
#include "t_config.h"

/**
 *  Args && 是一个右值引用，在内存中是一个左值，可以取地址
*/
template<class Args>
void show(Args && arg) {
    // NOTE("左边和右边的参数都是右值引用");
    NOTE(6,"左边和右边的参数都是右值引用");
    std::cout << arg << std::endl;
}


int main(){

    int value=444;
    show<int>(5);
    show(value);
    return 0;
}
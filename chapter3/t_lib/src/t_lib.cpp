#include <t_lib.hpp>
#include <iostream>



T_lib::T_lib(){
    std::cout << "T_lib::T_lib() be Created " << std::endl;
}


T_lib::~T_lib(){
    std::cout << "T_lib::T_lib() be Destorried " << std::endl;
}

void T_lib::showSomething(){
    std::cout << "T_lib::showSomething() be Called " << std::endl;
}


void T_lib::getSomeData(int value){
    // std::cout << "T_lib::getSomeData() be Called " << std::endl;
    std::cout << "T_lib::getSomeData() value = " << value << std::endl;
}


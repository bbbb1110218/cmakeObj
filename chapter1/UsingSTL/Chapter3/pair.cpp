#include <iostream>
#include <utility>
#include <cstring>

//TODO::链接记得加上头文件
#include "t_init.h"  

using std::pair;
using std::cout;
using std::endl;
using std::string;
using std::make_pair;

pair<int,int> getPair(int a,int b){
    return pair<int,int>{a*1.13,b};
}


int main(){
    auto p1=getPair(20,5);
    int a=66;
    SHOW(a);
    SHOW(p1.first);
    SHOW(p1.second);

//生成一对pair
    auto foo_Pair=std::make_pair(3,"hello");

//生成两队
    auto two_Pair=std::make_pair(std::make_pair("name","xigua"),std::make_pair("age",3));
    SHOW(two_Pair.first.first);
    SHOW(two_Pair.first.second);


   
   
    return 0;
}
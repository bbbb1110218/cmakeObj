#include <tuple>
#include <stdexcept>
#include <string>
#include <t_init.h>

//NOTE:: 可以是多个参数的tuple 
//tuple<typename ... > 
//std::get<index>(tuple_obj) 可以得到值



std::tuple<double, char, std::string> get_student(int id) {
    switch (id) {
        case 0:
            return {3.4, 'A', std::string("hello")};
        case 1:
            return {1.2, 'B', std::string("kitty")};
        case 2:
            return {0.4, 'C', std::string("hello,kitty")};
        case 3:
            return {4.2, 'D', std::string("duck")};
        default:
            return std::tuple<double, char, std::string>();
            //NOTE::抛出错误错误
            
           throw std::invalid_argument("id");
    }
}




std::ostream &operator <<(std::ostream &os,const std::tuple<double,char,std::string>& student ){
        os << "score: " <<std::get<0>(student) 
        << "\nanther score: " <<std::get<1>(student) 
        << "\nName :" << std::get<2>(student)
        << "\n";
    return os;
}



int main(){
    auto student=get_student(1);
    std::cout << student;

    //NOTE::可以用申通的::make_tuple<typename ... > get object!!
    auto foo=std::make_tuple<int,char,std::string,std::string >(13,'F',"xigua","butian");
    


    std::cout <<" std::get<0>(foo) = "<< std::get<0>(foo) <<"\n"    //NOTE:: std::get<index>(tuple_Obj) 得到value
              <<" std::get<1>(foo) = "<< std::get<1>(foo) <<"\n"
              <<" std::get<2>(foo) = "<< std::get<2>(foo) <<"\n"
              <<" std::get<3>(foo) = "<< std::get<3>(foo) <<"\n" 
              << std::endl;


    auto mayError=get_student(0);

    //NOTE::转换类型
    int df=static_cast<int>(std::get<0>(mayError));
    


    
    return 0;
}


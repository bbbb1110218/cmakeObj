cmake_minimum_required(VERSION 3.21)


project(t_include 
    VERSION 0.1
    DESCRIPTION  "cpp inter face"
    LANGUAGES CXX)

#定义一个接口
add_library(t_include1 INTERFACE)

#设置接口的头文件目录
target_include_directories(t_include1 INTERFACE include/)

#设置接口的编译特性
target_compile_features(t_include1 INTERFACE cxx_std_17)

#把接口添加到一个组件中
install(TARGETS t_include1 COMPONENT lynxlib)


#把接口的头文件添加到一个组件中的include目录下
install(
    DIRECTORY t_include/
    COMPONENT lynxlib
    DESTINATION include
)

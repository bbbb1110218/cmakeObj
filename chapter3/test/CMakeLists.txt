cmake_minimum_required(VERSION 3.5 )
project(t1)

set(CMAKE_INSTALL_PREFIX "/tmp/tmp")  #设置安装路径




include_directories(include)                            #添加头文件路径 作用域 只在当前目录和子目录中有用
add_executable(testObject src/main.cpp)                 #添加可执行文件
target_compile_features(testObject PRIVATE cxx_std_11)  #设置编译特性

add_library(math_SHARED_Lib SHARED t_math/t_math.cpp)   #添加动态库 math_SHARED_Lib   生成 libmath_SHARED_Lib.dylib
add_library(math_STATIC_Lib STATIC t_math/t_math.cpp)   #添加静态库 math_STATIC_Lib    生成 libmath_STATIC_Lib.a
target_link_libraries(testObject PUBLIC math_SHARED_Lib)        #链接库


install(TARGETS testObject math_SHARED_Lib  math_STATIC_Lib  #安装目标 可以同时安装多个目标
        RUNTIME DESTINATION bin                               #可执行文件安装路径
        LIBRARY DESTINATION lib                               #动态库安装路径 会自动添加lib前缀
        ARCHIVE DESTINATION libstatic)                          #静态库安装路径 会自动添加lib前缀



install(DIRECTORY include/ DESTINATION include)                 

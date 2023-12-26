# cmake_minimum_required(VERSION 3.10)

# # 设置项目名称和版本
# project(MyProject VERSION 1.0)

# # 指定 C++ 标准
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# # 添加子目录
# add_subdirectory(t_init)
# add_subdirectory(t_math)
# add_subdirectory(test)


cmake_minimum_required(VERSION 3.5)


project(cmakeObjs 
VERSION 0.0.1
LANGUAGES CXX C)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)


set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

#TODO::头文件的位置
include_directories(/usr/local/include)

# add_subdirectory(zCmain)

#TODO::就算 加入子文件夹，也要在目标文件里面include一下头文件，而且add_executable之后要target_link_libraries一下
# add_subdirectory(t_init)
# add_subdirectory(t_math)

#TODO::using Cpp
# add_subdirectory(zCppMain)

#TODO::using C


#TODO:: add UsingSTL
# add_subdirectory(UsingSTL)
<<<<<<< HEAD:chapter1/CMakeLists.txt
=======


add_subdirectory(boostSTL)
# target_include_directories()

>>>>>>> main:CMakeLists.txt


set(DEBUGDIR "DEBUGDIR")
add_subdirectory(UsingQt)
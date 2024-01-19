cmake_minimum_required(VERSION 3.21)


project(practiceCpp 
    VERSION 1.0
    DESCRIPTION "Practice C++"
    LANGUAGES CXX
)



# 当前
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)



add_executable(a.out x01_basic/rvalue.cpp)

# target_include_directories(a.out PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/include)


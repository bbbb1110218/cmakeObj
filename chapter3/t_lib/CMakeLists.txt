cmake_minimum_required(VERSION 3.21)


project(HelloWorld VERSION 1.0.0)


add_library(t_mylib STATIC)

#目标添加源文件
target_sources(t_mylib PRIVATE src/t_lib.cpp)

#目标添加头文件
target_include_directories(t_mylib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)


#目标连接
target_link_libraries(t_mylib PUBLIC t_include1)



target_compile_features(t_mylib PUBLIC cxx_std_17)


install(
    TARGETS t_mylib
    COMPONENT lynxlib
)


install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
    COMPONENT lynxlib
    DESTINATION include
)

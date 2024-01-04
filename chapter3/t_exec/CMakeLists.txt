cmake_minimum_required(VERSION 3.21)


project(HelloWorld_Exec VERSION 1.0.0)


add_executable(a.out)

target_sources(a.out PRIVATE src/main.cpp)
target_link_libraries(a.out 
            PUBLIC t_mylib 
            # PUBLIC t_include1
            )
cmake_minimum_required(VERSION 3.15)
project(testfileSystem
        VERSION 1.0.0
        DESCRIPTION "testfileSystem"
        LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
find_package(Boost 1.71.0  COMPONENTS filesystem REQUIRED)

if(Boost_NOT_FOUND)
    message(FATAL_ERROR "Boost Not Found")  
endif()
set(EXEC_NAME ${PROJECT_NAME}.out)

add_executable(${EXEC_NAME} main.cpp)

target_include_directories(${EXEC_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(${EXEC_NAME} PRIVATE ${Boost_LIBRARIES})


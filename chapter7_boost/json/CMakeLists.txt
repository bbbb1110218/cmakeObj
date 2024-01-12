cmake_minimum_required(VERSION 3.20)

project(testBoostjson
    VERSION 1.0
    LANGUAGES CXX
    DESCRIPTION "测试boost库"
)

set(EXEC_NAME ${PROJECT_NAME}.out)


set(CMAKE_CXX_STANDARD 17  )
set(CMAKE_CXX_STANDARD_REQUIRED ON )
set(CMAKR_EXPORT_COMPILE_COMMANDS ON)


set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost COMPONENTS json  ) 


if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost not found")
endif()


include_directories(${Boost_INCLUDE_DIRS}) 
add_executable(${EXEC_NAME} ${CMAKE_CURRENT_LIST_DIR}/main.cpp)
target_link_libraries(${EXEC_NAME} ${Boost_LIBRARIES})


message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")

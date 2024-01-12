cmake_minimum_required(VERSION 3.15)

project(testBoostAsio
    DESCRIPTION "测试boost库里面的ASIO库"
    LANGUAGES CXX
)

# asio 依赖 system 和 thread library
find_package(Boost REQUIRED COMPONENTS system thread)


if(NOT Boost_FOUND)
    # message(FATAL_ERROR "BOOST NOT FOUND")  
    message(STATUS "BOOST NOT FOUND")
    
endif()

message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
# OUTPUT:Boost_INCLUDE_DIRS: /usr/local/include

message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
# Boost_LIBRARIES: Boost::system;Boost::thread


message(STATUS "CMAKE_SYSTEM_PREFIX_PATH = ${CMAKE_SYSTEM_PREFIX_PATH}")


# message(STATUS "CMAKR_PREFIX_PATH = ${CMAKE_PREFIX_PATH}")
# message(STATUS "CMAKR_MODULE_PATH = ${CMAKE_MODULE_PATH}")
# message(STATUS "CMAKE_FRAMEWORK_PATH = ${CMAKE_FRAMEWORK_PATH}")
# message(STATUS "CMAKE_APPBUNDLE_PATH = ${CMAKE_APPBUNDLE_PATH}")



add_subdirectory(threadPool)
#return 下面不会执行
return ()  


add_executable(${PROJECT_NAME}.out main.cpp)
target_include_directories(${PROJECT_NAME}.out PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME}.out PRIVATE ${Boost_LIBRARIES})



add_executable(muti_thread.out mutiThread.cpp)
target_include_directories(muti_thread.out PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(muti_thread.out PRIVATE ${Boost_LIBRARIES} pthread)







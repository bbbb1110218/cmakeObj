cmake_minimum_required(VERSION 3.20)
project(testBOOST
    DESCRIPTION "测试boost库 只需要加入对应的文件夹就可以了")

set(CMAKE_EXPORT_NO_PACKAGE_REGISTRY ON)

if(LINUX)
    include($ENV{HOME}/app/cmake/.config.cmake)
endif()

# json库
#add_subdirectory(json)

# 文件系统
#add_subdirectory(fileSystem)

#网络库
add_subdirectory(asio)
# SHOW_CONFIG()

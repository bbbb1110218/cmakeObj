cmake_minimum_required(VERSION 3.15)

project(TOTAL)

if(APPLE OR LINUX)
    include("$ENV{HOME}/app/cmake/.config.cmake")
endif()
add_subdirectory(chapter0_C)
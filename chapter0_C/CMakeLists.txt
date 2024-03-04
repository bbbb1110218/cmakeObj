cmake_minimum_required(VERSION 3.21)

project(testingC_lib
        VERSION 0.0.1
        DESCRIPTION "测试C库"
        LANGUAGES C)

add_executable(testingString.out src/testString.c)
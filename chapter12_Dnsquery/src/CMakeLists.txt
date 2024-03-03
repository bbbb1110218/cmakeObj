cmake_minimum_required(VERSION 3.10)

project(TEST_DNS)

set(TEST_EXEC_NAME "test_dns.out")

# set(LIB_DIR "../lib")
set(LIB_DIR "${CMAKE_CURRENT_LIST_DIR}/../lib")
set(TEXT_DIR "../test")
set(LIB_INCLUDE "${LIB_DIR}/include")
include_directories(${LIB_INCLUDE})



add_library(dnsLIB SHARED "${LIB_DIR}/dnsLib.c" )

add_library(tsocketLIB SHARED "${LIB_DIR}/t_socket.c" )


# add_executable(${TEST_EXEC_NAME} ${CMAKE_CURRENT_LIST_DIR}/main.c)


# target_link_libraries(${TEST_EXEC_NAME} 
#     PUBLIC dnsLIB
#     PUBLIC tsocketLIB)

#show DEBUG
# target_compile_definitions(${TEST_EXEC_NAME} PRIVATE DEBUG=1)

# add_executable(${TEST_EXEC_NAME}  ${TEXT_DIR}/main.c)
# add_executable(test2.out ${TEXT_DIR}/main2.c)

#设置函数自动输出 main.c out main.out
FUNCTION(SET_FILE_OUTPUT SOURCE_FULL_FILE)

    get_filename_component(TMP_FILE_NAME ${SOURCE_FULL_FILE} NAME_WE)

    set(FILE_EXEC_NAME ${TMP_FILE_NAME}.out)

    add_executable(${FILE_EXEC_NAME} ${SOURCE_FULL_FILE})

    target_link_libraries(${FILE_EXEC_NAME} 
        PUBLIC dnsLIB
        PUBLIC tsocketLIB)
    target_compile_definitions(${FILE_EXEC_NAME} 
    # 设置宏
        PRIVATE DEBUG=1
        PUBLIC MARCO_DNS_SERVER="192.168.50.1"
        )
endfunction()

SET_FILE_OUTPUT(${CMAKE_CURRENT_LIST_DIR}/main.c)

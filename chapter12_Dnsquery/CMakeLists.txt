cmake_minimum_required(VERSION 3.15)




set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_GENERATOR "Unix Makefiles")

project(QueryDNS
        DESCRIPTION "请求DNS服务器解析域名为IP地址"
        LANGUAGES C)


# set(EXEC_NAME "query_dns")
# set(SOURCE_DIR "./src")
# add_executable(${EXEC_NAME} ${SOURCE_DIR}/dnsQuery.c)
# set(EXEC_NAME2 "query_dns2")
# set(SOURCE_DIR "./src")
# add_executable(${EXEC_NAME2} ${SOURCE_DIR}/dnsQuery2.c)
# target_compile_options(${EXEC_NAME} PRIVATE -g)
# target_compile_options(${EXEC_NAME2} PRIVATE -g)
# add_subdirectory(./test)



add_subdirectory(./src)






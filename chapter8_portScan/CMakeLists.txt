cmake_minimum_required(VERSION 3.15)

project(ScanPort
        VERSION 1.1.1
        DESCRIPTION "Scan Port"
        LANGUAGES C)


include($ENV{HOME}/app/cmake/.config.cmake)        

add_executable(scanTcpPort.out portScan.c)

add_executable(scanPort.out scanTCPUDP.c)

add_executable(getUrlIp.out UrlToIp.c)

install(
    TARGETS scanTcpPort.out  scanPort.out getUrlIp.out
    RUNTIME DESTINATION bin
    )
# export LDFLAGS="-L/opt/homebrew/opt/jpeg/lib"
# export CPPFLAGS="-I/opt/homebrew/opt/jpeg/include"


cmake_minimum_required(VERSION 3.1)

project(test_jpgLib
    VERSION 0.0.1
    DESCRIPTION "测试jpgLib"
    LANGUAGES C
)

include($ENV{HOME}/app/cmake/.config.cmake)

set(JEPG_INCLUDE_DIR "/opt/homebrew/opt/jpeg/include")
set(JEPG_LIBRARY "/opt/homebrew/opt/jpeg/lib")

# set(CMAKE_INSTALL_PREFIX "/tmp/tmp")


set(CMAKE_C_STANDARD 11)

add_executable(test_jpgLib)

target_sources(test_jpgLib
    PRIVATE
        jpeg.c
)

target_include_directories(test_jpgLib
    PRIVATE
        ${JEPG_INCLUDE_DIR}
)
target_link_directories(test_jpgLib
    PRIVATE
        ${JEPG_LIBRARY}
)

target_link_libraries(test_jpgLib
    PRIVATE
        jpeg)

# 安装文件到文档里面 ${CMAKE_INSTALL_PREFIX}/doc
install(FILES test_jpgLib.md
    DESTINATION doc
    )

# 安装可执行文件到bin 目录 ${CMAKE_INSTALL_PREFIX}/bin
install(TARGETS test_jpgLib
    RUNTIME DESTINATION bin
    )


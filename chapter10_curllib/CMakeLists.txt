cmake_minimum_required(VERSION 3.21)


project(testCurl
    VERSION 0.0.1
    DESCRIPTION "C语言测试CURL库"
    LANGUAGES C
    )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#找库
find_package(CURL REQUIRED)


# add_executable(${PROJECT_NAME}.out)



# target_sources(${PROJECT_NAME}.out
#     PRIVATE
#         src/main2.c
#     )

# #如果库没找到
# if(NOT CURL_FOUND)
#     message(FATAL_ERROR "CURL not found")
# endif()

# #设置头文件路径
# target_include_directories(${PROJECT_NAME}.out
#     PRIVATE
#         ${CURL_INCLUDE_DIRS}
#     )
# #设置链接库
# target_link_libraries(${PROJECT_NAME}.out
#     PRIVATE
#         ${CURL_LIBRARIES}
# )

# TODO 设置要编译的文件  有函数可以直接编译全部
set(SRC_LIST main.c)


function(MAKE_EXEC ARG)
# //获取文件名
    get_filename_component(EXEC_NAME ${ARG} NAME_WE)
    add_executable(${EXEC_NAME}.out src/${ARG})
    target_include_directories(${EXEC_NAME}.out
        PRIVATE
            ${CURL_INCLUDE_DIRS}
        )
    target_link_libraries(${EXEC_NAME}.out
        PRIVATE
            ${CURL_LIBRARIES}
        )
    target_compile_definitions(${EXEC_NAME}.out
        PRIVATE
            DEEPLAPI=${DEEPLAPI}
        )
endfunction()



foreach(ARG IN LISTS SRC_LIST)
    MAKE_EXEC(${ARG})
endforeach()















# execute_process(
#     COMMAND curl-config --cflags
#     OUTPUT_VARIABLE CURL_CFLAGS
#     OUTPUT_STRIP_TRAILING_WHITESPACE
#     )


get_filename_component(SRC_FILE src/main.c ABSOLUTE)

set(PREPROCESS_FILE ${CMAKE_BINARY_DIR}/preprocess.c)


add_custom_command(
    OUTPUT ${PREPROCESS_FILE}
    COMMAND ${CMAKE_C_COMPILER} -E -P ${SRC_FILE} -o ${PREPROCESS_FILE} ${CURL_CFLAGS}
    DEPENDS ${SRC_FILE}
    )

add_custom_target(preprocess DEPENDS ${PREPROCESS_FILE})


# install(TARGETS deepLcurl.out
#     RENAME deepl
#     RUNTIME DESTINATION bin 
    
# )


# not mac
if(LINUX)
    set(CMAKE_INSTALL_PREFIX "$ENV{HOME}/app")
endif()

add_executable(deepl)

target_compile_definitions(deepl
    PRIVATE
        DEEPLAPI=$ENV{DEEPLAPI}
)

target_sources(deepl
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src/deepLcurl.c
)

target_include_directories(deepl
    PRIVATE
        ${CURL_INCLUDE_DIRS}
)
target_link_libraries(
    deepl 
    PRIVATE
        ${CURL_LIBRARIES}
)

install(TARGETS deepl
    RUNTIME DESTINATION bin 
)

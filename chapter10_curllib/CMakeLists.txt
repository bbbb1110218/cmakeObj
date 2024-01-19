cmake_minimum_required(VERSION 3.21)


project(testCurl
    VERSION 0.0.1
    DESCRIPTION "C语言测试CURL库"
    LANGUAGES C
    )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#找库
find_package(CURL REQUIRED)



# TODO 设置要编译的文件  有函数可以直接编译全部
set(SRC_LIST main.c deepl.c)



#定义一个函数
function(MAKE_EXEC ARG)
# //获取文件名称组件，可以通过参数不要后缀
    get_filename_component(EXEC_NAME ${ARG} NAME_WE)
    add_executable(${EXEC_NAME}.out src/${ARG})
    
    #目标添加头文件
    target_include_directories(${EXEC_NAME}.out
        PRIVATE
            ${CURL_INCLUDE_DIRS}
        )
    
    # 连接库
    target_link_libraries(${EXEC_NAME}.out
        PRIVATE
            ${CURL_LIBRARIES}
        )

    #编译的时候添加预编译
    target_compile_definitions(${EXEC_NAME}.out
        PRIVATE
            URL_HEAD_INCLUDE_API=${URL_HEAD_INCLUDE_API}
        )
endfunction()



foreach(ARG IN LISTS SRC_LIST)
    MAKE_EXEC(${ARG})
endforeach()







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

add_executable(deepll)

target_compile_definitions(deepll
    PRIVATE
        URL_HEAD_INCLUDE_API=$ENV{URL_HEAD_INCLUDE_API}
)

target_sources(deepll
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src/deepl.c
)

target_include_directories(deepll
    PRIVATE
        ${CURL_INCLUDE_DIRS}
)
target_link_libraries(
    deepll 
    PRIVATE
        ${CURL_LIBRARIES}
)

install(TARGETS deepll
    RUNTIME DESTINATION bin 
)

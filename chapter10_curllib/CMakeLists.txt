# FILEPATH: /home/min122218/Github/cmakeObj/chapter10_curllib/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

project(testCurl
    VERSION 0.0.1
    DESCRIPTION "C语言测试CURL库"
    LANGUAGES C
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find the CURL library
find_package(CURL REQUIRED)



# TODO 设置要编译的文件  有函数可以直接编译全部
set(SRC_LIST main.c deepl.c)



#定义一个函数
function(MAKE_EXEC ARG)
# //获取文件名称组件，可以通过参数不要后缀
    get_filename_component(EXEC_NAME ${ARG} NAME_WE)
    # Create the executable target
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

# List of source files to compile
set(SRC_LIST main.c deepl.c)

# Create executable targets for each source file
foreach(ARG IN LISTS SRC_LIST)
    MAKE_EXEC(${ARG})
endforeach()

# Get the absolute path of the main.c source file
get_filename_component(SRC_FILE src/main.c ABSOLUTE)

# Set the path for the preprocessed file
set(PREPROCESS_FILE ${CMAKE_BINARY_DIR}/preprocess.c)

# Create a custom command to preprocess the source file
add_custom_command(
    OUTPUT ${PREPROCESS_FILE}
    COMMAND ${CMAKE_C_COMPILER} -E -P ${SRC_FILE} -o ${PREPROCESS_FILE} ${CURL_CFLAGS}
    DEPENDS ${SRC_FILE}
)

# Create a custom target for the preprocess command
add_custom_target(preprocess DEPENDS ${PREPROCESS_FILE})

# Create an executable target deepll
add_executable(deepll)

# Set compile definitions for the deepll target
target_compile_definitions(deepll
    PRIVATE
        URL_HEAD_INCLUDE_API=${URL_HEAD_INCLUDE_API}
)

# Set source files for the deepll target
target_sources(deepll
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src/deepl.c
)

# Set include directories for the deepll target
target_include_directories(deepll
    PRIVATE
        ${CURL_INCLUDE_DIRS}
)

# Link the deepll target with the CURL library
target_link_libraries(
    deepll 
    PRIVATE
        ${CURL_LIBRARIES}
)

# Install the deepll target to the bin directory
install(TARGETS deepll
    RUNTIME DESTINATION bin 
)



## JASON 库
# 在 CMake 中，你可以使用 `find_package` 命令来查找 `jansson` 库。以下是一个简单的 `CMakeLists.txt` 文件示例，展示了如何使用 `find_package` 来查找 `jansson`：

# ```cmake
# cmake_minimum_required(VERSION 3.10)
# project(MyProject)

# set(CMAKE_C_STANDARD 99)

# find_package(Jansson REQUIRED)

# add_executable(MyProject main.c)
# target_link_libraries(MyProject ${JANSSON_LIBRARIES})
# include_directories(${JANSSON_INCLUDE_DIRS})
# ```

# 在这个示例中，我们首先使用 `find_package(Jansson REQUIRED)` 来查找 `jansson` 库。然后，我们使用 `target_link_libraries` 命令来链接 `jansson` 库，使用 `include_directories` 命令来添加 `jansson` 的头文件目录。

# 请注意，`find_package(Jansson REQUIRED)` 需要 `jansson` 库提供 CMake 的 `FindJansson.cmake` 或 `jansson-config.cmake` 文件。如果 `jansson` 库没有提供这些文件，你可能需要手动指定 `jansson` 的库文件和头文件目录。

# 另外，你需要确保 `CMake` 能在其模块路径中找到 `FindJansson.cmake` 或 `jansson-config.cmake`。你可以通过添加路径到 `CMAKE_MODULE_PATH` 变量来实现这一点。例如：

# ```cmake
# list(APPEND CMAKE_MODULE_PATH "/path/to/your/cmake/modules")
# ```

# find_package(Jansson REQUIRED)

# if(NOT jansson_FOUND)

#     message(FATAL_ERROR "jansson be found")
# endif()


foreach(VAR IN  ${CMAKE_MODULE_PATH})
    message(STATUS "VAR >>>>>>>>>> : ${VAR}")
    
endforeach()

CMAKE_MINIMUM_REQUIRED(VERSION 3.21)

project(t_project
    VERSION 1.0.0  
    DESCRIPTION "nothing"
    LANGUAGES C CXX

)

# set(NEEDDEBUG TRUE)


#这段话的意思是，如果是直接调用cmake，那么就会执行这个函数
include(functions.cmake)


# set(NEEDTEST FALSE CACHE BOOL "测试")
# set(ISNEEDTEST)

# if(DEFINED NEEDTEST AND (NEEDTEST STREQUAL "1"))
#     message("need test")
# else()
#     message("no need test")
# endif()
    


# set(NEED_A_OBJ TRUE CACHE BOOL "defined a new obj")

set(CMAKE_C_STANDARD 11)

# SHOW(CMAKE_CPACK_COMMAND)


# SHOW(CMAKE_C_COMPILER)
# SHOW(CMAKE_C_EXTENSIONS)
# SHOW(CMAKE_C_STANDARD)
# SHOW(CMAKE_C_KNOWN_FEATURES)
# SHOW(CMAKE_CXX_COMPILER)
# CURRENTSHOW(HELLO)

set(HELLO "helloValue")
DEBUG(HELLO)


add_subdirectory(t_head)
add_subdirectory(t_lib)
add_subdirectory(t_exec)

# CURRENTSHOW(HELLO)


if(DEFINED ENV{MYENVDIR})
    message("MYENVDIR is $ENV{MYENVDIR}")
else()
    message("MYENVDIR is not defined")
endif()
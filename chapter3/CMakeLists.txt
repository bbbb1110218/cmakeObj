CMAKE_MINIMUM_REQUIRED(VERSION 3.21)

project(t_project
    VERSION 1.0.0  
    DESCRIPTION "nothing"

)

set(NEED_A_OBJ TRUE CACHE BOOL "defined a new obj")

add_subdirectory(t_head)
add_subdirectory(t_lib)
add_subdirectory(t_exec)

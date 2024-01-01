cmake_minimum_required(VERSION 3.23)
project(chapter2)




# 放在目标文件的BIN文件夹
# add_subdirectory(src bin) 


# include_directories(lib)

# target_include_directories(cha)
# include_directories(lib)


# add_subdirectory(lib lib)

add_executable(${PROJECT_NAME}.out src/main.cpp)

add_subdirectory(lib)

include_directories(lib)

# target_link_libraries(${PROJECT_NAME}.out addlib)


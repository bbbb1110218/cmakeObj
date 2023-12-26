cmake_minimum_required(VERSION 3.23)
project(chapter2)




# 放在目标文件的BIN文件夹
add_subdirectory(src bin) 


include_directories(lib)

# target_include_directories(cha)


add_subdirectory(lib lib)

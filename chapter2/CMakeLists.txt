cmake_minimum_required(VERSION 3.23)
project(chapter2)




# 放在目标文件的BIN文件夹
# add_subdirectory(src bin) 


# include_directories(lib)

# target_include_directories(cha)
# include_directories(lib)


# add_subdirectory(lib lib)
# 这句话的意思是在lib文件夹下面找CMakeLists.txt文件，然后执行里面的内容
# 也就是说，这句话的意思是在lib文件夹下面生成一个lib文件夹，然后在lib文件夹下面生成一个addlib的库文件

add_executable(${PROJECT_NAME}.out src/main.cpp)

add_subdirectory(lib)

include_directories(lib)

# target_link_libraries(${PROJECT_NAME}.out addlib)


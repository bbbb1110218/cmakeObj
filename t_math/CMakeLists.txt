
# # 添加库
# add_library(t_math SHARED
#     source1.cpp
#     source2.cpp
#     # 其他源文件
# )

# # 指定公共头文件的路径
# target_include_directories(t_math PUBLIC
#     ${CMAKE_CURRENT_SOURCE_DIR}/include
# )

add_library(t_math 
    SHARED t_math.c)

target_include_directories(t_math PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
   
)
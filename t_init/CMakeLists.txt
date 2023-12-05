# 创建一个接口库
add_library(t_init INTERFACE)

# 设置这个接口库的包含路径
target_include_directories(t_init INTERFACE
${CMAKE_CURRENT_SOURCE_DIR}
)

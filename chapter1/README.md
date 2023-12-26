# Notice:
    add_subdirectory()                会把子文件夹的CMakeLists.txt 加入进来
    target_link_library()                       目标可以链接多个库文件，不可以分开link库两次 要一次全部链接完，记得在目标文件 include 库的头文件
    add_library(t_init INTERFACE)               只有头文件定义没有实现 INTERFACE 是接口
    target_include_directories(t_init INTERFACE             设置这个接口库的包含路径
    ${CMAKE_CURRENT_SOURCE_DIR} )                           CMAKE_CURRENT_SOURCE_DIR 当前文件路径 也可以${CMAKE_CURRENT_SOURCE_DIR}/include 当前文件夹的include文件里面


# info

    CMAKE_CXX_COMPILER:FILEPATH=/Library/Developer/CommandLineTools/usr/bin/c++         设置CXX 编译器路径
    CMAKE_C_COMPILER:FILEPATH=/Library/Developer/CommandLineTools/usr/bin/cc            设置C编译器路径


# Note::   
    用//NOTE:: 笔记的格式 高亮代码 可以复习用
    View: Move Active Editor into a New Window vscode 移动窗口
    快捷键command+o ，command+0
    

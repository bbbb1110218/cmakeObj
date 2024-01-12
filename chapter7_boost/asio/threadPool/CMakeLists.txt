cmake_minimum_required(VERSION 3.20)

add_executable(MutiServerUsingPthreadPool.out)

target_sources(MutiServerUsingPthreadPool.out PRIVATE
    main.cpp
)


target_include_directories(MutiServerUsingPthreadPool.out PRIVATE
    ${Boost_INCLUDE_DIRS}
)

target_link_libraries(MutiServerUsingPthreadPool.out PRIVATE
    ${Boost_LIBRARIES}
)


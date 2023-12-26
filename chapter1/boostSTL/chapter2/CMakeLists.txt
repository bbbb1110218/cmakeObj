

# include_directories(/usr/local/include)

add_executable(testPair
    ${CMAKE_CURRENT_SOURCE_DIR}/testPair.cpp)


# target_include_directories(testPair PRIVATE /usr/local/include)
cmake_minimum_required(VERSION 3.12)

project(objUseQt)

add_executable(${PROJECT_NAME} usingQt.cpp)


set(CXXFLAGS "")
list(APPEND CXXFLAGS "-I/usr/local/include")
list(APPEND CXXFLAGS "-I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1")
list(APPEND CXXFLAGS "-I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/15.0.0/include")
list(APPEND CXXFLAGS "-I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include")
list(APPEND CXXFLAGS "-I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include")



if(NOT DEFINED DEBUGDIR)
    set(DEBUGDIR "DEBUGDIR")
    message(STATUS "---------DEBUGDIR note be defined")
else()
    message(STATUS "---------DEBUGDIR  be defined2")
endif()





add_custom_command(
    OUTPUT "${CMAKE_BINARY_DIR}/${DEBUGDIR}/usingQt.cc"
    # COMMAND ${CMAKE_CXX_COMPILER} -E ${CMAKE_CURRENT_SOURCE_DIR}/usingQt.cpp  ${CXXFLAGS} -o "${CMAKE_BINARY_DIR}/usingQt.cc"
    COMMAND g++ -E ${CMAKE_CURRENT_SOURCE_DIR}/usingQt.cpp  ${CXXFLAGS} -o "${CMAKE_BINARY_DIR}/${DEBUGDIR}/usingQt.cc"
    COMMAND echo "Running custom command for usingQt.cc-------"
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/usingQt.cpp
)

message(STATUS "----------------FUCK____________________") 


add_custom_target(
    ep 
    DEPENDS "${CMAKE_BINARY_DIR}/${DEBUGDIR}/usingQt.cc"
)


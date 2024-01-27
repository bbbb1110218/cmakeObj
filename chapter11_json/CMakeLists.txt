cmake_minimum_required(VERSION 3.21)


project(UsingJson
    DESCRIPTION "Using Json"
    LANGUAGES C
)

set(CMAKE_PREFIX_PATH "/usr/local")

# find_package(Jansson REQUIRED)

if(NOT Jansson_FOUND)
    # message(FATAL_ERROR "Jansson NOT found")
else()
    message(STATUS "Jansson found")
    message(STATUS "Jansson include dir: ${Jansson_INCLUDE_DIRS}")
    message(STATUS "Jansson libraries: ${Jansson_LIBRARIES}")
    message(STATUS "Jansson definitions: ${Jansson_DEFINITIONS}")
    message(STATUS "Jansson version: ${Jansson_VERSION}")
    message(STATUS "Jansson version major: ${Jansson_VERSION_MAJOR}")
    message(STATUS "Jansson version minor: ${Jansson_VERSION_MINOR}")
    message(STATUS "Jansson version patch: ${Jansson_VERSION_PATCH}")
    message(STATUS "Jansson version string: ${Jansson_VERSION_STRING}")
    message(STATUS "Jansson version hex: ${Jansson_VERSION_HEX}")
    message(STATUS "Jansson version check: ${Jansson_VERSION_CHECK}")
    message(STATUS "Jansson version check major: ${Jansson_VERSION_CHECK_MAJOR}")
    message(STATUS "Jansson version check minor: ${Jansson_VERSION_CHECK_MINOR}")
    message(STATUS "Jansson version check patch: ${Jansson_VERSION_CHECK_PATCH}")

    include_directories(${Jansson_INCLUDE_DIRS})
    link_directories(${Jansson_LIBRARIES})
    add_definitions(${Jansson_DEFINITIONS})


endif()

add_executable(UsingJson.out
    src/mainjson.c
)

target_link_libraries(UsingJson.out
    jansson)
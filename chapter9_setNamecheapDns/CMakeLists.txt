cmake_minimum_required(VERSION 3.15)

include($ENV{HOME}/app/cmake/.config.cmake)

project(GetIpAndSetToNamecheap
   LANGUAGES C
)


#TODO::查找CURL库
find_package(CURL REQUIRED)

add_executable(getPublicIpself.out)

target_sources(getPublicIpself.out
    PRIVATE
    getPublicIpself.c
)

#这行其实不用写 好像会自动链接
target_include_directories(getPublicIpself.out
    PRIVATE
    ${CURL_INCLUDE_DIRS}
)

#TODO::链接CURL库
target_link_libraries(getPublicIpself.out
    PRIVATE
    ${CURL_LIBRARIES}
)

install(TARGETS getPublicIpself.out
    RUNTIME DESTINATION bin
)


add_executable(setNamecheapByApi.out setNamecheapByApi.c)



# cmake set compile definition to c 
# 在.vscode setting.json中设置 cmake.environment set namecheapName and namecheapPasswd
# target_compile_definitions(setNamecheapByApi.out
#     PRIVATE
#     NAMECHEAPNAME=${namecheapName}
#     NAMECHEAPPASSWD=${namecheapPasswd}
#     NAMECHEAPDOMAIN=${NAMECHEAPDOMAIN}
#     NAMECHEAPHOST=${NAMECHEAPHOST}
# )



#TODO::链接CURL库
target_link_libraries(setNamecheapByApi.out
    PRIVATE
    ${CURL_LIBRARIES}
)


#build 完之后 使用方法 make runSetNamecheapByApi
add_custom_target(runSetNamecheapByApi
# 高级 
    COMMAND bash -c "./getPublicIpself.out | xargs ./setNamecheapByApi.out"
    DEPENDS getPublicIpself.out setNamecheapByApi.out
)
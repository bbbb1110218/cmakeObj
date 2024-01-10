
# set(NEED_DEBUG  CACHE BOOL "需要debug")

function(SHOW VAR)
    set(COLORED_MESSAGE TRUE)
    if(NOT DEFINED ${VAR})
        message([ERROR] "[${VAR}] IS NOT DEFINED" [ERROR])
    else()
        message([ERROR] "[${VAR}] = [${${VAR}}]" [ERROR])
    endif()
endfunction()



function(CURRENTSHOW VAR)
    message("current cmakefile start:${CMAKE_CURRENT_LIST_FILE}")
    SHOW(${VAR})
    message("current cmakefile end:${CMAKE_CURRENT_LIST_FILE}")
endfunction()



function(DEBUG VAR)
    if((DEFINED ENV{NEED_DEBUG}) OR (DEFINED NEED_DEBUG) OR (DEFINED NEEDDEBUG))
        # set(NEED_DEBUG $ENV{NEED_DEBUG})
    # endif()
    # #先判断是否定义了NEED_DEBUG 直接取值会报错
    # if()
        # if((${NEED_DEBUG}) OR (${NEEDDEBUG}))
            CURRENTSHOW(${VAR})
        # endif()
    endif()
endfunction()
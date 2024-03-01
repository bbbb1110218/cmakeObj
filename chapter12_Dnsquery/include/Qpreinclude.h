#ifndef __PRE_INCLUDE_H__
#define __PRE_INCLUDE_H__

#include <stdio.h>

#if defined(NEED_DEBUG) 
    #warning "DEBUG MODEL"
#else
    #warning "NO DEBUG MODEL"
#endif 

#ifndef NEED_DEBUG 
#else 
#endif 


//测试大小段
#define INT32_ADDR ((void *)&((unsigned int)1))
#define IS_BIG_ENDIAN (*(unsigned char)INT32_ADDR == 0)
#define IS_LITTLE_ENDIAN (*(unsigned char)INT32_ADDR == 1)
#define INT32_ADDR_ &((unsigned int)1)

#define __STR(x) #x
#define STR(x) __STR(x)
#define SHOW_STR(x) printf("%s:",STR(x))

//debug 输出unsigned short 
#define SHOW_FLAGS(INFO,_value)    do { \
    SHOW_STR(INFO); \
    int _size= (sizeof(_value) * 8) -1; \
    do { \
        printf("%s",((_value >> _size ) & 0x01 ) ? "1":"0"); \
        if((_size % 8 == 0)&& (_size !=(sizeof(_value) * 8) -1 )) printf("%s"," "); \
        _size--; \
    } while(_size >= 0); \
    printf("%s","\n"); \
} while(0)




#endif 
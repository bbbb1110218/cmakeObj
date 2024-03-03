#ifndef __PRE_INCLUDE_H__
#define __PRE_INCLUDE_H__

#define INT32_ADDR ((void *)&((unsigned int)1))
#define IS_BIG_ENDIAN (*(unsigned char)INT32_ADDR == 0)
#define IS_LITTLE_ENDIAN (*(unsigned char)INT32_ADDR == 1)
#define INT32_ADDR_ &((unsigned int)1)

// #if defined(NEED_DEBUG) 
//     #error "DEBUG MODEL"
// #else
//     #error "NO DEBUG MODEL"
// #endif 

#endif 
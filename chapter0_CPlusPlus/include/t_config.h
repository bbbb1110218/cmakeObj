#ifndef T_CONFIG_H
#define T_CONFIG_H


#include <stdio.h>


#define T_NOTE(X) 

#define NOTE1(note) printf("NOTE: %s:%s:%d: %s\n",__FILE__,__FUNCTION__,__LINE__,note)
#define NOTE(lineo,note) printf("[lineno:%d]: %s\n",lineo,note)


#endif
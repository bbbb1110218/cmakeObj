#ifndef T_INIT_H
#define T_INIT_H



 
#ifdef __cplusplus   //include the base Head file
    #include <iostream>
    #define SHOW(x) std::cout << " [ function: "<< __FUNCTION__ << "  line:"<< __LINE__ << "  ]"<< #x << " = " << x <<std::endl 
#else 
    #include <stdio.h>
    // #error "Can't Format the argument !!"
    // #define SHOW(x) printf("Not define TODO")  //TODO::
#endif



#ifdef __cplusplus
extern "C" {
#endif 

    #define t_abs(x) (x < 0)? (-x) :(x) 


#ifdef __cplusplus
}
#endif 










#endif 
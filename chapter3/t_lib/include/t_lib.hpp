#ifndef T_LIB_HPP
#define T_LIB_HPP

#include <father.hpp>

class T_lib : public Father{
    public:
        T_lib();
        ~T_lib();
        void showSomething();
        void getSomeData(int value);
};




#endif 
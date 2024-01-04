#ifndef FATHER_HPP
#define FATHER_HPP

class Father{
        // int _data;
    public:
        virtual ~Father(){};
        virtual void showSomething() = 0;
        virtual void getSomeData(int value) =0;
        
    
};
#endif 
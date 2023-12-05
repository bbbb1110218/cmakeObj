#ifndef T_MATH_H
#define T_MATH_H
#ifdef __cplusplus
extern "C" {
#endif



int add(int x,int y);
int sub(int x,int y);


#ifdef __cplusplus
};
#endif

#ifdef __cplusplus
namespace ML{
    using ::add;
    using ::sub;
}
#endif

#endif
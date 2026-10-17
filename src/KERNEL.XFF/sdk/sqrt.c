#include "common.h"

double __ieee754_sqrt(double x);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/sqrt", sqrt);
double sqrt(double x)
{
    return __ieee754_sqrt(x);
}

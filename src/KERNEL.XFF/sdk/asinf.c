#include "common.h"

float __ieee754_asinf(float x);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/asinf", asinf);
float asinf(float x)
{
    return __ieee754_asinf(x);
}

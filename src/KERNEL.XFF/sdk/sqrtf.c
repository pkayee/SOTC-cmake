#include "common.h"

float __ieee754_sqrtf(float x);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/sqrtf", sqrtf);
float sqrtf(float x)
{
    return __ieee754_sqrtf(x);
}

#include "common.h"

float __ieee754_acosf(float x);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/acosf", acosf);
float acosf(float x)
{
    return __ieee754_acosf(x);
}

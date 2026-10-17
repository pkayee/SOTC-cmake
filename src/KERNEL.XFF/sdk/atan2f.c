#include "common.h"

float __ieee754_atan2f(float y, float x);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/atan2f", atan2f);
float atan2f(float y, float x)
{
    return __ieee754_atan2f(y, x);
}

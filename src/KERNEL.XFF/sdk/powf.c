#include "common.h"

float __ieee754_powf(float x, float y);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/powf", powf);
float powf(float x, float y)
{
    return __ieee754_powf(x, y);
}

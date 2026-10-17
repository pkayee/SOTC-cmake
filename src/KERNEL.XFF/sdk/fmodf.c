#include "common.h"

float __ieee754_fmodf(float x, float y);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/sdk/fmodf", fmodf);
float fmodf(float x, float y)
{
    return __ieee754_fmodf(x, y);
}

#include "common.h"

float powf(float, float);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/power", iosPowf);
f32 iosPowf(f32 x, f32 y)
{
    return powf(x, y);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/power", iosFastPowf);
f32 iosFastPowf(f32 x, f32 y)
{
    return powf(x, y);
}

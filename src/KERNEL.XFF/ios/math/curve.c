#include "common.h"

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/curve", iosCubicBezier);
float iosCubicBezier(float *p, float t)
{
    float u = 1.0f - t;
    return u * u * p[0] + (u + u) * t * p[1] + t * t * p[2];
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/curve", iosCubicInterVectorXYZ);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/curve", iosFourthBezier);
float iosFourthBezier(float *p, float t)
{
    float u = 1.0f - t;
    return u * u * u * p[0] + u * u * 3.0f * t * p[1] + u * 3.0f * (t * t) * p[2] + t * t * t * p[3];
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/curve", iosCubicBezierVectorXYZ);

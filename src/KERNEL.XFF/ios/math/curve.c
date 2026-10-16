#include "common.h"

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/curve", iosCubicBezier);
float iosCubicBezier(float *p, float t)
{
    float u = 1.0f - t;
    return u * u * p[0] + (u + u) * t * p[1] + t * t * p[2];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/curve", iosCubicInterVectorXYZ);
void iosCubicInterVectorXYZ(void *dst, void *a, void *b, float *p, float t)
{
    float u = 1.0f - t;
    float r = u * u * p[0] + (u + u) * t * p[1] + t * t * p[2];
    asm volatile(
        "mfc1 $8, %4;"
        "qmtc2.ni $8, $vf7;"
        "lqc2 $vf5, 0(%1);"
        "lqc2 $vf6, 0(%2);"
        "vsubx.w $vf8, $vf0, $vf7x;"
        "vmulax.xyz ACC, $vf5, $vf7x;"
        "vmaddw.xyz $vf5, $vf6, $vf8w;"
        "sqc2 $vf5, 0(%0)"
        : : "r"(dst), "r"(a), "r"(b), "r"(p), "f"(r) : "$8", "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/curve", iosFourthBezier);
float iosFourthBezier(float *p, float t)
{
    float u = 1.0f - t;
    return u * u * u * p[0] + u * u * 3.0f * t * p[1] + u * 3.0f * (t * t) * p[2] + t * t * t * p[3];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/curve", iosCubicBezierVectorXYZ);
static inline void ScaleXYZ(void *dst, void *src, float s)
{
    asm volatile(
        "lqc2 $vf5, 0(%1);"
        "qmtc2.ni %2, $vf6;"
        "vmulx.xyz $vf5, $vf5, $vf6x;"
        "sqc2 $vf5, 0(%0)"
        : : "r"(dst), "r"(src), "r"(s));
}

static inline void AddXYZ(void *dst, void *a, void *b)
{
    asm volatile(
        "lqc2 $vf5, 0(%1);"
        "lqc2 $vf6, 0(%2);"
        "vadd.xyz $vf5, $vf5, $vf6;"
        "sqc2 $vf5, 0(%0)"
        : : "r"(dst), "r"(a), "r"(b));
}

void iosCubicBezierVectorXYZ(float *dst, float (*p)[4], float t)
{
    float tmp[4] __attribute__((aligned(16)));
    float u = 1.0f - t;

    ScaleXYZ(dst, p[0], u * u);
    ScaleXYZ(tmp, p[1], (u + u) * t);
    AddXYZ(dst, dst, tmp);
    ScaleXYZ(tmp, p[2], t * t);
    AddXYZ(dst, dst, tmp);
}

#include "common.h"

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetRandomVector);
void iosGetRandomVector(void *dst)
{
    asm volatile(
        "vrnext.x $vf5, R;"
        "vrnext.y $vf5, R;"
        "vrnext.z $vf5, R;"
        "vsubw.xyz $vf5, $vf5, $vf0w;"
        "sqc2 $vf5, 0(%0)"
        : : "r"(dst) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetDRandomVector);
void iosGetDRandomVector(void *dst)
{
    asm volatile(
        "vrnext.x $vf5, R;"
        "vrnext.y $vf5, R;"
        "vrnext.z $vf5, R;"
        "vsubw.xyz $vf5, $vf5, $vf0w;"
        "vadd.xyz $vf5, $vf5, $vf5;"
        "vsubw.xyz $vf5, $vf5, $vf0w;"
        "sqc2 $vf5, 0(%0)"
        : : "r"(dst) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetRandomVector0);
void iosGetRandomVector0(void *dst)
{
    asm volatile(
        "vrnext.xyz $vf5, R;"
        "vsubw.xyz $vf5, $vf5, $vf0w;"
        "vrxor R, $vf5x;"
        "sqc2 $vf5, 0(%0)"
        : : "r"(dst) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosAbsVector);
void iosAbsVector(void *dst, void *src)
{
    asm volatile("lqc2 $vf5, 0(%1); vabs.xyzw $vf6, $vf5; sqc2 $vf6, 0(%0)" : : "r"(dst), "r"(src) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetReflectVector);
void iosGetReflectVector(void *dst, void *src, void *normal)
{
    asm volatile(
        "lqc2 $vf4, 0(%1);"
        "lqc2 $vf5, 0(%2);"
        "vmul.xyz $vf7, $vf4, $vf5;"
        "vaddy.x $vf7, $vf7, $vf7y;"
        "vaddz.x $vf7, $vf7, $vf7z;"
        "vadd.xyzw $vf6, $vf0, $vf0;"
        "vmulx.xyz $vf5, $vf5, $vf7x;"
        "vmulw.xyz $vf5, $vf5, $vf6w;"
        "vsub.xyz $vf4, $vf4, $vf5;"
        "sqc2 $vf4, 0(%0)"
        : : "r"(dst), "r"(src), "r"(normal) : "memory");
}

void iosDumpFVector(void) {
}

void iosDumpIVector(void) {
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetArbitraryUpVectorElement);
extern f32 ZUnitVectorInv[4];
extern f32 ZUnitVector[4];
extern f32 YUnitVector[4];
extern f32 YUnitVectorInv[4];
void iosGetArbitraryUpVectorElement(void *dst, void *src)
{
    f32 tmp[4] __attribute__((aligned(16)));
    f32 *s = src;
    f32 *v;

    if (s[1] > 0.70699996f)
    {
        v = ZUnitVectorInv;
    }
    else if (s[1] < -0.70699996f)
    {
        v = ZUnitVector;
    }
    else
    {
        v = YUnitVector;
    }
    asm volatile(
        "lqc2 $vf5, 0(%1);"
        "lqc2 $vf6, 0(%2);"
        "vopmula.xyz ACC, $vf5, $vf6;"
        "vopmsub.xyz $vf7, $vf6, $vf5;"
        "vsub.w $vf7, $vf7, $vf7;"
        "sqc2 $vf7, 0(%3);"
        "lqc2 $vf5, 0(%3);"
        "lqc2 $vf6, 0(%1);"
        "vopmula.xyz ACC, $vf5, $vf6;"
        "vopmsub.xyz $vf7, $vf6, $vf5;"
        "vsub.w $vf7, $vf7, $vf7;"
        "sqc2 $vf7, 0(%0)"
        : : "r"(dst), "r"(src), "r"(v), "r"(tmp) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetScaleInverseVector);
void iosGetScaleInverseVector(void *dst, void *src)
{
    f32 *d = dst;
    f32 *s = src;

    d[0] = 1.0f / s[0];
    d[1] = 1.0f / s[1];
    d[2] = 1.0f / s[2];
    d[3] = 1.0f / s[3];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetStabXYVector);
void iosGetStabXYVector(void *dst, void *src)
{
    asm volatile(
        "lq $2, 0(%1);"
        "sq $2, 0(%0);"
        "sw $0, 8(%0);"
        "lqc2 $vf5, 0(%0);"
        "vmul.xyz $vf7, $vf5, $vf5;"
        "vmulax.w ACC, $vf0, $vf7x;"
        "vmadday.w ACC, $vf0, $vf7y;"
        "vmaddz.w $vf7, $vf0, $vf7z;"
        "vrsqrt Q, $vf0w, $vf7w;"
        "vwaitq;"
        "vmulq.xyz $vf5, $vf5, Q;"
        "sqc2 $vf5, 0(%0)"
        : : "r"(dst), "r"(src) : "$2", "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetStabYZVector);
void iosGetStabYZVector(void *dst, void *src)
{
    asm volatile(
        "lq $2, 0(%1);"
        "sq $2, 0(%0);"
        "sw $0, 0(%0);"
        "lqc2 $vf5, 0(%0);"
        "vmul.xyz $vf7, $vf5, $vf5;"
        "vmulax.w ACC, $vf0, $vf7x;"
        "vmadday.w ACC, $vf0, $vf7y;"
        "vmaddz.w $vf7, $vf0, $vf7z;"
        "vrsqrt Q, $vf0w, $vf7w;"
        "vwaitq;"
        "vmulq.xyz $vf5, $vf5, Q;"
        "sqc2 $vf5, 0(%0)"
        : : "r"(dst), "r"(src) : "$2", "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetLengthPointToLine);
void iosGetLengthPointToLine(void *dst, void *p1, void *p2, void *p3)
{
    f32 tmp[4] __attribute__((aligned(16)));
    asm volatile(
        "lqc2 $vf5, 0(%2);"
        "lqc2 $vf6, 0(%1);"
        "vsub.xyzw $vf7, $vf5, $vf6;"
        "sqc2 $vf7, 0(%4);"
        "lqc2 $vf7, 0(%4);"
        "vmul.xyz $vf7, $vf7, $vf7;"
        "vmulax.w ACC, $vf0, $vf7x;"
        "vmadday.w ACC, $vf0, $vf7y;"
        "vmaddz.w $vf7, $vf0, $vf7z;"
        ".word 0x4BA703BD;"
        "vwaitq;"
        "cfc2.ni $v0, $vi22;"
        "mtc1 $v0, $f1;"
        "lqc2 $vf5, 0(%1);"
        "lqc2 $vf6, 0(%4);"
        "vaddw.x $vf7, $vf0, $vf0w;"
        "vmul.xyz $vf6, $vf5, $vf6;"
        "vaddax.x ACC, $vf0, $vf6x;"
        "vmadday.x ACC, $vf7, $vf6y;"
        "vmaddz.x $vf6, $vf7, $vf6z;"
        "qmfc2.ni $v0, $vf6;"
        "mtc1 $v0, $f0;"
        "lqc2 $vf5, 0(%3);"
        "lqc2 $vf6, 0(%4);"
        "vaddw.x $vf7, $vf0, $vf0w;"
        "vmul.xyz $vf6, $vf5, $vf6;"
        "vaddax.x ACC, $vf0, $vf6x;"
        "vmadday.x ACC, $vf7, $vf6y;"
        "vmaddz.x $vf6, $vf7, $vf6z;"
        "qmfc2.ni $v0, $vf6;"
        "mtc1 $v0, $f2;"
        "neg.s $f0, $f0;"
        "mul.s $f1, $f1, $f1;"
        "add.s $f0, $f0, $f2;"
        "nop;"
        "nop;"
        "div.s $f0, $f0, $f1;"
        "mfc1 $v0, $f0;"
        "lqc2 $vf5, 0(%4);"
        "qmtc2.ni $v0, $vf6;"
        "vmulx.xyzw $vf5, $vf5, $vf6x;"
        "sqc2 $vf5, 0(%0)"
        : : "r"(dst), "r"(p1), "r"(p2), "r"(p3), "r"(tmp) : "$2", "$f0", "$f1", "$f2", "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetInverseVectorXYZ);
void iosGetInverseVectorXYZ(void *dst, void *src)
{
    f32 m = -1.0f;
    asm volatile(
        "lqc2 $vf5, 0(%1);"
        "qmtc2.ni %2, $vf6;"
        "vmulx.xyz $vf5, $vf5, $vf6x;"
        "sqc2 $vf5, 0(%0)"
        : : "r"(dst), "r"(src), "r"(m) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosGetExceptAxisVector);
void iosGetExceptAxisVector(void *dst, void *src, void *axis)
{
    f32 tmp[4] __attribute__((aligned(16)));
    asm volatile(
        "lqc2 $vf5, 0(%1);"
        "lqc2 $vf6, 0(%2);"
        "vaddw.x $vf7, $vf0, $vf0w;"
        "vmul.xyz $vf6, $vf5, $vf6;"
        "vaddax.x ACC, $vf0, $vf6x;"
        "vmadday.x ACC, $vf7, $vf6y;"
        "vmaddz.x $vf6, $vf7, $vf6z;"
        "qmfc2.ni $v0, $vf6;"
        "mtc1 $v0, $f0;"
        "mfc1 $v0, $f0;"
        "lqc2 $vf5, 0(%2);"
        "qmtc2.ni $v0, $vf6;"
        "vmulx.xyz $vf5, $vf5, $vf6x;"
        "sqc2 $vf5, 0(%3);"
        "lqc2 $vf5, 0(%1);"
        "lqc2 $vf6, 0(%3);"
        "vsub.xyz $vf5, $vf5, $vf6;"
        "sqc2 $vf5, 0(%0)"
        : : "r"(dst), "r"(src), "r"(axis), "r"(tmp) : "$2", "$f0", "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosCalcFColorToBrightness);
extern f32 D_40047590[4];
f32 iosCalcFColorToBrightness(void *color)
{
    f32 tmp[4] __attribute__((aligned(16)));
    asm volatile(
        "lqc2 $vf5, 0(%0);"
        "lqc2 $vf6, 0(%1);"
        "vmul.xyzw $vf5, $vf5, $vf6;"
        "sqc2 $vf5, 0(%2)"
        : : "r"(color), "r"(D_40047590), "r"(tmp) : "memory");
    return tmp[0] + tmp[1] + tmp[2];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosITOF15VectorXYZ);
void iosITOF15VectorXYZ(void *dst, void *src)
{
    asm volatile("lqc2 $vf5, 0(%1); vitof15.xyz $vf6, $vf5; sqc2 $vf6, 0(%0)" : : "r"(dst), "r"(src) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosScaleColorTo255);
extern f32 D_400475A0[4];
void iosScaleColorTo255(void *dst, void *src)
{
    asm volatile(
        "lqc2 $vf4, 0(%1);"
        "lqc2 $vf5, 0(%2);"
        "vmul.xyzw $vf5, $vf4, $vf5;"
        "sqc2 $vf6, 0(%0)"
        : : "r"(dst), "r"(src), "r"(D_400475A0) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/vector", iosScaleColorToONE);
extern f32 D_400475B0[4];
void iosScaleColorToONE(void *dst, void *src)
{
    asm volatile(
        "lqc2 $vf4, 0(%1);"
        "lqc2 $vf5, 0(%2);"
        "vmul.xyzw $vf5, $vf4, $vf5;"
        "sqc2 $vf6, 0(%0)"
        : : "r"(dst), "r"(src), "r"(D_400475B0) : "memory");
}

#include "common.h"

void func_4001D5E0(s32, void *, void *);
void iosGetAlignSinCosf(f32 *arg0, f32 arg1);
void iosGetSinCosf(f32 *out, f32 x);
extern u8 UnitMatrix[];

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", func_4001D5E0);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", CompareString16);
s32 CompareString16(void *a, void *b)
{
    u64 t[2];

    asm volatile(
        "lq $t0, 0(%1);"
        "lq $t1, 0(%2);"
        "pxor $t2, $t0, $t1;"
        "sq $t2, 0(%0)"
        : : "r"(t), "r"(a), "r"(b) : "$8", "$9", "$10", "memory");

    return (s32)(t[0] | t[1]);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInitCurrentMatrix);
void iosInitCurrentMatrix(void)
{
    asm volatile(
        "vmove.xyzw $vf4, $vf0;"
        "vmr32.xyzw $vf3, $vf4;"
        "vmr32.xyzw $vf2, $vf3;"
        "vmr32.xyzw $vf1, $vf2;"
        "viaddi $vi15, $vi0, 0"
        : : : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosUnitCurrentMatrix);
void iosUnitCurrentMatrix(void)
{
    asm volatile(
        "vmove.xyzw $vf4, $vf0;"
        "vmr32.xyzw $vf3, $vf4;"
        "vmr32.xyzw $vf2, $vf3;"
        "vmr32.xyzw $vf1, $vf2"
        : : : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosPushCurrentMatrix);
void iosPushCurrentMatrix(void)
{
    asm volatile(
        "vsqi.xyzw $vf1, ($vi15++);"
        "vsqi.xyzw $vf2, ($vi15++);"
        "vsqi.xyzw $vf3, ($vi15++);"
        "vsqi.xyzw $vf4, ($vi15++)"
        : : : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosPopCurrentMatrix);
void iosPopCurrentMatrix(void)
{
    asm volatile(
        "vlqd.xyzw $vf4, (--$vi15);"
        "vlqd.xyzw $vf3, (--$vi15);"
        "vlqd.xyzw $vf2, (--$vi15);"
        "vlqd.xyzw $vf1, (--$vi15)"
        : : : "memory");
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosPushVu0RegistersToWork);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosPopVu0RegistersFromWork);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransCurrentMatrix);
void iosTransCurrentMatrix(void *src)
{
    asm volatile(
        "lqc2 $vf8, 0(%0);"
        "vmulax.xyzw ACC, $vf1, $vf8x;"
        "vmadday.xyzw ACC, $vf2, $vf8y;"
        "vmaddaz.xyzw ACC, $vf3, $vf8z;"
        "vmaddw.xyzw $vf4, $vf4, $vf0w"
        : : "r"(src) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosSetTransCurrentMatrix);
void iosSetTransCurrentMatrix(void *src)
{
    asm volatile(
        "lqc2 $vf8, 0(%0);"
        "vmove.xyzw $vf4, $vf8"
        : : "r"(src) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosClearTransCurrentMatrix);
void iosClearTransCurrentMatrix(void)
{
    asm volatile(
        "vmove.xyzw $vf4, $vf0"
        : : : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosGetRotXVector);
void iosGetRotXVector(f32 angle, void *dst, void *src)
{
    f32 m[16] __attribute__((aligned(16)));
    f32 sc[2];

    iosGetSinCosf(sc, angle);
    asm volatile(
        "vmove.xyzw $vf17, $vf0;"
        "vmr32.xyzw $vf16, $vf17;"
        "vmr32.xyzw $vf15, $vf16;"
        "vmr32.xyzw $vf14, $vf15;"
        "lwc1 $f1, %0;"
        "lwc1 $f0, %3;"
        "mfc1 $8, $f1;"
        "mfc1 $9, $f0;"
        "qmtc2.ni $8, $vf5;"
        "qmtc2.ni $9, $vf6;"
        "vaddx.y $vf15, $vf0, $vf5x;"
        "vsubx.y $vf16, $vf0, $vf6x;"
        "vaddx.z $vf15, $vf0, $vf6x;"
        "vaddx.z $vf16, $vf0, $vf5x;"
        "sqc2 $vf14, %4;"
        "sqc2 $vf15, %5;"
        "sqc2 $vf16, %6;"
        "sqc2 $vf17, %7;"
        "lqc2 $vf8, 0(%2);"
        "lqc2 $vf14, %4;"
        "lqc2 $vf15, %5;"
        "lqc2 $vf16, %6;"
        "lqc2 $vf17, %7;"
        "vmulax.xyzw ACC, $vf14, $vf8x;"
        "vmadday.xyzw ACC, $vf15, $vf8y;"
        "vmaddaz.xyzw ACC, $vf16, $vf8z;"
        "vmaddw.xyzw $vf10, $vf17, $vf8w;"
        "sqc2 $vf10, 0(%1)"
        : : "m"(sc[0]), "r"(dst), "r"(src), "m"(sc[1]), "m"(m[0]), "m"(m[4]), "m"(m[8]), "m"(m[12]) : "$8", "$9", "$f0", "$f1", "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosGetRotYVector);
void iosGetRotYVector(f32 angle, void *dst, void *src)
{
    f32 m[16] __attribute__((aligned(16)));
    f32 sc[2];

    iosGetSinCosf(sc, angle);
    asm volatile(
        "vmove.xyzw $vf17, $vf0;"
        "vmr32.xyzw $vf16, $vf17;"
        "vmr32.xyzw $vf15, $vf16;"
        "vmr32.xyzw $vf14, $vf15;"
        "lwc1 $f1, %0;"
        "lwc1 $f0, %3;"
        "mfc1 $8, $f1;"
        "mfc1 $9, $f0;"
        "qmtc2.ni $8, $vf5;"
        "qmtc2.ni $9, $vf6;"
        "vaddx.x $vf14, $vf0, $vf5x;"
        "vaddx.x $vf16, $vf0, $vf6x;"
        "vsubx.z $vf14, $vf0, $vf6x;"
        "vaddx.z $vf16, $vf0, $vf5x;"
        "sqc2 $vf14, %4;"
        "sqc2 $vf15, %5;"
        "sqc2 $vf16, %6;"
        "sqc2 $vf17, %7;"
        "lqc2 $vf8, 0(%2);"
        "lqc2 $vf14, %4;"
        "lqc2 $vf15, %5;"
        "lqc2 $vf16, %6;"
        "lqc2 $vf17, %7;"
        "vmulax.xyzw ACC, $vf14, $vf8x;"
        "vmadday.xyzw ACC, $vf15, $vf8y;"
        "vmaddaz.xyzw ACC, $vf16, $vf8z;"
        "vmaddw.xyzw $vf10, $vf17, $vf8w;"
        "sqc2 $vf10, 0(%1)"
        : : "m"(sc[0]), "r"(dst), "r"(src), "m"(sc[1]), "m"(m[0]), "m"(m[4]), "m"(m[8]), "m"(m[12]) : "$8", "$9", "$f0", "$f1", "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotCurrentMatrixX);
void iosRotCurrentMatrixX(f32 angle)
{
    f32 sc[2];

    iosGetSinCosf(sc, angle);
    asm volatile(
        "vmove.xyzw $vf17, $vf0;"
        "vmr32.xyzw $vf16, $vf17;"
        "vmr32.xyzw $vf15, $vf16;"
        "vmr32.xyzw $vf14, $vf15;"
        "lwc1 $f1, 0(%0);"
        "lwc1 $f0, 4(%0);"
        "mfc1 $8, $f1;"
        "mfc1 $9, $f0;"
        "qmtc2.ni $8, $vf5;"
        "qmtc2.ni $9, $vf6;"
        "vaddx.y $vf15, $vf0, $vf5x;"
        "vsubx.y $vf16, $vf0, $vf6x;"
        "vaddx.z $vf15, $vf0, $vf6x;"
        "vaddx.z $vf16, $vf0, $vf5x;"
        "vmulax.xyzw ACC, $vf1, $vf14x;"
        "vmadday.xyzw ACC, $vf2, $vf14y;"
        "vmaddaz.xyzw ACC, $vf3, $vf14z;"
        "vmaddw.xyzw $vf14, $vf4, $vf14w;"
        "vmulax.xyzw ACC, $vf1, $vf15x;"
        "vmadday.xyzw ACC, $vf2, $vf15y;"
        "vmaddaz.xyzw ACC, $vf3, $vf15z;"
        "vmaddw.xyzw $vf15, $vf4, $vf15w;"
        "vmulax.xyzw ACC, $vf1, $vf16x;"
        "vmadday.xyzw ACC, $vf2, $vf16y;"
        "vmaddaz.xyzw ACC, $vf3, $vf16z;"
        "vmaddw.xyzw $vf16, $vf4, $vf16w;"
        "vmulax.xyzw ACC, $vf1, $vf17x;"
        "vmadday.xyzw ACC, $vf2, $vf17y;"
        "vmaddaz.xyzw ACC, $vf3, $vf17z;"
        "vmaddw.xyzw $vf17, $vf4, $vf17w;"
        "vmove.xyzw $vf1, $vf14;"
        "vmove.xyzw $vf2, $vf15;"
        "vmove.xyzw $vf3, $vf16;"
        "vmove.xyzw $vf4, $vf17"
        : : "r"(sc) : "$8", "$9", "$f0", "$f1", "memory");
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotCurrentMatrixY);
void iosRotCurrentMatrixY(f32 angle)
{
    f32 sc[2];

    iosGetSinCosf(sc, angle);
    asm volatile(
        "vmove.xyzw $vf17, $vf0;"
        "vmr32.xyzw $vf16, $vf17;"
        "vmr32.xyzw $vf15, $vf16;"
        "vmr32.xyzw $vf14, $vf15;"
        "lwc1 $f1, 0(%0);"
        "lwc1 $f0, 4(%0);"
        "mfc1 $8, $f1;"
        "mfc1 $9, $f0;"
        "qmtc2.ni $8, $vf5;"
        "qmtc2.ni $9, $vf6;"
        "vaddx.x $vf14, $vf0, $vf5x;"
        "vaddx.x $vf16, $vf0, $vf6x;"
        "vsubx.z $vf14, $vf0, $vf6x;"
        "vaddx.z $vf16, $vf0, $vf5x;"
        "vmulax.xyzw ACC, $vf1, $vf14x;"
        "vmadday.xyzw ACC, $vf2, $vf14y;"
        "vmaddaz.xyzw ACC, $vf3, $vf14z;"
        "vmaddw.xyzw $vf14, $vf4, $vf14w;"
        "vmulax.xyzw ACC, $vf1, $vf15x;"
        "vmadday.xyzw ACC, $vf2, $vf15y;"
        "vmaddaz.xyzw ACC, $vf3, $vf15z;"
        "vmaddw.xyzw $vf15, $vf4, $vf15w;"
        "vmulax.xyzw ACC, $vf1, $vf16x;"
        "vmadday.xyzw ACC, $vf2, $vf16y;"
        "vmaddaz.xyzw ACC, $vf3, $vf16z;"
        "vmaddw.xyzw $vf16, $vf4, $vf16w;"
        "vmulax.xyzw ACC, $vf1, $vf17x;"
        "vmadday.xyzw ACC, $vf2, $vf17y;"
        "vmaddaz.xyzw ACC, $vf3, $vf17z;"
        "vmaddw.xyzw $vf17, $vf4, $vf17w;"
        "vmove.xyzw $vf1, $vf14;"
        "vmove.xyzw $vf2, $vf15;"
        "vmove.xyzw $vf3, $vf16;"
        "vmove.xyzw $vf4, $vf17"
        : : "r"(sc) : "$8", "$9", "$f0", "$f1", "memory");
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotCurrentMatrixZ);
void iosRotCurrentMatrixZ(f32 angle)
{
    f32 sc[2];

    iosGetSinCosf(sc, angle);
    asm volatile(
        "vmove.xyzw $vf17, $vf0;"
        "vmr32.xyzw $vf16, $vf17;"
        "vmr32.xyzw $vf15, $vf16;"
        "vmr32.xyzw $vf14, $vf15;"
        "lwc1 $f1, 0(%0);"
        "lwc1 $f0, 4(%0);"
        "mfc1 $8, $f1;"
        "mfc1 $9, $f0;"
        "qmtc2.ni $8, $vf5;"
        "qmtc2.ni $9, $vf6;"
        "vaddx.x $vf14, $vf0, $vf5x;"
        "vsubx.x $vf15, $vf0, $vf6x;"
        "vaddx.y $vf14, $vf0, $vf6x;"
        "vaddx.y $vf15, $vf0, $vf5x;"
        "vmulax.xyzw ACC, $vf1, $vf14x;"
        "vmadday.xyzw ACC, $vf2, $vf14y;"
        "vmaddaz.xyzw ACC, $vf3, $vf14z;"
        "vmaddw.xyzw $vf14, $vf4, $vf14w;"
        "vmulax.xyzw ACC, $vf1, $vf15x;"
        "vmadday.xyzw ACC, $vf2, $vf15y;"
        "vmaddaz.xyzw ACC, $vf3, $vf15z;"
        "vmaddw.xyzw $vf15, $vf4, $vf15w;"
        "vmulax.xyzw ACC, $vf1, $vf16x;"
        "vmadday.xyzw ACC, $vf2, $vf16y;"
        "vmaddaz.xyzw ACC, $vf3, $vf16z;"
        "vmaddw.xyzw $vf16, $vf4, $vf16w;"
        "vmulax.xyzw ACC, $vf1, $vf17x;"
        "vmadday.xyzw ACC, $vf2, $vf17y;"
        "vmaddaz.xyzw ACC, $vf3, $vf17z;"
        "vmaddw.xyzw $vf17, $vf4, $vf17w;"
        "vmove.xyzw $vf1, $vf14;"
        "vmove.xyzw $vf2, $vf15;"
        "vmove.xyzw $vf3, $vf16;"
        "vmove.xyzw $vf4, $vf17"
        : : "r"(sc) : "$8", "$9", "$f0", "$f1", "memory");
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosScaleCurrentMatrix);
void iosScaleCurrentMatrix(f32 sx, f32 sy, f32 sz)
{
    asm volatile(
        "vmove.xyzw $vf17, $vf0;"
        "vmr32.xyzw $vf16, $vf17;"
        "vmr32.xyzw $vf15, $vf16;"
        "vmr32.xyzw $vf14, $vf15;"
        "mfc1 $6, $f12;"
        "mfc1 $7, $f13;"
        "mfc1 $8, $f14;"
        "qmtc2.ni $6, $vf5;"
        "qmtc2.ni $7, $vf6;"
        "qmtc2.ni $8, $vf7;"
        "vaddx.x $vf14, $vf0, $vf5x;"
        "vaddx.y $vf15, $vf0, $vf6x;"
        "vaddx.z $vf16, $vf0, $vf7x;"
        "vmulax.xyzw ACC, $vf1, $vf14x;"
        "vmadday.xyzw ACC, $vf2, $vf14y;"
        "vmaddaz.xyzw ACC, $vf3, $vf14z;"
        "vmaddw.xyzw $vf14, $vf4, $vf14w;"
        "vmulax.xyzw ACC, $vf1, $vf15x;"
        "vmadday.xyzw ACC, $vf2, $vf15y;"
        "vmaddaz.xyzw ACC, $vf3, $vf15z;"
        "vmaddw.xyzw $vf15, $vf4, $vf15w;"
        "vmulax.xyzw ACC, $vf1, $vf16x;"
        "vmadday.xyzw ACC, $vf2, $vf16y;"
        "vmaddaz.xyzw ACC, $vf3, $vf16z;"
        "vmaddw.xyzw $vf16, $vf4, $vf16w;"
        "vmulax.xyzw ACC, $vf1, $vf17x;"
        "vmadday.xyzw ACC, $vf2, $vf17y;"
        "vmaddaz.xyzw ACC, $vf3, $vf17z;"
        "vmaddw.xyzw $vf17, $vf4, $vf17w;"
        "vmove.xyzw $vf1, $vf14;"
        "vmove.xyzw $vf2, $vf15;"
        "vmove.xyzw $vf3, $vf16;"
        "vmove.xyzw $vf4, $vf17"
        : : : "$6", "$7", "$8", "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosGetCurrentMatrix);
void iosGetCurrentMatrix(void *dst)
{
    asm volatile(
        "sqc2 $vf1, 0(%0);"
        "sqc2 $vf2, 16(%0);"
        "sqc2 $vf3, 32(%0);"
        "sqc2 $vf4, 48(%0)"
        : : "r"(dst) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosGetCurrentMatrixTrans);
void iosGetCurrentMatrixTrans(void *dst)
{
    asm volatile(
        "sqc2 $vf4, 0(%0)"
        : : "r"(dst) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosSetCurrentMatrix);
void iosSetCurrentMatrix(void *src)
{
    asm volatile(
        "lqc2 $vf1, 0(%0);"
        "lqc2 $vf2, 16(%0);"
        "lqc2 $vf3, 32(%0);"
        "lqc2 $vf4, 48(%0)"
        : : "r"(src) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosMulCurrentMatrixR);
void iosMulCurrentMatrixR(void *src)
{
    asm volatile(
        "lqc2 $vf14, 0(%0);"
        "lqc2 $vf15, 16(%0);"
        "lqc2 $vf16, 32(%0);"
        "lqc2 $vf17, 48(%0);"
        "vmulax.xyzw ACC, $vf1, $vf14x;"
        "vmadday.xyzw ACC, $vf2, $vf14y;"
        "vmaddaz.xyzw ACC, $vf3, $vf14z;"
        "vmaddw.xyzw $vf14, $vf4, $vf14w;"
        "vmulax.xyzw ACC, $vf1, $vf15x;"
        "vmadday.xyzw ACC, $vf2, $vf15y;"
        "vmaddaz.xyzw ACC, $vf3, $vf15z;"
        "vmaddw.xyzw $vf15, $vf4, $vf15w;"
        "vmulax.xyzw ACC, $vf1, $vf16x;"
        "vmadday.xyzw ACC, $vf2, $vf16y;"
        "vmaddaz.xyzw ACC, $vf3, $vf16z;"
        "vmaddw.xyzw $vf16, $vf4, $vf16w;"
        "vmulax.xyzw ACC, $vf1, $vf17x;"
        "vmadday.xyzw ACC, $vf2, $vf17y;"
        "vmaddaz.xyzw ACC, $vf3, $vf17z;"
        "vmaddw.xyzw $vf17, $vf4, $vf17w;"
        "vmove.xyzw $vf1, $vf14;"
        "vmove.xyzw $vf2, $vf15;"
        "vmove.xyzw $vf3, $vf16;"
        "vmove.xyzw $vf4, $vf17"
        : : "r"(src) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosMulCurrentMatrixL);
void iosMulCurrentMatrixL(void *src)
{
    asm volatile(
        "lqc2 $vf14, 0(%0);"
        "lqc2 $vf15, 16(%0);"
        "lqc2 $vf16, 32(%0);"
        "lqc2 $vf17, 48(%0);"
        "vmulax.xyzw ACC, $vf14, $vf1x;"
        "vmadday.xyzw ACC, $vf15, $vf1y;"
        "vmaddaz.xyzw ACC, $vf16, $vf1z;"
        "vmaddw.xyzw $vf1, $vf17, $vf1w;"
        "vmulax.xyzw ACC, $vf14, $vf2x;"
        "vmadday.xyzw ACC, $vf15, $vf2y;"
        "vmaddaz.xyzw ACC, $vf16, $vf2z;"
        "vmaddw.xyzw $vf2, $vf17, $vf2w;"
        "vmulax.xyzw ACC, $vf14, $vf3x;"
        "vmadday.xyzw ACC, $vf15, $vf3y;"
        "vmaddaz.xyzw ACC, $vf16, $vf3z;"
        "vmaddw.xyzw $vf3, $vf17, $vf3w;"
        "vmulax.xyzw ACC, $vf14, $vf4x;"
        "vmadday.xyzw ACC, $vf15, $vf4y;"
        "vmaddaz.xyzw ACC, $vf16, $vf4z;"
        "vmaddw.xyzw $vf4, $vf17, $vf4w"
        : : "r"(src) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosApplyCurrentMatrix);
void iosApplyCurrentMatrix(void *dst, void *src)
{
    asm volatile(
        "lqc2 $vf8, 0(%1);"
        "vmulax.xyzw ACC, $vf1, $vf8x;"
        "vmadday.xyzw ACC, $vf2, $vf8y;"
        "vmaddaz.xyzw ACC, $vf3, $vf8z;"
        "vmaddw.xyzw $vf10, $vf4, $vf8w;"
        "sqc2 $vf10, 0(%0)"
        : : "r"(dst), "r"(src) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosApplyRotCurrentMatrix);
void iosApplyRotCurrentMatrix(void *dst, void *src)
{
    asm volatile(
        "lqc2 $vf8, 0(%1);"
        "vmulax.xyzw ACC, $vf1, $vf8x;"
        "vmadday.xyzw ACC, $vf2, $vf8y;"
        "vmaddaz.xyzw ACC, $vf3, $vf8z;"
        "vmaddw.xyzw $vf10, $vf0, $vf8w;"
        "sqc2 $vf10, 0(%0)"
        : : "r"(dst), "r"(src) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotTransPersCurrentMatrix);
void iosRotTransPersCurrentMatrix(void *dst, void *src)
{
    asm volatile(
        "lqc2 $vf8, 0(%1);"
        "vmulax.xyzw ACC, $vf1, $vf8x;"
        "vmadday.xyzw ACC, $vf2, $vf8y;"
        "vmaddaz.xyzw ACC, $vf3, $vf8z;"
        "vmaddw.xyzw $vf10, $vf4, $vf8w;"
        "vdiv Q, $vf0w, $vf10w;"
        "vwaitq;"
        "vmulq.xyz $vf10, $vf10, Q;"
        "sqc2 $vf10, 0(%0)"
        : : "r"(dst), "r"(src) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransposeCurrentMatrix);
void iosTransposeCurrentMatrix(void)
{
    asm volatile(
        "vsub.xyzw $vf5, $vf0, $vf0;"
        "vaddx.y $vf14, $vf5, $vf2x;"
        "vaddx.z $vf14, $vf5, $vf3x;"
        "vaddx.w $vf14, $vf5, $vf4x;"
        "vaddy.x $vf15, $vf5, $vf1y;"
        "vaddy.z $vf15, $vf5, $vf3y;"
        "vaddy.w $vf15, $vf5, $vf4y;"
        "vaddz.x $vf16, $vf5, $vf1z;"
        "vaddz.y $vf16, $vf5, $vf2z;"
        "vaddz.w $vf16, $vf5, $vf4z;"
        "vaddw.x $vf17, $vf5, $vf1w;"
        "vaddw.y $vf17, $vf5, $vf2w;"
        "vaddw.z $vf17, $vf5, $vf3w;"
        "vmove.yzw $vf1, $vf14;"
        "vmove.xzw $vf2, $vf15;"
        "vmove.xyw $vf3, $vf16;"
        "vmove.xyz $vf4, $vf17"
        : : : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransposeRotationCurrentMatrix);
void iosTransposeRotationCurrentMatrix(void)
{
    asm volatile(
        "vsub.xyzw $vf5, $vf0, $vf0;"
        "vaddx.y $vf14, $vf5, $vf2x;"
        "vaddx.z $vf14, $vf5, $vf3x;"
        "vaddy.x $vf15, $vf5, $vf1y;"
        "vaddy.z $vf15, $vf5, $vf3y;"
        "vaddz.x $vf16, $vf5, $vf1z;"
        "vaddz.y $vf16, $vf5, $vf2z;"
        "vmove.yz $vf1, $vf14;"
        "vmove.xz $vf2, $vf15;"
        "vmove.xy $vf3, $vf16"
        : : : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInverseCurrentMatrix);
void iosInverseCurrentMatrix(void)
{
    asm volatile(
        "vsub.xyzw $vf5, $vf0, $vf0;"
        "vsubw.x $vf6, $vf0, $vf0w;"
        "vaddx.y $vf14, $vf5, $vf2x;"
        "vaddx.z $vf14, $vf5, $vf3x;"
        "vaddy.x $vf15, $vf5, $vf1y;"
        "vaddy.z $vf15, $vf5, $vf3y;"
        "vaddz.x $vf16, $vf5, $vf1z;"
        "vaddz.y $vf16, $vf5, $vf2z;"
        "vmulx.xyz $vf17, $vf4, $vf6x;"
        "vmove.yz $vf1, $vf14;"
        "vmove.xz $vf2, $vf15;"
        "vmove.xy $vf3, $vf16;"
        "vmove.w $vf17, $vf0;"
        "vmulax.xyzw ACC, $vf1, $vf17x;"
        "vmadday.xyzw ACC, $vf2, $vf17y;"
        "vmaddaz.xyzw ACC, $vf3, $vf17z;"
        "vmaddw.xyzw $vf4, $vf0, $vf17w"
        : : : "memory");
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosPushVu0Registers);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosPopVu0Registers);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInitPushPosVuSema);
static s32 D_40081E70;

void iosInitPushPosVuSema(void)
{
    D_40081E70 = iosCreateSema(1, 1, 0);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosCopyMatrix);
void iosCopyMatrix(void *dst, void *src)
{
    asm volatile(
        "lq $9, 0x30(%1);"
        "sq $9, 0x30(%0);"
        "lq $8, 0x20(%1);"
        "sq $8, 0x20(%0);"
        "lq $7, 0x10(%1);"
        "sq $7, 0x10(%0);"
        "lq $6, 0x0(%1);"
        "sq $6, 0x0(%0);"
        : : "r"(dst), "r"(src) : "$6", "$7", "$8", "$9", "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosApplyRotMatrix);
void iosApplyRotMatrix(void *dst, void *mat, void *vec)
{
    asm volatile(
        "lqc2 $vf8, 0(%2);"
        "lqc2 $vf14, 0(%1);"
        "lqc2 $vf15, 16(%1);"
        "lqc2 $vf16, 32(%1);"
        "vmulax.xyzw ACC, $vf14, $vf8x;"
        "vmadday.xyzw ACC, $vf15, $vf8y;"
        "vmaddaz.xyzw ACC, $vf16, $vf8z;"
        "vmaddw.xyzw $vf10, $vf0, $vf8w;"
        "sqc2 $vf10, 0(%0)"
        : : "r"(dst), "r"(mat), "r"(vec) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosUnitMatrix);
void iosUnitMatrix(void *dst)
{
    asm volatile(
        "vmove.xyzw $vf17, $vf0;"
        "vmr32.xyzw $vf16, $vf17;"
        "vmr32.xyzw $vf15, $vf16;"
        "vmr32.xyzw $vf14, $vf15;"
        "sqc2 $vf14, 0(%0);"
        "sqc2 $vf15, 16(%0);"
        "sqc2 $vf16, 32(%0);"
        "sqc2 $vf17, 48(%0)"
        : : "r"(dst) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosUnitRotation);
void iosUnitRotation(void *dst)
{
    asm volatile(
        "vmove.xyzw $vf17, $vf0;"
        "vmr32.xyzw $vf16, $vf17;"
        "vmr32.xyzw $vf15, $vf16;"
        "vmr32.xyzw $vf14, $vf15;"
        "sqc2 $vf14, 0(%0);"
        "sqc2 $vf15, 16(%0);"
        "sqc2 $vf16, 32(%0)"
        : : "r"(dst) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransposeMatrix);
void iosTransposeMatrix(void *dst, void *src)
{
    asm volatile(
        "lq $t0, 0x0(%1);"
        "lq $t1, 0x10(%1);"
        "lq $t2, 0x20(%1);"
        "lq $t3, 0x30(%1);"
        "pextlw $t4, $t1, $t0;"
        "pextuw $t5, $t1, $t0;"
        "pextlw $t6, $t3, $t2;"
        "pextuw $t7, $t3, $t2;"
        "pcpyld $t0, $t6, $t4;"
        "pcpyud $t1, $t4, $t6;"
        "pcpyld $t2, $t7, $t5;"
        "pcpyud $t3, $t5, $t7;"
        "sq $t0, 0x0(%0);"
        "sq $t1, 0x10(%0);"
        "sq $t2, 0x20(%0);"
        "sq $t3, 0x30(%0)"
        : : "r"(dst), "r"(src)
        : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInverseMatrix);
void iosInverseMatrix(void *dst, void *src)
{
    asm volatile(
        "lq $8, 0x0(%1);"
        "lq $9, 0x10(%1);"
        "lq $10, 0x20(%1);"
        "lqc2 $vf1, 0x30(%1);"
        "vmove.xyzw $vf2, $vf1;"
        "vsub.xyz $vf1, $vf1, $vf1;"
        "vmove.xyzw $vf9, $vf1;"
        "qmfc2.ni $11, $vf1;"
        "pextlw $12, $9, $8;"
        "pextuw $13, $9, $8;"
        "pextlw $14, $11, $10;"
        "pextuw $15, $11, $10;"
        "pcpyld $8, $14, $12;"
        "pcpyud $9, $12, $14;"
        "pcpyld $10, $15, $13;"
        "qmtc2.ni $8, $vf3;"
        "qmtc2.ni $9, $vf4;"
        "qmtc2.ni $10, $vf8;"
        "vmulax.xyz ACC, $vf3, $vf2x;"
        "vmadday.xyz ACC, $vf4, $vf2y;"
        "vmaddz.xyz $vf1, $vf8, $vf2z;"
        "vsub.xyz $vf1, $vf9, $vf1;"
        "sq $8, 0x0(%0);"
        "sq $9, 0x10(%0);"
        "sq $10, 0x20(%0);"
        "sqc2 $vf1, 0x30(%0)"
        : : "r"(dst), "r"(src) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInverseMatrixPerfect);
void iosInverseMatrixPerfect(void *dst, void *src)
{
    func_4001D5E0(4, dst, src);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosScaleMatrixV);
void iosScaleMatrixV(void *dst, void *src, void *vec)
{
    asm volatile(
        "lqc2 $vf14, 0(%1);"
        "lqc2 $vf15, 16(%1);"
        "lqc2 $vf16, 32(%1);"
        "lqc2 $vf17, 48(%1);"
        "lqc2 $vf8, 0(%2);"
        "vmulx.xyzw $vf14, $vf14, $vf8x;"
        "vmuly.xyzw $vf15, $vf15, $vf8y;"
        "vmulz.xyzw $vf16, $vf16, $vf8z;"
        "sqc2 $vf14, 0(%0);"
        "sqc2 $vf15, 16(%0);"
        "sqc2 $vf16, 32(%0);"
        "sqc2 $vf17, 48(%0)"
        : : "r"(dst), "r"(src), "r"(vec) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosFloatModulo);
f32 iosFloatModulo(f32 a, f32 b)
{
    if (b == 0.0f)
    {
        return 0.0f;
    }
    return a - b * (f32)(s32)(a / b);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosSetCameraMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosMakeNormalLightMatrix);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosScaleNormalLightMatrix);
void iosScaleNormalLightMatrix(void *dst, void *src, void *vec)
{
    asm volatile(
        "lqc2 $vf24, 0(%1);"
        "lqc2 $vf25, 16(%1);"
        "lqc2 $vf26, 32(%1);"
        "lqc2 $vf27, 48(%1);"
        "lqc2 $vf28, 0(%2);"
        "vmulx.xyz $vf24, $vf24, $vf28x;"
        "vmuly.xyz $vf25, $vf25, $vf28y;"
        "vmulz.xyz $vf26, $vf26, $vf28z;"
        "sqc2 $vf24, 0(%0);"
        "sqc2 $vf25, 16(%0);"
        "sqc2 $vf26, 32(%0);"
        "sqc2 $vf27, 48(%0)"
        : : "r"(dst), "r"(src), "r"(vec) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosMakeLightColorMatrix);
void iosMakeLightColorMatrix(void *dst, void *a, void *b, void *c, void *d)
{
    asm volatile(
        "lq $6, 0(%1);"
        "lq $7, 0(%2);"
        "lq $8, 0(%3);"
        "lq $9, 0(%4);"
        "sq $6, 0(%0);"
        "sq $7, 16(%0);"
        "sq $8, 32(%0);"
        "sq $9, 48(%0)"
        : : "r"(dst), "r"(a), "r"(b), "r"(c), "r"(d) : "$6", "$7", "$8", "$9", "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransMatrix);
void iosTransMatrix(void *dst, void *src, void *trans)
{
    asm volatile(
        "lq $9, 0x30(%1);"
        "sq $9, 0x30(%0);"
        "lq $8, 0x20(%1);"
        "sq $8, 0x20(%0);"
        "lq $7, 0x10(%1);"
        "sq $7, 0x10(%0);"
        "lq $6, 0x0(%1);"
        "sq $6, 0x0(%0);"
        "addiu %0, %0, 0x30;"
        "lqc2 $vf8, 0(%2);"
        "lqc2 $vf14, 0(%1);"
        "lqc2 $vf15, 16(%1);"
        "lqc2 $vf16, 32(%1);"
        "lqc2 $vf17, 48(%1);"
        "vmulax.xyzw ACC, $vf14, $vf8x;"
        "vmadday.xyzw ACC, $vf15, $vf8y;"
        "vmaddaz.xyzw ACC, $vf16, $vf8z;"
        "vmaddw.xyzw $vf10, $vf17, $vf8w;"
        "sqc2 $vf10, 0(%0)"
        : "+r"(dst) : "r"(src), "r"(trans) : "$6", "$7", "$8", "$9", "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransMatrixF);
void iosTransMatrixF(void *dst, void *src, f32 x, f32 y, f32 z)
{
    f32 t[4];
    f32 *p = t;

    t[0] = x;
    t[1] = y;
    t[2] = z;
    t[3] = 1.0f;

    asm volatile(
        "lq $9, 0x30(%1);"
        "sq $9, 0x30(%0);"
        "lq $8, 0x20(%1);"
        "sq $8, 0x20(%0);"
        "lq $7, 0x10(%1);"
        "sq $7, 0x10(%0);"
        "lq $6, 0x0(%1);"
        "sq $6, 0x0(%0);"
        "addiu %0, %0, 0x30;"
        "lqc2 $vf8, 0(%2);"
        "lqc2 $vf14, 0(%1);"
        "lqc2 $vf15, 16(%1);"
        "lqc2 $vf16, 32(%1);"
        "lqc2 $vf17, 48(%1);"
        "vmulax.xyzw ACC, $vf14, $vf8x;"
        "vmadday.xyzw ACC, $vf15, $vf8y;"
        "vmaddaz.xyzw ACC, $vf16, $vf8z;"
        "vmaddw.xyzw $vf10, $vf17, $vf8w;"
        "sqc2 $vf10, 0(%0)"
        : "+r"(dst), "+r"(src), "+r"(p) : : "$6", "$7", "$8", "$9", "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosScaleMatrix);
void iosScaleMatrix(void *dst, f32 sx, f32 sy, f32 sz)
{
    f32 *m = dst;

    asm volatile(
        "vmove.xyzw $vf17, $vf0;"
        "vmr32.xyzw $vf16, $vf17;"
        "vmr32.xyzw $vf15, $vf16;"
        "vmr32.xyzw $vf14, $vf15;"
        "sqc2 $vf14, 0(%0);"
        "sqc2 $vf15, 16(%0);"
        "sqc2 $vf16, 32(%0);"
        "sqc2 $vf17, 48(%0)"
        : : "r"(dst) : "memory");
    m[0] = sx;
    m[5] = sy;
    m[10] = sz;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosMulRotMatrixXInt16);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotMatrixX);
void iosRotMatrixX(void *dst, f32 angle)
{
    f32 sp[2];
    f32 *m = dst;

    iosGetAlignSinCosf(sp, angle);
    asm volatile(
        "lq $9, 0x30(%1);"
        "sq $9, 0x30(%0);"
        "lq $8, 0x20(%1);"
        "sq $8, 0x20(%0);"
        "lq $7, 0x10(%1);"
        "sq $7, 0x10(%0);"
        "lq $6, 0x0(%1);"
        "sq $6, 0x0(%0)"
        : : "r"(dst), "r"(UnitMatrix) : "$6", "$7", "$8", "$9", "memory");
    m[5] = sp[1];
    m[6] = sp[0];
    m[9] = -sp[0];
    m[10] = sp[1];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotMatrixY);
void iosRotMatrixY(void *dst, f32 angle)
{
    f32 sp[2];
    f32 *m = dst;

    iosGetAlignSinCosf(sp, angle);
    asm volatile(
        "lq $9, 0x30(%1);"
        "sq $9, 0x30(%0);"
        "lq $8, 0x20(%1);"
        "sq $8, 0x20(%0);"
        "lq $7, 0x10(%1);"
        "sq $7, 0x10(%0);"
        "lq $6, 0x0(%1);"
        "sq $6, 0x0(%0)"
        : : "r"(dst), "r"(UnitMatrix) : "$6", "$7", "$8", "$9", "memory");
    m[0] = sp[1];
    m[2] = -sp[0];
    m[8] = sp[0];
    m[10] = sp[1];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotMatrixZ);
void iosRotMatrixZ(void *dst, f32 angle)
{
    f32 sp[2];
    f32 *m = dst;

    iosGetAlignSinCosf(sp, angle);
    asm volatile(
        "lq $9, 0x30(%1);"
        "sq $9, 0x30(%0);"
        "lq $8, 0x20(%1);"
        "sq $8, 0x20(%0);"
        "lq $7, 0x10(%1);"
        "sq $7, 0x10(%0);"
        "lq $6, 0x0(%1);"
        "sq $6, 0x0(%0)"
        : : "r"(dst), "r"(UnitMatrix) : "$6", "$7", "$8", "$9", "memory");
    m[0] = sp[1];
    m[1] = sp[0];
    m[4] = -sp[0];
    m[5] = sp[1];
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosDumpMatrix);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosGetScaleMatrixV);
extern u8 UnitMatrix[];

void iosGetScaleMatrixV(void *dst, f32 *src)
{
    f32 *m = dst;

    asm volatile(
        "lq $9, 0x30(%1);"
        "sq $9, 0x30(%0);"
        "lq $8, 0x20(%1);"
        "sq $8, 0x20(%0);"
        "lq $7, 0x10(%1);"
        "sq $7, 0x10(%0);"
        "lq $6, 0x0(%1);"
        "sq $6, 0x0(%0)"
        : : "r"(dst), "r"(UnitMatrix) : "$6", "$7", "$8", "$9", "memory");
    m[0] = src[0];
    m[5] = src[1];
    m[10] = src[2];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosGetYDirXYZFromMatrix);
void iosGetYDirXYZFromMatrix(void *dst, void *src)
{
    asm volatile(
        "lqc2 $vf4, 16(%1);"
        "vsub.w $vf4, $vf4, $vf4;"
        "sqc2 $vf4, 0(%0)"
        : : "r"(dst), "r"(src) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosGetXDirXYZFromMatrix);
void iosGetXDirXYZFromMatrix(void *dst, void *src)
{
    asm volatile(
        "lqc2 $vf4, 0(%1);"
        "vsub.w $vf4, $vf4, $vf4;"
        "sqc2 $vf4, 0(%0)"
        : : "r"(dst), "r"(src) : "memory");
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosFmodf);
f32 fmodf(f32, f32);

f32 iosFmodf(f32 a, f32 b)
{
    return fmodf(a, b);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotTransCurrentMatrix);
f32 iosRotTransCurrentMatrix(void *dst, void *src)
{
    f32 ret;

    asm volatile(
        "lqc2 $vf8, 0(%2);"
        "vmulax.xyzw ACC, $vf1, $vf8x;"
        "vmadday.xyzw ACC, $vf2, $vf8y;"
        "vmaddaz.xyzw ACC, $vf3, $vf8z;"
        "vmaddw.xyzw $vf10, $vf4, $vf8w;"
        "vdiv Q, $vf0w, $vf10w;"
        "vwaitq;"
        "vmulq.xyz $vf10, $vf10, Q;"
        "vftoi4.xyz $vf10, $vf10;"
        "vsub.xy $vf14, $vf10, $vf11;"
        "vsub.xy $vf15, $vf12, $vf11;"
        "vsub.zw $vf14, $vf14, $vf14;"
        "vsub.zw $vf15, $vf15, $vf15;"
        "vopmula.xyz ACC, $vf14, $vf15;"
        "vopmsub.xyz $vf16, $vf15, $vf14;"
        "vmr32.y $vf16, $vf16;"
        "vmr32.x $vf16, $vf16;"
        "sqc2 $vf10, 0(%1);"
        "qmfc2.ni $7, $vf16;"
        "mtc1 $7, %0;"
        "vmove.xy $vf12, $vf11;"
        "vmove.xy $vf11, $vf10"
        : "=f"(ret) : "r"(dst), "r"(src) : "$7", "memory");
    return ret;
}

#include "common.h"

void func_4001D5E0(s32, void *, void *);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosGetRotXVector);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosGetRotYVector);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotCurrentMatrixX);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotCurrentMatrixY);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotCurrentMatrixZ);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosScaleCurrentMatrix);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosMulCurrentMatrixR);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosCopyMatrix);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInverseMatrix);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransMatrixF);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotMatrixX);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotMatrixY);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotMatrixZ);

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

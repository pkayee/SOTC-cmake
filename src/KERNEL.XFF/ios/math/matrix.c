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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosMulCurrentMatrixL);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransposeCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransposeRotationCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInverseCurrentMatrix);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransposeMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInverseMatrix);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInverseMatrixPerfect);
void iosInverseMatrixPerfect(void *dst, void *src)
{
    func_4001D5E0(4, dst, src);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosScaleMatrixV);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosFloatModulo);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosSetCameraMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosMakeNormalLightMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosScaleNormalLightMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosMakeLightColorMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransMatrix);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosGetScaleMatrixV);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotTransCurrentMatrix);

#include "common.h"

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", func_4001D5E0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", CompareString16);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInitCurrentMatrix);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransCurrentMatrix);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosApplyRotCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotTransPersCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransposeCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransposeRotationCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInverseCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosPushVu0Registers);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosPopVu0Registers);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInitPushPosVuSema);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosCopyMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosApplyRotMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosUnitMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosUnitRotation);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransposeMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInverseMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInverseMatrixPerfect);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosScaleMatrixV);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosFloatModulo);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosSetCameraMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosMakeNormalLightMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosScaleNormalLightMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosMakeLightColorMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransMatrixF);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosScaleMatrix);

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

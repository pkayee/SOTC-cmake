#include "common.h"

void func_4001D5E0(s32, void *, void *);
void iosGetAlignSinCosf(f32 *arg0, f32 arg1);
void iosGetSinCosf(f32 *out, f32 x);
extern u8 UnitMatrix[];

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", func_4001D5E0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", CompareString16);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInitCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosUnitCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosPushCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosPopCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosPushVu0RegistersToWork);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosPopVu0RegistersFromWork);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosSetTransCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosClearTransCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosGetRotXVector);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosGetRotYVector);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotCurrentMatrixX);


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotCurrentMatrixY);


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotCurrentMatrixZ);


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosScaleCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosGetCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosGetCurrentMatrixTrans);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosSetCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosMulCurrentMatrixR);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosMulCurrentMatrixL);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosApplyCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosApplyRotCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotTransPersCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransposeCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransposeRotationCurrentMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInverseCurrentMatrix);

extern u8 D_40081C70[];
extern u8 D_40081A70[];
s32 iosDI(void);
s32 iosEI(void);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosPushVu0Registers);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosPopVu0Registers);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInitPushPosVuSema);
static s32 D_40081E70;

void iosInitPushPosVuSema(void)
{
    D_40081E70 = iosCreateSema(1, 1, 0);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosCopyMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosApplyRotMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosUnitMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosUnitRotation);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosTransposeMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInverseMatrix);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosInverseMatrixPerfect);
void iosInverseMatrixPerfect(void *dst, void *src)
{
    func_4001D5E0(4, dst, src);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosScaleMatrixV);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosGetYDirXYZFromMatrix);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosGetXDirXYZFromMatrix);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosFmodf);
f32 fmodf(f32, f32);

f32 iosFmodf(f32 a, f32 b)
{
    return fmodf(a, b);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/math/matrix", iosRotTransCurrentMatrix);

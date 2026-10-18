#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0217_GetAdjustQuaternion", GetAdjustQuaternion);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0217_GetAdjustQuaternion", GetScaleQuaternion);

extern float getRatioFromInterp(float, float);

float getValueInterp(float fparg0, float fparg1, float fparg2, float fparg3)
{
    float temp_f0;

    temp_f0 = getRatioFromInterp(fparg2, fparg3);
    return (fparg1 * temp_f0) + (fparg0 * (1.0f - temp_f0));
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0217_GetAdjustQuaternion", createSlowLegCtrlWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0217_GetAdjustQuaternion", updateSlowLegCtrlWork);

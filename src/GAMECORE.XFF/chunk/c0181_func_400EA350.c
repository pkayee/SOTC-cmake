#include "common.h"

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA350);

void func_400EA350(f32 param_1, s32 *param_2, s32 param_3)
{
    f32 fVar1;

    if (param_2[0] == 0 || *(s32 *)(param_3 + 0x18ac) == 1)
    {
        fVar1 = *(f32 *)&param_2[2] - param_1 * 0.5f;
        *(f32 *)&param_2[2] = fVar1;
        if (fVar1 < 0.0f)
        {
            *(f32 *)&param_2[2] = 0.0f;
            return;
        }
    }
    else
    {
        *(f32 *)&param_2[1] = 1.0f;
        *(f32 *)&param_2[2] = *(f32 *)&param_2[2] + param_1;
    }
    return;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA3B8);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA4A8);

void func_400EA4A8(f32 param_1, f32 param_2, s32 param_3, s32 param_4)
{
    s32 bVar1;
    f32 fVar2;

    bVar1 = 0;
    *(s32 *)(param_3 + 0x24) = 0;
    if (*(s32 *)(param_3 + 0x1c) != 0 && 0.0f < param_1 && param_1 <= *(f32 *)(param_4 + 0x118))
    {
        *(s32 *)(param_3 + 0x24) = 1;
        if (*(s32 *)(param_4 + 0x18ac) == 0)
        {
            bVar1 = 1;
            *(f32 *)(param_3 + 0x20) = *(f32 *)(param_3 + 0x20) + param_2;
        }
    }
    if (bVar1 == 0)
    {
        fVar2 = *(f32 *)(param_3 + 0x20) - param_2;
        *(f32 *)(param_3 + 0x20) = fVar2;
        if (fVar2 < 0.0f)
        {
            *(f32 *)(param_3 + 0x20) = 0.0f;
        }
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA528);

s32 func_400EA528(s32 param_1, s32 param_2)
{
    return *(s32 *)(param_2 + 0x5d4) == 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA538);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA608);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA690);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA790);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA848);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA960);

f32 func_400EA960(f32 param_1, f32 param_2, f32 param_3)
{
    f32 fVar1;

    if (param_2 < 0.0f)
    {
        fVar1 = -param_2 / param_1;
    }
    else
    {
        fVar1 = param_2 / param_1;
    }
    if (fVar1 < param_3)
    {
        fVar1 = param_3;
    }
    return fVar1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA9A8);

void GAMEUTIL_doit_interp_ratio_cntrl(f32 param_1, ...);

void func_400EA9A8(f32 param_1, s32 param_2, s32 param_3)
{
    if (*(s32 *)(param_3 + 0x5d4) != 0)
    {
        param_1 = -param_1;
    }
    GAMEUTIL_doit_interp_ratio_cntrl(param_1);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA9C8);

void func_400EA9C8(f32 param_1, s32 param_2, s32 param_3)
{
    if (*(s32 *)(param_3 + 0x13c0) != 1)
    {
        param_1 = -param_1;
    }
    GAMEUTIL_doit_interp_ratio_cntrl(param_1, param_2 + 0x20);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EA9F0);

void func_400EA9F0(f32 param_1, s32 param_2, s32 param_3)
{
    if ((((s32)((*(s64 *)(param_3 + 0x3d0) << 2) >> 32)) & 1) == 0)
    {
        param_1 = -param_1;
    }
    GAMEUTIL_doit_interp_ratio_cntrl(param_1, param_2 + 0x40);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EAA20);

f32 GAMEUTIL_get_dist_ratio(f32 value, f32 min, f32 max);

f32 func_400EAA20(s32 *param_1)
{
    return GAMEUTIL_get_dist_ratio(*(f32 *)((u8 *)param_1 + 0x1a0), 0.0f, *(f32 *)(*param_1 + 0x170));
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EAA48);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EAAD8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EABA8);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EAD60);

f32 GAMEUTIL_get_interp_value_interp_value_cntrl(s32 c);
f32 GAMEUTIL_mul_ratio(f32 a, f32 b, s32 c);

f32 func_400EAD60(f32 param_1, s32 param_2, s32 param_3)
{
    f32 fVar1;

    if (param_1 == 0.0f)
    {
        return 0.0f;
    }
    if (0.0f < param_1)
    {
        fVar1 = GAMEUTIL_get_interp_value_interp_value_cntrl(param_2);
    }
    else
    {
        fVar1 = GAMEUTIL_get_interp_value_interp_value_cntrl(param_3);
    }
    return GAMEUTIL_mul_ratio(param_1, fVar1, 1);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EADD8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0181_func_400EA350", func_400EAEE0);

#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", DispWithTorchBlur);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", CheckSwordIndicateAimPoint);

s32 GAMEUTIL_is_player_obj(s32 chr);

extern s32 D_40131E34;

s32 CheckSwordIndicateAimPoint(s32 chr)
{
    if (GAMEUTIL_is_player_obj(chr) == 1)
    {
        return D_40131E34;
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", GetSwordFlareHitPlaneAttribute);

extern u64 D_40131D88;

u64 GetSwordFlareHitPlaneAttribute(void)
{
    return D_40131D88;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getMinAmbient);

extern f32 D_40131CF0;

f32 *getMinAmbient(void)
{
    return &D_40131CF0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getMaxAmbient);

extern f32 D_40131CF4;

f32 *getMaxAmbient(void)
{
    return &D_40131CF4;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getMinAmbientLine);

extern f32 D_40131CF8;

f32 *getMinAmbientLine(void)
{
    return &D_40131CF8;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getMaxAmbientLine);

extern f32 D_40131CFC;

f32 *getMaxAmbientLine(void)
{
    return &D_40131CFC;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getMinAngle);
extern f32 D_40131D00;

f32 *getMinAngle(void)
{
    return &D_40131D00;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getMaxAngle);
extern f32 D_40131D04;

f32 *getMaxAngle(void)
{
    return &D_40131D04;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getMaxLineAngle);
extern f32 D_40131D08;

f32 *getMaxLineAngle(void)
{
    return &D_40131D08;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getMinAmbientWeak);

extern f32 D_40131D0C;

f32 *getMinAmbientWeak(void)
{
    return &D_40131D0C;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getMaxAmbientWeak);

extern f32 D_40131D10;

f32 *getMaxAmbientWeak(void)
{
    return &D_40131D10;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getMinAmbientLineWeak);
extern f32 D_40131D14;

f32 *getMinAmbientLineWeak(void)
{
    return &D_40131D14;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getMaxAmbientLineWeak);
extern f32 D_40131D18;

f32 *getMaxAmbientLineWeak(void)
{
    return &D_40131D18;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getMinAngleWeak);
extern f32 D_40131D1C;

f32 *getMinAngleWeak(void)
{
    return &D_40131D1C;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getMaxAngleWeak);
extern f32 D_40131D20;

f32 *getMaxAngleWeak(void)
{
    return &D_40131D20;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getMaxLineAngleWeak);
extern f32 D_40131D24;

f32 *getMaxLineAngleWeak(void)
{
    return &D_40131D24;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getMaxFogMulVal);
extern f32 D_40131D28;

f32 *getMaxFogMulVal(void)
{
    return &D_40131D28;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getFogChangeSpeed);
extern f32 D_40131D2C;

f32 *getFogChangeSpeed(void)
{
    return &D_40131D2C;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getSwordLineWidthMax);
extern f32 D_40131D30;

f32 *getSwordLineWidthMax(void)
{
    return &D_40131D30;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getSwordLineChangeSpeed);
extern f32 D_40131D34;

f32 *getSwordLineChangeSpeed(void)
{
    return &D_40131D34;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getSwordLlineChangeThreshold);
extern f32 D_40131D38;

f32 *getSwordLlineChangeThreshold(void)
{
    return &D_40131D38;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", getBossHPRatioBase);
extern f32 D_40131D40;

f32 *getBossHPRatioBase(void)
{
    return &D_40131D40;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0155_DispWithTorchBlur", func_400D2958);
extern void seStop(s32);

extern s32 D_40131E00;
extern s32 D_40131D58[];
extern f32 D_40131D48;
extern s32 D_40131DA0;
extern s32 D_40131DA4;
extern s32 D_40131CD0;

void func_400D2958(s32 *a0)
{
    *a0 = 0;
    if (--D_40131E00 <= 0)
    {
        if (D_40131D58[1] != 0)
        {
            seStop(D_40131D58[1]);
            D_40131D58[1] = 0;
        }
        if (D_40131D58[2] != 0)
        {
            seStop(D_40131D58[2]);
            D_40131D58[2] = 0;
        }
        if (D_40131D58[3] != 0)
        {
            seStop(D_40131D58[3]);
            D_40131D58[3] = 0;
        }
        D_40131DA0 = 0;
        D_40131DA4 = 0;
        D_40131D48 = 1.0f;
        D_40131CD0 = 0;
    }
}

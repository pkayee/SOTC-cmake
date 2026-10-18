#include "common.h"

extern s32 D_40124860;

void skipBlur(s32 arg0)
{
    D_40124860 = arg0;
}

extern s32 D_40124870[3];

void setFadeColor(s32 color)
{
    if (color != 0)
    {
        if (color == 1)
        {
            D_40124870[0] = 200;
            D_40124870[1] = 200;
            D_40124870[2] = 200;
        }
    }
    else
    {
        D_40124870[0] = 0;
        D_40124870[1] = 0;
        D_40124870[2] = 0;
    }
}

extern s32 D_40124880;

void setFadeLayer(s32 value)
{
    D_40124880 = value;
}

typedef union { s128 q; float f[4]; int i[4]; } Vec4;
extern int D_401AB0A0[];
extern Vec4 D_401AB090;
extern float D_40124898;
extern void gluGetLookAtPosition(Vec4 *, float);

void cameraBlurClearIntensityArray(void)
{
    int i;
    Vec4 p;
    for (i = 7; i >= 0; i--)
        D_401AB0A0[i] = 0;
    gluGetLookAtPosition(&p, D_40124898);
    D_401AB090.q = p.q;
}

extern unsigned char D_40124884[];

void *getCameraBlurSw(void)
{
    return D_40124884;
}

extern unsigned char D_40124888[];

void *getBlurAlsoChara(void)
{
    return D_40124888;
}

extern unsigned char D_4012488C[];

void *getBlurWorkSize(void)
{
    return D_4012488C;
}

extern unsigned char D_40124890[];

void *getNBlurPlanes(void)
{
    return D_40124890;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0014_skipBlur", getBlurIntensity);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0014_skipBlur", getBlurZBase);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0014_skipBlur", getBlurMinThreshold);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0014_skipBlur", getBlurMaxThreshold);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0014_skipBlur", getBlurShutterSpeed);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0014_skipBlur", getBlurXYZRatio);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0014_skipBlur", getBlurCamMoveThreshold);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0014_skipBlur", getBankAngle);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0014_skipBlur", glBeginWithDlLayerNo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0014_skipBlur", func_40024DA8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0014_skipBlur", func_40025190);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0014_skipBlur", func_400255E0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0014_skipBlur", func_400259C8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0014_skipBlur", func_40025D88);

#include "common.h"

void iosDlPushLayer(s32);
void gsRegBegin(void);
void gsRegEnd(void);
void gsReg(s32, u64);
void iosSetRootDC(void);
void iosDlPopLayer(void);

void waterRefractionEnd(void)
{
    iosDlPushLayer(9);
    gsRegBegin();
    gsReg(0x49, 0);
    gsReg(0x42, 0x44);
    gsReg(0x47, 0x5078D);
    gsRegEnd();
    iosSetRootDC();
    iosDlPopLayer();
}

extern u8 D_4012A554[];

void *getIsInWater(void)
{
    return D_4012A554;
}

extern u8 D_4012A558[];

void *getRefractBlurSpeed(void)
{
    return D_4012A558;
}

extern u8 D_4012A55C[];

void *getRefractBlurSpeedRand(void)
{
    return D_4012A55C;
}

extern u8 D_4012A560[];

void *getRefractBlurLevel(void)
{
    return D_4012A560;
}

extern u8 D_4012A564[];

void *getRefractBlurLevelRand(void)
{
    return D_4012A564;
}

extern u8 D_4012A568[];

void *getRefractLengthRatio(void)
{
    return D_4012A568;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0029_waterRefractionEnd", getRefractBlendRatio);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0029_waterRefractionEnd", getRefractBrightness);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0029_waterRefractionEnd", shadowReset);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0029_waterRefractionEnd", shadowDraw);

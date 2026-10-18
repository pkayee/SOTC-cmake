#include "common.h"

void iosDlPushLayer(s32);
void texResetVRAMRequest(s32);
void iosSetRootDC(void);
void iosDlPopLayer(void);
s32 *getFogUnderWater(void);
void func_400350F8(void);
void gsRegBegin(void);
void gsRegEnd(void);
void gsReg(s32, u64);

void reflectionEnd(void)
{
    iosDlPushLayer(0xF);
    texResetVRAMRequest(0);
    iosSetRootDC();
    iosDlPopLayer();
}

extern u8 D_4012A520[];

void *getRefBlurLevel(void)
{
    return D_4012A520;
}

void reflectionInit(void) {
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0028_reflectionEnd", refractionBegin);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0028_reflectionEnd", waterRefractionBegin);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0028_reflectionEnd", func_400350F8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0028_reflectionEnd", refractionInit);

void refractionEnd(void)
{
    iosDlPushLayer(0x14);
    if (*getFogUnderWater() != 0)
        func_400350F8();
    gsRegBegin();
    gsReg(0x42, 0x44);
    gsReg(0x47, 0x5078D);
    gsRegEnd();
    iosSetRootDC();
    iosDlPopLayer();
}

#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0022_lineObjectFlip", lineObjectFlip);

extern s32 D_4012A098;
extern s32 transMicroCode();
extern void iosDlChainTailCurrent();

s32 debugLineObjectSetup(void)
{
    D_4012A098 = -1;
    return transMicroCode(11);
}

void debugLineObjectSetAttribute(int arg0)
{
    if ((D_4012A098 == -1) || (arg0 != D_4012A098)) {
        if (arg0 != -1) {
            iosDlChainTailCurrent();
        }
        D_4012A098 = arg0;
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0022_lineObjectFlip", debugLineObjectCreateAttributre);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0022_lineObjectFlip", debugLineObjectSetMatrix);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0022_lineObjectFlip", debugLineObjectSetBillboardMatrix);

extern int *D_401ABD50[];
extern s32 iosDlGetWorkBufId(void);

void debugLineObjectDisp(int i)
{
    int *t = D_401ABD50[i];

    t += iosDlGetWorkBufId();
    iosDlChainTailCurrent(t[2]);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0022_lineObjectFlip", lineObjectDispImmediatef);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0022_lineObjectFlip", lineObjectCreate);

#include "common.h"

extern unsigned char D_40124798[];

void *getBgAntiLevel(void)
{
    return D_40124798;
}

void bgInit(void) {
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0009_getBgAntiLevel", setBossEffectTexture);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0009_getBgAntiLevel", bossDeathEffectBegin);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0009_getBgAntiLevel", bossDeathEffectEnd);

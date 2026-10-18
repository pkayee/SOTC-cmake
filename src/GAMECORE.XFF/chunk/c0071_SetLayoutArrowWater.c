#include "common.h"

extern s32 DldSysUndefSymbol;

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", SetLayoutArrowWater);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", InitArrowWater);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", arrowWaterInit);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", arrowWaterMain);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", getFallenLeafSize);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", EnableArrowWater);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", EndArrowWater);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", CheckEnableArrowWater);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", CheckStartArrowWater);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", UpdateArrowWater);

int getArrowWaterSize(char *a)
{
    unsigned int *h = (unsigned int *)(a + 0x1C);
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;
    char *p = (t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0;
    return (*(int *)(p + 8) << 6) + 0xDE0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", doit_game_camera_model);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", gameover);

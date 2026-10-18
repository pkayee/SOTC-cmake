#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0018_kPrintf", kPrintf);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0018_kPrintf", kPrintfScale);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0018_kPrintf", kPrintfAsSprite);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0018_kPrintf", kprintfSJIS);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0018_kPrintf", kprintfContext);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0018_kPrintf", kprintfContextCentering);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0018_kPrintf", kprintfContextSJIS);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0018_kPrintf", func_4002A2D8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0018_kPrintf", kInit);

extern s32 D_40129F80;

void kSetTex(s32 arg0)
{
    D_40129F80 = arg0;
}

typedef struct
{
    char pad0[0x90];
    f32 r;
    f32 g;
    f32 b;
    f32 a;
    s32 mode;
} KColorState;

extern KColorState D_40129E30;

void kColor(s32 mode, f32 r, f32 g, f32 b, f32 a)
{
    KColorState *k = &D_40129E30;

    k->r = r;
    k->g = g;
    k->b = b;
    k->a = a;
    k->mode = mode;
}

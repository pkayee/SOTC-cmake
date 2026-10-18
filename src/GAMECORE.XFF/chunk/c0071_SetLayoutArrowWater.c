#include "common.h"

extern s32 DldSysUndefSymbol;

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", SetLayoutArrowWater);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", InitArrowWater);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", arrowWaterInit);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", arrowWaterMain);

/* NEARMISS-STUB getFallenLeafSize */
#if 0 /* NEARMISS 83.0% cat=regalloc sub=- | target keeps 0x160 in reg before beqz; ours folds it, beqzl | attempts=1 */
int getFallenLeafSize(char *a)
{
    unsigned int *h = (unsigned int *)(a + 0x1C);
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;
    char *p = (t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0;
    int n;
    int base = 0x160;
    if (*(int *)(a + 0x30) != 0)
    {
        n = *(int *)(a + 0x3C);
    }
    else
    {
        n = *(int *)(a + 0x28) * *(int *)(a + 0x2C);
    }
    return (n << 7) + base + (*(int *)(p + 8) << 6);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", getFallenLeafSize);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", EnableArrowWater);
extern s32 D_40203690[];

void EnableArrowWater(s32 param)
{
    s32 i = 0;
    s32 *p = D_40203690;
    do {
        if (p[0] == 0) {
            p[0] = 1;
            p[2] = param;
            p[3] = 0;
            return;
        }
        i++;
        p += 4;
    } while (i < 0x19);
    return;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", EndArrowWater);
void EndArrowWater(s32 param)
{
    s32 i;

    for (i = 0; i < 0x19; i++) {
        if (D_40203690[i * 4 + 2] == param) {
            D_40203690[i * 4] = 0;
            D_40203690[i * 4 + 2] = 0;
            D_40203690[i * 4 + 3] = 0;
            return;
        }
    }
}

extern s32 D_40203690[];

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", CheckEnableArrowWater);
s32 CheckEnableArrowWater(s32 idx)
{
    return D_40203690[idx * 4];
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", CheckStartArrowWater);
s32 CheckStartArrowWater(s32 idx)
{
    if (D_40203690[idx * 4] != 0)
    {
        if (*(D_40203690 + idx * 4 + 1) == 0)
        {
            return 1;
        }
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0071_SetLayoutArrowWater", UpdateArrowWater);
typedef struct { u8 pad[0x190]; f32 frameTime; } GcGlobalArrow;
extern u8 gcGlobalVar[];

void UpdateArrowWater(void)
{
    s32 i;

    for (i = 0; i < 0x19; i++) {
        D_40203690[i * 4 + 1] = D_40203690[i * 4];
        if (D_40203690[i * 4] != 0) {
            *(f32 *)&D_40203690[i * 4 + 3] = *(f32 *)&D_40203690[i * 4 + 3] + ((GcGlobalArrow *)gcGlobalVar)->frameTime;
        }
    }
}

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

#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0085_func_40076E40", func_40076E40);

extern s32 D_4012AFC8;

s32 getIkExpressionSwBool(void)
{
    return D_4012AFC8;
}

extern unsigned char D_4012AFC0[];

void *getRootFittingEnableFlag(void)
{
    return D_4012AFC0;
}

extern unsigned char D_4012AFC4[];

void *getRootFittingMode(void)
{
    return D_4012AFC4;
}

void *getIkExpressionSw(void)
{
    return &D_4012AFC8;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0085_func_40076E40", GetCharacterClassOptionNodeBasePos);

void resetExpressionLocalHeightDiff(char *c)
{
    int n = 0;
    int *d = *(int **)(c + 0x338);
    char *m = *(char **)(c + 0x354);
    if (m != 0)
        n = *(int *)(m + 0x20);
    while (n-- != 0)
        *d++ = 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0085_func_40076E40", CalcRootFitting);

extern u8 *GetCharacterClass(u8 *obj);

void SetCharacterObjForceNoExpressionInterp(void *actor)
{
    (*(signed char *)((char *)(GetCharacterClass(actor)) + 0x518)) = 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0085_func_40076E40", func_40077930);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0085_func_40076E40", func_400781A8);

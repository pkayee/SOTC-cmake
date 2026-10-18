#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0052_getSkeletonGlobalGeo", getSkeletonGlobalGeo);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0052_getSkeletonGlobalGeo", func_4004FED8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0052_getSkeletonGlobalGeo", func_40050298);

extern int DldSysUndefSymbol;
extern char *GetCharacterClass(void *);
extern int getEffectBloodWorkSize(int);

static inline char *dldResolve(unsigned int *h)
{
    unsigned int v = *h;
    int off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;

    return (t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0;
}

static inline int dldCount(int *h)
{
    int off = *h & 0x3FFFF;
    int *t = off != 0 ? *(int **)((char *)h - off) : 0;

    return (t != 0 && t != (int *)DldSysUndefSymbol) ? t[3] : 0;
}

int SCRGetSizeOfBossWork(void *a)
{
    char *p = dldResolve(*(unsigned int **)(GetCharacterClass(a) + 0x3E4));
    char *q = dldResolve((unsigned int *)(p + 0xC));
    int n = dldCount((int *)(p + 8));

    return n * 4 + getEffectBloodWorkSize(*(int *)(q + 0x20)) + 0x156;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0052_getSkeletonGlobalGeo", SCRCharaInitBossWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0052_getSkeletonGlobalGeo", func_40050A90);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0052_getSkeletonGlobalGeo", func_40050C08);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0052_getSkeletonGlobalGeo", func_40050FB8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0052_getSkeletonGlobalGeo", func_40051170);

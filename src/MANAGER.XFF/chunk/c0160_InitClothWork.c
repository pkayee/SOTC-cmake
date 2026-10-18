#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0160_InitClothWork", InitClothWork);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0160_InitClothWork", CheckClothChainDetect);

int GetClothWorkSize(char *c)
{
    int n = 0;
    char *p = c;
    int size;
    int i;

    while (*(short *)p >= 0) {
        p += 0x34;
        n++;
    }
    size = n * 0xC3 + 0x47;
    for (i = 0; i < n; i++) {
        size = size + (*(int *)(c + 4) * 24 + *(int *)(c + 4) * *(int *)(c + 8) * 64) + 0x33;
        c += 0x34;
    }
    return size;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0160_InitClothWork", DebugDumpClothResources);

typedef struct {
    char *p;
    short n;
} Cloth;

extern void func_400C9E30(char *);
extern void func_400C9BE0(char *);

int DispCloth(Cloth *c)
{
    char *p = c->p;
    int n = c->n;
    int i;

    for (i = 0; i < n; i++) {
        if (p[0x81] == 0)
            func_400C9E30(p);
        else
            p[0x81] = 0;
        p += 0x90;
    }
    return 1;
}

int DebugDispCloth(Cloth *c)
{
    char *p = c->p;
    int n = c->n;
    int i;

    for (i = 0; i < n; i++) {
        func_400C9BE0(p);
        p += 0x90;
    }
    return 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0160_InitClothWork", FlushClothWork);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0160_InitClothWork", SetClothAccessSwitch);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0160_InitClothWork", SetClothWorkDispFlag);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0160_InitClothWork", GetClothQuaternion);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0160_InitClothWork", GetClothPosition);

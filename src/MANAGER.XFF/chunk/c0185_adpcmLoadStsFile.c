#include "common.h"

typedef struct Ptn Ptn;
extern Ptn rootPtn;
extern void *iosMallocAlign(Ptn *, int, int);
extern char *sheetFileGetDataAdrs(void *);
extern void sheetFileRead(void *, void *, int);

int adpcmLoadStsFile(void *f, int unused, int size)
{
    void *b = iosMallocAlign(&rootPtn, size, 16);
    char *d = sheetFileGetDataAdrs(f);
    sheetFileRead(f, b, size);
    *(void **)(d + 0x10) = b;
    return 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", func_400E90B8);

extern s32 D_4012E020;

void func_400E90B8(void)
{
    D_4012E020 = 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", func_400E90C8);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", func_400E90D8);

void func_400E90D8(void)
{
    D_4012E020 = 2;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", func_400E90E8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", func_400E90F8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", func_400E9178);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", func_400E91F0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", func_400E92B0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", createAdpcmTest);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", func_400E9390);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", sound3DCalc);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", func_400E95D8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", seSwapHDBDFile);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", sePlay3D);

extern s32 DldSysUndefSymbol;
void func_400EA248(void);
void func_400EA690(void);
extern char *sndSepReq(void *, void *, int, int, int, int, int);

static inline char *sepReq(void *f1, void *f2, int u, int id)
{
    if (id == u)
        return 0;
    return sndSepReq(f1, f2, 0, id, 0, 2, 0);
}

char *sePlayStageEnv(int id, int val)
{
    char *s = sepReq(func_400EA248, func_400EA690, *(int *)DldSysUndefSymbol, id);
    if (s == 0)
        return 0;
    *(int *)(s + 0x3C) = val;
    return s;
}

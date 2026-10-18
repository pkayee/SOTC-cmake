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

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", func_400E90C8);

void func_400E90C8(void)
{
    D_4012E020 = 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", func_400E90D8);

void func_400E90D8(void)
{
    D_4012E020 = 2;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", func_400E90E8);

extern s32 D_4012E024;

s32 *func_400E90E8(void)
{
    return &D_4012E024;
}

/* NEARMISS-STUB func_400E90F8 */
#if 0 /* NEARMISS 91.6% cat=regalloc sub=- | x in a3 not a2; &D_4012E028 in a4 not a3; p copy a5 not t0 early | attempts=1 */
extern char D_4012E088[];
extern s32 D_4012E028;
extern s32 DldSysUndefSymbol;
extern u8 SH_AdpcmSeqDEFAULT[];
extern void createParamMenu(char *, s32, s32);

void func_400E90F8(s32 unused0, s32 unused1, s32 *p)
{
    char *s = D_4012E088;
    s32 *q = p;

    if (*(s32 *)(s + 0x30) == 0)
    {
        u8 *sh = (DldSysUndefSymbol == (s32)SH_AdpcmSeqDEFAULT) ? 0 : SH_AdpcmSeqDEFAULT;
        s32 x = *(s32 *)(sh + 0x10);
        D_4012E028 = x;
        D_4012E028 = x + *q * 56;
        createParamMenu(s, 0, D_4012E028);
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", func_400E90F8);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", func_400E9178);

extern s32 DldSysUndefSymbol;
extern s32 D_4012E018;
extern s32 D_4012E01C;
extern s32 D_4012E0C0[];
extern u8 SH_AdpcmSeqDEFAULT[];
extern void createSheetMenu(s32 *, s32);

void func_400E9178(void)
{
    u8 *sh = 0;

    if (DldSysUndefSymbol != (s32)SH_AdpcmSeqDEFAULT)
    {
        sh = SH_AdpcmSeqDEFAULT;
    }
    if (D_4012E018 != 0)
    {
        D_4012E01C = 1;
        D_4012E0C0[2] = *(s32 *)(sh + 0x10);
        D_4012E0C0[3] = *(s32 *)(sh + 0xC);
        createSheetMenu(D_4012E0C0, 0);
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", func_400E91F0);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", func_400E92B0);

extern s32 D_4012E228;
extern s32 D_4012E018;
extern s32 D_4012E01C;
extern u8 D_401B2428[];

void func_400E92B0(void)
{
    s32 idx = D_4012E228;

    if (idx >= 0)
    {
        if (D_4012E018 != 0)
        {
            u8 *p = D_401B2428 + idx * 0x560;
            *(s32 *)(p + 0x44) = 0;
            *(u64 *)(p + 0x38) |= 0x2000000000;
        }
        D_4012E228 = -1;
    }
    D_4012E01C = 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", createAdpcmTest);

extern s32 D_4012E230[];

void createAdpcmTest(void)
{
    u8 *sh = 0;

    if (DldSysUndefSymbol != (s32)SH_AdpcmSeqDEFAULT)
    {
        sh = SH_AdpcmSeqDEFAULT;
    }
    if (D_4012E018 != 0)
    {
        D_4012E01C = 1;
        D_4012E230[2] = *(s32 *)(sh + 0x10);
        D_4012E230[3] = *(s32 *)(sh + 0xC);
        createSheetMenu(D_4012E230, 0);
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0185_adpcmLoadStsFile", func_400E9390);

extern s32 D_4012E028;

void func_400E9390(s32 unused0, s32 unused1, s32 unused2, s32 *p)
{
    s32 v;

    switch (D_4012E020)
    {
    case 0:
        *p = -2;
        return;
    case 1:
        break;
    default:
        v = D_4012E028;
        D_4012E028 = 0;
        if (v != 0)
        {
            *p = D_4012E024;
            return;
        }
        break;
    }
    *p = -1;
}

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

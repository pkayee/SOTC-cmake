#include "common.h"

extern void func_401258C0();
extern char rootPtn[];
extern char D_40137838[];
void *_gcCreateChildScriptObj(void *, void *, void *, int, int, int, char *, void *);

void *createScrDemoManager(void *parent)
{
    return _gcCreateChildScriptObj(func_401258C0, parent, rootPtn, 0x4000, 0, 4, D_40137838, parent);
}

extern s32 D_40132440;
extern s32 D_40132444;

void setScrDemoMangerFinishCallback(s32 arg0, s32 arg1)
{
    D_40132440 = arg0;
    D_40132444 = arg1;
}

extern s32 D_40132448;

void pauseEventDemoManger(s32 on)
{
    s32 *p = &D_40132448;
    s32 v;

    if (on == 1)
    {
        v = *p + 1;
    }
    else
    {
        v = *p - 1;
    }
    *p = v;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0230_createScrDemoManager", createScrEventDemoManager);

extern char D_4021E1E8[];
extern void *memset(void *, int, unsigned int);

void scrDemoInit(void)
{
    memset(D_4021E1E8, 0, 0xA8);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0230_createScrDemoManager", func_40126440);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0230_createScrDemoManager", func_40126508);
extern void bgmStop(void *, s32, f32);

void func_40126508(s32 a0, s32 a1, s32 a2, s32 a3, s32 *p)
{
    if (p[6] != 0)
    {
        bgmStop((void *)p[6], 0, 100.0f);
        p[7] = 1;
        p[6] = 0;
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0230_createScrDemoManager", updateEyeWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0230_createScrDemoManager", createEyeWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0230_createScrDemoManager", updateHintWork);

extern int *DldSysUndefSymbol;
extern char *getSCRDataCtrlWork(void *);

static inline int dldData(unsigned int *h)
{
    int off = *h & 0x3FFFF;
    int *t = off != 0 ? *(int **)((char *)h - off) : 0;

    return (t != 0 && t != DldSysUndefSymbol) ? t[4] : 0;
}

static inline int dldCount(unsigned int *h)
{
    int off = *h & 0x3FFFF;
    int *t = off != 0 ? *(int **)((char *)h - off) : 0;

    return (t != 0 && t != DldSysUndefSymbol) ? t[3] : 0;
}

void createHintWork(void *actor, unsigned int *h)
{
    int *w = (int *)(getSCRDataCtrlWork(actor) + 0x40C0);

    w[0] = dldData(h);
    w[1] = dldCount(h);
    w[2] = 0;
    w[3] = 0;
}

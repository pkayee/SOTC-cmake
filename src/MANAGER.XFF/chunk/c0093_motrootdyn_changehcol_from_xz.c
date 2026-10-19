#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0093_motrootdyn_changehcol_from_xz", motrootdyn_changehcol_from_xz);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0093_motrootdyn_changehcol_from_xz", motrootdyn_startxzfit_common);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0093_motrootdyn_changehcol_from_xz", xzfit);

extern int GetScrLwsOriClass();
extern int GetScriptAnimationClass();

int GetChildGroupManagerClass(void *arg0)
{
    unsigned char temp_v1;

    temp_v1 = (*(unsigned char *)((char *)(arg0) + 8));
    switch (temp_v1) {                              /* irregular */
    case 13:
        return GetScriptAnimationClass() + 0x320;
    case 22:
        return GetScrLwsOriClass() + 0x1140;
    default:
        return 0;
    }
}

extern void isysInitGroup(char *);

void InitChildGroupManagerObj(unsigned char *p)
{
    char *g;

    switch (p[8]) {
    case 0xD:
        g = GetScriptAnimationClass() + 0x320;
        break;
    case 0x16:
        g = GetScrLwsOriClass() + 0x1140;
        break;
    default:
        g = 0;
        break;
    }
    g[0] = 0;
    isysInitGroup(g + 2);
}

void EntryChildGroupManagerObj(unsigned char *o, void *b, void *c)
{
    char *m;

    switch (o[8]) {
    case 0xD:
        m = GetScriptAnimationClass(o) + 0x320;
        break;
    case 0x16:
        m = GetScrLwsOriClass(o) + 0x1140;
        break;
    default:
        m = 0;
        break;
    }
    *m = 1;
    ScanAllTwoWayLink(b, c, m + 2);
}

extern void isysDeleteGroupAllObj(char *);

void FlushChildGroupManagerObj(unsigned char *p)
{
    char *g;

    switch (p[8]) {
    case 0xD:
        g = GetScriptAnimationClass(p) + 0x320;
        break;
    case 0x16:
        g = GetScrLwsOriClass(p) + 0x1140;
        break;
    default:
        g = 0;
        break;
    }
    isysDeleteGroupAllObj(g + 2);
    g[0] = 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0093_motrootdyn_changehcol_from_xz", ExecChildGroupManagerObj);

extern s32 DldSysUndefSymbol;

typedef struct { s32 w[3]; } DemoOri12;

DemoOri12 *GetDemoOrientNext(u8 *o)
{
    u32 *h = *(u32 **)(o + 0x10);
    u32 w = *h;
    s32 off = w & 0x3FFFF;
    DemoOri12 *cur = *(DemoOri12 **)(o + 0x14);
    u8 *t = off != 0 ? *(u8 **)((u8 *)h - off) : 0;
    s32 n = (t != 0 && t != (u8 *)DldSysUndefSymbol) ? *(s32 *)(t + 0xC) : 0;
    u32 w2 = *(volatile u32 *)h;
    s32 off2 = w2 & 0x3FFFF;
    u8 *t2 = off2 != 0 ? *(u8 **)((u8 *)h - off2) : 0;
    DemoOri12 *base = (DemoOri12 *)((t2 != 0 && t2 != (u8 *)DldSysUndefSymbol) ? *(u8 **)(t2 + 0x10) + ((w2 >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(t2 + 8) + 0xC) : 0);

    if (cur - base < n - 1) {
        return *(DemoOri12 **)(o + 0x14) = cur + 1;
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0093_motrootdyn_changehcol_from_xz", SetDemoMotionOrientInfo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0093_motrootdyn_changehcol_from_xz", func_400811A0);

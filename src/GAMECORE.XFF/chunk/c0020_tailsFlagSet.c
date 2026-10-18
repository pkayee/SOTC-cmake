#include "common.h"
extern u8 D_401FC788[];
void *memcpy(void *d, const void *s, u32 n);
s32 mcRead();
void optionMenuParamSetLoadData();
typedef struct { u8 *p[2]; } OmGrp2;
extern u8 D_401FD0A2[];
extern u8 D_401FD098[];
extern OmGrp2 D_40132E98;
extern u8 D_401FCA58[];
extern u8 D_401FCD78[];
extern u8 D_401FCA58[];
extern u8 D_401FCD78[];
extern u8 D_401FD09A[];
extern u8 D_401FD0A2[];
extern u8 D_401FD098[];
extern u8 D_401FC788[];
void *memset(void *d, s32 c, u32 n);
void _omakeSelectFlagSet();
s32 mcWrite();
void optionMenuParamSetDefault();

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", tailsFlagSet);
extern u8 D_401FCA58[];
extern u8 D_401FCD78[];
extern u8 D_401FD09A[];
extern u8 D_401FD0A2[];
extern u8 D_401FD098[];
extern u8 D_401FC788[];
void tailsFlagSet(s32 a, s32 b)
{
    s32 idx;
    s32 bit;
    u8 *p;
    u8 *t = D_401FCA58;

    if (a >= 100 || b >= 0x40) {
        p = 0;
    } else {
        idx = a * 64 + b;
        bit = idx & 7;
        p = t + (idx >> 3);
    }
    if (p != 0) {
        *p |= 1 << bit;
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", tailsFlagClr);
void tailsFlagClr(s32 a, s32 b)
{
    s32 idx;
    s32 bit;
    u8 *p;
    u8 *t = D_401FCA58;

    if (a >= 100 || b >= 0x40) {
        p = 0;
    } else {
        idx = a * 64 + b;
        bit = idx & 7;
        p = t + (idx >> 3);
    }
    if (p != 0) {
        *p &= ~(1 << (bit & 7));
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", tailsFlagsAllClr);
void *memset(void *d, s32 c, u32 n);
void tailsFlagsAllClr(void)
{
    memset(D_401FCA58, 0, 0x320);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", tailsFlagChk);
extern u8 D_401FCA58[];
extern u8 D_401FCD78[];
s32 tailsFlagChk(s32 a, s32 b)
{
    s32 idx;
    s32 bit;
    u8 *p;
    u8 *t = D_401FCA58;

    if (a >= 100 || b >= 0x40) {
        p = 0;
    } else {
        idx = a * 64 + b;
        bit = idx & 7;
        p = t + (idx >> 3);
    }
    if (p != 0 && ((*p >> bit) & 1) != 0) {
        return 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", gexsFlagSet);
void gexsFlagSet(s32 a, s32 b)
{
    s32 idx;
    s32 bit;
    u8 *p;
    u8 *t = D_401FCD78;

    if (a >= 100 || b >= 0x40) {
        p = 0;
    } else {
        idx = a * 64 + b;
        bit = idx & 7;
        p = t + (idx >> 3);
    }
    if (p != 0) {
        *p |= 1 << bit;
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", gexsFlagClr);
void gexsFlagClr(s32 a, s32 b)
{
    s32 idx;
    s32 bit;
    u8 *p;
    u8 *t = D_401FCD78;

    if (a >= 100 || b >= 0x40) {
        p = 0;
    } else {
        idx = a * 64 + b;
        bit = idx & 7;
        p = t + (idx >> 3);
    }
    if (p != 0) {
        *p &= ~(1 << (bit & 7));
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", gexsFlagChk);
s32 gexsFlagChk(s32 a, s32 b)
{
    s32 idx;
    s32 bit;
    u8 *p;
    u8 *t = D_401FCD78;

    if (a >= 100 || b >= 0x40) {
        p = 0;
    } else {
        idx = a * 64 + b;
        bit = idx & 7;
        p = t + (idx >> 3);
    }
    if (p != 0 && ((*p >> bit) & 1) != 0) {
        return 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", _omakeGetFlagSet);
void _omakeGetFlagSet(s32 bit)
{
    D_401FD09A[bit / 8] |= 1 << (bit & 7);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", _omakeGetFlagCls);
void _omakeGetFlagCls(s32 bit)
{
    D_401FD09A[bit / 8] &= ~(1 << (bit & 7));
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", _omakeGetFlagChk);
s32 _omakeGetFlagChk(s32 bit)
{
    return (D_401FD09A[bit / 8] >> (bit & 7)) & 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", _omakeSelectFlagCls);
extern u8 D_401FD0A2[];
extern u8 D_401FD098[];
extern OmGrp2 D_40132E98;
void _omakeSelectFlagCls(s32 bit)
{
    OmGrp2 grp = D_40132E98;
    u8 **pp;
    u8 *g;
    u8 *found;
    s32 i;

    for (pp = grp.p; (g = *pp) != 0; pp++) {
        for (i = 0; g[i] != 0; i++) {
            if (bit == g[i]) {
                found = g;
                goto done;
            }
        }
    }
    found = 0;
done:
    D_401FD0A2[bit / 8] &= ~(1 << (bit & 7));
    if (found != 0) {
        u8 *o = D_401FD098;

        if (*(s32 *)(o + 0x20) != 0) {
            u8 *q = o + 0xB;

            *q |= 4;
        }
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", _omakeSelectFlagChk);
s32 _omakeSelectFlagChk(s32 bit)
{
    return (D_401FD0A2[bit / 8] >> (bit & 7)) & 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", omakeGetAndSelectSet);
void _omakeSelectFlagSet();
void omakeGetAndSelectSet(s32 bit)
{
    D_401FD09A[bit / 8] |= 1 << (bit & 7);
    _omakeSelectFlagSet(bit);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", setClearGameHotStartFlag);
void setClearGameHotStartFlag(s32 a0)
{
    u64 *p = (u64 *)D_401FD098;

    *p = (*p & ~0x100ULL) | ((u64)(a0 & 1) << 8);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", getClearGameHotStartFlag);
s32 getClearGameHotStartFlag(void)
{
    return (s32)(*(u64 *)D_401FD098 >> 8) & 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", gOptionMcSave);
s32 mcWrite();
s32 gOptionMcSave(s32 a0)
{
    return mcWrite(a0, D_401FC788, 0x88);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", gOptionMcLoad);
extern u8 D_401FC788[];
void *memcpy(void *d, const void *s, u32 n);
s32 mcRead();
void optionMenuParamSetLoadData();
s32 gOptionMcLoad(s32 a0)
{
    u8 backup[0x88];
    s32 r;

    memcpy(backup, D_401FC788, 0x88);
    r = mcRead(a0, D_401FC788, 0x88);
    if (r == 0) {
        optionMenuParamSetLoadData();
    } else {
        memcpy(D_401FC788, backup, 0x88);
    }
    return r;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", optionFlagInit);
void optionMenuParamSetDefault();
void optionFlagInit(void)
{
    memset(D_401FC788, 0, 0x88);
    optionMenuParamSetDefault();
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", getOptionDataAdrsAndSize);
u8 *getOptionDataAdrsAndSize(s32 *size)
{
    *size = 0x88;
    return D_401FC788;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", func_4002B300);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", func_4002B660);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0020_tailsFlagSet", func_4002BA78);

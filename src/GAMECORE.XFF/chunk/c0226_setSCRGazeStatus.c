#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0226_setSCRGazeStatus", setSCRGazeStatus);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0226_setSCRGazeStatus", getDPGroupID);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0226_setSCRGazeStatus", execCondition);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0226_setSCRGazeStatus", func_401215B8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0226_setSCRGazeStatus", checkDeadMotionLoadByScriptDataSystem);

extern void *GetSCRCharaAIWorkPtr(void *);

void *getSCRDataCtrlWork(void *actor)
{
    return (void *)(((u32)GetSCRCharaAIWorkPtr(actor) + 0x13) & ~0xF);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0226_setSCRGazeStatus", execSCRBaseFunc);

extern s32 DldSysUndefSymbol;
extern void setAttainRangeStruct();

static inline u8 *dldResolve(u32 *h)
{
    u32 v = *h;
    s32 off = v & 0x3FFFF;
    s32 *t = off != 0 ? *(s32 **)((u8 *)h - off) : 0;

    return (t != 0 && (s32)t != DldSysUndefSymbol) ? (u8 *)t[4] + ((v >> 18) & 0xFFF) * ((s32 *)t[2])[3] : 0;
}

void setSCRAttainRange(void *w, u32 *h)
{
    float *p = (float *)dldResolve(h);
    float r[8];

    if (p == 0)
        return;
    r[0] = p[0];
    r[1] = p[1];
    r[2] = p[2];
    r[3] = 1.0f;
    r[4] = p[3];
    r[5] = p[4];
    r[6] = p[5] * 3.1415926f / 180.0f;
    r[7] = p[6];
    setAttainRangeStruct(w, r);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0226_setSCRGazeStatus", loadRequestMotList);

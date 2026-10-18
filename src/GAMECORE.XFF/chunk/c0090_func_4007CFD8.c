#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", func_4007CFD8);

typedef struct { s32 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o; } MParam;
extern s32 ScriptLayoutObjDef_MISSILE_TYPE1;
extern u8 gcGlobalVar[];
extern u8 rootPtn[];
extern void *initScriptLayoutObj(void *, s32, MParam *, s32, s32, void *, s32);
extern void isysAddGroupWithLinkParam(void *, void *, s32, s32);
extern void *isysGetThisSubThread(void);
extern int iosCreatePartition(void *, int);
extern char *GetScriptLayoutClass(void *);
extern void SetScriptLayoutObjLetterProcMode(void *, int);
extern char *_SCRMallocAlign(int, int, int);
extern void isysJumpSubThread(void (*)(void), void *);
extern void func_4007CFD8(void);

void SCRSetupMissile1(void *a, s32 b, s32 c, s32 d)
{
    MParam s;
    void *o;
    s.a = 0;
    s.b = b;
    s.c = c;
    s.d = 0;
    s.i = 0;
    s.e = 0;
    s.f = 0;
    s.g = 0;
    s.h = 1;
    s.j = 0;
    s.k = 0;
    s.l = 1;
    s.m = 0;
    s.n = 0;
    s.o = 0;
    o = initScriptLayoutObj(rootPtn, ScriptLayoutObjDef_MISSILE_TYPE1, &s, d, 4, a, 0);
    if (o != 0)
    {
        isysAddGroupWithLinkParam(o, gcGlobalVar + 0x280, 0, 0);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", func_4007D210);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", func_4007D240);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", func_4007D330);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", func_4007D378);

void nico_missile1start(int arg)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, 0x53);
    char *c;
    char *w;

    *(int *)(GetScriptLayoutClass(th) + 0x2D4) = part;
    SetScriptLayoutObjLetterProcMode(th, 1);
    c = GetScriptLayoutClass(th);
    w = _SCRMallocAlign(part, 0x20, 0x10);
    *(char **)(c + 0x2D8) = w;
    *(int *)(w + 0x10) = arg;
    isysJumpSubThread(func_4007CFD8, w);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", CalcFootVec);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", CalcFootPos);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", CalcDistancePointAnd2Point);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", CalcDistancePointAndLine);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", MVHIST_Init);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", MVHIST_Update);

void DirectTurn_Reset(char *p)
{
    *(char *)(p + 0x14) = 0;
    *(int *)(p + 0x10) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", IsTouchableObj);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", nico_nargaBossStart);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0090_func_4007CFD8", SCRConditionNaragaBodyRot);

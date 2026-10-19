#include "common.h"

extern u8 gcGlobalVar[];
s32 *getSeamlessStageHighModelDispDistDefault(void);
s32 *getSeamlessStageMiddleModelDispDistDefault(void);
void getStageChipID(void *g, s32 *x, s32 *y);
void setLoadMode(s32 x, s32 y, s32 mode);

INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0001_CreateMapWindow", CreateMapWindow);

//INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0001_CreateMapWindow", func_40013F90);
extern s32 D_40014870;

void func_40013F90(void)
{
    s32 *p;

    p = &D_40014870;
    setLoadMode(p[1], p[2], 0);
}

//INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0001_CreateMapWindow", func_40013FB8);
void func_40013FB8(void)
{
    s32 *p;

    p = &D_40014870;
    setLoadMode(p[1], p[2], 1);
}

//INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0001_CreateMapWindow", func_40013FE0);
void func_40013FE0(void)
{
    s32 *p;

    p = &D_40014870;
    setLoadMode(p[1], p[2], 2);
}

void func_40014008(void)
{
    s32 *hi;
    s32 *mid;
    s32 x;
    s32 y;
    s32 r;
    s32 x0;
    s32 x1;
    s32 y0;
    s32 y1;
    s32 i;
    hi = getSeamlessStageHighModelDispDistDefault();
    mid = getSeamlessStageMiddleModelDispDistDefault();
    if (*mid < 3) {
        r = *hi + *mid;
        getStageChipID(gcGlobalVar + 0x340, &x, &y);
        x0 = (x - r) - 1;
        x1 = (x - r) + r * 2;
        y1 = (y - r) + r * 2;
        y0 = (y - r) - 1;
        for (i = x0; i <= x1; i++) {
            setLoadMode(i, y0, 2);
        }
        for (i = x0; i <= x1; i++) {
            setLoadMode(i, y1, 2);
        }
        for (i = y0; i <= y1; i++) {
            setLoadMode(x0, i, 2);
        }
        for (i = y0; i <= y1; i++) {
            setLoadMode(x1, i, 2);
        }
        *mid = *mid + 1;
    }
}

void func_40014180(void)
{
    s32 *hi;
    s32 *mid;
    s32 x;
    s32 y;
    s32 r;
    s32 x0;
    s32 x1;
    s32 y0;
    s32 y1;
    s32 i;
    hi = getSeamlessStageHighModelDispDistDefault();
    mid = getSeamlessStageMiddleModelDispDistDefault();
    if (*mid > 0) {
        *mid = *mid - 1;
        r = *hi + *mid;
        getStageChipID(gcGlobalVar + 0x340, &x, &y);
        x0 = (x - r) - 1;
        x1 = (x - r) + r * 2;
        y1 = (y - r) + r * 2;
        y0 = (y - r) - 1;
        for (i = x0; i <= x1; i++) {
            setLoadMode(i, y0, 0);
        }
        for (i = x0; i <= x1; i++) {
            setLoadMode(i, y1, 0);
        }
        for (i = y0; i <= y1; i++) {
            setLoadMode(x0, i, 0);
        }
        for (i = y0; i <= y1; i++) {
            setLoadMode(x1, i, 0);
        }
    }
}

void setLoadMode(s32, s32, s32);

void func_400142E8(void)
{
    s32 i;
    s32 j;
    u8 *env;

    env = (u8 *)getSeamlessStageEnv();
    for (i = 0; i < *(s32 *)(env + 0x4c); i++)
    {
        for (j = 0; j < *(s32 *)(env + 0x48); j++)
        {
            setLoadMode(j, i, 0);
        }
    }
}

//INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0001_CreateMapWindow", func_40014378);
void func_40014378(void)
{
    s32 *p;

    p = (s32 *)getSeamlessStageStatusDispSw();
    if (*p == 1)
    {
        p = (s32 *)getSeamlessStageStatusDispSw();
        *p = 2;
    }
    else
    {
        p = (s32 *)getSeamlessStageStatusDispSw();
        *p = 1;
    }
}


//INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0001_CreateMapWindow", func_400143D0);
extern u32 D_4001485C;

void func_400143D0(void)
{
    D_4001485C = D_4001485C + 1;
    if (2 < D_4001485C)
    {
        D_4001485C = 0;
    }
}

//INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0001_CreateMapWindow", func_400143F8);
void windowSetCursorPos(f32 *position);

void func_400143F8(void)
{
    f32 *p;
    s32 *q;
    f32 zero;
    f32 half;

    zero = 0.0f;
    half = 0.5f;
    p = (f32 *)&D_40014870;
    p[4] = zero;
    p[3] = zero;
    q = (s32 *)D_40014870;
    p[8] = *(f32 *)((u8 *)q + 0x264) + *(f32 *)((u8 *)q + 0x26C) * half;
    p[9] = *(f32 *)((u8 *)q + 0x268) + *(f32 *)((u8 *)q + 0x270) * half;
    windowSetCursorPos((f32 *)(p + 8));
}

//INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0001_CreateMapWindow", func_40014458);
extern u8 gcGlobalVar[];
extern s32 D_40015000;
void *SCRGetFirstObj(void *table);
void DebugSetHorsePositionWithTargetOfs(void *obj, void *ofs);

void func_40014458(void)
{
    void *obj;

    obj = SCRGetFirstObj(gcGlobalVar + 0x2B0);
    DebugSetHorsePositionWithTargetOfs(obj, &D_40015000);
}

//INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0001_CreateMapWindow", func_40014488);
s32 createScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, void *a6, s32 a7);
void func_40014750(void);

void func_40014488(s32 a0, s32 a1, s32 a2)
{
    createScriptObj((void *)func_40014750, a2, *(void **)(gcGlobalVar + 0x308), 0x1000, 0, 0, 0, 0);
}

INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0001_CreateMapWindow", func_400144C8);

INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0001_CreateMapWindow", func_40014578);

INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0001_CreateMapWindow", func_40014648);

//INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0001_CreateMapWindow", func_400146F8);
void *getSeamlessStageStatusDispSw(void);
void windowCloseRequest(void *p);

void func_400146F8(void *a0, void *a1)
{
    s32 *p;

    p = (s32 *)getSeamlessStageStatusDispSw();
    if (*p == 0)
    {
        windowCloseRequest(a1);
    }
}

//INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0001_CreateMapWindow", func_40014738);
extern s32 D_40014870;
extern s32 D_400148C8;

void func_40014738(void)
{
    D_40014870 = 0;
    D_400148C8 = 0;
}

INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0001_CreateMapWindow", func_40014750);

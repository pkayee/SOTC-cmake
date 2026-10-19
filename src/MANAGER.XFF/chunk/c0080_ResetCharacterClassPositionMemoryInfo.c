#include "common.h"

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0080_ResetCharacterClassPositionMemoryInfo", ResetCharacterClassPositionMemoryInfo);

extern void DeleteTwoWayLink(void *);

typedef union { s128 q; float f[4]; } HitV;
typedef struct { s128 pad[4]; HitV v; } ColHit;
extern int CheckUnderVariableXZSurface();

extern int func_4006ADC0(int, int, int, int, int, float, float, int);
extern int func_4006B2A8(int, int);

extern void *GetGeometryPointerObject(void *);
extern void *GetLayoutClass(void *);
extern int AddTwoWayLinkNext(int *, int *);
extern void CopyGeometryPointer(void *, void *);

void ResetCharacterClassPositionMemoryInfo(char *p)
{
    if (*(int *)(p + 0xFC0) != 0) {
        *(int *)(p + 0xFC0) = 0;
        DeleteTwoWayLink(p + 0xFC4);
    }
}

extern int func_40074EA8();
extern int ClipCollisionFinderCallBack();

int charrootdyn_clipNoStopCollisionFinder(int a, int b, int c, int d)
{
    return ClipCollisionFinderCallBack(a, b, c, d, func_40074EA8, 0);
}

typedef struct
{
    int a, b;
} Flags;

extern int charrootdyn_slidecollisionCB(void *, void *, void *, void *, void *, void *, void *, Flags *);
extern int charrootdyn_slideExceptionJudgeCB();

int charrootdyn_slidecollision(void *a, void *b, void *c, void *d, void *e, void *f, char *o)
{
    Flags fl;

    if (o != 0)
    {
        fl.a = (*(unsigned int *)(o + 0x68) >> 11) & 1;
        fl.b = (*(unsigned int *)(o + 0x68) >> 15) & 1;
        return charrootdyn_slidecollisionCB(a, b, c, d, e, f, charrootdyn_slideExceptionJudgeCB, &fl);
    }
    return charrootdyn_slidecollisionCB(a, b, c, d, e, f, o, 0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0080_ResetCharacterClassPositionMemoryInfo", charrootdyn_getCollisionDBwithFunc);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0080_ResetCharacterClassPositionMemoryInfo", charrootdyn_getInterpVector);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0080_ResetCharacterClassPositionMemoryInfo", charrootdyn_getInterpPoint);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0080_ResetCharacterClassPositionMemoryInfo", charrootdyn_getGPPlaneInfo);

void charrootdyn_getUpperEdgeEffectiveHeight(void *arg0)
{
    (*(int *)((char *)(arg0) + 0x98)) = 0;
}

int charrootdyn_detectCharClimbableWall(int a, int b, int c, int d, int e, float x0, float x1, float y2, float y3, int f)
{
    int r;
    int n;

    *(float *)(a + 0x38) = x1;
    *(float *)(a + 0x3C) = x0;
    *(int *)(a + 0x20) = 0;
    *(int *)(a + 0x80) = 0;
    *(int *)(a + 0x8C) = 0;
    r = func_4006ADC0(a, b, c, d, e, y2, y3, f);
    if (r == 0) {
        n = func_4006B2A8(b, f);
        if (n != 0) {
            r = func_4006ADC0(a, n, c, d, e, y2, y3, f);
        }
    }
    return r;
}

int charrootdyn_detectCharClimbableWallContinue(int a, int b, int c, int d, int e, float y2, float y3, int f)
{
    int r = func_4006ADC0(a, b, c, d, e, y2, y3, f);
    int n;

    if (r == 0) {
        n = func_4006B2A8(b, f);
        if (n != 0) {
            r = func_4006ADC0(a, n, c, d, e, y2, y3, f);
        }
    }
    return r;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0080_ResetCharacterClassPositionMemoryInfo", charrootdyn_checkZplane);

void charrootdyn_setHColFindStatus(float y, char *c, void *g)
{
    char *l = GetLayoutClass(GetGeometryPointerObject(g));

    if (*(int *)(c + 0xED0) != 0) {
        *(int *)(c + 0xED0) = 0;
        DeleteTwoWayLink(c + 0xF20);
    }
    AddTwoWayLinkNext((int *)(l + 0x118), (int *)(c + 0xF20));
    *(float *)(c + 0xED4) = y;
    *(int *)(c + 0xED0) = 1;
    CopyGeometryPointer(c + 0xEE0, g);
}

typedef union
{
    s128 q;
    float f[4];
    int i[4];
} Vec4;

int charrootdyn_getLandingSurface(void *f, void *a, void *b, Vec4 *pos, float y)
{
    Vec4 t;

    t.q = pos->q;
    t.f[1] += y;
    return ClipCollisionFinderCallBack(f, b, &t, a, charrootdyn_slideExceptionJudgeCB, 0) != 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0080_ResetCharacterClassPositionMemoryInfo", charrootdyn_slideExceptionJudgeCB);

int *charrootdyn_getSlideCollisionJudgeCBArg(int *out, char *p, int flag)
{
    out[0] = ((*(unsigned int *)(p + 0x68) >> 11) & 1) ? flag != 0 : 0;
    out[1] = (*(unsigned int *)(p + 0x68) >> 15) & 1;
    return out;
}

int charrootdyn_checkUnderWater(float y, Vec4 *out, Vec4 *obj, void *x, void *list)
{
    Vec4 p1;
    ColHit h1;
    ColHit h2;
    Vec4 p2;

    p1.q = obj->q;
    p1.f[1] += y;
    if (CheckUnderVariableXZSurface(&h1, obj, &p1, x) == 0) {
        return 0;
    }
    p2.q = obj->q;
    p2.f[1] += y;
    if (ClipCollisionFinderCallBack(&h2, obj, &p2, list, charrootdyn_slideExceptionJudgeCB, 0) != 0
        && h2.v.f[1] > h1.v.f[1]) {
        return 0;
    }
    out->q = h1.v.q;
    return 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0080_ResetCharacterClassPositionMemoryInfo", charrootdyn_getWaterStatus);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0080_ResetCharacterClassPositionMemoryInfo", charrootdyn_addSlideElement);

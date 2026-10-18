#include "common.h"

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0080_ResetCharacterClassPositionMemoryInfo", ResetCharacterClassPositionMemoryInfo);

extern void DeleteTwoWayLink(void *);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0080_ResetCharacterClassPositionMemoryInfo", charrootdyn_detectCharClimbableWall);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0080_ResetCharacterClassPositionMemoryInfo", charrootdyn_detectCharClimbableWallContinue);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0080_ResetCharacterClassPositionMemoryInfo", charrootdyn_checkZplane);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0080_ResetCharacterClassPositionMemoryInfo", charrootdyn_setHColFindStatus);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0080_ResetCharacterClassPositionMemoryInfo", charrootdyn_checkUnderWater);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0080_ResetCharacterClassPositionMemoryInfo", charrootdyn_getWaterStatus);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0080_ResetCharacterClassPositionMemoryInfo", charrootdyn_addSlideElement);

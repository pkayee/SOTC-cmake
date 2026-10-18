#include "common.h"

typedef struct {
    s8 *data;
    s32 *point;
    s32 *line;
    s32 *root;
    s32 f10;
    s32 f14;
    s8 pad[0xC];
} PathE;

typedef struct {
    PathE e[4];
    s32 n;
    s32 pad;
} PathSet;

u8* getPathInfo(u8* work);
extern s8 *getPointData(s32 *, s32);
extern void resetPassageWork(char *);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", pathJudgeFunc);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", addPassageInsertPos);

int forceSetWayFinish(char *p)
{
    int s;
    if (*(int *)(p + 0x39C) == 0) {
        s = *(int *)(p + 0x380);
        if (s == 1) {
            resetPassageWork(p);
            *(int *)(p + 0x3E8) = s;
            return 1;
        }
    }
    return 0;
}

s8 *getPointDataFromEvent(s8 *w, s32 id, s32 *idx)
{
    PathSet *s = (PathSet *)getPathInfo(w);
    s32 i;
    u32 j;

    if (idx != 0) {
        *idx = -1;
    }
    for (i = 0; i < s->n; i++) {
        s32 *arr = s->e[i].point;

        if (arr == 0) {
            continue;
        }
        for (j = 0; j < *arr; j++) {
            s8 *p = getPointData(arr, j);

            if (p != 0 && id == *(s16 *)(p + 0x1C)) {
                if (idx != 0) {
                    *idx = j;
                }
                return p;
            }
        }
    }
    return 0;
}

static inline s8 *findPoint(u8 *w, s32 id)
{
    PathSet *s = (PathSet *)getPathInfo(w);
    s32 i;
    u32 j;

    for (i = 0; i < s->n; i++) {
        s32 *arr = s->e[i].point;

        if (arr == 0) {
            continue;
        }
        for (j = 0; j < *arr; j++) {
            s8 *p = getPointData(arr, j);

            if (p != 0 && id == *(s16 *)(p + 0x1C)) {
                return p;
            }
        }
    }
    return 0;
}

s32 getPointPosFromEvent(u8 *w, s32 id, s128 *out)
{
    s8 *p = findPoint(w, id);

    if (p != 0) {
        *out = *(s128 *)p;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", getRootPointIdxForGroupID);

extern PathSet D_4021DF58[];
extern s32 getRootPointData(s32, s32);
extern s32 getGoalPointData(s32, s32);
extern s32 getSubPointData(s32, s32);
extern s32 getChildGoalPointIdxArray(s32, s32);
extern s32 getChildSubPointIdxArray(s32, s32);

static inline PathE *getPathDataAddr(s8 *w, s32 id)
{
    PathSet *s = &D_4021DF58[*(s32 *)(w + 0x3C30)];
    s32 i;

    for (i = 0; i < s->n; i++) {
        if (id == *(s32 *)(s->e[i].data + 0x1C)) {
            return &s->e[i];
        }
    }
    return 0;
}

s32 getRootPointDataByAreaIdx(s8 *w, s32 b, s32 area)
{
    PathE *e = getPathDataAddr(w, area);

    if (e != 0) {
        return getRootPointData(*(s32 *)((s8 *)e + 0xC), b);
    }
    return 0;
}

s32 getGoalPointDataByAreaIdx(s8 *w, s32 b, s32 area)
{
    PathE *e = getPathDataAddr(w, area);

    if (e != 0) {
        return getGoalPointData(*(s32 *)((s8 *)e + 0x10), b);
    }
    return 0;
}

s32 getSubPointDataByAreaIdx(s8 *w, s32 b, s32 area)
{
    PathE *e = getPathDataAddr(w, area);

    if (e != 0) {
        return getSubPointData(*(s32 *)((s8 *)e + 0x14), b);
    }
    return 0;
}

s32 getChildGoalPointIdxArrayByAreaIdx(s8 *w, s32 b, s32 area)
{
    PathE *e = getPathDataAddr(w, area);

    if (e != 0) {
        return getChildGoalPointIdxArray(*(s32 *)((s8 *)e + 0xC), b);
    }
    return 0;
}

s32 getChildSubPointIdxArrayByAreaIdx(s8 *w, s32 b, s32 area)
{
    PathE *e = getPathDataAddr(w, area);

    if (e != 0) {
        return getChildSubPointIdxArray(*(s32 *)((s8 *)e + 0x10), b);
    }
    return 0;
}

extern u8 gcGlobalVar[];

void *getColiGroupByUserPathWork(char *w)
{
    s32 v = *(s32 *)(w + 0x3C30);

    if (v == 0) {
        return gcGlobalVar + 0x238;
    }
    if (v == 1) {
        return gcGlobalVar + 0x234;
    }
    return 0;
}

/* NEARMISS-STUB func_40101AD8 */
#if 0 /* NEARMISS 55.5% cat=sched sub=- | lq/store order reshuffled; ret in a7 not v0; flag in v0 not v1 | attempts=1 */
s32 func_40101AD8(char *p, s32 a1, u32 a2, u128 *a3, s32 a4)
{
    s32 ret = 0;
    u32 n = *(u32 *)(p + 0x380);

    if (n < 0x13) {
        char *e;
        u128 q;
        if ((s32)n < 0x14) {
            e = p + n * 0x20 + 0x100;
        } else {
            e = 0;
        }
        q = *a3;
        *(u16 *)(e + 0x1A) = 1;
        ret = 1;
        *(u128 *)e = q;
        *(u16 *)(e + 0x14) = a1;
        *(u32 *)(e + 0x1C) = a2;
        *(u16 *)(e + 0x16) = a4;
        *(u32 *)(e + 0x10) = 0;
        *(u16 *)(e + 0x18) = 0;
        *(u32 *)(p + 0x380) = *(u32 *)(p + 0x380) + 1;
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40101AD8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40101B40);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40101C30);
void func_40101C30(char *p)
{
    s128 v = *(s128 *)p;

    *(s32 *)(p + 0x40) = -1;
    *(s128 *)(p + 0x30) = v;
    *(s128 *)(p + 0x50) = v;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40101C48);

/* NEARMISS-STUB func_40101E70 */
#if 0 /* NEARMISS 55.5% cat=sched sub=- | store order: ee-gcc reorders sh/sw/sq stores vs target; ret addiu placement | attempts=1 */
s32 func_40101E70(s8 *w, s32 a1, s32 a2, u128 *a3, s32 a4, s32 idx)
{
    s8 *e;
    u128 q;

    if (idx < 0x14) {
        e = w + idx * 0x20 + 0x100;
        q = *a3;
        *(s16 *)(e + 0x14) = a1;
        *(s32 *)(e + 0x1C) = a2;
        *(s16 *)(e + 0x16) = a4;
        *(s16 *)(e + 0x18) = 0;
        *(s16 *)(e + 0x1A) = 1;
        *(u128 *)e = q;
        *(s32 *)(e + 0x10) = 0;
        return 1;
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40101E70);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40101EB8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40101F40);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40101FC8);

extern f32 CalcDistancePointAnd2Point();

s32 func_40101FC8(f32 a0)
{
    f32 r = CalcDistancePointAnd2Point();

    if (0.0f <= r && r <= a0)
    {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40102010);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_401020D8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40102198);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40102228);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_401026D0);
s32 ClipCollisionDirectCallBack();

s32 func_401026D0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    s32 r = 0;

    if (a3 != 0) {
        r = ClipCollisionDirectCallBack(a0, a1, a2, a3, 0, 0, 0, a4, 0);
    }
    return r;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40102708);
extern s32 widePathCollisionDirect(f32, s32, s32, s32, s32, s32, s32);

s32 func_40102708(s8 *w, s32 a1, s32 a2)
{
    return widePathCollisionDirect(*(f32 *)(w + 0x3C1C), (s32)w, a1, a2, *(s32 *)(w + 0x3C20), *(s32 *)(w + 0xF0), 0);
}

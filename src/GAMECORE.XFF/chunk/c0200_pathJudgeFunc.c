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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40101AD8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40101B40);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40101C30);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40101C48);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40101E70);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40101EB8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40101F40);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40101FC8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40102010);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_401020D8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40102198);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40102228);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_401026D0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40102708);

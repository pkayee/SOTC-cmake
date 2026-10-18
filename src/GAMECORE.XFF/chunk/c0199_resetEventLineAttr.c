#include "common.h"

u8* getLineData();
u8* getPathInfo(u8* work);

extern int ZeroVector[];
extern int chkAttainExecOffsetData(int, int, int, int *, int, float);

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

extern PathSet D_4021DF58[];

void resetEventLineAttr(u8* w, s32 id)
{
    PathSet *s = (PathSet *)getPathInfo(w);
    s32 i;
    u32 j;

    for (i = 0; i < s->n; i++)
    {
        s32 *arr = s->e[i].line;

        if (arr == 0)
        {
            continue;
        }
        for (j = 0; j < *arr; j++)
        {
            u8* l = getLineData(arr, j);

            if (id == *(s16*)(l + 0x10) || id == *(s16*)(l + 0x12))
            {
                *(s32*)(l + 8) = *(s32*)(l + 4);
            }
        }
    }
}

void allResetLineAttr(u8* w)
{
    PathSet *s = (PathSet *)getPathInfo(w);
    s32 i;
    u32 j;

    for (i = 0; i < s->n; i++)
    {
        s32 *arr = s->e[i].line;

        if (arr == 0)
        {
            continue;
        }
        for (j = 0; j < *arr; j++)
        {
            u8* l = getLineData(arr, j);

            *(s32*)(l + 8) = *(s32*)(l + 4);
            *(u16*)(l + 0xE) = *(u16*)(l + 0xC);
        }
    }
}

void setEventLinePrio(u8* w, s32 id, s32 prio)
{
    PathSet *s = (PathSet *)getPathInfo(w);
    s32 i;
    u32 j;

    for (i = 0; i < s->n; i++)
    {
        s32 *arr = s->e[i].line;

        if (arr == 0)
        {
            continue;
        }
        for (j = 0; j < *arr; j++)
        {
            u8* l = getLineData(arr, j);

            if (id == *(s16*)(l + 0x10) || id == *(s16*)(l + 0x12))
            {
                *(s16*)(l + 0xE) = prio;
            }
        }
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0199_resetEventLineAttr", setEventLineDir);

int chkAttainExecLayout(int a, int b, int c, int d)
{
    return chkAttainExecOffsetData(a, b, c, ZeroVector, d, 0.0f);
}

int chkAttainExecOffsetRadius(int a, int b, int c, int d)
{
    return ((int (*)(int, int, int, int *, int))chkAttainExecOffsetData)(a, b, c, ZeroVector, d);
}

int chkAttainExecOffsetPos(int a, int b, int c, int d)
{
    return ((int (*)(int, int, int, int, float))chkAttainExecOffsetData)(a, b, c, d, 0.0f);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0199_resetEventLineAttr", chkAttainExecColumn);

void resetPassageWork(u8* w)
{
    *(s32*)(w + 0x380) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0199_resetEventLineAttr", pathDetectCollision);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0199_resetEventLineAttr", pathDetectCollision2);

PathE *getPathDataAddr(u8* w, s32 id)
{
    PathSet *s = &D_4021DF58[*(s32*)(w + 0x3C30)];
    s32 i;

    for (i = 0; i < s->n; i++)
    {
        if (id == *(s32*)(s->e[i].data + 0x1C))
        {
            return &s->e[i];
        }
    }
    return 0;
}

static inline PathE *getPathDataAddrByArea(u8* w, s32 id)
{
    PathSet *s = &D_4021DF58[*(s32*)(w + 0x3C30)];
    s32 i;

    for (i = 0; i < s->n; i++)
    {
        if (id == *(s32*)(s->e[i].data + 0x1C))
        {
            return &s->e[i];
        }
    }
    return 0;
}

u8* getLineDataByAreaIdx(u8* w, s32 b, s32 area)
{
    PathE *e = getPathDataAddrByArea(w, area);

    if (e != 0)
    {
        return getLineData(*(s32*)((u8*)e + 0x8), b);
    }
    return 0;
}

extern s32 getPointData(s32, s32);

s32 getPointDataByAreaIdx(u8* w, s32 b, s32 area)
{
    PathE *e = getPathDataAddrByArea(w, area);

    if (e != 0)
    {
        return getPointData(*(s32*)((u8*)e + 0x4), b);
    }
    return 0;
}

extern s32 getConnectLineArray(s32, s32);

s32 getConnectLineArrayByAreaIdx(u8* w, s32 b, s32 area)
{
    PathE *e = getPathDataAddrByArea(w, area);

    if (e != 0)
    {
        return getConnectLineArray(*(s32*)((u8*)e + 0x4), b);
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0199_resetEventLineAttr", getConnectPointData);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0199_resetEventLineAttr", getNearPoint);

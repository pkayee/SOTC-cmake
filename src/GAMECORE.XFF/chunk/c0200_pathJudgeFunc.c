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

/* addPassageInsertPos: GAMECORE c0200 shifts the passage entries (32 byte, w+0x100) up by one and tail-calls func_40101E70 to fill slot 0 */
typedef struct { s32 q[8]; } __attribute__((aligned(8))) PassCopy;
extern s32 func_40101E70();

/* func_40101EB8: GAMECORE c0200 path judge glue; collision probe via func_40102708 then distance test via func_40101FC8 (tail call with 4 args, needs _prelude_patch.py) */
extern s32 func_40102708(s8 *w, s32 a1, s32 a2);
extern s32 func_40101FC8(f32 d, s32 a, s32 b, s32 c);

/* func_40101F40: GAMECORE c0200 sibling of func_40101EB8 with the first two int args of func_40101FC8 swapped (needs _prelude_patch.py) */
extern s32 func_40102708(s8 *w, s32 a1, s32 a2);

/* func_40102010: GAMECORE c0200 line data by area; both endpoint points must exist, then distance test (needs _prelude_patch.py for func_40101FC8) */
extern s32 func_40101FC8(f32 d, s32 a, s32 b, s32 c);
extern s16 *getLineDataByAreaIdx();
extern s32 getPointDataByAreaIdx();

/* func_401020D8: GAMECORE c0200 walks the D_40218B58 link table (24-byte entries, +4 area +6 next +8 idx) from the index func_40102198 returns until next==self; 1 if a line longer than 0x80 is found */
typedef struct {
    s32 f0;
    s16 f4;
    s16 f6;
    s16 f8;
    s8 pad[0xE];
} PassLink;
extern PassLink D_40218B58[];
extern s32 func_40102198();

/* pathJudgeFunc: collision attribute filter, sibling of arrowFilter (c0045); surface pointer passes straight through to GetCollisionDBAttributeAdr */
extern unsigned long *GetCollisionDBAttributeAdr();

int pathJudgeFunc(void *surface)
{
    unsigned long attribute = *GetCollisionDBAttributeAdr(surface);
    unsigned long flags = attribute & (0xF800UL << 20);
    unsigned long mode = attribute & (0xF000UL << 30);
    unsigned long material = attribute & 0x7C000000UL;

    if (flags == (0x8000UL << 18) || material == 0x7C000000UL) {
        return 1;
    }
    if (material == 0x04000000UL || material == 0x64000000UL || material == 0x68000000UL ||
        material == 0x6C000000UL)
    {
        return 0;
    }
    if (material == 0x24000000UL || flags == (0xC000UL << 18) || flags == (0xA000UL << 19) ||
        flags == (0xB800UL << 20) || flags == (0xA000UL << 18) || flags == (0xE000UL << 18) ||
        mode == (0x8000UL << 28))
    {
        return 0;
    }
    return 1;
}

s32 addPassageInsertPos(char *w, s128 *pos)
{
    s32 n0 = *(s32 *)(w + 0x380);

    if (*(s32 *)(w + 0x39C) != 0) {
        return 0;
    }
    {
        s32 n = n0;
        s32 cnt = n;
        PassCopy *p;
        u32 m;

        if (n == 0x14) {
            cnt = n - 1;
        }
        if (cnt > 0) {
            s32 k = cnt;
            p = (PassCopy *)(w + 0x100);
            do {
                k--;
                p[1] = p[0];
                p++;
            } while (k != 0);
        }
        m = *(u32 *)(w + 0x380);
        if (m < 0x14) {
            *(s32 *)(w + 0x380) = m + 1;
        }
        return func_40101E70(w, -1, -1, pos, -1, 0);
    }
}

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

s32 func_40101EB8(s8 *w, s32 a1, s32 a2, f32 *a3, s32 a4)
{
    if (func_40102708((s8 *)a4, (s32)w, a2) == 0) {
        return func_40101FC8(a3[5], a2, (s32)w, a1);
    }
    return 0;
}

s32 func_40101F40(s8 *w, s32 a1, s32 a2, f32 *a3, s32 a4)
{
    if (func_40102708((s8 *)a4, (s32)w, a2) == 0) {
        return func_40101FC8(a3[5], (s32)w, a2, a1);
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0200_pathJudgeFunc", func_40101FC8);

extern f32 CalcDistancePointAnd2Point();

s32 func_40101FC8(f32 a0, s32 a1, s32 a2, s32 a3)
{
    f32 r = CalcDistancePointAnd2Point();

    if (0.0f <= r && r <= a0)
    {
        return 1;
    }
    return 0;
}

s32 func_40102010(s8 *w, s32 a1, s32 a2, s32 a3)
{
    s16 *line = getLineDataByAreaIdx(w, a2, a3);

    if (line != 0) {
        s32 p0 = getPointDataByAreaIdx(w, line[0], a3);
        s32 p1 = getPointDataByAreaIdx(w, line[1], a3);

        if (p0 != 0 && p1 != 0) {
            return func_40101FC8(*(f32 *)((s8 *)line + 0x14), a1, p0, p1);
        }
    }
    return 0;
}

s32 func_401020D8(s8 *w, s32 a1, s32 a2, s32 a3, s32 a4)
{
    PassLink *tbl = D_40218B58;
    s32 cur = func_40102198(w, a3, a4);

    while (cur != tbl[cur].f6) {
        u16 *line = (u16 *)getLineDataByAreaIdx(w, tbl[cur].f8, tbl[cur].f4);

        if (line != 0 && line[7] > 0x80) {
            return 1;
        }
        cur = tbl[cur].f6;
    }
    return 0;
}

/* func_40102198: GAMECORE c0200 sums the point counts of path entries before the one whose data+0x1C equals area; a1 is the base offset (D_4021DF58 PathSet array already declared in the TU) */
s32 func_40102198(s8 *w, s32 a1, s32 a2)
{
    PathSet *s = &D_4021DF58[*(s32 *)(w + 0x3C30)];
    s32 i;
    s32 sum = 0;

    if (a1 >= 0 && a2 >= 0) {
        for (i = 0; i < s->n; i++) {
            if (a2 == *(s32 *)(s->e[i].data + 0x1C)) {
                return sum + a1;
            }
            if (s->e[i].point != 0) {
                sum += *s->e[i].point;
            }
        }
    }
    return -1;
}

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

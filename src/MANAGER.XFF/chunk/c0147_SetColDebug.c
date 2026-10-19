#include "common.h"

extern s32 D_4012B338;

extern u8 *GetLayoutClass();
typedef struct {
    u8 pad0[8];
    u8 flag8;
    u8 pad9[0xB];
    u8 *tbl14;
    u8 pad18[0x3C];
    s32 *ref54;
    u8 pad58[0x38];
} ColChunk;
typedef struct {
    u8 pad0[4];
    s32 mode4;
    ColChunk *chunks;
    u8 pad0c[0xC];
    u8 *ents18;
    u8 pad1c[0x4];
    u8 *obj20;
    u8 pad24[0x10];
    u8 *attr34;
} ColSet;

extern s128 YUnitVector;
extern void *iosMallocAlign(void *, s32, s32);

extern s32 func_400AB528();
extern s32 func_400AECA0(void *, void *, void *, void *, void *, f32);
extern s32 func_400AF438(void *, void *, void *, void *, void *, f32);
typedef union { s128 q; s32 w[4]; } Q4;

void SetColDebug(int arg0)
{
    D_4012B338 = arg0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BBDE8);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BBE40);

extern u64 *GetCollisionDBAttributeAdr();

s32 func_400BBE40(void)
{
    u64 *temp_v0;

    temp_v0 = GetCollisionDBAttributeAdr();
    return (*temp_v0 & 0xF80000000) != 0x280000000;
}

u32 func_400BBE80(s32 *ref)
{
    u32 w;
    u32 chunk;
    u32 id;
    ColSet *cs;
    ColChunk *c;
    u32 x;

    w = ref[1];
    chunk = (w >> 24) & 0x7F;
    id = w & 0xFFFFFF;
    cs = *(ColSet **)(*(u8 **)(GetLayoutClass(ref[0]) + 0x184) + 0x20);
    if (ref[1] < 0) {
        c = &cs->chunks[chunk];
        if (c->flag8 != 0) {
            x = *(u16 *)(c->tbl14 + id * 20);
        } else {
            x = *(u32 *)(c->tbl14 + id * 52 + 0x30);
        }
        return x;
    }
    return *(u32 *)(*(s32 *)(cs->chunks[chunk].ref54 + id) * 64 + cs->ents18 + 0x3C);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BBF70);
s32 func_400BBF70(f32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 *arg4)
{
    return *arg4 <= arg0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BBF90);
s32 func_400BBF90(s32 arg0, s32 arg1)
{
    return arg0 != arg1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BBFA0);

u8 *GetCollisionDBNextSurfLinkComp(s32 *ref)
{
    u32 w;
    u32 chunk;
    u32 id;
    ColSet *cs;
    ColChunk *c;

    w = ref[1];
    chunk = (w >> 24) & 0x7F;
    id = w & 0xFFFFFF;
    cs = *(ColSet **)(*(u8 **)(GetLayoutClass(ref[0]) + 0x184) + 0x20);
    c = &cs->chunks[chunk];
    return c->tbl14 + id * 20 + 8;
}

u8 *GetCollisionDBNextSurfLink(s32 *ref)
{
    u32 w;
    u32 chunk;
    u32 id;
    ColSet *cs;

    w = ref[1];
    chunk = (w >> 24) & 0x7F;
    id = w & 0xFFFFFF;
    cs = *(ColSet **)(*(u8 **)(GetLayoutClass(ref[0]) + 0x184) + 0x20);
    if (ref[1] < 0)
    {
        ColChunk *c = &cs->chunks[chunk];
        return c->tbl14 + id * 52 + 0xC;
    }
    return cs->ents18 + *(s32 *)(cs->chunks[chunk].ref54 + id) * 64 + 0x18;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", MakeCollisionPointCollisionInfo);

void MakeGeometryPointerGlobalInfo(void *arg0)
{
    (*(int *)((char *)(arg0) + 0x30)) = 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", GetSTPositionOfCollisionDB);

void MakeCollisionPointGlobalInfo(char *p, s128 *v)
{
    *(s128 *)(p + 0x40) = *v;
    *(int *)(p + 0x30) = 0;
}

s32 func_400BC558(void *a, void *b, void *c, void *d, void *e, f32 f)
{
    Q4 w[2];
    s32 r;
    s32 res;

    func_400AB528(&w[0], e, c, 1);
    w[1].q = ((Q4 *)d)->q;
    r = func_400AECA0(a, b, &w[0], &w[1], e, f);
    res = 0;
    if (r == 1) {
        w[1].q = ((Q4 *)((u8 *)a + 0x40))->q;
        res = 1;
    }
    if (r == 0) {
        if (func_400AF438(a, b, &w[0], &w[1], e, f)) {
            res = 1;
        }
    }
    return res;
}

s32 func_400BC638(void *a, void *b, void *c, void *d, void *e, f32 f)
{
    Q4 v;
    s32 r;
    s32 res;

    v.q = ((Q4 *)d)->q;
    r = func_400AECA0(a, b, c, &v, e, f);
    res = 0;
    if (r == 1) {
        v.q = ((Q4 *)((u8 *)a + 0x40))->q;
        res = 1;
    }
    if (r == 0) {
        if (func_400AF438(a, b, c, &v, e, f)) {
            res = 1;
        }
    }
    return res;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", GetCollisionDynamicsProjectionFloatPosition);

extern void RelocateCollisionWork(void *, s32);

void func_400BC778(void *arg0, void *arg1)
{
    RelocateCollisionWork(arg1, *(s32 *)((char *)(*(s32 *)((char *)(arg0) + 0x184)) + 0x20));
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", func_400BC798);
void func_400BC798(u8* work)
{
    *(s32*)work = 0;
}

int objfilter(int arg0, int arg1)
{
    return arg0 != arg1;
}

void FlushCollisionEdgeLinkDBVWallFinder(void *arg0)
{
    (*(int *)((char *)(arg0) + 0x20)) = 0;
}

int GetCollisionEdgeLinkDBWorkSize(int arg0)
{
    if (arg0 != 0) {
        return (arg0 * 0x14) + 0x96;
    }
    return 0;
}

void *InitCollisionEdgeLinkDB(void *arg0, s32 arg1)
{
    u8 *p;
    void *q;

    if (arg1 != 0) {
        p = iosMallocAlign(arg0, 0x30, 4);
        q = iosMallocAlign(arg0, arg1 * 0x14, 4);
        *(s32 *)(p + 0x14) = -1;
        *(s32 *)(p + 0x18) = 0;
        *(s32 *)(p + 0x1C) = 0;
        *(u8 *)(p + 0x12) = 0;
        *(s128 *)p = YUnitVector;
        *(s32 *)(p + 0x20) = 0;
        *(void **)(p + 0x24) = q;
        *(s32 *)(p + 0x10) = arg1;
        return p;
    }
    return NULL;
}

void iosFree(void *);

void ReleaseCollisionEdgeLinkDB(void **arg0)
{
    void *temp_s0;

    temp_s0 = *arg0;
    if (temp_s0 != NULL) {
        iosFree((*(void **)((char *)(temp_s0) + 0x24)));
        iosFree(temp_s0);
        *arg0 = NULL;
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0147_SetColDebug", GetCollisionEdgeLinkDBVWallFinder);

#include "common.h"

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", DebugDispQuaternion);

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", GetGlDebugSw);
extern s32 D_4001E060;

s32 *GetGlDebugSw(void)
{
    return &D_4001E060;
}

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", gluNewQuadric);
u64 gluNewQuadric()
{
    return 0;
}

void gluDeleteQuadric(void) {
}

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", gluCylinder);
void _gluCylinder(u64 a, u64 b);

void gluCylinder(u64 a, u64 b, u64 c)
{
    _gluCylinder(b, c);
}

extern void *iosReallocAlign(void *ptn, void *oldUser, s32 size, s32 align);
typedef union { f32 f[4]; u128 q; } GluV4;
typedef struct { void *pool; s32 b; s32 n; GluV4 *v; } GluObj;

void iosgluAddVertex4fv(GluObj *o, GluV4 *p)
{
    o->v = iosReallocAlign(o->pool, o->v, o->n * 16 + 16, 16);
    o->v[o->n].q = p->q;
    o->n++;
}

void iosgluAddVertex3f(f32 x, f32 y, f32 z, GluObj *o)
{
    GluV4 t;

    t.f[0] = x; t.f[1] = y; t.f[2] = z; t.f[3] = 1.0f;
    o->v = iosReallocAlign(o->pool, o->v, o->n * 16 + 16, 16);
    o->v[o->n].q = t.q;
    o->n++;
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", iosgluAddPrim);

typedef struct IosgluDefaultObj {
    s32 a;
    s32 b;
    s32 c;
} IosgluDefaultObj;

extern IosgluDefaultObj D_4001E078;
extern void *iosMallocAlign(s32, s32, s32);

IosgluDefaultObj *iosgluCreateObject(s32 param_1)
{
    IosgluDefaultObj *p;

    p = iosMallocAlign(param_1, 0xc, 4);
    *p = D_4001E078;
    p->a = param_1;
    return p;
}
//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", iosgluDeleteObject);
typedef struct IosgluEntry {
    s32 a;
    s32 b;
    s32 c;
    void *ptr;
} IosgluEntry;

typedef struct IosgluObj {
    s32 pad0;
    s32 count;
    IosgluEntry *entries;
} IosgluObj;

extern void iosFree(void *ptr);

void iosgluDeleteObject(IosgluObj *obj)
{
    s32 i;

    for (i = 0; i < obj->count; i++) {
        iosFree(obj->entries[i].ptr);
    }
    iosFree(obj->entries);
    iosFree(obj);
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", iosgluDrawObject);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", iosgluAddLineCircleObject);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", glDrawLineStrip);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", glDrawLineCircle);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", glDrawNull);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", glDrawLight);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", glDrawLineArrow);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", glDrawLineArrowPosition);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", glDrawBox);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", glDrawGLUObj);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", glDrawSpaceAxisQuaternion);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", glDrawViewFrustum);

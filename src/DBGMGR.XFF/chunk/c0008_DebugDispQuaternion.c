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

/* NEARMISS-STUB iosgluAddVertex4fv */
#if 0 /* NEARMISS 50.7% cat=cse-hoist sub=- | ours CSEs count load before sq; target reloads count after vector store; ptr store scheduled late | attempts=1 */
extern void *iosReallocAlign(void *ptn, void *oldUser, s32 size, s32 align);

void iosgluAddVertex4fv(u32 *param_1, u128 *param_2)
{
    param_1[3] = (u32)iosReallocAlign((void *)param_1[0], (void *)param_1[3], param_1[2] * 16 + 16, 16);
    *(u128 *)((u8 *)param_1[3] + param_1[2] * 16) = *param_2;
    param_1[2] = param_1[2] + 1;
}
#endif
INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", iosgluAddVertex4fv);

/* NEARMISS-STUB iosgluAddVertex3f */
#if 0 /* NEARMISS 75.3% cat=cse-hoist sub=- | ours CSEs param_4[2] count load across vector sq; target reloads count after sq; stores scheduled earlier | attempts=1 */
extern void *iosReallocAlign(void *ptn, void *oldUser, s32 size, s32 align);

void iosgluAddVertex3f(f32 x, f32 y, f32 z, u32 *param_4)
{
    f32 v[4] = { x, y, z, 1.0f };

    param_4[3] = (u32)iosReallocAlign((void *)param_4[0], (void *)param_4[3], param_4[2] * 16 + 16, 16);
    *(u128 *)((u8 *)param_4[3] + param_4[2] * 16) = *(u128 *)v;
    param_4[2] = param_4[2] + 1;
}
#endif
INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", iosgluAddVertex3f);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", iosgluAddPrim);

/* NEARMISS-STUB iosgluCreateObject */
#if 0 /* NEARMISS 82.38% cat=struct-layout sub=- | target copies struct via a0 with ptr moved to a0 before ld ra; ours keeps ptr in v0, ld ra late | attempts=1 */
typedef struct IosgluDefaultObj {
    s32 a;
    s32 b;
    s32 c;
} IosgluDefaultObj;

extern IosgluDefaultObj D_4001E078;
extern void *iosMallocAlign(s32, s32, s32);

void iosgluCreateObject(s32 param_1)
{
    IosgluDefaultObj *p;

    p = iosMallocAlign(param_1, 0xc, 4);
    *p = D_4001E078;
    p->a = param_1;
}
#endif
INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", iosgluCreateObject);
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

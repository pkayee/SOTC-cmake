#include "common.h"

extern void func_400BBDE8();
extern s32 *isysGroupForFirst(void *group, s32 a);
extern s32 *isysGroupForNext(s32 *it, s32 a);
extern void isysGroupForExit(s32 obj, s32 a);
extern void func_400A97C8(s32 *res, s32 obj, s32 p2, s32 p3, float f, float g, void *region, s32 w, s32 a8, s32 a9, s32 cbarg);

static inline void collisionDBQuery(s32 *res, void *group, float f, s32 p2, s32 p3, s32 (*cb)(s32, s32), s32 w, s32 a8, s32 a9, s32 cbarg)
{
    s32 *it;
    s32 obj = 0;
    u8 region[16];
    float r;

    r = 0.0f;
    func_400BBDE8(region, &r, p2, p3);
    for (it = isysGroupForFirst(group, 0); it != NULL && (obj = *it, res[0] < res[1]); it = isysGroupForNext(it, 0))
    {
        if (cb == NULL || cb(obj, cbarg) != 0)
        {
            func_400A97C8(res, obj, p2, p3, f, r, region, w, a8, a9, cbarg);
        }
    }
    if (obj != 0)
    {
        isysGroupForExit(obj, 0);
    }
}

void AddCollisionDBCallBack(s32 *res, void *group, float f, s32 p2, s32 p3, s32 (*cb)(s32, s32), s32 w, s32 a8, s32 a9, s32 cbarg)
{
    collisionDBQuery(res, group, f, p2, p3, cb, w, a8, a9, cbarg);
}

/* NEARMISS-STUB GetCollisionDB */
#if 0 /* NEARMISS 99.84% cat=sched sub=- | only the addiu a0,sp,16 / addiu a1,sp,32 order after the FlushCollisionFinder call (target a0 first); uses the shared collisionDBQuery static inline that matche | attempts=1 */
extern void FlushCollisionFinder(void);
extern s32 func_400BBF90(s32 obj, s32 arg);

void GetCollisionDB(s32 *res, void *group, s32 unused, s32 p2, s32 p3, float f)
{
    FlushCollisionFinder();
    collisionDBQuery(res, group, f, p2, p3, func_400BBF90, 0, 0, 0, 0);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0142_AddCollisionDBCallBack", GetCollisionDB);

extern s32 func_400BBF90(s32 obj, s32 arg);

void AddCollisionDB(s32 *res, void *group, s32 arg, s32 p2, s32 p3, float f)
{
    collisionDBQuery(res, group, f, p2, p3, func_400BBF90, 0, 0, 0, arg);
}

extern int func_400AB528();

int GetCollisionDBCurrentPointOnLastPlane(int a, int b, int c)
{
    return func_400AB528(a, b, c, 0);
}

extern u8 *GetLayoutClass(s32 id);
extern void func_400A7AE0(void *out, s32 a, u8 *cls, u32 grp, u32 idx);
extern void func_400A8F78(void *out, s32 a, u8 *verts, s32 n, s32 b, u8 *groups, s32 c, s32 d);

static inline void collisionDBModelVertex(void *out, u8 *sub, u8 *d, u32 grp, u32 idx)
{
    func_400A8F78(out, 0, *(u8 **)(sub + 0x20) + 0x28, *(s32 *)(*(u8 **)(sub + 0x20) + 0x24), *(s32 *)(sub + 8),
                  *(u8 **)(d + 8), *(s32 *)(d + 0x14),
                  *(s32 *)(d + 0x18) + (*(s32 **)(*(u8 **)(d + 8) + grp * 0x90 + 0x54))[idx] * 0x40);
}

void GetCollisionDBVertexPoint(void *out, s32 *ref)
{
    u32 idx = ref[1] & 0xFFFFFF;
    u32 grp = ((u32)ref[1] >> 24) & 0x7F;
    u8 *cls = GetLayoutClass(ref[0]);

    if (ref[1] < 0)
    {
        func_400A7AE0(out, 0, cls, grp, idx);
        return;
    }
    collisionDBModelVertex(out, cls + 0x154, *(u8 **)(*(u8 **)(cls + 0x184) + 0x20), grp, idx);
}


void GetCollisionDBRegion(void *db, float *out, float base)
{
    float t[4];

    func_400BBDE8(db, t);
    *out = base + t[0];
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0142_AddCollisionDBCallBack", GetCollisionDBPositionWithST);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0142_AddCollisionDBCallBack", GetCollisionDBPositionWithNodeLocalPos);

extern u128 *func_400AC180(void *out, u8 *cls, s32 node);

void GetCollisionDBQuaternion(u128 *out, s32 *ref)
{
    u32 idx = ref[1] & 0xFFFFFF;
    u32 grp = ((u32)ref[1] >> 24) & 0x7F;
    u8 *cls = GetLayoutClass(ref[0]);
    u8 *d;

    if (ref[1] < 0)
    {
        *out = (*(u128 **)(cls + 0x154))[grp];
        return;
    }
    d = *(u8 **)(*(u8 **)(cls + 0x184) + 0x20);
    func_400AC180(out, cls, (*(s32 **)(*(u8 **)(d + 8) + grp * 0x90 + 0x54))[idx]);
}

/* NEARMISS-STUB GetCollisionDBOriginQuatPos */
#if 0 /* NEARMISS 84.98% cat=sched sub=- | target loads cls+0x15C (matrix ptr) AFTER the out[0] sq and keeps grp*0x10 in v1 before the ref[1] reload; ours hoists the lw 348 above the sq; a CollLayoutQ st | attempts=1 */
void GetCollisionDBOriginQuatPos(u128 *out, s32 *ref)
{
    u32 idx = ref[1] & 0xFFFFFF;
    u32 grp = ((u32)ref[1] >> 24) & 0x7F;
    u8 *cls = GetLayoutClass(ref[0]);
    u8 *d;
    u128 pos;

    if (ref[1] < 0)
    {
        out[0] = (*(u128 **)(cls + 0x154))[grp];
        pos = (*(u128 **)(cls + 0x15C))[grp * 4 + 3];
    }
    else
    {
        d = *(u8 **)(*(u8 **)(cls + 0x184) + 0x20);
        pos = *func_400AC180(out, cls, (*(s32 **)(*(u8 **)(d + 8) + grp * 0x90 + 0x54))[idx]);
    }
    out[1] = pos;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0142_AddCollisionDBCallBack", GetCollisionDBOriginQuatPos);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0142_AddCollisionDBCallBack", GetCollisionDBVectorPlane);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0142_AddCollisionDBCallBack", GetCollisionDBPlane);

#include "common.h"

void CopyMultiMatrix();
void *dynamic_cast_to_camera_obj();
u8 *get_camera_obj_layout_class();
u8 *GetScriptLayoutClass();
u8 *GetLightClass();
s32 CheckClothChainExist();

#define LAYOUT_CLASS(c, obj)                                                 \
    switch ((obj)[8]) {                                                      \
    case 10:                                                                 \
        c = (obj) + 0x20;                                                    \
        break;                                                               \
    case 11:                                                                 \
        c = GetScriptLayoutClass(obj) + 0x70;                                \
        break;                                                               \
    case 17:                                                                 \
        c = get_camera_obj_layout_class(dynamic_cast_to_camera_obj(obj));    \
        break;                                                               \
    case 19:                                                                 \
        c = GetLightClass(obj);                                              \
        break;                                                               \
    case 9:                                                                  \
    case 13:                                                                 \
    case 22:                                                                 \
        c = (obj) + 0x90;                                                    \
        break;                                                               \
    default:                                                                 \
        c = NULL;                                                            \
        break;                                                               \
    }

void UpdateLayoutClassPastGeometry(u8 *a0)
{
    *(u128 *)*(u8 **)(a0 + 0x138) = *(u128 *)*(u8 **)(a0 + 0x134);
    *(u128 *)(a0 + 0xB0) = *(u128 *)(a0 + 0xA0);
    if (*(u8 *)(a0 + 0x1BC) & 0x20) {
        CopyMultiMatrix(*(u32 *)(a0 + 0x168), *(u32 *)(a0 + 0x164), *(s16 *)(a0 + 0x1B4));
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", SetLayoutObjAccessSwitchThisObjOnly);
void SetClothAccessSwitch();

u8 *SetLayoutObjAccessSwitchThisObjOnly(u8 *obj, s32 v)
{
    u8 *c;

    LAYOUT_CLASS(c, obj)
    if (c != NULL && *(s8 *)(c + 0x1B8) != v) {
        *(s8 *)(c + 0x1B8) = v;
        if (*(s32 *)(c + 0x180) != 0) {
            SetClothAccessSwitch(*(s32 *)(c + 0x178), v);
        }
        return c;
    }
    return NULL;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", GetLayoutClassWindGeometry);

/* NEARMISS-STUB SetLayoutClassScaleElem */
#if 0 /* NEARMISS 60.0% cat=float-ops sub=- | see attempt (kX15 haiku best) | attempts=1 */
extern u128 ZeroPoint;

void iosGetScaleInverseVector();

void SetLayoutClassScaleElem(u8 *a0, u128 *a1, s32 a2)
{
    f32 f;
    f32 y;
    f32 x;

    *(u128 *)(a0 + 0x90) = *a1;
    y = *(f32 *)(a0 + 0x94);
    x = *(f32 *)(a0 + 0x90);
    if (y < x) {
        f = x;
        if (!(*(f32 *)(a0 + 0x98) < f)) {
            f = *(f32 *)(a0 + 0x98);
        }
    } else {
        f = y;
        if (!(*(f32 *)(a0 + 0x98) < f)) {
            f = *(f32 *)(a0 + 0x98);
        }
    }
    *(f32 *)(a0 + 0x9C) = f;
    if (a2 != 0) {
        iosGetScaleInverseVector(a0 + 0xA0, a0 + 0x90);
        return;
    }
    *(u128 *)(a0 + 0xA0) = ZeroPoint;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", SetLayoutClassScaleElem);

s32 CheckLayoutObjChainExist(u8 *obj)
{
    u8 *c;

    LAYOUT_CLASS(c, obj)
    if (c != NULL) {
        return CheckClothChainExist(*(s32 *)(c + 0x178));
    }
    return 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", SetLayoutObjDebugResetFunc);
void SetLayoutObjDebugResetFunc(u8 *obj, s32 fn)
{
    u8 *c;

    LAYOUT_CLASS(c, obj)
    *(s32 *)(c + 0x14C) = fn;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", CallLayoutObjDebugResetFunc);
void CallLayoutObjDebugResetFunc(u8 *obj)
{
    u8 *c;
    void (*fn)(u8 *);

    LAYOUT_CLASS(c, obj)
    fn = *(void (**)(u8 *))(c + 0x14C);
    if (fn != NULL) {
        fn(obj);
    }
}

typedef union {
    s128 q;
    float f[4];
    int i[4];
} Vec4;

typedef struct {
    char pad0[0x2C];
    float radius;
} BoundaryData;

typedef struct {
    char pad0[0x20];
    BoundaryData *data;
} CollisionInfo;

typedef struct {
    char pad0[0x90];
    float scale;
    char pad94[0xA0];
    Vec4 *center;
    char pad138[0x4C];
    CollisionInfo *collision;
} LayoutClass;

typedef struct {
    Vec4 center;
} Boundary;

extern Vec4 ZeroVector;

int GetLayoutClassCollisionBoundaryInfo(Boundary *out, LayoutClass *layout)
{
    CollisionInfo *col = layout->collision;

    if (col != 0) {
        BoundaryData *bd = col->data;

        out->center.q = layout->center->q;
        out->center.f[3] = bd->radius * layout->scale;
        return 0;
    }
    out->center.q = ZeroVector.q;
    return -1;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", SetLayoutObjCollisionEnableFlag);
void SetLayoutObjCollisionEnableFlag(u8 *obj, s32 v)
{
    u8 *c;

    LAYOUT_CLASS(c, obj)
    if (*(s32 *)(c + 0x174) != 0) {
        *(s8 *)(c + 0x1BB) = v;
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", GetLayoutObjCollisionEnableFlag);
s8 GetLayoutObjCollisionEnableFlag(u8 *obj)
{
    u8 *c;

    LAYOUT_CLASS(c, obj)
    return *(s8 *)(c + 0x1BB);
}

void SetLayoutClassCollisionWorkAdr(u8 *layoutObj, void *work)
{
    *(void **)(layoutObj + 0x174) = work;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", ChangeLayoutObjCollisionResourceAttribute);
void ChangeCollisionResourceAttribute();

void ChangeLayoutObjCollisionResourceAttribute(u8 *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6)
{
    u8 *c;
    u8 *p;

    LAYOUT_CLASS(c, obj)
    p = *(u8 **)(c + 0x184);
    if (*(s32 *)(p + 0x20) != 0) {
        ChangeCollisionResourceAttribute(*(s32 *)(p + 0x20), a1, a2, a3, a4, a5, a6);
    }
}

s32 SaveLayoutObjGeo(u8 *obj)
{
    u8 *c;
    s32 ok;

    LAYOUT_CLASS(c, obj)
    if (c == NULL) {
        return -2;
    }
    ok = 0;
    if (*(s32 *)(c + 0x190) != 0) {
        (*(void (**)(s32))(c + 0x190))(*(s32 *)(c + 0x1A4));
        ok = 1;
    }
    return ok ? 0 : -1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", GetLayoutRootMatrix);

s64 GetGeometryPointerObject();

s64 GetLayoutParentObj(u8 *a0)
{
    if (*(s32 *)(a0 + 0x124) != 0) {
        return GetGeometryPointerObject(a0 + 0xC0);
    }
    return 0;
}

extern u16 D_4012B010;

u16 getSeqNo(void)
{
    return D_4012B010++;
}

/* NEARMISS-STUB func_400881C0 */
#if 0 /* NEARMISS 78.0% cat=regalloc sub=- | see attempt (kX15 haiku best) | attempts=1 */
s64 func_400881C0(u8 *a0)
{
    s32 v;

    v = *(s32 *)(a0 + 0x40);
    if (v != 0) {
        return 1;
    }
    v = *(s32 *)(a0 + 0x44);
    if (v != 0) {
        return 1;
    }
    v = *(s32 *)(a0 + 0x48);
    if (v == 0) {
        return 0;
    }
    return 1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", func_400881C0);

s64 GetClothWorkSize();

s64 GetAliasLayoutObjWorkSize(u8 *a0)
{
    s64 size = 0;
    u8 *sub = *(u8 **)(a0 + 0xC);

    if (sub != NULL) {
        size = GetClothWorkSize(*(u32 *)(*(u8 **)(sub + 0x8) + 0x20));
    }
    return size;
}

/* NEARMISS-STUB UpdateAliasLayoutObjClothGeometry */
#if 0 /* NEARMISS 83.2% cat=regalloc sub=- | 2nd LAYOUT_CLASS(alias) result kept in v0 not a1; src->0x19C re-tested as pointer; expected beqz (not beqzl) default-case and a0 caching of src->0x19C; C with c | attempts=1 */
extern u128 ZeroVector;

void UpdateAliasLayoutObjClothGeometry(u8 *obj)
{
    u8 *c;
    u8 *alias;
    u8 *src;

    LAYOUT_CLASS(c, obj)
    if (*(s32 *)(c + 0x180) != 0) {
        alias = *(u8 **)(c + 0x194);
        LAYOUT_CLASS(src, alias)
        if (*(s32 *)(src + 0x19C) != 0) {
            *(f32 *)(*(u8 **)(c + 0x19C) + 0x80) = *(f32 *)(*(u8 **)(src + 0x19C) + 0x80);
            *(f32 *)(*(u8 **)(c + 0x19C) + 0x84) = *(f32 *)(*(u8 **)(src + 0x19C) + 0x84);
            *(u128 *)(*(u8 **)(c + 0x19C) + 0x60) = *(u128 *)(*(u8 **)(src + 0x19C) + 0x60);
            *(u128 *)(*(u8 **)(c + 0x19C) + 0x70) = *(u128 *)(*(u8 **)(src + 0x19C) + 0x70);
        } else {
            *(s32 *)(*(u8 **)(c + 0x19C) + 0x80) = 0;
            *(s32 *)(*(u8 **)(c + 0x19C) + 0x84) = 0;
            *(u128 *)(*(u8 **)(c + 0x19C) + 0x60) = ZeroVector;
            *(u128 *)(*(u8 **)(c + 0x19C) + 0x70) = ZeroVector;
        }
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", UpdateAliasLayoutObjClothGeometry);

void func_400883B8(s32 *a0)
{
    *a0 = 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", func_400883C0);
extern f32 IdentityQuaternion[];
extern u128 ZeroPoint;

void SetGeometryPointerGlobalState();
void DeleteTwoWayLink();
u8 *GetLayoutClass();
u8 *GetSubLinkClass();
void isysRequestDeleteObj();

void func_400883C0(u8 *obj)
{
    u8 *c;
    u8 *o;

    LAYOUT_CLASS(c, obj)
    if (c != NULL) {
        o = GetLayoutClass(obj);
        if (*(s32 *)(o + 0x124) != 0) {
            *(u128 *)(o + 0x60) = *(u128 *)*(u8 **)(o + 0x13C);
            SetGeometryPointerGlobalState(o + 0xC0, IdentityQuaternion, &ZeroPoint);
            DeleteTwoWayLink(o + 0x100);
            *(s32 *)(o + 0x124) = 0;
        }
        return;
    }
    if (GetSubLinkClass(obj) == NULL) {
        return;
    }
    isysRequestDeleteObj(obj);
}

void isysRequestDeleteObj();

void func_400884D0(void)
{
    isysRequestDeleteObj();
}

void FlushLayoutObjImmediate();

void func_400884E8(void)
{
    FlushLayoutObjImmediate();
}

void FlushLayoutObj();

void func_40088500(void)
{
    FlushLayoutObj();
}

/* NEARMISS-STUB func_40088518 */
#if 0 /* NEARMISS 92.7% cat=regalloc sub=- | see attempt (kX15 haiku best) | attempts=1 */
typedef struct {
    u64 q[2];
} SprQuad;

typedef struct {
    s32 a[4];
    SprQuad blk;
    s32 b[4];
} SprArgs;

extern const SprQuad D_40132DB0;

void gsRegBegin(void);
void gsRegEnd(void);
void gsReg(s32, u64);
s32 getDrawScreenWidth(void);
s32 getDrawScreenHeight(void);
s32 getFrameBufferSizeFBP(void);
s32 getFrameBufferSizeTBP(void);
s32 getDrawBufferAddressFBP(void);
s32 getDrawBufferAddressTBP(void);
void spriteTexFast(s32, s32, s32, s32, s32, void *, void *, s32);

void func_40088518(void)
{
    SprArgs spr;
    s32 w;
    s32 h;
    s32 c800;
    s32 four;

    c800 = 0x800;
    four = 4;
    gsRegBegin();
    w = getDrawScreenWidth();
    h = getDrawScreenHeight();
    gsReg(0x4C, (u64)getFrameBufferSizeFBP() | 0x40000);
    gsReg(0x18, 0x0000780000007800ULL);
    gsReg(0x40, 0x00FF000000FF0000ULL);
    gsReg(0x4A, 0);
    gsReg(0x3B, 0x0000008000000080ULL);
    gsReg(0x47, 0x31001);
    gsReg(0x42, 0x44);
    gsReg(0x14, 0x60);
    spr.blk = D_40132DB0;
    spr.a[1] = -0x800;
    spr.a[3] = 0x1000;
    spr.a[0] = -0x800;
    spr.a[2] = 0x1000;
    spr.b[1] = four;
    spr.b[2] = w << 4;
    spr.b[3] = h << 4;
    spr.b[0] = four;
    gsReg(6, (u64)(getDrawBufferAddressTBP() | ((u64)(w / 64) << 14)) | ((u64)0xCC82 << 19));
    spriteTexFast(spr.a[0], spr.a[1], spr.a[2], spr.a[3], 0xFFFFFF, spr.b, &spr.blk, 0);
    gsReg(0x47, 0x5000D);
    gsReg(6, (u64)getFrameBufferSizeTBP() | 0x10000 | ((u64)0xC400 << 19));
    gsReg(0x4C, (u64)getDrawBufferAddressFBP() | ((u64)((w >> 6) & 0x3F) << 16));
    gsReg(0x18, ((u64)((c800 - w / 2) << 4)) | (((u64)((c800 - h / 2) << 4)) << 32));
    gsReg(0x40, ((u64)(w - 1) << 16) | ((u64)(h - 1) << 48));
    gsReg(0x08, 0x5);
    gsRegEnd();
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", func_40088518);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", func_40088758);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", func_40088918);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", func_40088AE0);

#include "common.h"

void CopyMultiMatrix();

void UpdateLayoutClassPastGeometry(u8 *a0)
{
    *(u128 *)*(u8 **)(a0 + 0x138) = *(u128 *)*(u8 **)(a0 + 0x134);
    *(u128 *)(a0 + 0xB0) = *(u128 *)(a0 + 0xA0);
    if (*(u8 *)(a0 + 0x1BC) & 0x20) {
        CopyMultiMatrix(*(u32 *)(a0 + 0x168), *(u32 *)(a0 + 0x164), *(s16 *)(a0 + 0x1B4));
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", SetLayoutObjAccessSwitchThisObjOnly);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", CheckLayoutObjChainExist);

/* NEARMISS-STUB SetLayoutObjDebugResetFunc */
#if 0 /* NEARMISS 89.0% cat=rodata-const sub=- | see attempt (kX15 haiku best) | attempts=1 */
s32 GetScriptLayoutClass();
s64 dynamic_cast_to_camera_obj();
s32 get_camera_obj_layout_class();
s32 GetLightClass();

void SetLayoutObjDebugResetFunc(u8 *a0, s32 a1)
{
    u8 *p;

    switch (a0[8]) {
    case 9:
    case 0xD:
    case 0x16:
        p = a0 + 0x90;
        break;
    case 10:
        p = a0 + 0x20;
        break;
    case 0xB:
        p = (u8 *)GetScriptLayoutClass() + 0x70;
        break;
    case 0x11:
        *(s32 *)((u8 *)get_camera_obj_layout_class(dynamic_cast_to_camera_obj()) + 0x14C) = a1;
        return;
    case 0x13:
        *(s32 *)((u8 *)GetLightClass() + 0x14C) = a1;
        return;
    default:
        p = NULL;
        break;
    }
    *(s32 *)(p + 0x14C) = a1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", SetLayoutObjDebugResetFunc);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", CallLayoutObjDebugResetFunc);

/* NEARMISS-STUB GetLayoutClassCollisionBoundaryInfo */
#if 0 /* NEARMISS 48.0% cat=regalloc sub=- | see attempt (kX15 haiku best) | attempts=1 */
extern u128 ZeroVector;

s32 GetLayoutClassCollisionBoundaryInfo(u8 *out, u8 *obj)
{
    u8 *dst = out;
    u8 *o = obj;

    if (*(s32 *)(o + 0x184) != 0) {
        *(u128 *)dst = *(u128 *)*(u8 **)(o + 0x134);
        *(f32 *)(dst + 0xC) = *(f32 *)(*(u8 **)(o + 0x184) + 0x2C) * *(f32 *)(o + 0x90);
        return 0;
    }
    *(u128 *)dst = ZeroVector;
    return -1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", GetLayoutClassCollisionBoundaryInfo);

/* NEARMISS-STUB SetLayoutObjCollisionEnableFlag */
#if 0 /* NEARMISS 79.0% cat=rodata-const sub=- | see attempt (kX15 haiku best) | attempts=1 */
s32 GetScriptLayoutClass();
s64 dynamic_cast_to_camera_obj();
s32 get_camera_obj_layout_class();
s32 GetLightClass();

void SetLayoutObjCollisionEnableFlag(u8 *a0, s32 a1)
{
    u8 *p;

    switch (a0[8]) {
    case 9:
    case 0xD:
    case 0x16:
        p = a0 + 0x90;
        break;
    case 10:
        p = a0 + 0x20;
        break;
    case 0xB:
        p = (u8 *)GetScriptLayoutClass() + 0x70;
        break;
    default:
        p = NULL;
        break;
    case 0x11:
        p = (u8 *)get_camera_obj_layout_class(dynamic_cast_to_camera_obj());
        break;
    case 0x13:
        p = (u8 *)GetLightClass();
        break;
    }
    if (*(s32 *)(p + 0x174) != 0) {
        *(s8 *)(p + 0x1BB) = a1;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", SetLayoutObjCollisionEnableFlag);

/* NEARMISS-STUB GetLayoutObjCollisionEnableFlag */
#if 0 /* NEARMISS 89.0% cat=rodata-const sub=- | see attempt (kX15 haiku best) | attempts=1 */
s32 GetScriptLayoutClass();
s64 dynamic_cast_to_camera_obj();
s32 get_camera_obj_layout_class();
s32 GetLightClass();

s32 GetLayoutObjCollisionEnableFlag(u8 *a0)
{
    u8 *p;

    switch (a0[8]) {
    case 9:
    case 0xD:
    case 0x16:
        p = a0 + 0x90;
        break;
    case 10:
        p = a0 + 0x20;
        break;
    case 0xB:
        p = (u8 *)GetScriptLayoutClass() + 0x70;
        break;
    case 0xC:
    case 0xE:
    case 0xF:
    case 0x10:
    case 0x12:
    case 0x14:
    case 0x15:
        p = NULL;
        break;
    case 0x11:
        return *(s8 *)((u8 *)get_camera_obj_layout_class(dynamic_cast_to_camera_obj()) + 0x1BB);
    case 0x13:
        return *(s8 *)((u8 *)GetLightClass() + 0x1BB);
    default:
        p = NULL;
        break;
    }
    return *(s8 *)(p + 0x1BB);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", GetLayoutObjCollisionEnableFlag);

void SetLayoutClassCollisionWorkAdr(u8 *layoutObj, void *work)
{
    *(void **)(layoutObj + 0x174) = work;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", ChangeLayoutObjCollisionResourceAttribute);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", SaveLayoutObjGeo);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", UpdateAliasLayoutObjClothGeometry);

void func_400883B8(s32 *a0)
{
    *a0 = 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0100_UpdateLayoutClassPastGeometry", func_400883C0);

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

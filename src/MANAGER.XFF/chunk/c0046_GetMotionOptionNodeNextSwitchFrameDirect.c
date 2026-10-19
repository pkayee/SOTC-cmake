#include "common.h"

extern s32 DldSysUndefSymbol;
extern u8 _AnimObjDef[];
extern u8 _BlendMotionDef[];
extern u8 D_40131D40[];
void iosJumpRecoverPoint();
u32 *getBlendLastMotion();
u32 *getBlendBaseMotion();
/* dld link word: bits 0..17 = byte distance back to the slot (or DldSysUndefSymbol), bits 18..29 = element index */
static inline u8 *dldSlot(u32 *lp) { /* inline helper */
    u8 *slot;
    u32 off = *lp & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol) ? slot : NULL;
}
static inline u8 *dldElem(u32 *lp) { /* inline helper */
    u8 *slot;
    u32 w = *lp;
    u32 off = w & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol)
               ? *(u8 **)(slot + 0x10) + ((w >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(slot + 8) + 0xC)
               : NULL;
}
s32 func_40044598(void *, void *, float);

typedef struct { signed char x, y, z; } V3;
void func_40045C30(void *, void *, s32, float, float);

float GetMotionOptionNodeNextSwitchFrameDirectResource(void *, void *, s32, float, s32);

s32 func_400442D8(void *, void *, float);

void func_40043F08(void *, void *, s32);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0046_GetMotionOptionNodeNextSwitchFrameDirect", GetMotionOptionNodeNextSwitchFrameDirectResource);

float GetMotionOptionNodeNextSwitchFrame(void *a, u32 *lp, s32 b, float f, s32 c) {
    u8 *e;

    if (*(u8 **)(dldSlot(lp) + 8) == _AnimObjDef) {
        e = dldElem(lp);
        if (*(u8 **)(e + 0xC) == NULL) {
            iosJumpRecoverPoint(D_40131D40, *(s32 *)e);
        }
        return GetMotionOptionNodeNextSwitchFrameDirectResource(a, *(u8 **)(*(u8 **)(e + 0xC) + 0x20), b, f, c);
    }
    if (*(u8 **)(dldSlot(lp) + 8) == _BlendMotionDef) {
        return GetMotionOptionNodeNextSwitchFrame(a, getBlendBaseMotion(lp), b, f, c);
    }
    return 0.0f;
}

void GetMotionOptionNodeBooleanInfoFloatFrame(signed char *out, u32 *lp, s32 idx, float x, float y) {
    u8 *e;
    signed char buf[0x30];

    if (*(u8 **)(dldSlot(lp) + 8) == _AnimObjDef) {
        e = dldElem(lp);
        if (*(u8 **)(e + 0xC) == NULL) {
            iosJumpRecoverPoint(D_40131D40, *(s32 *)e);
        }
        func_40045C30(buf, (u8 *)*(s32 *)(*(u8 **)(*(u8 **)(e + 0xC) + 0x20) + 0x1C) + idx * 0x10,
                      *(s16 *)(*(u8 **)(*(u8 **)(e + 0xC) + 0x20) + 4), x, y);
        *(V3 *)out = *(V3 *)(buf + 0x20);
    } else if (*(u8 **)(dldSlot(lp) + 8) == _BlendMotionDef) {
        GetMotionOptionNodeBooleanInfoFloatFrame(out, getBlendLastMotion(lp), idx, x, y);
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0046_GetMotionOptionNodeNextSwitchFrameDirect", GetMotionNbOptionNodes);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0046_GetMotionOptionNodeNextSwitchFrameDirect", GetMotionOptionNodePhysicalId);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0046_GetMotionOptionNodeNextSwitchFrameDirect", GetMotionVersion);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0046_GetMotionOptionNodeNextSwitchFrameDirect", GetMotionResourceOriginalFrames);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0046_GetMotionOptionNodeNextSwitchFrameDirect", GetMotionStretchRatio);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0046_GetMotionOptionNodeNextSwitchFrameDirect", GetMotionIntFrame);

void GetMotionRootIntFrame(void *a, u32 *lp, s32 c) {
    u8 *e;

    if (*(u8 **)(dldSlot(lp) + 8) == _AnimObjDef) {
        e = dldElem(lp);
        if (*(u8 **)(e + 0xC) == NULL) {
            iosJumpRecoverPoint(D_40131D40, *(s32 *)e);
        }
        func_40043F08(a, *(u8 **)(*(u8 **)(e + 0xC) + 0x20), c);
        return;
    }
    if (*(u8 **)(dldSlot(lp) + 8) == _BlendMotionDef) {
        GetMotionRootIntFrame(a, getBlendBaseMotion(lp), c);
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0046_GetMotionOptionNodeNextSwitchFrameDirect", GetMotionOptionNodeIntFrame);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0046_GetMotionOptionNodeNextSwitchFrameDirect", GetMotionRootFloatFrame);

s32 GetMotionRootDirInfo(void *a, u32 *lp, float f) {
    u8 *e;

    if (*(u8 **)(dldSlot(lp) + 8) == _AnimObjDef) {
        e = dldElem(lp);
        if (*(u8 **)(e + 0xC) == NULL) {
            iosJumpRecoverPoint(D_40131D40, *(s32 *)e);
        }
        return func_400442D8(a, *(u8 **)(*(u8 **)(e + 0xC) + 0x20), f);
    }
    if (*(u8 **)(dldSlot(lp) + 8) == _BlendMotionDef) {
        return GetMotionRootDirInfo(a, getBlendBaseMotion(lp), f);
    }
    return 0;
}

s32 GetMotionGazeDirInfo(void *a, u32 *lp, float f) {
    u8 *e;

    if (*(u8 **)(dldSlot(lp) + 8) == _AnimObjDef) {
        e = dldElem(lp);
        if (*(u8 **)(e + 0xC) == NULL) {
            iosJumpRecoverPoint(D_40131D40, *(s32 *)e);
        }
        return func_40044598(a, *(u8 **)(*(u8 **)(e + 0xC) + 0x20), f);
    }
    if (*(u8 **)(dldSlot(lp) + 8) == _BlendMotionDef) {
        return GetMotionGazeDirInfo(a, getBlendBaseMotion(lp), f);
    }
    return 0;
}

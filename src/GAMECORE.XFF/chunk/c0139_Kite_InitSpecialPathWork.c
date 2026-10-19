#include "common.h"

extern int AI_InitAnimalLayout();
extern int AI_SetAnimalLayout();
extern void Kite_InitKitePathWork();

/* func_400BB738: motion-kind not-in-list check. owner+0x20C = dld sheet, row word at +0x18 -> list table; return 0 if the current motion kind is in the list. dld helpers as c0112 */
extern s32 DldSysUndefSymbol;
extern s32 AI_GetCurMotionKind();
/* func_400BB8C0: control-mode not-in-list check. owner+0x20C = dld sheet, row word at +0x18 -> list table; return 0 if the current control mode is in the list. dld helpers as c0112 */
extern s32 DldSysUndefSymbol;
extern s32 AI_GetCurControlMode();

/* func_400BBD90: script sheet row -> element -> motion kind equals current motion kind (T54 dld helpers) */
extern s32 DldSysUndefSymbol;
extern void *isysGetThisSubThread();
extern u8 *GetScriptClass();
static inline u8 *dldRef(u32 *lp, s32 fld) {
    u8 *slot;
    u32 off = *lp & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol) ? *(u8 **)(slot + fld) : NULL;
}

static inline u8 *dldElem(u32 *lp) {
    u8 *slot;
    u32 w = *lp;
    u32 off = w & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol)
               ? *(u8 **)(slot + 0x10) + ((w >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(slot + 8) + 0xC)
               : NULL;
}
static inline s32 dldCnt(u32 *lp) {
    u8 *slot;
    u32 off = *lp & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol) ? *(s32 *)(slot + 0xC) : 0;
}

int Kite_InitSpecialPathWork(int a, int b, int c, int d)
{
    return AI_InitAnimalLayout(a, b, c, d);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0139_Kite_InitSpecialPathWork", AI_CheckPathPoint);

int Kite_CmpPathPoint(char *a, char *b)
{
    if (*(int *)(a + 0x18) == *(int *)(b + 0x18) && *(int *)(a + 0x10) == *(int *)(b + 0x10)) {
        return 1;
    }
    return 0;
}

/* NEARMISS-STUB Kite_InitKitePathPoint */
#if 0 /* NEARMISS 0.0% cat=vu0-mmi sub=- | first insn sqc2 vf0 store (0,0,0,1) has no C form; C gives sw x4 | attempts=1 */
void Kite_InitKitePathPoint(int *p)
{
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0x3F800000;
    p[5] = 0;
    p[6] = -1;
    p[4] = -1;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0139_Kite_InitSpecialPathWork", Kite_InitKitePathPoint);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0139_Kite_InitSpecialPathWork", AI_UpdateLeaderPathWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0139_Kite_InitSpecialPathWork", AI_UpdateChildPathWork);

void Kite_InitKiteAdvertisePathWork(void *arg0)
{
    Kite_InitKitePathWork();
    (*(int *)((char *)(arg0) + 4)) = 0;
}

void Kite_SetAnimalID_KitePathWork(int *arg0, int arg1)
{
    *arg0 = arg1;
}

void Kite_SetEventIDList(int arg0, int arg1, unsigned int arg2)
{
    if (arg2 < 0xAU) {
        (*(int *)((char *)(((arg2 * 4) + arg0)) + 0x1BC)) = arg1;
    }
}

void Kite_InitEventCheck(int *arg0)
{
    arg0[0] = -1;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
}

void Kite_ResetEventFrameCheck(char *p)
{
    *(int *)(p + 0x8) = 0;
    *(int *)(p + 0xC) = 0;
}

void Kite_StartEventCheck(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0)) = arg1;
    (*(int *)((char *)(arg0) + 8)) = 1;
    (*(int *)((char *)(arg0) + 4)) = 0;
}

void Kite_EndEventCheck(char *p)
{
    *(int *)(p + 0x4) = 1;
    *(int *)(p + 0xC) = 1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0139_Kite_InitSpecialPathWork", Kite_SetAnimalLayout);

void Kite_SetKiteObj(char *p, int a1)
{
    *(int *)(p + 0xF0) = a1;
    *(int *)(p + 0x1E8) = a1;
}

void Kite_SetPathOfs(char *p, s128 *v)
{
    *(s128 *)(p + 0xD0) = *v;
    *(s128 *)(p + 0x1A0) = *v;
}

int Kite_SetSpecialPathLayout(int a, int b, int c, int d)
{
    return AI_SetAnimalLayout(a + 496, b, c, d);
}

void Kite_SucceedKitePathWork(void *arg0, void *arg1)
{
    *(s64 *)((char *)arg0 + 0x10) = *(s64 *)((char *)arg1 + 0x10);
    *(s64 *)((char *)arg0 + 0x18) = *(s64 *)((char *)arg1 + 0x18);
    *(s64 *)((char *)arg0 + 0x20) = *(s64 *)((char *)arg1 + 0x20);
    *(s64 *)((char *)arg0 + 0x28) = *(s64 *)((char *)arg1 + 0x28);
    *(s64 *)((char *)arg0 + 0x30) = *(s64 *)((char *)arg1 + 0x30);
    *(s64 *)((char *)arg0 + 0x38) = *(s64 *)((char *)arg1 + 0x38);
    *(s64 *)((char *)arg0 + 0x40) = *(s64 *)((char *)arg1 + 0x40);
    *(s64 *)((char *)arg0 + 0x48) = *(s64 *)((char *)arg1 + 0x48);
    *(s64 *)((char *)arg0 + 0x50) = *(s64 *)((char *)arg1 + 0x50);
    *(s64 *)((char *)arg0 + 0x58) = *(s64 *)((char *)arg1 + 0x58);
    *(s64 *)((char *)arg0 + 0x60) = *(s64 *)((char *)arg1 + 0x60);
    *(s64 *)((char *)arg0 + 0x68) = *(s64 *)((char *)arg1 + 0x68);
    *(s64 *)((char *)arg0 + 0x70) = *(s64 *)((char *)arg1 + 0x70);
    *(s64 *)((char *)arg0 + 0x78) = *(s64 *)((char *)arg1 + 0x78);
    *(s64 *)((char *)arg0 + 0x80) = *(s64 *)((char *)arg1 + 0x80);
    *(s64 *)((char *)arg0 + 0x88) = *(s64 *)((char *)arg1 + 0x88);
    *(s64 *)((char *)arg0 + 0x90) = *(s64 *)((char *)arg1 + 0x90);
    *(s64 *)((char *)arg0 + 0x98) = *(s64 *)((char *)arg1 + 0x98);
    *(s64 *)((char *)arg0 + 0xA0) = *(s64 *)((char *)arg1 + 0xA0);
    *(s64 *)((char *)arg0 + 0xA8) = *(s64 *)((char *)arg1 + 0xA8);
    *(s64 *)((char *)arg0 + 0xB0) = *(s64 *)((char *)arg1 + 0xB0);
    *(s64 *)((char *)arg0 + 0xB8) = *(s64 *)((char *)arg1 + 0xB8);
    *(s64 *)((char *)arg0 + 0xC0) = *(s64 *)((char *)arg1 + 0xC0);
    *(s64 *)((char *)arg0 + 0xC8) = *(s64 *)((char *)arg1 + 0xC8);
}

s32 func_400BB738(u8 *o) {
    u32 *tab = (u32 *)dldElem((u32 *)(*(u8 **)(o + 0x20C) + 0x18));
    s32 kind = AI_GetCurMotionKind(*(s32 *)(o + 0x44));
    s32 n = 0;
    s32 i;

    if (tab != NULL) {
        n = dldCnt((u32 *)(*(u8 **)(o + 0x20C) + 0x18));
    }
    for (i = 0; i < n; i++) {
        if (kind == (s32)dldElem(&tab[i])) {
            return 0;
        }
    }
    return 1;
}

s32 func_400BB8C0(u8 *o) {
    u32 *tab = (u32 *)dldElem((u32 *)(*(u8 **)(o + 0x20C) + 0x1C));
    s32 kind = AI_GetCurControlMode(*(s32 *)(o + 0x44));
    s32 n = 0;
    s32 i;

    if (kind != 0) {
        n = dldCnt((u32 *)(*(u8 **)(o + 0x20C) + 0x1C));
    }
    for (i = 0; i < n; i++) {
        if (kind == (s32)dldElem(&tab[i])) {
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0139_Kite_InitSpecialPathWork", func_400BBA48);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0139_Kite_InitSpecialPathWork", func_400BBC40);

s32 func_400BBD90(void) {
    void *sub = isysGetThisSubThread();
    u8 *sc = GetScriptClass(sub);
    u32 *p = (u32 *)dldRef(*(u32 **)(sc + 0x48), 0x10);
    u8 *e;
    u8 *m;
    s32 kind;

    e = p ? dldElem(p) : NULL;
    if (e != NULL) {
        m = dldElem((u32 *)(e + 0x10));
        kind = AI_GetCurMotionKind(sub);
        if (m != NULL && kind != 0) {
            if (m == (u8 *)kind) {
                return 1;
            }
        }
    }
    return 0;
}

s32 func_400BBF00(void) {
    void *sub = isysGetThisSubThread();
    u8 *sc = GetScriptClass(sub);
    u32 *p = (u32 *)dldRef(*(u32 **)(sc + 0x48), 0x10);
    u8 *e;
    u8 *m;
    s32 kind;

    e = p ? dldElem(p) : NULL;
    if (e != NULL) {
        m = dldElem((u32 *)(e + 0x14));
        kind = AI_GetCurMotionKind(sub);
        if (m != NULL && m == (u8 *)kind) {
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0139_Kite_InitSpecialPathWork", func_400BC068);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0139_Kite_InitSpecialPathWork", func_400BC278);

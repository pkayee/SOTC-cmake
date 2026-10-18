#include "common.h"

extern u8 *D_40015818;

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", createLayerMenu);

extern s32 D_40021E00[];
u8 *dlGetLinkLayer();

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40010A20);
void func_40010A20(void)
{
    s32 bits = 0;
    s32 i;

    for (i = 0; i < 32; i++)
    {
        bits |= (D_40021E00[i] & 1) << i;
    }
    *(s32 *)dlGetLinkLayer() = bits;
}

void func_40010A80(void) {
}

/* NEARMISS-STUB swordEffectTool */
#if 0 /* NEARMISS 88.13% cat=regalloc sub=- | ret var lands in a1 and the cond value in v1 (target: cond in a1, ret built in v0 before bnez); if-return shape worse; 3 variants | attempts=1 */
extern u8 D_40014948[];
void createParamMenu(u8 *a0, s32 a1);

u8 *swordEffectTool(void)
{
    u8 *p = D_40014948;
    u8 *ret = NULL;

    if (*(s32 *)(p + 0x30) == 0)
    {
        createParamMenu(p, 0);
        ret = p + 0x30;
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", swordEffectTool);

void changeFogParam();
void refractionInit();

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40010AC8);
void func_40010AC8(void)
{
    changeFogParam();
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40010AE0);
void func_40010AE0(void)
{
    refractionInit();
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40010AF8);
extern u8 gcGlobalVar[];
extern u8 D_4001498C[];
void *SCRGetFirstObj(void *p);
u8 *GetLayoutClass(void *obj);

u8 *func_40010AF8(void)
{
    u8 *obj;
    u8 *layout;

    obj = SCRGetFirstObj(gcGlobalVar + 0x2B8);
    if (obj != NULL) {
        layout = GetLayoutClass(obj);
        if (layout != NULL) {
            return *(u8 **)(layout + 0x144) + 0x2A8;
        }
    }
    return D_4001498C;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40010B48);
u8 *func_40010B48(void)
{
    u8 *obj;
    u8 *layout;

    obj = SCRGetFirstObj(gcGlobalVar + 0x2B8);
    if (obj != NULL) {
        layout = GetLayoutClass(obj);
        if (layout != NULL) {
            return *(u8 **)(layout + 0x144) + 0x2AC;
        }
    }
    return D_4001498C;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40010B98);
u8 *func_40010B98(void)
{
    u8 *obj;
    u8 *layout;

    obj = SCRGetFirstObj(gcGlobalVar + 0x2B0);
    if (obj != NULL) {
        layout = GetLayoutClass(obj);
        return *(u8 **)(layout + 0x144) + 0x2A8;
    }
    return D_4001498C;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40010BE0);
u8 *func_40010BE0(void)
{
    u8 *obj;
    u8 *layout;

    obj = SCRGetFirstObj(gcGlobalVar + 0x2B0);
    if (obj != NULL) {
        layout = GetLayoutClass(obj);
        return *(u8 **)(layout + 0x144) + 0x2AC;
    }
    return D_4001498C;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40010C28);
void SetEffectDebugLock(s32 flag);

void func_40010C28(void) {
    SetEffectDebugLock(0);
}

/* NEARMISS-STUB fullScreenEffectTool */
#if 0 /* NEARMISS 92.78% cat=regalloc sub=- | ret var lands in a0 instead of v0 and lui uses v1 not a0 (target zeroes v0 before bnez and computes s0+0x30 into v0); 3 variants tried | attempts=1 */
extern u8 D_40015778[];
void createParamMenu(u8 *a0, s32 a1);

u8 *fullScreenEffectTool(void)
{
    u8 *p = D_40015778;
    u8 *ret = NULL;

    if (*(s32 *)(p + 0x30) == 0)
    {
        SetEffectDebugLock(1);
        createParamMenu(p, 0);
        ret = p + 0x30;
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", fullScreenEffectTool);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40010C88);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40010E68);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40010FC8);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011170);

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_400115C0);
u8 *func_400115C0(void) {
    return D_40015818 + 0x80;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_400115D0);
u8 *func_400115D0(void) {
    return D_40015818 + 0x50;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_400115E0);
void DebugDispFogColClass(void *p, s32 flag, f32 f);

void func_400115E0(void) {
    DebugDispFogColClass(*(u8 **)(D_40015818 + 0x98), 0, 3.0f);
}

/* NEARMISS-STUB func_40011610 */
#if 0 /* NEARMISS 98.08% cat=regalloc sub=- | base and loaded value swapped: target keeps base in a1 and value in v1, ours base v1 value a1 (3 variants tried) | attempts=1 */
void func_40010E68(u8 *a0);

void func_40011610(void)
{
    u8 *p;
    u8 *v;

    p = D_40015818;
    v = *(u8 **)(p + 0x98);
    if (v != NULL)
    {
        func_40010E68(v);
    }
}
#endif
INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011610);

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011648);
u8 *GetFogColMan(void);

u8 *func_40011648(void) {
    return GetFogColMan() + 0x94;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011668);
s32 func_40011668(void) {
    u8 *p = *(u8 **)(D_40015818 + 0x98);

    if (p == NULL) {
        return 0;
    }
    return *(s32 *)(p + 0x44);
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011688);
u8 *func_40011688(void) {
    return D_40015818 + 0x54;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011698);
u8 *func_40011698(void) {
    return D_40015818 + 0x5C;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_400116A8);
u8 *func_400116A8(void) {
    return D_40015818 + 0x60;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_400116B8);
u8 *func_400116B8(void) {
    return D_40015818 + 0x58;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_400116C8);
u8 *func_400116C8(void) {
    return D_40015818 + 0x64;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_400116D8);
u8 *func_400116D8(void) {
    return D_40015818 + 0x68;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_400116E8);
u8 *func_400116E8(void) {
    return D_40015818 + 0x6C;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_400116F8);
u8 *func_400116F8(void) {
    return D_40015818 + 0x70;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011708);
u8 *func_40011708(void) {
    return D_40015818 + 0x74;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011718);
u8 *func_40011718(void) {
    return D_40015818 + 0x78;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011728);
u8 *func_40011728(void) {
    return D_40015818 + 0x7C;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011738);
u8 *func_40011738(void) {
    return D_40015818 + 0x84;
}

/* NEARMISS-STUB func_40011748 */
#if 0 /* NEARMISS 90.0% cat=regalloc sub=GRPTOOLS-kF1 | store-sink+reg: target keeps s->A0=0 after if-join (ours sinks it into fallthrough), first ptr in v1 (ours v0), 2nd ptr loaded to a0 with beql epilogue | attempts=1 */
void iosFree(void *p);

void func_40011748(void) {
    u8 *ctx = D_40015818;
    u8 *p = *(u8 **)(ctx + 0xA0);

    *(s32 *)(ctx + 0x94) = 0;
    if (p != NULL) {
        iosFree(p);
    }
    *(s32 *)(ctx + 0xA0) = 0;
    if (*(u8 **)(ctx + 0x9C) != NULL) {
        iosFree(*(u8 **)(ctx + 0x9C));
        *(s32 *)(ctx + 0x9C) = 0;
    }
}
#endif
INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011748);

/* NEARMISS-STUB func_400117A0 */
#if 0 /* NEARMISS 76.38% cat=call-abi sub=- | target does a non-tail jal func_400115E0 then restores s0/s1/ra; ours tail-calls with j (sibcall) even with prototyped callee; ~9 insns of arg/reg order also di | attempts=1 */
void func_40010C88(u8 *a0);

void func_400117A0(u8 *a0, u8 *a1)
{
    u8 *p = D_40015818;

    if (*(s32 *)(p + 0xA0) != 0)
    {
        u8 *x = *(u8 **)(a1 + 0x2C);
        s32 idx;

        x = *(u8 **)(x + 0x4);
        x = *(u8 **)(x + 0x3E8);
        idx = *(s32 *)(x + 0x4);
        *(s32 *)(p + 0x98) = *(s32 *)(*(u8 **)(p + 0x9C) + (idx << 2));
        func_40010C88(p);
        func_400115E0(a0, a1);
    }
}
#endif
INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_400117A0);

/* NEARMISS-STUB func_40011818 */
#if 0 /* NEARMISS 99.41% cat=regalloc sub=- | lw/bnez value in a0 (ours) vs a2 (target); base/flag order otherwise matches, tail j matches | attempts=1 */
void func_40011818(void)
{
    if ((*(s32 *)(padManagerData + 0x8) & 0x20) && (*(s32 *)(D_40015818 + 0x94) == 0))
    {
        func_40010FC8();
    }
}
#endif
INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011818);

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011860);
u8 *func_40011860(void) {
    return D_40015818 + 0x10;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011870);
u8 *func_40011870(void) {
    return D_40015818 + 0x14;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011880);
u8 *func_40011880(void) {
    return D_40015818 + 0x18;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011890);
u8 *func_40011890(void) {
    return D_40015818;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_400118A0);
u8 *func_400118A0(void) {
    return D_40015818 + 0x4;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_400118B0);
u8 *func_400118B0(void) {
    return D_40015818 + 0x8;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_400118C0);
u8 *func_400118C0(void)
{
    u8 *p = D_40015818;

    if (*(f32 *)(p + 0x30) < *(f32 *)(p + 0x20))
    {
        *(f32 *)(p + 0x20) = *(f32 *)(p + 0x30);
    }
    return p + 0x20;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_400118E8);
u8 *func_400118E8(void)
{
    u8 *p = D_40015818;

    if (*(f32 *)(p + 0x34) < *(f32 *)(p + 0x24))
    {
        *(f32 *)(p + 0x24) = *(f32 *)(p + 0x34);
    }
    return p + 0x24;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011910);
u8 *func_40011910(void)
{
    u8 *p = D_40015818;

    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x28))
    {
        *(f32 *)(p + 0x28) = *(f32 *)(p + 0x38);
    }
    return p + 0x28;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011938);
u8 *func_40011938(void)
{
    u8 *p = D_40015818;

    if (*(f32 *)(p + 0x30) < *(f32 *)(p + 0x20))
    {
        *(f32 *)(p + 0x30) = *(f32 *)(p + 0x20);
    }
    return p + 0x30;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011960);
u8 *func_40011960(void)
{
    u8 *p = D_40015818;

    if (*(f32 *)(p + 0x34) < *(f32 *)(p + 0x24))
    {
        *(f32 *)(p + 0x34) = *(f32 *)(p + 0x24);
    }
    return p + 0x34;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011988);
u8 *func_40011988(void)
{
    u8 *p = D_40015818;

    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x28))
    {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x28);
    }
    return p + 0x38;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_400119B0);
u8 *func_400119B0(void) {
    return D_40015818 + 0x40;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_400119C0);
u8 *func_400119C0(void) {
    return D_40015818 + 0x44;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_400119D0);
u8 *func_400119D0(void) {
    return D_40015818 + 0x48;
}

extern u8 padManagerData[];
s32 GetToolNewNameNum();
s32 NewCreateFogColClass();

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_400119E0);
void func_400119E0(void)
{
    u8 *p;
    u8 *f;
    s32 n;

    if (*(s32 *)(padManagerData + 0x8) & 0x20)
    {
        p = D_40015818;
        if (*(s32 *)(p + 0xA4) < 0x14)
        {
            f = GetFogColMan();
            n = GetToolNewNameNum(*(s32 *)(p + 0xA4));
            if (NewCreateFogColClass(f, 0, n))
            {
                *(s32 *)(p + 0xA4) += 1;
            }
        }
    }
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011A68);
void func_40011A68(void)
{
    u8 *p;
    u8 *f;
    s32 n;

    if (*(s32 *)(padManagerData + 0x8) & 0x20)
    {
        p = D_40015818;
        if (*(s32 *)(p + 0xA4) < 0x14)
        {
            f = GetFogColMan();
            n = GetToolNewNameNum(*(s32 *)(p + 0xA4));
            if (NewCreateFogColClass(f, 12, n))
            {
                *(s32 *)(p + 0xA4) += 1;
            }
        }
    }
}

extern s32 D_400157B0;
void func_40010E68();

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0000_createLayerMenu", func_40011AF0);
void func_40011AF0(void)
{
    u8 **pp = &D_40015818;
    u8 *p = *pp;

    if (*(u8 **)(p + 0x98) != NULL)
    {
        func_40010E68(*(u8 **)(p + 0x98), p);
    }
    p = *pp;
    if (p != NULL)
    {
        iosFree(p);
    }
    *pp = NULL;
    D_400157B0 = 0;
}

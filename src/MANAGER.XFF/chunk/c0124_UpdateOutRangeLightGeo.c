#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", UpdateOutRangeLightGeo);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", func_400A11A0);
extern s32 D_4012B1E8;
void SendVolumeShapeDamageLetter();

void func_400A11A0(s32 arg0, s32 arg1)
{
    s32 q;

    q = arg1 + 0x90;
    if (0.0009999999310821295f < *(f32 *)(q + 4))
    {
        SendVolumeShapeDamageLetter(arg0, D_4012B1E8, ((s32 *)*(s32 *)(arg1 + 0x138))[1], *(s32 *)*(s32 *)(arg1 + 0x138), *(s32 *)(arg1 + 0x134), *(s32 *)(arg1 + 0x13C), q, arg1 + 0x40);
    }
}

/* NEARMISS-STUB ReparentChildObjects */
#if 0 /* NEARMISS 78.0% cat=call-abi sub=- | non-tail jal with s0 frame; we emit j | attempts=1 */
s32 GetLayoutClass();
s32 GetCharacterClass();
s32 ReparentCharacterObj();

void ReparentChildObjects(s32 arg0)
{
    if (GetLayoutClass(arg0) != 0)
    {
        if (GetCharacterClass(arg0) != 0)
        {
            ReparentCharacterObj(arg0);
        }
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", ReparentChildObjects);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", CreateScriptCharObj);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", GetScriptCharacterClass);
s32 GetScriptCharacterClass(s32 arg0)
{
    if (*(u8 *)(arg0 + 8) != 9)
    {
        return 0;
    }
    return arg0 + 0x20;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", FlushScriptCharObj);
void flushScriptObj();
void FlushCharacterObj();

void FlushScriptCharObj(s32 arg0)
{
    s32 p;
    s32 t;

    p = arg0 + 0x20;
    if (*(u8 *)(arg0 + 8) != 9)
    {
        p = 0;
    }
    flushScriptObj(arg0);
    FlushCharacterObj(arg0);
    t = *(s32 *)(p + 0x114C);
    if (t != 0)
    {
        iosFree(t);
    }
}

/* NEARMISS-STUB InitScriptCharObj */
#if 0 /* NEARMISS 85.9% cat=sched sub=- | epilogue ld s2/ld ra and store order differ (gcc scheduling); dsubu fixed by s64 tcount; p in s0 fixed | attempts=1 */
s64 iosGetTCount();
s32 iosGetSecondFromTCount();
s32 InitCharacterObj();
s32 initScriptObj();

void InitScriptCharObj(s32 arg0, s32 arg1)
{
    s32 p;
    s64 t;
    s32 v;

    t = iosGetTCount();
    InitCharacterObj(arg0, arg1);
    iosGetSecondFromTCount(iosGetTCount() - t);
    initScriptObj(arg0, arg1 + 0x11C, *(s32 *)arg0);
    iosGetSecondFromTCount(iosGetTCount() - t);
    v = *(s32 *)(arg1 + 0x140);
    p = arg0 + 0x20;
    if (*(u8 *)(arg0 + 8) != 9)
    {
        p = 0;
    }
    *(s32 *)(p + 0x1140) = v;
    *(s32 *)(p + 0x1144) = *(s32 *)(arg1 + 0x144);
    *(s32 *)(p + 0x115C) = 0;
    *(s32 *)(p + 0x1148) = *(s32 *)(arg1 + 0x148);
    *(s32 *)(p + 0x1154) = 0;
    *(s32 *)(p + 0x1150) = 0;
    *(s32 *)(p + 0x114C) = 0;
    *(s32 *)(p + 0x1158) = 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", InitScriptCharObj);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", SetScriptCharDefaultScriptFunc);
extern s32 D_4012B2A0;

void SetScriptCharDefaultScriptFunc(s32 arg0)
{
    D_4012B2A0 = arg0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", SetScriptCharacterObjReleaseCallBackFunc);
void SetScriptCharacterObjReleaseCallBackFunc(s32 arg0, s32 arg1, s32 arg2)
{
    s32 p;

    p = arg0 + 0x20;
    if (*(u8 *)(arg0 + 8) != 9)
    {
        p = 0;
    }
    *(s32 *)(p + 0x1158) = arg1;
    *(s32 *)(p + 0x115C) = arg2;
}

/* NEARMISS-STUB func_400A1520 */
#if 0 /* NEARMISS 94.0% cat=regalloc sub=- | p routed via v0 copy after movn | attempts=1 */
/* func_400A1520 best C: 94.05% (objdiff). Residual: ours keeps p in v1 and f in v0; target routes p through v0 (copy after movn). */
void FlushCharacterObjImmediate();

void func_400A1520(s32 arg0)
{
    s32 f;
    s32 p;

    p = (*(u8 *)(arg0 + 8) != 9) ? 0 : arg0 + 0x20;
    f = *(s32 *)(p + 0x1158);
    if (f != 0)
    {
        ((void (*)(s32))f)(*(s32 *)(p + 0x115C));
    }
    flushScriptObjImmediate(arg0);
    FlushCharacterObjImmediate(arg0);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", func_400A1520);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", func_400A1578);
void func_400A1578(s32 arg0)
{
    s32 p;
    s32 t;

    p = arg0 + 0x20;
    if (*(u8 *)(arg0 + 8) != 9)
    {
        p = 0;
    }
    flushScriptObj(arg0);
    FlushCharacterObj(arg0);
    t = *(s32 *)(p + 0x114C);
    if (t != 0)
    {
        iosFree(t);
    }
    isysFlushISYSLetterObj(arg0);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", GetScriptCharObjWorkSize);
s32 GetCharacterObjWorkSize();
s32 GetScriptObjWorkSize();

s32 GetScriptCharObjWorkSize(s32 arg0)
{
    s32 a;
    s32 b;

    a = GetCharacterObjWorkSize(arg0);
    b = GetScriptObjWorkSize(arg0 + 0x11C);
    return a + b;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", CreateScriptLayoutObj);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", CreateAliasScriptLayoutObj);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", FlushScriptLayoutObj);
s32 GetScriptLayoutClass();
void iosFree();

void FlushScriptLayoutObj(s32 arg0)
{
    s32 t;

    FlushLayoutObj(arg0);
    flushScriptObj(arg0);
    t = *(s32 *)(GetScriptLayoutClass(arg0) + 0x2D4);
    if (t != 0)
    {
        iosFree(t);
    }
}

/* NEARMISS-STUB GetScriptLayoutClass */
#if 0 /* NEARMISS 96.0% cat=regalloc sub=- | 0xD const in v0 vs v1 | attempts=1 */
s32 GetScriptAnimationClass();

s32 GetScriptLayoutClass(s32 arg0)
{
    u8 t;

    t = *(u8 *)(arg0 + 8);
    if (t == 0xB)
    {
        return arg0 + 0x20;
    }
    if (t == 0xD)
    {
        return GetScriptAnimationClass(arg0);
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", GetScriptLayoutClass);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", SetScriptLayoutObjLetterProcMode);
s32 GetScriptAnimationClass();

void SetScriptLayoutObjLetterProcMode(s32 arg0, s32 arg1)
{
    s32 p;
    u8 t;

    p = arg0 + 0x20;
    t = *(u8 *)(arg0 + 8);
    if (t != 0xB)
    {
        if (t == 0xD)
        {
            p = GetScriptAnimationClass(arg0);
        }
        else
        {
            p = 0;
        }
    }
    *(s32 *)(p + 0x2D0) = arg1;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", ExecScriptLayoutObj);
s32 GetDamageClass();
s32 ResetDamageClass();
s32 CheckDamageLetter();
s32 CheckLetter();

void ExecScriptLayoutObj(s32 arg0)
{
    s32 t;

    t = GetDamageClass(arg0);
    ResetDamageClass(t);
    CheckLetter(arg0, CheckDamageLetter);
}

/* NEARMISS-STUB InitScriptLayoutObj */
#if 0 /* NEARMISS 91.0% cat=cse-hoist sub=- | arg0+0x20 CSE into saved reg; frame 0x30 vs 0x20 | attempts=1 */
s32 InitLayoutObj();
s32 initScriptObj();
s32 GetScriptAnimationClass();
s32 InitDamageClass();

s32 InitScriptLayoutObj(s32 arg0, s32 arg1)
{
    s32 p;
    s32 q;

    InitLayoutObj(arg0, arg1);
    initScriptObj(arg0, arg1 + 0x7C, *(s32 *)arg0);
    p = arg0 + 0x20;
    if (*(u8 *)(arg0 + 8) != 0xB)
    {
        if (*(u8 *)(arg0 + 8) == 0xD)
        {
            p = GetScriptAnimationClass(arg0);
        }
        else
        {
            p = 0;
        }
    }
    *(s32 *)(p + 0x2D4) = 0;
    *(s32 *)(p + 0x2DC) = *(s32 *)(arg1 + 0xA0);
    if (*(u8 *)(arg0 + 8) == 0xB)
    {
        q = arg0 + 0x20;
    }
    else
    {
        if (*(u8 *)(arg0 + 8) == 0xD)
        {
            q = GetScriptAnimationClass(arg0);
        }
        else
        {
            q = 0;
        }
    }
    *(s32 *)(q + 0x2D0) = 0;
    InitDamageClass(p + 0x230);
    return 1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", InitScriptLayoutObj);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", GetScriptLayoutObjWorkSize);
s32 GetLayoutObjWorkSize();

s32 GetScriptLayoutObjWorkSize(s32 arg0)
{
    s32 a;
    s32 b;

    a = GetLayoutObjWorkSize(arg0);
    b = GetScriptObjWorkSize(arg0 + 0x7C);
    return a + b;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", FlushScriptLayoutObjImmediate);
void FlushLayoutObjImmediate();
void flushScriptObjImmediate();

void FlushScriptLayoutObjImmediate(s32 arg0)
{
    FlushLayoutObjImmediate(arg0);
    flushScriptObjImmediate(arg0);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", func_400A1AD8);
void isysFlushISYSLetterObj();

void func_400A1AD8(s32 arg0)
{
    s32 t;

    FlushLayoutObj(arg0);
    flushScriptObj(arg0);
    t = *(s32 *)(GetScriptLayoutClass(arg0) + 0x2D4);
    if (t != 0)
    {
        iosFree(t);
    }
    isysFlushISYSLetterObj(arg0);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", func_400A1B28);
void func_400A1B28(s32 arg0)
{
    FlushLayoutObjImmediate(arg0);
    flushScriptObjImmediate(arg0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", InitAliasScriptLayoutObj);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", func_400A1C08);

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

s32 GetLayoutClass();
s32 GetCharacterClass();
s32 ReparentCharacterObj();

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", ReparentChildObjects);
void ReparentChildObjects(u8 *obj)
{
    if (GetLayoutClass(obj))
    {
        if (GetCharacterClass(obj))
        {
            ReparentCharacterObj(obj);
        }
    }
    /* explicit return keeps the final call a jal (no sibcall) */
    return;
}

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

s64 iosGetTCount();
void iosGetSecondFromTCount();
void InitCharacterObj();
void initScriptObj();

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", InitScriptCharObj);
void InitScriptCharObj(u8 *obj, u8 *params)
{
    u8 *cls;
    s64 t;

    t = iosGetTCount();
    InitCharacterObj(obj, params);
    iosGetSecondFromTCount(iosGetTCount() - t);
    initScriptObj(obj, params + 0x11C, *(s32 *)obj);
    iosGetSecondFromTCount(iosGetTCount() - t);
    cls = obj[8] == 9 ? obj + 0x20 : 0;
    *(s32 *)(cls + 0x1140) = *(s32 *)(params + 0x140);
    *(s32 *)(cls + 0x1144) = *(s32 *)(params + 0x144);
    *(s32 *)(cls + 0x1148) = *(s32 *)(params + 0x148);
    *(s32 *)(cls + 0x1154) = 0;
    *(s32 *)(cls + 0x1150) = 0;
    *(s32 *)(cls + 0x114C) = 0;
    *(s32 *)(cls + 0x1158) = 0;
    *(s32 *)(cls + 0x115C) = 0;
}

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

void FlushCharacterObjImmediate();
void flushScriptObjImmediate();

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", func_400A1520);
void func_400A1520(u8 *obj)
{
    u8 *cls = obj[8] == 9 ? obj + 0x20 : 0;
    void (*fn)(s32) = *(void (**)(s32))(cls + 0x1158);

    if (fn != 0)
    {
        fn(*(s32 *)(cls + 0x115C));
    }
    flushScriptObjImmediate(obj);
    FlushCharacterObjImmediate(obj);
}

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

void isysInitISYSLetterObj();
u8 *_isysCreateObj();
void InitLayoutObj();
void InitAliasLayoutObj();
void isysSetObjImmediateDeleteFunc();
void FlushLayoutObj();
s32 GetLayoutObjWorkSize();
void InitDamageClass();
u8 *GetScriptAnimationClass();
static void func_400A1AD8();
static void func_400A1B28();
u8 *GetScriptLayoutClass(u8 *);

static inline u8 *scriptLayoutClass(u8 *o) {
    switch (o[8]) {
    case 11:
        return o + 0x20;
    case 13:
        return GetScriptAnimationClass(o);
    }
    return 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", CreateScriptLayoutObj);
u8 *CreateScriptLayoutObj(s32 parent, s32 extra, u8 *params) {
    u8 *script = params + 0x7C;
    s32 size;
    u8 *obj;
    u8 *cls;
    u8 *cls2;

    size = extra + (GetLayoutObjWorkSize(params) + GetScriptObjWorkSize(script));
    obj = _isysCreateObj(parent, 11, 0x300, size + 0x33, func_400A1AD8, 16);
    if (obj != 0) {
        isysInitISYSLetterObj(obj);
        InitLayoutObj(obj, params);
        initScriptObj(obj, script, *(s32 *)obj);
        cls = scriptLayoutClass(obj);
        *(s32 *)(cls + 0x2D4) = 0;
        *(s32 *)(cls + 0x2DC) = *(s32 *)(params + 0xA0);
        cls2 = scriptLayoutClass(obj);
        *(s32 *)(cls2 + 0x2D0) = 0;
        InitDamageClass(cls + 0x230);
        isysSetObjImmediateDeleteFunc(obj, func_400A1B28);
    }
    return obj;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", CreateAliasScriptLayoutObj);
u8 *CreateAliasScriptLayoutObj(s32 parent, s32 extra, u8 *params, s32 alias) {
    u8 *script = params + 0x7C;
    s32 size;
    u8 *obj;
    u8 *cls;
    u8 *cls2;

    size = extra + (GetLayoutObjWorkSize(params) + GetScriptObjWorkSize(script));
    obj = _isysCreateObj(parent, 11, 0x300, size, func_400A1AD8, 16);
    if (obj != 0) {
        isysInitISYSLetterObj(obj);
        InitAliasLayoutObj(obj, params, alias);
        initScriptObj(obj, script, *(s32 *)obj);
        cls = scriptLayoutClass(obj);
        *(s32 *)(cls + 0x2D4) = 0;
        *(s32 *)(cls + 0x2DC) = *(s32 *)(params + 0xA0);
        cls2 = scriptLayoutClass(obj);
        *(s32 *)(cls2 + 0x2D0) = 0;
        InitDamageClass(cls + 0x230);
        isysSetObjImmediateDeleteFunc(obj, func_400A1B28);
    }
    return obj;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", FlushScriptLayoutObj);
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

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", GetScriptLayoutClass);
u8 *GetScriptLayoutClass(u8 *obj) {
    switch (obj[8]) {
    case 11:
        return obj + 0x20;
    case 13:
        return GetScriptAnimationClass(obj);
    }
    return 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", SetScriptLayoutObjLetterProcMode);
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

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", InitScriptLayoutObj);
s32 InitScriptLayoutObj(u8 *obj, u8 *params) {
    u8 *cls;
    u8 *cls2;

    InitLayoutObj(obj, params);
    initScriptObj(obj, params + 0x7C, *(s32 *)obj);
    cls = scriptLayoutClass(obj);
    *(s32 *)(cls + 0x2D4) = 0;
    *(s32 *)(cls + 0x2DC) = *(s32 *)(params + 0xA0);
    cls2 = scriptLayoutClass(obj);
    *(s32 *)(cls2 + 0x2D0) = 0;
    InitDamageClass(cls + 0x230);
    return 1;
}

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

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", InitAliasScriptLayoutObj);
s32 InitAliasScriptLayoutObj(u8 *obj, u8 *params) {
    u8 *cls;
    u8 *cls2;

    InitAliasLayoutObj(obj, params);
    initScriptObj(obj, params + 0x7C, *(s32 *)obj);
    cls = scriptLayoutClass(obj);
    *(s32 *)(cls + 0x2D4) = 0;
    *(s32 *)(cls + 0x2DC) = *(s32 *)(params + 0xA0);
    cls2 = scriptLayoutClass(obj);
    *(s32 *)(cls2 + 0x2D0) = 0;
    InitDamageClass(cls + 0x230);
    return 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0124_UpdateOutRangeLightGeo", func_400A1C08);

#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0059__setNodeHPBIllegal", _setNodeHPBIllegal);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0059__setNodeHPBIllegal", _setNodeHPB);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0059__setNodeHPBIllegal", _setRootXYZHPB);

float getexpressiondatapoint(int arg0, int arg1)
{
    return (*(float *)((char *)(((arg1 * 0x10) + arg0)) + 4));
}

extern s32 DldSysUndefSymbol;
u8 *GetLayoutClass(void *chara);
void gStatGobjDispGflagSet(u8 *obj);
s32 gStatGobjDispGflagChk(u8 *obj);

static inline s32 dldResolve(u32 *h)
{
    u32 v = *h;
    s32 off = v & 0x3FFFF;
    s32 *t = off != 0 ? *(s32 **)((u8 *)h - off) : 0;

    return (t != 0 && (s32)t != DldSysUndefSymbol) ? t[4] + ((v >> 18) & 0xFFF) * ((s32 *)t[2])[3] : 0;
}

s32 setGameFlagForGameObj(void *obj)
{
    s32 base;

    if (GetLayoutClass(obj) != 0)
    {
        base = *(s32 *)(GetLayoutClass(obj) + 0x1A4);
    }
    else
    {
        base = 0;
    }
    if (dldResolve((u32 *)(base + 0x10)) != 0)
    {
        gStatGobjDispGflagSet((u8 *)dldResolve((u32 *)(base + 0x10)));
        return 1;
    }
    return 0;
}

s32 chkGameFlagForGameObj(void *obj)
{
    s32 base;

    if (GetLayoutClass(obj) != 0)
    {
        base = *(s32 *)(GetLayoutClass(obj) + 0x1A4);
    }
    else
    {
        base = 0;
    }
    if (dldResolve((u32 *)(base + 0x10)) != 0)
    {
        return gStatGobjDispGflagChk((u8 *)dldResolve((u32 *)(base + 0x10)));
    }
    return 0;
}

extern s32 rootPtn;
extern const char D_401333F8[];
void *_gcCreateChildScriptObj(void *fn, void *a1, void *a2, s32 a3, s32 a4, s32 a5, const char *a6, void *a7);
void func_40055690(void);

void bootTexAlphaAnim(void *parent, s32 *st, f32 a, f32 b)
{
    *(f32 *)&st[3] = b;
    *(f32 *)&st[2] = a;
    if (st[0] == 0)
    {
        st[0] = 1;
        _gcCreateChildScriptObj(func_40055690, st, &rootPtn, 0x4000, 0, 4, D_401333F8, parent);
    }
    return;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0059__setNodeHPBIllegal", nico_weaponUpdateGeometry);

extern u8 D_401315A4[];

void *getBosstatusDispMode(void)
{
    return D_401315A4;
}

extern u8 D_401315A8[];

void *getBoneCollisionDebugMode(void)
{
    return D_401315A8;
}

u8 *GetCharacterClass(void *chara);
void *GetGeometryPointerObject(void *obj);
void CharaCtrlSetOutsideScriptCtrlStatus(void *obj, s32 status);

void SCRSetScriptKeyToWallObject(void *a, u32 *h)
{
    u8 *cls = GetCharacterClass(a);

    if (*(s32 *)(cls + 0xDB0) != 0)
    {
        void *o = GetGeometryPointerObject(cls + 0xDD0);

        if (o != 0)
        {
            u32 v = *h;
            s32 off = v & 0x3FFFF;
            u8 *t = off != 0 ? *(u8 **)((u8 *)h - off) : 0;
            u8 *p = (t != 0 && (s32)t != DldSysUndefSymbol) ? *(u8 **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(t + 8) + 0xC) : 0;

            CharaCtrlSetOutsideScriptCtrlStatus(o, *(s32 *)(p + 4));
        }
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0059__setNodeHPBIllegal", nico_optBoneParentScaleUpdateScript);

extern u8 gcGlobalVar[];
void *isysGetThisSubThread(void);
void UpdateLayoutClassPastSimpleGeometry(u8 *obj);
void UpdateLayoutClassParentGeometry(u8 *obj, s32 a, s32 b);
void UpdateLayoutClassSimpleGeometry(u8 *obj, f32 scale);
void FlushCollisionWork(void *th);
void scrRun(void);

void nico_updatescript(void)
{
    void *t = isysGetThisSubThread();
    u8 *l = GetLayoutClass(t);
    u8 *g = gcGlobalVar;

    for (;;)
    {
        UpdateLayoutClassPastSimpleGeometry(l);
        UpdateLayoutClassParentGeometry(l, 0, 0);
        UpdateLayoutClassSimpleGeometry(l, *(f32 *)(g + 0x184));
        FlushCollisionWork(t);
        scrRun();
    }
}

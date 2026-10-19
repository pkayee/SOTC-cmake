#include "common.h"

extern s32 D_4021E1E0;
extern s32 D_4021E1E4;
extern s32 DldSysUndefSymbol;

u8* getSCRDataCtrlWork();
u8* GetDamageClass(s32 a0);
s32 GetDamagerClassDamageSheetType(u8* damage);
u8* GetCharacterClass(s32 chr);
u8* GetLayoutClass(void);
s32 nico_GetCharacterAttackedFlag(s32 chr);
s32 nico_GetCharacterAttackedGPAttr(s32 chr, s32 attr);
s32 nico_GetPlayerCharacterRidingHorseObject(s32 chr);
s32 execCondition(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7);
s32 getTorchInfo(s32 a0);
s32 getPathExFinish(u8* work, s32 type);
s32 getWayFinish(u8* work);
s32 getPathStatus(u8* work);
s32 getPassageNum(u8* work);
s32 getPPointPasasgeNum(u8* work);
s32 getDPGroupID(s32 a0, s32 a1);
s32 changedGPIndex(s32 a0, u8* work, s32 a2);
s32 changedAPIndex(s32 a0, u8* work);
s32 changedDPGroupID(s32 a0, s32 a1, s32 a2, s32 a3);
void execPointListSort(u8* work, u8* list, s32 num);
s32 getNearPoint(u8* work, s32 a1, s32* a2, s32* a3, u8* list, s32 t1, s32 t2, s32 t3);
void GetGeometryPointerPosition(f32* out, u8* geo);
void SCRGetTargetPosXZDirOnMyCtrlGeo(f32* out, s32 a1, f32* out2);
s32 getLastPassagePointIdx(u8* work);
s32 getLastPassageAreaIdx(u8* work);
u8* getPointDataByAreaIdx(u8* work, s32 pi, s32 area);
u8* getPassageWork(u8* work, s32 idx);
s32 getNowPassagePointIdx(u8* work);
s32 getNowPassageAreaIdx(u8* work);
u8* getPlayerColCont2(s32 chr);
s32 ColCont2_IsParentObj(void* cont, void* obj);
s32 ColCont2_IsColStatus(void* cont, s32 a1, s32 a2);
s32 equipmentInvisibilityCloak(void);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", finishLoadMotList);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", setConditionResultBoss);

void setConditionResultBoss(s32 value)
{
    D_4021E1E0 = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", setConditionResultHorse);

void setConditionResultHorse(s32 value)
{
    D_4021E1E4 = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionResultBoss);

s32 SCRConditionResultBoss(void)
{
    return D_4021E1E0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionResultHorse);

s32 SCRConditionResultHorse(void)
{
    return D_4021E1E4;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionTrue);

s32 SCRConditionTrue(void)
{
    return 1;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionSubFunc);

s32 SCRConditionSubFunc(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8)
{
    return execCondition(a0, a8, a2, a3, a4, a5, a6, a7);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionAttacked);

s32 SCRConditionAttacked(s32 a0)
{
    return nico_GetCharacterAttackedFlag(a0);
}

s32 SCRConditionDamagedType(s32 a0, s32 a1, s32 a2, s32 a3, s32 sheetType)
{
    u8 *damage = GetDamageClass(a0);

    if (*(s32 *)damage == 1 && sheetType == GetDamagerClassDamageSheetType(damage))
    {
        return 1;
    }
    return 0;
}

s32 SCRConditionDamagedWeaponType(s32 a0, s32 type)
{
    u8 *damage = GetDamageClass(a0);

    if (damage != NULL && *(s32 *)damage == 3)
    {
        if (type == 1)
        {
            s32 result = 0;
            s32 weapon = *(s32 *)(damage + 0x60);
            if (weapon == 1 || weapon == 3)
            {
                result = 1;
            }
            return result;
        }
        if (type == 0)
        {
            s32 result = 0;
            s32 weapon = *(s32 *)(damage + 0x60);
            if (weapon == 5 || weapon == 0 || weapon == 2 || weapon == 4)
            {
                result = 1;
            }
            return result;
        }
        return type == *(s32 *)(damage + 0x60);
    }
    return 0;
}

/* NEARMISS-STUB SCRConditionDamagedColType */
#if 0 /* NEARMISS 92.14% cat=branch-layout sub=- | d2 r88: r = attr != 0; eq = attr == colType; if (colType != -1) r = eq; gets both setcc before the beq (target shape) but ifcvt turns the then-move into movn; t | attempts=2 */
s32 SCRConditionDamagedColType(s32 a0, s32 a1, s32 a2, s32 a3, s32 gpAttr, s32 colType)
{
    u8 *damage = GetDamageClass(a0);
    s32 attr;
    s32 r = 0;
    s32 eq;

    if (*(s32 *)damage != 0) {
        attr = nico_GetCharacterAttackedGPAttr(a0, gpAttr);
        r = attr != 0;
        eq = attr == colType;
        if (colType != -1) {
            r = eq;
        }
    }
    return r;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionDamagedColType);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionDamagedPosRight);

s32 SCRConditionDamagedPosRight(s32 a0)
{
    f32 vec[3];
    u8* damage = GetDamageClass(a0);
    if (*(s32*)damage == 0)
    {
        return 0;
    }
    GetGeometryPointerPosition(vec, damage + 0x10);
    SCRGetTargetPosXZDirOnMyCtrlGeo(vec, a0, vec);
    if (!(0.0f <= vec[0]))
    {
        return 0;
    }
    return 1;
}

s32 SCRConditionLastPassagePointEventID(void* o, s32 id)
{
    u8* w = getSCRDataCtrlWork();
    s32 pi = getLastPassagePointIdx(w);
    u8* p = getPointDataByAreaIdx(w, pi, getLastPassageAreaIdx(w));
    if (p != 0 && id == *(s16*)(p + 0x1C))
    {
        return 1;
    }
    return 0;
}

s32 SCRConditionNextPointEventID(u8* a, s32 id)
{
    u8* pt;
    u8* w = getSCRDataCtrlWork();
    u8* p = getPassageWork(w, 0);
    if (p != 0)
    {
        pt = getPointDataByAreaIdx(w, *(s16*)(p + 0x14), *(s32*)(p + 0x1C));
        if (pt != 0 && id == *(s16*)(pt + 0x1C))
        {
            return 1;
        }
    }
    return 0;
}

s32 SCRConditionNowPassagePointEventID(void* o, s32 id)
{
    u8* w = getSCRDataCtrlWork();
    s32 pi = getNowPassagePointIdx(w);
    u8* p = getPointDataByAreaIdx(w, pi, getNowPassageAreaIdx(w));
    if (p != 0 && id == *(s16*)(p + 0x1C))
    {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionNowPassagePointEventIDRange);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionCheckWayOrientAttainPlayer);

s32 SCRConditionCheckWayOrientAttainPlayer(void)
{
    u8* ctrl = getSCRDataCtrlWork();
    u8* list = ctrl + 0x2018;
    s32 a;
    s32 b;
    execPointListSort(ctrl, list, *(s32*)(*(u8**)(ctrl + 0x405C) + 0x134));
    return getNearPoint(ctrl, 0, &a, &b, list, *(s32*)(*(u8**)(ctrl + 0x405C) + 0x134), 1, 1);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionCheckAngleToNextPoint);

static inline s32* dldTable(s32* h)
{
    s32 off = *h & 0x3FFFF;

    return off != 0 ? *(s32**)((u8*)h - off) : 0;
}

static inline s32* dldObj(s32* h)
{
    s32* t = dldTable(h);

    return (t != 0 && (s32)t != DldSysUndefSymbol) ? (s32*)t[4] : 0;
}

s32 SCRConditionPlayerParentColAttr(void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32* h)
{
    u8* w = getSCRDataCtrlWork();
    s32* o = dldObj(h);
    s32 ok;
    s32 r;

    if (o != 0 && o[2] != 0)
    {
        ok = 0;
        if (ColCont2_IsParentObj(getPlayerColCont2(*(s32*)(w + 0x4058)), o))
            ok = 1;
    }
    else
    {
        ok = dldTable(h) == 0;
    }
    r = 0;
    if (ok)
        r = ColCont2_IsColStatus(getPlayerColCont2(*(s32*)(w + 0x4058)), e, f) != 0;
    return r;
}

s32 SCRConditionPlayerParentRangeColAttr(void* actor, s32 a1, s32 a2, s32 a3, long type, long from, long to)
{
    u8* w = getSCRDataCtrlWork();
    long step = 0x200000;
    long x;

    if (type != 0x1E00000)
    {
        step = 0x800000000000L;
        if (type != 0x3F800000000000L)
        {
            return 0;
        }
    }
    for (x = from; x <= to; x += step)
    {
        if (((s32 (*)(void*, long, long))ColCont2_IsColStatus)(getPlayerColCont2(*(s32*)(w + 0x4058)), type, x))
        {
            return 1;
        }
    }
    return 0;
}

s32 SCRConditionPlayerParentColAttrAndEquipmentCheck(void* actor, s32 a1, s32 a2, s32 a3, s32 type, s32 val, s32 a6, s32* h)
{
    u8* w;
    s32* t;
    s32* o;
    s32 ok;

    if (equipmentInvisibilityCloak())
    {
        return 0;
    }
    w = getSCRDataCtrlWork(actor);
    t = dldTable(h);
    o = (t != 0 && (s32)t != DldSysUndefSymbol) ? (s32*)t[4] : 0;
    if (o != 0 && o[2] != 0)
    {
        ok = 0;
        if (ColCont2_IsParentObj(getPlayerColCont2(*(s32*)(w + 0x4058)), o))
            ok = 1;
    }
    else
    {
        ok = dldTable(h) == 0;
    }
    if (!ok)
    {
        return 0;
    }
    return ColCont2_IsColStatus(getPlayerColCont2(*(s32*)(w + 0x4058)), type, val) != 0;
}

s32 SCRConditionPlayerParentRangeColAttrAndEquipmentCheck(void* actor, s32 a1, s32 a2, s32 a3, long type, long from, long to)
{
    u8* w;
    long step;
    long x;

    if (equipmentInvisibilityCloak())
    {
        return 0;
    }
    w = getSCRDataCtrlWork(actor);
    step = 0x200000;

    if (type != 0x1E00000)
    {
        step = 0x800000000000L;
        if (type != 0x3F800000000000L)
        {
            return 0;
        }
    }
    for (x = from; x <= to; x += step)
    {
        if (((s32 (*)(void*, long, long))ColCont2_IsColStatus)(getPlayerColCont2(*(s32*)(w + 0x4058)), type, x))
        {
            return 1;
        }
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionPlayerRidingHorse);

s32 SCRConditionPlayerRidingHorse(void)
{
    return nico_GetPlayerCharacterRidingHorseObject(*(s32*)(getSCRDataCtrlWork() + 0x4058)) != 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionPlayerWaterIn);

s32 SCRConditionPlayerWaterIn(void)
{
    u8* ctrl = getSCRDataCtrlWork();
    s32 obj = nico_GetPlayerCharacterRidingHorseObject(*(s32*)(ctrl + 0x4058));
    s32 chr = *(s32*)(ctrl + 0x4058);
    if (obj != 0)
    {
        chr = obj;
    }
    return *(s8*)(GetCharacterClass(chr) + 0x35E);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionDamagedPlayer);

s32 SCRConditionDamagedPlayer(void)
{
    return *(s32*)GetDamageClass(*(s32*)(getSCRDataCtrlWork() + 0x4058)) != 0;
}

s32 SCRConditionPlayerDamagedType(void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 i, u32* h)
{
    u8* dmg = GetDamageClass(*(s32*)(getSCRDataCtrlWork() + 0x4058));

    if (*(s32*)dmg == 1)
    {
        u32 v = *h;
        s32 off = v & 0x3FFFF;
        u8* t = off != 0 ? *(u8**)((u8*)h - off) : 0;
        u8* p = (t != 0 && (s32)t != DldSysUndefSymbol) ? *(u8**)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32*)(*(u8**)(t + 8) + 0xC) : 0;
        if (p == *(u8**)(dmg + 0x50))
        {
            return 1;
        }
    }
    return 0;
}

s32 SCRConditionMyselfParentColAttr(void* actor, s32 a1, s32 a2, s32 a3, s64 mask, s32 attr)
{
    u8* cls;

    if (*(s32*)(((u8* (*)(void*))GetLayoutClass)(actor) + 0x124) == 0)
    {
        return 0;
    }
    cls = GetCharacterClass((s32)actor);
    if (attr != -1)
        return attr == (*(s64*)(cls + 0x680) & mask);
    return (*(s64*)(cls + 0x680) & mask) != 0;
}

s32 SCRConditionGameObjParentColAttr(void* a, s32 b, s32 c, s32 d, long mask, s32 attr, s32 g, s32* h)
{
    s32 ooff = *h & 0x3FFFF;
    s32* ot = ooff != 0 ? *(s32**)((u8*)h - ooff) : 0;
    s32* o = (ot != 0 && (s32)ot != DldSysUndefSymbol) ? (s32*)ot[4] : 0;
    u8* cls;

    if (o != 0)
    {
        if (o[2] != 0)
        {
            if (*(s32*)(((u8* (*)(void*))GetLayoutClass)((void*)o[2]) + 0x124) != 0)
            {
                cls = GetCharacterClass(o[2]);
                if (attr != -1)
                    return attr == (*(long*)(cls + 0x680) & mask);
                return (*(long*)(cls + 0x680) & mask) != 0;
            }
        }
    }
    return 0;
}

s32 SCRConditionMyselfMotionCheck(void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 i, u32* h)
{
    u8* w = GetCharacterClass((s32)a) + 0x1C0;
    u32 v = *h;
    s32 off = v & 0x3FFFF;
    u8* t = off != 0 ? *(u8**)((u8*)h - off) : 0;
    u8* p = (t != 0 && (s32)t != DldSysUndefSymbol) ? *(u8**)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32*)(*(u8**)(t + 8) + 0xC) : 0;
    return p == *(u8**)w;
}

s32 SCRConditionMyselfMotionShiftCheck(void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 i, u32* h)
{
    s32 ret = 0;
    u8* w = GetCharacterClass((s32)a) + 0x1C0;
    u32 v = *h;
    s32 off = v & 0x3FFFF;
    u8* t = off != 0 ? *(u8**)((u8*)h - off) : 0;
    u8* p = (t != 0 && (s32)t != DldSysUndefSymbol) ? *(u8**)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32*)(*(u8**)(t + 8) + 0xC) : 0;
    if (p == *(u8**)w)
        ret = *(s8*)(GetCharacterClass((s32)a) + 0x35C) != 0;
    return ret;
}

s32 SCRConditionMyselfLastMotionShiftCheck(void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 i, u32* h)
{
    s32 ret = 0;
    u8* w = GetCharacterClass((s32)a) + 0x1C0;
    u32 v = *h;
    s32 off = v & 0x3FFFF;
    u8* t = off != 0 ? *(u8**)((u8*)h - off) : 0;
    u8* p = (t != 0 && (s32)t != DldSysUndefSymbol) ? *(u8**)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32*)(*(u8**)(t + 8) + 0xC) : 0;
    if (p == *(u8**)(w + 4))
        ret = *(s8*)(GetCharacterClass((s32)a) + 0x35C) != 0;
    return ret;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionMyselfAddMotionCheck);

s32 SCRConditionMyselfControlModeCheck(void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 i, u32* h)
{
    u32 v = *h;
    s32 off = v & 0x3FFFF;
    u8* t = off != 0 ? *(u8**)((u8*)h - off) : 0;
    u8* p = (t != 0 && (s32)t != DldSysUndefSymbol) ? *(u8**)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32*)(*(u8**)(t + 8) + 0xC) : 0;
    return p == *(u8**)(GetCharacterClass((s32)a) + 0x740);
}

s32 SCRConditionPlayerMotionCheck(void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 i, u32* h)
{
    u8* w = GetCharacterClass(*(s32*)(getSCRDataCtrlWork(a) + 0x4058)) + 0x1C0;
    u32 v = *h;
    s32 off = v & 0x3FFFF;
    u8* t = off != 0 ? *(u8**)((u8*)h - off) : 0;
    u8* p = (t != 0 && (s32)t != DldSysUndefSymbol) ? *(u8**)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32*)(*(u8**)(t + 8) + 0xC) : 0;
    return p == *(u8**)w;
}

s32 SCRConditionPlayerMotionShiftCheck(void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 i, u32* h)
{
    u8* w = getSCRDataCtrlWork(a);
    u8* m = GetCharacterClass(*(s32*)(w + 0x4058)) + 0x1C0;
    u32 v = *h;
    s32 off = v & 0x3FFFF;
    s32 ret = 0;
    u8* t = off != 0 ? *(u8**)((u8*)h - off) : 0;
    u8* p = (t != 0 && (s32)t != DldSysUndefSymbol) ? *(u8**)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32*)(*(u8**)(t + 8) + 0xC) : 0;
    if (p == *(u8**)m)
        ret = *(s8*)(GetCharacterClass(*(s32*)(w + 0x4058)) + 0x35C) != 0;
    return ret;
}

s32 SCRConditionPlayerLastMotionShiftCheck(void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 i, u32* h)
{
    u8* w = getSCRDataCtrlWork(a);
    u8* m = GetCharacterClass(*(s32*)(w + 0x4058)) + 0x1C0;
    u32 v = *h;
    s32 off = v & 0x3FFFF;
    s32 ret = 0;
    u8* t = off != 0 ? *(u8**)((u8*)h - off) : 0;
    u8* p = (t != 0 && (s32)t != DldSysUndefSymbol) ? *(u8**)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32*)(*(u8**)(t + 8) + 0xC) : 0;
    if (p == *(u8**)(m + 4))
        ret = *(s8*)(GetCharacterClass(*(s32*)(w + 0x4058)) + 0x35C) != 0;
    return ret;
}

s32 SCRConditionPlayerControlModeCheck(void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 i, u32* h)
{
    u8* w = getSCRDataCtrlWork(a);
    u32 v = *h;
    s32 off = v & 0x3FFFF;
    u8* t = off != 0 ? *(u8**)((u8*)h - off) : 0;
    u8* p = (t != 0 && (s32)t != DldSysUndefSymbol) ? *(u8**)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32*)(*(u8**)(t + 8) + 0xC) : 0;
    return p == *(u8**)(GetCharacterClass(*(s32*)(w + 0x4058)) + 0x740);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionMyselfOverGlobalY);

s32 SCRConditionMyselfOverGlobalY(f32 y)
{
    u8* layout = GetLayoutClass();
    u8* g = *(u8**)(layout + 0x134);
    if (y <= *(f32*)(g + 4))
    {
        return 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionMyselfLessGlobalY);

s32 SCRConditionMyselfLessGlobalY(f32 y)
{
    u8* layout = GetLayoutClass();
    u8* g = *(u8**)(layout + 0x134);
    if (*(f32*)(g + 4) <= y)
    {
        return 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionMyselfKeepHit);

s32 SCRConditionMyselfKeepHit(s32 a0)
{
    return *(s32*)(GetCharacterClass(a0) + 0xF50);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionPlayerTorch);

s32 SCRConditionPlayerTorch(void)
{
    return getTorchInfo(*(s32*)(getSCRDataCtrlWork() + 0x4058));
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionAPFinish);

s32 SCRConditionAPFinish(void)
{
    return getPathExFinish(getSCRDataCtrlWork(), 2);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionGPFinish);

s32 SCRConditionGPFinish(void)
{
    return getPathExFinish(getSCRDataCtrlWork(), 5);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionPPFinish);

s32 SCRConditionPPFinish(void)
{
    return getPathExFinish(getSCRDataCtrlWork(), 9);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionPPPassageNum);

s32 SCRConditionPPPassageNum(s32 a0, s32 a1)
{
    return a1 == getPPointPasasgeNum(getSCRDataCtrlWork());
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionGPChanged);

s32 SCRConditionGPChanged(s32 a0)
{
    u8* ctrl = getSCRDataCtrlWork();
    return changedGPIndex(a0, ctrl, *(s32*)(ctrl + 0x4058));
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionAPChanged);

s32 SCRConditionAPChanged(s32 a0)
{
    return changedAPIndex(a0, getSCRDataCtrlWork());
}

s32 SCRConditionDPGroupIDChanged(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 t3)
{
    u8* w = getSCRDataCtrlWork(a0);
    return changedDPGroupID(a0, (s32)w, getDPGroupID(a0, t3), -1);
}

s32 SCRConditionGPOrDPGroupIDChanged(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 t3)
{
    s32 ret = 0;
    u8* w = getSCRDataCtrlWork(a0);
    s32 id = getDPGroupID(a0, t3);

    if (changedGPIndex(a0, w, *(s32*)(w + 0x4058)) || changedDPGroupID(a0, (s32)w, id, -1))
        ret = 1;
    return ret;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionWayFinish);

s32 SCRConditionWayFinish(void)
{
    return getWayFinish(getSCRDataCtrlWork());
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionPathStatus);

s32 SCRConditionPathStatus(void)
{
    return getPathStatus(getSCRDataCtrlWork());
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionPathPassageNum);

s32 SCRConditionPathPassageNum(s32 a0, s32 a1)
{
    return a1 == getPassageNum(getSCRDataCtrlWork());
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionPlayerInSight);

s32 SCRConditionPlayerInSight(void)
{
    return *(s32*)(getSCRDataCtrlWork() + 0x403C);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionPlayerInLost);

s32 SCRConditionPlayerInLost(void)
{
    return *(s32*)(getSCRDataCtrlWork() + 0x403C) == 0;
}

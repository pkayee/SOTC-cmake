#include "common.h"

u8* getSCRDataCtrlWork(void);
s32 _gameFlagChk(s32 idx);
f32 getPlayerGrip(void);
f32 getPlayerHpRatio(void);
f32 getBossPartsLifeRatio(s32 a0, s32 a1);
f32 getHorseInterpSpeed(u8 *obj);
u8 *SCRGetFirstObj(u8 *list);
u8 *SCRGetBossWork(void);
s32 GetSwordFlareHitPlaneAttribute(void);
extern u8 gcGlobalVar[];
extern s32 DldSysUndefSymbol;
f32 getBossPartsCurDamage(s32 a0, s32 a1);

s32 SCRConditionInstantaneousPlayerInSight(void)
{
    return *(s64*)(getSCRDataCtrlWork() + 0x4040) != 0;
}

s32 SCRConditionOverDistanceToPlayerWorldXZ(f32 a0)
{
    return a0 <= *(f32 *)(getSCRDataCtrlWork() + 0x4060);
}

s32 SCRConditionLessDistanceToPlayerWorldXZ(f32 a0)
{
    return *(f32 *)(getSCRDataCtrlWork() + 0x4060) <= a0;
}

s32 SCRConditionOverDistanceToPlayerWorld(f32 a0)
{
    return a0 <= *(f32 *)(getSCRDataCtrlWork() + 0x4064);
}

s32 SCRConditionLessDistanceToPlayerWorld(f32 a0)
{
    return *(f32 *)(getSCRDataCtrlWork() + 0x4064) <= a0;
}

s32 SCRConditionAnglePlayerWorldXZ(f32 a0)
{
    return __builtin_fabsf(*(f32 *)(getSCRDataCtrlWork() + 0x4048)) <= a0 * 3.1415926f / 180.0f;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionRootAnglePlayerWorldXZ);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionLessDistanceToBossWorldXZ);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionOverDistanceToBossWorldXZ);

s32 SCRConditionModeLapsedTime(f32 a0)
{
    return a0 <= *(f32 *)(getSCRDataCtrlWork() + 0x4084);
}

s32 SCRConditionOrientLapsedTime(f32 a0)
{
    return a0 <= *(f32 *)(getSCRDataCtrlWork() + 0x4088);
}

s32 SCRConditionVolumeTime0(f32 a0)
{
    return a0 <= *(f32 *)(getSCRDataCtrlWork() + 0x408C);
}

s32 SCRConditionVolumeCheckForPlayerPos(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8)
{
    u8 buf[0x60];
    u8 *obj;
    s32 equipmentInvisibilityCloak(void);
    s32 CheckPositionInsideOfJudgeVolumeObject(u8 *a0, s32 a1, s32 a2, s32 a3);

    obj = *(u8 **)(getSCRDataCtrlWork() + 0x405C);
    if (equipmentInvisibilityCloak() != 0)
    {
        return 0;
    }
    return CheckPositionInsideOfJudgeVolumeObject(buf, a0, a8, *(s32 *)(obj + 0x134));
}

s32 SCRConditionVolumeCheckForPointPos(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8)
{
    u8 buf[0x60] __attribute__((aligned(16)));
    s128 pt;
    s32 r;
    s32 getPointDataFromEvent(u8 *a0, s32 a1, s128 *a2);
    s32 CheckPositionInsideOfJudgeVolumeObject(u8 *a0, s32 a1, s32 a2, s32 a3);

    r = getPointDataFromEvent(getSCRDataCtrlWork(), a1, &pt);
    if (r == 0)
    {
        return 0;
    }
    return CheckPositionInsideOfJudgeVolumeObject(buf, a0, a8, r);
}

static inline s32 *dldData(u32 *h)
{
    s32 off = *h & 0x3FFFF;
    s32 *t = off != 0 ? *(s32 **)((u8 *)h - off) : 0;

    return (t != 0 && (s32)t != DldSysUndefSymbol) ? (s32 *)t[4] : 0;
}

static inline u8 *dldResolve(u32 *h)
{
    u32 v = *h;
    s32 off = v & 0x3FFFF;
    s32 *t = off != 0 ? *(s32 **)((u8 *)h - off) : 0;

    return (t != 0 && (s32)t != DldSysUndefSymbol) ? (u8 *)t[4] + ((v >> 18) & 0xFFF) * ((s32 *)t[2])[3] : 0;
}

s32 SCRFuncVolumeCheckByGameObj(u8 *actor, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 *h, u32 *vh)
{
    u8 work[0x60];
    s128 pos;
    u8 *w;
    s32 *o;
    s32 equipmentInvisibilityCloak(void);
    s32 CheckPositionInsideOfJudgeVolumeObject(u8 *a0, s32 a1, s32 a2, s32 a3);

    w = getSCRDataCtrlWork();
    o = dldData(h);
    if (equipmentInvisibilityCloak())
    {
        return 0;
    }
    pos = **(s128 **)(*(u8 **)(w + 0x405C) + 0x134);
    if (o != 0)
    {
        void *vol = (void *)o[2];

        if (vol != 0 && dldResolve(vh) != 0 && CheckPositionInsideOfJudgeVolumeObject(work, (s32)vol, (s32)vh, (s32)&pos) != 0)
        {
            return 1;
        }
    }
    return 0;
}

s32 SCRFuncVolumeCheckByGameObjForSelfPos(u8 *actor, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 *h, u32 *vh)
{
    u8 work[0x60];
    s128 pos;
    s32 *o;
    u8 *GetLayoutClass(void *chara);
    s32 CheckPositionInsideOfJudgeVolumeObject(u8 *a0, s32 a1, s32 a2, s32 a3);

    o = dldData(h);
    pos = **(s128 **)(GetLayoutClass(actor) + 0x134);
    if (o != 0)
    {
        void *vol = (void *)o[2];

        if (vol != 0 && dldResolve(vh) != 0 && CheckPositionInsideOfJudgeVolumeObject(work, (s32)vol, (s32)vh, (s32)&pos) != 0)
        {
            return 1;
        }
    }
    return 0;
}

s32 SCRConditionHorseMotionCheck(u8 *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 i, u32 *h)
{
    u8 *obj;
    u8 *anim;
    u32 v;
    s32 off;
    u8 *t;
    u8 *p;
    u8 *GetAnimationClass(void *chara);

    obj = SCRGetFirstObj(gcGlobalVar + 0x2B4);
    if (obj == 0)
    {
        return 0;
    }
    anim = GetAnimationClass(obj);
    v = *h;
    off = v & 0x3FFFF;
    t = off != 0 ? *(u8 **)((u8 *)h - off) : 0;
    p = (t != 0 && (s32)t != DldSysUndefSymbol) ? *(u8 **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(t + 8) + 0xC) : 0;
    return p == *(u8 **)anim;
}

static inline s32 *dldObj(s32 *h)
{
    s32 off = *h & 0x3FFFF;
    s32 *t = off != 0 ? *(s32 **)((u8 *)h - off) : 0;

    return (t != 0 && (s32)t != DldSysUndefSymbol) ? (s32 *)t[4] : 0;
}

s32 SCRConditionMotionCheck(void *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 *h1, u32 *h2)
{
    s32 none;
    s32 *o = dldObj(h1);
    u8 *m;
    u8 *GetCharacterClass(void *chara);

    if (o == 0 || o[2] == 0)
    {
        return 0;
    }
    none = GetCharacterClass((void *)o[2]) == 0;
    if (none)
    {
        return 0;
    }
    m = GetCharacterClass((void *)o[2]) + 0x1C0;
    return dldResolve(h2) == *(u8 **)m;
}

s32 SCRConditionGameObjMotionShiftCheck(void *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 *h1, u32 *h2)
{
    s32 none;
    s32 *o = dldObj(h1);
    u8 *m;
    s32 ret;
    u8 *GetCharacterClass(void *chara);

    if (o == 0 || o[2] == 0)
    {
        return 0;
    }
    none = GetCharacterClass((void *)o[2]) == 0;
    if (none)
    {
        return 0;
    }
    m = GetCharacterClass((void *)o[2]) + 0x1C0;
    ret = 0;
    if (dldResolve(h2) == *(u8 **)(m + 0))
    {
        ret = *(s8 *)(GetCharacterClass((void *)o[2]) + 0x35C) != 0;
    }
    return ret;
}

s32 SCRConditionGameObjLastMotionShiftCheck(void *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 *h1, u32 *h2)
{
    s32 none;
    s32 *o = dldObj(h1);
    u8 *m;
    s32 ret;
    u8 *GetCharacterClass(void *chara);

    if (o == 0 || o[2] == 0)
    {
        return 0;
    }
    none = GetCharacterClass((void *)o[2]) == 0;
    if (none)
    {
        return 0;
    }
    m = GetCharacterClass((void *)o[2]) + 0x1C0;
    ret = 0;
    if (dldResolve(h2) == *(u8 **)(m + 4))
    {
        ret = *(s8 *)(GetCharacterClass((void *)o[2]) + 0x35C) != 0;
    }
    return ret;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionGameObjAddMotionCheck);

s32 SCRConditionHorseControlModeCheck(u8 *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 i, u32 *h)
{
    u8 *obj;
    u32 v;
    s32 off;
    u8 *t;
    u8 *p;
    u8 *GetCharacterClass(void *chara);

    obj = SCRGetFirstObj(gcGlobalVar + 0x2B4);
    if (obj == 0)
    {
        return 0;
    }
    v = *h;
    off = v & 0x3FFFF;
    t = off != 0 ? *(u8 **)((u8 *)h - off) : 0;
    p = (t != 0 && (s32)t != DldSysUndefSymbol) ? *(u8 **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(t + 8) + 0xC) : 0;
    return p == *(u8 **)(GetCharacterClass(obj) + 0x740);
}

s32 SCRConditionControlModeCheck(void *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 *h1, u32 *h2)
{
    s32 none;
    s32 *o = dldObj(h1);
    u8 *GetCharacterClass(void *chara);

    if (o == 0 || o[2] == 0)
    {
        return 0;
    }
    none = GetCharacterClass((void *)o[2]) == 0;
    if (none)
    {
        return 0;
    }
    return dldResolve(h2) == *(u8 **)(GetCharacterClass((void *)o[2]) + 0x740);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionGameFlagCheckByGameObj);

s32 SCRConditionGameFlagCheck(s32 a0, s32 a1)
{
    return _gameFlagChk(a1);
}

s32 SCRConditionAttackPassageTime(f32 a0)
{
    return a0 <= *(f32 *)(getSCRDataCtrlWork() + 0x40B0);
}

s32 SCRConditionOverMyselfLife(f32 a0)
{
    u8 *boss = SCRGetBossWork();

    return a0 <= (*(f32 *)(boss + 0x44) / *(f32 *)(boss + 0x40)) * 100.0f;
}

s32 SCRConditionLessMyselfLife(f32 a0)
{
    u8 *boss = SCRGetBossWork();

    return (*(f32 *)(boss + 0x44) / *(f32 *)(boss + 0x40)) * 100.0f <= a0;
}

s32 SCRConditionOverMyselfPartsLife(f32 a0, s32 a0i, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{
    return a0 <= getBossPartsLifeRatio(a0i, a5) * 100.0f;
}

s32 SCRConditionLessMyselfPartsLife(f32 a0, s32 a0i, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{
    return getBossPartsLifeRatio(a0i, a5) * 100.0f <= a0;
}

s32 SCRConditionMyselfPartsDamaged(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{
    return getBossPartsCurDamage(a0, a5) != 0.0f;
}

/* NEARMISS-STUB SCRConditionExecGazeToPlayer */
#if 0 /* NEARMISS 95.62% cat=regalloc sub=- | bnel polarity, v0/v1/a0 choice | attempts=1 */
s32 SCRConditionExecGazeToPlayer(s32 a0)
{
    u8 *gcw;
    u8 *p;
    u8 *chr;
    u8 *s2;
    s32 cmpA;
    s32 cmpB;
    u8 *GetCharacterClass(s32 a0);
    s32 getPassageNum(u8 *a0);

    gcw = getSCRDataCtrlWork();
    p = gcw + 0x3CA0;
    chr = GetCharacterClass(a0);
    s2 = *(u8 **)(chr + 0x1064);
    if (*(s32 *)(p + 0x14) != 0)
    {
        cmpB = *(s32 *)(p + 0x30);
        cmpA = *(s32 *)(gcw + 0x4058);
    }
    else
    {
        if (getPassageNum(gcw) >= 2)
        {
            return 0;
        }
        if (*(s32 *)(gcw + 0x39C) != 0)
        {
            return 0;
        }
        cmpB = *(s32 *)(gcw + 0x4058);
        cmpA = *(s32 *)(gcw + 0x94);
    }
    if (cmpA != cmpB)
    {
        return 0;
    }
    return *(s32 *)(s2 + 0x68);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionExecGazeToPlayer);

s32 SCRConditionOverPlayerLife(f32 a0)
{
    return a0 <= getPlayerHpRatio() * 100.0f;
}

s32 SCRConditionLessPlayerLife(f32 a0)
{
    return getPlayerHpRatio() * 100.0f <= a0;
}

s32 SCRConditionOverPlayerGrip(f32 a0)
{
    return a0 <= getPlayerGrip();
}

s32 SCRConditionLessPlayerGrip(f32 a0)
{
    return getPlayerGrip() <= a0;
}

/* NEARMISS-STUB SCRConditionBossCheck */
#if 0 /* NEARMISS 38.55% cat=regalloc sub=- | DLD link a7, call/schedule shape | attempts=1 */
s32 SCRConditionBossCheck(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 *a7)
{
    u8 *obj;
    u32 off;
    s32 slot;
    u8 *e;
    extern s32 DldSysUndefSymbol;

    obj = SCRGetFirstObj(gcGlobalVar + 0x2B8);
    off = *a7 & 0x3FFFF;
    if (off == 0)
    {
        slot = 0;
    }
    else
    {
        slot = *(s32 *)((u8 *)a7 - off);
    }
    if (slot == 0)
    {
        e = NULL;
    }
    else if (slot == DldSysUndefSymbol)
    {
        e = NULL;
    }
    else
    {
        e = *(u8 **)(slot + 0x10);
    }
    if (obj == NULL)
    {
        return 0;
    }
    if (e == NULL)
    {
        return 0;
    }
    return *(u8 **)(e + 8) == obj;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionBossCheck);

s32 SCRConditionOverRandomVal(f32 a0)
{
    return a0 <= *(f32 *)(getSCRDataCtrlWork() + 0x4094);
}

s32 SCRConditionLessRandomVal(f32 a0)
{
    return *(f32 *)(getSCRDataCtrlWork() + 0x4094) <= a0;
}

s32 SCRConditionLessHorseSpeed(f32 a0)
{
    u8 *obj;

    obj = SCRGetFirstObj(gcGlobalVar + 0x2B4);
    if (obj == NULL)
    {
        return 0;
    }
    return getHorseInterpSpeed(obj) <= a0;
}

s32 SCRConditionCheckGameObjLwsPlayMode(void *a, s32 mode, s32 c, s32 d, s32 e, s32 f, s32 g, s32 *h)
{
    u8 *GetScriptAnimationClass(void *chara);
    s32 off = *h & 0x3FFFF;
    s32 *t = off != 0 ? *(s32 **)((u8 *)h - off) : 0;
    s32 *o = (t != 0 && t != (s32 *)DldSysUndefSymbol) ? (s32 *)t[4] : 0;

    if (o != 0 && o[2] != 0)
    {
        return mode == *(s32 *)(GetScriptAnimationClass((void *)o[2]) + 0x344);
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionOverLengthXZPlayerFromGp);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionLessLengthXZPlayerFromGp);

s32 SCRConditionSwordFlareHitColAttr(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{
    if (a5 != -1)
    {
        return a5 == (GetSwordFlareHitPlaneAttribute() & a4);
    }
    return (GetSwordFlareHitPlaneAttribute() & a4) != 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionUnderWaterByBone);

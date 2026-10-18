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

/* NEARMISS-STUB SCRConditionVolumeCheckForPointPos */
#if 0 /* NEARMISS 95.37% cat=regalloc sub=- | v0 copied to v1 before a2 load | attempts=1 */
void SCRConditionVolumeCheckForPointPos(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8)
{
    u8 buf[0x60];
    u8 pos[0x10];
    s32 point;
    s32 getPointDataFromEvent(u8 *a0, s32 a1, u8 *a2);
    s32 CheckPositionInsideOfJudgeVolumeObject(u8 *a0, s32 a1, s32 a2, s32 a3);

    point = getPointDataFromEvent(getSCRDataCtrlWork(), a1, pos);
    if (point)
    {
        CheckPositionInsideOfJudgeVolumeObject(buf, a0, a8, point);
    }
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionVolumeCheckForPointPos);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRFuncVolumeCheckByGameObj);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRFuncVolumeCheckByGameObjForSelfPos);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionHorseMotionCheck);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionMotionCheck);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionGameObjMotionShiftCheck);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionGameObjLastMotionShiftCheck);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionGameObjAddMotionCheck);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionHorseControlModeCheck);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionControlModeCheck);

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

/* NEARMISS-STUB SCRConditionCheckGameObjLwsPlayMode */
#if 0 /* NEARMISS 76.57% cat=regalloc sub=- | DLD link a7, beql polarity | attempts=1 */
s32 SCRConditionCheckGameObjLwsPlayMode(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 *a7)
{
    u8 *e;
    u32 off;
    s32 slot;
    extern s32 DldSysUndefSymbol;
    u8 *GetScriptAnimationClass(void);

    off = *a7 & 0x3FFFF;
    if (off == 0)
    {
        slot = 0;
    }
    else
    {
        slot = *(s32 *)((u8 *)a7 - off);
    }
    if (slot != 0 && slot != DldSysUndefSymbol)
    {
        e = *(u8 **)(slot + 0x10);
    }
    else
    {
        e = NULL;
    }
    if (e == NULL)
    {
        return 0;
    }
    if (*(u8 **)(e + 8) == NULL)
    {
        return 0;
    }
    return a1 == *(s32 *)(GetScriptAnimationClass() + 0x344);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0228_SCRConditionInstantaneousPlayerInSight", SCRConditionCheckGameObjLwsPlayMode);

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

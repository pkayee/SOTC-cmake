#include "common.h"

void bossStatStartDemo(void);

void SCRFuncBootBoss(void)
{
    bossStatStartDemo();
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0223_SCRFuncBootBoss", SCRFuncSetGameFlagByGameObj);

void _gameFlagSet(s32 idx);

void SCRFuncSetGameFlag(s32 unused, s32 idx)
{
    _gameFlagSet(idx);
}

s32 _gameFlagCls(s32 idx);

void SCRFuncClsGameFlag(s32 unused, s32 idx)
{
    _gameFlagCls(idx);
}

void SCRSetCharaMotionPlaySpeedRatio(s32 a0, s32 a1);

void SCRFuncSetMyselfMotionSpeedRatio(s32 a0, s32 a1)
{
    SCRSetCharaMotionPlaySpeedRatio(a0, a1);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0223_SCRFuncBootBoss", SCRFuncSetAttakIKPosForMotionCheck);

void *getSCRDataCtrlWork(void);

void SCRFuncParentRelateInit(void)
{
    s32 *p = (s32 *)((u8 *)getSCRDataCtrlWork() + 0x40B8);

    p[0] = 0;
    p[1] = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0223_SCRFuncBootBoss", SCRFuncParentRelateMain);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0223_SCRFuncBootBoss", SCRFuncSetGeoAndSendKey);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0223_SCRFuncBootBoss", SCRFuncCheckColAndSendKey);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0223_SCRFuncBootBoss", SCRFuncSetAttainForPreParallelTrans);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0223_SCRFuncBootBoss", SCRFuncSetAttainForParallelTrans);

s32 getHitPosWayCollision(f32 value, void *work, s32 *pos, s32 arg);
void setAttainmentPos(void *work, s32 *pos);

void SCRFuncSetAttainHitPosByWayCollision(f32 value)
{
    u8 *work = (u8 *)getSCRDataCtrlWork();
    s32 pos[4];

    if (getHitPosWayCollision(value, work, pos, *(s32 *)(*(u8 **)(work + 0x405C) + 0x134)) != 0)
    {
        setAttainmentPos(work, pos);
    }
}

s32 getPointPosFromEvent(void *work, s32 eventId, s32 *pos);
void setAttainmentPos(void *work, s32 *pos);

void SCRFuncSetAttainPointPosForEventID(s32 a0, s32 eventId)
{
    s32 pos[4];
    void *work = getSCRDataCtrlWork();

    if (getPointPosFromEvent(work, eventId, pos) != 0)
    {
        setAttainmentPos(work, pos);
    }
}

void SCRFuncSetAngryValue(f32 value)
{
    u8 *work = (u8 *)getSCRDataCtrlWork();

    *(f32 *)(work + 0x40D8) = value;
}

void SCRFuncAddAngryValue(f32 value)
{
    u8 *work = (u8 *)getSCRDataCtrlWork();

    *(f32 *)(work + 0x40D8) = *(f32 *)(work + 0x40D8) + value;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0223_SCRFuncBootBoss", SCRFuncSetOrientCheckWork);

void GAMEUTIL_set_auto_get_flag_boss_interest_position(s32 flag);

void SCRFuncSetAutoBossGazePos(void)
{
    GAMEUTIL_set_auto_get_flag_boss_interest_position(1);
}

void forceSetPerceptionWork(void *obj, void *work);

void SCRFuncForceSetPerceptionWork(void *obj)
{
    u8 *work = (u8 *)getSCRDataCtrlWork();

    forceSetPerceptionWork(obj, work + 0x4010);
}

void forceRenewLastPosPerceptionWork(void *obj, void *work);

void SCRFuncForceRenewLastPos(void *obj)
{
    u8 *work = (u8 *)getSCRDataCtrlWork();

    forceRenewLastPosPerceptionWork(obj, work + 0x4010);
}

void resetVelocityWormCtrlWork(s32 a0, u8 *work);

void SCRFuncResetWormCtrlParam(s32 a0)
{
    u8 *work = (u8 *)getSCRDataCtrlWork();

    if (*(s32 *)(work + 0x4070) == 3)
    {
        resetVelocityWormCtrlWork(a0, work + 0x3CF0);
    }
}

void setRotColCheckWormCtrlWork(u8 *work, s32 a1);

void SCRFuncSetRotColCheckWormCtrlParam(s32 a0, s32 a1)
{
    u8 *work = (u8 *)getSCRDataCtrlWork();

    if (*(s32 *)(work + 0x4070) == 3)
    {
        setRotColCheckWormCtrlWork(work + 0x3CF0, a1);
    }
}

void setAttainSpeedWormCtrlWork(u8 *work, f32 speed);
void setAcceleParamWormCtrlWork(u8 *work, f32 a, f32 b);

void SCRFuncSetAcceleParamWormCtrlParam(f32 p1, f32 p2, f32 p3)
{
    u8 *work = (u8 *)getSCRDataCtrlWork();

    if (*(s32 *)(work + 0x4070) == 3)
    {
        setAttainSpeedWormCtrlWork(work + 0x3CF0, p1);
        setAcceleParamWormCtrlWork(work + 0x3CF0, p2, p3);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0223_SCRFuncBootBoss", SCRFuncResetAcceleParamWormCtrlParam);

void setSearchRadius(u8 *work, f32 radius);

void SCRFuncSetSearchRadius(f32 radius)
{
    u8 *work = (u8 *)getSCRDataCtrlWork();

    setSearchRadius(work, radius);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0223_SCRFuncBootBoss", SCRFuncResetSearchRadius);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0223_SCRFuncBootBoss", SCRFuncSetSpeedByHorseForWormCtrl);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0223_SCRFuncBootBoss", SCRFuncSetDistByHorseForWormCtrl);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0223_SCRFuncBootBoss", SCRFuncSetAttainPosForEscapeToPlayer);

void stagemanager_loadstageByStrptrWithTargetObjectAreaCenter(s32 strptr, s32 a1);

void SCRFuncSegmentLoadRequestByMyself(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 strptr)
{
    if (stagemanager_checkstageAlreadyLoadRequestedByStrptr(strptr) == 0)
    {
        stagemanager_loadstageByStrptrWithTargetObjectAreaCenter(strptr, a0);
    }
}

s32 stagemanager_checkstageAlreadyLoadRequestedByStrptr(s32 strptr);
void stagemanager_unloadstageByStrptr(s32 strptr);

void SCRFuncSegmentUnloadRequest(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 strptr)
{
    if (stagemanager_checkstageAlreadyLoadRequestedByStrptr(strptr) != 0)
    {
        stagemanager_unloadstageByStrptr(strptr);
    }
}

void setLoadingCheckFunc(s32 (*func)(s32), s32 strptr);

void SCRFuncSegmentLoadWait(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 strptr)
{
    if (stagemanager_checkstageAlreadyLoadRequestedByStrptr(strptr) == 0)
    {
        setLoadingCheckFunc(stagemanager_checkstageAlreadyLoadRequestedByStrptr, strptr);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0223_SCRFuncBootBoss", SCRFuncSetPerceptionParam);

s32 stagemanager_getSegmentVariation(s32 a0);
void stagemanager_changeSegmentVariation(s32 a0);

void SCRFuncChangeSegmentVariation(s32 a0, s32 a1)
{
    if (a1 != stagemanager_getSegmentVariation(a0))
    {
        stagemanager_changeSegmentVariation(a1);
    }
}

extern u8 gcGlobalVar[];
void player_SetGripDamage(s32 unused, f32 value);

void SCRFuncSetGripDamage(f32 scale)
{
    u8 *work = (u8 *)getSCRDataCtrlWork();

    player_SetGripDamage(*(s32 *)(work + 0x4058), scale * *(f32 *)(gcGlobalVar + 0x180));
}

void setPassageRangeData(u8 *work, f32 a, f32 b);

void SCRFuncSetPassageRangeData(f32 a, f32 b)
{
    u8 *work = (u8 *)getSCRDataCtrlWork();

    setPassageRangeData(work, a, b);
}

#include "common.h"

extern s32 D_4021E1E0;
extern s32 D_4021E1E4;

u8* getSCRDataCtrlWork(void);
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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionDamagedWeaponType);

/* NEARMISS-STUB SCRConditionDamagedColType */
#if 0 /* NEARMISS 88.57% cat=cse-hoist sub=- | target computes attr!=0 before colType==-1 and reuses | attempts=1 */
s32 SCRConditionDamagedColType(s32 a0, s32 a1, s32 a2, s32 a3, s32 gpAttr, s32 colType)
{
    u8* damage = GetDamageClass(a0);
    s32 attr;
    if (*(s32*)damage == 0)
    {
        return 0;
    }
    attr = nico_GetCharacterAttackedGPAttr(a0, gpAttr);
    if (colType == -1)
    {
        return attr != 0;
    }
    return attr == colType;
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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionLastPassagePointEventID);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionNextPointEventID);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionNowPassagePointEventID);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionPlayerParentColAttr);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionPlayerParentRangeColAttr);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionPlayerParentColAttrAndEquipmentCheck);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionPlayerParentRangeColAttrAndEquipmentCheck);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionPlayerDamagedType);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionMyselfParentColAttr);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionGameObjParentColAttr);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionMyselfMotionCheck);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionMyselfMotionShiftCheck);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionMyselfLastMotionShiftCheck);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionMyselfAddMotionCheck);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionMyselfControlModeCheck);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionPlayerMotionCheck);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionPlayerMotionShiftCheck);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionPlayerLastMotionShiftCheck);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionPlayerControlModeCheck);

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

/* NEARMISS-STUB SCRConditionDPGroupIDChanged */
#if 0 /* NEARMISS 84.0% cat=cse-hoist sub=- | target copies getDPGroupID result to s2, a2 from v0; we CSE into a1 | attempts=1 */
s32 SCRConditionDPGroupIDChanged(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 t3)
{
    s32 group;
    getSCRDataCtrlWork();
    group = getDPGroupID(a0, t3);
    return changedDPGroupID(a0, group, group, -1);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionDPGroupIDChanged);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0227_finishLoadMotList", SCRConditionGPOrDPGroupIDChanged);

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

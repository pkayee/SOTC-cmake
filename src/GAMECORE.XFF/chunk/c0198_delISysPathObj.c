#include "common.h"

void delISysPathObj(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setBossPathColiGroup);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setHorsePathColiGroup);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getPathColiGroup);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getPathColiGroupByType);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getAimPosFromPathManager);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getPassageWork);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getPassageNum);
s32 getPassageNum(u8* work)
{
    return *(s32*)(work + 0x380);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", deletePassageWork);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setDataHeaderFromAreaIdx);
s32 setDataHeaderFromAreaIdx(u8* work, s32 areaIdx)
{
    return 1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", resetUserPathWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setRealColJudgeFunc);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getRealColJudgeFunc);
s32 getRealColJudgeFunc(u8* work)
{
    return *(s32*)(work + 0x3C34);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setLockPassageWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setStabilizeYPathWork);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setAngleStabilizeYPathWork);
void setAngleStabilizeYPathWork(u8* work, s32 value)
{
    *(s32*)(work + 0xEC) = value;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setRayByRealColPathWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setPassageWideRayPathWork);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setExecRayChkPathWork);
void setExecRayChkPathWork(u8* work, s32 value)
{
    *(s32*)(work + 0x384) = value;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setRayCutPassageWork);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setForceRouteAttrPathWork);
void setForceRouteAttrPathWork(u8* work, s32 value)
{
    *(s32*)(work + 0x38C) = value;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setRouteColCheckPathWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setRouteLockPathWork);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setFollowModePathWork);
void setFollowModePathWork(u8* work, s32 value)
{
    *(s32*)(work + 0x398) = value;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setPassageCallBack);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", deleteUserPathWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setUserPathMode);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setPassageRangeData);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setAttainRangeData);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setAttainRangeStruct);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setTmpBasePos);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setCreateTempAttain);
void setCreateTempAttain(u8* work, s32 value)
{
    *(s32*)(work + 0x3F4) = value;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setAttainmentPos);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setAttainmentObj);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setAttainmentPosAndDirPos);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setAttainmentPosAndDir);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setAttainmentPosAndDirAndLock);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setAttainmentObjAndDir);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setAttainmentObjAndOffset);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setAttainModePathWork);
void setAttainModePathWork(u8* work, s32 value)
{
    *(s32*)(work + 0xE0) = value;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setAttainRadPathWork);
void setAttainRadPathWork(u8* work, f32 rad)
{
    *(f32*)(work + 0xE4) = rad;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getPathInfo);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getWayFinish);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getPathStatus);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", useTempAttain);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getWayForRoute);
s32 getWayForRoute(u8* work)
{
    return *(s32*)(work + 0x3EC);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getLastAttainUpdate);
s32 getLastAttainUpdate(u8* work)
{
    return *(s32*)(work + 0x90);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getLastPassagePointIdx);
s32 getLastPassagePointIdx(u8* work)
{
    return *(s32*)(work + 0x404);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getLastPassageAreaIdx);
s32 getLastPassageAreaIdx(u8* work)
{
    return *(s32*)(work + 0x408);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getNowPassagePointIdx);
s32 getNowPassagePointIdx(u8* work)
{
    return *(s32*)(work + 0x40C);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", getNowPassageAreaIdx);
s32 getNowPassageAreaIdx(u8* work)
{
    return *(s32*)(work + 0x410);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setRouteMinAngle);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setSearchRouteMaxAngle);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setSearchRadius);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setPathRayWideParam);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", setEventLineAttr);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0198_delISysPathObj", unsetEventLineAttr);

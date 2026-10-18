#include "common.h"

static inline u8 *chrClass(u8 *obj)
{
    switch (obj[8])
    {
        case 9:
            return obj + 0x90;
        case 0x16:
            return obj + 0x90;
        default:
            return NULL;
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", getClothGeometry);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", GetCharacterClass);

u8 *GetCharacterClass(u8 *obj)
{
    switch (obj[8])
    {
        case 9:
            return obj + 0x90;
        case 0x16:
            return obj + 0x90;
        default:
            return NULL;
    }
}

void charrootdyn_resetHColFindFlag();
void charrootdyn_resetVColFindFlag();
void charrootdyn_resetVColEdgeFindFlag();
void charrootdyn_resetChainFindStatus();
void charrootdyn_resetkeepcolhitstatus();
void ReleaseCollisionFinder();
void ReleaseCollisionEdgeLinkDB();
void FlushLayoutObj();
void FlushJudgeVolumeObj();

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", FlushCharacterObj);
void FlushCharacterObj(u8 *obj)
{
    u8 *cc = chrClass(obj);

    charrootdyn_resetHColFindFlag(cc);
    charrootdyn_resetVColFindFlag(cc);
    charrootdyn_resetVColEdgeFindFlag(cc);
    charrootdyn_resetChainFindStatus(cc);
    charrootdyn_resetkeepcolhitstatus(cc);
    ReleaseCollisionFinder(cc + 0xD90);
    ReleaseCollisionEdgeLinkDB(cc + 0xDAC);
    FlushLayoutObj(obj);
    FlushJudgeVolumeObj(obj);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", ExecCharaGeometryPreprocess);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", ExecCharaGeometryPostprocess);
void SetCharacterObjDemoCutFinishFlag();

void ExecCharaGeometryPostprocess(u8 *obj)
{
    u8 *cc = chrClass(obj);
    u8 *p;

    if (*(u8 **)(cc + 0x19C) != NULL)
    {
        (*(u8 **)(cc + 0x19C))[0x8C] = 0;
    }
    if (*(s8 *)(cc + 0x1000) != 0)
    {
        SetCharacterObjDemoCutFinishFlag(obj, 0);
        p = *(u8 **)(cc + 0x19C);
        if (p != NULL)
        {
            p[0x8C] = 1;
        }
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", GetCharacterClassInitParamNbNodes);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", GetCharacterClassInitParamNbOptionNodes);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", GetCharacterClassBaseQ);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", GetCharacterClassMotionTopDirection);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", GetCharacterClassControlFrontDirection);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", GetCharacterClassMotionFrontDirection);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", GetCharacterClassControlDirection);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", GetCharacterClassIKNodeBooleanInfo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", GetCharacterClassOptionNodeLocalQuaternionPos);

void isysDeleteGroupAllObj();

void ResetCharacterClassCtrlRelationInfos(u8 *a)
{
    isysDeleteGroupAllObj(a + 0x103C);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", ResetCharacterClassFallDownInfo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", ResetCharacterClassIKInfo);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", ResetCharacterClassWaterStatus);

void ResetCharacterClassWaterStatus(u8 *a)
{
    a[0x35D] = 0;
    a[0x35E] = 0;
    *(u32 *)(a + 0x1024) = 0;
    *(u32 *)(a + 0x1020) = 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", ReleaseCharacterClassMotSyncAnimForceDeleteGroupWithMotChange);
u8 *isysGroupForFirst();
u8 *isysGroupForNext();
void isysRequestDeleteObj();
void isysGroupForExit();
void isysDeleteGroupAllObj();

void ReleaseCharacterClassMotSyncAnimForceDeleteGroupWithMotChange(u8 *obj)
{
    u8 *cc = chrClass(obj);
    u8 *grp = cc + 0xD06;
    u8 *node;
    u8 *last = NULL;

    node = isysGroupForFirst(grp, 0);
    if (node != NULL)
    {
        last = *(u8 **)node;
        for (;;)
        {
            isysRequestDeleteObj(last);
            node = isysGroupForNext(node, 0);
            if (node == NULL)
            {
                break;
            }
            last = *(u8 **)node;
        }
    }
    if (last != NULL)
    {
        isysGroupForExit(last, 0);
    }
    isysDeleteGroupAllObj(grp);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", ReleaseCharacterClassAddMotSyncAnim);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", DebugResetCharacterObjControlTarget);
void ChangeCharacterObjControlTarget();
void CopyGeometryPointer();

void DebugResetCharacterObjControlTarget(u8 *obj1, u8 *obj2)
{
    u8 *cc1 = chrClass(obj1);
    u8 *cc2 = chrClass(obj2);
    u8 *ctl = *(u8 **)(cc1 + 0x940);

    *(u8 **)(chrClass(ctl) + 0x950) = ctl;
    ChangeCharacterObjControlTarget(obj1, obj2);
    *(u8 **)(cc2 + 0x950) = obj1;
    if (obj1 == obj2)
    {
        return;
    }
    cc2[0x9B5] = 1;
    CopyGeometryPointer(cc2 + 0x960, cc1 + 0xC0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", UpdateCharacterClassGeometry);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0059_getClothGeometry", UpdateCharacterClassPastGeometry);

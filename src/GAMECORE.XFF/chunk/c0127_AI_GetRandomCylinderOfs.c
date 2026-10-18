#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", AI_GetRandomCylinderOfs);

void AI_GetNegaVector(void *arg0, void *arg1)
{
    (*(float *)((char *)(arg0) + 0)) = (float) -(*(float *)((char *)(arg1) + 0));
    (*(float *)((char *)(arg0) + 4)) = (float) -(*(float *)((char *)(arg1) + 4));
    (*(float *)((char *)(arg0) + 8)) = (float) -(*(float *)((char *)(arg1) + 8));
    (*(float *)((char *)(arg0) + 0xC)) = (float) (*(float *)((char *)(arg1) + 0xC));
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", AI_CheckDamage_Bow);

u8 *GetDamageClass(s32 a0);
s32 GetDamagerClassDamageSheetType(u8 *damage);

static inline s32 checkDamage(void *obj, s32 type)
{
    u8 *d = GetDamageClass((s32)obj);

    if ((d != 0) & (*(s32 *)d == 1)) {
        if (GetDamagerClassDamageSheetType(d) == type) {
            return 1;
        }
    }
    return 0;
}

s32 AI_CheckDamage_Impact(void *a, void *obj)
{
    return checkDamage(obj, 4);
}

s32 AI_CheckDamage_Sword(void *a, void *obj)
{
    return checkDamage(obj, 0x1D);
}

s32 AI_CheckDamage_Reaction(void *a, void *obj)
{
    return checkDamage(obj, 0x1C);
}

u8 *GetCharacterClass(void *chara);

s32 AI_JudgeNotCharaObjFunc(void *actor)
{
    return GetCharacterClass(actor) == 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", AI_JudgeColAttrFunc);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", AI_CheckViewInCameraClipVolume);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", AI_GetQuaternionNodeDirTargetExt);

extern u8 gcGlobalVar[];
u8 *GetLayoutClass(void *chara);
u8 *SCRGetFirstObj(void *table);
u8 *GetGeometryPointerObject(void *g);

s32 AI_CheckHorseParent(void *o)
{
    u8 *l = GetLayoutClass(o);
    u8 *h = SCRGetFirstObj(gcGlobalVar + 0x2B4);

    if (h == 0) {
        return 0;
    }
    return GetGeometryPointerObject(l + 0xC0) == h;
}

void AI_DebugDir(void) {
}

void AI_DebugArrow(void) {
}

void AI_DebugCylinder(void) {
}

s32 AIDebug_GetFirstObjOfMyGroup(void)
{
    return 0;
}

s32 AIDebug_GetAnimalMode(void)
{
    return 0;
}

s32 AIDebug_CheckPlayerParent(void)
{
    return 0;
}

s32 AIDebug_SetID(void)
{
    return 0;
}

s32 AIDebug_GetAnimalDispType(void)
{
    return 0;
}

s32 AIDebug_GetAnimalDispID(void)
{
    return 0;
}

s32 AIDebug_GetAdvertiseLoopFlag(void)
{
    return 0;
}

s32 AIDebug_GetAdvertisePauseFlag(void)
{
    return 0;
}

void AIDebug_SetAdvertisePauseFlag(void) {
}

s32 getDebugAdvertiseLoopFlag(void)
{
    return 0;
}

s32 getDebugAnimalMode(void)
{
    return 0;
}

s32 getDebugAnimalDispType(void)
{
    return 0;
}

s32 getDebugAnimalDispID(void)
{
    return 0;
}

void AIDebug_AdvertisePauseKey(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", AI_GetYRotQuaternionFromVector);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", func_400AAB60);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", func_400AACE0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", func_400AAEB8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", func_400AB0A8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", func_400AB2E8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", func_400AB3E8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", func_400AB5D0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", func_400ABA00);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", func_400ABB28);

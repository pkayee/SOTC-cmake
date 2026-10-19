#include "common.h"

extern s64 *GetCollisionDBAttributeAdr(void);

void *isysGetThisSubThread();

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", AI_GetRandomCylinderOfs);

void AI_GetNegaVector(void *arg0, void *arg1)
{
    (*(float *)((char *)(arg0) + 0)) = (float) -(*(float *)((char *)(arg1) + 0));
    (*(float *)((char *)(arg0) + 4)) = (float) -(*(float *)((char *)(arg1) + 4));
    (*(float *)((char *)(arg0) + 8)) = (float) -(*(float *)((char *)(arg1) + 8));
    (*(float *)((char *)(arg0) + 0xC)) = (float) (*(float *)((char *)(arg1) + 0xC));
}

u8 *GetDamageClass(s32 a0);

s32 AI_CheckDamage_Bow(void *a, void *obj)
{
    u8 *d = GetDamageClass((s32)obj);

    if ((d != 0) && (*(s32 *)d == 3)) {
        return *(s32 *)(d + 0x60) == 1;
    }
    return 0;
}

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

s32 AI_JudgeColAttrFunc(void)
{
    u64 attr = *(u64 *)GetCollisionDBAttributeAdr();
    u64 hi = attr & 0xF80000000LL;
    u64 lo = attr & 0x7C00;

    if (hi == 0x200000000LL || hi == 0x300000000LL || hi == 0x500000000LL || hi == 0xB80000000LL) {
        return 0;
    }
    if (lo == 0x3C00 || lo == 0x4000 || lo == 0x4400 || lo == 0x4C00 || lo == 0x5400 || lo == 0x5C00 ||
        lo == 0x6400 || lo == 0x6C00 || lo == 0x7400 || lo == 0x7C00) {
        return 0;
    }
    return 1;
}

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

void func_400AB2E8(u8 *o)
{
    s32 t;
    s32 v;

    isysGetThisSubThread();
    t = *(s32 *)(o + 0x1A0);
    *(s32 *)(o + 0x1B0) = 0;
    switch (t) {
    case 0:
        if (*(s32 *)(o + 0x190) == 0xC) {
            *(s32 *)(o + 0x1B0) = 1;
            *(s32 *)(o + 0x19C) = 0;
        }
        break;
    case 1:
        if (*(s32 *)(o + 0x190) == 0xD) {
            *(s32 *)(o + 0x19C) = 1;
            *(s32 *)(o + 0x1B0) = 1;
        }
        break;
    case 2:
        if (*(s32 *)(o + 0x190) == 0xD) {
            *(s32 *)(o + 0x19C) = t;
            *(s32 *)(o + 0x1B0) = 1;
        }
        break;
    case 3:
        if (*(s32 *)(o + 0x190) == 0xD) {
            *(s32 *)(o + 0x19C) = t;
            *(s32 *)(o + 0x1B0) = 1;
        }
        break;
    }
    v = *(s32 *)(o + 0x1A4);
    if (v != 5) {
        if (v < 6) {
            if (v != 4) {
                return;
            }
        } else if (v != 6) {
            return;
        }
    }
    *(s32 *)(o + 0x19C) = v;
    *(s32 *)(o + 0x1B0) = 1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", func_400AB3E8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", func_400AB5D0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", func_400ABA00);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0127_AI_GetRandomCylinderOfs", func_400ABB28);

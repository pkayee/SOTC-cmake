#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0050_nico_IK_legCalcAndSetUpper", nico_IK_legCalcAndSetUpper);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0050_nico_IK_legCalcAndSetUpper", nico_IK_legSetLower);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0050_nico_IK_legCalcAndSetUpper", nico_IK_legSetLowerFit);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0050_nico_IK_legCalcAndSetUpper", nico_neckFitToParentInvDirIK);

u64 *GetCollisionDBAttributeAdr(void *surface);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0050_nico_IK_legCalcAndSetUpper", character_ikcolattrfilter);
s32 character_ikcolattrfilter(void *surface)
{
    u64 attribute = *GetCollisionDBAttributeAdr(surface);
    u64 material = attribute & 0x7C000000UL;
    u64 flags = attribute & (0xF800UL << 20);
    u64 mode = attribute & (0xF000UL << 30);

    if (material == 0x30000000UL || material == 0x04000000UL || material == 0x64000000UL ||
        material == 0x68000000UL || material == 0x6C000000UL)
    {
        return 0;
    }
    if (material == 0x24000000UL || flags == (0x8000UL << 20) || flags == (0x8000UL << 18) ||
        flags == (0xB800UL << 20) || flags == (0xC000UL << 18) || flags == (0xA000UL << 19) ||
        flags == (0xE000UL << 18) || flags == (0xA000UL << 18) || mode == (0x8000UL << 28))
    {
        return 0;
    }
    return 1;
}

extern int GetCharacterClassInitParamNbOptionNodes();

int getPinAttackIKWorkSize(void)
{
    return GetCharacterClassInitParamNbOptionNodes() << 6;
}

typedef struct {
    s128 q;
} Vec4;

typedef struct {
    Vec4 pos;
    Vec4 dir;
    Vec4 target;
    int node;
    float time;
    float weight;
    int flag;
} PinAttackIK;

extern void *GetCharacterClass(void *);
extern Vec4 ZeroPoint;
extern Vec4 ZeroVector;

void initPinAttackIKWork(void *arg0, void *arg1, PinAttackIK *ik)
{
    int n = *(int *)(*(char **)((char *)GetCharacterClass(arg0) + 0x354) + 0x20);
    int i;

    for (i = 0; i < n; i++) {
        ik->pos = ZeroPoint;
        ik->dir = ZeroVector;
        ik->weight = -1.0f;
        ik->time = -1.0f;
        ik->node = -1;
        ik->flag = 0;
        ik->target = ZeroPoint;
        ik++;
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0050_nico_IK_legCalcAndSetUpper", SCRSetCharacterObjPinAttackIKTargetInfo);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0050_nico_IK_legCalcAndSetUpper", func_4004EE18);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0050_nico_IK_legCalcAndSetUpper", GetVolumeClippedTargetPos);

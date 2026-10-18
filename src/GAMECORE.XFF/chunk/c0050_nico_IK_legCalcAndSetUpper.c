#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0050_nico_IK_legCalcAndSetUpper", nico_IK_legCalcAndSetUpper);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0050_nico_IK_legCalcAndSetUpper", nico_IK_legSetLower);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0050_nico_IK_legCalcAndSetUpper", nico_IK_legSetLowerFit);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0050_nico_IK_legCalcAndSetUpper", nico_neckFitToParentInvDirIK);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0050_nico_IK_legCalcAndSetUpper", character_ikcolattrfilter);

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

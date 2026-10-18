#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0232_createPerceptionWork", createPerceptionWork);

void setPerceptionParam(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x40)) = arg1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0232_createPerceptionWork", perceptionExec2);

union PerceptionVector {
    s128 q;
    float f[4];
    int words[4];
    void *pointers[4];
};

void forceSetPerceptionWork(void *arg0, void *work)
{
    void *context = *(void **)((char *)work + 0x40);

    if (context != 0) {
        void *actor = *(void **)((char *)work + 0x4C);
        float negative;

        ((union PerceptionVector *)work)->q = (*(union PerceptionVector **)((char *)actor + 0x134))->q;
        ((union PerceptionVector *)((char *)work + 0x10))->q = (*(union PerceptionVector **)((char *)actor + 0x134))->q;
        negative = -*(float *)((char *)context + 0x18);
        *(float *)((char *)work + 0x20) = 0.0f;
        *(float *)((char *)work + 0x24) = 0.0f;
        *(float *)((char *)work + 0x28) = negative;
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0232_createPerceptionWork", forceRenewLastPosPerceptionWork);

s32 _omakeSelectFlagChk();

s32 equipmentInvisibilityCloak(s32 a, s32 b, s32 c, s32 d)
{
    return _omakeSelectFlagChk(7, b, c, d);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0232_createPerceptionWork", func_40127DE0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0232_createPerceptionWork", nico_aimIK);

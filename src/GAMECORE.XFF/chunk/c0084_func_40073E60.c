#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0084_func_40073E60", func_40073E60);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0084_func_40073E60", SCRFuncKnightParentMoveControlScriptKey);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0084_func_40073E60", func_400744E0);
void *isysGetThisSubThread(void);
void SCRExecBossPreProcess(s32 a0);
void CharaCtrlResetAllScriptCtrlStatus(void *chara);
void updateScriptDataSystem(void *chara);
void SCRExecBossPostProcess(s32 a0);
void scrRunM(s32 n);

void func_400744E0(s32 *a0)
{
    void *thread;

    isysGetThisSubThread();
    for (;;)
    {
        thread = isysGetThisSubThread();
        SCRExecBossPreProcess(*a0);
        CharaCtrlResetAllScriptCtrlStatus(thread);
        updateScriptDataSystem(thread);
        isysGetThisSubThread();
        SCRExecBossPostProcess(*a0);
        scrRunM(1);
    }
}

extern void RequestCharacterMotionShiftFunc(void *character, void (*func)(void *character));

extern void func_40073E60(void *character);

void SCRKnightBossPartsBroken(void *character)
{
    RequestCharacterMotionShiftFunc(character, func_40073E60);
}

extern void *GetSCRCharaAIWorkPtr(void *);

void SCRFuncKnightSetStand(void *actor)
{
    void *temp_v0;

    temp_v0 = GetSCRCharaAIWorkPtr(actor);
    (*(int *)((char *)(temp_v0) + 0x4190)) = (int) ((*(int *)((char *)(temp_v0) + 0x4190)) | 1);
}

void SCRFuncKnightSetWalk(void *actor)
{
    int temp_v0_2;
    void *temp_v0;

    temp_v0 = GetSCRCharaAIWorkPtr(actor);
    temp_v0_2 = (*(int *)((char *)(temp_v0) + 0x4190));
    if (!(temp_v0_2 & 4)) {
        (*(int *)((char *)(temp_v0) + 0x4190)) = (int) (temp_v0_2 | 2);
    }
}

void SCRFuncKnightSetShakeStop(void *actor)
{
    int temp_v0_2;
    void *temp_v0;

    temp_v0 = GetSCRCharaAIWorkPtr(actor);
    temp_v0_2 = (*(int *)((char *)(temp_v0) + 0x4190));
    if (!(temp_v0_2 & 4)) {
        (*(int *)((char *)(temp_v0) + 0x4190)) = (int) (temp_v0_2 | 4);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0084_func_40073E60", leoTorch);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0084_func_40073E60", func_40074850);

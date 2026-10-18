#include "common.h"

extern void *GetSCRCharaAIWorkPtr(void *);
extern s32 execCondition(void *, s32);
extern s32 execSCRBaseFunc(void *, s32);

void SCRFuncConditionStillnessTimerSet(void *a, float time, s32 b, s32 c, s32 d, s32 e, s32 f, s32 cond, s32 func)
{
    u8 *ai = GetSCRCharaAIWorkPtr(a);

    if (execCondition(a, cond)) {
        execSCRBaseFunc(a, func);
        return;
    }
    *(float *)(ai + 0x4220) = time;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0078_SCRFuncConditionStillnessTimerSet", SCRConditionHorseForceStandby);

extern void RequestCharacterMotionShiftFunc(void *character, void (*func)(void *character));
extern void func_4006ED40(void *character);

void SCRHorseUnLoad(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_4006ED40);
}

void nico_setHorseBridleObjToHorseWork(void *a, int b)
{
    *(int *)((u8 *)GetSCRCharaAIWorkPtr(a) + 0x4228) = b;
}

extern void nico_setHorseBridleTerminalParentPoint(void *, void *, int, const float *, float);

void nico_setHorseRidingStatusForHorse(void *actor, void *parent, int node, const float *point, float span)
{
    void *horse;

    horse = *(void **)((u8 *)GetSCRCharaAIWorkPtr(actor) + 0x4228);
    if (horse != 0) {
        nico_setHorseBridleTerminalParentPoint(horse, parent, node, point, span);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0078_SCRFuncConditionStillnessTimerSet", nico_setHorseRidingStatusForHorseIndep);

extern void nico_resetHorseBridleTerminalParentPoint(int);

void nico_resetHorseRidingStatusForHorse(void *actor)
{
    int h = *(int *)((u8 *)GetSCRCharaAIWorkPtr(actor) + 0x4228);

    if (h != 0) {
        nico_resetHorseBridleTerminalParentPoint(h);
    }
}

extern void nico_setHorseBridleType(void *, int);

void nico_setHorseBridleDoubleShort(void *actor)
{
    void *horse = *(void **)((u8 *)GetSCRCharaAIWorkPtr(actor) + 0x4228);

    if (horse != 0) {
        nico_setHorseBridleType(horse, 0);
    }
}

void nico_setHorseBridleLeftLong(void *actor)
{
    void *horse = *(void **)((u8 *)GetSCRCharaAIWorkPtr(actor) + 0x4228);

    if (horse != 0) {
        nico_setHorseBridleType(horse, 1);
    }
}

void nico_setHorseBridleRightLong(void *actor)
{
    void *horse = *(void **)((u8 *)GetSCRCharaAIWorkPtr(actor) + 0x4228);

    if (horse != 0) {
        nico_setHorseBridleType(horse, 2);
    }
}

void nico_setHorseBridleDoubleLong(void *actor)
{
    void *horse = *(void **)(GetSCRCharaAIWorkPtr(actor) + 0x4228);

    if (horse != 0) {
        nico_setHorseBridleType(horse, 3);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0078_SCRFuncConditionStillnessTimerSet", func_4006ED40);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0078_SCRFuncConditionStillnessTimerSet", func_4006ED58);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0078_SCRFuncConditionStillnessTimerSet", nico_resetHorseBridleTerminalParentPoint);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0078_SCRFuncConditionStillnessTimerSet", func_4006F2D0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0078_SCRFuncConditionStillnessTimerSet", func_4006F500);

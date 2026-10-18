#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0056_func_40054018", func_40054018);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0056_func_40054018", SCRConditionSendDamageToCollisionObject3);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0056_func_40054018", nico_leoBodyExpression);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0056_func_40054018", func_40054AD8);

extern void *isysGetThisSubThread(void);
void SCRExecBossPreProcess(s32 a0);
void CharaCtrlResetAllScriptCtrlStatus(void *chara);
void updateScriptDataSystem(void *chara);
void SCRExecBossPostProcess(s32 a0);
void scrRunM(s32 n);

void func_40054B00(s32 *a0)
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

extern void *GetSCRCharaAIWorkPtr(void *);
extern void setEventLineAttr(void *, int, int);

void SCRCerberusEventLineCut(void *actor, int line)
{
    setEventLineAttr((char *)GetSCRCharaAIWorkPtr(actor) + 0x10, line, 4);
}

extern void _SCRStartLWS(int, int, int, int);

void SCRCerberusArmorBroken(void *a)
{
    char *ai = GetSCRCharaAIWorkPtr(a);

    _SCRStartLWS(*(int *)(ai + 0x4190), -1, 4, 0);
    _SCRStartLWS(*(int *)(ai + 0x41A0), -1, 4, 0);
    _SCRStartLWS(*(int *)(ai + 0x41A4), -1, 4, 0);
    _SCRStartLWS(*(int *)(ai + 0x4194), -1, 3, 0);
    _SCRStartLWS(*(int *)(ai + 0x4198), -1, 3, 0);
    _SCRStartLWS(*(int *)(ai + 0x419C), -1, 3, 0);
}

extern void RequestCharacterMotionShiftFunc(void *character, void (*func)(void *character));
extern void func_40054F20(void *character);

void SCRCerberusPollFalldown(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_40054F20);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0056_func_40054018", SCRFuncCerberusChangedCol);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0056_func_40054018", SCRConditionSendDamageToCollisionObject);

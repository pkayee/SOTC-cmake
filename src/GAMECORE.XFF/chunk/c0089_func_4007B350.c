#include "common.h"

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0089_func_4007B350", func_4007B350);
void func_4007B350(s32 *a0)
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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0089_func_4007B350", SCRFuncMinoASetTemporaryTarget);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0089_func_4007B350", func_4007B4E8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0089_func_4007B350", nico_BossMinotaurCStart);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0089_func_4007B350", func_4007B680);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0089_func_4007B350", SCRConditionMinoCBridgeRayChack);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0089_func_4007B350", func_4007BA48);
void *isysGetThisSubThread(void);
void CharaCtrlResetAllScriptCtrlStatus(void *chara);
void updateScriptDataSystem(void *chara);
void SCRExecBossPreProcess(s32 a0);
void SCRExecBossPostProcess(s32 a0);
void scrRunM(s32 n);

void func_4007BA48(s32 *a0)
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
extern void func_4007B680(void *character);

void SCRMinotourCFallWeapon(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_4007B680);
}

extern void func_4007BED8(void *character);

void SCRMinotourCSetFallWeaponFlag(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_4007BED8);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0089_func_4007B350", func_4007BAE8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0089_func_4007B350", SCRFuncMinoCSetTemporaryTarget);

extern void *GetSCRCharaAIWorkPtr(void *);

void SCRFuncMinoCAtkCountInit(void *actor)
{
    (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41C8)) = 0;
}

void SCRFuncMinoCAddAtkCount(void *actor)
{
    void *temp_v0;

    temp_v0 = GetSCRCharaAIWorkPtr(actor);
    (*(int *)((char *)(temp_v0) + 0x41C8)) = (int) ((*(int *)((char *)(temp_v0) + 0x41C8)) + 1);
}

int SCRConditionMinoCAtkCountChack(int a, int n)
{
    return n < *(int *)(((char *)GetSCRCharaAIWorkPtr((void *)a)) + 0x41C8);
}

extern void func_4007BF10(void *character);

void SCRMinoCSetAddFlag(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_4007BF10);
}

extern void func_4007BF48(void *character);

void SCRMinoCResetAddFlag(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_4007BF48);
}

int SCRConditionMinoCAddFlagChack(void *actor)
{
    return (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41CC));
}

int SCRConditionMinoCWallCaseFlagChack(void *actor)
{
    return (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41D0));
}

void SCRFuncMinoCSetPlayerInCorridorFlag(void *actor)
{
    (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41D4)) = 1;
}

void SCRFuncMinoCResetPlayerInCorridorFlag(void *actor)
{
    (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41D4)) = 0;
}

int SCRFuncMinoCPlayerInCorridorFlagChack(void *actor)
{
    return (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41D4));
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0089_func_4007B350", func_4007BED8);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0089_func_4007B350", func_4007BF10);
extern u8 gcGlobalVar[];
s32 SCRGetFirstObj();

void func_4007BF10(void *character)
{
    s32 obj = SCRGetFirstObj(gcGlobalVar + 0x2B8);

    if (obj != 0)
    {
        u8 *work = GetSCRCharaAIWorkPtr((void *)obj);
        *(s32 *)(work + 0x41CC) = 1;
    }
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0089_func_4007B350", func_4007BF48);
void func_4007BF48(void *character)
{
    s32 obj = SCRGetFirstObj(gcGlobalVar + 0x2B8);

    if (obj != 0)
    {
        u8 *work = GetSCRCharaAIWorkPtr((void *)obj);
        *(s32 *)(work + 0x41CC) = 0;
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0089_func_4007B350", func_4007BF80);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0089_func_4007B350", func_4007C2F8);

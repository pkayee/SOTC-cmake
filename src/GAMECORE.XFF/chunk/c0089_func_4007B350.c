#include "common.h"

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0089_func_4007B350", func_4007B350);
extern s64 *GetCollisionDBAttributeAdr(void);

extern s32 _gameFlagChk(s32 idx);
extern void _gameFlagSet(s32 i);

extern char rootPtn[];
void *isysGetThisSubThread(void);
extern s32 iosCreatePartition(void *, s32);
extern void *GetScriptCharacterClass(void *);
extern void CharaCtrlResetCtrlStatus(void *);
void CharaCtrlResetAllScriptCtrlStatus(void *chara);
extern void *_SCRMallocAlign(s32, s32, s32);
extern void isysJumpSubThread(void (*)(s32 *), void *);
extern s32 SCRGetSizeOfBossWork(void *);
extern s32 SCRCharaInitBossWork(s32, void *);
extern void SCRReleaseBossWork(void);
extern void SetScriptCharacterObjReleaseCallBackFunc(void *, void (*)(void), s32);
extern void *GetScriptClass(void *);
extern void initScriptDataSystem(void *, s32);
extern s32 _SCRSetupLWSWithTargetNodeParent(s32, void *, s32);
extern void _SCRStartLWS(s32, s32, s32, s32);
extern s32 SkelFocusDef_MINOTAUR_SWORD;
extern s32 ScriptAnimationObjDef_MINO_C_WEAPON_DEFAULT;
extern s32 ScriptAnimationObjDef_MINO_C_WEAPON_FALL;
extern void func_4007BA48(s32 *a0);

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

s32 func_4007B4E8(void)
{
    return (*GetCollisionDBAttributeAdr() & 0x7C000000) == 0x64000000;
}

void nico_BossMinotaurCStart(void)
{
    void *th = isysGetThisSubThread();
    s32 part = iosCreatePartition(rootPtn, SCRGetSizeOfBossWork(th) + 0x4213);
    s32 *c;
    s32 *w;
    s32 r;

    *(s32 *)((u8 *)GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = _SCRMallocAlign(part, 0x41E0, 0x10);
    *(s32 **)((u8 *)c + 0x1150) = w;
    r = SCRCharaInitBossWork(part, th);
    *w = r;
    SetScriptCharacterObjReleaseCallBackFunc(th, SCRReleaseBossWork, r);
    initScriptDataSystem(th, *(s32 *)((u8 *)GetScriptClass(th) + 0x48));
    *(s32 *)((u8 *)w + 0x41C8) = 0;
    *(s32 *)((u8 *)w + 0x41CC) = 0;
    *(s32 *)((u8 *)w + 0x41D0) = 0;
    *(s32 *)((u8 *)w + 0x41D4) = 0;
    if (_gameFlagChk(0x13F) == 0) {
        s32 lws;
        lws = _SCRSetupLWSWithTargetNodeParent(ScriptAnimationObjDef_MINO_C_WEAPON_DEFAULT, th, SkelFocusDef_MINOTAUR_SWORD);
        *(s32 *)((u8 *)w + 0x41C0) = lws;
        _SCRStartLWS(lws, -1, 2, 0);
        lws = _SCRSetupLWSWithTargetNodeParent(ScriptAnimationObjDef_MINO_C_WEAPON_FALL, th, SkelFocusDef_MINOTAUR_SWORD);
        *(s32 *)((u8 *)w + 0x41C4) = lws;
        _SCRStartLWS(lws, -1, 1, 0);
    }
    isysJumpSubThread(func_4007BA48, w);
}

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

int func_4007BAE8(int a, long *b)
{
    return b[1] == (*(long *)GetCollisionDBAttributeAdr() & b[0]);
}

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

void func_4007BED8(void *character)
{
    if (_gameFlagChk(0x13F) == 0) {
        _gameFlagSet(0x13F);
    }
}

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

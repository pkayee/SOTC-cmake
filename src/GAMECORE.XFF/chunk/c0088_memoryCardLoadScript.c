#include "common.h"

extern int D_40131828;
extern int ScriptSpriteMenuObjDef_SPRITE_SAVE;
extern void _SCRStartSpriteMenuAnim(int, int, int, int *, int, int);
extern void scrRun(void);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0088_memoryCardLoadScript", memoryCardLoadScript);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0088_memoryCardLoadScript", bootMemoryCardLoadScriptNoBlock);

void bootMemoryCardSaveScript(int param)
{
    int done;

    if (D_40131828 != 0)
        return;
    D_40131828 = 1;
    done = 0;
    _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_SAVE, 0, 0, &done, 0, param);
    if (done == 0) {
        do {
            scrRun();
        } while (done == 0);
    }
    D_40131828 = 0;
}

void bootMemoryCardSaveScriptNoBlock(void *a)
{
    int *p = &D_40131828;
    if (*p == 0) {
        *p = 1;
        _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_SAVE, 0, 0, 0, 0, (int)a);
        *p = 0;
    }
}

extern char rootPtn[];
extern void *isysGetThisSubThread(void);
extern int iosCreatePartition(void *, int);
extern char *GetScriptCharacterClass(void *);
extern void CharaCtrlResetCtrlStatus(void *);
extern void CharaCtrlResetAllScriptCtrlStatus(void *);
extern char *_SCRMallocAlign(int, int, int);
extern void isysJumpSubThread(void (*)(void), void *);
extern int SCRGetSizeOfBossWork(void *);
extern int SCRCharaInitBossWork(int, void *);
extern void SCRReleaseBossWork(void);
extern void SetScriptCharacterObjReleaseCallBackFunc(void *, void (*)(void), int);
extern char *GetScriptClass(void *);
extern void initScriptDataSystem(void *, int);
void func_4007AE38(s32 *a0);

void nico_BossMinotaurStart(void)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, SCRGetSizeOfBossWork(th) + 0x4203);
    char *c;
    int *w;
    int r;

    *(int *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = (int *)_SCRMallocAlign(part, 0x41D0, 0x10);
    *(int **)(c + 0x1150) = w;
    r = SCRCharaInitBossWork(part, th);
    *w = r;
    SetScriptCharacterObjReleaseCallBackFunc(th, SCRReleaseBossWork, r);
    initScriptDataSystem(th, *(int *)(GetScriptClass(th) + 0x48));
    w[0x41C0 / 4] = 0;
    isysJumpSubThread(func_4007AE38, w);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0088_memoryCardLoadScript", SCRFuncMinoBCanossaWallBreak);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0088_memoryCardLoadScript", func_4007AE38);
extern void updateScriptDataSystem(void *chara);
extern void SCRExecBossPreProcess(s32 a0);
extern void SCRExecBossPostProcess(s32 a0);
extern void scrRunM(s32 n);

void func_4007AE38(s32 *a0)
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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0088_memoryCardLoadScript", SCRFuncMinoBSetTemporaryTarget);

extern void RequestCharacterMotionShiftFunc(void *character, void (*func)(void *character));
extern void func_4007B050(void *character);

void SCRCanossaWallBreakEnd(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_4007B050);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0088_memoryCardLoadScript", func_4007B010);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0088_memoryCardLoadScript", func_4007B050);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0088_memoryCardLoadScript", SCRSetupWeaponMinotaur);

extern u8 gcGlobalVar[];
extern void *isysGetThisSubThread(void);
extern void *GetLayoutClass(void *);
extern void UpdateLayoutClassPastSimpleGeometry(void *);
extern void UpdateLayoutClassParentGeometry(void *, s32, s32);
extern void UpdateLayoutClassSimpleGeometry(void *, f32);
extern void scrRun(void);

void nico_minotaur_weaponstart(void)
{
    void *l = GetLayoutClass(isysGetThisSubThread());
    u8 *g = gcGlobalVar;

    for (;;) {
        UpdateLayoutClassPastSimpleGeometry(l);
        UpdateLayoutClassParentGeometry(l, 0, 0);
        UpdateLayoutClassSimpleGeometry(l, *(f32 *)(g + 0x184));
        scrRun();
    }
}

extern void func_4007B350(void);

void nico_BossMinotaurAStart(void)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, SCRGetSizeOfBossWork(th) + 0x41F3);
    char *c;
    int *w;
    int r;

    *(int *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = (int *)_SCRMallocAlign(part, 0x41C0, 0x10);
    *(int **)(c + 0x1150) = w;
    r = SCRCharaInitBossWork(part, th);
    *w = r;
    SetScriptCharacterObjReleaseCallBackFunc(th, SCRReleaseBossWork, r);
    initScriptDataSystem(th, *(int *)(GetScriptClass(th) + 0x48));
    isysJumpSubThread(func_4007B350, w);
}

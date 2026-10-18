#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0160_demo_title", demo_title);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0160_demo_title", func_400D6650);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0160_demo_title", titlemenu);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0160_demo_title", title_newfile);
extern s32 D_40131EB0;
extern s32 ScrIntrDef_GAME_NEWSTART;
void setGameHardMode(s32 v);
void scriptIntrSignal();

void title_newfile(void)
{
    D_40131EB0 = 0;
    setGameHardMode(0);
    scriptIntrSignal(ScrIntrDef_GAME_NEWSTART);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0160_demo_title", title_newfile_hard);

void title_newfile_hard(void)
{
    D_40131EB0 = 0;
    setGameHardMode(1);
    scriptIntrSignal(ScrIntrDef_GAME_NEWSTART);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0160_demo_title", title_loadfile);
extern s32 D_40131EB4;
extern s32 opflowCompareOptionData(void);
extern void func_400D6B80(s32 param_1);
void bootMemoryCardLoadScriptNoBlock(s32 a, void *b);

void title_loadfile(void)
{
    D_40131EB4 = 1;
    bootMemoryCardLoadScriptNoBlock((s32)func_400D6B80, (void *)opflowCompareOptionData);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0160_demo_title", title_options);
extern void PauseGame(s32 a);
extern void OptionMenuStart(s32 *a);
extern void scrRun(void);
extern void ReleaseGame(s32 a);

void title_options(void)
{
    s32 sel;

    PauseGame(1);
    sel = 0;
    OptionMenuStart(&sel);
    while (sel == 0)
    {
        scrRun();
    }
    ReleaseGame(1);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0160_demo_title", func_400D6B80);
extern s32 D_40131EB8;
extern s32 ScrIntrDef_GAME_LOADSTART;

void func_400D6B80(s32 param_1)
{
    if (param_1 != 0)
    {
        D_40131EB8 = 1;
        D_40131EB0 = 0;
        scriptIntrSignal(ScrIntrDef_GAME_LOADSTART);
        return;
    }
    D_40131EB4 = 0;
    return;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0160_demo_title", nico_tortoiseBossStart);
extern char rootPtn[];
extern void *isysGetThisSubThread(void);
extern s32 iosCreatePartition(void *, s32);
extern void *GetScriptCharacterClass(void *);
extern void CharaCtrlResetCtrlStatus(void *);
extern void CharaCtrlResetAllScriptCtrlStatus(void *);
extern void *_SCRMallocAlign(s32, s32, s32);
extern void isysJumpSubThread(void (*)(void), void *);
extern s32 SCRGetSizeOfBossWork(void *);
extern s32 SCRCharaInitBossWork(s32, void *);
extern void SCRReleaseBossWork(void);
extern void SetScriptCharacterObjReleaseCallBackFunc(void *, void (*)(void), s32);
extern void *GetScriptClass(void *);
extern void initScriptDataSystem(void *, s32);
extern void SetScriptObjDeleteCallBackFunc(void *, void (*)(void), s32);
extern void func_400D78E8(void);
extern void nico_bossTortoiseAIMain(void);

void nico_tortoiseBossStart(void)
{
    void *th = isysGetThisSubThread();
    s32 part = iosCreatePartition(rootPtn, SCRGetSizeOfBossWork(th) + 0x41F3);
    s32 *c;
    s32 *w;
    s32 r;

    *(s32 *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = _SCRMallocAlign(part, 0x41C0, 0x10);
    *(s32 **)((u8 *)c + 0x1150) = w;
    r = SCRCharaInitBossWork(part, th);
    *w = r;
    SetScriptCharacterObjReleaseCallBackFunc(th, SCRReleaseBossWork, r);
    CharaCtrlResetCtrlStatus(th);
    initScriptDataSystem(th, *(s32 *)((u8 *)GetScriptClass(th) + 0x48));
    *(s32 *)((u8 *)w + 0x41A0) = 0;
    *(s32 *)((u8 *)w + 0x41A4) = 0;
    *(s32 *)((u8 *)w + 0x41A8) = 0;
    *(s32 *)((u8 *)w + 0x41AC) = 0;
    *(s32 *)((u8 *)w + 0x41B0) = 0;
    *(s32 *)((u8 *)w + 0x41B4) = 0;
    *(s32 *)((u8 *)w + 0x41B8) = 0;
    SetScriptObjDeleteCallBackFunc(th, func_400D78E8, 0);
    isysJumpSubThread(nico_bossTortoiseAIMain, w);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0160_demo_title", func_400D6CE8);

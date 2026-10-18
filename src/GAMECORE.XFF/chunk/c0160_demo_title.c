#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0160_demo_title", demo_title);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0160_demo_title", func_400D6650);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0160_demo_title", titlemenu);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0160_demo_title", title_newfile);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0160_demo_title", title_newfile_hard);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0160_demo_title", title_loadfile);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0160_demo_title", title_options);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0160_demo_title", func_400D6B80);

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

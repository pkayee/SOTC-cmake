#include "common.h"

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
extern void *GetLayoutClass(void *);
extern void SetScriptObjDeleteCallBackFunc(void *, void (*)(void), s32);
extern void func_400739A8(void);
extern void func_40073948(void);

void nico_kirinBossStart(void)
{
    void *th = isysGetThisSubThread();
    s32 part = iosCreatePartition(rootPtn, SCRGetSizeOfBossWork(th) + 0x41D3);
    s32 *c;
    s32 *w;
    s32 r;

    *(s32 *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = _SCRMallocAlign(part, 0x41A0, 0x10);
    *(s32 **)((u8 *)c + 0x1150) = w;
    r = SCRCharaInitBossWork(part, th);
    *w = r;
    SetScriptCharacterObjReleaseCallBackFunc(th, SCRReleaseBossWork, r);
    CharaCtrlResetCtrlStatus(th);
    initScriptDataSystem(th, *(s32 *)((u8 *)GetScriptClass(th) + 0x48));
    *(s32 *)((u8 *)w + 0x4198) = 0;
    *(s32 *)((u8 *)w + 0x419C) = 0;
    *(s32 *)((u8 *)w + 0x4194) = 0;
    *(s32 *)((u8 *)w + 0x4190) = 0;
    *(s32 *)((u8 *)GetLayoutClass(th) + 0x1AC) = 0;
    SetScriptObjDeleteCallBackFunc(th, func_400739A8, 0);
    isysJumpSubThread(func_40073948, w);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0082_nico_kirinBossStart", nico_kirinBodyExpression);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0082_nico_kirinBossStart", func_40072A00);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0082_nico_kirinBossStart", SCRFuncKirinCaveFallRockLWSLoad);

#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0076_SCRFuncHorseStandRundmSendkey", SCRFuncHorseStandRundmSendkey);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0076_SCRFuncHorseStandRundmSendkey", func_4006D468);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0076_SCRFuncHorseStandRundmSendkey", func_4006D4F0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0076_SCRFuncHorseStandRundmSendkey", func_4006D598);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0076_SCRFuncHorseStandRundmSendkey", func_4006D800);

extern int D_401317C0;

void setHorseAIStopFlag(int arg0)
{
    D_401317C0 = arg0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0076_SCRFuncHorseStandRundmSendkey", func_4006DA08);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0076_SCRFuncHorseStandRundmSendkey", func_4006DAC0);

extern char rootPtn[];
extern void *isysGetThisSubThread(void);
extern int iosCreatePartition(void *, int);
extern char *GetScriptCharacterClass(void *);
extern void CharaCtrlResetCtrlStatus(void *);
extern void CharaCtrlResetAllScriptCtrlStatus(void *);
extern char *_SCRMallocAlign(int, int, int);
extern char YUnitVector[];
extern void func_4006DAC0(void);
extern char *GetCharacterClass(void *);
extern void SetCollisionEdgeLinkDBFinderCollectStatus(void *, int, int, void *, void (*)(void), float);
extern void scrRun(void);

void nico_blankHorseStart(void)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, 0x4263);
    char *c;
    char *w;
    char *cc;

    *(int *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = _SCRMallocAlign(part, 0x4230, 0x10);
    *(char **)(c + 0x1150) = w;
    *(int *)(w + 0x4228) = 0;
    cc = GetCharacterClass(th);
    if (*(void **)(cc + 0xDAC) != 0) {
        SetCollisionEdgeLinkDBFinderCollectStatus(*(void **)(cc + 0xDAC), 0, 0, YUnitVector, func_4006DAC0, 3.0f);
        cc[0xA90] = 1;
        cc[0xAB0] = 1;
    }
    for (;;)
        scrRun();
}

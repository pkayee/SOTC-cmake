#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0148_nico_SmallNamazuStart", nico_SmallNamazuStart);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0148_nico_SmallNamazuStart", NamazuInitFunc);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0148_nico_SmallNamazuStart", func_400C92E0);

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
extern void getWormIKWork(void *);
extern void func_400C92E0(void);

void nico_snakeCBossStart(void)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, SCRGetSizeOfBossWork(th) + 0x5A93);
    char *c;
    int *w;
    int r;

    *(int *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = (int *)_SCRMallocAlign(part, 0x5A60, 0x10);
    *(int **)(c + 0x1150) = w;
    r = SCRCharaInitBossWork(part, th);
    *w = r;
    SetScriptCharacterObjReleaseCallBackFunc(th, SCRReleaseBossWork, r);
    CharaCtrlResetCtrlStatus(th);
    initScriptDataSystem(th, *(int *)(GetScriptClass(th) + 0x48));
    getWormIKWork(th);
    w[0x5A40 / 4] = 0;
    w[0x5A44 / 4] = 0;
    w[0x5A48 / 4] = 0;
    w[0x5A4C / 4] = 0;
    w[0x5A50 / 4] = 0;
    isysJumpSubThread(func_400C92E0, w);
}

extern void *GetSCRCharaAIWorkPtr(void *);

void SCRFuncSnakeCDeflateEnd(void *actor)
{
    (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x5A4C)) = 1;
}

void SCRFuncSnakeCUpGroundInit(void *actor)
{
    (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x5A50)) = 1;
}

extern int DldSysUndefSymbol;
extern void CharaCtrlSetScriptCtrlStatus(void *, int);

void SCRFuncSnakeCUpGroundMain(void *a, int b, int c, int d, int e, int f, int g, int i, unsigned int *h)
{
    char *ai = GetSCRCharaAIWorkPtr(a);

    if (*(int *)(ai + 0x5A50) != 0 && *(int *)(ai + 0x3DDC) == 0) {
        unsigned int v = *h;
        int voff = v & 0x3FFFF;
        char *t = voff != 0 ? *(char **)((char *)h - voff) : 0;
        char *p = (t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(int *)(*(char **)(t + 8) + 0xC) : 0;

        if (p != 0)
            CharaCtrlSetScriptCtrlStatus(a, *(int *)(p + 4));
        *(int *)(ai + 0x5A50) = 0;
    }
}

extern char D_40131BE8[];
extern void bootTexAlphaAnim(void *, void *, float, float);

void nico_snakeBellyFrontTexEnd(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40131BE8, 0.0f, -0.05f);
}

void nico_snakeBellyFrontTexStart(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40131BE8, 1.0f, 0.05f);
}

extern char D_40131C00[];

void nico_snakeBellyCenterTexEnd(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40131C00, 0.0f, -0.05f);
}

void nico_snakeBellyCenterTexStart(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40131C00, 1.0f, 0.05f);
}

extern char D_40131C18[];

void nico_snakeBellyBackTexEnd(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40131C18, 0.0f, -0.05f);
}

void nico_snakeBellyBackTexStart(void)
{
    bootTexAlphaAnim(isysGetThisSubThread(), D_40131C18, 1.0f, 0.05f);
}

void nico_snakeAllTexEnd(void)
{
    void *th = isysGetThisSubThread();

    bootTexAlphaAnim(th, D_40131BE8, 0.0f, -0.05f);
    bootTexAlphaAnim(th, D_40131C00, 0.0f, -0.05f);
    bootTexAlphaAnim(th, D_40131C18, 0.0f, -0.05f);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0148_nico_SmallNamazuStart", func_400C9970);

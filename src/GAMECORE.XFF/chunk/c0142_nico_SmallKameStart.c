#include "common.h"

extern char rootPtn[];
extern void *isysGetThisSubThread(void);
extern int iosCreatePartition(void *, int);
extern char *GetScriptCharacterClass(void *);
extern void CharaCtrlResetCtrlStatus(void *);
extern void CharaCtrlResetAllScriptCtrlStatus(void *);
extern char *_SCRMallocAlign(int, int, int);
extern void isysJumpSubThread(void (*)(void), void *);
extern char gcGlobalVar[];
extern char *GetScriptClass(void *);
extern int getEditWorkInitData(int);
extern void *SCRGetFirstObj(void *);
extern void scrRun(void);
extern void AI_InitAnimalWork(void *, int);
extern void func_400BFF50(void *);
extern void func_400BF450(void);

void nico_SmallKameStart(void)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, 0x243);
    char *c;
    char *w;

    *(int *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = _SCRMallocAlign(part, 0x210, 0x10);
    *(char **)(c + 0x1150) = w;
    CharaCtrlResetCtrlStatus(th);
    *(int *)(w + 0x40) = getEditWorkInitData(*(int *)(GetScriptClass(th) + 0x40));
    while ((*(void **)(w + 0x44) = SCRGetFirstObj(gcGlobalVar + 0x2B0)) == 0)
        scrRun();
    AI_InitAnimalWork(w, 7);
    func_400BFF50(w);
    isysJumpSubThread(func_400BF450, w);
}

void nico_SmallLizardStart(void)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, 0x243);
    char *c;
    char *w;

    *(int *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = _SCRMallocAlign(part, 0x210, 0x10);
    *(char **)(c + 0x1150) = w;
    CharaCtrlResetCtrlStatus(th);
    *(int *)(w + 0x40) = getEditWorkInitData(*(int *)(GetScriptClass(th) + 0x40));
    while ((*(void **)(w + 0x44) = SCRGetFirstObj(gcGlobalVar + 0x2B0)) == 0)
        scrRun();
    AI_InitAnimalWork(w, 2);
    func_400BFF50(w);
    isysJumpSubThread(func_400BF450, w);
}

void GexCutTail(void *actor)
{
    int *temp_v1;
    void *temp_v0;

    temp_v0 = (*(void **)((char *)(GetScriptCharacterClass(actor)) + 0x1150));
    if (temp_v0 != NULL) {
        temp_v1 = (*(int **)((char *)(temp_v0) + 0x10));
        if (temp_v1 != NULL) {
            *temp_v1 = 1;
        }
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0142_nico_SmallKameStart", AI_SetQuaternionFromGP);

extern void GexInitCommonFunc(void *, void *, void *, void *, void *, float *);

void GexInitFunc(void *a, void *b, void *c, void *d, void *e)
{
    float v[4];
    memset(v, 0, 0x10);
    v[1] = -1.0f;
    GexInitCommonFunc(a, b, c, d, e, v);
}

void GexCeilInitFunc(void *a, void *b, void *c, void *d, void *e)
{
    float v[4];
    memset(v, 0, 0x10);
    v[1] = 1.0f;
    GexInitCommonFunc(a, b, c, d, e, v);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0142_nico_SmallKameStart", GexWallInitFunc);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0142_nico_SmallKameStart", func_400C0690);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0142_nico_SmallKameStart", func_400C0D68);

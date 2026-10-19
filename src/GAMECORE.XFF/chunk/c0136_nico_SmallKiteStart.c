#include "common.h"

extern char rootPtn[];
extern void *isysGetThisSubThread(void);
extern int iosCreatePartition(void *, int);
extern char *GetScriptCharacterClass(void *);
extern void CharaCtrlResetCtrlStatus(void *);
extern void CharaCtrlResetAllScriptCtrlStatus(void *);
extern char *_SCRMallocAlign(int, int, int);
extern void isysJumpSubThread(void (*)(void), void *);
extern char *GetScriptClass(void *);
extern char *getEditWorkInitData(int);
extern void AI_InitAnimalWork(void *, int);
extern void Kite_InitKitePathWork(void *, void *, float, float);
extern void Kite_SetAnimalID_KitePathWork(void *, int);
extern void SetScriptObjDeleteCallBackFunc(void *, void (*)(void *, u8 *), void *);
extern void func_400B79B8(void *);
extern void func_400B75A8(void *);
extern void func_400B7810(void *);
extern void func_400B8390(void *, u8 *);
extern void func_400B7308(void);

void nico_SmallKiteStart(void)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, 0x853);
    char *c;
    char *w;
    char *path;

    *(int *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = _SCRMallocAlign(part, 0x820, 0x10);
    *(char **)(c + 0x1150) = w;
    path = w + 0x310;
    CharaCtrlResetCtrlStatus(th);
    *(char **)(w + 0x20) = getEditWorkInitData(*(int *)(GetScriptClass(th) + 0x40));
    AI_InitAnimalWork(w, 1);
    func_400B79B8(w);
    Kite_InitKitePathWork(path, th, *(float *)(*(char **)(w + 0x20) + 0xE8), *(float *)(*(char **)(w + 0x20) + 0xE4));
    Kite_SetAnimalID_KitePathWork(path, 1);
    func_400B75A8(w);
    func_400B7810(w);
    SetScriptObjDeleteCallBackFunc(isysGetThisSubThread(), func_400B8390, w);
    isysJumpSubThread(func_400B7308, w);
}

/* NEARMISS-STUB nico_SmallKiteSpecialStart */
#if 0 /* NEARMISS 92.62% cat=regalloc sub=path-copy | SmallKiteStart shape + loop Kite_SetEventIDList(path,7,i) i<10; target keeps a second copy of path (daddu s2,s1) for the loop and 5 saved regs, ours coalesces i | attempts=1 */
extern void Kite_SetEventIDList(void *, int, int);

void nico_SmallKiteSpecialStart(void)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, 0x853);
    char *c;
    char *w;
    char *path;
    int i;

    *(int *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = _SCRMallocAlign(part, 0x820, 0x10);
    *(char **)(c + 0x1150) = w;
    path = w + 0x310;
    CharaCtrlResetCtrlStatus(th);
    *(char **)(w + 0x20) = getEditWorkInitData(*(int *)(GetScriptClass(th) + 0x40));
    AI_InitAnimalWork(w, 8);
    func_400B79B8(w);
    Kite_InitKitePathWork(path, isysGetThisSubThread(), *(float *)(*(char **)(w + 0x20) + 0xE8), *(float *)(*(char **)(w + 0x20) + 0xE4));
    Kite_SetAnimalID_KitePathWork(path, 8);
    func_400B75A8(w);
    *(int *)(w + 0x300) = 0;
    func_400B7810(w);
    for (i = 0; i < 10; i++) {
        Kite_SetEventIDList(path, 7, i);
    }
    SetScriptObjDeleteCallBackFunc(isysGetThisSubThread(), func_400B8390, w);
    isysJumpSubThread(func_400B7308, w);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0136_nico_SmallKiteStart", nico_SmallKiteSpecialStart);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0136_nico_SmallKiteStart", nico_SmallKiteAdvertiseStart);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0136_nico_SmallKiteStart", KiteGroundInitFunc);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0136_nico_SmallKiteStart", KiteInitFunc);

extern void iosFree(void *);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0136_nico_SmallKiteStart", func_400B8390);
void func_400B8390(void *a0, u8 *a1)
{
    s32 v;

    if (a1 != NULL)
    {
        v = *(s32 *)(a1 + 0x300);
        if (v != 0)
        {
            return iosFree((void *)v);
        }
    }
    return;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0136_nico_SmallKiteStart", func_400B83C8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0136_nico_SmallKiteStart", func_400B8718);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0136_nico_SmallKiteStart", func_400B89C8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0136_nico_SmallKiteStart", func_400B8AD8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0136_nico_SmallKiteStart", func_400B8C20);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0136_nico_SmallKiteStart", func_400B8F70);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0136_nico_SmallKiteStart", func_400B91F8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0136_nico_SmallKiteStart", func_400B93E8);

#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0164_SCRSetupWeaponPlayer", SCRSetupWeaponPlayer);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0164_SCRSetupWeaponPlayer", setIsWeapon);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0164_SCRSetupWeaponPlayer", nico_weaponstart);

extern int initWeaponSpriteStatus();

int initWeapon(int a, int b, int c, int d)
{
    return initWeaponSpriteStatus(a, b, c, d);
}

extern int D_40131F50;

int getSelectWeapon(void)
{
    return D_40131F50;
}

typedef struct
{
    s32 name;
    s32 flag;
    char pad[0x14];
} Weapon;

typedef struct
{
    char pad[0x10];
    Weapon *list;
} WeaponList;

extern s32 DldSysUndefSymbol;
extern WeaponList SH_WeaponListDEFAULT;

s32 getWeaponName(s32 i)
{
    WeaponList *l = DldSysUndefSymbol != (s32)&SH_WeaponListDEFAULT ? &SH_WeaponListDEFAULT : 0;
    return l->list[i].name;
}

extern void CancelSwordEffect();
extern int D_40131F54;
extern void setWeaponSpriteStatus(int, int);

void setSelectWeapon(int w)
{
    int old;
    CancelSwordEffect(w);
    old = D_40131F50;
    D_40131F50 = w;
    D_40131F54 = old;
    setWeaponSpriteStatus(w, old);
}

s32 selectWeaponBefore(s32 cur)
{
    int *sh = DldSysUndefSymbol != (s32)&SH_WeaponListDEFAULT ? (int *)&SH_WeaponListDEFAULT : 0;
    Weapon *tab = (Weapon *)sh[4];
    s32 i;

    i = cur;
    for (;;) {
        if (--i <= 0)
            i = 9;
        if (i == cur)
            break;
        if (_omakeSelectFlagChk(tab[i].flag))
            break;
    }
    CancelSwordEffect();
    D_40131F54 = D_40131F50;
    D_40131F50 = i;
    setWeaponSpriteStatus(i, D_40131F54);
    return i;
}

s32 selectWeaponNext(s32 cur)
{
    int *sh = DldSysUndefSymbol != (s32)&SH_WeaponListDEFAULT ? (int *)&SH_WeaponListDEFAULT : 0;
    Weapon *tab = (Weapon *)sh[4];
    s32 i;

    i = cur;
    for (;;) {
        if (++i >= 10)
            i = 1;
        if (i == cur)
            break;
        if (_omakeSelectFlagChk(tab[i].flag))
            break;
    }
    CancelSwordEffect();
    D_40131F54 = D_40131F50;
    D_40131F50 = i;
    setWeaponSpriteStatus(i, D_40131F54);
    return i;
}

extern s32 _omakeSelectFlagChk(s32);

s32 chkPossessWeapon(s32 i)
{
    WeaponList *l = DldSysUndefSymbol != (s32)&SH_WeaponListDEFAULT ? &SH_WeaponListDEFAULT : 0;
    return _omakeSelectFlagChk(l->list[i].flag);
}

extern s128 D_40131F60;
extern s128 D_40131F70;
extern int D_40131F80;

void sprWeaponSetMarker(s128 *a, s128 *b, int c)
{
    if (c != 0 && a != 0) {
        D_40131F60 = *a;
        D_40131F70 = *b;
    }
    D_40131F80 = c;
}

void sprWeaponGetMarkerPos(s128 *out)
{
    *out = D_40131F60;
}

extern float getPlayerMaxGripRatio(void);
extern float *ScrParam_bow_range;
extern float *ScrParam_harpoon_range;

float GetWeaponRange(void)
{
    switch (D_40131F50) {
    case 1:
    case 2:
    case 3:
        return 500.0f;
    case 4:
    case 6:
    case 7:
        return getPlayerMaxGripRatio() * ScrParam_bow_range[1];
    case 5:
        return ScrParam_harpoon_range[1];
    }
    return 0.0f;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0164_SCRSetupWeaponPlayer", func_400D9E98);

/* NEARMISS-STUB nico_yamori2Start */
#if 0 /* NEARMISS 96.23% cat=sched sub=float-store-order | mammosBossStart shape; only the lui/lwc1 of D_40136F94 is scheduled one store later. 15 store orders + float-local placements tried | attempts=1 */
extern char rootPtn[];
extern void *isysGetThisSubThread(void);
extern s32 SCRGetSizeOfBossWork(void *);
extern void *iosCreatePartition(void *, s32);
extern u8 *GetScriptCharacterClass(void *);
extern void CharaCtrlResetCtrlStatus(void *);
extern void CharaCtrlResetAllScriptCtrlStatus(void *);
extern void *_SCRMallocAlign(void *, s32, s32);
extern void *SCRCharaInitBossWork(void *, void *);
extern void SCRReleaseBossWork();
extern void SetScriptCharacterObjReleaseCallBackFunc(void *, void (*)(), void *);
extern u8 *GetScriptClass(void *);
extern void initScriptDataSystem(void *, void *);
extern void isysJumpSubThread(void (*)(), void *);
extern void func_400D9E98();
extern f32 D_40136F94;

void nico_yamori2Start(void)
{
    void *thread = isysGetThisSubThread();
    s32 size = SCRGetSizeOfBossWork(thread);
    void *part = iosCreatePartition(rootPtn, size + 0x4213);
    u8 *cls = GetScriptCharacterClass(thread);
    u8 *mem;
    void *boss;

    *(void **)(cls + 0x114C) = part;
    CharaCtrlResetCtrlStatus(thread);
    CharaCtrlResetAllScriptCtrlStatus(thread);
    cls = GetScriptCharacterClass(thread);
    mem = _SCRMallocAlign(part, 0x41E0, 0x10);
    *(void **)(cls + 0x1150) = mem;
    boss = SCRCharaInitBossWork(part, thread);
    *(void **)mem = boss;
    SetScriptCharacterObjReleaseCallBackFunc(thread, SCRReleaseBossWork, boss);
    CharaCtrlResetCtrlStatus(thread);
    *(s32 *)(mem + 0x41AC) = 0;
    *(s32 *)(mem + 0x41A4) = 0;
    *(f32 *)(mem + 0x41C4) = D_40136F94;
    *(s32 *)(mem + 0x41B8) = 0;
    *(s32 *)(mem + 0x41BC) = 0;
    *(s32 *)(mem + 0x41B0) = 0;
    *(s32 *)(mem + 0x41B4) = 0;
    *(s32 *)(mem + 0x41C0) = 0;
    *(s32 *)(mem + 0x41C8) = 0;
    cls = GetScriptClass(thread);
    initScriptDataSystem(thread, *(void **)(cls + 0x48));
    isysJumpSubThread(func_400D9E98, mem);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0164_SCRSetupWeaponPlayer", nico_yamori2Start);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0164_SCRSetupWeaponPlayer", func_400DA118);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0164_SCRSetupWeaponPlayer", SCRFuncYamoriBSendFallKey);

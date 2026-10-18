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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0164_SCRSetupWeaponPlayer", nico_yamori2Start);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0164_SCRSetupWeaponPlayer", func_400DA118);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0164_SCRSetupWeaponPlayer", SCRFuncYamoriBSendFallKey);

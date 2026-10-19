#include "common.h"

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

extern int D_40131F50;
extern int D_40131F54;
extern void CancelSwordEffect();
extern void setWeaponSpriteStatus(int, int);
s32 _omakeSelectFlagChk(s32);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0164_SCRSetupWeaponPlayer", SCRSetupWeaponPlayer);

/* NEARMISS-STUB setIsWeapon */
#if 0 /* NEARMISS 99.5% cat=regalloc sub=- | d2 r105: force path = setSelectWeapon body, else loop for(;;){if(++i>=10)i=1; if(i==w)break; if(chk(tab[i].flag))break;} then if(i==w){D50=-1;set(-1,D54);} else | attempts=1 */
s32 setIsWeapon(s32 w, s32 force)
{
    WeaponList *l = DldSysUndefSymbol != (s32)&SH_WeaponListDEFAULT ? &SH_WeaponListDEFAULT : 0;
    Weapon *tab = l->list;
    s32 i;

    if (force) {
        int old;
        CancelSwordEffect();
        old = D_40131F50;
        D_40131F50 = w;
        D_40131F54 = old;
        setWeaponSpriteStatus(w, old);
    } else if (w == D_40131F50) {
        i = w;
        for (;;) {
            if (++i >= 10)
                i = 1;
            if (i == w)
                break;
            if (_omakeSelectFlagChk(tab[i].flag))
                break;
        }
        if (i == w) {
            D_40131F50 = -1;
            setWeaponSpriteStatus(-1, D_40131F54);
        } else {
            CancelSwordEffect();
            D_40131F54 = D_40131F50;
            D_40131F50 = i;
            setWeaponSpriteStatus(i, D_40131F54);
        }
    }
    return D_40131F50;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0164_SCRSetupWeaponPlayer", setIsWeapon);

extern u8 gcGlobalVar[];
void *isysGetThisSubThread(void);
void *GetLayoutClass(void *);
s32 _omakeSelectFlagChk(s32);
void SetLayoutObjAccessSwitch(void *, s32);
void nico_weaponUpdateGeometry(void *);
void FlushCollisionWork(void *);
void scrRun(void);

void nico_weaponstart(void)
{
    void *th = isysGetThisSubThread();
    void *lc = GetLayoutClass(th);
    u8 *g = gcGlobalVar;

    while (1) {
        if (_omakeSelectFlagChk(7) != 0)
            SetLayoutObjAccessSwitch(th, 0);
        else
            SetLayoutObjAccessSwitch(th, 1);
        if (*(s32 *)(g + 0x1AC) == 0) {
            nico_weaponUpdateGeometry(lc);
            FlushCollisionWork(th);
        }
        scrRun();
    }
}

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

extern void SCRExecBossPreProcess(s32);
extern void SCRExecBossPostProcess(s32);
extern void CharaCtrlResetAllScriptCtrlStatus(void *);
extern void updateScriptDataSystem(void *);
extern s32 *GetDamageClass(void *);
extern s32 nico_GetCharacterAttackedGPAttr(void *, s32);
extern void scrRunM(s32);
extern float D_40136F90;

void func_400D9E98(s32 *w)
{
    void *th = isysGetThisSubThread();
    char *b = (char *)w;
    u8 *g = gcGlobalVar;

    while (1) {
        void *t = isysGetThisSubThread();
        s32 *d;

        SCRExecBossPreProcess(w[0]);
        CharaCtrlResetAllScriptCtrlStatus(t);
        updateScriptDataSystem(t);
        d = GetDamageClass(th);
        if (d != 0 && d[0] == 3) {
            if (nico_GetCharacterAttackedGPAttr(th, 0x3F0) == 0x160 || nico_GetCharacterAttackedGPAttr(th, 0x3F0) == 0x180
                || nico_GetCharacterAttackedGPAttr(th, 0x3F0) == 0x170 || nico_GetCharacterAttackedGPAttr(th, 0x3F0) == 0x190) {
                if (d[0x18] == 1 || d[0x18] == 3 || d[0x18] == 2 || d[0x18] == 4) {
                    *(float *)(b + 0x41C4) = 0.0f;
                    *(s32 *)(b + 0x41C0) += 1;
                }
            }
        }
        if (*(s32 *)(b + 0x41C0) > 0)
            *(float *)(b + 0x41C4) += *(float *)(g + 0x180);
        if (*(float *)(b + 0x41C8) < *(float *)(b + 0x41C4)) {
            *(float *)(b + 0x41C4) = D_40136F90;
            *(s32 *)(b + 0x41C0) = 0;
        }
        isysGetThisSubThread();
        SCRExecBossPostProcess(w[0]);
        scrRunM(1);
    }
}

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

extern char *GetSCRCharaAIWorkPtr(void *);
extern char *GetCharacterClass(void *);
extern s32 equipmentInvisibilityCloak(void);
extern char *getSCRDataCtrlWork(void *);
extern s32 CheckPositionInsideOfJudgeVolumeObject(void *, void *, s32, void *);
extern void GetVolumeClippedTargetPos(void *, void *, s32, void *);
extern void func_400DAFA0(void *, void *, s32);
extern s32 SkelFocusDef_BOSS_OPT_ATTACK;

void func_400DA118(void *obj)
{
    char *ai = GetSCRCharaAIWorkPtr(obj);
    void *pos = *(void **)(GetCharacterClass(obj) + 0x1064);
    char buf[0x60];
    float out[4];

    if (equipmentInvisibilityCloak() == 0) {
        if (CheckPositionInsideOfJudgeVolumeObject(buf, obj, *(s32 *)(ai + 0x41AC), pos) != 0) {
            func_400DAFA0(obj, pos, SkelFocusDef_BOSS_OPT_ATTACK);
        } else {
            GetVolumeClippedTargetPos(out, obj, *(s32 *)(ai + 0x41AC), pos);
            func_400DAFA0(obj, out, SkelFocusDef_BOSS_OPT_ATTACK);
        }
    } else {
        char *p2 = getSCRDataCtrlWork(obj) + 0x4010;

        if (CheckPositionInsideOfJudgeVolumeObject(buf, obj, *(s32 *)(ai + 0x41AC), p2) != 0) {
            func_400DAFA0(obj, p2, SkelFocusDef_BOSS_OPT_ATTACK);
        } else {
            GetVolumeClippedTargetPos(out, obj, *(s32 *)(ai + 0x41AC), p2);
            func_400DAFA0(obj, out, SkelFocusDef_BOSS_OPT_ATTACK);
        }
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0164_SCRSetupWeaponPlayer", SCRFuncYamoriBSendFallKey);

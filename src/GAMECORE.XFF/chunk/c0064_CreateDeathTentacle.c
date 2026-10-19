#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0064_CreateDeathTentacle", CreateDeathTentacle);

extern int D_401315B4;

int CheckDeathTentacle(void)
{
    if (D_401315B4 != 0) {
        D_401315B4 = 0;
        return 0;
    }
    return 1;
}

void meshObjectFree(void *);

void func_4005E190(void *arg0, u8 *w)
{
    u8 *info = *(u8 **)(w + 4);
    s32 i;

    for (i = 0; i < *(s32 *)(info + 0x50); i++) {
        if (((void **)(w + 0x14))[i] != 0)
            meshObjectFree(((void **)(w + 0x14))[i]);
    }
}

extern void isysJumpSubThread(void (*)(void), void *);
extern void func_4005E2E0();

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0064_CreateDeathTentacle", func_4005E200);
void func_4005E200(void *arg0)
{
    isysJumpSubThread(func_4005E2E0, arg0);
}

int AI_GetDeathTentWorkSize(void *arg0, int arg1)
{
    int var_v1;

    var_v1 = ((*(int *)((char *)(arg0) + 0x14)) << 5) + 0x429;
    if (arg1 >= (*(int *)((char *)(arg0) + 0x1C))) {
        var_v1 += (*(int *)((char *)(arg0) + 0x4C));
    }
    return var_v1;
}

extern void func_4005DC58(void);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0064_CreateDeathTentacle", func_4005E248);
void func_4005E248(void *arg0)
{
    isysJumpSubThread(func_4005DC58, arg0);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0064_CreateDeathTentacle", func_4005E268);
void GAMEUTIL_set_auto_get_flag_boss_interest_position(s32 flag);

void func_4005E268(void)
{
    GAMEUTIL_set_auto_get_flag_boss_interest_position(1);
}

void GetMeshObjInfo(void *arg0, int arg1, int arg2)
{
    int var_a2;
    int var_a3;

    var_a2 = arg2;
    var_a3 = 1;
    if (arg1 < var_a2) {
        do {
            var_a2 = (var_a2 - arg1) + 2;
            var_a3 += 1;
        } while (arg1 < var_a2);
    }
    (*(int *)((char *)(arg0) + 4)) = var_a3;
    (*(int *)((char *)(arg0) + 0)) = 0;
}

int AI_GetBaseWorkSize(int arg0, int arg1)
{
    int var_v1;

    var_v1 = (arg0 * 4) + 0xD6;
    if (arg1 > 0) {
        var_v1 = var_v1 + (arg0 * 0x30) + 0x33;
    }
    return var_v1;
}

void scrRunM(int);
s32 func_4005D310(u8 *);

void func_4005E2E0(u8 *w)
{
    u8 *info = *(u8 **)(w + 4);

    while (*(s32 *)(info + 0x58) == 0)
        scrRunM(1);
    while (1) {
        *(s32 *)(w + 0x384) = func_4005D310(w);
        scrRunM(1);
    }
}

/* NEARMISS-STUB dischargeInit */
#if 0 /* NEARMISS 95.6% cat=sched sub=- | only the e=w+0x20 copy (daddu s1,v1) vs the d+0x10 lwc1 order: target sw elem; daddu; lwc1, ours lwc1 first. PI2 literal 6.28318501f and iosRotMatrixY(void*,f32 | attempts=1 */
extern char *getSpecialEffectObjWork();
extern char *getEditWorkInitData(int);
extern s32 ScriptAnimationObjDef_EEL_THUNDER_CIRCLE;
extern u128 ZeroPoint;
extern u128 IdentityQuaternion;
f32 iosGetSinf(f32);
f32 iosGetCosf(f32);
void iosUnitMatrix(void *);
void iosRotMatrixY(void *, f32);
s32 _SCRSetupLWS(s32, s32, void *, void *, s32);
void _SCRStartLWS(s32, s32, s32, s32);

void dischargeInit(u8 *o)
{
    char *w = getSpecialEffectObjWork(o);
    char *d = getEditWorkInitData(*(s32 *)(*(u8 **)(o + 0x1C) + 8));
    f32 *e;
    s32 i;
    f32 a;

    *(f32 **)(w + 0xC) = (f32 *)(w + 0x20);
    e = (f32 *)(w + 0x20);
    *(s32 *)(w + 8) = *(f32 *)(d + 0x10);
    for (i = 0; i < *(s32 *)(w + 8); i++) {
        a = ((f32)i / (f32)*(s32 *)(w + 8)) * 6.28318501f;
        e[8] = -iosGetSinf(a);
        e[9] = 0.0f;
        e[10] = iosGetCosf(a);
        e[11] = 1.0f;
        e[0] = 1.0f;
        e[1] = 0.0f;
        e[2] = 0.0f;
        e[3] = 0.0f;
        e[4] = 1.0f;
        e[5] = 0.0f;
        e[6] = 0.0f;
        e[7] = 0.0f;
        iosUnitMatrix(e + 12);
        iosRotMatrixY(e + 12, -a);
        e += 28;
    }
    *(s32 *)(w + 0x10) = _SCRSetupLWS(ScriptAnimationObjDef_EEL_THUNDER_CIRCLE, 0, &ZeroPoint, &IdentityQuaternion, 0);
    _SCRStartLWS(*(s32 *)(w + 0x10), -1, 1, 0);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0064_CreateDeathTentacle", dischargeInit);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0064_CreateDeathTentacle", dischargeMain);

union DischargeVector {
    s128 q;
    float f[4];
};

extern char *getSpecialEffectObjWork();

void setDischargeParam(void *effect, union DischargeVector *vector, float first, float second)
{
    void *work = (void *)getSpecialEffectObjWork(effect);

    *(float *)work = first;
    *(float *)((char *)work + 4) = second;
    ((union DischargeVector *)((char *)effect + 0x20))->q = vector->q;
}

extern char *getEditWorkInitData(int);

int getDischargeSize(char *o)
{
    char *d = getEditWorkInitData(*(int *)(o + 8));
    float min = 32.0f;

    return *(float *)(d + 0x10) * 112.0f + min;
}

extern int isysRequestDeleteObj();

int dischargeTerm(void)
{
    return isysRequestDeleteObj(*(int *)(getSpecialEffectObjWork() + 0x10));
}

extern char rootPtn[];
extern void *isysGetThisSubThread(void);
extern int iosCreatePartition(void *, int);
extern char *GetScriptCharacterClass(void *);
extern void CharaCtrlResetCtrlStatus(void *);
extern void CharaCtrlResetAllScriptCtrlStatus(void *);
extern char *_SCRMallocAlign(int, int, int);
extern void isysJumpSubThread(void (*)(void), void *);
extern char SH_SCRArrowThrustMotListDORMIN_P[];
extern float getPlayerMaxHp(void);
extern void setPlayerHp(float);
extern float getPlayerMaxGrip(void);
extern void setPlayerGrip(float);
extern void createArrowThrustWork(void *, void *, void *);
extern void scrRunM(int);
extern void func_4005EA98();

void nico_dorminStart(void)
{
    void *th = isysGetThisSubThread();
    int part = iosCreatePartition(rootPtn, 0x53);
    char *c;
    char *w;

    *(int *)(GetScriptCharacterClass(th) + 0x114C) = part;
    CharaCtrlResetCtrlStatus(th);
    CharaCtrlResetAllScriptCtrlStatus(th);
    c = GetScriptCharacterClass(th);
    w = _SCRMallocAlign(part, 0x20, 0x10);
    *(char **)(c + 0x1150) = w;
    CharaCtrlResetCtrlStatus(th);
    setPlayerHp(getPlayerMaxHp());
    setPlayerGrip(getPlayerMaxGrip());
    createArrowThrustWork(th, w + 0x10, SH_SCRArrowThrustMotListDORMIN_P);
    scrRunM(1);
    isysJumpSubThread(func_4005EA98, w);
}

s32 *GetDamageClass(void *);
void addPlayerHp(f32);
f32 getPlayerHp(void);
void updateArrowThrustWork(void *, void *);

void func_4005EA98(u8 *w)
{
    void *th = isysGetThisSubThread();

    while (1) {
        CharaCtrlResetAllScriptCtrlStatus(th);
        if (*GetDamageClass(th) == 3) {
            addPlayerHp(-1.0f);
            if (getPlayerHp() < 0.0f)
                setPlayerHp(1.0f);
        }
        updateArrowThrustWork(th, w + 0x10);
        scrRunM(1);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0064_CreateDeathTentacle", nico_balltest);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0064_CreateDeathTentacle", nico_pendulumtest);

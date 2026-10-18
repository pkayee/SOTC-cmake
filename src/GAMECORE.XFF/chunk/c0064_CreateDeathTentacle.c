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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0064_CreateDeathTentacle", func_4005E190);

extern void isysJumpSubThread(void (*)(void), void *);
extern void func_4005E2E0(void);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0064_CreateDeathTentacle", func_4005E2E0);

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
extern void func_4005EA98(void);

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

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0064_CreateDeathTentacle", func_4005EA98);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0064_CreateDeathTentacle", nico_balltest);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0064_CreateDeathTentacle", nico_pendulumtest);

#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0120_SCRConditoinPoseidonPlayerRayChack", SCRConditoinPoseidonPlayerRayChack);

extern void *GetSCRCharaAIWorkPtr(void *);
extern void *getSCRDataCtrlWork(void *);
extern void func_400A3950(void *, void *);
extern void *getRootPointDataByAreaIdx(void *, int, int);
extern unsigned char D_40135B58[];
extern unsigned char gcGlobalVar[];

void SCRFuncPoseidonModifyGP2AttainPos(void *arg0)
{
    void *var_s0;
    int temp_v1;
    int var_s1;
    void *temp_s2;
    void *temp_s4;
    void *temp_v0;

    temp_s4 = GetSCRCharaAIWorkPtr(arg0);
    temp_v0 = getSCRDataCtrlWork(arg0);
    temp_s2 = getRootPointDataByAreaIdx(temp_v0, (*(int *)((char *)(temp_v0) + 0x3C68)), (*(int *)((char *)(temp_v0) + 0x3C6C)));
    if ((*(int *)((char *)(temp_v0) + 0x4074)) != 0) {
        (*(int *)((char *)(temp_s4) + 0x4198)) = 1;
    } else if (temp_s2 != NULL) {
        if ((*(int *)((char *)(temp_s4) + 0x4198)) != 0) {
            var_s1 = 4;
            var_s0 = D_40135B58;
            do {
                temp_v1 = (*(int *)((char *)(temp_s2) + 0x10));
                if (temp_v1 != (*(int *)((char *)(var_s0) + 0))) {
                    if (temp_v1 == (*(int *)((char *)(var_s0) + 4))) {
                        goto block_9;
                    }
                } else {
block_9:
                    func_400A3950(arg0, var_s0);
                }
                var_s1 -= 1;
                var_s0 += 0x20;
            } while (var_s1 >= 0);
        }
        (*(int *)((char *)(temp_s4) + 0x4198)) = 0;
    }
}

void SCRFuncPoseidonResetRevolutionDirection(void *arg0)
{
    (*(int *)((char *)(GetSCRCharaAIWorkPtr(arg0)) + 0x41A8)) = 0;
}

int SCRConditionPoseidonGetRevolutionRayChack(void *arg0)
{
    return (*(int *)((char *)(GetSCRCharaAIWorkPtr(arg0)) + 0x4194));
}

void SCRFuncPoseidonMissAttackInit(void *arg0, s32 arg1)
{
    (*(int *)((char *)(GetSCRCharaAIWorkPtr(arg0)) + 0x41A4)) = arg1;
}

void SCRFuncPoseidonMissAttackAdd(void *actor)
{
    void *temp_v0;

    temp_v0 = GetSCRCharaAIWorkPtr(actor);
    (*(int *)((char *)(temp_v0) + 0x41A4)) = (int) ((*(int *)((char *)(temp_v0) + 0x41A4)) - 1);
}

int SCRConditionPoseidonMissAttackCheck(void *actor)
{
    return (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41A4)) < 1;
}

void SCRFuncPoseidonSetPlayerTerrLog(void *actor, s32 value)
{
    char *w = GetSCRCharaAIWorkPtr(actor);

    if ((u32)(value - 1) < 2U) {
        (*(int *)(w + 0x41AC)) = value;
    }
}

void SCRFuncPoseidonResetPlayerTerrLog(void *actor)
{
    (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41AC)) = 0;
}

int SCRConditionPoseidonGetPlayerTerrLog(void *a, int n)
{
    char *w = GetSCRCharaAIWorkPtr(a);

    if (n == 1) {
        return *(int *)(w + 0x41AC) == 1;
    }
    if (n == 2) {
        return *(int *)(w + 0x41AC) == 2;
    }
    return 0;
}

void SCRFuncPoseidonAngryCountAdd(void *actor)
{
    void *temp_v0;

    temp_v0 = GetSCRCharaAIWorkPtr(actor);
    (*(int *)((char *)(temp_v0) + 0x41B0)) = (int) ((*(int *)((char *)(temp_v0) + 0x41B0)) + 1);
}

void SCRFuncPoseidonAngryCountInit(void *actor)
{
    (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41B0)) = 0;
}

int SCRConditionPoseidonAngryCountChack(int a, int n)
{
    return *(int *)(((char *)GetSCRCharaAIWorkPtr((void *)a)) + 0x41B0) < n;
}

int SCRConditionPoseidonDamageCoreTime(void *actor, float fparg0)
{
    int var_v0;

    var_v0 = 1;
    if (!(fparg0 <= (*(float *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41B4)))) {
        var_v0 = 0;
    }
    return var_v0;
}

void SCRConditionPoseidonDamageFlagSet(void *actor)
{
    (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41A0)) = 1;
}

void SCRConditionPoseidonDamageFlagReset(void *actor)
{
    char *w = ((char *)GetSCRCharaAIWorkPtr(actor));

    *(int *)(w + 0x41A0) = 0;
    *(int *)(w + 0x41B4) = 0;
}

void SCRConditionPoseidonDamageCoreTimeMain(void *actor)
{
    void *temp_v0;

    temp_v0 = GetSCRCharaAIWorkPtr(actor);
    if ((*(int *)((char *)(temp_v0) + 0x41A0)) != 0) {
        (*(float *)((char *)(temp_v0) + 0x41B4)) = (float) ((*(float *)((char *)(temp_v0) + 0x41B4)) + (*(float *)((char *)(gcGlobalVar) + 0x180)));
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0120_SCRConditoinPoseidonPlayerRayChack", func_400A43D0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0120_SCRConditoinPoseidonPlayerRayChack", progressive_check_script);

void _SCRStartSpriteMenuAnim(s32 obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
extern s32 ScriptSpriteMenuObjDef_SPRITE_BOOT_PROGRESSIVE_ALERT;

void bootprogressivecheck(s32 a)
{
    _SCRStartSpriteMenuAnim(ScriptSpriteMenuObjDef_SPRITE_BOOT_PROGRESSIVE_ALERT, 0, 0, a, 0, 0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0120_SCRConditoinPoseidonPlayerRayChack", func_400A4778);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0120_SCRConditoinPoseidonPlayerRayChack", func_400A4A00);

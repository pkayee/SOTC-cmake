#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0161_nico_kameBodyExpression", nico_kameBodyExpression);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0161_nico_kameBodyExpression", SCRFuncKameRockLWSLoad);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0161_nico_kameBodyExpression", SCRConditionKameBattleAreaEscape);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0161_nico_kameBodyExpression", nico_bossTortoiseAIMain);
void nico_bossTortoiseAIMain(s32 *a0)
{
    void *thread;

    isysGetThisSubThread();
    for (;;)
    {
        thread = isysGetThisSubThread();
        SCRExecBossPreProcess(*a0);
        CharaCtrlResetAllScriptCtrlStatus(thread);
        updateScriptDataSystem(thread);
        *(u64 *)((u8 *)a0 + 0x4198) = 0;
        isysGetThisSubThread();
        SCRExecBossPostProcess(*a0);
        scrRunM(1);
    }
}

extern char gcGlobalVar[];
extern int *isysGroupForFirst(void *, int);
extern int *isysGroupForNext(int *, int);
extern void isysGroupForExit(int, int);
extern void unloadObj(int);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0161_nico_kameBodyExpression", func_400D78E8);
void func_400D78E8(void)
{
    int m = 0;
    int *g;

    for (g = isysGroupForFirst(gcGlobalVar + 0x304, 0); g != 0; g = isysGroupForNext(g, 0))
    {
        m = *g;
        unloadObj(m);
    }
    if (m != 0)
        isysGroupForExit(m, 0);
}

extern void RequestCharacterMotionShiftFunc(void *character, void (*func)(void *character));

extern void func_400D81E0(void *character);

void SCRTortoiseShoot(void *character)
{
    RequestCharacterMotionShiftFunc(character, func_400D81E0);
}

extern void func_400D8218(void *character);

void SCRTortoisePulseCharge(void *character)
{
    RequestCharacterMotionShiftFunc(character, func_400D8218);
}

extern void func_400D8278(void *character);

void SCRTortoisePulseChargeStop(void *character)
{
    RequestCharacterMotionShiftFunc(character, func_400D8278);
}

extern int DldSysUndefSymbol;
extern char *GetSCRCharaAIWorkPtr(void *);
extern void GetScriptAnimationSubObjectWithTypeFiltering(int, int, void *, void *);
extern void func_400D8088();

void SCRFuncTortoiseGeyserDamagedMain(void *a, int b, int c, int d, int e, int *h)
{
    char *ai = GetSCRCharaAIWorkPtr(a);
    int off = *h & 0x3FFFF;
    int *t = off != 0 ? *(int **)((char *)h - off) : 0;
    int *g = (t != 0 && t != (int *)DldSysUndefSymbol) ? (int *)t[4] : 0;
    *(int *)(ai + 0x4190) = 0;
    GetScriptAnimationSubObjectWithTypeFiltering(g[2], 2, func_400D8088, ai);
}

int SCRConditionTortoiseGeyserDamaged(void *actor)
{
    return *(int *)(GetSCRCharaAIWorkPtr(actor) + 0x4190);
}

int SCRConditionTortoiseGeyserHitColAttr(void *actor, int a, int b, int c, long mask, long value)
{
    return value == (mask & *(long *)(GetSCRCharaAIWorkPtr(actor) + 0x4198));
}

/* NEARMISS-STUB SCRFuncKameFallPatienceCunterInit */
#if 0 /* NEARMISS 97.06% cat=stack-frame sub=- | in-TU: extra addiu sp,sp,0x20 vs exp; offset edit 0x41C0->0x41A0 applied | attempts=1 */

extern char *GetSCRCharaAIWorkPtr(void *);
s32 _gameFlagChk();

void SCRFuncKameFallPatienceCunterInit(void *a, f32 base, f32 add)
{
    char *ai = GetSCRCharaAIWorkPtr(a);

    *(f32 *)(ai + 0x41A0) = base;
    if (_gameFlagChk(0x117) || _gameFlagChk(0x118) || _gameFlagChk(0x119) || _gameFlagChk(0x11A))
        *(f32 *)(ai + 0x41A0) += add;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0161_nico_kameBodyExpression", SCRFuncKameFallPatienceCunterInit);

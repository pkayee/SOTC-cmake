#include "common.h"

/* NEARMISS-STUB func_400D7B48 */
#if 0 /* NEARMISS 0.0% cat=no-c-form sub=- | 8-byte tail of prior fn: addiu sp,+0x20 then nop; no C form | attempts=1 */
void func_400D7B48(void)
{
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", func_400D7B48);

extern void *GetSCRCharaAIWorkPtr(void *);
extern u8 gcGlobalVar[];

void SCRFuncKameFallPatienceCunterMain(void *actor)
{
    f32 temp_f1;
    void *temp_v0;

    temp_v0 = GetSCRCharaAIWorkPtr(actor);
    temp_f1 = *(f32 *)((u8 *)temp_v0 + 0x41A0);
    if (temp_f1 > 0.0f) {
        *(f32 *)((u8 *)temp_v0 + 0x41A0) = temp_f1 - *(f32 *)(gcGlobalVar + 0x180);
    }
}

int SCRConditionKameFallPatienceCunterCheck(void *actor)
{
    char *w = GetSCRCharaAIWorkPtr(actor);
    int r = 1;
    if (!(0.0f < *(float *)(w + 0x41A0)))
        r = 0;
    return r;
}

/* NEARMISS-STUB SCRFuncKameSetMissileRadius */
#if 0 /* NEARMISS 93.1% cat=branch-layout sub=- | work ptr reg v0 vs v1 swap; p2 store should be likely-branch delay slot | attempts=1 */
void SCRFuncKameSetMissileRadius(f32 param_1, f32 param_2, f32 param_3)
{
    void *GetSCRCharaAIWorkPtr();
    s32 v;
    void *work;

    work = GetSCRCharaAIWorkPtr();
    if (param_1 != 0.0f) {
        *(s32 *)((u8 *)work + 0x41A4) = 0;
    } else {
        v = 1;
        if (param_2 != 0.0f) {
            *(s32 *)((u8 *)work + 0x41A4) = 1;
            return;
        }
        v = 2;
        if (param_3 != 0.0f) {
            *(s32 *)((u8 *)work + 0x41A4) = v;
        }
    }
    return;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", SCRFuncKameSetMissileRadius);

void SCRFuncKameDemoFlagSet(void *actor)
{
    (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41B8)) = 1;
}

void SCRFuncKameDemoFlagReset(void *actor)
{
    (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41B8)) = 0;
}

extern void RequestCharacterMotionShiftFunc(void *character, void (*func)(void *character));
void func_400D8298(void *character);

void SCRFallRockDelete(void *character)
{
    RequestCharacterMotionShiftFunc(character, func_400D8298);
}

void func_400D82E8(void *character);

void SCRFallRockSub(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_400D82E8);
}

extern u8 *GetCharacterClass(void *);
extern void *SCRGetFirstObj(void *);

void SCRSetCrackAnimTimer(void)
{
    void *boss;
    u8 *work;

    boss = SCRGetFirstObj(gcGlobalVar + 0x2B8);
    if (boss == 0) {
        return;
    }
    work = GetSCRCharaAIWorkPtr(boss);
    if ((*(s64 *)(GetCharacterClass(boss) + 0x680) & 0x01E00000) == 0x200000) {
        *(f32 *)(work + 0x41AC) += 0.5f;
    } else {
        *(f32 *)(work + 0x41AC) = 0.0f;
    }
    if (*(f32 *)(work + 0x41AC) > 5.0f) {
        *(f32 *)(work + 0x41AC) = 5.0f;
    }
}

int SCRConditionKameCrackAnimChack(void *actor)
{
    char *w = GetSCRCharaAIWorkPtr(actor);
    int r = 1;
    if (!(0.0f < *(float *)(w + 0x41AC)))
        r = 0;
    return r;
}

void SCRFuncKameCrackAnimMain(void *actor)
{
    f32 temp_f1;
    void *temp_v0;

    temp_v0 = GetSCRCharaAIWorkPtr(actor);
    temp_f1 = *(f32 *)((u8 *)temp_v0 + 0x41AC);
    if (temp_f1 > 0.0f) {
        *(f32 *)((u8 *)temp_v0 + 0x41AC) = temp_f1 - *(f32 *)(gcGlobalVar + 0x180);
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", SCRFuncKameSetTemporaryTarget);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", SCRConditionKameNextTemporaryTarget);
extern void *getSCRDataCtrlWork(void *);

int SCRConditionKameNextTemporaryTarget(void *actor, s32 n)
{
    return (int)*(f32 *)((u8 *)getSCRDataCtrlWork(actor) + 0x4084) % n < 1;
}

int SCRConditionKameWallCaseFlagChack(void *actor)
{
    return (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41B4));
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", func_400D8088);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", func_400D81B0);
s64 *GetCollisionDBAttributeAdr(void);

s32 func_400D81B0(void)
{
    return (*GetCollisionDBAttributeAdr() & 0x3F0) == 0x160;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", func_400D81E0);
extern void func_400D6CE8(void *actor, s32 a1, s32 a2);
extern s32 SkelFocusDef_BOSS_HEAD;

void func_400D81E0(void *actor)
{
    void *temp_v0;
    u8 *temp_v1;

    temp_v0 = GetSCRCharaAIWorkPtr(actor);
    temp_v1 = *(u8 **)((u8 *)temp_v0 + 0x406C);
    func_400D6CE8(actor, *(s32 *)(temp_v1 + 0x134), SkelFocusDef_BOSS_HEAD);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", func_400D8218);
extern void *GetSCRCharaAIWorkPtr(void *);
extern s32 _SCRSetupLWSWithTargetNodeParent(s32, void *, s32);
extern void _SCRStartLWS(s32, s32, s32, s32);
extern s32 ScriptAnimationObjDef_TTS_PLS_CHARGE;

void func_400D8218(void *actor)
{
    void *temp_s1;
    s32 temp_v0;

    temp_s1 = GetSCRCharaAIWorkPtr(actor);
    temp_v0 = _SCRSetupLWSWithTargetNodeParent(ScriptAnimationObjDef_TTS_PLS_CHARGE, actor, SkelFocusDef_BOSS_HEAD);
    *(s32 *)((u8 *)temp_s1 + 0x41B0) = temp_v0;
    _SCRStartLWS(temp_v0, -1, 3, 0);
}

extern void isysRequestDeleteObj(s32 obj);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", func_400D8278);
void func_400D8278(void *actor)
{
    isysRequestDeleteObj(*(s32 *)((u8 *)GetSCRCharaAIWorkPtr(actor) + 0x41B0));
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", func_400D8298);
void func_400D8298(void *character)
{
    void *boss;
    void *work;

    boss = SCRGetFirstObj(gcGlobalVar + 0x2B8);
    if (boss != 0) {
        work = GetSCRCharaAIWorkPtr(boss);
        if (*(s32 *)((u8 *)work + 0x41B8) == 0) {
            isysRequestDeleteObj((s32)character);
        }
    }
    return;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", func_400D82E8);
void func_400D82E8(void *character)
{
    void *boss;
    u8 *work;

    boss = SCRGetFirstObj(gcGlobalVar + 0x2B8);
    if (boss != 0) {
        work = GetSCRCharaAIWorkPtr(boss);
        if (*(s32 *)(work + 0x41B8) == 0) {
            if (*(s32 *)(work + 0x41A8) > 0) {
                *(s32 *)(work + 0x41A8) = *(s32 *)(work + 0x41A8) - 1;
            }
        }
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", func_400D8338);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0162_func_400D7B48", nico_unagiBossStart);

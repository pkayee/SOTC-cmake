#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0165_func_400DA5B8", func_400DA5B8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0165_func_400DA5B8", SCRFuncYamoriBProgramRotForWindAttack);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0165_func_400DA5B8", func_400DAFA0);

extern void RequestCharacterMotionShiftFunc(void *character, void (*func)(void *character));
extern void func_400DC2E0(void *character);

void SCRYamori2BeginStand(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_400DC2E0);
}

extern void func_400DA118(void *character);

void SCRYamoriBReadyToBreeze(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_400DA118);
}

extern void func_400DC2E8(void *character);

void SCRYamoriBReadyToBreeze2(void *character)
{
    RequestCharacterMotionShiftFunc(character, &func_400DC2E8);
}

extern void *GetSCRCharaAIWorkPtr(void *);

void SCRFuncYamoriBDamageCheckInit(void *actor)
{
    float *slot;
    int count;

    slot = (float *)((char *)GetSCRCharaAIWorkPtr(actor) + 0x419C);
    count = 3;
    do {
        count -= 1;
        *slot = -1.0f;
        slot -= 1;
    } while (count >= 0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0165_func_400DA5B8", SCRFuncYamoriBDamageCheckMain);

int SCRConditionYamoriBDamageCheckFrontR(void *actor)
{
    char *w = GetSCRCharaAIWorkPtr(actor);
    int r = 1;
    if (!(0.0f <= *(float *)(w + 0x4190)))
        r = 0;
    return r;
}

int SCRConditionYamoriBDamageCheckBackR(void *actor)
{
    char *w = GetSCRCharaAIWorkPtr(actor);
    int r = 1;
    if (!(0.0f <= *(float *)(w + 0x4194)))
        r = 0;
    return r;
}

int SCRConditionYamoriBDamageCheckFrontL(void *actor)
{
    char *w = GetSCRCharaAIWorkPtr(actor);
    int r = 1;
    if (!(0.0f <= *(float *)(w + 0x4198)))
        r = 0;
    return r;
}

int SCRConditionYamoriBDamageCheckBackL(void *actor)
{
    char *w = GetSCRCharaAIWorkPtr(actor);
    int r = 1;
    if (!(0.0f <= *(float *)(w + 0x419C)))
        r = 0;
    return r;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0165_func_400DA5B8", SCRFuncYamoriBSendKLeftStandUpLey);

void SCRFuncYamoriBSetCalcPosOffset(void *actor, float fparg0)
{
    (*(float *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41A4)) = fparg0;
}

extern void *getSCRDataCtrlWork(void *);
extern void func_400DA5B8(void *actor, s128 *pos, int flag, int point);
extern void setAttainmentPos(void *work, s128 *pos);

void SCRFuncYamoriBSetAttainPointForAttack(void *actor, int a1, int point)
{
    s128 pos;
    char *ai;
    char *work;

    ai = GetSCRCharaAIWorkPtr(actor);
    work = getSCRDataCtrlWork(actor);
    func_400DA5B8(actor, &pos, 1, point);
    setAttainmentPos(work, &pos);
    *(s128 *)(ai + 0x41D0) = pos;
    *(int *)(ai + 0x41A8) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0165_func_400DA5B8", SCRFuncYamoriBSetAttainPointForWindAttack);

s32 memcmp(const void *a, const void *b, u32 n);

int SCRConditionYamoriBChangeAttainPointForAttack(void *actor, int a1, int point)
{
    s128 pos;
    char *work;

    work = GetSCRCharaAIWorkPtr(actor);
    func_400DA5B8(actor, &pos, 1, point);
    return memcmp(&pos, work + 0x41D0, 16) != 0;
}

void SCRFuncYamoriBSetBreathVolume(void *actor, int a, int b, int c, int d, int e, int volume)
{
    *(int *)((char *)GetSCRCharaAIWorkPtr(actor) + 0x41AC) = volume;
}

extern char *GetLayoutClass(void *);
extern char *GetCharacterClass(void *);

void SCRFuncYamoriBGounrdAttackMain(void *a)
{
    char *c, *p;
    unsigned long m;
    if (*(int *)(GetLayoutClass(a) + 0x124) == 0)
        return;
    c = GetCharacterClass(a);
    m = *(unsigned long *)(c + 0x680) & 0x1E00000;
    p = *(char **)(c + 0x1064);
    if (m == 0xC00000 || m == 0xA00000)
        *(float *)(p + 0x38) = 0.0f;
    else
        *(float *)(p + 0x38) = 1.0f;
}

void SCRFuncYamoriBSetRandomRadius(void *actor, float fparg0, float fparg1)
{
    void *temp_v0;

    temp_v0 = GetSCRCharaAIWorkPtr(actor);
    (*(float *)((char *)(temp_v0) + 0x41B8)) = fparg0;
    (*(float *)((char *)(temp_v0) + 0x41BC)) = fparg1;
    (*(int *)((char *)(temp_v0) + 0x41B0)) = 1;
    (*(int *)((char *)(temp_v0) + 0x41B4)) = 0;
}

void SCRFuncYamoriBSetRandomRadius2(void *actor, float first, float second)
{
    void *work;

    work = GetSCRCharaAIWorkPtr(actor);
    *(float *)((char *)work + 0x41B8) = first;
    *(float *)((char *)work + 0x41BC) = second;
    *(int *)((char *)work + 0x41B0) = 1;
    *(int *)((char *)work + 0x41B4) = 1;
}

void SCRFuncYamoriBUnsetRandom(void *actor)
{
    char *w = ((char *)GetSCRCharaAIWorkPtr(actor));

    *(int *)(w + 0x41B0) = 0;
    *(int *)(w + 0x41B4) = 0;
}

void SCRFuncYamoriBSetAttackPosAndGazePosInit(void *actor)
{
    (*(int *)((char *)(GetSCRCharaAIWorkPtr(actor)) + 0x41A0)) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0165_func_400DA5B8", SCRFuncYamoriBSetAttackPosAndGazePosMain);

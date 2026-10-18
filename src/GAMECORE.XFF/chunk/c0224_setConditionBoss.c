#include "common.h"

extern int execCondition();
extern int setConditionResultBoss();
extern int setConditionResultHorse();
extern int _gameWorkSet();
extern void *getSCRDataCtrlWork(void *);
extern void setSCRAttainRange(void *, unsigned int *);

int setConditionBoss(int a, int b, int c, int d, int e, int f, int g)
{
    return setConditionResultBoss(execCondition(a, g));
}

int setConditionHorse(int a, int b, int c, int d, int e, int f, int g)
{
    return setConditionResultHorse(execCondition(a, g));
}

int SCRFuncSetGameWork(int a, int b, int c, int d)
{
    return _gameWorkSet(b, c, c, d);
}

void SCRFuncSetAttainRange(void *a, int b, int c, int d, int e, int f, int g, unsigned int *h)
{
    setSCRAttainRange(getSCRDataCtrlWork(a), h);
}

extern void *GetCollisionDBAttributeAdr();

int func_4011EB70(int a, long *b)
{
    return b[1] == (*(long *)GetCollisionDBAttributeAdr() & b[0]);
}

int func_4011EBB0(int a, u64 *b)
{
    return !((*(u64 *)GetCollisionDBAttributeAdr() & b[0]) < b[1]);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0224_setConditionBoss", initScriptDataSystem);

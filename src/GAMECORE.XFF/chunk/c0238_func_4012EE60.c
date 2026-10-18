#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0238_func_4012EE60", func_4012EE60);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0238_func_4012EE60", nico_calcWormGenealogicalNodeDownHead);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0238_func_4012EE60", nico_calcWormGenealogicalNodeDownNext);

extern void *GetSCRCharaAIWorkPtr(void *);

void *getWormIKWork(void *actor)
{
    return (void *)(((int)GetSCRCharaAIWorkPtr(actor) + 0x4193) & ~0xF);
}

void setWormIKBoundDynamics(char *p, float f1, float f2, float f3)
{
    *(float *)(p + 0x1260) = f1;
    *(float *)(p + 0x1264) = f2;
    *(float *)(p + 0x1268) = f3;
}

void setWormIKNodeLimit(char *w, float limit)
{
    int i;
    char *p = w + 0x9F0;

    for (i = 31; i >= 0; i--) {
        *(float *)p = limit;
        p -= 0x50;
    }
}

void setWormIKBankInterpSec(void *arg0, float fparg0)
{
    (*(float *)((char *)(arg0) + 0x126C)) = fparg0;
}

s64 *GetCollisionDBAttributeAdr(void);

s32 coliJudgeNotWater(void)
{
    return (*GetCollisionDBAttributeAdr() & 0x7C00) != 0x4400;
}

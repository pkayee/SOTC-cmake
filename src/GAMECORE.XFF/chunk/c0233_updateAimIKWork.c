#include "common.h"

extern char *GetCharacterClass(void *);
extern char D_4021E290[];
extern void GetMotionNodeQuaternionPos(void *, void *, int, int, int);

void updateAimIKWork(void *a, s128 *v)
{
    **(s128 **)(GetCharacterClass(a) + 0x1068) = *v;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0233_updateAimIKWork", updateAimIKWork);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0233_updateAimIKWork", getAimIKWork);

int getAimIKWork(void *actor)
{
    return (*(int *)((char *)(GetCharacterClass(actor)) + 0x1068));
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0233_updateAimIKWork", getSizeAimIKWork);

int getSizeAimIKWork(void)
{
    return 0x30;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0233_updateAimIKWork", initAimIKWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0233_updateAimIKWork", nico_attackIK_waist);

void updateAttackWaistIKWork(void *a, s128 *v)
{
    **(s128 **)(GetCharacterClass(a) + 0x1068) = *v;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0233_updateAimIKWork", updateAttackWaistIKWork);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0233_updateAimIKWork", getSizeAttackIKWork);

int getSizeAttackIKWork(void)
{
    return 0x30;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0233_updateAimIKWork", initAttackWaistIKWork);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0233_updateAimIKWork", nico_attackIK_optBone);

void nico_attackIK_optBone(int *p)
{
    int buf[4] __attribute__((aligned(16)));

    GetMotionNodeQuaternionPos(D_4021E290, buf, p[0], p[5], 0);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0233_updateAimIKWork", nico_BeardTop);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0233_updateAimIKWork", nico_BeardNext);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0233_updateAimIKWork", nico_BeardLast);

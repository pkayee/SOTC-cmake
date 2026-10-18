#include "common.h"

void lizard_head(void) {
}

extern int func_400C0D68(float);

int lizard_chest(void)
{
    return func_400C0D68(0.7f);
}

void lizard_waist(void) {
}

void lizard_tail(void *obj)
{
    ((void (*)(void *, float))func_400C0D68)(obj, 0.5f);
}

void lizard_berry(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0143_lizard_head", func_400C1D60);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0143_lizard_head", func_400C1F78);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0143_lizard_head", func_400C2150);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0143_lizard_head", nico_SmallLizardTailStart);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0143_lizard_head", gextailUpdateQuat);

extern int SetCharacterObjCollisionProcFlag();

int gextailStopColProc(int a, int b, int c, int d)
{
    return SetCharacterObjCollisionProcFlag(a, 0, c, d);
}

int gextailStartColProc(int a, int b, int c, int d)
{
    return SetCharacterObjCollisionProcFlag(a, 1, c, d);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0143_lizard_head", updateSmallManager);

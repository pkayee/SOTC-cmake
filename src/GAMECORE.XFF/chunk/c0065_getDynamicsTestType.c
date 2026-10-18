#include "common.h"

extern unsigned char D_401315B8[];
extern unsigned char D_401315BC[];
extern unsigned char D_401315C0[];
extern unsigned char D_401315C4[];

void *getDynamicsTestType(void)
{
    return D_401315B8;
}

void *getPendulumGravityRatio(void)
{
    return D_401315BC;
}

void *getPendulumAirResistRatio(void)
{
    return D_401315C0;
}

void *getPendulumSideFriction(void)
{
    return D_401315C4;
}

void dynamicstest(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0065_getDynamicsTestType", func_4005F690);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0065_getDynamicsTestType", func_4005FAF8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0065_getDynamicsTestType", func_4005FF20);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0065_getDynamicsTestType", func_4005FFE8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0065_getDynamicsTestType", func_40060280);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0065_getDynamicsTestType", func_40060418);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0065_getDynamicsTestType", func_400605F8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0065_getDynamicsTestType", func_40060A68);

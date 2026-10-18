#include "common.h"

extern u8 D_401ABD00[];
extern u8 D_401ABD04[];
extern u8 D_401ABD08[];
extern u8 D_401ABD10[];
extern u8 D_401ABD14[];
extern u8 D_401ABD18[];
extern u8 D_401ABD20[];
extern u8 D_401ABD24[];
extern u8 D_401ABD28[];
extern void func_4002A9B0();
extern u8 D_401ABD30[];
extern u8 D_401ABD34[];
extern u8 D_401ABD38[];
extern u8 D_40129FA0[];
extern u8 D_40129FA4[];
extern u8 D_40129FA8[];
extern u8 D_40129FB0[];
extern u8 D_40129FB4[];
extern u8 D_40129FB8[];
extern u8 D_40129FC0[];
extern u8 D_40129FC4[];
extern u8 D_40129FC8[];
extern float D_40129F90;
extern u8 D_401ABD40[];
extern u8 D_401ABD44[];
extern u8 D_401ABD48[];
extern u8 D_401ABD4C[];
extern u8 D_4012A010[];

void setSpecularity(float fparg0)
{
    D_40129F90 = fparg0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getAmbientColor);

void *lightsw0(void)
{
    return D_401ABD40;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlc0_r);
u8 *getlc0_r(void)
{
    return D_401ABD00;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlc0_g);
u8 *getlc0_g(void)
{
    return D_401ABD04;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlc0_b);
u8 *getlc0_b(void)
{
    return D_401ABD08;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlv0_h);
u8 *getlv0_h(void)
{
    return D_40129FA0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlv0_p);
u8 *getlv0_p(void)
{
    return D_40129FA4;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlv0_b);
u8 *getlv0_b(void)
{
    return D_40129FA8;
}

void *lightsw1(void)
{
    return D_401ABD44;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlc1_r);
u8 *getlc1_r(void)
{
    return D_401ABD10;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlc1_g);
u8 *getlc1_g(void)
{
    return D_401ABD14;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlc1_b);
u8 *getlc1_b(void)
{
    return D_401ABD18;
}

u8 *getlv1_h(void)
{
    return D_40129FB0;
}

void *getlv1_p(void)
{
    return D_40129FB4;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlv1_b);
u8 *getlv1_b(void)
{
    return D_40129FB8;
}

void *lightsw2(void)
{
    return D_401ABD48;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlc2_r);
u8 *getlc2_r(void)
{
    return D_401ABD20;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlc2_g);
u8 *getlc2_g(void)
{
    return D_401ABD24;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlc2_b);
u8 *getlc2_b(void)
{
    return D_401ABD28;
}

void *getlv2_h(void)
{
    return D_40129FC0;
}

void *getlv2_p(void)
{
    return D_40129FC4;
}

void *getlv2_b(void)
{
    return D_40129FC8;
}

void *lightsw3(void)
{
    return D_401ABD4C;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getamb_r);
u8 *getamb_r(void)
{
    return D_401ABD30;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getamb_g);
u8 *getamb_g(void)
{
    return D_401ABD34;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getamb_b);
u8 *getamb_b(void)
{
    return D_401ABD38;
}

void setLightParamDefault(void)
{
    func_4002A9B0();
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", rotLightVector);

void CopyAmbFromAmbdef(void)
{
    *(s128 *)D_4012A010 = *(s128 *)D_401ABD30;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getLightVector);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", debugLineObjectCreateAndSetAttributreIfChange);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", lineObjectCreatef);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", lineObjectDispImmediate);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", func_4002C4C8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", func_4002C690);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", func_4002C858);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", func_4002CA18);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", func_4002CC50);

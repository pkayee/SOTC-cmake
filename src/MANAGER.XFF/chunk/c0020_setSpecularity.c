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
extern u8 D_401ABD30[];
extern u8 D_401ABD34[];
extern u8 D_401ABD38[];
extern u8 D_40129FA0[];
extern u8 D_40129FA4[];
extern u8 D_40129FA8[];
extern u8 D_40129FB8[];

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", setSpecularity);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getAmbientColor);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", lightsw0);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", lightsw1);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlv1_h);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlv1_p);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlv1_b);
u8 *getlv1_b(void)
{
    return D_40129FB8;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", lightsw2);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlv2_h);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlv2_p);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getlv2_b);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", lightsw3);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", setLightParamDefault);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", rotLightVector);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", CopyAmbFromAmbdef);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", getLightVector);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", debugLineObjectCreateAndSetAttributreIfChange);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", lineObjectCreatef);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", lineObjectDispImmediate);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", func_4002C4C8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", func_4002C690);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", func_4002C858);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", func_4002CA18);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0020_setSpecularity", func_4002CC50);

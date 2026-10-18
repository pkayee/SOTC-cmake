#include "common.h"

extern unsigned char D_4012A98C[];
extern unsigned char D_4012A990[];
extern unsigned char D_4012A994[];
extern unsigned char D_4012A998[];
extern unsigned char D_4012A99C[];
extern unsigned char D_4012A9A0[];

void *getZFogDivide(void)
{
    return D_4012A98C;
}

void *getZFogWidth(void)
{
    return D_4012A990;
}

void *getZFogFarMargin(void)
{
    return D_4012A994;
}

void *getZFogFar(void)
{
    return D_4012A9A0;
}

void *getZFogScissorMargin(void)
{
    return D_4012A998;
}

void *getBgFogOffset(void)
{
    return D_4012A99C;
}

void setZFogFar(float fparg0)
{
    *(float *)D_4012A9A0 = fparg0;
}

void zFogInit(void) {
}

float getZFogNear(void)
{
    return (*(float *)D_4012A9A0 - *(float *)D_4012A994) - *(float *)D_4012A990;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0040_getZFogDivide", func_40043360);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0040_getZFogDivide", func_40043588);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0040_getZFogDivide", func_40043F08);

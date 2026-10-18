#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0032_solarFlareReset", solarFlareReset);

extern s32 D_4012A5B0;
extern void func_400366D0(void);
extern void func_40037F38(void);

void solarFlare(void)
{
    int m;
    switch (D_4012A5B0) {
    case 0:
        break;
    case 1:
        func_400366D0();
        break;
    case 2:
        func_40037F38();
        m = 0;
        break;
    }
}

void *getSolarFlareSw(void)
{
    return &D_4012A5B0;
}

extern unsigned char D_4012A5BC[];

void *getSolarFlareBlur(void)
{
    return D_4012A5BC;
}

extern unsigned char D_4012A5C8[];

void *getSolarFlareColorR(void)
{
    return D_4012A5C8;
}

extern unsigned char D_4012A5CC[];

void *getSolarFlareColorG(void)
{
    return D_4012A5CC;
}

extern unsigned char D_4012A5D0[];

void *getSolarFlareColorB(void)
{
    return D_4012A5D0;
}

extern unsigned char D_4012A5C0[];

void *getSolarFlareSolarLevel(void)
{
    return D_4012A5C0;
}

extern unsigned char D_4012A5C4[];

void *getSolarGlowLevel(void)
{
    return D_4012A5C4;
}

extern unsigned char D_4012A5B8[];

void *getSolarFlareSamplePix(void)
{
    return D_4012A5B8;
}

extern unsigned char D_4012A5B4[];

void *getSolarFlarePanelZ(void)
{
    return D_4012A5B4;
}

extern char FBOfs[];

char *getSolarFlareReduceOfsU(void)
{
    return FBOfs;
}

char *getSolarFlareReduceOfsV(void)
{
    return FBOfs + 0x4;
}

char *getSolarFlareZoomOfsU(void)
{
    return FBOfs + 0x8;
}

char *getSolarFlareZoomOfsV(void)
{
    return FBOfs + 0xC;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0032_solarFlareReset", func_40039C28);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0032_solarFlareReset", func_40039EF8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0032_solarFlareReset", spriteCreateObject);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0032_solarFlareReset", func_4003A2D8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0032_solarFlareReset", func_4003A408);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0032_solarFlareReset", func_4003A5C0);

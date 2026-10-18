#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0035_spriteSetValue", spriteSetValue);

extern int iosFree();

int spriteDeleteObject(int a, int b, int c, int d)
{
    return iosFree(a, b, c, d);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0035_spriteSetValue", spriteSetPosition);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0035_spriteSetValue", spriteSetTextureCoordinateST);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0035_spriteSetValue", spriteSetTextureCoordinateSTFromUV);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0035_spriteSetValue", spriteSetTextureCoordinateUV);

void spriteSetColor(char *p, int a1, int a2, int a3, int a4)
{
    *(char *)(p + 0xC) = a1;
    *(char *)(p + 0xD) = a2;
    *(char *)(p + 0xE) = a3;
    *(char *)(p + 0xF) = a4;
}

void spriteSetScale(char *p, float f1, float f2)
{
    *(float *)(p + 0x50) = f1;
    *(float *)(p + 0x54) = f2;
}

void spriteSetRotation(void *arg0, float fparg0)
{
    (*(float *)((char *)(arg0) + 0x4C)) = fparg0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0035_spriteSetValue", spriteSetBlendMode);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0035_spriteSetValue", spriteSetIdentifier);

void spriteSetFade(void *arg0, float fparg0)
{
    (*(float *)((char *)(arg0) + 0x64)) = fparg0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0035_spriteSetValue", spriteSetPriority);

extern unsigned char D_4012A670[];

void *getSpriteDispFlag(void)
{
    return D_4012A670;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0035_spriteSetValue", texTransResolve);

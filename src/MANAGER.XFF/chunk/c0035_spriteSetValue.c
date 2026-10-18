#include "common.h"

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0035_spriteSetValue", spriteSetValue);
void spriteSetValue(u8 *sprite, s32 value)
{
    *(s32 *)(sprite + 0x4) = value;
}

extern int iosFree();

int spriteDeleteObject(int a, int b, int c, int d)
{
    return iosFree(a, b, c, d);
}

/* MANAGER c0035 sprite obj: +0x30 x, +0x34 y, +0x38 z=1.0 */
void spriteSetPosition(char *p, float x, float y)
{
    *(float *)(p + 0x30) = x;
    *(float *)(p + 0x34) = y;
    *(float *)(p + 0x38) = 1.0f;
}

/* MANAGER c0035: ST rect at +0x20..+0x2C, flags u64 at +0x68 |= 0x10 (statement order from 120-perm search) */
void spriteSetTextureCoordinateST(char *p, float s, float t, float ds, float dt)
{
    *(float *)(p + 0x20) = s;
    *(float *)(p + 0x24) = t;
    *(u64 *)(p + 0x68) |= 0x10;
    *(float *)(p + 0x28) = s + ds;
    *(float *)(p + 0x2C) = t + dt;
}

/* MANAGER c0035: texture size from p->tex(+0x0)->+0x20->+0x1C (log2 w at bits16-19, log2 h at 20-23); UV (+0.5 texel) -> ST.
 * Use (u + du) * iw inline (named du = u + du temp gives swapped add.s operands). */
void spriteSetTextureCoordinateSTFromUV(char *p, float u, float v, float du, float dv)
{
    u32 sz = *(u32 *)(*(char **)(*(char **)p + 0x20) + 0x1C);
    float w = (float)(1 << ((sz >> 16) & 0xF));
    float h = (float)(1 << ((sz >> 20) & 0xF));
    float iw = 1.0f / w;
    float ih = 1.0f / h;
    u += 0.5f;
    v += 0.5f;
    *(u64 *)(p + 0x68) |= 0x10;
    *(float *)(p + 0x20) = u * iw;
    *(float *)(p + 0x28) = (u + du) * iw;
    *(float *)(p + 0x24) = v * ih;
    *(float *)(p + 0x2C) = (v + dv) * ih;
}

/* MANAGER c0035: UV rect as ints at +0x10..+0x1C, raw size floats at +0x40/+0x44, flags +0x68 &= ~0x10 (order from 5040-perm search) */
void spriteSetTextureCoordinateUV(char *p, float u, float v, float du, float dv)
{
    *(float *)(p + 0x40) = du;
    *(s32 *)(p + 0x10) = (s32)u;
    *(u64 *)(p + 0x68) &= ~0x10;
    *(s32 *)(p + 0x14) = (s32)v;
    *(s32 *)(p + 0x18) = (s32)(u + du);
    *(s32 *)(p + 0x1C) = (s32)(v + dv);
    *(float *)(p + 0x44) = dv;
}

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

/* MANAGER c0035: +0x60 = a; flags u64 at +0x68: bits0-1 = b, bits2-3 = c (u32 args widened to u64: dsll32/dsrl32).
 * The `t = (cc & 3) << 2` temp BEFORE the flag ops fixed the dsrl32 a3 scheduling (88.9 -> 100). */
void spriteSetBlendMode(char *p, s32 a, u32 b, u32 c)
{
    u64 bb = b;
    u64 cc = c;
    u64 f = *(u64 *)(p + 0x68);
    u64 t = (cc & 3) << 2;
    f &= ~3;
    f |= bb & 3;
    f &= ~0xC;
    f |= t;
    *(s32 *)(p + 0x60) = a;
    *(u64 *)(p + 0x68) = f;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0035_spriteSetValue", spriteSetIdentifier);
void spriteSetIdentifier(u8 *sprite, s32 id)
{
    *(s32 *)(sprite + 0x8) = id;
}

void spriteSetFade(void *arg0, float fparg0)
{
    (*(float *)((char *)(arg0) + 0x64)) = fparg0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0035_spriteSetValue", spriteSetPriority);
void spriteSetPriority(u8 *sprite, s32 value)
{
    *(s32 *)(sprite + 0x5C) = value;
}

extern unsigned char D_4012A670[];

void *getSpriteDispFlag(void)
{
    return D_4012A670;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0035_spriteSetValue", texTransResolve);

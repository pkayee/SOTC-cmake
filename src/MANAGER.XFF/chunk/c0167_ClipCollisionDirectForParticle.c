#include "common.h"

s32 ClipCollisionDirectCallBack();
s32 CollisionPlaneJudgeCallbackParticle();

extern char rootPtn[];
s32 CheckCollisionFinderAlive();
s32 InitCollisionFinder();

extern f32 D_401AD614;

extern s32 D_4012B504;

typedef union { s128 q; f32 f[4]; } Q4;
Q4 *GetGeometryPointerSurfacePlane();

void glBegin(s32);
void glSetReg(s64, s64);
void glDisable(s32);
void glEnd(void);
u8 *iosGetCurrentDC(void);

f32 glSetFogFactor(void *);
void glSetFogFactorDirect(s32);

extern char D_40134120[];
void *malloc_from_root_partition(s32, char *);
void sheetFileRead(void *, void *, s32);

s32 ClipCollisionDirectForParticle(s32 a0, s32 a1, s32 a2, s32 a3)
{
    return ClipCollisionDirectCallBack(a0, a1, a2, a3, 0, 0, 0, CollisionPlaneJudgeCallbackParticle, 0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0167_ClipCollisionDirectForParticle", func_400D2E50);

s32 func_400D2FC8(u8 *a) {
    if (CheckCollisionFinderAlive() != 0 || InitCollisionFinder(a, rootPtn, 0x40) != 0) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0167_ClipCollisionDirectForParticle", func_400D3018);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0167_ClipCollisionDirectForParticle", func_400D3178);

void func_400D3208(u8 *a, u8 *b, u8 *c) {
    u32 m = *(u32 *)(c + 0xc8);
    switch (m) {
    case 1:
        *(f32 *)(a + 4) = *(f32 *)(b + 0x14c);
        break;
    case 0:
        break;
    case 2:
        *(f32 *)(a + 4) = D_401AD614;
        break;
    }
}

f32 func_400D3248(f32 x) {
    f32 r = 1.0f;
    s32 n;
    if (x != 1.0f) {
        n = D_4012B504;
        if (n > 0) {
            do {
                n--;
                r *= x;
            } while (n != 0);
        }
    }
    return r;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0167_ClipCollisionDirectForParticle", func_400D3298);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0167_ClipCollisionDirectForParticle", func_400D3498);

void func_400D3608(Q4 *a, Q4 *b, u8 *c) {
    Q4 *p;
    a->q = ((Q4 *)(c + 0x40))->q;
    p = GetGeometryPointerSurfacePlane(c);
    b->q = p->q;
    b->f[3] = 0.0f;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0167_ClipCollisionDirectForParticle", func_400D3648);

s32 func_400D37A8(u8 *p) {
    if (*(s32 *)(p + 0x34) == 1 && *(s32 *)(p + 0xdc) == 0) {
        return 1;
    }
    return 2;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0167_ClipCollisionDirectForParticle", func_400D37D0);

f32 func_400D3958(u8 *p) {
    f32 t = *(f32 *)(p + 0x44);
    if (t < *(f32 *)(p + 0x58)) {
        return t * *(f32 *)(p + 0x60);
    }
    if (t < *(f32 *)(p + 0x5c)) {
        return 1.0f;
    }
    return (*(f32 *)(p + 0x40) - t) * *(f32 *)(p + 100);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0167_ClipCollisionDirectForParticle", func_400D39A8);

void func_400D3A70(void) {
    u8 *dc;
    glBegin(8);
    dc = iosGetCurrentDC();
    glSetReg(0x4e, 0x31000000 | *(s32 *)(dc + 0x164));
    glDisable(0);
    glDisable(3);
    glDisable(4);
    glEnd();
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0167_ClipCollisionDirectForParticle", func_400D3AC0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0167_ClipCollisionDirectForParticle", func_400D3B58);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0167_ClipCollisionDirectForParticle", func_400D3C00);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0167_ClipCollisionDirectForParticle", func_400D3C78);

void func_400D3F18(u8 *a, u8 *b) {
    s128 v = *(s128 *)(a + 0x10);
    f32 f = glSetFogFactor(&v);
    glSetFogFactorDirect(0xff - (s32)((255.0f - f) * *(f32 *)(b + 0x24)));
}

void *func_400D3F70(void *sheet, s32 size) {
    void *buf = malloc_from_root_partition(size, D_40134120);
    sheetFileRead(sheet, buf, size);
    return buf;
}

#include "common.h"

extern s32 DldSysUndefSymbol;
typedef struct PartSeg { s32 f0; s32 f4; s32 f8; s32 fC; } PartSeg;
extern PartSeg *func_400D1FA8(void);
extern s32 create_particle_texture_and_get_id(u8 *);
extern s32 func_400D1F30(u8 *, s32, u8 *, u8 *);

signed char CheckClothChainExist(void *arg0)
{
    return (*(signed char *)((char *)(arg0) + 6));
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", ResetClothDynamics);

extern void CopyGeometryPointer(char *, int, int, int);

void SetClothSingleFixedChainLeafFixGeometryPointer(char *p, int a, int b, int c)
{
    char *g = p + 0x30;
    g[0x40] = 1;
    CopyGeometryPointer(g, a, b, c);
    g[0x41] = 0;
}

void SetClothSingleFixedChainLeafFixNodeOffset(void *arg0, signed char arg1)
{
    (*(signed char *)((char *)(arg0) + 0x71)) = arg1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", getClothDynamics);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", clothmath_doubleTensionMove);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", create_particle_texture_and_get_id);

/* add_particle_segment: fill a free PartSeg from a npe file, then resolve each 0x54-byte emitter's texture links (dld link word at +0x20) */
void add_particle_segment(u8 *src)
{
    PartSeg *dst;
    s32 i;
    u8 *e;
    u8 *slot;
    u8 *tex;
    u32 d;
    u32 *lp;
    s32 n;

    if (src != 0) {
        i = 0;
        dst = func_400D1FA8();
        dst->f0 = *(s32 *)src;
        dst->f4 = (s32)src;
        n = *(s32 *)(src + 0xC);
        dst->f8 = n;
        dst->fC = *(s32 *)(src + 0x10);
        if (n > 0) {
            do {
                e = (u8 *)dst->fC + i * 0x54;
                lp = (u32 *)(e + 0x20);
                d = *lp & 0x3FFFF;
                slot = d ? *(u8 **)((u8 *)lp - d) : 0;
                if (slot != 0 && slot != (u8 *)DldSysUndefSymbol) {
                    tex = *(u8 **)(slot + 0x10) + ((*lp >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(slot + 8) + 0xC);
                } else {
                    tex = 0;
                }
                i++;
                *(s32 *)(e + 0x48) = func_400D1F30(e + 0xC, create_particle_texture_and_get_id(tex), src, e);
                *(s32 *)(e + 0x4C) = func_400D1F30(e + 0x1C, -1, src, e);
            } while (i < dst->f8);
        }
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CBA98);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", init_particle_manager);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", doit_particle_manager);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CC058);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CC1E8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CC348);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CC510);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CC6E8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CC948);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CCC28);

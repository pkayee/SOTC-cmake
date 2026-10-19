#include "common.h"

/* MPEG DMA/IPU reset: clear IPU, SPR DMA channels under DIntr, then sceIpuSync(0,0) tail call. c0208 needs cc=ee-gcc2.9-991111 (frameless tail jumps, see func_400FF4E8) */
s32 DIntr(void);
s32 EIntr(void);
void sceIpuSync(s32, s32);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208b_func_400FF4E8", func_400FF4E8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208b_func_400FF4E8", sceMpegCreate);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208b_func_400FF4E8", func_400FF7F0);

void func_400FF8F0(u8 *c) {
    s32 intr;

    *(s32 *)(c + 0x828) = 1;
    *(s32 *)(c + 0x1C0) = 0;
    intr = DIntr();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B000 = 0;
    *(volatile u32 *)0x1000B400 = 0;
    *(volatile u32 *)0x1000D400 = 0;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & 0xFFFEFFFF;
    if (intr != 0) {
        EIntr();
    }
    *(volatile u32 *)0x1000B020 = 0;
    *(volatile u32 *)0x1000B420 = 0;
    *(volatile u32 *)0x1000D420 = 0;
    *(volatile u32 *)0x10002010 = 0x40000000;
    sceIpuSync(0, 0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208b_func_400FF4E8", func_400FF9B8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208b_func_400FF4E8", func_400FFB70);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208b_func_400FF4E8", func_400FFE28);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208b_func_400FF4E8", func_400FFF98);

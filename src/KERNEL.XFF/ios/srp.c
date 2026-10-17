#include "common.h"

s32 iosWaitDMA(void);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/srp", iosSrpWaitDMA);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/srp", iosMemToSprDmaAdrCopy);
void iosMemToSprDmaAdrCopy(u32 a0, u32 a1, u32 a2)
{
    *(volatile u32 *)0x1000E020 = -0x400;
    *(volatile u32 *)0x1000E010 = 0x200;
    *(volatile u32 *)0x1000D410 = a0;
    *(volatile u32 *)0x1000D420 = a1;
    *(volatile u32 *)0x1000D480 = a2;
    *(volatile u32 *)0x1000E020 |= 0x200;
    *(volatile u32 *)0x1000D400 = 0x101;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/srp", iosSprToMemDmaAdrCopy);
void iosSprToMemDmaAdrCopy(u32 a0, u32 a1, u32 a2)
{
    *(volatile u32 *)0x1000E020 = -0x400;
    *(volatile u32 *)0x1000E010 = 0x100;
    *(volatile u32 *)0x1000D010 = a0;
    *(volatile u32 *)0x1000D020 = a1;
    *(volatile u32 *)0x1000D080 = a2;
    *(volatile u32 *)0x1000E020 |= 0x100;
    *(volatile u32 *)0x1000D000 = 0x100;
}

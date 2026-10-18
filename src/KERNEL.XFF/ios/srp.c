#include "common.h"

s32 iosWaitDMA(void);

/* NEARMISS-STUB iosSrpWaitDMA */
#if 0 /* NEARMISS 83.33% cat=no-c-form sub=- | sync instruction has no C form; plain tail call scores 83.3 without it | attempts=1 */
s32 iosSrpWaitDMA(void)
{
    return iosWaitDMA();
}
#endif
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

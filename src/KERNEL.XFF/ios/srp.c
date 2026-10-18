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

/* NEARMISS-STUB iosMemToSprDmaAdrCopy */
#if 0 /* NEARMISS 38.1% cat=alias sub=- | needs (banned): stripped form folds E020 -0x400 then |=0x200 into one store (-0x200) and drops the first store; target keeps both stores in order and r | attempts=1 */
void iosMemToSprDmaAdrCopy(u32 a0, u32 a1, u32 a2)
{
    *(u32 *)0x1000E020 = -0x400;
    *(u32 *)0x1000E010 = 0x200;
    *(u32 *)0x1000D410 = a0;
    *(u32 *)0x1000D420 = a1;
    *(u32 *)0x1000D480 = a2;
    *(u32 *)0x1000E020 |= 0x200;
    *(u32 *)0x1000D400 = 0x101;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/srp", iosMemToSprDmaAdrCopy);

/* NEARMISS-STUB iosSprToMemDmaAdrCopy */
#if 0 /* NEARMISS 35.88% cat=alias-hold sub=- | needs the banned qualifier: target keeps the E020 store (-0x400) then reloads E020 (lw, ori 0x100, sw) because the other stores are to other addresses; with pla | attempts=1 */
void iosSprToMemDmaAdrCopy(u32 a0, u32 a1, u32 a2)
{
    u32 *r020 = (u32 *)(0x1000E000 + (a1 & 0) + 0x20);
    u32 *r010 = (u32 *)(0x1000E000 + (a1 & 0) + 0x10);
    u32 *d000 = (u32 *)(0x1000D000 + (a1 & 0));

    r020[0] = -0x400;
    r010[0] = 0x100;
    d000[4] = a0;
    d000[8] = a1;
    d000[32] = a2;
    r020[0] |= 0x100;
    d000[0] = 0x100;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/srp", iosSprToMemDmaAdrCopy);

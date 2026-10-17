#include "common.h"

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", topThread);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", InitThread);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", iWakeupThread);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", iRotateThreadReadyQueue);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", iSuspendThread);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", DelayThread);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", StartThread);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", _DelayThreadHandler);

/* NEARMISS-STUB sioPutc */
#if 0 /* NEARMISS 55.5% cat=sdk-compiler sub=ee-gcc2.9-991111 | ref loop: lw, andi, 3 nops, bnez; sb sits in jr delay slot after daddu return move; 55.5% attempt loop/store order differs under ee-gcc2.9 (static diff only) | attempts=1 */
s32 sioPutc(s32 c)
{
    volatile s32 *stat = (volatile s32 *)0x1000F130;
    volatile u8 *data = (volatile u8 *)0x1000F180;

    while (*stat & 0x8000)
        ;
    *data = c;
    return c;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", sioPutc);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", func_00107DA8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", sioPutcNL);

/* NEARMISS-STUB func_00107E90 */
#if 0 /* NEARMISS 9.7% cat=bitops sub=ee-gcc2.9-991111 | 64-bit IEEE double bit-pattern decode (exponent field, mantissa shift, round-half on variable shift); 9.7% attempt guessed the rounding; body has no FPU ops; not sdk-compiler | attempts=1 */
s32 func_00107E90(u64 x)
{
    s32 e;
    u64 m;
    s64 r;

    e = (s32)((x << 1) >> 53) - 0x433;
    if (e < -0x35)
    {
        return 0;
    }
    if (e >= 0xD)
    {
        return 0x270F;
    }
    m = ((x << 12) >> 12) | (1ULL << 52);
    if (e < 0)
    {
        e = -e;
        r = m >> (e - 2);
        if ((r & 3) == 3)
        {
            return (s32)((r >> 2) + 1);
        }
        return (s32)(r >> 2);
    }
    return (s32)(m << e);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", func_00107E90);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", func_00107F20);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", func_001080F8);

/* NEARMISS-STUB func_00108E10 */
#if 0 /* NEARMISS 27.0% cat=sdk-compiler sub=ee-gcc2.9-991111 | 27% best (kK23) has the right shape; movz select for if(*a1==1) a2=0 and beql early-out do not match ee-gcc2.9 codegen; db cause "exact or 1 insn off" contradicts 27%, recheck under SDK compiler | attempts=1 */
s32 func_00108E10(u8 **a0, s32 *a1, s32 a2)
{
    u8 *p;

    if (*a1 == 0)
    {
        return 1;
    }
    if (a2 >= 0x100)
    {
        **a0 = 0;
        return 0;
    }
    p = *a0;
    if (*a1 == 1)
    {
        a2 = 0;
    }
    *p = a2;
    *a0 = p + 1;
    *a1 -= 1;
    return 1;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", func_00108E10);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", func_00108E68);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", sioPutcSkipNull);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", func_00108EB8);

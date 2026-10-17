#include "common.h"

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", SetT2);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", SetT2_COUNT);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", SetT2_MODE);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", SetT2_COMP);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", InitTimer);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", EndTimer);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", GetTimerPreScaleFactor);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", StartTimerSystemTime);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", StopTimerSystemTime);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", func_00110880);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", func_00110A10);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", func_00110A98);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", func_00110AD0);

#if 0 /* NEARMISS 20.7% cat=bitops sub=ee-gcc2.9-991111 | 64-bit variable shift expression form (t2<<=16, v0<<=t1 as dsllv) codegen differs under ee-gcc2.9-991111; prior tag sdk-compiler | attempts=1 */
u64 iGetTimerSystemTime(void)
{
    u64 v0;
    s32 t0;
    s32 t1;
    u64 t2;

    v0 = *(volatile u32 *)0x10001000;
    t0 = *(volatile u32 *)0x10001010;
    t2 = *(u64 *)0x00133A18;
    t1 = 2;
    if (t0 & 0x800)
    {
        v0 = *(volatile u32 *)0x10001000;
        t2++;
    }
    t0 &= 3;
    t2 <<= 16;
    if (t0 == 0)
    {
        t1 = 0;
    }
    v0 |= t2;
    t1 <<= t0;
    v0 <<= t1;
    return v0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iGetTimerSystemTime);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", GetTimerSystemTime);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iAllocTimerCounter);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", AllocTimerCounter);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iFreeTimerCounter);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", FreeTimerCounter);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iGetTimerUsedUnusedCounters);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", GetTimerUsedUnusedCounters);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iStartTimerCounter);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", StartTimerCounter);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iStopTimerCounter);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", StopTimerCounter);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", SetTimerCount);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iGetTimerBaseTime);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", GetTimerBaseTime);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iGetTimerCount);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", GetTimerCount);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iSetTimerHandler);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", SetTimerHandler);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", TimerBusClock2USec);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", TimerUSec2BusClock);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", TimerBusClock2Freq);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", TimerFreq2BusClock);

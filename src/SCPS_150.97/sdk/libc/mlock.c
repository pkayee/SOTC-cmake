#include "common.h"

extern s32 D_00132AA0[];
extern s32 D_001361C0[];
extern s32 D_001361C4[];

s32 GetThreadId(void);
s32 WaitSema(s32 sema);
s32 SignalSema(s32 sema);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mlock", __malloc_lock);
void __malloc_lock(void)
{
    s32 tid = GetThreadId();

    if (D_001361C0[0] == tid)
    {
        D_001361C4[0]++;
    }
    else
    {
        WaitSema(D_00132AA0[0]);
        D_001361C0[0] = tid;
        D_001361C4[0]++;
    }
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/mlock", __malloc_unlock);

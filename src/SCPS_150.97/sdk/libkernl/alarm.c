#include "common.h"

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarm", func_00110350);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarm", func_00110360);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarm", func_00110370);
int func_00110370(u32 *dst, u32 *src, u32 size)
{
    u32 i;
    u32 n;

    n = size >> 2;
    i = 0;
    while (i < n)
    {
        *dst = *src;
        i++;
        src++;
        dst++;
    }
    return 0;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarm", func_001103A8);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarm", InitAlarm);
extern u32 D_001339D8[];
extern u32 D_00133270[];
extern u32 D_001339B0[];
void FlushCache(int);
void func_00110350(u32 dst, u32 src);
void func_00110360(u32 dst, u32 *src, u32 size);
u32 func_001103A8(u32 arg);
void InitAlarm(void)
{
    u32 i;

    if ((*(volatile u32 *)0x10001810 & 0x100) == 0)
    {
        func_00110350(D_001339D8[0], D_001339D8[1]);
        func_00110360(0x80076000, D_00133270, 0x740);
        func_00110360(0x82000, D_001339B0, 0x28);
        FlushCache(0);
        FlushCache(2);
        func_00110350(D_001339D8[2], D_001339D8[3]);
        for (i = 2; i < 8; i++)
        {
            func_00110350(D_001339D8[i * 2], func_001103A8(D_001339D8[i * 2]));
        }
    }
}


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

/* NEARMISS-STUB InitAlarm */
#if 0 /* NEARMISS 96.9% cat=volatile-alias sub=- | needs the banned qualifier: target keeps lui/ori address in v0 and loads 0(v0) into v1; plain pointer forms fold to lw 0x1810(v0) | attempts=2 */
extern u32 D_001339D8[];
extern u32 D_00133270[];
extern u32 D_001339B0[];
void FlushCache(int);
void func_00110350(u32 dst, u32 src);
void func_00110360(u32 dst, u32 *src, u32 size);
u32 func_001103A8(u32 arg);

void InitAlarm(void)
{
    u32 *base;
    u32 *p;
    int i;
    u32 v;

    if ((*(u32 *)0x10001810 & 0x100) == 0)
    {
        base = D_001339D8;
        func_00110350(base[0], base[1]);
        func_00110360(0x80076000, D_00133270, 0x740);
        func_00110360(0x82000, D_001339B0, 0x28);
        FlushCache(0);
        FlushCache(2);
        func_00110350(base[2], base[3]);
        p = base + 4;
        i = 2;
        do
        {
            i++;
            v = func_001103A8(p[0]);
            func_00110350(p[0], v);
            p += 2;
        } while (i < 8);
    }
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarm", InitAlarm);


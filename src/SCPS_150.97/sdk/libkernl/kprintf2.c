#include "common.h"
#include <stdarg.h>

extern int func_001080F8();
extern void func_00108E10();
extern void func_00108E68();
extern void sioPutcSkipNull();
extern int DIntr(void);
extern int EIntr(void);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/kprintf2", sceVsnprintf);
int sceVsnprintf(char *buffer, u32 count, const char *fmt, va_list ap)
{
    u32 ctx[4];

    ctx[0] = (u32)buffer;
    return func_001080F8(func_00108E10, ctx, count, fmt, ap);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/kprintf2", sceSnprintf);
int sceSnprintf(char *buffer, u32 count, const char *fmt, ...)
{
    u32 ctx[4];
    char *ap;

    /* va_start stand-in: gcc 2.9 has no va_start; next_arg(fmt) is the frame top, back up over the 5 unnamed a3..a7 slots */
    ap = (char *)__builtin_next_arg(fmt) - 5 * 8;
    ctx[0] = (u32)buffer;
    return func_001080F8(func_00108E10, ctx, count, fmt, ap);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/kprintf2", sceVprintf);
void sceVprintf(const char *fmt, va_list ap)
{
    u32 ctx[4];
    int state;

    ctx[0] = 0;
    state = DIntr();
    func_001080F8(func_00108E68, ctx, 0xFFFFFFFFU, fmt, ap);
    if (state)
    {
        EIntr();
    }
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/kprintf2", scePrintf);
void scePrintf(const char *fmt, ...)
{
    u32 ctx[4];
    int state;

    ctx[0] = 0;
    state = DIntr();
    func_001080F8(func_00108E68, ctx, 0xFFFFFFFFU, fmt, (char *)__builtin_next_arg(fmt) - 7 * 8);
    if (state)
    {
        EIntr();
    }
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/kprintf2", kprintf);
void kprintf(const char *fmt, ...)
{
    u32 ctx[4];
    int state;

    ctx[0] = 0;
    state = DIntr();
    func_001080F8(sioPutcSkipNull, ctx, 0xFFFFFFFFU, fmt, (char *)__builtin_next_arg(fmt) - 7 * 8);
    if (state)
    {
        EIntr();
    }
}

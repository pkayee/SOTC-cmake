#include "common.h"
#include <stdio.h>
#include <stdarg.h>
#include <sys/reent.h>

extern struct _reent *D_00135D60[];

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/sprintf", _sprintf_r);
int _sprintf_r(struct _reent *ptr, char *str, const char *fmt, ...)
{
    FILE f;
    va_list ap;
    int ret;

    f._flags = 0x208;
    f._p = (unsigned char *)str;
    f._w = 0x7FFFFFFF;
    f._bf._base = (unsigned char *)str;
    f._bf._size = 0x7FFFFFFF;
    f._data = ptr;
    va_start(ap, fmt);
    ret = vfprintf(&f, fmt, ap);
    va_end(ap);
    *f._p = 0;
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/sprintf", sprintf);
int sprintf(char *str, const char *fmt, ...)
{
    FILE f;
    va_list ap;
    int ret;

    f._flags = 0x208;
    f._p = (unsigned char *)str;
    f._w = 0x7FFFFFFF;
    f._bf._base = (unsigned char *)str;
    f._bf._size = 0x7FFFFFFF;
    f._data = D_00135D60[0];
    va_start(ap, fmt);
    ret = vfprintf(&f, fmt, ap);
    va_end(ap);
    *f._p = 0;
    return ret;
}

// 2-insn `return 0;` stub at 0x00128C00 (8-aligned, last function in TU).
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/sprintf", func_00128C00);
int func_00128C00(void)
{
    return 0;
}

#include "common.h"
#include <stdio.h>
#include <stdarg.h>
#include <sys/reent.h>

extern struct _reent *D_00135D60[];

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/printf", _printf_r);
int _printf_r(struct _reent *ptr, const char *fmt, ...)
{
    va_list ap;
    int ret;

    va_start(ap, fmt);
    ret = _vfprintf_r(ptr, ptr->_stdout, fmt, ap);
    va_end(ap);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/printf", printf);
int printf(const char *fmt, ...)
{
    va_list ap;
    struct _reent *ptr;

    ptr = D_00135D60[0];
    ptr->_stdout->_data = ptr;
    va_start(ap, fmt);
    return vfprintf(ptr->_stdout, fmt, ap);
}

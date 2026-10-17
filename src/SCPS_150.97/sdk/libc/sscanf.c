#include "common.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <sys/reent.h>

extern int func_00128C00(void *cookie, char *buf, int n);
extern int __svfscanf(FILE *fp, const char *fmt, va_list ap);
extern struct _reent *D_00135D60[];

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/sscanf", sscanf);
int sscanf(const char *str, const char *fmt, ...)
{
    FILE f;
    va_list ap;

    f._flags = __SRD;
    f._p = (unsigned char *)str;
    f._bf._base = (unsigned char *)str;
    f._bf._size = f._r = strlen(str);
    f._read = func_00128C00;
    f._data = D_00135D60[0];
    f._ub._base = NULL;
    va_start(ap, fmt);
    f._lb._base = NULL;
    return __svfscanf(&f, fmt, ap);
}

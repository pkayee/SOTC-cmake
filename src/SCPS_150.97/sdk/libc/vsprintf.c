#include "common.h"
#include <stdio.h>
#include <stdarg.h>
#include <sys/reent.h>

extern struct _reent *D_00135D60[];

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/vsprintf", vsprintf);
int vsprintf(char *buf, const char *fmt, va_list ap)
{
    FILE f;
    int ret;

    f._flags = 0x208;
    f._p = (unsigned char *)buf;
    f._w = 0x7FFFFFFF;
    f._bf._base = (unsigned char *)buf;
    f._bf._size = 0x7FFFFFFF;
    f._data = D_00135D60[0];
    ret = vfprintf(&f, fmt, ap);
    *f._p = 0;
    return ret;
}

// last function in TU has size 4 mod 8 (pad nop), so it stays asm (INFRA-PAD, kS1).
// C draft that scored 100% in isolation: saved to decomp/notes/batches/kS3_vsprintf_r.c.txt
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/vsprintf", vsprintf_r);

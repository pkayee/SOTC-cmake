#include "common.h"

extern char D_001385A8[];

s32 sceOpen(const char *name, s32 flags);
s32 sceRead(s32 fd, void *buf, s32 count);
s32 sceClose(s32 fd);
int atoi(const char *s);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgraph/graph021", sceGsSetHalfOffset);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgraph/graph021", func_00114208);
s32 func_00114208(void)
{
    char buf[256];
    s32 fd;
    u32 i;
    char *p;

    fd = sceOpen(D_001385A8, 1);
    if (fd < 0)
    {
        return -1;
    }
    i = 0;
    p = buf;
    while (i < 256)
    {
        sceRead(fd, p, 1);
        if (*p == 0)
        {
            break;
        }
        p++;
        i++;
    }
    sceClose(fd);
    return 0x1315670 < atoi(&buf[i - 9]);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgraph/graph021", func_001142A8);

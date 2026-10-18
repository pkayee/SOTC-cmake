#include "common.h"

extern char D_001385A8[];

s32 sceOpen(const char *name, s32 flags);
s32 sceRead(s32 fd, void *buf, s32 count);
s32 sceClose(s32 fd);
int atoi(const char *s);

/* NEARMISS-STUB sceGsSetHalfOffset */
#if 0 /* NEARMISS 36.617645% cat=branch-layout sub=- | movn if-conversion instead of beqz branch on halfoff; 64-bit op order: target sign-extends/shifts centerx first and computes ofx (bits16) before ofy (bits48); g | attempts=1 */
void sceGsSetHalfOffset(sceGsDrawEnv1 *draw, short centerx, short centery, short halfoff)
{
    u64 *p;
    s32 ofx;
    s32 ofy;
    u64 hx;
    u64 hy;
    s64 x;
    s64 y;

    p = (u64 *)draw;
    ofy = (p[6] >> 48) & 0x7FF;
    ofx = (p[6] >> 16) & 0x7FF;
    hy = (u64)(ofy + 1) >> 1;
    hx = (u64)(ofx + 1) >> 1;
    y = ((s64)centery - hy) << 4;
    x = ((s64)centerx - hx) << 4;
    if (halfoff)
    {
        y += 8;
    }
    p[4] = ((u64)y << 32) | (u64)x;
}
#endif
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

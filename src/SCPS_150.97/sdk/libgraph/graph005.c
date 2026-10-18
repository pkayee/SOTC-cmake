#include "common.h"

/* NEARMISS-STUB sceGszbufaddr */
#if 0 /* NEARMISS 97.3% cat=regalloc sub=- | gcc picks different temp regs for the width/height ternary (t in v0 vs v1, slt into v0 vs a0) and for the 1-constant (a0 vs v1); arithmetic and branch shape mat | attempts=2 */
short sceGszbufaddr(short psm, short width, short height)
{
    sceGsGParam *gp;
    s32 bw;
    s32 bh;
    s32 x;
    s32 m1;
    s32 t;

    gp = sceGsGetGParam();
    m1 = -1;
    t = width + 0x3F;
    bw = width + 0x7E;
    if (m1 < t)
    {
        bw = t;
    }
    bw >>= 6;
    if (psm & 2)
    {
        t = height + 0x3F;
        bh = height + 0x7E;
        if (m1 < t)
        {
            bh = t;
        }
        bh >>= 6;
    }
    else
    {
        t = height + 0x1F;
        bh = height + 0x3E;
        if (m1 < t)
        {
            bh = t;
        }
        bh >>= 5;
    }
    x = bw * bh;
    if ((*(u_long *)gp & 0x0000FFFF0000FFFFUL) == 1)
    {
        return x;
    }
    return x * 2;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgraph/graph005", sceGszbufaddr);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgraph/graph005", sceGsSetDefClear);

#include "common.h"

/* NEARMISS-STUB sceGsSetDefDispEnv */
#if 0 /* NEARMISS 45.79% cat=regalloc sub=dxdy-sreg-swap | s-reg swap dx/dy (target dx=s5 dy=s4); compiler emits one shared x/y block where target has separate NTSC/PAL bodies with own InterMode==1 split and bnel zero-s | attempts=1 */
void sceGsSetDefDispEnv(sceGsDispEnv *disp, short psm, short w, short h, short dx, short dy)
{
    sceGsGParam *gp;
    s32 ofs[4];
    s32 mag;
    s32 x;
    s32 y;
    s32 dw;
    s32 dh;
    s32 magh;

    gp = sceGsGetGParam();
    if ((u_short)(gp->sceGsOutMode - 2) < 2)
    {
        ofs[0] = ofs[1] = ofs[2] = ofs[3] = 0;
    }
    else if (func_00114208())
    {
        func_001142A8(gp->sceGsOutMode, &ofs[0], &ofs[1], &ofs[2], &ofs[3]);
    }
    else
    {
        ofs[0] = ofs[1] = ofs[2] = ofs[3] = 0;
    }
    *(u_long *)&disp->pmode = 0x66;
    *(u_long *)&disp->smode2 = (gp->sceGsInterMode == 0) ? 2 : (gp->sceGsFFMode ? 3 : 1);
    *(u_long *)&disp->dispfb = ((u_long)(psm & 0xF) << 15) | ((u_long)(((w + 0x3F) >> 6) & 0x3F) << 9);
    if (gp->sceGsOutMode == 2 || gp->sceGsOutMode == 3)
    {
        s32 xb = (gp->sceGsOutMode == 2) ? 0x27C : 0x290;
        s32 yb;
        mag = (w + 0x9FF) / w;
        if (gp->sceGsInterMode == 1)
        {
            yb = (gp->sceGsOutMode == 2) ? 0x32 : 0x48;
            dh = gp->sceGsFFMode ? (h * 2 - 1) : (h - 1);
        }
        else
        {
            yb = (gp->sceGsOutMode == 2) ? 0x19 : 0x24;
            dh = h - 1;
        }
        x = (ofs[0] + xb + mag * dx) & 0xFFF;
        y = (dy + ofs[1] + yb) & 0xFFF;
        dw = mag * w - 1;
        magh = mag - 1;
        *(u_long *)&disp->display = (u_long)x | ((u_long)y << 12) | ((u_long)magh << 23) | ((u_long)dw << 32) | ((u_long)dh << 44);
    }
    else if (gp->sceGsOutMode == 0x50)
    {
        x = ((((0x2D0 - w) / 2) * 2) + ofs[0] + dx * 2 + 0xE8) & 0xFFF;
        y = (dy + ofs[1] + 0x23) & 0xFFF;
        *(u_long *)&disp->display = (u_long)x | 0x800000 | ((u_long)y << 12) | ((u_long)(w * 2 - 1) << 32) | ((u_long)(h - 1) << 44);
    }
    else
    {
        scePrintf(D_001385B8);
    }
    *(u_long *)&disp->bgcolor = 0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgraph/graph003", sceGsSetDefDispEnv);

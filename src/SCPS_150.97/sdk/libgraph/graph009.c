#include "common.h"

/* NEARMISS-STUB sceGsSetDefDBuff */
#if 0 /* NEARMISS 97.35% cat=bitops sub=zbp-short-vs-int | zbp width: target keeps zbp int (sra 1 on full reg inside the GParam if, no sll16 after the call); best C uses short zbp so it narrows at the call and the shift | attempts=1 */
void sceGsSetDefDBuff(sceGsDBuff *db, short psm, short w, short h, short ztest, short zpsm, short clear)
{
    sceGsGParam *gp;
    short zbp;

    gp = sceGsGetGParam();
    sceGsSetDefDispEnv(&db->disp[0], psm, w, h, 0, 0);
    sceGsSetDefDispEnv(&db->disp[1], psm, w, h, 0, 0);
    sceGsSetDefDrawEnv(&db->draw0, psm, w, h, ztest, zpsm);
    sceGsSetDefDrawEnv(&db->draw1, psm, w, h, ztest, zpsm);
    if (clear)
    {
        sceGsSetDefClear(&db->clear0, ztest, 0x800 - (w >> 1), 0x800 - (h >> 1), w, h, 0, 0, 0, 0, 0);
        sceGsSetDefClear(&db->clear1, ztest, 0x800 - (w >> 1), 0x800 - (h >> 1), w, h, 0, 0, 0, 0, 0);
    }
    SCE_GIF_CLEAR_TAG(&db->giftag0);
    SCE_GIF_CLEAR_TAG(&db->giftag1);
    db->giftag0.NLOOP = clear ? 14 : 8;
    db->giftag0.EOP = 1;
    db->giftag0.NREG = 1;
    db->giftag0.REGS0 = 0xE;
    db->giftag1.NLOOP = clear ? 14 : 8;
    db->giftag1.EOP = 1;
    db->giftag1.NREG = 1;
    db->giftag1.REGS0 = 0xE;
    zbp = sceGszbufaddr(psm, w, h);
    if ((gp->sceGsInterMode == SCE_GS_INTERLACE && gp->sceGsFFMode == SCE_GS_FRAME) || gp->sceGsInterMode == SCE_GS_NOINTERLACE)
    {
        zbp >>= 1;
        db->disp[1].dispfb.FBP = zbp;
        db->draw0.frame1.FBP = zbp;
    }
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgraph/graph009", sceGsSetDefDBuff);

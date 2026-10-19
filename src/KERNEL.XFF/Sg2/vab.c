#include "common.h"

typedef struct {
    s32 unk0;   /* 0x10 semastervol */
    s32 unk4;   /* 0x14 header */
    void *unk8; /* 0x18 veltbl */
    s32 unkC;   /* 0x1C */
    void *unk10; /* 0x20 lfotbl */
    s32 unk14;  /* 0x24 */
    s32 unk18;  /* 0x28 */
} VabSub;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    VabSub sub; /* 0x10 */
} VabSlot;

extern VabSlot D_40115640[8];
extern VabSlot D_40115650[8];

void Sg2SmfpVabStopSndOff(s32);
void Sg2SepVabStopSndOff(s32);
s32 Sg2VabHdClose(s32);
s32 DIntr(void);
void EIntr(void);
s32 func_4003EBE0(VabSlot *arg0, void *arg1);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", get_vabid);
s32 get_vabid(void)
{
    s32 i;

    for (i = 0; i < 8; i++)
    {
        if (D_40115640[i].unk0 == 0)
        {
            return i;
        }
    }
    return -1;
}

typedef struct {
    s32 pad0[3];
    s32 magic;  /* 0xC */
    s32 off[6]; /* 0x10 */
    s32 pad28[2];
    s32 ptr[6]; /* 0x30 */
    s32 pad48[13];
    s32 flag7C;
} VabHd;

s32 func_4003EBE0(VabSlot *slot, void *arg1)
{
    VabHd *hd = arg1;
    s32 t;
    u16 *c;

    if (hd->magic != 0x64685353)
    {
        return -1;
    }
    if (slot->unk0 == 0)
    {
        if (hd->flag7C == -1)
        {
            slot->unk0 = 3;
        }
        else
        {
            slot->unk0 = 4;
        }
        slot->unk4 = (s32)hd;
        if (hd->off[0] != -1)
        {
            hd->ptr[0] = hd->off[0] + (s32)hd;
        }
        else
        {
            hd->ptr[0] = 0;
        }
        if (hd->off[1] != -1)
        {
            hd->ptr[1] = hd->off[1] + (s32)hd;
        }
        else
        {
            hd->ptr[1] = 0;
        }
        if (hd->off[2] != -1)
        {
            hd->ptr[2] = hd->off[2] + (s32)hd;
        }
        else
        {
            hd->ptr[2] = 0;
        }
        if (hd->off[3] != -1)
        {
            hd->ptr[3] = hd->off[3] + (s32)hd;
        }
        else
        {
            hd->ptr[3] = 0;
        }
        if (hd->off[4] != -1)
        {
            hd->ptr[4] = hd->off[4] + (s32)hd;
        }
        else
        {
            hd->ptr[4] = 0;
        }
        if (hd->off[5] != -1)
        {
            hd->ptr[5] = hd->off[5] + (s32)hd;
        }
        else
        {
            hd->ptr[5] = 0;
        }
        c = (u16 *)hd->ptr[1];
        slot->sub.unk4 = (s32)hd;
        if (c != 0)
        {
            *(s32 *)&slot->sub.unk8 = *c;
            slot->sub.unkC = hd->ptr[1] + 2;
        }
        else
        {
            slot->sub.unkC = 0;
            *(s32 *)&slot->sub.unk8 = -1;
        }
        c = (u16 *)hd->ptr[2];
        if (c != 0)
        {
            *(s32 *)&slot->sub.unk10 = *c;
            t = hd->ptr[2];
            slot->sub.unk14 = t;
            slot->sub.unk18 = t + 2;
        }
        else
        {
            slot->sub.unk18 = 0;
            *(s32 *)&slot->sub.unk10 = -1;
        }
        slot->sub.unk0 = 0x7F;
        return 0;
    }
    return -1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", func_4003ED58);
s32 func_4003ED58(VabSlot *arg0, s32 arg1)
{
    u8 *base = *(u8 **)(arg0->sub.unk4 + 0x30);
    u16 *p = (u16 *)(arg1 * 2 + (s32)base);

    return (s32)base + p[1];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", vab_check_alive);
s32 vab_check_alive(s32 vab)
{
    s32 ret = 0;

    if (vab < 0)
    {
        return ret;
    }
    if (vab >= 8)
    {
        return ret;
    }
    return D_40115640[vab].unk0 != 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", vab_get_info);
s32 vab_get_info(s32 arg0, s32 *arg1, s32 *arg2)
{
    *arg1 = D_40115640[arg0].unkC;
    *arg2 = D_40115640[arg0].unk0;
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", vab_get_seseq);
s32 vab_get_seseq(s32 arg0, u32 arg1, u32 arg2)
{
    VabSlot *slot = &D_40115640[arg0];
    u8 *hd;
    u16 *c;
    u32 v;

    if (!vab_check_alive(arg0))
    {
        return 0;
    }
    hd = (u8 *)slot->sub.unk4;
    if (!hd)
    {
        return 0;
    }
    c = *(u16 **)(hd + 0x3C);
    if (!c)
    {
        return 0;
    }
    if (c[0] < arg1)
    {
        return 0;
    }
    v = c[1 + arg1] >> 1;
    if (c[v] < arg2)
    {
        return 0;
    }
    return (s32)c + c[v + arg2 + 1];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", vab_get_seprogchunk);
s32 vab_get_seprogchunk(s32 arg0, u32 arg1)
{
    VabSlot *slot = &D_40115640[arg0];
    u8 *hd;
    u16 *c;

    if (!vab_check_alive(arg0))
    {
        return 0;
    }
    hd = (u8 *)slot->sub.unk4;
    if (!hd)
    {
        return 0;
    }
    c = *(u16 **)(hd + 0x44);
    if (!c)
    {
        return 0;
    }
    if ((s32)c & 1)
    {
        return 0;
    }
    if (c[0] < arg1)
    {
        return 0;
    }
    return (s32)c + c[1 + arg1];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", vab_get_progchunk);
s32 vab_get_progchunk(s32 arg0, u32 arg1)
{
    VabSlot *slot = &D_40115640[arg0];
    u8 *hd;
    u16 *c;

    if (!vab_check_alive(arg0))
    {
        return 0;
    }
    hd = (u8 *)slot->sub.unk4;
    if (!hd)
    {
        return 0;
    }
    c = *(u16 **)(hd + 0x30);
    if (!c)
    {
        return 0;
    }
    if ((s32)c & 1)
    {
        return 0;
    }
    if (c[0] < arg1)
    {
        return 0;
    }
    if (c[1 + arg1] == 0xFFFF)
    {
        return 0;
    }
    return (s32)c + c[1 + arg1];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", vab_get_splitchunk);
s32 vab_get_splitchunk(s32 arg0)
{
    if (arg0 == 0)
    {
        return 0;
    }
    return arg0 + 8;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", vab_get_veltbl);
s32 vab_get_veltbl(s32 arg0, void **arg1)
{
    *arg1 = D_40115640[arg0].sub.unk8;
    return D_40115640[arg0].sub.unkC;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", vab_get_lfotbl_param);
s32 vab_get_lfotbl_param(s32 arg0, void **arg1, s32 *arg2)
{
    *arg2 = D_40115640[arg0].sub.unk14;
    *arg1 = D_40115640[arg0].sub.unk10;
    return D_40115640[arg0].sub.unk18;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", vab_set_semastervol);
s32 vab_set_semastervol(s32 arg0, s32 arg1)
{
    s32 old = D_40115650[arg0].unk0;

    D_40115650[arg0].unk0 = arg1;
    return old;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", vab_get_semastervol);
s32 vab_get_semastervol(s32 arg0)
{
    return D_40115650[arg0].unk0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", Sg2VabHdOpen);
s32 Sg2VabHdOpen(void *arg0)
{
    s32 intr;
    s32 id;
    s32 ret;

    intr = DIntr();
    id = get_vabid();
    ret = (func_4003EBE0(&D_40115640[id], arg0) == -1) ? -1 : id;
    if (intr)
    {
        EIntr();
    }
    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", Sg2VabGetBdSize);
s32 Sg2VabGetBdSize(s32 arg0)
{
    VabSlot *slot = &D_40115640[arg0];
    s32 ret;

    if (!vab_check_alive(arg0))
    {
        return -1;
    }
    ret = slot->unk0;
    if (ret != 0)
    {
        ret = ((s32 *)D_40115640[arg0].sub.unk4)[1];
    }
    else
    {
        ret = -1;
    }
    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", Sg2VabBdOpen);
s32 Sg2VabBdOpen(s32 arg0, s32 arg1)
{
    VabSlot *slot = &D_40115640[arg0];

    if (!vab_check_alive(arg0))
    {
        return -1;
    }
    slot->unkC = arg1;
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", Sg2VabClose);
s32 Sg2VabClose(s32 arg0)
{
    if (!vab_check_alive(arg0))
    {
        return -1;
    }
    Sg2SmfpVabStopSndOff(arg0);
    Sg2SepVabStopSndOff(arg0);
    return Sg2VabHdClose(arg0);
}

/* NEARMISS-STUB Sg2VabHdClose */
#if 0 /* NEARMISS 97.67% cat=regalloc sub=- | hoisted &D_40115640[vab] field addresses get different temp regs (a3/a4/a5 order); individual stores match; chaining perturbs lui/addiu temps | attempts=4 */
/* Sg2VabHdClose best C: 97.67% (individual stores, manager order; NOT left in file). Tried chain groupings: (1) top chain then sub chain = 94.96%; (2) sub chain then top chain = 95.35%; (3) contiguous same-group chains in target order = 95.17%. Chaining perturbs the hoisted lui/addiu temps (arg_mism on a0..a7). Remaining diff: register allocation of hoisted &D[vab] addresses. */
s32 Sg2VabHdClose(s32 vab)
{
    if (!vab_check_alive(vab))
    {
        return -1;
    }
    D_40115640[vab].unk4 = 0;
    D_40115640[vab].unk8 = 0;
    D_40115640[vab].sub.unk0 = 0;
    D_40115640[vab].unkC = 0;
    D_40115640[vab].sub.unkC = 0;
    D_40115640[vab].unk0 = 0;
    D_40115640[vab].sub.unk14 = 0;
    D_40115640[vab].sub.unk18 = 0;
    D_40115640[vab].sub.unk10 = 0;
    D_40115640[vab].sub.unk8 = 0;
    D_40115640[vab].sub.unk4 = 0;
    return 0;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", Sg2VabHdClose);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", Sg2VabInit);
s32 Sg2VabInit(void)
{
    s32 i = 0;

    do
    {
        Sg2VabHdClose(i);
    } while (++i < 8);
    return 0;
}

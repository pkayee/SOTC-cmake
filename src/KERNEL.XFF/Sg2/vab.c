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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", func_4003EBE0);

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

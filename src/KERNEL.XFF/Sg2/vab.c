#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
} VabSlot;

extern VabSlot D_40115640[8];
extern VabSlot D_40115650[8];

void Sg2SmfpVabStopSndOff(s32);
void Sg2SepVabStopSndOff(s32);
s32 Sg2VabHdClose(s32);

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
    u8 *base = *(u8 **)(arg0->unk14 + 0x30);
    u16 *p = (u16 *)(arg1 * 2 + (s32)base);

    return (s32)base + p[1];
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", vab_check_alive);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", vab_get_info);
s32 vab_get_info(s32 arg0, s32 *arg1, s32 *arg2)
{
    *arg1 = D_40115640[arg0].unkC;
    *arg2 = D_40115640[arg0].unk0;
    return 0;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", vab_get_seseq);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", vab_get_seprogchunk);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", vab_get_progchunk);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", vab_get_splitchunk);
s32 vab_get_splitchunk(s32 arg0)
{
    if (arg0 == 0)
    {
        return 0;
    }
    return arg0 + 8;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", vab_get_veltbl);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", vab_get_lfotbl_param);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", Sg2VabHdOpen);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/vab", Sg2VabGetBdSize);

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

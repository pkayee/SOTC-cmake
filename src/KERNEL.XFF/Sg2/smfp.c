#include "common.h"

typedef struct {
    /* 0x00 */ s32 status;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[0x50];
    /* 0x60 */ u8 *unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 unk68;
    /* 0x69 */ u8 pad69[0x17];
} Sg2SmfpSlot;

extern Sg2SmfpSlot D_40114200[];
extern s32 D_40114208[][0x20];
extern s32 D_40114604;
extern s32 D_40114608;
extern s32 D_40114E14;
extern s32 D_40114E10;
extern u8 D_40114610[];

s32 Sg2SmfpOpenSelCore(s32 arg0, s32 arg1, s32 arg2);
s32 Sg2SmfpStopSndOff(s32 arg0);
s32 Sg2SmfpPause(s32 arg0, s32 arg1);
s32 Sg2SmfpCont(s32 arg0);
s32 Sg2ModCheckSndOn(s32 arg0);
s32 Sg2ModSetParam(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 Sg2ModClose(s32 arg0);
s32 vab_check_alive(s32 arg0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", func_4003CE68);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", func_4003CF28);
s32 func_4003CF28(Sg2SmfpSlot *arg0)
{
    arg0->unk60 += 8;
    return 0;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpOpen);
s32 Sg2SmfpOpen(s32 arg0, s32 arg1)
{
    return Sg2SmfpOpenSelCore(arg0, arg1, 2);
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpOpenSelCore);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpClose);
s32 Sg2SmfpClose(s32 arg0)
{
    Sg2SmfpSlot *slot;

    if (arg0 >= 0)
    {
        slot = &D_40114200[arg0];
        if (slot->status != 0)
        {
            Sg2SmfpStopSndOff(arg0);
        }
        Sg2ModClose(slot->unk8);
        slot->status = 0;
    }
    return 0;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpVabStopSndOff);
s32 Sg2SmfpVabStopSndOff(s32 arg0)
{
    s32 i;
    Sg2SmfpSlot *slot;

    if (vab_check_alive(arg0))
    {
        slot = D_40114200;
        for (i = 0; i < 8; i++, slot++)
        {
            if (slot->unkC == arg0)
            {
                Sg2SmfpClose(i);
            }
        }
    }
    return 0;
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpPlay);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpStop);
s32 Sg2SmfpStop(s32 arg0)
{
    Sg2SmfpSlot *slot;

    if (arg0 >= 0)
    {
        slot = &D_40114200[arg0];
        if (slot->status == 2)
        {
            Sg2SmfpPause(arg0, 0);
            Sg2SmfpCont(arg0);
            slot->status = 1;
        }
    }
    return 0;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpStopSndOff);
s32 Sg2SmfpStopSndOff(s32 arg0)
{
    Sg2SmfpSlot *slot;

    if (arg0 >= 0)
    {
        slot = &D_40114200[arg0];
        if (slot->status == 2)
        {
            Sg2SmfpPause(arg0, 1);
            Sg2SmfpCont(arg0);
            slot->status = 1;
        }
    }
    return 0;
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpPause);


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpCont);
s32 Sg2SmfpCont(s32 arg0)
{
    Sg2SmfpSlot *slot;

    if (arg0 >= 0)
    {
        D_40114200[arg0].status = 2;
    }
    slot = &D_40114200[arg0];
    Sg2ModSetParam(slot->unk8, 0x40, 0, 0);
    return 0;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpStatus);
s32 Sg2SmfpStatus(s32 arg0)
{
    if (arg0 >= 0)
    {
        return D_40114200[arg0].status;
    }
    return 1;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpCheckSndOn);
s32 Sg2SmfpCheckSndOn(s32 arg0)
{
    if (arg0 >= 0)
    {
        return Sg2ModCheckSndOn(D_40114208[arg0][0]);
    }
    return 0;
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpSetParam);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpGetParam);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpMidiOut);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpSetSignal);
void Sg2SmfpSetSignal(s32 arg0)
{
    D_40114608 = arg0;
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpTickProc);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpInit);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", debug_smfp_mod_config);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", debug_set_smfp_time_count_delta_per);

void func_4003E2A0(void) {
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", func_4003E2A8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", func_4003E338);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", func_4003E4C8);
void func_4003E4C8(Sg2SmfpSlot *arg0)
{
    u8 a = *arg0->unk60++;
    u8 b = arg0->unk68;

    if (D_40114E14 != b)
    {
        D_40114E14 = b;
        D_40114610[D_40114E10++] = b;
    }
    D_40114610[D_40114E10++] = a;
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", func_4003E548);

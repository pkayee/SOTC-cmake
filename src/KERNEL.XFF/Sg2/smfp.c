#include "common.h"

typedef struct {
    /* 0x00 */ s32 status;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s64 unk30;
    /* 0x38 */ s64 unk38;
    /* 0x40 */ s64 unk40;
    /* 0x48 */ s64 unk48;
    /* 0x50 */ s64 unk50;
    /* 0x58 */ s64 unk58;
    /* 0x60 */ u8 *unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 unk68;
    /* 0x69 */ u8 unk69;
    /* 0x6A */ u8 pad6A[0x2];
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ u8 pad74[0x4];
    /* 0x78 */ s64 unk78;
} Sg2SmfpSlot;

extern Sg2SmfpSlot D_40114200[];
extern s32 D_40114208[][0x20];
extern s32 D_40114604;
extern s32 D_40114608;
extern u8 D_40114600;
extern s32 D_40114E14;
extern s32 D_40114E10;
extern u8 D_40114610[];
extern u8 D_40114E20[];
extern s32 D_40115620;
extern s64 D_40049388;
extern s64 D_40049390;
extern s32 D_40114210[][0x20];
extern s32 D_40114218[][0x20];
extern s32 D_4011421C[][0x20];
extern s64 D_40114230[][0x10];

s64 litodp(s32);
s64 dpdiv(s64, s64);
s64 dpmul(s64, s64);
s64 dpadd(s64, s64);
s32 dptoli(s64);
s32 Sg2CtrlGetTickMode(void);
s64 __floatdidf(s64);
s32 Sg2SmfpSetParam(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

s32 Sg2SmfpOpenSelCore(s32 arg0, s32 arg1, s32 arg2);
s32 func_4003CE68(Sg2SmfpSlot *arg0);
s32 Sg2ModOpenBgm(s32 arg0, s32 arg1);
s32 Sg2SmfpStopSndOff(s32 arg0);
s32 Sg2SmfpPause(s32 arg0, s32 arg1);
s32 Sg2SmfpCont(s32 arg0);
s32 Sg2ModCheckSndOn(s32 arg0);
s32 Sg2ModSetParam(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 Sg2ModClose(s32 arg0);
s32 vab_check_alive(s32 arg0);
void *memset(void *s, s32 c, u32 n);
s32 Sg2CtrlEntryTickProcById(s32 id, void (*proc)(void));
void Sg2SmfpTickProc(void);

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


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpPause);
s32 Sg2SmfpPause(s32 arg0, s32 arg1)
{
 if (arg0 >= 0) {
 if (arg1 != 0) {
 Sg2ModSetParam(D_40114200[arg0].unk8, 0x20, 1, 0);
 D_40114200[arg0].status = 3;
 } else {
 Sg2ModSetParam(D_40114200[arg0].unk8, 0x40, 1, 0);
 D_40114200[arg0].status = 4;
 }
 }
 return 0;
}


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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpGetParam);
s32 Sg2SmfpGetParam(s32 arg0, s32 arg1)
{
    s32 ret;

    if (arg0 >= 0)
    {
    switch (arg1)
    {
    case 2:
        ret = D_40114210[arg0][0];
        break;
    case 4:
        ret = D_40114218[arg0][0];
        break;
    case 8:
        ret = D_4011421C[arg0][0];
        break;
    case 512:
        ret = dptoli(D_40114230[arg0][0]);
        break;
    }
    }
    else ret = 0;
    return ret;
}



//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpMidiOut);
s32 Sg2SmfpMidiOut(s32 id, s32 len, u8 *data)
{
    s32 n;
    Sg2SmfpSlot *slot;

    if (id >= 0)
    {
        slot = &D_40114200[id];
        if (slot->status == 0)
        {
            return -1;
        }
        D_40114E20[D_40115620++] = *(u8 *)&slot->unk8;
        D_40114E20[D_40115620++] = len;
        n = len;
        while (n != 0)
        {
            D_40114E20[D_40115620++] = *data++;
            n--;
        }
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpSetSignal);
void Sg2SmfpSetSignal(s32 arg0)
{
    D_40114608 = arg0;
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpTickProc);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", Sg2SmfpInit);
s32 Sg2SmfpInit(void)
{
    s32 i;
    Sg2SmfpSlot *slot;

    slot = D_40114200;
    for (i = 7; i >= 0; i--, slot++)
    {
        memset(slot, -1, 0x80);
        slot->status = 0;
    }
    D_40114604 = 1;
    D_40115620 = 0;
    D_40114608 = 0;
    Sg2CtrlEntryTickProcById(0, Sg2SmfpTickProc);
    return 0;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", debug_smfp_mod_config);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", debug_set_smfp_time_count_delta_per);

void func_4003E2A0(void) {
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/smfp", func_4003E2A8);
void func_4003E2A8(Sg2SmfpSlot *arg0)
{
    u8 d0 = *arg0->unk60++;
    u8 d1 = *arg0->unk60++;

    if (D_40114E14 != arg0->unk68)
    {
        D_40114E14 = arg0->unk68;
        D_40114610[D_40114E10++] = arg0->unk68;
    }
    D_40114610[D_40114E10++] = d0;
    D_40114610[D_40114E10++] = d1;
}

void func_4003E338(Sg2SmfpSlot *arg0)
{
    s32 emit = 0;
    u8 d0 = *arg0->unk60++;
    u8 d1 = *arg0->unk60++;

    switch (d0)
    {
    case 0x63:
        switch (d1)
        {
        case 0x14:
            arg0->unk69 = arg0->unk68;
            arg0->unk6C = (s32)arg0->unk60;
            break;
        case 0x1E:
            if (arg0->unk70 != 0x7F)
            {
                arg0->unk70--;
            }
            if (arg0->unk70 > 0)
            {
                arg0->unk68 = arg0->unk69;
                arg0->unk60 = (u8 *)arg0->unk6C;
            }
            break;
        default:
            emit = 1;
            break;
        }
        break;
    case 0x66:
        arg0->unk70 = d1;
        break;
    case 0x5A:
        if (D_40114608 != 0)
        {
            ((void (*)(u8, s32, u8))D_40114608)(D_40114600, arg0->unk68 & 0xF, d1);
        }
        break;
    default:
        emit = 1;
        break;
    }

    if (emit)
    {
        if (D_40114E14 != arg0->unk68)
        {
            D_40114E14 = arg0->unk68;
            D_40114610[D_40114E10++] = arg0->unk68;
        }
        D_40114610[D_40114E10++] = d0;
        D_40114610[D_40114E10++] = d1;
    }
}

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

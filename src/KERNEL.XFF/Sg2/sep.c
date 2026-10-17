#include "common.h"

typedef struct
{
    s32 mod;         /* 0x10 */
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10[8];
    u8 *data;        /* 0x40 */
    s32 unk34;
    u8 runStatus;    /* 0x48 */
    u8 pad39[3];
    s32 unk3C;
} Sg2SepSub;

typedef struct
{
    s32 status;      /* 0x00 */
    s32 savedStatus; /* 0x04 */
    s32 unk8;
    s32 vab;         /* 0x0C */
    Sg2SepSub sub;   /* 0x10 */
} Sg2SepSlot;

extern Sg2SepSlot D_40110B40[32];
extern s32 D_40110B50[][20];
extern s32 D_40111540;
extern s32 D_40111654;
extern s32 D_40111650;
extern u8 D_40111550[];
extern u8 D_40111660[];
extern s32 D_40111760;

s32 DIntr(void);
s32 EIntr(void);
void Sg2ModMidiout1(s32 mod, s32 data);
s32 Sg2ModSetParam(s32 mod, s32 param, s32 val, s32 arg3);
s32 Sg2ModCheckSndOn(s32 mod);
s32 vab_check_alive(s32 vab);
s32 vab_set_semastervol(s32 vab, s32 vol);
void *memset(void *s, s32 c, u32 n);
s32 Sg2CtrlEntryTickProcById(s32 id, void (*proc)(void));
void Sg2SepTickProc(void);
s32 Sg2SepPlaySelectCore(s32 vab, s32 prog, s32 flags, s32 arg3, s32 arg4);
s32 Sg2SepStopSndOff(u32 id);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", func_40037188);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", Sg2SepPlay);
s32 Sg2SepPlay(s32 vab, s32 prog, s32 flags, s32 arg3)
{
    return Sg2SepPlaySelectCore(vab, prog, flags, arg3, 2);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", Sg2SepPlaySelectCore);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", Sg2SepStop);
s32 Sg2SepStop(u32 id)
{
    s32 intr;
    Sg2SepSlot *slot;

    if (id < 32)
    {
        slot = &D_40110B40[id];
        if (slot->status > 0)
        {
            intr = DIntr();
            slot->status = 2;
            slot->vab = -1;
            Sg2ModMidiout1(D_40110B40[id].sub.mod, 255);
            Sg2ModMidiout1(D_40110B40[id].sub.mod, 64);
            Sg2ModMidiout1(D_40110B40[id].sub.mod, 247);
        }
        if (intr != 0)
        {
            EIntr();
        }
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", Sg2SepStopSndOff);
s32 Sg2SepStopSndOff(u32 id)
{
    s32 intr;
    Sg2SepSlot *slot;

    if (id < 32)
    {
        slot = &D_40110B40[id];
        if (slot->status > 0)
        {
            intr = DIntr();
            slot->status = 2;
            slot->vab = -1;
            Sg2ModMidiout1(D_40110B40[id].sub.mod, 255);
            Sg2ModMidiout1(D_40110B40[id].sub.mod, 65);
            Sg2ModMidiout1(D_40110B40[id].sub.mod, 247);
            if (intr != 0)
            {
                EIntr();
            }
        }
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", Sg2SepPause);
s32 Sg2SepPause(u32 id, s32 flag)
{
    s32 intr;
    Sg2SepSlot *slot;

    if (id < 32)
    {
        slot = &D_40110B40[id];
        if ((u32)(slot->status - 1) < 2)
        {
            intr = DIntr();
            slot->savedStatus = slot->status;
            Sg2ModSetParam(D_40110B40[id].sub.mod, 128, 1, 0);
            Sg2ModSetParam(D_40110B40[id].sub.mod, 16, flag, 0);
            if (flag != 0)
            {
                slot->status = 3;
            }
            else
            {
                slot->status = 4;
            }
            if (intr != 0)
            {
                EIntr();
            }
        }
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", Sg2SepCont);
s32 Sg2SepCont(u32 id)
{
    s32 intr;
    Sg2SepSlot *slot;

    if (id < 32)
    {
        slot = &D_40110B40[id];
        if ((u32)(slot->status - 3) < 2)
        {
            intr = DIntr();
            Sg2ModSetParam(D_40110B40[id].sub.mod, 128, 0, 0);
            Sg2ModSetParam(D_40110B40[id].sub.mod, 16, 0, 0);
            slot->status = slot->savedStatus;
            if (intr != 0)
            {
                EIntr();
            }
        }
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", Sg2SepVabStopSndOff);
s32 Sg2SepVabStopSndOff(s32 vab)
{
    s32 i;
    Sg2SepSlot *p;

    if (vab_check_alive(vab))
    {
        p = D_40110B40;
        for (i = 0; i < 32; i++, p++)
        {
            if (p->vab == vab)
            {
                Sg2SepStopSndOff(i);
            }
        }
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", Sg2SepAllStopSndOff);
s32 Sg2SepAllStopSndOff(void)
{
    s32 i;

    for (i = 0; i < 32; i++)
    {
        Sg2SepStopSndOff(i);
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", Sg2SepStatus);
s32 Sg2SepStatus(u32 id)
{
    if (id < 32)
    {
        return D_40110B40[id].status;
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", Sg2SepCheckSndOn);
s32 Sg2SepCheckSndOn(u32 id)
{
    if (id < 32)
    {
        Sg2ModCheckSndOn(D_40110B50[id][0]);
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", Sg2SepSetParam);
s32 Sg2SepSetParam(u32 id, s32 p, s32 a2, s32 a3)
{
    if (id < 32)
    {
        switch (p)
        {
        case 2:
            Sg2ModSetParam(D_40110B50[id][0], 1, a2, a3);
            break;
        case 1024:
            Sg2ModSetParam(D_40110B50[id][0], 65536, a2, a3);
            break;
        case 4:
            Sg2ModSetParam(D_40110B50[id][0], 4, a2, a3);
            break;
        case 8:
            Sg2ModSetParam(D_40110B50[id][0], 16, 1, 0);
            break;
        case 16:
            Sg2ModSetParam(D_40110B50[id][0], 16, 0, 0);
            break;
        case 32:
            Sg2ModSetParam(D_40110B50[id][0], 256, a2, a3);
            break;
        case 64:
            Sg2ModSetParam(D_40110B50[id][0], 512, a2, 0);
            break;
        case 128:
            Sg2ModSetParam(D_40110B50[id][0], 1024, a2, a3);
            break;
        case 256:
            Sg2ModSetParam(D_40110B50[id][0], 2048, a2, a3);
            break;
        case 512:
            Sg2ModSetParam(D_40110B50[id][0], 4096, a2, a3);
            break;
        }
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", Sg2SepMidiOut);
s32 Sg2SepMidiOut(u32 id, s32 len, u8 *data)
{
    s32 n;
    u8 *src;

    if (id < 32)
    {
        if (D_40110B40[id].status == 0 || D_40110B40[id].status == 2)
        {
            return -1;
        }
        D_40111660[D_40111760++] = D_40110B40[id].sub.mod;
        D_40111660[D_40111760++] = len;
        src = data;
        n = len;
        while (n != 0)
        {
            D_40111660[D_40111760++] = *src++;
            n--;
        }
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", Sg2SepMasterVol);
s32 Sg2SepMasterVol(s32 vab, s32 vol)
{
    s32 i;
    Sg2SepSlot *p;

    if (!vab_check_alive(vab))
    {
        return -1;
    }
    vab_set_semastervol(vab, vol);
    for (p = D_40110B40, i = 31; i >= 0; i--, p++)
    {
        if (p->vab == vab)
        {
            Sg2ModSetParam(p->sub.mod, 2, vol, 0);
        }
    }
    return vol;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", Sg2SepTickProc);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", Sg2SepInit);
s32 Sg2SepInit(void)
{
    s32 i;
    Sg2SepSlot *base = D_40110B40;
    for (i = 0; i < 32; i++)
    {
        Sg2SepSub *sub = &D_40110B40[i].sub;
        memset(&base[i], 0, 0x50);
        D_40110B40[i].status = 0;
        sub->unk4 = -1;
        sub->unk8 = -1;
        D_40110B40[i].vab = -1;
    }
    D_40111540 = 1;
    Sg2CtrlEntryTickProcById(1, Sg2SepTickProc);
    return 0;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", debug_sep_config);

void func_40038100(void) {
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", func_40038108);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", func_400381B8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", func_40038720);

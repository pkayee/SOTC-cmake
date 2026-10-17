#include "common.h"

typedef struct
{
    s32 mod;         /* 0x10 */
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10[8];
    u8 *data;        /* 0x40 */
    u8 skipWait;     /* 0x44 */
    u8 pad35[3];
    s32 runStatus;   /* 0x48 */
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

typedef struct
{
    s32 idx;
    u32 serial;
} SepPick;

typedef struct
{
    s32 mod;        /* sub+0x00 */
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s64 step;       /* sub+0x10 (slot+0x20) */
    s64 accum;      /* sub+0x18 */
    s64 next;       /* sub+0x20 */
    s32 counter;    /* sub+0x28 */
    u8 *start;      /* sub+0x2C */
    u8 *data;       /* sub+0x30 */
    u8 skipWait;    /* sub+0x34 */
    u8 pad35[3];
    s32 runStatus;  /* sub+0x38 */
    s32 unk3C;
} Sg2SepSubD;

typedef struct
{
    s32 status;
    s32 savedStatus;
    s32 unk8;
    s32 vab;
    Sg2SepSubD sub;
} Sg2SepSlotD;

extern void (*D_40046328[16])(Sg2SepSlotD *);
s64 dpadd(s64, s64);
s32 dpcmp(s64, s64);
s64 __floatdidf(s64);
void Sg2ModMidiout(s32 mod, s32 len, u8 *data);

s64 dpdiv(s64, s64);
s64 dpsub(s64, s64);
s64 dpmul(s64, s64);
s64 litodp(s32);
s32 dptoli(s64);
s32 sprintf(char *s, const char *fmt, ...);
char *strcat(char *dst, const char *src);

/* NEARMISS-STUB func_40037188 */
#if 0 /* NEARMISS 91.86% cat=cse-hoist sub=- | scan-loop induction pointer slot vs slot+0x10; min-loop q=sp+8 element vs serial address | attempts=1 */
void func_40037188(s32 vab, s32 prog, s32 flags, u32 maxN)
{
    SepPick *w;
    SepPick *q;
    Sg2SepSlot *p;
    s32 i;
    u32 n;
    u32 k;
    SepPick list[49];

    n = 0;
    w = list;
    for (i = 0, p = D_40110B40; i < 32; i++, p++)
    {
        if (p->vab == vab && p->sub.unk4 == prog && p->sub.unk8 == flags)
        {
            w->idx = i;
            w->serial = p->unk8;
            w++;
            n++;
        }
    }
    if (n > maxN)
    {
        list[48].idx = list[0].idx;
        list[48].serial = list[0].serial;
        for (k = 1, q = &list[1]; k < n; k++, q++)
        {
            if (q->serial < list[48].serial)
            {
                list[48].idx = q->idx;
                list[48].serial = q->serial;
            }
        }
        Sg2SepStopSndOff(list[48].idx);
        D_40110B40[list[48].idx].sub.unk4 = -1;
    }
}
#endif
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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", func_40038108);
void func_40038108(Sg2SepSlot *slot)
{
    u8 status = slot->sub.runStatus;
    u8 b0 = *slot->sub.data++;
    u8 b1 = *slot->sub.data++;
    u8 b2 = *slot->sub.data++;

    if (D_40111654 != status)
    {
        D_40111654 = status;
        D_40111550[D_40111650++] = status;
    }
    D_40111550[D_40111650++] = b0;
    D_40111550[D_40111650++] = b1;
    D_40111550[D_40111650++] = b2;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", func_400381B8);

/* NEARMISS-STUB func_40038720 */
#if 0 /* NEARMISS 91.67% cat=regalloc sub=- | slot in a3/rs in a2 in target; lui hoist of D_40111550/650; 0x3F loaded early | attempts=1 */
void func_40038720(Sg2SepSlot *slot)
{
    u8 type;
    u8 len;
    s32 rs = slot->sub.runStatus;

    if (rs == 0xFF)
    {
        type = *slot->sub.data++;
        len = *slot->sub.data++;
        if (type == 0x2F)
        {
            slot->sub.data = NULL;
            slot->status = 2;
            if (rs != D_40111654)
            {
                D_40111654 = rs;
                D_40111550[D_40111650++] = rs;
            }
            D_40111550[D_40111650++] = 0x3F;
            D_40111550[D_40111650++] = len;
        }
    }
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/sep", func_40038720);

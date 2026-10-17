#include "common.h"

typedef struct { s32 f[117]; } PcmInSlot;
typedef struct { s32 f[49]; } PcmAfSlot;
typedef struct
{
    s32 type;
    f32 a0;
    f32 a1;
    f32 a2;
    f32 b0;
    f32 b1;
    f32 b2;
    f32 z[4];
    f32 gain;
    f32 freq;
    f32 nb[5];
} PcmIir;

typedef struct
{
    s32 f00;
    s32 flags;
    s32 type8;
    f32 targetA;
    f32 targetB;
    f32 rateA;
    f32 rateB;
    void *f1C;
    s32 f20;
    s32 remain;
    void *cur;
    void *loopPtr;
    s32 loopCnt;
    PcmIir iir1;
    PcmIir iir2;
} PcmAfRec;

typedef struct
{
    s16 *pcm;       /* +0x00 sample ring (user buffer / IOP-bound buffer) */
    f32 *work;      /* +0x04 malloc'd float work buffer (2 channels x 0x400 B blocks) */
    s32 size;       /* +0x08 ring size in samples */
    s32 chunk;      /* +0x0C */
    s32 pos;        /* +0x10 read/write position */
    PcmAfRec af[2]; /* +0x14, stride 0xC4 */
} PcmStream;

typedef struct
{
    s32 ctrl;       /* +0x000 bit0 play, bit1 stop; init 2 */
    PcmStream st;   /* +0x004 */
    s32 flags;      /* +0x1A0 2 = stop at end, 4 = loop region */
    s32 mode;       /* +0x1A4 0 interleaved, 1 split halves */
    s32 outMode;    /* +0x1A8 */
    s32 vol;        /* +0x1AC */
    s32 phase[2];   /* +0x1B0 */
    s32 outVol[2];  /* +0x1B8 */
    s32 pan;        /* +0x1C0 */
    s32 lipLen;     /* +0x1C4 */
    s32 loopStart;  /* +0x1C8 */
    s32 loopEnd;    /* +0x1CC */
    s32 playFrames; /* +0x1D0 */
} PcmIn;
extern PcmInSlot D_4011596C[];
extern PcmInSlot D_40115B28[];
extern PcmInSlot D_40115B00[];
extern PcmAfSlot D_401157BC[];
extern s32 D_401157B8;
typedef struct {
    s32 outMode;    /* +0x000 */
    s32 ctrl;       /* +0x004 */
    PcmStream st;   /* +0x008 pcm=+8, work=+0xC, size=+0x10, chunk=+0x14, pos=+0x18 */
    s32 mode;       /* +0x1A4 */
    s32 len;        /* +0x1A8 */
    s32 f1AC;
    s32 f1B0;       /* +0x1B0 half-buffer toggle */
} PcmOut;
extern PcmOut D_401157A0;
extern s32 D_401157A8[];
extern s32 D_401160A8;
s32 Sg2StPcmSetVolume(s32 arg0, s32 arg1);
s32 Sg2StPcmSetEffect(s32 arg0);
void *memset(void *s, int c, unsigned long n);
void *malloc(s32 n);
void func_4003FC78();
s32 Sg2StPcmIopTransOffset(void);
void func_40040118(void);
void IirParam(void *iir, s32 type, f32 freq, f32 gain);
extern PcmIn D_40115958[];
extern PcmInSlot D_4011595C[];
extern PcmInSlot D_40115970[];
extern PcmInSlot D_40115B04[];
extern PcmInSlot D_40115B18[];
extern s32 D_401157AC;
s32 func_40040398(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7);
void Sg2ExPcmOutputCtrl(s32 arg0);
s32 DIntr(void);
void EIntr(void);
void free(void *p);
void func_40040710();
extern s32 D_401157B0;
void Sg2ExPcmInputCtrl(u32 arg0, s32 arg1);
void func_4003FF10(void *a0, s32 a1, void *a2, s32 a3);
void func_4003FD60(s32 *a0, s32 a1, s32 a2, s32 a3, f32 f12, f32 f13);
void func_4003FAD0(s32 *arg0, s32 arg1);
void func_4003F928(s32 *arg0, s32 arg1);
void func_4003F7E8(s32 *arg0, s32 arg1);
s32 Sg2StPcmInit(s32 arg0);
s32 Sg2CtrlGetTickMode(void);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F3C8);
void func_4003F3C8(s32 *arg0, s32 arg1)
{
    memset((void *)arg0[1], 0, arg1 * 4);
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F3E8);
void func_4003F3E8(s32 *arg0, s32 arg1)
{
    s16 *out = (s16 *)arg0[0] + arg0[4];
    f32 *in = (f32 *)arg0[1];
    s32 i;

    for (i = 0; i < arg1; i++)
    {
        f32 v = in[i];

        if (v > 32767.0f)
        {
            v = 32767.0f;
        }
        if (v < -32768.0f)
        {
            v = -32768.0f;
        }
        out[i] = (s32)v;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F468);
void func_4003F468(s32 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 pos = arg0[4];
    f32 *out1 = (f32 *)arg0[1];
    f32 *out2 = (f32 *)(arg0[1] + 0x400);
    s16 *buf = (s16 *)arg0[0] + pos;
    s32 i;
    s32 j;

    for (i = 0; i < arg1;)
    {
        for (j = 0; j < 0x100; j++)
        {
            s32 sample = buf[i];

            i++;
            *out1++ = (sample * arg2) / 100;
            *out2++ = (sample * arg3) / 100;
        }
        out1 += 0x100;
        out2 += 0x100;
    }
    arg0[4] = pos + arg1;
    if (arg0[4] >= arg0[2])
    {
        arg0[4] = 0;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F528);
void func_4003F528(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    f32 *out1 = (f32 *)arg0[1];
    f32 *out2 = (f32 *)(arg0[1] + 0x400);
    s16 *buf = (s16 *)arg0[0];
    s32 idx = arg0[4];
    s32 i;

    for (i = 0; i < arg1; i += 0x100)
    {
        s32 div = 100;
        s32 j;

        for (j = 0xFF; j >= 0; j--)
        {
            s32 sample = buf[idx];

            idx++;
            if (arg5 < idx)
            {
                idx = arg4;
            }
            *out1++ = (sample * arg2) / div;
            *out2++ = (sample * arg3) / div;
        }
        out1 += 0x100;
        out2 += 0x100;
    }
    arg0[4] = idx;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F5D0);
void func_4003F5D0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 pos = arg0[4];
    f32 *out = (f32 *)arg0[1];
    s16 *buf = (s16 *)arg0[0] + pos;
    s32 i;
    s32 j;

    for (i = 0; i < arg1; i += 0x200)
    {
        for (j = 0; j < 0x100; j++)
        {
            *out++ = (*buf++ * arg2) / 100;
        }
        for (j = 0; j < 0x100; j++)
        {
            *out++ = (*buf++ * arg3) / 100;
        }
    }
    arg0[4] = pos + arg1;
    if (arg0[4] >= arg0[2])
    {
        arg0[4] = 0;
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F6A0);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F788);
void func_4003F788(s32 *arg0, s32 arg1)
{
    f32 *buf = (f32 *)arg0[1];
    s32 i = 0;

    while (i < arg1)
    {
        f32 v = (buf[i] + buf[i + 256]) * 0.5f;
        buf[i + 256] = v;
        buf[i] = v;
        i++;
        if (i & 0x100)
        {
            i += 0x100;
        }
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F7E8);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F8F0);
void func_4003F8F0(s32 *arg0, s32 *arg1, s32 arg2)
{
    f32 *a = (f32 *)arg0[1];
    f32 *b = (f32 *)arg1[1];

    if (arg2 > 0)
    {
        do
        {
            *a = *a + *b;
            b++;
            a++;
            arg2--;
        } while (arg2 != 0);
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003F928);
void func_4003F928(s32 *arg0, s32 arg1)
{
    s32 *p = arg0 + 1;
    s32 n = arg1;
    s32 len = p[2];
    s32 pos = p[4];
    s32 mode;

    if (arg0[104] & 2)
    {
        if (!(pos + n < len))
        {
            n = len - pos;
            arg0[0] = 2;
        }
    }
    mode = arg0[105];
    switch (mode)
    {
    case 0:
        if (arg0[114] != 0 || arg0[115] != 0)
        {
            func_4003F528(p, n / 2, arg0[110], arg0[111], arg0[114], arg0[115]);
        }
        else
        {
            func_4003F468(p, n / 2, arg0[110], arg0[111]);
        }
        break;
    case 1:
        if (arg0[114] != 0 || arg0[115] != 0)
        {
            func_4003F6A0(p, n, arg0[110], arg0[111], arg0[114], arg0[115]);
        }
        else
        {
            func_4003F5D0(p, n, arg0[110], arg0[111]);
        }
        break;
    }
    if (arg0[105] == 1 && arg0[106] == 0)
    {
        func_4003F788(p, n);
    }
    func_4003F7E8(p, n);
    if (arg0[113] != 0)
    {
        if (arg0[105] == 0)
        {
            n /= 2;
        }
        arg0[116] = arg0[116] + n;
        arg0[116] = (u32)arg0[116] % ((u32)arg0[113] >> 1);
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003FAD0);
void func_4003FAD0(s32 *arg0, s32 arg1)
{
    s32 i;

    if (arg0[1] & 4)
    {
        return;
    }
    func_4003F3C8(arg0 + 2, arg1);
    for (i = 0; i < 4; i++)
    {
        if (D_40115958[i].ctrl & 1)
        {
            func_4003F928((s32 *)&D_40115958[i], arg1);
            func_4003F8F0(arg0 + 2, (s32 *)&D_40115958[i].st, arg1);
        }
    }
    func_4003F7E8(arg0 + 2, arg1);
    if (arg0[0] == 0)
    {
        func_4003F788(arg0 + 2, arg1);
    }
    func_4003F3E8(arg0 + 2, arg1);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003FBD8);
void func_4003FBD8(PcmInSlot *arg0, s32 arg1)
{
    s32 pos;
    s32 ring;

    ((s32 (*)(s32, s16 *, s16 *, s32))D_401160A8)(0, (s16 *)arg0->f[2] + arg0->f[6], (s16 *)arg0->f[105] + arg0->f[107], arg1 * 2);
    pos = arg0->f[6] + arg1;
    arg0->f[6] = pos;
    pos = pos % arg0->f[4];
    ring = arg0->f[107] + arg1;
    arg0->f[107] = ring;
    arg0->f[6] = pos;
    arg0->f[107] = ring % arg0->f[106];
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003FC78);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003FD60);
void func_4003FD60(s32 *a0, s32 a1, s32 a2, s32 a3, f32 f12, f32 f13)
{
    PcmAfRec *rec;
    s32 intr;
    f32 curA;
    f32 curB;
    f32 ticks;

    rec = (PcmAfRec *)((u8 *)a0 + a1 * 0xC4 + 0x14);
    intr = DIntr();
    curA = rec->iir1.freq;
    curB = rec->iir1.gain;
    ticks = 1000.0f / (f32)Sg2CtrlGetTickMode();
    ticks = (f32)a2 / ticks;
    if (ticks < 1.0f)
    {
        ticks = 1.0f;
    }
    if (a3 != 0)
    {
        rec->type8 = a3;
        rec->flags |= 4;
    }
    if ((f32)(s32)f12 != -1000.0f)
    {
        rec->targetA = f12;
        rec->flags |= 1;
        rec->rateA = (f12 - curA) / ticks;
    }
    if ((f32)(s32)f13 != -1000.0f)
    {
        rec->targetB = f13;
        rec->flags |= 2;
        rec->rateB = (f13 - curB) / ticks;
    }
    if (rec->flags != 0)
    {
        rec->f00 = 1;
    }
    if (intr != 0)
    {
        EIntr();
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_4003FF10);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_400400A0);
s32 func_400400A0(u8 *arg0)
{
    if (arg0[0] != 0x45 || arg0[1] != 0x51 || arg0[2] != 0x41 || arg0[3] != 0x54)
    {
        return -1;
    }
    return ((s32 *)arg0)[1];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_400400F0);
void *func_400400F0(s32 *arg0, s32 arg1)
{
    return (char *)arg0 + (arg0[arg1 + 2] / 4) * 4;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_40040118);
//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_40040350);
s32 func_40040350(void)
{
    s32 i;
    for (i = 0; i < 4; i++)
    {
        if (D_40115958[i].st.pcm == 0)
        {
            return i;
        }
    }
    return -1;
}

/* NEARMISS-STUB func_40040398 */
#if 0 /* NEARMISS 96.45% cat=sched sub=delay-slot | jal malloc delay slot: target fills it with addu s1,s1,a1 (p=&D_40115958[idx] after call); ours hoists addu before jal, nop in slot. Tail store order: target ch | attempts=2 */
s32 func_40040398(s16 *pcm, s32 size, s32 chunk, s32 mode, s32 flags, s32 ls, s32 le, s32 lipLen)
{
    s32 idx;
    PcmIn *p;
    f32 *work;
    s32 intr;

    idx = func_40040350();
    if (idx == -1)
    {
        return idx;
    }
    p = &D_40115958[idx];
    work = malloc(chunk * 4);
    p->st.work = work;
    if (work == 0)
    {
        return -2;
    }
    intr = DIntr();
    p->mode = mode;
    p->outMode = mode;
    p->flags = flags;
    p->loopStart = ls;
    p->loopEnd = le;
    p->ctrl = 2;
    p->lipLen = lipLen;
    Sg2ExPcmInputSetVol(idx, 100);
    Sg2ExPcmInputSetPan(idx, 0x40);
    Sg2ExPcmInputSetPhase(idx, 1, 1);
    p->st.pcm = pcm;
    p->st.pos = 0;
    p->st.size = size;
    p->playFrames = 0;
    p->st.chunk = chunk;
    Sg2ExPcmInputAutoFilterInit(idx, 0);
    Sg2ExPcmInputAutoFilterInit(idx, 1);
    if (intr)
    {
        EIntr();
    }
    return idx;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_40040398);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputOpenDoubleBuffer);
s32 Sg2ExPcmInputOpenDoubleBuffer(s32 arg0, s32 arg1, s32 arg2)
{
    return func_40040398(arg0, arg1, arg1 / 2, arg2, 1, 0, 0, 0);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputOpen);
//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputClose);
void Sg2ExPcmInputClose(u32 arg0)
{
    s32 intr;

    if (arg0 >= 4)
    {
        return;
    }
    intr = DIntr();
    Sg2ExPcmInputCtrl(arg0, 2);
    free(D_40115958[arg0].st.work);
    D_40115958[arg0].st.pcm = 0;
    D_40115958[arg0].st.work = 0;
    if (intr)
    {
        EIntr();
    }
}
//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputCtrl);
void Sg2ExPcmInputCtrl(u32 arg0, s32 arg1)
{
    s32 intr;

    if (arg0 >= 4 || (arg1 & 3) == 3)
    {
        return;
    }
    intr = DIntr();
    if (arg1 & 1)
    {
        D_40115958[arg0].st.pos = 0;
        D_40115958[arg0].playFrames = 0;
    }
    D_40115958[arg0].ctrl = arg1;
    if (intr)
    {
        EIntr();
    }
}
//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputGetLipFrame);
s32 Sg2ExPcmInputGetLipFrame(u32 arg0)
{
    s32 ret;
    if (arg0 >= 4)
    {
        return -1;
    }
    ret = D_4011596C[arg0].f[0];
    return ret;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputGetRealPlayFrameCount);
s32 Sg2ExPcmInputGetRealPlayFrameCount(u32 arg0)
{
    s32 ret;
    if (arg0 >= 4)
    {
        return -1;
    }
    ret = D_40115B28[arg0].f[0];
    return ret;
}


extern u16 pan_tbl[];
/* NEARMISS-STUB func_40040710 */
#if 0 /* NEARMISS 88.48% cat=regalloc sub=- | target vol->a0 ph1->t0 ph0->v1 pan->a1; ours vol->a1 ph1->v0 pan->a0 | attempts=1 */
void func_40040710(u32 idx)
{
    if (idx < 4)
    {
        s32 d = 127;
        s32 d2 = 127;
        PcmInSlot *p = &D_40115958[idx];
        s32 vol = p->f[107];
        s32 ph0 = p->f[108];
        s32 ph1 = p->f[109];
        s32 pan = p->f[112];
        s32 l = vol * ph0;
        s32 r = vol * ph1;
        u16 tbl = pan_tbl[pan];
        p->f[110] = l * (tbl >> 8) / d;
        p->f[111] = r * (tbl & 0xFF) / d2;
    }
}

/* kR38 (repair, not matched): best 88.48% = kR31 form (vol,ph0,ph1,pan load order; d/d2 locals; pan_tbl extern).
   Tried: ph1-before-ph0 declare order 87.97; pan-table-as-u8 two loads 79.52; lo/hi split order swap 81.76;
   tbl read before l/r products 88.48 (no change). Residual: target allocs vol->a0, ph1->t0, ph0->v1, pan->a1;
   ours vol->a1, ph1->v0, pan->a0; mult1 operands differ. Needs an idea (register allocation), not a mechanical fix. */
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", func_40040710);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputSetVol);
void Sg2ExPcmInputSetVol(u32 arg0, s32 arg1)
{
    if (arg0 < 4)
    {
        D_40115B04[arg0].f[0] = arg1;
        func_40040710(arg0);
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputSetPan);
void Sg2ExPcmInputSetPan(u32 arg0, s32 arg1)
{
    if (arg0 < 4)
    {
        D_40115B18[arg0].f[0] = arg1;
        func_40040710(arg0);
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputSetPhase);
void Sg2ExPcmInputSetPhase(u32 arg0, s32 arg1, s32 arg2)
{
    if (arg0 < 4)
    {
        PcmIn *p = &D_40115958[arg0];
        p->phase[0] = arg1;
        p->phase[1] = arg2;
        func_40040710(arg0);
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputSetOutputMode);
void Sg2ExPcmInputSetOutputMode(u32 arg0, s32 arg1)
{
    if (arg0 < 4)
    {
        D_40115B00[arg0].f[0] = arg1;
    }
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputAutoFilterInit);
void Sg2ExPcmInputAutoFilterInit(u32 arg0)
{
    if (arg0 < 4)
    {
        func_4003FC78(&D_4011595C[arg0]);
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputSetAutoFilterDirect);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputSetAutoFilter);
s32 Sg2ExPcmInputSetAutoFilter(u32 arg0, u8 *arg1, s32 arg2)
{
    s32 r;

    if (arg0 >= 4)
    {
        return -2;
    }
    r = func_400400A0(arg1);
    if (r == -1)
    {
        return -1;
    }
    if (!(arg2 < r))
    {
        return -2;
    }
    func_4003FF10(func_400400F0((s32 *)arg1, arg2), arg0, arg1, arg2);
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInputAutoFilterCtrl);
void Sg2ExPcmInputAutoFilterCtrl(u32 arg0, s32 arg1, s32 arg2)
{
    if (arg0 < 4)
    {
        *(s32 *)((u8 *)D_40115970 + arg1 * 196 + arg0 * 468) = arg2;
    }
}

s32 Sg2ExPcmOutputBufferClear(void);
void Sg2ExPcmOutputAutoFilterInit(s32 arg0);

s32 Sg2ExPcmOutputOpen(s32 arg0, s16 *arg1, s32 arg2)
{
    PcmOut *o = &D_401157A0;
    f32 *work;
    s32 intr;

    if (o->st.work != 0)
    {
        return -1;
    }
    work = malloc((arg2 / 2) * 4);
    o->st.work = work;
    if (work == 0)
    {
        return -2;
    }
    intr = DIntr();
    o->st.pcm = arg1;
    o->len = arg2;
    o->f1B0 = 0;
    o->st.size = arg2;
    o->mode = arg0;
    o->st.chunk = arg2;
    o->st.pos = 0;
    Sg2ExPcmOutputBufferClear();
    o->st.pos = 0;
    o->f1AC = 0;
    Sg2ExPcmOutputAutoFilterInit(0);
    Sg2ExPcmOutputAutoFilterInit(1);
    o->outMode = 1;
    if (intr)
    {
        EIntr();
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputClose);
s32 Sg2ExPcmOutputClose(void)
{
    s32 intr;
    s32 buf;
    s32 *p;

    intr = DIntr();
    Sg2ExPcmOutputCtrl(2);
    p = (s32 *)&D_401157A0;
    buf = p[3];
    p[3] = 0;
    if (intr)
    {
        EIntr();
    }
    free((void *)buf);
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputBufferClear);
s32 Sg2ExPcmOutputBufferClear(void)
{
    s32 *p = (s32 *)&D_401157A0;
    s32 intr;

    if (p[3] != 0)
    {
        return -1;
    }
    intr = DIntr();
    func_4003FAD0(p, p[4]);
    if (intr != 0)
    {
        EIntr();
    }
    func_4003FBD8((PcmInSlot *)p, p[4]);
    p[6] = 0;
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputSetVol);
void Sg2ExPcmOutputSetVol(s32 arg0, s32 arg1)
{
    Sg2StPcmSetVolume(arg0, arg1);
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputSetEffect);
void Sg2ExPcmOutputSetEffect(s32 arg0)
{
    Sg2StPcmSetEffect(arg0);
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputSetOutputMode);
void Sg2ExPcmOutputSetOutputMode(s32 arg0)
{
    D_401157A0.outMode = arg0;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputCtrl);
void Sg2ExPcmOutputCtrl(s32 arg0)
{
    if ((arg0 & 3) == 3)
    {
        return;
    }
    if (arg0 & 1)
    {
        if (!(D_401157A0.ctrl & 1))
        {
            D_401157A0.st.pos = 0;
            if (D_401157A0.mode != 0)
            {
                if (D_401157A0.st.work != 0)
                {
                    Sg2StPcmStart(D_401157A0.mode, D_401157A0.len << 1);
                }
            }
        }
    }
    if (arg0 & 2)
    {
        Sg2StPcmStop();
    }
    D_401157A0.ctrl = arg0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputGetLipFrame);
s32 Sg2ExPcmOutputGetLipFrame(void)
{
    return D_401157B8;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputAutoFilterInit);
void Sg2ExPcmOutputAutoFilterInit(s32 arg0)
{
    func_4003FC78(D_401157A8, arg0);
}


/* NEARMISS-STUB Sg2ExPcmOutputSetAutoFilterDirect */
#if 0 /* NEARMISS 89.88% cat=regalloc sub=- | s1/s2/s3 swap: target base=s1,arg2=s2,arg1=s3 | attempts=1 */
kR38 (Haiku repair) Sg2ExPcmOutputSetAutoFilterDirect: best 89.88% (kR31 baseline, not matched). pcm.c restored to INCLUDE_ASM; the function stays INCLUDE_ASM.
Best C (= kR31 body, unchanged):
void Sg2ExPcmOutputSetAutoFilterDirect(s32 arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4)
{ s32 *base; s32 *p; s32 intr; base = D_401157A8; intr = DIntr(); p = base + arg0 * 49;
  p[12] = 0; p[13] = -1; p[15] = 0; if (intr != 0) { EIntr(); }
  func_4003FD60(D_401157A8, arg0, arg1, arg2 != -1000 ? arg2 : 0, arg3, arg4); }
Compact diff (target vs best):
- regs: target s1=&D_401157A8, s2=arg2, s3=arg1; ours s1=arg2, s2=arg1, s3=base (replace x3, arg_mism tail).
- stores: target uses two pointers, v1=&base[49a] for p[12] and a1=&base[49a+12] (addiu a0,v1,0x30; addu a1,s1,a0) for p[13]/p[15]; ours one pointer with offsets 0x34/0x3c/0x30.
Tried (kR38):
- tail uses base instead of D_401157A8: 89.88 (CSE, identical).
- base[arg0*49+k] indexing: 89.88 (CSE, identical).
- second pointer q=(s32*)((u8*)base+arg0*196+0x30), q[1]=-1, q[3]=0: 88.44 (worse).
- no base local (lui after DIntr, D_401157A8+arg0*49): 27.0 (much worse).
Cause: callee-saved allocation (base gets s3, target s1); not fixed by mechanical edits. Needs an Opus idea for the two-pointer store pattern / reg priority.
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputSetAutoFilterDirect);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputSetAutoFilter);
s32 Sg2ExPcmOutputSetAutoFilter(u8 *arg0, s32 arg1)
{
    s32 r;

    r = func_400400A0(arg0);
    if (r == -1)
    {
        return -1;
    }
    if (!(arg1 < r))
    {
        return -2;
    }
    func_4003FF10(func_400400F0((s32 *)arg0, arg1), 5, arg0, arg1);
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmOutputAutoFilterCtrl);
void Sg2ExPcmOutputAutoFilterCtrl(s32 arg0, s32 arg1)
{
    D_401157BC[arg0].f[0] = arg1;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmCheckAutoFilterSeq);
void Sg2ExPcmCheckAutoFilterSeq(u8 *arg0)
{
    func_400400A0(arg0);
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmTickProc);
void Sg2ExPcmTickProc(void)
{
    s32 off;
    s32 len;

    func_40040118();
    if (D_401157A0.ctrl & 2)
    {
        return;
    }
    off = Sg2StPcmIopTransOffset();
    len = D_401157A0.len / 2;
    if (off / 2 / len == D_401157A0.f1B0)
    {
        return;
    }
    func_4003FAD0((void *)&D_401157A0, len);
    func_4003FBD8((PcmInSlot *)&D_401157A0, len);
    D_401157A0.f1B0 = (D_401157A0.f1B0 + 1) % 2;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmSetSignal);
void Sg2ExPcmSetSignal(s32 arg0)
{
    D_401160A8 = arg0;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/pcm", Sg2ExPcmInit);
s32 Sg2ExPcmInit(void)
{
    s32 i;
    PcmIn *p;

    Sg2StPcmInit(0);
    memset(&D_401157A0, 0, 0x1B4);
    p = D_40115958;
    for (i = 0; i < 4; i++)
    {
        p->ctrl = 2;
        p->flags = 0;
        p->st.af[0].f00 = 0;
        p->st.af[0].flags = 0;
        p->st.af[0].f1C = 0;
        p->st.af[0].cur = 0;
        p->st.af[1].f00 = 0;
        p->st.af[1].flags = 0;
        p->st.af[1].f1C = 0;
        p->st.af[1].cur = 0;
        p->st.pcm = 0;
        p->st.size = 0;
        p->st.pos = 0;
        p++;
    }
    Sg2ExPcmOutputCtrl(2);
    return 0;
}

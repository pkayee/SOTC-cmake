#include "common.h"

extern s32 D_400F8F7C;
extern s32 (*D_400F9040)(void*, s32, s32, s32);
extern s32 Sg2StAdpcmQuit(void);
extern s32 Sg2StAdpcmSetPitch(u64, u32);
extern s32 Sg2ExStAdpcmSlotFree(void);
extern s32 D_400F8F78;
extern s32 D_400F8F80[48];
extern s32 Sg2StAdpcmInit(s32);
extern s32 Sg2StAdpcmPlay(u64);
extern s32 Sg2StAdpcmClose(s32);
extern s32 Sg2StAdpcmStop(u64);
extern s32 Sg2StAdpcmSetVolume(u64, s32, s32);
extern s32 Sg2StAdpcmIopReadAdr(s32);
extern s32 Sg2SlotFree(s32);
extern void* memset(void*, s32, u32);
extern void ____VolReflection(void*);
extern s32 func_40031728(void*);
extern void func_40032608(void*);
extern void func_400327D0(void*);
extern s32 Sg2ExStAdpcmSlotReserv(s32, s32);
extern void Sg2SlotSetReverbOnBit(s32, s32);
extern void Sg2SlotSetReverbOffBit(s32, s32);
extern void func_40032420(void*, s32, s32, s32);
extern s32 Sg2ExStAdpcmIopReadAdr(void*, s32);
extern s32 Sg2SlotFreeSearchTerm(s32);
extern void Sg2SlotBlock(s32, s32);

typedef struct { u8 pad[0x240]; s32 lr[16][2]; } StAdpcmVolSub;          /* starts at ctx+0xC */
typedef struct { u8 pad[0x30]; s32 l[8]; s32 r[8]; } StAdpcmSendSub;     /* starts at ctx+0x10 */
typedef struct
{
    u8 pad0[0xC];
    union
    {
        StAdpcmVolSub c;
        struct { s32 pad; StAdpcmSendSub d; } d;
    } u;
} StAdpcmVolCtx;

/* NEARMISS-STUB Sg2ExStAdpcmInit */
#if 0 /* NEARMISS 95.17% cat=volatile-alias sub=- | needs volatile (banned): D_400F8F78 store folds %lo into sw in matched build; volatile-free forms (ptr local, array extern, reorder, cast-addr) keep addiu v1,%l | attempts=1 */
void Sg2ExStAdpcmInit(void)
{
    s32 i;

    for (i = 47; i >= 0; i--)
    {
        D_400F8F80[i] = 0;
    }
    Sg2StAdpcmInit(0);
    D_400F8F78 = 1;
    D_400F8F7C = 0;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmInit);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmStopMode);
void Sg2ExStAdpcmStopMode(s32 arg0)
{
    D_400F8F7C = arg0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmQuit);
s32 Sg2ExStAdpcmQuit(void)
{
    Sg2ExStAdpcmSlotFree();
    return Sg2StAdpcmQuit();
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmSlotMalloc);
s32 Sg2ExStAdpcmSlotMalloc(s32 arg0)
{
    return Sg2ExStAdpcmSlotReserv(0, arg0);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmSlotReserv);
s32 Sg2ExStAdpcmSlotReserv(s32 isTerm, s32 n)
{
    s32 i;
    s32 s;
    s32 cnt = 0;
    s32 term = isTerm != 0;
    for (i = 0; i < n; i++)
    {
        s = Sg2SlotFreeSearchTerm(term);
        if (s != -1)
        {
            Sg2SlotBlock(3, s);
            D_400F8F80[s] = 1;
            cnt++;
        }
    }
    return cnt;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmSlotFree);
s32 Sg2ExStAdpcmSlotFree(void)
{
    s32 i;
    s32 n = 0;

    for (i = 0; i < 48; i++)
    {
        if (D_400F8F80[i] > 0)
        {
            Sg2SlotFree(i);
            n++;
            D_400F8F80[i] = 0;
        }
    }
    return n;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmWorkClear);
void Sg2ExStAdpcmWorkClear(void* p, s32 v)
{
    memset(p, 0, 0x2E0);
    *(s32*)((u8*)p + 0) = 0;
    *(s32*)((u8*)p + 8) = v;
    *(s32*)((u8*)p + 0xC) = v;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", func_40031728);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmOpenFake);
s32 Sg2ExStAdpcmOpenFake(void* p)
{
    u32* magic = (u32*)((u8*)p + 0x28);

    if (*(s32*)((u8*)p + 0) != 0)
    {
        return -3;
    }
    if (*magic != 0x54535845)
    {
        return -1;
    }
    *(s32*)((u8*)p + 0x2D4) = 0;
    *(s32*)((u8*)p + 0x248) = 0;
    *(u64*)((u8*)p + 0xA0) = 0;
    *(s32*)((u8*)p + 0x228) = 0;
    *(s32*)((u8*)p + 0x22C) = 0;
    memset((u8*)p + 0xA8, 0, 0x180);
    *(s32*)((u8*)p + 8) = *(s32*)((u8*)p + 0xC);
    return func_40031728(p) ? -2 : 0;
}

extern void* memcpy(void*, const void*, u32);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmOpen);
s32 Sg2ExStAdpcmOpen(void* p, void* hdr, s32 a, s32 b, s32 c, s32 d)
{
    s32 i;

    memcpy((u8*)p + 0x28, hdr, 0x78);
    *(s32*)((u8*)p + 0x230) = a;
    *(s32*)((u8*)p + 0x234) = b;
    *(s32*)((u8*)p + 0x238) = c;
    *(s32*)((u8*)p + 0x23C) = d;
    *(s32*)((u8*)p + 0x2D8) = 0;
    *(s32*)((u8*)p + 0x2DC) = 0;
    *(s32*)((u8*)p + 0x240) = *(s32*)((u8*)hdr + 0x10) << 11;
    *(s32*)((u8*)p + 0x244) = *(s32*)((u8*)hdr + 0x14) << 11;
    for (i = 0; i < 8; i++)
    {
        ((StAdpcmVolCtx*)p)->u.c.lr[i][1] = ((StAdpcmVolCtx*)p)->u.c.lr[i][0] = 100;
    }
    *(s32*)((u8*)p + 0x2CC) = 100;
    return Sg2ExStAdpcmOpenFake(p);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmSetFd);
s32 Sg2ExStAdpcmSetFd(void* p, s32 v)
{
    *(s32*)((u8*)p + 0x2D8) = v;
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmGetFd);
s32 Sg2ExStAdpcmGetFd(void* pAdpcm)
{
    return *(s32*)((u8*)pAdpcm + 0x2D8);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmSetLsn);
s32 Sg2ExStAdpcmSetLsn(void* p, s32 v)
{
    *(s32*)((u8*)p + 0x2D8) = v;
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmGetLsn);
s32 Sg2ExStAdpcmGetLsn(void* pAdpcm)
{
    return *(s32*)((u8*)pAdpcm + 0x2D8);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmGetTargetLsn);
s32 Sg2ExStAdpcmGetTargetLsn(void* p)
{
    return *(s32*)((u8*)p + 0x2D8) + (*(u32*)((u8*)p + 0x248) >> 11);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmSetUserParam);
s32 Sg2ExStAdpcmSetUserParam(void* p, s32 v)
{
    *(s32*)((u8*)p + 0x2DC) = v;
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmGetUserParam);
s32 Sg2ExStAdpcmGetUserParam(void* p)
{
    return *(s32*)((u8*)p + 0x2DC);
}

/* decomper FIX (scratch MATCH via cmp.sh; only diffs are the j-label name and TU padding).
   Needs `extern s32 D_400F8F78;` (see Sg2ExStAdpcmInit fix).
   Two embedded views of the ctx: track vol bank pairs at ctx+0xC+0x240 = ctx+0x24C (stride 8, [16][2]),
   per-track send L/R arrays at ctx+0x10+0x30 = ctx+0x40 / ctx+0x60 ([8] each).
   The pointer locals MUST be declared d first, then c (that gives addiu p+0x10 before addiu p+0xC). */

/* NEARMISS-STUB func_40031C08 */
#if 0 /* NEARMISS 78.2% cat=volatile-alias sub=- | needs volatile (banned): target re-reads D_400F8F78 between the two || compares and keeps lui+addiu address; volatile-free forms (ptr local, u32 cast reread, u3 | attempts=1 */
s32 func_40031C08(StAdpcmVolCtx* p, s32 voice, s32 idx)
{
    s32 l;
    s32 r;
    StAdpcmSendSub *d = &p->u.d.d;
    StAdpcmVolSub *c = &p->u.c;
    l = d->l[idx] * c->lr[idx][0] / 100;
    r = d->r[idx] * c->lr[idx][1] / 100;
    if (l >= 0x4000)
    {
        l = 0x3FFF;
    }
    if (r >= 0x4000)
    {
        r = 0x3FFF;
    }
    if (D_400F8F78 == 0 || D_400F8F78 == 2)
    {
        if (r < l)
        {
            r = l;
        }
        else
        {
            l = r;
        }
        if ((D_400F8F78 & 2) && *(s32*)((u8*)p + 0x2C) == 0x20000)
        {
            l /= 2;
            r /= 2;
        }
    }
    return Sg2StAdpcmSetVolume(1LL << voice, l, r);
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", func_40031C08);


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmVolumePercent);
s32 Sg2ExStAdpcmVolumePercent(void* p, s32 vol)
{
    u64 i;
    s32 cnt;
    s32 ret = -1;
    s32* q = (s32*)((u8*)p + 0x24C);

    for (i = 0; i < 8; i++)
    {
        q[0] = q[1] = vol;
        q += 2;
    }
    if (*(s32*)((u8*)p + 0) < 16)
    {
        return -1;
    }
    for (i = 0, cnt = 0; i < 48; i++)
    {
        if (*(u64*)((u8*)p + 0xA0) & (1LL << i))
        {
            func_40031C08(p, (s32)i, cnt++);
            ret = 0;
        }
    }
    return ret;
}

/* NEARMISS-STUB Sg2ExStAdpcmTrkVolumeDirect */
#if 0 /* NEARMISS 91.44% cat=regalloc sub=- | p in t2 trk in t1 vs a5/a4; volR cvt after L store | attempts=1 */
//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmTrkVolumeDirect);
s32 Sg2ExStAdpcmTrkVolumeDirect(StAdpcmVolCtx* p, s32 trk, s32 volL, s32 volR)
{
    StAdpcmSendSub *d = &p->u.d.d;
    StAdpcmVolSub *c = &p->u.c;
    s32 n;
    u64 i;
    f32 full = 8191.0f;
    f32 div = 127.0f;

    c->lr[trk][0] = (s32)(full / (f32)d->l[trk] * (f32)volL / div);
    c->lr[trk][1] = (s32)(full / (f32)d->r[trk] * (f32)volR / div);
    if (*(s32*)((u8*)p + 0) < 16)
    {
        return -1;
    }
    n = trk;
    for (i = 0; i < 48; i++)
    {
        if (*(u64*)((u8*)p + 0xA0) & (1LL << i))
        {
            if (--trk < 0)
            {
                func_40031C08(p, (s32)i, n);
                return 0;
            }
        }
    }
    return -1;
}

/* kR38 repair (haiku): best stays 91.44 (= kR29 C, unchanged). Tried, all <=91.44:
   v1 c-before-d local order 91.44; v2 f32 temp for (f32)volR set after the L store 91.44;
   v3 u64 t=(u32)trk index 75.3 (stride goes 64-bit, target uses 32-bit sll); v4 s32 *row=c->lr[trk] 77.0.
   Diff (target vs ours): ours hoists `mtc1 a3`+`cvt.s.w` (volR->f32) into the div.s latency nops
   right after the L-channel addu (target has nops there, volR conversion sits AFTER the swc1 0x240 store).
   Also p/trk regalloc: target p=t2(a6), trk=t1(a5); ours p=a5, trk=a4 (arg_mism cascade). */
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmTrkVolumeDirect);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmTrkVolumePercent);
s32 Sg2ExStAdpcmTrkVolumePercent(void* p, s32 trk, s32 volL, s32 volR)
{
    StAdpcmVolSub *c = &((StAdpcmVolCtx*)p)->u.c;
    u64 i;
    s32 n;

    c->lr[trk][0] = volL;
    c->lr[trk][1] = volR;
    if (*(s32*)((u8*)p + 0) < 16)
    {
        return -1;
    }
    n = trk;
    for (i = 0; i < 48; i++)
    {
        if (*(u64*)((u8*)p + 0xA0) & (1LL << i))
        {
            if (--trk < 0)
            {
                func_40031C08(p, (s32)i, n);
                return 0;
            }
        }
    }
    return -1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmTrkDspSw);
s32 Sg2ExStAdpcmTrkDspSw(void* p, s32 trk, s32 mode)
{
    u64 i;

    if (*(s32*)((u8*)p + 0) < 16)
    {
        return -1;
    }
    if (mode == -1)
    {
        mode = *(s32*)((u8*)p + 0x80 + trk * 4);
    }
    for (i = 0; i < 48; i++)
    {
        if (*(u64*)((u8*)p + 0xA0) & (1LL << (s32)i))
        {
            if (--trk < 0)
            {
                switch (mode)
                {
                case 0:
                    Sg2SlotSetReverbOffBit(i >= 24, 1 << (i < 24 ? (s32)i : (s32)(i - 24)));
                    break;
                case 1:
                    Sg2SlotSetReverbOnBit(i >= 24, 1 << (i < 24 ? (s32)i : (s32)(i - 24)));
                    break;
                }
                return 0;
            }
        }
    }
    return -1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", ____VolReflection);
void ____VolReflection(void* p)
{
    u64 i;
    s32 cnt;

    if (*(s32*)((u8*)p + 0) < 16)
    {
        return;
    }
    for (i = 0, cnt = 0; i < 48; i++)
    {
        if (*(u64*)((u8*)p + 0xA0) & (1LL << i))
        {
            func_40031C08(p, (s32)i, cnt++);
        }
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", ____VolPerBackup);
void ____VolPerBackup(void* p, s32 flag)
{
    u32* dst;
    u32* src;
    s32 i;

    if (flag)
    {
        src = (u32*)((u8*)p + 0x24C);
        dst = (u32*)((u8*)p + 0x28C);
    }
    else
    {
        src = (u32*)((u8*)p + 0x28C);
        dst = (u32*)((u8*)p + 0x24C);
    }
    for (i = 0; i < 8; i++)
    {
        *dst++ = *src++;
        *dst++ = *src++;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmPitchPercent);
s32 Sg2ExStAdpcmPitchPercent(void* p, s32 pct)
{
    *(s32*)((u8*)p + 0x2CC) = pct;
    if (*(s32*)((u8*)p + 0) < 16)
    {
        return -1;
    }
    return Sg2StAdpcmSetPitch(*(u64*)((u8*)p + 0xA0), *(s32*)((u8*)p + 0x30) * pct / 100);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmPlay);
s32 Sg2ExStAdpcmPlay(void* p)
{
    s32 r;

    if (*(s32*)((u8*)p + 0) == 8)
    {
        *(s32*)((u8*)p + 0) = 16;
        r = Sg2StAdpcmPlay(*(u64*)((u8*)p + 0xA0));
        ____VolReflection(p);
        Sg2ExStAdpcmPitchPercent(p, *(s32*)((u8*)p + 0x2CC));
    }
    else
    {
        *(s32*)((u8*)p + 8) |= 4;
    }
    return r;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmPause);
s32 Sg2ExStAdpcmPause(void* p)
{
    s32 st = *(s32*)((u8*)p + 0);

    if (st == 0x80)
    {
        return -1;
    }
    *(s32*)((u8*)p + 4) = st;
    *(s32*)((u8*)p + 0) = 0x80;
    return Sg2StAdpcmSetPitch(*(u64*)((u8*)p + 0xA0), 0);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmCont);
s32 Sg2ExStAdpcmCont(void* p)
{
    *(s32*)((u8*)p + 0) = *(s32*)((u8*)p + 4);
    return Sg2StAdpcmSetPitch(*(u64*)((u8*)p + 0xA0), *(u32*)((u8*)p + 0x30));
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmStop);
s32 Sg2ExStAdpcmStop(void* p)
{
    u64 i;
    u64 id;

    if (D_400F8F7C == 0)
    {
        id = *(u64*)((u8*)p + 0xA0);
        for (i = 0; i < 48; i++)
        {
            if (id & (1LL << (s32)i))
            {
                D_400F8F80[(s32)i] = 1;
            }
        }
    }
    if (*(s32*)((u8*)p + 0) < 16)
    {
        *(s32*)((u8*)p + 0) = 0;
        return -1;
    }
    *(s32*)((u8*)p + 0) = 0;
    return Sg2StAdpcmStop(*(u64*)((u8*)p + 0xA0));
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmIopReadAdr);
s32 Sg2ExStAdpcmIopReadAdr(void* p, s32 n)
{
    u64 i;
    u64 id;

    i = 0;
    id = *(u64*)((u8*)p + 0xA0);
    for (; i < 48; i++)
    {
        if (id & (1LL << (s32)i))
        {
            if (--n < 0)
            {
                return Sg2StAdpcmIopReadAdr(i);
            }
        }
    }
    return 0;
}

/* NEARMISS-STUB Sg2ExStAdpcmSetOutputMode */
#if 0 /* NEARMISS 53.25% cat=volatile-alias sub=- | needs volatile (banned): store to D_400F8F78 differs | attempts=1 */
void Sg2ExStAdpcmSetOutputMode(void* p, s32 mode)
{

    D_400F8F78 = mode;
    if (p)
    {
        ____VolReflection(p);
    }
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmSetOutputMode);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmLoopSecNum);
s32 Sg2ExStAdpcmLoopSecNum(void* p, s32* a, s32* b)
{
    *a = *(s32*)((u8*)p + 0x38);
    *b = *(s32*)((u8*)p + 0x3C);
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmGetBuffer);
s32 Sg2ExStAdpcmGetBuffer(void* p, s32* a, s32* b, s32* c, s32* d)
{
    *a = *(s32*)((u8*)p + 0x230);
    *b = *(s32*)((u8*)p + 0x234);
    *c = *(s32*)((u8*)p + 0x238);
    *d = *(s32*)((u8*)p + 0x23C);
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmSetSignal);
void Sg2ExStAdpcmSetSignal(s32 arg0)
{
    D_400F9040 = (s32 (*)(void*, s32, s32, s32))arg0;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", func_40032420);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", func_400324D0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", func_40032608);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", func_400327D0);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmPreLoad);
s32 Sg2ExStAdpcmPreLoad(void* p)
{
    if (*(s32*)((u8*)p + 0) != 1)
    {
        return -1;
    }
    *(s32*)((u8*)p + 0) = 2;
    if (!(*(s32*)((u8*)p + 8) & 1))
    {
        func_40032420(p, 2, 0, 0);
    }
    func_40032420(p, 1, *(s32*)((u8*)p + 0x230), *(s32*)((u8*)p + 0x234));
    if (*(s32*)((u8*)p + 8) & 0x10)
    {
        func_40032420(p, 0x10, 0, 0);
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmClose);
s32 Sg2ExStAdpcmClose(void* p)
{
    u64 i;
    s32 ret = -1;

    if (*(s32*)((u8*)p + 0) >= 16)
    {
        Sg2ExStAdpcmStop(p);
    }
    *(s32*)((u8*)p + 0) = 0;
    for (i = 0; i < 48; i++)
    {
        if (*(u64*)((u8*)p + 0xA0) & (1LL << i))
        {
            Sg2StAdpcmClose(i);
            ret = 0;
            D_400F8F80[i] = 1;
        }
    }
    if (!(*(s32*)((u8*)p + 0x8) & 2))
    {
        D_400F9040(p, 4, 0, 0);
    }
    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmTickProc);
void Sg2ExStAdpcmTickProc(void* p)
{
    s32 x = *(s32*)((u8*)p + 0x22C);

    func_40032608(p);
    func_400327D0(p);
    if (*(s32*)((u8*)p + 0x22C) != x)
    {
        func_40032608(p);
    }
}

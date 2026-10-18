#include "common.h"

typedef struct
{
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ u64 unk8;
    /* 0x10 */ s32 *unk10;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ u8 pad18[0x4];
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ s16 unk2C;
    /* 0x2E */ s16 unk2E;
    /* 0x30 */ s16 unk30;
    /* 0x32 */ u8 pad32[0x34 - 0x32];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s32 unk40;
    /* 0x44 */ s32 unk44;
    /* 0x48 */ s32 unk48;
    /* 0x4C */ u8 pad4C[0x60 - 0x4C];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 pad64[0x70 - 0x64];
} SndSep;

s32 Sg2VabClose(s32 arg0);
s32 Sg2VabHdOpen(s32 arg0);
s32 Sg2VabBdOpen(s32 arg0, s32 arg1);
s32 Sg2DspSetMasterVolume(s32 core, s32 l, s32 r);
s32 Sg2DspSetMasterVolumeMax();
void Sg2CtrlTickProc(void);
s32 Sg2RemoteSyncStatus();
void Sg2ExPcmTickProc(void);
s32 Sg2SlotTbl();
void Sg2SlotSetOutputMode(s32 arg0);

extern s32 D_40045EA4;
extern s32 D_40045EA8;
extern void *D_400F6D88;
extern void *D_400F6D8C;
extern s32 soundTickProcCnt;
extern s32 D_40045EB0;
extern s32 sg2NicoReverbMode;
extern SndSep D_400F5D50[];
extern s32 D_400F6B50;
extern s32 D_40048F20;

typedef struct SndVabEntry
{
    u32 unk0;
    s32 unk4;
    u8 pad8[8];
    s32 unk10;
    u8 pad14[8];
} SndVabEntry;
extern SndVabEntry D_400F6B58[];

s32 iosCreateSema(s32, s32, s32);
void iosJumpRecoverPoint();

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", func_4002F2A8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepTickProc);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepReq);
SndSep *sndSepReq(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void (*arg4)(SndSep *), s32 arg5, s32 *arg6)
{
    SndSep *ret;
    s32 i;
    s32 cnt;
    u64 flag;

    WaitSema(D_400F6B50);
    ret = NULL;
    for (i = 0; i < 32; i++)
    {
        if (D_400F5D50[i].unk0 == 0)
        {
            goto found;
        }
    }
    goto done;
found:
    ret = &D_400F5D50[i];
    flag = ret->unk8;
    flag &= 0xFFFFFFFEFFFFFFFFULL;
    flag &= 0xFFFFFFE3FFFFFFFFULL;
    flag |= (u64)(arg5 & 7) << 34;
    flag |= 0x2000000000ULL;
    ret->unk34 = arg0;
    ret->unk38 = arg1;
    ret->unk40 = arg2;
    ret->unk44 = arg3;
    ret->unk10 = arg6;
    ret->unk8 = flag;
    ret->unk3C = 0;
    if (arg4 != NULL)
    {
        arg4(ret);
    }
    cnt = soundTickProcCnt;
    ret->unk0 = 1;
    ret->unk60 = cnt;
done:
    SignalSema(D_400F6B50);
    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepPlayerSrh);
SndSep *sndSepPlayerSrh(s32 arg0, s32 arg1, s32 arg2)
{
    s32 i;
    SndSep *ret = 0;
    SndSep *p;

    for (i = 0; i < 32; i++)
    {
        p = &D_400F5D50[i];
        if (p->unk0 != 0 && p->unk14 == arg1 && p->unk16 == arg2 && p->unk10 != 0 && p->unk10[1] == arg0)
        {
            ret = p;
            break;
        }
    }
    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepPlayerSrh2);
SndSep *sndSepPlayerSrh2(s32 arg0, s32 arg1)
{
    s32 i;
    SndSep *p;
    SndSep *ret = 0;

    for (i = 0; i < 32; i++)
    {
        p = &D_400F5D50[i];
        if (p->unk0 == 0)
        {
            continue;
        }
        if (p->unk14 != arg1)
        {
            continue;
        }
        if (p->unk10 == 0)
        {
            continue;
        }
        if (p->unk10[1] != arg0)
        {
            continue;
        }
        ret = p;
        break;
    }
    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepStopReq);
void sndSepStopReq(SndSep *arg0)
{
    arg0->unk8 |= 0x100000000;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepSetVol);
void sndSepSetVol(f32 arg0, SndSep *arg1)
{
    s32 vol = arg0 * 127.0f * arg1->unk1C;

    if (vol > 127)
    {
        vol = 127;
    }
    else if (vol < 0)
    {
        vol = 0;
    }
    arg1->unk28 = vol;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepSetPan);
void sndSepSetPan(f32 arg0, SndSep *arg1)
{
    if (arg0 > 1.0f)
    {
        arg0 = 1.0f;
    }
    else if (arg0 < -1.0f)
    {
        arg0 = -1.0f;
    }
    arg1->unk24 = (s32)(arg0 * 63.0f + 64.0f);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepSetDefaultParam);
void sndSepSetDefaultParam(SndSep *arg0)
{
    s32 neg = -1;

    *(s32 *)&arg0->unk8 = 0xC;
    arg0->unk2A = neg;
    arg0->unk20 = -1.0f;
    arg0->unk30 = 1;
    arg0->unk24 = 64.0f;
    arg0->unk2E = 1;
    arg0->unk2C = 0x1000;
    arg0->unk28 = arg0->unk1C * 127.0f;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepPauseAll);
void sndSepPauseAll(s32 arg0)
{
    if (arg0 != 0)
    {
        D_40045EA4 = 1;
    }
    else
    {
        D_40045EA4 = 0;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepPause);
void sndSepPause(SndSep *arg0)
{
    arg0->unk8 |= 0x200000000;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepCont);
void sndSepCont(SndSep *arg0)
{
    arg0->unk8 &= ~0x200000000;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepStopTypeAll);
void sndSepStopTypeAll(s32 arg0)
{
    s32 i;
    SndSep *p;
    u64 flag = 0x100000000;

    p = D_400F5D50;
    for (i = 31; i >= 0; i--, p++)
    {
        if (p->unk0 != 0 && ((u32)(p->unk8 >> 34) & 7) == arg0)
        {
            p->unk8 |= flag;
        }
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepInitTickParam);
void sndSepInitTickParam(s32 arg0, s32 arg1, s32 arg2)
{
    s32 i;
    s32 *p;
    s32 val;

    if (arg1 != 0x20)
    {
        iosJumpRecoverPoint(&D_40048F20);
    }
    p = (s32 *)D_400F5D50;
    p += 0x48 / 4;
    val = arg0;
    for (i = 31; i >= 0; i--, p += 0x70 / 4, val += arg2)
    {
        *p = val;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepInit);
void sndSepInit(void)
{
    SndSep *p;
    s32 i;
    s32 sema = iosCreateSema(1, 1, 0);
    p = D_400F5D50;
    p += 31;
    D_400F6B50 = sema;
    for (i = 31; i >= 0; i--, p--)
    {
        p->unk0 = 0;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndVabCreate);
void *sndVabCreate(void)
{
    s32 i;
    SndVabEntry *p;

    for (i = 0; i < 20; i++)
    {
        if (!(D_400F6B58[i].unk0 & 1))
        {
            goto found;
        }
    }
    return NULL;
found:
    p = &D_400F6B58[i];
    p->unk0 |= 1;
    D_400F6B58[i].unk4 = -1;
    D_400F6B58[i].unk10 = 0;
    return p;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndVabDelete);
void sndVabDelete(u32 *arg0)
{
    *arg0 &= ~1;
}

void sndVabHDOpen(void *arg0, int arg1, int arg2)
{
    int temp_a1;
    int temp_v0;

    (*(int *)((char *)(arg0) + 8)) = arg2;
    (*(int *)((char *)(arg0) + 0xC)) = arg1;
    temp_v0 = Sg2VabHdOpen(arg1);
    (*(int *)((char *)(arg0) + 4)) = temp_v0;
    if (temp_v0 >= 0) {
        temp_a1 = (*(int *)((char *)(arg0) + 0x10));
        if (temp_a1 != 0) {
            Sg2VabBdOpen(temp_v0, temp_a1);
        }
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndVabHDClose);
s32 sndVabHDClose(s32 *arg0)
{
    return Sg2VabClose(arg0[1]);
}

extern s32 D_40048F60;
s32 Sg2DmaTransVoice(s32 arg0, s32 arg1, s32 arg2);
s32 Sg2DmaTransStatus(s32 arg0);
s32 iosAllocIopHeap(s32 arg0);
void iosFreeIopHeap(s32 arg0);
void iosWaitIdleThread();
void iosEE2IopRequest(s32 arg0, s32 arg1, s32 arg2, s32 *arg3);
s32 iosEE2IopEndChk(s32 arg0);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndBDOpen);
void sndBDOpen(s32 *p, s32 (*cb)(), s32 arg2, s32 size, void (*fn)())
{
    s32 id;
    s32 buf;
    s32 n;
    s32 off = 0;
    s32 st;

    buf = iosAllocIopHeap(size);
    if (buf == 0)
    {
        iosJumpRecoverPoint(&D_40048F60);
    }
    while ((n = cb()) != 0)
    {
        iosEE2IopRequest(arg2, buf, n, &id);
        while (iosEE2IopEndChk(id) == 0)
        {
            if (fn != NULL)
            {
                fn();
            }
        }
        st = Sg2DmaTransVoice(buf, p[4] + off, n);
        while (Sg2DmaTransStatus(st) != 0)
        {
            if (fn == NULL)
            {
                iosWaitIdleThread();
            }
            else
            {
                fn();
            }
        }
        off += n;
    }
    if (p[1] >= 0 && p[4] != 0)
    {
        Sg2VabBdOpen(p[1], p[4]);
    }
    iosFreeIopHeap(buf);
}

void sndBDClose(void) {
}

void sndVabInit(void)
{
    int i;

    for (i = 0; i < 20; i++)
        D_400F6B58[i].unk0 &= ~1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", initSound);
void initSound(void)
{
    D_400F6D88 = NULL;
    sg2NicoReverbMode = 0;
    Sg2CtrlInit(0);
    Sg2RemoteInit(0);
    Sg2ChipInit(0);
    Sg2CtrlSetTickMode(0x3C);
    Sg2ExStAdpcmInit();
    Sg2DspInit(0);
    Sg2ModInit(0);
    Sg2SepInit(0);
    Sg2SmfpInit(0);
    Sg2SlotInit(0);
    Sg2DmaInit(0);
    Sg2VabInit(0);
    Sg2ExPcmInit(0);
    Sg2ChipSetDigitalOutputMode(0x880);
    Sg2DspEffectSetEndAdr(0, 0x1FFFFF);
    Sg2DspEffectSetEndAdr(1, 0x1DFFFF);
    Sg2DspEffectSetType(0, 0x104);
    Sg2DspEffectSetType(1, 0x104);
    Sg2DspEffectSetDepth(0, 0x3C);
    Sg2DspEffectSetDepth(1, 0x3C);
    Sg2DspEffectChange(0);
    Sg2DspEffectChange(1);
    Sg2DspSetMasterVolumeMax();
    sndVabInit();
    sndSepInit();
    Sg2SlotSetOutputMode(D_40045EA8);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", tickProcSound);
void tickProcSound(s32 arg0)
{
    if (D_40045EB0 != arg0)
    {
        if (arg0 != 0) { Sg2DspSetMasterVolume(0, 0, 0); Sg2DspSetMasterVolume(1, 0, 0); }
        else { Sg2DspSetMasterVolumeMax(); }
    }
    if (arg0 == 0 || D_40045EB0 == 0)
    {
        if (Sg2RemoteSyncStatus() == 0) { Sg2CtrlTickProc(); }
        soundTickProcCnt++;
        Sg2ExPcmTickProc();
        if (D_400F6D8C != 0) { ((void (*)(void))D_400F6D8C)(); }
        if (D_400F6D88 != 0) { ((void (*)(void))D_400F6D88)(); }
    }
    D_40045EB0 = arg0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", addAdpcmTickProcFunc);
void addAdpcmTickProcFunc(void *arg0)
{
    D_400F6D88 = arg0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", setPcmTickProcFunc);
void setPcmTickProcFunc(void *arg0)
{
    D_400F6D8C = arg0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", soundGetTickProcCnt);
s32 soundGetTickProcCnt(void)
{
    return soundTickProcCnt;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", soundSetRevMode);
void soundSetRevMode(s32 arg0, s32 arg1)
{
    if (arg0 == 0)
    {
        sg2NicoReverbMode |= arg1;
    }
    else
    {
        sg2NicoReverbMode &= ~arg1;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", soundGetRevMode);
s32 soundGetRevMode(void)
{
    return sg2NicoReverbMode;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", getSlotInfo);
s32 getSlotInfo()
{
    return Sg2SlotTbl();
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", setSoundMode);
void setSoundMode(s32 arg0)
{
    D_40045EA8 = arg0 ? 1 : 2;
    Sg2SlotSetOutputMode(D_40045EA8);
}

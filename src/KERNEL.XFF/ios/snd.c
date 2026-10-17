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
    /* 0x32 */ u8 pad32[0x48 - 0x32];
    /* 0x48 */ s32 unk48;
    /* 0x4C */ u8 pad4C[0x70 - 0x4C];
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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndSepReq);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndVabHDOpen);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndVabHDClose);
s32 sndVabHDClose(s32 *arg0)
{
    return Sg2VabClose(arg0[1]);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndBDOpen);

void sndBDClose(void) {
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", sndVabInit);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/snd", initSound);

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

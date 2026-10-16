#include "common.h"

extern s32 D_400F8F7C;
extern s32 D_400F9040;
extern s32 Sg2StAdpcmQuit(void);
extern s32 Sg2StAdpcmSetPitch(u64, u32);
extern s32 Sg2ExStAdpcmSlotFree(void);
extern s32 D_400F8F78;
extern s32 D_400F8F80[48];
extern s32 Sg2StAdpcmInit(s32);
extern s32 Sg2StAdpcmPlay(u64);
extern s32 Sg2StAdpcmStop(u64);
extern s32 Sg2StAdpcmIopReadAdr(void);
extern s32 Sg2SlotFree(s32);
extern void* memset(void*, s32, u32);
extern void ____VolReflection(void*);
extern s32 func_40031728(void*);
extern void func_40032608(void*);
extern void func_400327D0(void*);
extern s32 Sg2ExStAdpcmSlotReserv(s32, s32);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmSlotReserv);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmOpen);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", func_40031C08);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmVolumePercent);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmTrkVolumeDirect);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmTrkVolumePercent);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmTrkDspSw);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", ____VolReflection);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmIopReadAdr);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmSetOutputMode);
void Sg2ExStAdpcmSetOutputMode(void* p, s32 mode)
{

    *(volatile s32*)&D_400F8F78 = mode;
    if (p)
    {
        ____VolReflection(p);
    }
}

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
    D_400F9040 = arg0;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", func_40032420);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", func_400324D0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", func_40032608);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", func_400327D0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmPreLoad);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmClose);

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

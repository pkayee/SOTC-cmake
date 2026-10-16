#include "common.h"

extern s32 D_400F8F7C;
extern s32 D_400F9040;
extern s32 Sg2StAdpcmQuit(void);
extern s32 Sg2StAdpcmSetPitch(u64, u32);
extern void Sg2ExStAdpcmSlotFree(void);
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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmSlotFree);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmWorkClear);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", func_40031728);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmOpenFake);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", ____VolPerBackup);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmPitchPercent);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmPlay);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmPause);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmCont);
s32 Sg2ExStAdpcmCont(void* p)
{
    *(s32*)((u8*)p + 0) = *(s32*)((u8*)p + 4);
    return Sg2StAdpcmSetPitch(*(u64*)((u8*)p + 0xA0), *(u32*)((u8*)p + 0x30));
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmStop);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmIopReadAdr);

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
    D_400F9040 = arg0;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", func_40032420);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", func_400324D0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", func_40032608);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", func_400327D0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmPreLoad);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmClose);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/ex/st_adpcm", Sg2ExStAdpcmTickProc);

#include "common.h"

typedef struct DlState
{
    s32 endAdrs[2]; // 0x0
    s32 createAdrs[2]; // 0x8
    s32 packetPtrPath1; // 0x10
    s32 layerNum;  // 0x14
    s32 workBufId; // 0x18
    s32 layer;     // 0x1C
    s32 lockLink[2]; // 0x20
    s32 lockCount[2]; // 0x28
} DlState;

extern DlState D_40092698;
extern s32 D_40092690;
extern s32 D_40045A1C;
extern s32 D_40045A10;
extern s32 D_40045A14;
extern char D_400475C0[];
extern char D_400475D8[];
extern s32 D_40045A20;
extern s32 D_400926C8[];

s32 LoaderSysPrintf(const char *format, ...);
void iosFree(s32);

s32 iosCreateSema(s32, s32, s32);
s32 SignalSema(s32);
s32 WaitSema(s32);
void iosDmaSendSChainPath1(s32);
void isysObjDeleteLock(s32);
s32 isysAddGroupWithLinkParamNoWait(s32, volatile s32 *, s32, s32);
void func_40024FB0(void);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", func_40024B90);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlPopLayer);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", func_40024FB0);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosUsedPacketBufferSize);
f32 iosUsedPacketBufferSize(void)
{
    volatile DlState *dl = &D_40092698;
    u32 used = dl->packetPtrPath1 - dl->endAdrs[dl->workBufId];

    return used / (f32)(D_40045A1C << 4);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosCreateIVArbitrationSema);
void iosCreateIVArbitrationSema(void)
{
    s32 sema = iosCreateSema(0, 1, 0);
    volatile s32 *dst = &D_40092690;

    *dst = sema;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlGetTransAdrs);
s32 iosDlGetTransAdrs(void)
{
    volatile DlState *dl = &D_40092698;

    return dl->createAdrs[dl->workBufId];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosGetPacketPtrPath1);
s32 iosGetPacketPtrPath1(void)
{
    volatile DlState *dl = &D_40092698;

    if (dl->packetPtrPath1 & 0xF)
    {
        dl->packetPtrPath1 = dl->packetPtrPath1 - (dl->packetPtrPath1 & 0xF) + 0x10;
    }
    __asm__ volatile("pref 0x00, 0x40(%0)" : : "r"(dl->packetPtrPath1));

    return ((volatile DlState *)&D_40092698)->packetPtrPath1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosSetPacketPtrPath1);
void iosSetPacketPtrPath1(s32 arg0)
{
    volatile DlState *dl = &D_40092698;

    dl->packetPtrPath1 = arg0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosAllocPacketPtrPath1);
s32 iosAllocPacketPtrPath1(s32 arg0)
{
    volatile DlState *dl = &D_40092698;
    s32 ret = dl->packetPtrPath1;

    dl->packetPtrPath1 = dl->packetPtrPath1 + arg0;
    __asm__ volatile("pref 0x00, 0x40(%0)" : : "r"(ret));

    return ret;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlChainHead);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlChainTail);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlChainHeadCurrent);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlChainTailCurrent);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlSwap);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlTrans);
void iosDlTrans(void)
{
    volatile DlState *dl;
    volatile s32 *sema = &D_40092690;

    WaitSema(*sema);
    dl = &D_40092698;
    iosDmaSendSChainPath1(dl->createAdrs[!dl->workBufId]);
    D_40045A14++;
    SignalSema(*sema);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlLockObj);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlGetWorkBufId);
s32 iosDlGetWorkBufId(void)
{
    volatile DlState *dl = &D_40092698;

    return dl->workBufId;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlGetTransBufId);
s32 iosDlGetTransBufId(void)
{
    volatile DlState *dl = &D_40092698;

    return dl->workBufId == 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlGetEndAdrs);
s32 iosDlGetEndAdrs(void)
{
    volatile DlState *dl = &D_40092698;

    return dl->endAdrs[dl->workBufId] + (D_40045A1C << 4) - 0x1000;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlGetLayer);
s32 iosDlGetLayer(void)
{
    volatile DlState *dl = &D_40092698;

    return dl->layer;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlSetLayer);
void iosDlSetLayer(s32 arg0)
{
    s32 layer = arg0;

    if (layer < 0)
    {
        LoaderSysPrintf(D_400475C0);
    }
    else if (layer >= ((volatile DlState *)&D_40092698)->layerNum)
    {
        layer = ((volatile DlState *)&D_40092698)->layerNum - 1;
    }
    ((volatile DlState *)&D_40092698)->layer = layer;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlPushLayer);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlGetLayerNum);
s32 iosDlGetLayerNum(void)
{
    volatile DlState *dl = &D_40092698;

    return dl->layerNum;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlRelease);
void iosDlRelease(void)
{
    volatile DlState *dl = &D_40092698;
    s32 i;

    for (i = 0; i < 2; i++)
    {
        volatile s32 *createAdrs = dl->createAdrs;
        volatile s32 *endAdrs = dl->endAdrs;

        if (createAdrs[i] != 0)
        {
            iosFree(createAdrs[i]);
        }
        if (endAdrs[i] != 0)
        {
            iosFree(endAdrs[i]);
        }
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", InitDL);
void InitDL(void)
{
    volatile s32 *sema;
    volatile s32 *dst;

    func_40024FB0();
    sema = &D_40092690;
    SignalSema(*sema);
    dst = &D_40045A10;
    *dst = 1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlCheckAdrs);
s32 iosDlCheckAdrs(s32 arg0)
{
    volatile DlState *dl = &D_40092698;
    u32 end = dl->endAdrs[dl->workBufId] + (D_40045A1C << 4) - 0x1000;

    return (u32)arg0 < end;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlCheckSize);
s32 iosDlCheckSize(void)
{
    volatile DlState *dl = &D_40092698;
    s32 end = dl->endAdrs[dl->workBufId] + (D_40045A1C << 4) - 0x1000;

    if (dl->packetPtrPath1 & 0xF)
    {
        dl->packetPtrPath1 = dl->packetPtrPath1 - (dl->packetPtrPath1 & 0xF) + 0x10;
    }
    __asm__ volatile("pref 0x00, 0x40(%0)" : : "r"(dl->packetPtrPath1));

    return end - ((volatile DlState *)&D_40092698)->packetPtrPath1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlGetCreateAdrs);
s32 iosDlGetCreateAdrs(void)
{
    volatile DlState *dl = &D_40092698;

    return dl->createAdrs[dl->workBufId == 0 ? 1 : 0];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosAllocPacketPtrPath1UnCachedA);
s32 iosAllocPacketPtrPath1UnCachedA(s32 arg0)
{
    volatile DlState *dl = &D_40092698;
    s32 ret = dl->packetPtrPath1 | 0x30000000;

    dl->packetPtrPath1 += arg0;

    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlTransNow);
void iosDlTransNow(void)
{
    volatile DlState *dl;
    volatile s32 *sema = &D_40092690;

    WaitSema(*sema);
    dl = &D_40092698;
    iosDmaSendSChainPath1(dl->createAdrs[!dl->workBufId]);
    SignalSema(*sema);
}

#include "common.h"

typedef struct DlState
{
    u8 unk0[0x8];
    s32 createAdrs[2]; // 0x8
    s32 packetPtrPath1; // 0x10
    s32 layerNum;  // 0x14
    s32 workBufId; // 0x18
    s32 layer;     // 0x1C
} DlState;

extern DlState D_40092698;

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", func_40024B90);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlPopLayer);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", func_40024FB0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosUsedPacketBufferSize);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosCreateIVArbitrationSema);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlGetTransAdrs);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosGetPacketPtrPath1);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlTrans);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlGetEndAdrs);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlGetLayer);
s32 iosDlGetLayer(void)
{
    volatile DlState *dl = &D_40092698;

    return dl->layer;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlSetLayer);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlPushLayer);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlGetLayerNum);
s32 iosDlGetLayerNum(void)
{
    volatile DlState *dl = &D_40092698;

    return dl->layerNum;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlRelease);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", InitDL);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlCheckAdrs);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlCheckSize);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dl", iosDlTransNow);

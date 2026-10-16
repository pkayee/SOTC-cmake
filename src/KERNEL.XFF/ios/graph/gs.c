#include "common.h"

extern s32 D_40092BD0;
extern s32 D_40092BD4;
extern s32 D_40092BD8;
extern s32 D_40092BDC;
extern s32 D_40092C70;
extern s32 D_40092C74;
extern s32 D_40092C7C;
extern s32 D_40092C80;
extern s32 D_40045A90;

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDumpDMAStatus);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDumpVIF1Status);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDumpGIFStatus);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosSyncPath);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", func_400268A8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", func_40026BE0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosGsResizeRootDC);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosGsSetMode);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosGsSetDrawContext);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosCopyFrameBuffer);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getDispScreenWidth);
s32 getDispScreenWidth(void)
{
    return D_40092BD0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getDispScreenHeight);
s32 getDispScreenHeight(void)
{
    return D_40092BD4;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getDrawScreenWidth);
s32 getDrawScreenWidth(void)
{
    return D_40092BD8;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getDrawScreenHeight);
s32 getDrawScreenHeight(void)
{
    return D_40092BDC;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getFrameBufferSize);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getFrameBufferSizeFBP);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getFrameBufferSizeTBP);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getDispBufferAddressTBP);
s32 getDispBufferAddressTBP(void)
{
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getDispBufferAddressFBP);
s32 getDispBufferAddressFBP(void)
{
    return 0;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getDrawBufferAddressTBP);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getDrawBufferAddressFBP);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getZBufferAddressTBP);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getZBufferAddressFBP);
s32 getZBufferAddressFBP(void)
{
    s32 *p = (s32 *)&D_40092BD0;

    return (p[0] * p[1]) >> 11;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getTextureAreaAddressTBP);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getTextureAreaAddressFBP);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getScreenOffsetX);
s32 *getScreenOffsetX(void)
{
    return &D_40092C7C;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getScreenOffsetY);
s32 *getScreenOffsetY(void)
{
    return &D_40092C80;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getAntiAlias);
s32 *getAntiAlias(void)
{
    return &D_40092C70;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getProgressiveMode);
s32 *getProgressiveMode(void)
{
    return &D_40092C74;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosResetGraph);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDmaSendPath1);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDmaSendPath2);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDmaSendPath3);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDmaSendSChainPath1);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDmaSendSChainPath2);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDmaSendSChainPath3);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosResetPath);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosSyncV);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosGetField);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosGsChangeMode);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosSetBGColor);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosGsResetCRTC);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosSetSyncNoReturnFunc);
s32 iosSetSyncNoReturnFunc(s32 func)
{
    D_40045A90 = func;
    return 1;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosSetScreenEnv);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosCheckDrawFinish);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosGsInitDC);

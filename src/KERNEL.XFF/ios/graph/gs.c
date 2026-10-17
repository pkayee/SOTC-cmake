#include "common.h"
#include "sdk/ee/eekernel.h"
#include "sdk/ee/eeregs.h"

extern s32 D_40092BD0;
extern s32 D_40092BD4;
extern s32 D_40092BD8;
extern s32 D_40092BDC;
extern s32 D_40092C70;
extern s32 D_40092C74;
extern s32 D_40092C7C;
extern s32 D_40092C80;
extern s32 D_40045A90;
extern s32 D_40045A50, D_40045A54, D_40045A58;
extern u_long128 D_40045A70[2];
extern u8 *D_40092C58;
void waitVscheduler(void);
void func_400268A8(void);
s32 iosDlGetWorkBufId(void);
void iosResetDC(void *dc);
void iosSetDCParam(void *dc, s32 a, s32 b, s32 c, s32 d);
void iosSetDCViewPort(void *dc, s32 x, s32 y, s32 w, s32 h);
void sceGsResetGraph(short mode, short inter, short omode, short ffmode);
void iosDumpDMAStatus(s32);
void iosDumpVIF1Status(void);
void iosDumpGIFStatus(void);
void func_40026BE0(s32 field);
extern s32 D_40045A5C;
extern char D_40048060[], D_40048098[], D_400480D0[], D_40048100[], D_40048130[];

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDumpDMAStatus);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDumpVIF1Status);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDumpGIFStatus);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosSyncPath);
s32 iosSyncPath(s32 mode, s32 timeout)
{
    u32 stat;
    s32 count;
    s32 limit;
    s32 r, r2, r3, r4, r5;

    limit = 0x2000000;
    timeout &= 0xFFFF;
    if (timeout)
        limit = timeout;
    count = 0;
    if (mode != 0)
    {
        asm volatile("cfc2.ni %0, $vi29" : "=r"(stat));
        r = ((s32)*D1_CHCR >> 8) & 1;
        r2 = (*D2_CHCR & 0x100) ? (r | 2) : r;
        r3 = (*VIF1_STAT & 0x1F000003) ? (r2 | 4) : r2;
        r4 = (stat & 0x100) ? (r3 | 8) : r3;
        r5 = (*GIF_STAT & 0xC00) ? (r4 | 0x10) : r4;
        return r5;
    }
    while (*D1_CHCR & 0x100)
    {
        count++;
        if (limit < count)
        {
            iosDumpDMAStatus(0);
            iosDumpVIF1Status();
            iosDumpGIFStatus();
            LoaderSysPrintf(D_40048060);
            ((void (*)(u32))D_40045A90)(*VIF1_MARK);
            return -1;
        }
    }
    while (*D2_CHCR & 0x100)
    {
        count++;
        if (limit < count)
        {
            iosDumpDMAStatus(1);
            LoaderSysPrintf(D_40048098);
            return -1;
        }
    }
    while (*VIF1_STAT & 0x1F000003)
    {
        count++;
        if (limit < count)
        {
            iosDumpDMAStatus(0);
            iosDumpVIF1Status();
            iosDumpGIFStatus();
            LoaderSysPrintf(D_400480D0);
            ((void (*)(u32))D_40045A90)(*VIF1_MARK);
            return -1;
        }
    }
    asm volatile("cfc2.ni %0, $vi29" : "=r"(stat));
    while (stat & 0x100)
    {
        count++;
        if (limit < count)
        {
            iosDumpDMAStatus(0);
            iosDumpVIF1Status();
            LoaderSysPrintf(D_40048100);
            ((void (*)(u32))D_40045A90)(*VIF1_MARK);
            return -1;
        }
        asm volatile("cfc2.ni %0, $vi29" : "=r"(stat));
    }
    while (*GIF_STAT & 0xC00)
    {
        count++;
        if (limit < count)
        {
            iosDumpDMAStatus(0);
            iosDumpDMAStatus(1);
            iosDumpVIF1Status();
            iosDumpGIFStatus();
            LoaderSysPrintf(D_40048130);
            ((void (*)(u32))D_40045A90)(*VIF1_MARK);
            return -1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", func_400268A8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", func_40026BE0);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosGsResizeRootDC);
void iosGsResizeRootDC(void)
{
    s32 *p = (s32 *)&D_40092BD0;
    s32 i = 1;
    s32 off = 0;

    do
    {
        iosSetDCParam((u8 *)p[0x22] + off, ((p[0] * p[1]) >> 11) + ((p[2] * p[3]) >> 11), (p[0] * p[1]) >> 11, p[2], p[3]);
        iosSetDCViewPort((u8 *)p[0x22] + off, 0, 0, p[2], p[3]);
        off += 0x190;
    } while (--i >= 0);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosGsSetMode);
void iosGsSetMode(void)
{
    s32 *p = (s32 *)&D_40092BD0;

    if (p[0xA4 / 4] != 0)
    {
        p[0xA0 / 4] = 0;
        p[2] = 0x200;
        p[0] = 0x200;
        p[3] = 0x1C0;
        p[1] = 0x1C0;
        D_40045A50 = 0;
        D_40045A54 = 0x50;
        D_40045A58 = 1;
    }
    else
    {
        p[0xA0 / 4] = 1;
        p[2] = 0x200;
        p[3] = 0x1C0;
        p[0] = 0x200;
        p[1] = 0x1C0;
        D_40045A50 = 1;
        D_40045A54 = 2;
        D_40045A58 = 0;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosGsSetDrawContext);
void iosGsSetDrawContext(void)
{
    u32 stat;
    u8 *dc;
    s64 qwc;
    s64 addr;

    do
    {
        asm volatile("cfc2.ni %0, $vi29" : "=r"(stat));
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    func_40026BE0((*(volatile u64 *)0x12001000 >> 13) & 1);
    dc = D_40092C58;
    if (iosDlGetWorkBufId() == 0)
        dc += 0x190;
    dc += 0x10;
    qwc = (s32)(*(u64 *)dc & 0x7FFF) + 1;
    addr = (u32)dc;
    do
    {
        asm volatile("cfc2.ni %0, $vi29" : "=r"(stat));
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    *D2_QWC = qwc;
    *D2_MADR = addr & 0x0FFFFFFF;
    FlushCache(0);
    *D2_CHCR = 0x141;
}

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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getFrameBufferSize);
s32 getFrameBufferSize(void)
{
    s32 *p = (s32 *)&D_40092BD0;

    return (p[0] * p[1]) + (p[2] * p[3]) * 2;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getFrameBufferSizeFBP);
s32 getFrameBufferSizeFBP(void)
{
    s32 *p = (s32 *)&D_40092BD0;

    return ((p[0] * p[1]) + (p[2] * p[3]) * 2) >> 11;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getFrameBufferSizeTBP);
s32 getFrameBufferSizeTBP(void)
{
    s32 *p = (s32 *)&D_40092BD0;

    return ((p[0] * p[1]) + (p[2] * p[3]) * 2) >> 6;
}

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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getDrawBufferAddressTBP);
s32 getDrawBufferAddressTBP(void)
{
    s32 *p = (s32 *)&D_40092BD0;

    return ((p[0] * p[1]) >> 6) + ((p[2] * p[3]) >> 6);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getDrawBufferAddressFBP);
s32 getDrawBufferAddressFBP(void)
{
    s32 *p = (s32 *)&D_40092BD0;

    return ((p[0] * p[1]) >> 11) + ((p[2] * p[3]) >> 11);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getZBufferAddressTBP);
s32 getZBufferAddressTBP(void)
{
    s32 *p = (s32 *)&D_40092BD0;

    return (p[0] * p[1]) >> 6;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getZBufferAddressFBP);
s32 getZBufferAddressFBP(void)
{
    s32 *p = (s32 *)&D_40092BD0;

    return (p[0] * p[1]) >> 11;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getTextureAreaAddressTBP);
s32 getTextureAreaAddressTBP(void)
{
    s32 *p = (s32 *)&D_40092BD0;
    s32 t = (p[0] * p[1]) >> 6;
    s32 u = (p[2] * p[3]) >> 6;

    return t + u + u;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", getTextureAreaAddressFBP);
s32 getTextureAreaAddressFBP(void)
{
    s32 *p = (s32 *)&D_40092BD0;
    s32 t = (p[0] * p[1]) >> 11;
    s32 u = (p[2] * p[3]) >> 11;

    return t + u + u;
}

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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosResetGraph);
void iosResetGraph(s16 arg0, s16 arg1, s16 arg2, s16 arg3)
{
    if (arg0 != 0)
    {
        *GS_CSR = 0x100;
        return;
    }
    *GS_CSR = 0x200;
    sceGsResetGraph(0, arg1 & 1, arg2, arg3 & 1);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDmaSendPath1);
void iosDmaSendPath1(s64 arg0, s64 arg1)
{
    u32 stat;

    do
    {
        asm volatile("cfc2.ni %0, $vi29" : "=r"(stat));
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    *D1_QWC = arg1;
    *D1_MADR = arg0 & 0x0FFFFFFF;
    FlushCache(0);
    *D1_CHCR = 0x101;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDmaSendPath2);
void iosDmaSendPath2(s64 arg0, s64 arg1)
{
    u32 stat;

    do
    {
        asm volatile("cfc2.ni %0, $vi29" : "=r"(stat));
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    *D1_QWC = arg1;
    *D1_MADR = arg0 & 0x0FFFFFFF;
    FlushCache(0);
    *D1_CHCR = 0x101;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDmaSendPath3);
void iosDmaSendPath3(s64 arg0, s64 arg1)
{
    u32 stat;

    do
    {
        asm volatile("cfc2.ni %0, $vi29" : "=r"(stat));
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    *D2_QWC = arg1;
    *D2_MADR = arg0 & 0x0FFFFFFF;
    FlushCache(0);
    *D2_CHCR = 0x141;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDmaSendSChainPath1);
void iosDmaSendSChainPath1(u32 arg0)
{
    u32 stat;

    do
    {
        asm volatile("cfc2.ni %0, $vi29" : "=r"(stat));
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    *D1_QWC = 0;
    *D1_TADR = arg0 & 0x7FFFFFFF;
    FlushCache(0);
    *D1_CHCR = 0x145;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDmaSendSChainPath2);
void iosDmaSendSChainPath2(u32 arg0)
{
    u32 stat;

    do
    {
        asm volatile("cfc2.ni %0, $vi29" : "=r"(stat));
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    *D1_QWC = 0;
    *D1_TADR = arg0 & 0x7FFFFFFF;
    FlushCache(0);
    *D1_CHCR = 0x145;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDmaSendSChainPath3);
void iosDmaSendSChainPath3(u32 arg0)
{
    u32 stat;

    do
    {
        asm volatile("cfc2.ni %0, $vi29" : "=r"(stat));
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    *D2_QWC = 0;
    *D2_TADR = arg0 & 0x7FFFFFFF;
    FlushCache(0);
    *D2_CHCR = 0x105;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosResetPath);
void iosResetPath(void)
{
    register s32 tmp asm("v1") = 0;
    *VIF1_FBRST = 1;
    asm volatile("cfc2.ni %0, $vi28" : "+r"(tmp));
    tmp |= 0x200;
    asm volatile("ctc2.ni %0, $vi28; sync.p" : : "r"(tmp));
    *VIF1_FIFO = D_40045A70[0];
    *VIF1_FIFO = D_40045A70[1];
    *GIF_CTRL = 1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosSyncV);
s32 iosSyncV(s32 arg0)
{
    s32 i;

    for (i = 0; i < arg0 + 1; i++)
    {
        waitVscheduler();
    }
    return (*GS_CSR >> 13) & 1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosGetField);
s32 iosGetField(void)
{
    return (*(volatile u64 *)0x12001000 >> 13) & 1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosGsChangeMode);
void iosGsChangeMode(void)
{
    s16 a = D_40045A50;
    s16 b = D_40045A54;
    s16 c = D_40045A58;

    *GS_CSR = 0x200;
    sceGsResetGraph(0, a & 1, b, c & 1);
    func_400268A8();
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosSetBGColor);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosGsResetCRTC);
void func_40026BE0(s32 field);
void iosGsResetCRTC(void)
{
    u32 stat;

    do
    {
        asm volatile("cfc2.ni %0, $vi29" : "=r"(stat));
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    func_40026BE0((*(volatile u64 *)0x12001000 >> 13) & 1);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosSetSyncNoReturnFunc);
s32 iosSetSyncNoReturnFunc(s32 func)
{
    D_40045A90 = func;
    return 1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosSetScreenEnv);
void iosSetScreenEnv(s32 w, s32 h, s32 dw, s32 dh)
{
    s16 a = D_40045A50;
    s16 b = D_40045A54;
    s16 c = D_40045A58;
    s32 *p = (s32 *)&D_40092BD0;
    u32 stat;

    p[2] = dw;
    p[3] = dh;
    p[0] = w;
    p[1] = h;
    p[0xAC / 4] = 0;
    p[0xB0 / 4] = 0;
    *GS_CSR = 0x200;
    sceGsResetGraph(0, a & 1, b, c & 1);
    func_400268A8();
    waitVscheduler();
    *GS_CSR;
    do
    {
        asm volatile("cfc2.ni %0, $vi29" : "=r"(stat));
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    func_40026BE0((*(volatile u64 *)0x12001000 >> 13) & 1);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosCheckDrawFinish);
s32 iosCheckDrawFinish(void)
{
    u32 stat;

    D_40045A5C++;
    asm volatile("cfc2.ni %0, $vi29" : "=r"(stat));
    if ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00))
        return 0;
    return 1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosGsInitDC);
void iosGsInitDC(void)
{
    iosResetDC(D_40092C58 + iosDlGetWorkBufId() * 0x190);
}

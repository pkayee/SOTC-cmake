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

/* NEARMISS-STUB iosDumpVIF1Status */
#if 0 /* NEARMISS 98.47% cat=regalloc sub=- | rodata lui/addiu reg choice; stat in s1 vs s0 | attempts=1 */
/* kR39 iosDumpVIF1Status: 98.470% (was 93.405). cause=regalloc/other: .rodata lui/addiu register choice for string literals remains; stat is in s1 vs target s0. Fix that worked: ForceBreak flag index as (stat & 0x80) != 0 (breaks CSE with BUFFER id). Worse: (stat&4)!=0 and (stat&0x10)!=0 (93.18%); (int) cast on BUFFER (93.41%). */
/* iosDumpVIF1Status: 93.405% (kR27). Residual: register allocation (stat in s1 in ours, s0 in target; vu1run ptr s0 vs s1) and CSE of (stat>>7)&1 for BUFFER id and ForceBreak (target recomputes). Function-scope tables: 79.9%, fqc-first decl: no change. */
//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDumpVIF1Status);
void iosDumpVIF1Status(void)
{
    u32 stat;
    u32 fqc;

    LoaderSysPrintf("\n------------------------------------------------ VIF1\n");
    stat = *VIF1_STAT;
    {
        char *flag[2] = {"OFF", "ON"};
        char *status[4] = {"IDLE", "RUNNING", "WAIT", "ERROR"};
        char *vu1run[2] = {"NO", "YES"};
        char *gifwait[2] = {"NO", "YES"};
        char *dir[2] = {"NO", "YES"};

        LoaderSysPrintf("VIF1Status     : %s\n", status[stat & 3]);
        LoaderSysPrintf("VU1Running?    : %s\n", vu1run[(stat >> 2) & 1]);
        LoaderSysPrintf("GIFTransWait   : %s\n", gifwait[(stat >> 3) & 1]);
        LoaderSysPrintf("MARKdetected   : %s\n", flag[(stat >> 4) & 1]);
        LoaderSysPrintf("BUFFER id      : %d\n", (stat >> 7) & 1);
        LoaderSysPrintf("STOP           : %s\n", flag[(stat >> 6) & 1]);
        LoaderSysPrintf("ForceBreak     : %s\n", flag[(stat & 0x80) != 0]);
        LoaderSysPrintf("VIF1Stall      : %s\n", flag[(stat >> 8) & 1]);
        LoaderSysPrintf("ibitIntr       : %s\n", flag[(stat >> 9) & 1]);
        LoaderSysPrintf("DMATagError    : %s\n", flag[(stat >> 10) & 1]);
        LoaderSysPrintf("VifCodeError   : %s\n", flag[(stat >> 11) & 1]);
        LoaderSysPrintf("TrsDirection   : %s\n", dir[(stat >> 21) & 1]);
    }
    fqc = (stat >> 24) & 0x1F;
    LoaderSysPrintf("DataCount(QW)  : %d(0x%x)\n", fqc, fqc);
    LoaderSysPrintf("-------------------------\n");
    LoaderSysPrintf(" MARK:\x1b[32m0x%08x\x1b[0m\n", *(volatile u32 *)0x10003C30);
    LoaderSysPrintf(" Row0:\x1b[32m0x%08x\x1b[0m   Row1:\x1b[32m0x%08x\x1b[0m   Row2:\x1b[32m0x%08x\x1b[0m   Row3:\x1b[32m0x%08x\x1b[0m\n",
        *(volatile u32 *)0x10003D00, *(volatile u32 *)0x10003D10, *(volatile u32 *)0x10003D20, *(volatile u32 *)0x10003D30);
    LoaderSysPrintf(" Col0:\x1b[32m0x%08x\x1b[0m   Col1:\x1b[32m0x%08x\x1b[0m   Col2:\x1b[32m0x%08x\x1b[0m   Col3:\x1b[32m0x%08x\x1b[0m\n",
        *(volatile u32 *)0x10003D40, *(volatile u32 *)0x10003D50, *(volatile u32 *)0x10003D60, *(volatile u32 *)0x10003D70);
    LoaderSysPrintf("CYCLE:\x1b[32m0x%08x\x1b[0m   MASK:\x1b[32m0x%08x\x1b[0m   MODE:\x1b[32m0x%08x\x1b[0m\n",
        *(volatile u32 *)0x10003C40, *(volatile u32 *)0x10003C70, *(volatile u32 *)0x10003C50);
    LoaderSysPrintf(" ITOP:\x1b[32m0x%08x\x1b[0m  ITOPS:\x1b[32m0x%08x\x1b[0m   BASE:\x1b[32m0x%08x\x1b[0m   OFST:\x1b[32m0x%08x\x1b[0m\n",
        *(volatile u32 *)0x10003CD0, *(volatile u32 *)0x10003C90, *(volatile u32 *)0x10003CA0, *(volatile u32 *)0x10003CB0);
    LoaderSysPrintf("  TOP:\x1b[32m0x%08x\x1b[0m   TOPS:\x1b[32m0x%08x\x1b[0m    NUM:\x1b[32m0x%08x\x1b[0m   CODE:\x1b[32m0x%08x\x1b[0m\n",
        *(volatile u32 *)0x10003CE0, *(volatile u32 *)0x10003CC0, *(volatile u32 *)0x10003C60, *(volatile u32 *)0x10003C80);
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDumpVIF1Status);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDumpGIFStatus);

/* NEARMISS-STUB iosSyncPath */
#if 0 /* NEARMISS 89.0% cat=vu0-mmi sub=- | cfc2.ni vi29 (VU0 COP2 control read) has no C form; asm-free probe read version | attempts=1 */
/* kR39 asm-free probe: 89.01% (cfc2.ni $vi29 read replaced by volatile probe; no C form for COP2 cfc2) cause=no-c-form */
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
        stat = *(volatile u32 *)0x1000F000;
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
    stat = *(volatile u32 *)0x1000F000;
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
        stat = *(volatile u32 *)0x1000F000;
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
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosSyncPath);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", func_400268A8);

/* NEARMISS-STUB func_40026BE0 */
#if 0 /* NEARMISS 85.67% cat=regalloc sub=- | -2/-0x21 masks hoisted to a3/t0 in target; v0/v1/a0 swapped | attempts=1 */
/* kR39 func_40026BE0: 85.672% best (kR32 C). cause=regalloc: constants -2/-0x21 hoisted into a3/t0 in target, ours a7/t4; target uses a2/v0/v1 naming. Variants tried: aa masked at load (85.67%, same), pointer reuse p (80.37%). */
/* KERNEL.XFF/ios/graph/gs func_40026BE0 — best so far 85.67% (SCORE KERNEL.XFF/ios/graph/gs/func_40026BE0 85.67164%)
 * Drop-in for src/KERNEL.XFF/ios/graph/gs.c in place of the INCLUDE_ASM line. No extra typedefs needed.
 * Shape: base = &D_40092BD0 (GsEnv); field at +0x8C, aa at +0xA0; disp[f] stride 0x38 starting at +0x18.
 * Remaining diff is register naming only (target: field->v0, aa->a2, pointer->v1; ours swaps v0/v1/a0).
 * Tried: struct GsDisp view (44.9%), disp base at +0x18 (54.3%), re-reads of field/aa after each RMW store
 * (80.4%, needed: the s32 stores may alias env), (off = f*0x38 + 0x10) association (85.7%).
 */
void func_40026BE0(s32 field)
{
    s32 *env = (s32 *)&D_40092BD0;
    s32 aa = env[0xA0 / 4];
    s32 off;
    s32 *lo;
    u8 *x;

    off = (env[0x8C / 4] & 1) * 0x38 + 0x10;
    lo = (s32 *)((u8 *)env + off);
    lo[2] = (lo[2] & ~1) | (aa & 1);
    off = (env[0x8C / 4] & 1) * 0x38 + 0x10;
    lo = (s32 *)((u8 *)env + off);
    lo[2] = (lo[2] & ~0x20) | ((env[0xA0 / 4] & 1) << 5);
    x = (u8 *)env + (env[0x8C / 4] & 1) * 0x38;
    *(volatile u64 *)0x12000000 = *(u64 *)(x + 0x18);
    *(volatile u64 *)0x12000020 = *(u64 *)(x + 0x20);
    *(volatile u64 *)0x12000070 = *(u64 *)(x + 0x28);
    *(volatile u64 *)0x12000090 = *(u64 *)(x + 0x38);
    *(volatile u64 *)0x12000080 = *(u64 *)(x + 0x30);
    *(volatile u64 *)0x120000A0 = *(u64 *)(x + 0x40);
}
#endif
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

/* NEARMISS-STUB iosGsSetDrawContext */
#if 0 /* NEARMISS 89.0% cat=vu0-mmi sub=- | cfc2.ni vi29 (VU0 COP2 control read) has no C form; asm-free probe read version | attempts=1 */
/* kR39 asm-free probe: 88.74% (cfc2.ni $vi29 read replaced by volatile probe; no C form for COP2 cfc2) cause=no-c-form */
void iosGsSetDrawContext(void)
{
    u32 stat;
    u8 *dc;
    s64 qwc;
    s64 addr;

    do
    {
        stat = *(volatile u32 *)0x1000F000;
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
        stat = *(volatile u32 *)0x1000F000;
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    *D2_QWC = qwc;
    *D2_MADR = addr & 0x0FFFFFFF;
    FlushCache(0);
    *D2_CHCR = 0x141;
}
#endif
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

/* NEARMISS-STUB iosDmaSendPath1 */
#if 0 /* NEARMISS 91.0% cat=vu0-mmi sub=- | cfc2.ni vi29 (VU0 COP2 control read) has no C form; asm-free probe read version | attempts=1 */
/* kR39 asm-free probe: 90.84% (cfc2.ni $vi29 read replaced by volatile probe; no C form for COP2 cfc2) cause=no-c-form */
void iosDmaSendPath1(s64 arg0, s64 arg1)
{
    u32 stat;

    do
    {
        stat = *(volatile u32 *)0x1000F000;
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    *D1_QWC = arg1;
    *D1_MADR = arg0 & 0x0FFFFFFF;
    FlushCache(0);
    *D1_CHCR = 0x101;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDmaSendPath1);

/* NEARMISS-STUB iosDmaSendPath2 */
#if 0 /* NEARMISS 91.0% cat=vu0-mmi sub=- | cfc2.ni vi29 (VU0 COP2 control read) has no C form; asm-free probe read version | attempts=1 */
/* kR39 asm-free probe: 90.84% (cfc2.ni $vi29 read replaced by volatile probe; no C form for COP2 cfc2) cause=no-c-form */
void iosDmaSendPath2(s64 arg0, s64 arg1)
{
    u32 stat;

    do
    {
        stat = *(volatile u32 *)0x1000F000;
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    *D1_QWC = arg1;
    *D1_MADR = arg0 & 0x0FFFFFFF;
    FlushCache(0);
    *D1_CHCR = 0x101;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDmaSendPath2);

/* NEARMISS-STUB iosDmaSendPath3 */
#if 0 /* NEARMISS 91.0% cat=vu0-mmi sub=- | cfc2.ni vi29 (VU0 COP2 control read) has no C form; asm-free probe read version | attempts=1 */
/* kR39 asm-free probe: 90.84% (cfc2.ni $vi29 read replaced by volatile probe; no C form for COP2 cfc2) cause=no-c-form */
void iosDmaSendPath3(s64 arg0, s64 arg1)
{
    u32 stat;

    do
    {
        stat = *(volatile u32 *)0x1000F000;
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    *D2_QWC = arg1;
    *D2_MADR = arg0 & 0x0FFFFFFF;
    FlushCache(0);
    *D2_CHCR = 0x141;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDmaSendPath3);

/* NEARMISS-STUB iosDmaSendSChainPath1 */
#if 0 /* NEARMISS 90.0% cat=vu0-mmi sub=- | cfc2.ni vi29 (VU0 COP2 control read) has no C form; asm-free probe read version | attempts=1 */
/* kR39 asm-free probe: 90.15% (cfc2.ni $vi29 read replaced by volatile probe; no C form for COP2 cfc2) cause=no-c-form */
void iosDmaSendSChainPath1(u32 arg0)
{
    u32 stat;

    do
    {
        stat = *(volatile u32 *)0x1000F000;
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    *D1_QWC = 0;
    *D1_TADR = arg0 & 0x7FFFFFFF;
    FlushCache(0);
    *D1_CHCR = 0x145;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDmaSendSChainPath1);

/* NEARMISS-STUB iosDmaSendSChainPath2 */
#if 0 /* NEARMISS 90.0% cat=vu0-mmi sub=- | cfc2.ni vi29 (VU0 COP2 control read) has no C form; asm-free probe read version | attempts=1 */
/* kR39 asm-free probe: 90.15% (cfc2.ni $vi29 read replaced by volatile probe; no C form for COP2 cfc2) cause=no-c-form */
void iosDmaSendSChainPath2(u32 arg0)
{
    u32 stat;

    do
    {
        stat = *(volatile u32 *)0x1000F000;
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    *D1_QWC = 0;
    *D1_TADR = arg0 & 0x7FFFFFFF;
    FlushCache(0);
    *D1_CHCR = 0x145;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDmaSendSChainPath2);

/* NEARMISS-STUB iosDmaSendSChainPath3 */
#if 0 /* NEARMISS 90.0% cat=vu0-mmi sub=- | cfc2.ni vi29 (VU0 COP2 control read) has no C form; asm-free probe read version | attempts=1 */
/* kR39 asm-free probe: 90.15% (cfc2.ni $vi29 read replaced by volatile probe; no C form for COP2 cfc2) cause=no-c-form */
void iosDmaSendSChainPath3(u32 arg0)
{
    u32 stat;

    do
    {
        stat = *(volatile u32 *)0x1000F000;
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    *D2_QWC = 0;
    *D2_TADR = arg0 & 0x7FFFFFFF;
    FlushCache(0);
    *D2_CHCR = 0x105;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosDmaSendSChainPath3);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosResetPath);

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

/* NEARMISS-STUB iosGsResetCRTC */
#if 0 /* NEARMISS 91.0% cat=vu0-mmi sub=- | cfc2.ni vi29 (VU0 COP2 control read) has no C form; asm-free probe read version | attempts=1 */
/* kR39 asm-free probe: 91.38% (cfc2.ni $vi29 read replaced by volatile probe; no C form for COP2 cfc2) cause=no-c-form */
void iosGsResetCRTC(void)
{
    u32 stat;

    do
    {
        stat = *(volatile u32 *)0x1000F000;
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    func_40026BE0((*(volatile u64 *)0x12001000 >> 13) & 1);
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosGsResetCRTC);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosSetSyncNoReturnFunc);
s32 iosSetSyncNoReturnFunc(s32 func)
{
    D_40045A90 = func;
    return 1;
}

/* NEARMISS-STUB iosSetScreenEnv */
#if 0 /* NEARMISS 93.0% cat=vu0-mmi sub=- | cfc2.ni vi29 (VU0 COP2 control read) has no C form; asm-free probe read version | attempts=1 */
/* kR39 asm-free probe: 93.19% (cfc2.ni $vi29 read replaced by volatile probe; no C form for COP2 cfc2) cause=no-c-form */
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
        stat = *(volatile u32 *)0x1000F000;
    } while ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00));
    func_40026BE0((*(volatile u64 *)0x12001000 >> 13) & 1);
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosSetScreenEnv);

/* NEARMISS-STUB iosCheckDrawFinish */
#if 0 /* NEARMISS 68.0% cat=vu0-mmi sub=- | cfc2.ni vi29 (VU0 COP2 control read) has no C form; asm-free probe read version | attempts=1 */
/* kR39 asm-free probe: 67.5% (cfc2.ni $vi29 read replaced by volatile probe; no C form for COP2 cfc2) cause=no-c-form */
s32 iosCheckDrawFinish(void)
{
    u32 stat;

    D_40045A5C++;
    stat = *(volatile u32 *)0x1000F000;
    if ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100) || (*VIF1_STAT & 0x1F000003) || (stat & 0x100) || (*GIF_STAT & 0xC00))
        return 0;
    return 1;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosCheckDrawFinish);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gs", iosGsInitDC);
void iosGsInitDC(void)
{
    iosResetDC(D_40092C58 + iosDlGetWorkBufId() * 0x190);
}

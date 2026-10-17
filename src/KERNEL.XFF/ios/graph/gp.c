#include "common.h"
#include "sdk/ee/eetypes.h"
#include "sdk/ee/eestruct.h"
#include "sdk/ee/eekernel.h"
#include "sdk/ee/libgraph.h"
#include "sdk/ee/eeregs.h"
#include "ios/thread.h"
#include "ios/system.h"


extern void iosGsInitDC();
extern void iosCopyFrameBuffer();
extern void iosGsResetCRTC();
extern void iosDlSwap();
extern void iosDlTrans();
extern void iosSyncV(s32);
extern void iosSyncPath(s32, s32);
extern void iosDebPcVsyncCounterCheck(void);
extern void waitVscheduler(void);
extern void iosPushVu0Registers(void);
extern void iosPopVu0Registers(void);
extern s32 iosCheckDrawFinish(void);
extern volatile s64* iosGetPacketPtrPath1();
extern void iosSetPacketPtrPath1();
extern void iosDlChainTailCurrent();

extern void InitDL(s32, s32);
extern void iosSetScreenEnv(s32, s32, s32, s32);
extern void iosAddIntcHandler(s32, void*);

extern volatile s32 gpMainCallCounter;




// .data
extern s32 D_40045AB8;
extern s32 D_40045ABC;
extern volatile s32 D_40045AC0;
extern volatile s32 D_40045AC4;
extern volatile s64 D_40045AC8;
extern volatile s32 D_40045AD0;
extern void (*D_40045AD4)(); // i start function
extern void (*D_40045AD8)(); // i finish function
extern void (*D_40045ADC)(); // gp finish function
extern void (*D_40045AE0)(); // dl trans function
extern void (*D_40045AE4)(); // v scheduler function
extern void (*D_40045AE8)();
extern s32 D_40045AEC;
extern struct unkstrc {
    volatile s64 *unk0;
    s64 *unk4, *unk8;
    volatile s64* unkC;
    s32 unk10, unk14, unk18, unk1C;
} *D_40045AF4;
extern s32 D_40045AF8;
extern void iosFTOI4Vector(s32 *dst, f32 *src);

static inline void gsRegI(s64 addr, s64 data)
{
    if (D_40045AF4->unk1C == 0)
    {
        *(D_40045AF4->unkC++) = data;
        *(D_40045AF4->unkC++) = addr;
    }
}
#define GSREG(addr, data) gsRegI((addr), (data))
#define GSVERT(x, y) (((u64)((x) + 0x8000) | ((u64)((y) + 0x8000) << 16)) | 0xFFFFFFFF00000000ULL)
#define GSVERTZ(x, y, z) (((u64)((x) + 0x8000) | ((u64)((y) + 0x8000) << 16)) | ((u64)(z) << 32))
#define GSRGBAQ(c) ((u64)(c)[0] | ((u64)(c)[1] << 8) | ((u64)(c)[2] << 16) | ((u64)(c)[3] << 24) | 0x3F80000000000000LL)


// .bss
extern volatile struct { char pad[0xA0]; s32 unkA0; s32 unkA4; } D_40092BD0;
extern s16 D_40045A50, D_40045A54, D_40045A58;
extern void iosInitDC();
extern void isysSleepSubThread();
extern volatile s64 D_40092C90;
extern iosThread* D_40092C98;
extern s32 D_40092CA0;



// prototypes
s32 func_40028600(void);
void func_400286E8();









//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", InitGp);
void InitGp(void)
{
    s16 a;
    s16 b;
    s16 c;

    iosInitDC();
    a = D_40045A50;
    b = D_40045A54;
    c = D_40045A58;
    D_40092BD0.unkA0 = 1;
    D_40092BD0.unkA4 = 0;
    *GS_CSR = 0x200;
    sceGsResetGraph(0, a & 1, b, c & 1);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", iosWaitDMA);
s32 iosWaitDMA(void)
{
    asm(".L400281D0: bc0f .L400281D0; nop");
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", iosWaitVU1);
s32 iosWaitVU1(void)
{
    asm(".L400281F8: bc2t .L400281F8; nop;");
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", getCRTCoffsetU);
s32* getCRTCoffsetU(void)
{
    return &D_40045AB8;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", getCRTCoffsetV);
s32* getCRTCoffsetV(void)
{
    return &D_40045ABC;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", iosGsChangeScreenOffset);
void iosGsChangeScreenOffset(void)
{
    func_400268A8();
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", iosSyncGP);
void iosSyncGP(void)
{
    FlushCache(0);
    iosGsInitDC();
    iosCopyFrameBuffer();
    if (D_40045AE0 != NULL)
        D_40045AE0();
    iosGsResetCRTC();
    D_40045AD0 = 1;
    sceGsPutIMR(sceGsGetIMR() & ~0x200);
    iosDlSwap();
    iosDlTrans();
    FlushCache(0);
    if (D_40045AE0 != NULL)
        D_40045AE0();
    iosGsResetCRTC();
    D_40045AD0 = 1;
    sceGsPutIMR(sceGsGetIMR() & ~0x200);
    iosDlSwap();
    iosDlTrans();
    iosSyncPath(0, 0);
    iosSyncV(0);
    iosSyncV(0);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", bootGPThread);
void bootGPThread(void* arg0)
{
    InitDL(0x7C80, 0x20);
    iosSetScreenEnv(0x200, 0x1C0, 0x200, 0x1C0);
    D_40092C90 = iosGetTCount();
    *GS_CSR |= 2;
    sceGsPutIMR(sceGsGetIMR() & ~0x200);
    iosAddIntcHandler(0, func_40028600);
    D_40045AE8 = arg0;
    D_40092C98 = iosCreateThread(func_400286E8, &D_40092CA0, 0x8000, 0x2A, 0);
    iosStartThread(D_40092C98, NULL);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", iosTransGP);
void iosTransGP(void)
{
    if (D_40045AE0 != NULL)
        D_40045AE0();
    iosGsResetCRTC();
    D_40045AD0 = 1;
    sceGsPutIMR(sceGsGetIMR() & ~0x200);
    iosDlSwap();
    iosDlTrans();
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", iosChkGpDlTransExec);
s32 iosChkGpDlTransExec(void)
{
    s32 var_a0;

    var_a0 = 0;
    if ((*D1_CHCR & 0x100) || (*D2_CHCR & 0x100))
        var_a0 = 1;
    return var_a0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", iosGPFrameInit);
void iosGPFrameInit(void)
{
    iosGsInitDC();
    iosCopyFrameBuffer();
    if (D_40045AE0 != NULL)
        D_40045AE0();
    iosGsResetCRTC();
    D_40045AD0 = 1;
    sceGsPutIMR(sceGsGetIMR() & ~0x200);
    iosDlSwap();
    iosDlTrans();
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", iosSetIStartFunc);
s32 iosSetIStartFunc(void* arg0)
{
    D_40045AD4 = arg0;
    return 1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", iosSetGpFinishFunc);
s32 iosSetGpFinishFunc(void* arg0)
{
    D_40045ADC = arg0;
    return 1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", iosSetIFinishFunc);
s32 iosSetIFinishFunc(void* arg0)
{
    D_40045AD8 = arg0;
    return 1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", getIntrGpCount);
s64 getIntrGpCount()
{
    return D_40045AC8;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", iosSetDlTransFunc);
s32 iosSetDlTransFunc(void* arg0)
{
    D_40045AE0 = arg0;
    return 1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", iosSetVSchedulerFunc);
s32 iosSetVSchedulerFunc(void* arg0)
{
    D_40045AE4 = arg0;
    return 1;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", iosWaitGPFinish);
//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", func_40028600);
s32 func_40028600(void)
{
    u64 temp_s0;

    temp_s0 = isceGsPutIMR(0xFF00U);
    D_40045AC8 += 1;
    if (D_40045ADC != NULL)
        D_40045ADC();
    
    *GS_CSR |= 2;
    isceGsPutIMR(temp_s0);
    ExitHandler();
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", iStart);
void iStart(void)
{
    if (D_40045AD4 != NULL)
        D_40045AD4();
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", iFinish);
void iFinish(void)
{
    if (D_40045AD8 != NULL)
        D_40045AD8();
    D_40045AC0 = 1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", func_400286E8);
void func_400286E8(void)
{
    while(1)
    {
        iosDebPcVsyncCounterCheck();
        waitVscheduler();
        iosPushVu0Registers();
        gpMainCallCounter++;
        
        if (D_40045AE4 != NULL)
            D_40045AE4();
        
        D_40045AC4 = iosCheckDrawFinish();
        if (D_40045AC4 != 0)
        {
            if (D_40045AC0 != 0)
            {
                D_40045AC0 = 0;
                D_40045AEC = D_40045AC0;
            }
            if (D_40045AE8 != 0)
                D_40045AE8();
            
            D_40045AD0 = 0;
        }
        else
        {
            if (++D_40045AEC >= 121)
                iosSyncPath(0, 0);
        }
        iosPopVu0Registers();
    }
}

volatile s64* gsRegBegin(void)
{
    D_40045AF4->unk1C = 0;
    D_40045AF4->unkC = iosGetPacketPtrPath1();
    if (D_40045AF4->unkC == NULL)
    {
        D_40045AF4->unk1C = 1;
    }
    else
    {
        D_40045AF4->unk0 = D_40045AF4->unkC;
        D_40045AF4->unkC += 1;
    }
    if (D_40045AF4->unk1C == 0)
    {
        D_40045AF4->unk4 = (s64*)D_40045AF4->unkC;
        *(D_40045AF4->unkC++) = 0;
        if (((u32)D_40045AF4->unkC & 3) != 0)
        {
            *(D_40045AF4->unkC++) = 0;
        }
        D_40045AF4->unk8 = (s64*)D_40045AF4->unkC;
        D_40045AF4->unkC += 2;
    }
    return D_40045AF4->unkC;
}
#define GTAG ((sceGifTag *)D_40045AF4->unk8)
//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", gsRegEnd);
void gsRegEnd(void)
{
    if (D_40045AF4->unk1C == 0)
    {
        D_40045AF4->unk14 = ((u32)D_40045AF4->unkC - (u32)D_40045AF4->unk8) >> 4;
        D_40045AF4->unk18 = D_40045AF4->unk14 - 1;
        if (D_40045AF4->unk18 > 0)
        {
            SCE_GIF_CLEAR_TAG(GTAG);
            GTAG->FLG = 0;
            GTAG->PRE = 0;
            GTAG->EOP = 1;
            GTAG->NREG = 1;
            GTAG->REGS0 = 0xE;
            GTAG->NLOOP = D_40045AF4->unk18;
            ((u32 *)D_40045AF4->unk8)[-1] = 0x50000000 | D_40045AF4->unk14;
            ((u32 *)D_40045AF4->unk8)[-2] = 0x10000000;
        }
        else
        {
            D_40045AF4->unkC = D_40045AF4->unk4;
        }
    }
    if (D_40045AF4->unk1C != 0)
    {
        D_40045AF4->unkC = 0;
        return;
    }
    D_40045AF4->unk10 = (((u32)D_40045AF4->unkC - (u32)D_40045AF4->unk0) >> 4) - 1;
    if (D_40045AF4->unk10 > 1)
    {
        *D_40045AF4->unk0 = D_40045AF4->unk10 | 0x60000000;
        iosSetPacketPtrPath1(D_40045AF4->unkC);
        iosDlChainTailCurrent(D_40045AF4->unk0);
        D_40045AF4->unkC = 0;
        return;
    }
    D_40045AF4->unkC = 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", gsRegEndWithPtr);
volatile s64 *gsRegEndWithPtr(void)
{
    if (D_40045AF4->unk1C == 0)
    {
        D_40045AF4->unk14 = ((u32)D_40045AF4->unkC - (u32)D_40045AF4->unk8) >> 4;
        D_40045AF4->unk18 = D_40045AF4->unk14 - 1;
        if (D_40045AF4->unk18 > 0)
        {
            SCE_GIF_CLEAR_TAG(GTAG);
            GTAG->FLG = 0;
            GTAG->PRE = 0;
            GTAG->EOP = 1;
            GTAG->NREG = 1;
            GTAG->REGS0 = 0xE;
            GTAG->NLOOP = D_40045AF4->unk18;
            ((u32 *)D_40045AF4->unk8)[-1] = 0x50000000 | D_40045AF4->unk14;
            ((u32 *)D_40045AF4->unk8)[-2] = 0x10000000;
        }
        else
        {
            D_40045AF4->unkC = D_40045AF4->unk4;
        }
    }
    if (D_40045AF4->unk1C != 0)
    {
        D_40045AF4->unkC = 0;
        return NULL;
    }
    D_40045AF4->unk10 = (((u32)D_40045AF4->unkC - (u32)D_40045AF4->unk0) >> 4) - 1;
    if (D_40045AF4->unk10 > 1)
    {
        *D_40045AF4->unk0 = D_40045AF4->unk10 | 0x60000000;
        iosSetPacketPtrPath1(D_40045AF4->unkC);
        iosDlChainTailCurrent(D_40045AF4->unk0);
        D_40045AF4->unkC = 0;
        return D_40045AF4->unk0;
    }
    D_40045AF4->unkC = 0;
    return NULL;
}

void gsReglistBegin(void)
{
    D_40045AF4->unk1C = 0;
    D_40045AF4->unkC = iosGetPacketPtrPath1();
    if (D_40045AF4->unkC == NULL)
    {
        D_40045AF4->unk1C = 1;
    }
    else
    {
        D_40045AF4->unk0 = D_40045AF4->unkC;
        D_40045AF4->unkC += 1;
    }
    if (D_40045AF4->unk1C == 0)
    {
        D_40045AF4->unk4 = (s64*)D_40045AF4->unkC;
        *(D_40045AF4->unkC++) = 0;
        if (((u32)D_40045AF4->unkC & 3) != 0)
        {
            *(D_40045AF4->unkC++) = 0;
        }
        D_40045AF4->unk8 = (s64*)D_40045AF4->unkC;
        D_40045AF4->unkC += 2;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", gsReglistEnd);
void gsReglistEnd(s32 prim)
{
    if (D_40045AF4->unk1C == 0)
    {
        D_40045AF4->unk14 = ((u32)D_40045AF4->unkC - (u32)D_40045AF4->unk8) >> 4;
        D_40045AF4->unk18 = (D_40045AF4->unk14 - 1) / 3;
        if (D_40045AF4->unk18 > 0)
        {
            SCE_GIF_CLEAR_TAG(GTAG);
            GTAG->FLG = 0;
            GTAG->PRE = 1;
            GTAG->EOP = 1;
            GTAG->NREG = 3;
            GTAG->REGS0 = 2;
            GTAG->REGS1 = 1;
            GTAG->REGS2 = 4;
            GTAG->NLOOP = D_40045AF4->unk18 * 3;
            GTAG->PRIM = prim;
        }
        else
        {
            D_40045AF4->unkC = D_40045AF4->unk4;
        }
    }
    if (D_40045AF4->unk1C != 0)
    {
        D_40045AF4->unkC = 0;
        return;
    }
    D_40045AF4->unk10 = (((u32)D_40045AF4->unkC - (u32)D_40045AF4->unk0) >> 4) - 1;
    if (D_40045AF4->unk10 > 1)
    {
        *D_40045AF4->unk0 = D_40045AF4->unk10 | 0x60000000;
        iosSetPacketPtrPath1(D_40045AF4->unkC);
        iosDlChainTailCurrent(D_40045AF4->unk0);
        D_40045AF4->unkC = 0;
        return;
    }
    D_40045AF4->unkC = 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", gsBox);
void gsBox(f32 *rect, s32 *fill, s32 *line)
{
    s32 xy[4] __attribute__((aligned(16)));

    gsRegBegin();
    iosFTOI4Vector(xy, rect);
    GSREG(0, 0x4E);
    GSREG(1, GSRGBAQ(fill));
    GSREG(4, GSVERT(xy[0], xy[1]));
    GSREG(4, GSVERT(xy[2], xy[3]));
    GSREG(0, (line[3] == 0x80) ? 0xCA : 0x4A);
    GSREG(1, GSRGBAQ(line));
    GSREG(4, GSVERT(xy[0], xy[1]));
    GSREG(4, GSVERT(xy[0], xy[3]));
    GSREG(4, GSVERT(xy[2], xy[3]));
    GSREG(4, GSVERT(xy[2], xy[1]));
    GSREG(4, GSVERT(xy[0], xy[1]));
    gsRegEnd();
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", gsBox2);
void gsBox2(f32 *rect, s32 *fill, s32 *line, s32 w)
{
    s32 xy[4] __attribute__((aligned(16)));

    gsRegBegin();
    iosFTOI4Vector(xy, rect);
    GSREG(0, 0x4E);
    GSREG(1, GSRGBAQ(fill));
    GSREG(4, GSVERT(xy[0], xy[1]));
    GSREG(4, GSVERT(xy[2], xy[3]));
    GSREG(0, (line[3] == 0x80) ? 0xC9 : 0x49);
    GSREG(1, GSRGBAQ(line));
    GSREG(4, GSVERT(xy[0], xy[1] - w));
    GSREG(4, GSVERT(xy[0], xy[3] + w));
    GSREG(4, GSVERT(xy[0] - w, xy[3]));
    GSREG(4, GSVERT(xy[2] + w, xy[3]));
    GSREG(4, GSVERT(xy[2], xy[3] + w));
    GSREG(4, GSVERT(xy[2], xy[1] - w));
    GSREG(4, GSVERT(xy[2] + w, xy[1]));
    GSREG(4, GSVERT(xy[0] - w, xy[1]));
    gsRegEnd();
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", gsBoxLine);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", spriteNoTexFast);
void spriteNoTexFast(s32 x, s32 y, s32 w, s32 h, s32 z, s32 *rgba, s32 abe)
{
    if (D_40045AF8 == 0)
    {
        GSREG(0, (abe << 6) | 6);
        GSREG(1, GSRGBAQ(rgba));
        GSREG(4, GSVERTZ(x, y, z));
        GSREG(4, GSVERTZ(x + w, y + h, z));
    }
    else
    {
        s32 tile = 64;
        s32 pw = w >> 4;
        s32 ph = h >> 4;
        s32 rem = (pw % tile) != 0;
        s32 cols;
        s32 i;
        u32 zz = z;

        GSREG(1, GSRGBAQ(rgba));
        GSREG(0, (abe << 6) | 6);
        cols = (w >> 10) + rem;
        for (i = 0; i < cols; i++)
        {
            GSREG(0x40, (u64)(i * tile) | ((u64)((i + 1) * tile - 1) << 16) | ((u64)(ph - 1) << 48));
            GSREG(4, GSVERTZ(x, y, zz));
            GSREG(4, GSVERTZ(x + w, y + h, zz));
        }
        GSREG(0x40, ((u64)(pw - 1) << 16) | ((u64)(ph - 1) << 48));
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", spriteTexFast);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", gsReg);
void gsReg(s64 arg0, s64 arg1)
{
    if (D_40045AF4->unk1C == 0)
    {
        *(D_40045AF4->unkC++) = arg1;
        *(D_40045AF4->unkC++) = arg0;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", getSpriteDrawFirst);
s32* getSpriteDrawFirst()
{
    return &D_40045AF8;
}

void gsReglist(void)
{}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", iosTransTex);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/graph/gp", getTWH);



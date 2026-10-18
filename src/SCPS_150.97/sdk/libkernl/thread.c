#include "common.h"
#include "sdk/ee/eekernel.h"

typedef struct ThreadReadyEntry
{
    u8 unk00;
    u8 unk01;
} ThreadReadyEntry;

typedef struct ThreadReadyQueue
{
    s32 unk00;
    s32 unk04;
    ThreadReadyEntry unk08[0x200];
} ThreadReadyQueue;

extern s32 D_00132380[];
extern s32 D_00143E10[];
extern ThreadReadyQueue D_00143E18[];
extern s32 D_00132384[];
extern char D_00144220[];
extern char D_00137D88[];
extern char D_00143A10[];
extern s32 D_00137DB0[];

void kputs(char *str);

void func_00107DA8(s32 c);
s32 func_001080F8();
s32 sioPutc(s32 c);
s32 iSignalSema(s32 id);
s32 WaitSema(s32 id);
s32 WakeupThread(s32 id);
s32 SuspendThread(s32 id);
s32 RotateThreadReadyQueue(s32 id);
s32 kprintf(const char *fmt, ...);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", topThread);
void topThread(ThreadReadyQueue *a0)
{
    s32 idx;

    for (;;)
    {
        WaitSema(D_00143E10[0]);
        idx = a0->unk00 & 0x1FF;
        a0->unk00 = idx + 1;
        switch (a0->unk08[idx].unk00)
        {
        case 0:
            WakeupThread(a0->unk08[idx].unk01);
            break;
        case 1:
            RotateThreadReadyQueue(a0->unk08[idx].unk01);
            break;
        case 2:
            SuspendThread(a0->unk08[idx].unk01);
            break;
        default:
            kprintf(D_00137D88);
            break;
        }
    }
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", InitThread);
s32 InitThread(void)
{
    struct ThreadParam thread;
    struct SemaParam sema;
    s32 id;

    if (D_00132380[0] > 0)
    {
        return -1;
    }
    sema.maxCount = 0xFF;
    sema.initCount = 0;
    sema.option = (u_int)D_00137DB0;
    D_00143E10[0] = CreateSema(&sema);
    if (D_00143E10[0] < 0)
    {
        return -1;
    }
    thread.entry = (void (*)(void *))topThread;
    thread.stack = D_00143A10;
    thread.stackSize = 0x400;
    thread.gpReg = (void *)&_gp;
    thread.initPriority = 0;
    thread.option = (u_int)D_00137DB0;
    id = CreateThread(&thread);
    D_00132380[0] = id;
    if (id < 0)
    {
        DeleteSema(D_00143E10[0]);
        return -1;
    }
    D_00143E18[0].unk00 = 0;
    D_00143E18[0].unk04 = 0;
    StartThread(id, D_00143E18);
    ChangeThreadPriority(GetThreadId(), 1);
    return D_00132380[0];
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", iWakeupThread);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", iRotateThreadReadyQueue);
s32 iRotateThreadReadyQueue(s32 a0)
{
    s32 idx;

    if ((u32)a0 >= 0x80)
    {
        return -1;
    }
    if (D_00132380[0] == 0)
    {
        return -1;
    }
    idx = D_00143E18[0].unk04 & 0x1FF;
    D_00143E18[0].unk04 = idx + 1;
    D_00143E18[0].unk08[idx].unk00 = 1;
    D_00143E18[0].unk08[idx].unk01 = a0;
    iSignalSema(D_00143E10[0]);
    return a0;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", iSuspendThread);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", DelayThread);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", StartThread);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", _DelayThreadHandler);

/* NEARMISS-STUB sioPutc */
#if 0 /* NEARMISS 55.5% cat=sdk-compiler sub=ee-gcc2.9-991111 | ref loop: lw, andi, 3 nops, bnez; sb sits in jr delay slot after daddu return move; 55.5% attempt loop/store order differs under ee-gcc2.9 (static diff only) | attempts=1 */
s32 sioPutc(s32 c)
{
    volatile s32 *stat = (volatile s32 *)0x1000F130;
    volatile u8 *data = (volatile u8 *)0x1000F180;

    while (*stat & 0x8000)
        ;
    *data = c;
    return c;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", sioPutc);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", func_00107DA8);
void func_00107DA8(s32 c)
{
    s32 idx;

    idx = D_00132384[0];
    if (idx >= 0x7E)
    {
        D_00132384[0] = 0;
        D_00144220[0x7F] = 0;
        kputs(D_00144220);
        idx = D_00132384[0];
    }
    if (c == 10)
    {
        D_00132384[0] = 0;
        D_00144220[idx] = c;
        D_00144220[idx + 1] = 0;
        kputs(D_00144220);
        return;
    }
    D_00132384[0] = idx + 1;
    D_00144220[idx] = c;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", sioPutcNL);
void sioPutcNL(s32 c)
{
    if (c == 10)
    {
        sioPutc(13);
        sioPutc(10);
    }
    else
    {
        sioPutc(c);
    }
}

/* NEARMISS-STUB func_00107E90 */
#if 0 /* NEARMISS 9.7% cat=bitops sub=ee-gcc2.9-991111 | 64-bit IEEE double bit-pattern decode (exponent field, mantissa shift, round-half on variable shift); 9.7% attempt guessed the rounding; body has no FPU ops; not sdk-compiler | attempts=1 */
s32 func_00107E90(u64 x)
{
    s32 e;
    u64 m;
    s64 r;

    e = (s32)((x << 1) >> 53) - 0x433;
    if (e < -0x35)
    {
        return 0;
    }
    if (e >= 0xD)
    {
        return 0x270F;
    }
    m = ((x << 12) >> 12) | (1ULL << 52);
    if (e < 0)
    {
        e = -e;
        r = m >> (e - 2);
        if ((r & 3) == 3)
        {
            return (s32)((r >> 2) + 1);
        }
        return (s32)(r >> 2);
    }
    return (s32)(m << e);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", func_00107E90);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", func_00107F20);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", func_001080F8);

/* NEARMISS-STUB func_00108E10 */
#if 0 /* NEARMISS 27.0% cat=sdk-compiler sub=ee-gcc2.9-991111 | 27% best (kK23) has the right shape; movz select for if(*a1==1) a2=0 and beql early-out do not match ee-gcc2.9 codegen; db cause "exact or 1 insn off" contradicts 27%, recheck under SDK compiler | attempts=1 */
s32 func_00108E10(u8 **a0, s32 *a1, s32 a2)
{
    u8 *p;

    if (*a1 == 0)
    {
        return 1;
    }
    if (a2 >= 0x100)
    {
        **a0 = 0;
        return 0;
    }
    p = *a0;
    if (*a1 == 1)
    {
        a2 = 0;
    }
    *p = a2;
    *a0 = p + 1;
    *a1 -= 1;
    return 1;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", func_00108E10);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", func_00108E68);
s32 func_00108E68(s32 a0, s32 a1, s32 a2)
{
    if (a2 != 0)
    {
        func_00107DA8(a2);
    }
    return 1;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", sioPutcSkipNull);
s32 sioPutcSkipNull(s32 a0, s32 a1, s32 a2)
{
    if (a2 != 0)
    {
        sioPutcNL(a2);
    }
    return 1;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/thread", func_00108EB8);

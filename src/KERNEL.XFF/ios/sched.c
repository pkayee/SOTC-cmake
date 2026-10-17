#include "common.h"
#include "sdk/ee/eekernel.h"
#include "sdk/ee/eeregs.h"
#include "ios/message.h"
#include "ios/thread.h"

typedef struct
{
    s32 unk0;
    s32 unk4;
} t_ischedTask;

extern volatile s32 D_40045C64;
extern s32 D_40045C68;
extern s32 D_40045C6C;
extern s32 D_40045C74;
extern s32 D_40045C7C;
extern s64 D_400F2B18;
extern volatile s32 D_400F2B20;
extern t_iosMessageQueue D_400F2B28;
extern iosThread* D_400F2B44;
extern t_iosMessageQueue D_400F3B50;
extern t_ischedTask D_400F3B70[3];
extern iosThread *D_400F3B88;
extern u8 D_400F2B50[];
extern u8 D_400F3B90[];
extern u64 D_400F2B10;
extern s32 vschedGameTimeExec;
extern s32 vschedGameTime;
extern void iosPadInit(void);
extern void iosPadTickProc(void);
extern void iosCreateIVArbitrationSema(void);
extern void iosAddIntcHandler(s32, void *);
extern void tickProcSound(s32);
extern s64 iosGetTCountExtension(void);
extern s32 func_4002C8F0();
extern s32 func_4002CDB0();
extern s32 func_4002CE70(void);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", func_4002C8F0);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", getVIntrCnt);
s32 getVIntrCnt(void)
{
    return D_40045C64;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", waitVscheduler);
void waitVscheduler(void)
{
    iosSendMsg(&D_400F3B50, 0, 1);
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", bootSchedulerThread);
void bootSchedulerThread(void)
{
    iosPadInit();
    D_40045C6C = 0;
    iosCreateIVArbitrationSema();
    D_400F2B44 = iosCreateThread(func_4002CDB0, D_400F2B50, 0x1000, 0x28, 0);
    iosStartThread(D_400F2B44, 0);
    iosAddIntcHandler(2, func_4002CE70);
    D_400F3B88 = iosCreateThread(func_4002C8F0, D_400F3B90, 0x2000, 0x2D, 0);
    iosStartThread(D_400F3B88, 0);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", iosAddISchedulerTaskList);
void iosAddISchedulerTaskList(s32 arg0, s32 arg1)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        if (D_400F3B70[i].unk0 == 0)
        {
            D_400F3B70[i].unk0 = arg0;
            D_400F3B70[i].unk4 = arg1;
            return;
        }
    }
    asm("break");
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", iosGetISchedulerExecCnt);
s32 iosGetISchedulerExecCnt(void)
{
    return D_40045C74;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", ischedStop);
void ischedStop(void)
{
    if (D_400F2B20 == 0)
    {
        *T0_MODE &= ~0x80;
    }
    D_400F2B20 += 1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", ischedRestart);
void ischedRestart(void)
{
    D_400F2B20 -= 1;
    if (D_400F2B20 == 0)
    {
        *T0_MODE |= 0x80;
    }
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", iosSetISchedulerSubthreadTask);
void iosSetISchedulerSubthreadTask(s32 arg0)
{
    D_40045C7C = arg0;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", iosSetIVSyncMode);
void iosSetIVSyncMode(s32 arg0)
{
    D_40045C6C = arg0;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", iosGetIVSyncMode);
s32 iosGetIVSyncMode(void)
{
    return D_40045C6C;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", vschedSetNextFrameForceGarbage);
void vschedSetNextFrameForceGarbage(void)
{
    D_40045C68 = 1;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", GetGarbageTime);
s64 GetGarbageTime(void)
{
    return D_400F2B18;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", func_4002CD88);
void func_4002CD88(void)
{
    iosRecvMsg(&D_400F2B28, NULL, 0);
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", func_4002CDB0);
s32 func_4002CDB0(void)
{
    iosCreateMsgQueue(&D_400F3B50, 0, 0);
    while (1)
    {
        iosSleepThread();
        D_400F2B10 = iosGetTCountExtension();
        D_40045C64++;
        if (vschedGameTimeExec != 0)
        {
            vschedGameTime++;
        }
        tickProcSound(D_400F2B20);
        iosPadTickProc();
        iosRecvMsg(&D_400F3B50, 0, 0);
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", func_4002CE70);
s32 func_4002CE70(void)
{
    iosiWakeupThread(D_400F2B44);
    ExitHandler();
    return 0;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", func_4002CEA0);
s32 func_4002CEA0(s32 arg0)
{
    s32 r;

    if (D_40045C68 == 0)
    {
        r = 0;
        if (arg0 == D_40045C64 && (float)(u64)(iosGetTCountExtension() - D_400F2B10) < 2124999.75f)
        {
            r = 1;
        }
    }
    else
    {
        r = 1;
    }
    return r;
}

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

extern s32 D_40045C64;
extern s32 D_40045C68;
extern s32 D_40045C6C;
extern s32 D_40045C74;
extern s32 D_40045C7C;
extern s64 D_400F2B18;
extern s32 D_400F2B20;
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
extern s32 rootPtn;
extern s32 gpMainCallCounter;
extern s32 D_40045C80;
extern s32 schedGarbageDisableFlag;
extern s32 ischedExecSubThread;
extern void iosCdSetErrorCallback(void *arg0, void *arg1);
extern void iosCreateMsgQueue(t_iosMessageQueue *arg0, void *arg1, s32 arg2);
extern void bootGPThread(void *arg0);
extern void init_letter_manager(void *arg0, s32 arg1);
extern void isysDeleteObjManager(s32 arg0);
extern void sndSepTickProc(void);
extern void iosWaitIdleThread(void);
extern void iosMallocGarbageTickProc(s32 (*cb)(void *), void *cbArg);
extern s32 iosChkGpDlTransExec(void);
extern void iosGPFrameInit(void);
extern s64 getIntrGpCount(void);
extern void iStart(void);
extern void iFinish(void);
extern void doit_letter_manager(void);
extern void ischedStop(void);
extern void ischedRestart(void);
extern void func_4002CD88(void);
extern s32 func_4002CEA0(s32 arg0);

/* NEARMISS-STUB func_4002C8F0 */
#if 0 /* NEARMISS 92.3% cat=volatile-alias sub=- | needs volatile (banned): poll loop and top lock store; local-ptr lock form reached 92.3, delay slot fill and vint reread still differ | attempts=1 */
s32 func_4002C8F0(void)
{
    s32 garbageFlag;
    s32 vintSnap;
    s32 i;
    s32 *lockp = &D_400F2B20;

    *lockp = 0;
    iosCdSetErrorCallback((void *)ischedStop, (void *)ischedRestart);
    iosCreateMsgQueue(&D_400F2B28, 0, 0);
    bootGPThread((void *)func_4002CD88);
    memset(D_400F3B70, 0, sizeof(D_400F3B70));
    init_letter_manager((void *)&rootPtn, 0x4CCCC);

    while (1)
    {
        isysDeleteObjManager(gpMainCallCounter);
        gpMainCallCounter = 0;
        iStart();
        sndSepTickProc();
        if (D_40045C7C != 0)
        {
            ischedExecSubThread = 1;
            ((void (*)(void))D_40045C7C)();
            ischedExecSubThread = 0;
        }
        for (i = 0; i < 3; i++)
        {
            if (D_400F3B70[i].unk0 != 0)
            {
                ((void (*)(s32))D_400F3B70[i].unk0)(D_400F3B70[i].unk4);
            }
        }
        D_40045C74++;
        while (*lockp != 0)
        {
        }
        doit_letter_manager();
        D_400F2B18 = 0;
        if (D_40045C80 == 0 && schedGarbageDisableFlag == 0)
        {
            vintSnap = D_40045C64;
            while (iosChkGpDlTransExec() != 0)
            {
            }
            garbageFlag = 1;
            if (D_40045C68 == 0)
            {
                garbageFlag = 0;
                if (vintSnap == D_40045C64 &&
                    (float)(u64)(iosGetTCountExtension() - D_400F2B10) < 2124999.75f)
                {
                    garbageFlag = 1;
                }
            }
            if (garbageFlag)
            {
                s64 t = iosGetTCountExtension();
                iosMallocGarbageTickProc((s32 (*)(void *))func_4002CEA0, (void *)vintSnap);
                D_40045C68 = 0;
                D_400F2B18 = iosGetTCountExtension() - t;
            }
            iFinish();
        }
        else
        {
            iFinish();
            D_40045C80 = 0;
        }
        if (D_40045C6C != 0)
        {
            iosWaitIdleThread();
            continue;
        }
        iosSendMsg(&D_400F2B28, 0, 1);
        getIntrGpCount();
        iosGPFrameInit();
    }
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", func_4002C8F0);

/* NEARMISS-STUB getVIntrCnt */
#if 0 /* NEARMISS 47.8% cat=volatile-alias sub=- | needs volatile (banned): expected lui+addiu+lw 0(v1) (volatile-global address form); plain/local-pointer/int-cast/register/array-index forms all fold to lw %lo | attempts=1 */
s32 getVIntrCnt(void)
{
    return (&D_40045C64)[0];
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", getVIntrCnt);


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", waitVscheduler);
void waitVscheduler(void)
{
    iosSendMsg(&D_400F3B50, 0, 1);
}


/* NEARMISS-STUB bootSchedulerThread */
#if 0 /* NEARMISS 99.87% cat=volatile-alias sub=- | needs volatile (banned): target lui %hi(D_400F2B50+0x4a0) addend differs from plain-form 0x4c0; local-ptr, s32-retype, folded-offset forms change the lui shape | attempts=1 */
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
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", bootSchedulerThread);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", iosAddISchedulerTaskList);


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", iosGetISchedulerExecCnt);
s32 iosGetISchedulerExecCnt(void)
{
    return D_40045C74;
}


/* NEARMISS-STUB ischedStop */
#if 0 /* NEARMISS 67.6% cat=volatile-alias sub=- | needs volatile (banned): target reloads D_400F2B20 after T0_MODE store | attempts=1 */
void ischedStop(void)
{
    if (D_400F2B20 == 0)
    {
        *T0_MODE &= ~0x80;
    }
    D_400F2B20 += 1;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", ischedStop);

/* NEARMISS-STUB ischedRestart */
#if 0 /* NEARMISS 75.7% cat=volatile-alias sub=- | needs volatile (banned): target store then reloads D_400F2B20 via lw 0(v0) before bnez; plain/alias/label/goto forms forward the value and fold to lw %lo | attempts=1 */
void ischedRestart(void)
{
    s32 *p;

    p = &D_400F2B20;
    *p = *p - 1;
    if (*p == 0)
    {
        *T0_MODE |= 0x80;
    }
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", ischedRestart);


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


/* NEARMISS-STUB func_4002CDB0 */
#if 0 /* NEARMISS 92.23404% cat=volatile-alias sub=- | needs volatile (banned): ours folds sw D_40045C64 into delay slot of beqz, target keeps it before; prologue hi-reg order differs | attempts=1 */
s32 func_4002CDB0(void)
{
    s32 *p;

    iosCreateMsgQueue(&D_400F3B50, 0, 0);
    p = &D_400F2B20;
    while (1)
    {
        iosSleepThread();
        D_400F2B10 = iosGetTCountExtension();
        D_40045C64++;
        if (vschedGameTimeExec != 0)
        {
            vschedGameTime++;
        }
        tickProcSound(*p);
        iosPadTickProc();
        iosRecvMsg(&D_400F3B50, 0, 0);
    }
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", func_4002CDB0);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", func_4002CE70);
s32 func_4002CE70(void)
{
    iosiWakeupThread(D_400F2B44);
    ExitHandler();
    return 0;
}


/* NEARMISS-STUB func_4002CEA0 */
#if 0 /* NEARMISS 93.02439% cat=volatile-alias sub=- | needs volatile (banned): target loads D_40045C64 via lui+addiu v0,0 then lw 0(v1) (volatile-only form); plain, local s32* ptr, array-index, cast forms all fold  | attempts=1 */
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
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/sched", func_4002CEA0);

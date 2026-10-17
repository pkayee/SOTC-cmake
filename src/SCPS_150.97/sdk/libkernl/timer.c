#include "common.h"

void SetT2(void *reg, unsigned int value);

extern u32 D_00133A18[];

typedef struct TimerCounter
{
    struct TimerCounter *next;
    u32 unk04;
    u32 id;
    u32 flags;
    u64 startTime;
    u64 accum;
    u64 unk20;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
} TimerCounter;

typedef struct TimerTable
{
    u32 unk00;
    u32 unk04;
    s32 intcId;
    u32 unk0C;
    u32 numUsed;
    TimerCounter *freeList;
    TimerCounter *activeList;
    s32 activeId;
} TimerTable;

void func_00110A98(TimerCounter *tc);
int RemoveIntcHandler(int, int);
int DisableIntc(int);
int iSetTimerHandler(int id, u64 ulSchedule, u64 (*cbHandler)(int, u64, u64, void *, void *), void *arg);
void func_00110A10(TimerCounter *tc);
void func_00110880(u64 now);
u64 iGetTimerSystemTime(void);
void SetT2_COMP(unsigned int value);
void SetT2_MODE(unsigned int value);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", SetT2);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", SetT2_COUNT);
void SetT2_COUNT(unsigned int value)
{
    SetT2((void *)0xB0001000, value);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", SetT2_MODE);
void SetT2_MODE(unsigned int value)
{
    SetT2((void *)0xB0001010, value);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", SetT2_COMP);
void SetT2_COMP(unsigned int value)
{
    SetT2((void *)0xB0001020, value);
}

/* NEARMISS-STUB InitTimer */
#if 0 /* NEARMISS 79.5% cat=stack-frame sub=- | target frame 0x60 saves s0-s4; ours 0x40 | attempts=1 */
int InitTimer(int arg)
{
    TimerTable *tt;
    TimerCounter *pool;
    TimerCounter *e;
    u32 nxt;
    int i;
    int id;
    int stat;
    u32 mode;

    tt = (TimerTable *)D_00133A18;
    if (tt->intcId >= 0)
    {
        return 0x80008001;
    }
    *(u64 *)D_00133A18 = 0;
    tt->numUsed = 0;
    pool = (TimerCounter *)D_00148A00;
    tt->freeList = pool;
    memset(pool, 0, 0x2000);
    nxt = (u32)pool + 0x2000;
    e = (TimerCounter *)((u8 *)pool + 0x1FC0);
    for (i = 0x7F; i >= 0; i--)
    {
        e->next = (TimerCounter *)nxt;
        e = (TimerCounter *)((u8 *)e - 0x40);
        nxt -= 0x40;
    }
    pool->next = 0;
    _InitAlarm();
    id = AddIntcHandler2(0xB, func_00110AD0, 0, 0);
    if (id < 0)
    {
        return 0x80009021;
    }
    tt->intcId = id;
    stat = DIntr();
    mode = *(volatile u32 *)0x10001010;
    mode = (mode & 0xFFFFFFFC) | arg;
    mode |= 0x300;
    if (!(mode & 0x80))
    {
        SetT2_COUNT(0);
        mode |= 0xC80;
        SetT2_COMP(0xFFFF);
    }
    SetT2_MODE(mode);
    EnableIntc(0xB);
    if (stat != 0)
    {
        EIntr();
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", InitTimer);

/* NEARMISS-STUB EndTimer */
#if 0 /* NEARMISS 95.2% cat=branch-layout sub=- | bgezl with delay-slot lw vs ours beqz | attempts=1 */
int EndTimer(void)
{
    TimerTable *tt;
    int stat;

    tt = (TimerTable *)D_00133A18;
    if (tt->intcId < 0)
    {
        return 0x80008001;
    }
    if (tt->numUsed != 0)
    {
        return 0x80000010;
    }
    stat = DIntr();
    if (RemoveIntcHandler(0xB, tt->intcId) == 0)
    {
        DisableIntc(0xB);
        SetT2_MODE(0xC00);
        SetT2_COUNT(0);
    }
    *(u64 *)D_00133A18 = 0;
    tt->intcId = -1;
    if (stat != 0)
    {
        EIntr();
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", EndTimer);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", GetTimerPreScaleFactor);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", StartTimerSystemTime);
int StartTimerSystemTime(void)
{
    int stat;
    u32 mode;

    stat = DIntr();
    mode = *(volatile u32 *)0x10001010;
    if (mode & 0x80)
    {
        if (stat != 0)
        {
            EIntr();
        }
        return 1;
    }
    SetT2_MODE((mode & 0xFFFFF3FF) | 0x80);
    func_00110880(iGetTimerSystemTime());
    if (stat != 0)
    {
        EIntr();
    }
    return 0;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", StopTimerSystemTime);
int StopTimerSystemTime(void)
{
    int stat;
    u32 mode;

    stat = DIntr();
    mode = *(volatile u32 *)0x10001010;
    if (!(mode & 0x80))
    {
        if (stat != 0)
        {
            EIntr();
        }
        return 0;
    }
    SetT2_MODE(mode & 0xFFFFF37F);
    if (stat != 0)
    {
        EIntr();
    }
    return 1;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", func_00110880);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", func_00110A10);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", func_00110A98);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", func_00110AD0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iGetTimerSystemTime);

/* NEARMISS-STUB GetTimerSystemTime */
#if 0 /* NEARMISS 59.4% cat=regalloc sub=- | DIntr result kept in v0 in target; ours copies | attempts=1 */
u64 GetTimerSystemTime(void)
{
    int stat;
    u64 count;
    u64 base;
    u32 mode;
    u64 shift;

    stat = DIntr();
    count = *(volatile u32 *)0x10001000;
    mode = *(volatile u32 *)0x10001010;
    base = *(u64 *)D_00133A18;
    shift = 2;
    if (mode & 0x800)
    {
        count = *(volatile u32 *)0x10001000;
        base++;
    }
    mode &= 3;
    base <<= 16;
    if (mode == 0)
    {
        shift = 0;
    }
    count |= base;
    shift <<= mode;
    count <<= shift;
    if (stat != 0)
    {
        EIntr();
    }
    return count;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", GetTimerSystemTime);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iAllocTimerCounter);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", AllocTimerCounter);
int AllocTimerCounter(void)
{
    int stat;
    int ret;

    stat = DIntr();
    ret = iAllocTimerCounter();
    if (stat != 0)
    {
        EIntr();
    }
    return ret;
}

/* NEARMISS-STUB iFreeTimerCounter */
#if 0 /* NEARMISS 97.0% cat=sched sub=- | beqzl with duplicated delay-slot store; ours beqz+nop | attempts=1 */
int iFreeTimerCounter(int id)
{
    TimerCounter *tc;
    TimerTable *tt;
    int ret;

    tc = (TimerCounter *)(((u32)id >> 10) << 6);
    if (id < 0 || ((u32)id & 0x3FF) != tc->id)
    {
        return 0x80008002;
    }
    tt = (TimerTable *)D_00133A18;
    if (tt->activeId == id)
    {
        return 0x80000010;
    }
    if (tc->flags & 2)
    {
        func_00110A98(tc);
    }
    tc->id = 0;
    ret = 0;
    tc->flags = 0;
    tc->next = tt->freeList;
    tt->freeList = tc;
    tt->numUsed--;
    return ret;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iFreeTimerCounter);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", FreeTimerCounter);
int FreeTimerCounter(int id)
{
    int stat;
    int ret;

    stat = DIntr();
    ret = iFreeTimerCounter(id);
    if (stat != 0)
    {
        EIntr();
    }
    return ret;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iGetTimerUsedUnusedCounters);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", GetTimerUsedUnusedCounters);
int GetTimerUsedUnusedCounters(int *pnUsed, int *pnUnused)
{
    int stat;
    int ret;

    stat = DIntr();
    ret = iGetTimerUsedUnusedCounters(pnUsed, pnUnused);
    if (stat != 0)
    {
        EIntr();
    }
    return ret;
}

/* NEARMISS-STUB iStartTimerCounter */
#if 0 /* NEARMISS 97.5% cat=cse-hoist sub=- | D_00133A18+0x1c symbol-offset fold: target lui/lw vs ours lui+addiu+lw | attempts=1 */
int iStartTimerCounter(int id)
{
    TimerCounter *tc;
    u64 now;

    tc = (TimerCounter *)(((u32)id >> 10) << 6);
    if (id < 0 || ((u32)id & 0x3FF) != tc->id)
    {
        return 0x80008002;
    }
    if ((s32)D_00133A18[7] == id)
    {
        return 0x80000010;
    }
    if (tc->flags & 1)
    {
        return 1;
    }
    now = iGetTimerSystemTime();
    tc->startTime = now;
    tc->flags |= 1;
    if (tc->flags & 2)
    {
        func_00110A10(tc);
        func_00110880(now);
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iStartTimerCounter);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", StartTimerCounter);
int StartTimerCounter(int id)
{
    int stat;
    int ret;

    stat = DIntr();
    ret = iStartTimerCounter(id);
    if (stat != 0)
    {
        EIntr();
    }
    return ret;
}

/* NEARMISS-STUB iStopTimerCounter */
#if 0 /* NEARMISS 97.8% cat=cse-hoist sub=- | same D_00133A18+0x1c fold | attempts=1 */
int iStopTimerCounter(int id)
{
    TimerCounter *tc;
    u64 now;
    u32 flags;

    tc = (TimerCounter *)(((u32)id >> 10) << 6);
    if (id < 0 || ((u32)id & 0x3FF) != tc->id)
    {
        return 0x80008002;
    }
    if ((s32)D_00133A18[7] == id)
    {
        return 0x80000010;
    }
    if (!(tc->flags & 1))
    {
        return 0;
    }
    now = iGetTimerSystemTime();
    flags = tc->flags;
    tc->accum += now - tc->startTime;
    tc->flags = flags & 0xFFFFFFFE;
    if (flags & 2)
    {
        func_00110A98(tc);
        func_00110880(now);
    }
    return 1;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iStopTimerCounter);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", StopTimerCounter);
int StopTimerCounter(int id)
{
    int stat;
    int ret;

    stat = DIntr();
    ret = iStopTimerCounter(id);
    if (stat != 0)
    {
        EIntr();
    }
    return ret;
}

/* NEARMISS-STUB SetTimerCount */
#if 0 /* NEARMISS 97.9% cat=cse-hoist sub=- | same D_00133A18+0x1c fold | attempts=1 */
u64 SetTimerCount(int id, u64 ulNewCount)
{
    int stat;
    TimerCounter *tc;
    u64 ret;
    u64 now;
    u64 oldStart;

    tc = (TimerCounter *)(((u32)id >> 10) << 6);
    stat = DIntr();
    if (id < 0 || ((u32)id & 0x3FF) != tc->id || (s32)D_00133A18[7] == id)
    {
        if (stat != 0)
        {
            EIntr();
        }
        return -1;
    }
    ret = tc->accum;
    if (tc->flags & 1)
    {
        now = iGetTimerSystemTime();
        oldStart = tc->startTime;
        tc->accum = ulNewCount;
        tc->startTime = now;
        ret += now - oldStart;
    }
    else
    {
        tc->accum = ulNewCount;
    }
    if (stat != 0)
    {
        EIntr();
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", SetTimerCount);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iGetTimerBaseTime);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", GetTimerBaseTime);
unsigned long GetTimerBaseTime(int id)
{
    int stat;
    unsigned long ret;

    stat = DIntr();
    ret = iGetTimerBaseTime(id);
    if (stat != 0)
    {
        EIntr();
    }
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iGetTimerCount);
u64 iGetTimerCount(int id)
{
    TimerCounter *tc;
    u64 count;
    u64 now;

    tc = (TimerCounter *)(((u32)id >> 10) << 6);
    if (id < 0 || ((u32)id & 0x3FF) != tc->id)
    {
        return -1;
    }
    count = tc->accum;
    if (tc->flags & 1)
    {
        now = iGetTimerSystemTime();
        count += now - tc->startTime;
    }
    return count;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", GetTimerCount);
unsigned long GetTimerCount(int id)
{
    int stat;
    unsigned long ret;

    stat = DIntr();
    ret = iGetTimerCount(id);
    if (stat != 0)
    {
        EIntr();
    }
    return ret;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iSetTimerHandler);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", SetTimerHandler);
int SetTimerHandler(int id, u64 ulSchedule, u64 (*cbHandler)(int, u64, u64, void *, void *), void *arg)
{
    int stat;
    int ret;

    stat = DIntr();
    ret = iSetTimerHandler(id, ulSchedule, cbHandler, arg);
    if (stat != 0)
    {
        EIntr();
    }
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", TimerBusClock2USec);
void TimerBusClock2USec(unsigned long ulClock, unsigned int *puiSec, unsigned int *puiUsec)
{
    int sec;

    sec = ulClock / 147456000;
    if (puiSec != 0)
    {
        *puiSec = sec;
    }
    if (puiUsec != 0)
    {
        *puiUsec = ((ulClock - (unsigned long)(unsigned int)sec * 147456000) * 1000000) / 147456000;
    }
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", TimerUSec2BusClock);
unsigned long TimerUSec2BusClock(unsigned int uiSec, unsigned int uiUsec)
{
    return (unsigned long)uiSec * 147456000 + ((unsigned long)uiUsec * 147456000) / 1000000;
}

/* NEARMISS-STUB TimerBusClock2Freq */
#if 0 /* NEARMISS 90.0% cat=sched sub=- | mtc1/div.s nop scheduling | attempts=1 */
float TimerBusClock2Freq(unsigned long ulClock)
{
    return 147456000.0f / (float)ulClock;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", TimerBusClock2Freq);

/* NEARMISS-STUB TimerFreq2BusClock */
#if 0 /* NEARMISS 72.0% cat=sched sub=- | mtc1/div.s nop hazard scheduling vs jal delay slot | attempts=1 */
unsigned long TimerFreq2BusClock(float fFreq)
{
    return (unsigned long)(147456000.0f / fFreq);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", TimerFreq2BusClock);

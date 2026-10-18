#include "common.h"

void SetT2(void *reg, unsigned int value);

extern u32 D_00133A18[];

typedef struct TimerCounter
{
    struct TimerCounter *next;
    u32 unk04;
    volatile u32 id;
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
#if 0 /* NEARMISS 79.5% cat=stack-frame sub=- | frame 0x60 (s0-s4 saved) vs ours smaller; D_00148A00 and func_00110AD0 need extern decls (added inside stub); store/regalloc of pool/tt same 79.5 | attempts=2 */
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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", EndTimer);
int EndTimer(void)
{
    int stat;

    if (((volatile TimerTable *)D_00133A18)->intcId < 0)
    {
        return 0x80008001;
    }
    if (((volatile TimerTable *)D_00133A18)->numUsed != 0)
    {
        return 0x80000010;
    }
    stat = DIntr();
    if (RemoveIntcHandler(0xB, ((volatile TimerTable *)D_00133A18)->intcId) == 0)
    {
        DisableIntc(0xB);
        SetT2_MODE(0xC00);
        SetT2_COUNT(0);
    }
    *(u64 *)D_00133A18 = 0;
    ((TimerTable *)D_00133A18)->intcId = -1;
    if (stat != 0)
    {
        EIntr();
    }
    return 0;
}


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

/* NEARMISS-STUB func_00110880 */
#if 0 /* NEARMISS 93.55% cat=branch-layout sub=- | loop shape: target tests exit with beqzl and back-edge b; ours bnezl; cursor/now copy scheduling differs (now in a3 early in target); single-cursor loop gets 93 | attempts=1 */
void func_00110880(u64 now)
{
    TimerTable *tt;
    TimerCounter *p;
    u64 cmp;
    u64 k;
    u32 mode;
    u32 shift;

    tt = (TimerTable *)D_00133A18;
    p = tt->activeList;
    if (tt->activeId >= 0)
    {
        return;
    }
    mode = *(volatile u32 *)0x10001010;
    if (p == NULL)
    {
        SetT2_COMP(0);
        SetT2_MODE(mode & 0xFFFFF7FF);
        return;
    }
    cmp = p->unk20 + p->startTime - p->accum;
    for (;;)
    {
        p = p->next;
        if (p == NULL)
        {
            break;
        }
        k = p->unk20 + p->startTime - p->accum;
        if (k >= cmp + 0x7333)
        {
            break;
        }
        cmp = k;
    }
    shift = mode & 3;
    if ((s64)(cmp - now) < 0x7333)
    {
        SetT2_COMP(*(volatile u32 *)0x10001000 + (u32)((u64)0x7333 >> (shift * 4)));
        SetT2_MODE(mode & 0xFFFFF7FF);
        return;
    }
    SetT2_MODE(mode & 0xFFFFF7FF);
    SetT2_COMP((u32)(cmp >> (shift * 4)));
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", func_00110880);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", func_00110A10);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", func_00110A98);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", func_00110AD0);

#if 0 /* NEARMISS 20.7% cat=bitops sub=ee-gcc2.9-991111 | 64-bit variable shift expression form (t2<<=16, v0<<=t1 as dsllv) codegen differs under ee-gcc2.9-991111; prior tag sdk-compiler | attempts=1 */
u64 iGetTimerSystemTime(void)
{
    u64 v0;
    s32 t0;
    s32 t1;
    u64 t2;

    v0 = *(volatile u32 *)0x10001000;
    t0 = *(volatile u32 *)0x10001010;
    t2 = *(u64 *)0x00133A18;
    t1 = 2;
    if (t0 & 0x800)
    {
        v0 = *(volatile u32 *)0x10001000;
        t2++;
    }
    t0 &= 3;
    t2 <<= 16;
    if (t0 == 0)
    {
        t1 = 0;
    }
    v0 |= t2;
    t1 <<= t0;
    v0 <<= t1;
    return v0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iGetTimerSystemTime);

/* NEARMISS-STUB GetTimerSystemTime */
#if 0 /* NEARMISS 59.5% cat=regalloc sub=- | lwu zero-extend load: target loads count with lwu straight into s0 (and reloads in the if), ours lw+dsll32/dsrl32; volatile/non-volatile mix tried (42-59%); DIn | attempts=2 */
u64 GetTimerSystemTime(void)
{
    int stat;
    u64 count;
    u64 base;
    u32 mode;
    u64 shift;

    stat = DIntr();
    count = ((volatile u32 *)0x10001000)[0];
    mode = ((volatile u32 *)0x10001000)[4];
    base = *(u64 *)D_00133A18;
    shift = 2;
    if (mode & 0x800)
    {
        count = ((volatile u32 *)0x10001000)[0];
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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iFreeTimerCounter);
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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iStartTimerCounter);
int iStartTimerCounter(int id)
{
    TimerCounter *tc;
    u64 now;

    tc = (TimerCounter *)(((u32)id >> 10) << 6);
    if (id < 0 || ((u32)id & 0x3FF) != tc->id)
    {
        return 0x80008002;
    }
    if (((volatile TimerTable *)D_00133A18)->activeId == id)
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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", iStopTimerCounter);
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
    if (((volatile TimerTable *)D_00133A18)->activeId == id)
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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", SetTimerCount);
u64 SetTimerCount(int id, u64 ulNewCount)
{
    int stat;
    TimerCounter *tc;
    u64 ret;
    u64 now;
    u64 oldStart;

    tc = (TimerCounter *)(((u32)id >> 10) << 6);
    stat = DIntr();
    if (id < 0 || ((u32)id & 0x3FF) != tc->id || ((volatile TimerTable *)D_00133A18)->activeId == id)
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

/* NEARMISS-STUB iSetTimerHandler */
#if 0 /* NEARMISS 94.5% cat=no-c-form sub=- | target stores gp register (sw $gp,0x2C) = no C form; placeholder tc->unk2C=0 used here; also s2/s3 regalloc swapped (ulSchedule/arg); store-order variants no ch | attempts=1 */
int iSetTimerHandler(int id, u64 ulSchedule, u64 (*cbHandler)(int, u64, u64, void *, void *), void *arg)
{
    TimerCounter *tc;
    u32 flags;

    tc = (TimerCounter *)(((u32)id >> 10) << 6);
    if (id < 0 || ((u32)id & 0x3FF) != tc->id)
    {
        return 0x80008002;
    }
    if (((volatile TimerTable *)D_00133A18)->activeId == id)
    {
        return 0x80000010;
    }
    flags = tc->flags;
    if (flags & 2)
    {
        func_00110A98(tc);
        flags = tc->flags;
    }
    tc->unk28 = (u32)cbHandler;
    if (cbHandler == 0)
    {
        tc->flags = flags & ~2;
    }
    else
    {
        tc->flags = flags | 2;
        tc->unk20 = ulSchedule;
        tc->unk2C = 0;
        tc->unk30 = (u32)arg;
        if (tc->flags & 1)
        {
            func_00110A10(tc);
        }
    }
    func_00110880(iGetTimerSystemTime());
    return 0;
}
#endif
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
#if 0 /* NEARMISS 90.0% cat=sched sub=- | unsigned long->float 2.9 expansion matches; target has 2 hazard nops after ld ra before div.s, ours none; k-local variant no change | attempts=1 */
float TimerBusClock2Freq(unsigned long ulClock)
{
    return 147456000.0f / (float)ulClock;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", TimerBusClock2Freq);

/* NEARMISS-STUB TimerFreq2BusClock */
#if 0 /* NEARMISS 72.3% cat=sched sub=- | mtc1/div.s: target has 2 nops between sd ra and div.s, ours none; jal __fixunssfdi tail matches; local-temp/order variants no change | attempts=2 */
unsigned long TimerFreq2BusClock(float fFreq)
{
    float c;
    c = 147456000.0f;
    return (unsigned long)(c / fFreq);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/timer", TimerFreq2BusClock);

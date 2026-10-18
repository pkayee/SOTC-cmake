#include "common.h"

typedef struct AlarmNode
{
    s32 next;
    s32 field4;
    s32 (*handler)(s32, s32, s32, void *);
    void *arg;
} AlarmNode;

extern s32 D_0014AE00[];
s32 iFreeTimerCounter(s32 id);
int DIntr(void);
int EIntr(void);
s32 FreeTimerCounter(s32 id);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarmtimer", _InitAlarm);

/* NEARMISS-STUB func_00111850 */
#if 0 /* NEARMISS 95.17% cat=delay-slot-epilogue sub=- | s32 next / s32 D_0014AE00[] typing sets addiu/lw order (76.9->95.2); target keeps an explicit ld ra in the zero path (dup epilogue), ours folds it into the bnez delay slot; ret=-1 variable form 82.6 | attempts=6 */
typedef struct AlarmNode
{
    s32 next;
    s32 field4;
    s32 (*handler)(s32, s32, s32, void *);
    void *arg;
} AlarmNode;

extern s32 D_0014AE00[];

s32 func_00111850(s32 a0, s32 a1, s32 a2, AlarmNode *a3)
{
    s32 head;
    s32 ret;

    ret = a3->handler(((u32)a3 << 4) | (a0 & 0xFE) | 1, a1, a2, a3->arg);
    if (ret == 0)
    {
        head = D_0014AE00[0];
        D_0014AE00[0] = (s32)a3;
        a3->next = head;
        a3->field4 = 0;
        return -1;
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarmtimer", func_00111850);


/* NEARMISS-STUB SetTimerAlarm */
#if 0 /* NEARMISS 97.8% cat=branch-layout sub=inline-pop-helper | inline AllocAlarmNode pop helper: 89.5->97.8 | attempts=2 */
/* 2.9: free-list pop as static inline AllocAlarmNode(): 89.5 -> 97.8. */
typedef struct AlarmNode
{
    struct AlarmNode *next;
    s32 field4;
    void *handler;
    void *arg;
} AlarmNode;

extern AlarmNode *D_0014AE00[];
s32 iAllocTimerCounter(void);
s32 iSetTimerHandler(s32 id, u32 clock, void *handler, void *arg);
s32 iStartTimerCounter(s32 id);
s32 func_00111850(s32 a0, s32 a1, s32 a2, AlarmNode *a3);

s32 AllocTimerCounter(void);
s32 SetTimerHandler(s32 id, u32 clock, void *handler, void *arg);
s32 StartTimerCounter(s32 id);
int DIntr(void);
int EIntr(void);

static inline AlarmNode *AllocAlarmNode(void)
{
    AlarmNode *node = D_0014AE00[0];

    if (node != NULL)
    {
        D_0014AE00[0] = node->next;
    }
    return node;
}

s32 SetTimerAlarm(u32 ulClock, u32 (*cbHandler)(s32, u32, u32, void *, void *), void *arg)
{
    AlarmNode *node;
    AlarmNode *head;
    s32 intr;
    s32 id;

    if (cbHandler == NULL)
    {
        return 0x80000016;
    }
    intr = DIntr();
    node = AllocAlarmNode();
    if (node == NULL)
    {
        if (intr != 0)
        {
            EIntr();
        }
        return 0x80008005;
    }
    id = AllocTimerCounter();
    if (id < 0)
    {
        head = D_0014AE00[0];
        D_0014AE00[0] = node;
        node->next = head;
        node->field4 = 0;
        if (intr != 0)
        {
            EIntr();
        }
        return id;
    }
    node->handler = cbHandler;
    node->arg = arg;
    node->field4 = id;
    SetTimerHandler(id, ulClock, func_00111850, node);
    StartTimerCounter(id);
    if (intr != 0)
    {
        EIntr();
    }
    return (((u32)node << 4) | ((u32)id & 0xFE) | 1);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarmtimer", SetTimerAlarm);

/* NEARMISS-STUB iSetTimerAlarm */
#if 0 /* NEARMISS 97.25% cat=branch-layout sub=inline-pop-helper | free-list pop is an inline helper (separate null tests, no threading): 88.6->97.25; error-path delay slot left | attempts=2 */
/* 2.9: free-list pop as a static inline AllocAlarmNode() (keeps the separate `if (node) pop; if (!node) fail` tests, no jump threading): 88.6 -> 97.25; left: error-path delay slot (sw field4 vs ld ra). Needs AlarmNode typedef + protos (see func_00111850 stub). */
typedef struct AlarmNode
{
    struct AlarmNode *next;
    s32 field4;
    void *handler;
    void *arg;
} AlarmNode;

extern AlarmNode *D_0014AE00[];
s32 iAllocTimerCounter(void);
s32 iSetTimerHandler(s32 id, u32 clock, void *handler, void *arg);
s32 iStartTimerCounter(s32 id);
s32 func_00111850(s32 a0, s32 a1, s32 a2, AlarmNode *a3);

static inline AlarmNode *AllocAlarmNode(void)
{
    AlarmNode *node = D_0014AE00[0];

    if (node != NULL)
    {
        D_0014AE00[0] = node->next;
    }
    return node;
}

static inline void FreeAlarmNode(AlarmNode *node)
{
    AlarmNode *head = D_0014AE00[0];

    D_0014AE00[0] = node;
    node->next = head;
    node->field4 = 0;
}

s32 iSetTimerAlarm(u32 ulClock, u32 (*cbHandler)(s32, u32, u32, void *, void *), void *arg)
{
    AlarmNode *node;
    AlarmNode *head;
    s32 id;

    if (cbHandler == NULL)
    {
        return 0x80000016;
    }
    node = AllocAlarmNode();
    if (node == NULL)
    {
        return 0x80008005;
    }
    id = iAllocTimerCounter();
    if (id < 0)
    {
        FreeAlarmNode(node);
        return id;
    }
    node->handler = cbHandler;
    node->arg = arg;
    node->field4 = id;
    iSetTimerHandler(id, ulClock, func_00111850, node);
    iStartTimerCounter(id);
    return (((u32)node << 4) | ((u32)id & 0xFE) | 1);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarmtimer", iSetTimerAlarm);

s32 ReleaseTimerAlarm(s32 id)
{
    AlarmNode *node;
    AlarmNode *head;
    s32 intr;

    node = (AlarmNode *)((((u32)id) >> 8) << 4);
    intr = DIntr();
    if (id < 0 || ((id ^ ((volatile AlarmNode *)node)->field4) & 0xFF) != 0)
    {
        if (intr != 0)
        {
            EIntr();
        }
        return 0x80008002;
    }
    FreeTimerCounter(((volatile AlarmNode *)node)->field4);
    head = (AlarmNode *)D_0014AE00[0];
    D_0014AE00[0] = (s32)node;
    node->next = (s32)head;
    ((volatile AlarmNode *)node)->field4 = 0;
    if (intr != 0)
    {
        EIntr();
    }
    return 0;
}

s32 iReleaseTimerAlarm(s32 id)
{
    AlarmNode *node;
    s32 head;
    s32 ret;

    node = (AlarmNode *)((((u32)id) >> 8) << 4);
    if (id < 0 || ((id ^ ((volatile AlarmNode *)node)->field4) & 0xFF) != 0)
    {
        return 0x80008002;
    }
    ret = iFreeTimerCounter(((volatile AlarmNode *)node)->field4);
    if (ret == 0)
    {
        head = D_0014AE00[0];
        D_0014AE00[0] = (s32)node;
        node->next = head;
        node->field4 = 0;
    }
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarmtimer", sceSifInitRebootNotify);

extern s32 D_00133A38[];
extern s32 D_00133A3C[];
extern u8 D_0014AE08[];

void sceSifInitRebootNotify(void)
{
    D_00133A38[0] = 0;
    D_00133A3C[0] = 0;
    memset(D_0014AE08, 0, 0x200);
}


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarmtimer", sceSifSetRebootNotifyBuffer);
void *sceSifSetRebootNotifyBuffer(void *buf, s32 size)
{
    s32 intr;
    void *old;

    intr = DIntr();
    old = (void *)D_00133A38[0];
    D_00133A38[0] = (s32)buf;
    D_00133A3C[0] = size;
    memset(buf, 0, size << 4);
    if (intr != 0)
    {
        EIntr();
    }
    return old;
}


INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarmtimer", sceSifAddRebootNotifyHandler);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarmtimer", sceSifRemoveRebootNotifyHandler);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarmtimer", sceSifExecNotifyHandler);

#include "common.h"

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarmtimer", _InitAlarm);

/* NEARMISS-STUB func_00111850 */
#if 0 /* NEARMISS 76.9% cat=branch-layout sub=- | ret!=0 path: target reloads ra in zero path (dup epilogue); store order head/next/field4 and addiu -1 placement differ | attempts=1 */
typedef struct AlarmNode
{
    struct AlarmNode *next;
    s32 field4;
    s32 (*handler)(s32, s32, s32, void *);
    void *arg;
} AlarmNode;

extern AlarmNode *D_0014AE00[];

s32 func_00111850(s32 a0, s32 a1, s32 a2, AlarmNode *a3)
{
    AlarmNode *head;
    s32 ret;

    ret = a3->handler(((u32)a3 << 4) | (a0 & 0xFE) | 1, a1, a2, a3->arg);
    if (ret == 0)
    {
        head = D_0014AE00[0];
        D_0014AE00[0] = a3;
        a3->next = head;
        a3->field4 = 0;
        return -1;
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarmtimer", func_00111850);

/* NEARMISS-STUB SetTimerAlarm */
#if 0 /* NEARMISS 89.5% cat=branch-layout sub=- | DIntr-wrapped free-list pop: target conditional pop branch and push-back ordering differ | attempts=1 */
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
    node = D_0014AE00[0];
    if (node == NULL)
    {
        if (intr != 0)
        {
            EIntr();
        }
        return 0x80008005;
    }
    D_0014AE00[0] = node->next;
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
#if 0 /* NEARMISS 88.6% cat=branch-layout sub=- | free-list pop: target uses beqz skip-pop branch; ours emits bnezl (pop in delay slot) | attempts=1 */
s32 iSetTimerAlarm(u32 ulClock, u32 (*cbHandler)(s32, u32, u32, void *, void *), void *arg)
{
    AlarmNode *node;
    AlarmNode *head;
    s32 id;

    if (cbHandler == NULL)
    {
        return 0x80000016;
    }
    node = D_0014AE00[0];
    if (node == NULL)
    {
        return 0x80008005;
    }
    D_0014AE00[0] = node->next;
    id = iAllocTimerCounter();
    if (id < 0)
    {
        head = D_0014AE00[0];
        D_0014AE00[0] = node;
        node->next = head;
        node->field4 = 0;
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

/* NEARMISS-STUB ReleaseTimerAlarm */
#if 0 /* NEARMISS 34.9% cat=regalloc sub=- | DIntr result and id held across call; saved-reg order s0/s1/s2 and node computed after DIntr differ | attempts=1 */
s32 ReleaseTimerAlarm(s32 id)
{
    AlarmNode *node;
    AlarmNode *head;
    s32 intr;
    s32 ret;

    intr = DIntr();
    node = (AlarmNode *)((((u32)id) >> 8) << 4);
    if (id >= 0 && ((id ^ node->field4) & 0xFF) == 0)
    {
        FreeTimerCounter(node->field4);
        head = D_0014AE00[0];
        D_0014AE00[0] = node;
        node->next = head;
        node->field4 = 0;
        ret = 0;
    }
    else
    {
        ret = 0x80008002;
    }
    if (intr != 0)
    {
        EIntr();
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarmtimer", ReleaseTimerAlarm);

/* NEARMISS-STUB iReleaseTimerAlarm */
#if 0 /* NEARMISS 62.3% cat=branch-layout sub=- | target reloads node->field4 for FreeTimerCounter arg (no CSE) and uses bnez shape; prologue order differs | attempts=1 */
s32 iReleaseTimerAlarm(s32 id)
{
    AlarmNode *node;
    AlarmNode *head;
    s32 ret;

    if (id < 0)
    {
        return 0x80008002;
    }
    node = (AlarmNode *)((((u32)id) >> 8) << 4);
    if (((id ^ node->field4) & 0xFF) != 0)
    {
        return 0x80008002;
    }
    ret = iFreeTimerCounter(node->field4);
    if (ret == 0)
    {
        head = D_0014AE00[0];
        D_0014AE00[0] = node;
        node->next = head;
        node->field4 = 0;
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarmtimer", iReleaseTimerAlarm);

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


/* NEARMISS-STUB sceSifSetRebootNotifyBuffer */
#if 0 /* NEARMISS 98.9% cat=regalloc sub=- | lui register choice swapped (target lui v1 for D_00133A38, a1 for D_00133A3C); otherwise identical | attempts=1 */
void *sceSifSetRebootNotifyBuffer(void *buf, s32 size)
{
    s32 intr;
    void *old;

    intr = DIntr();
    old = (void *)D_00133A38[0];
    D_00133A3C[0] = size;
    D_00133A38[0] = (s32)buf;
    memset(buf, 0, size << 4);
    if (intr != 0)
    {
        EIntr();
    }
    return old;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarmtimer", sceSifSetRebootNotifyBuffer);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarmtimer", sceSifAddRebootNotifyHandler);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarmtimer", sceSifRemoveRebootNotifyHandler);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/alarmtimer", sceSifExecNotifyHandler);

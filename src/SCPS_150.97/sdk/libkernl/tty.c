#include "common.h"

typedef struct TtyQueue
{
    s32 size;       /* 0x00 */
    s32 count;      /* 0x04 */
    u8 *rd;         /* 0x08 */
    u8 *wr;         /* 0x0C */
    u8 data[0x100]; /* 0x10 */
} TtyQueue;

typedef struct TtyCtl
{
    s32 handle;     /* 0x00 */
    s32 wrLen;      /* 0x04 */
    s32 rdCnt;      /* 0x08 */
    s32 wrBusy;     /* 0x0C */
    u8 *wrBuf;      /* 0x10 */
    u8 *rdBuf;      /* 0x14 */
    TtyQueue *queue; /* 0x18 */
} TtyCtl;

typedef struct TtyPacket
{
    u16 len;        /* 0x00 */
    u16 unk02;      /* 0x02 */
    u16 proto;      /* 0x04 */
    u8 kind;        /* 0x06 */
    u8 type;        /* 0x07 */
    s32 unk08;      /* 0x08 */
} TtyPacket;

extern TtyCtl D_0014B150[];
extern TtyQueue *D_0014B168[];
extern u8 D_0014B180[];
extern u8 D_0014B2C0[];
extern TtyQueue D_0014B040;
extern char D_00138378[];
extern char D_001383A0[];
extern char D_001383B8[];
extern char D_001383D0[];

void *QueueInit(s32 size);
void QueuePeekReadDone(TtyQueue *q);
void sceTtyHandler(s32 event, s32 param, void *opt);
void FlushCache(s32 op);
s32 kprintf(const char *fmt, ...);
s32 DIntr(void);
s32 EIntr(void);
s32 sceDeci2ReqSend(s32 s, s8 dest);
void sceDeci2Poll(s32 s);
s32 sceDeci2Open(u16 protocol, void *opt, void (*handler)(s32, s32, void *));

void *QueueInit(s32 size)
{
    TtyQueue *q = &D_0014B040;

    q->size = size;
    q->count = 0;
    q->wr = q->data;
    q->rd = q->data;
    return q;
}

void QueuePeekWriteDone(TtyQueue *q)
{
    q->count = q->count + 1;
    q->wr = q->wr + 1;
    if (q->wr == q->data + q->size)
    {
        q->wr = q->data;
    }
}

void QueuePeekReadDone(TtyQueue *q)
{
    q->count = q->count - 1;
    q->rd = q->rd + 1;
    if (q->rd == q->data + q->size)
    {
        q->rd = q->data;
    }
}

/* NEARMISS-STUB sceTtyHandler */
#if 0 /* NEARMISS 45.0% cat=regalloc sub=- | switch-form gets close; target has opt in s1/param in s0 (we swap), event==3 block laid out last, param!=0 recv/loop block order and 0x80-frame differences unre | attempts=1 */
void sceTtyHandler(s32 event, s32 param, void *opt)
{
    TtyCtl *ctl;
    TtyPacket *pkt;
    s32 i;
    s32 n;

    ctl = (TtyCtl *)opt;
    switch (event)
    {
    case 3:
        n = sceDeci2ExSend(ctl->handle, ctl->wrBuf, (u16)ctl->wrLen);
        if (n < 0)
        {
            kprintf(D_001383B8);
            ctl->wrBusy = 0;
        }
        else
        {
            ctl->wrBuf = ctl->wrBuf + n;
            ctl->wrLen = ctl->wrLen - n;
        }
        break;
    case 1:
    case 2:
        if (param == 0)
        {
            pkt = (TtyPacket *)ctl->rdBuf;
            for (i = 12; i < pkt->len; i++)
            {
                *ctl->queue->wr = ((u8 *)pkt)[i];
                QueuePeekWriteDone(ctl->queue);
            }
            ctl->rdCnt = 0;
        }
        else
        {
            if ((u32)(ctl->rdCnt + param) >= 0x141)
            {
                kprintf(D_00138378);
            }
            n = sceDeci2ExRecv(ctl->handle, ctl->rdBuf + ctl->rdCnt, (u16)param);
            if (n < 0)
            {
                kprintf(D_001383A0);
            }
            ctl->rdCnt = ctl->rdCnt + n;
        }
        break;
    case 4:
        if (ctl->wrLen != 0)
        {
            kprintf(D_001383D0, ctl->wrLen);
        }
        ctl->wrBusy = 0;
        break;
    }
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tty", sceTtyHandler);

/* NEARMISS-STUB sceTtyWrite */
#if 0 /* NEARMISS 73.9% cat=regalloc sub=- | frame 0x70 vs 0x80: target keeps 7 saved regs (intr in s6, cnt in s1, hi base s5); loop exit delay slot and wrLen reload differ; loop counter/pointer allocation | attempts=1 */
s32 sceTtyWrite(u8 *buf, s32 len)
{
    s32 cnt;
    s32 n;
    s32 intr;
    TtyPacket *pkt;
    u8 *dst;

    if (D_0014B150[0].wrBusy != 0)
    {
        return -1;
    }
    intr = DIntr();
    D_0014B150[0].wrBusy = 1;
    pkt = (TtyPacket *)((u32)D_0014B180 | 0x20000000);
    D_0014B150[0].wrBuf = (u8 *)pkt;
    dst = (u8 *)pkt + 0xC;
    cnt = 0;
    n = 0;
    while (len-- != 0)
    {
        if (*(s8 *)buf == '\n')
        {
            *dst++ = '\r';
            cnt++;
            if (cnt >= 0x100)
            {
                break;
            }
        }
        *dst++ = *buf++;
        cnt++;
        n++;
        if (cnt >= 0x100)
        {
            break;
        }
    }
    D_0014B150[0].wrLen = cnt + 0xC;
    pkt->len = ((TtyCtl *)D_0014B150)->wrLen;
    if (sceDeci2ReqSend(D_0014B150[0].handle, pkt->type) < 0)
    {
        D_0014B150[0].wrBusy = 0;
        if (intr != 0)
        {
            EIntr();
        }
        return -1;
    }
    while (D_0014B150[0].wrBusy != 0)
    {
        sceDeci2Poll(D_0014B150[0].handle);
    }
    if (intr != 0)
    {
        EIntr();
    }
    return n;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tty", sceTtyWrite);

/* NEARMISS-STUB sceTtyRead */
#if 0 /* NEARMISS 91.73% cat=volatile-alias sub=- | needs the banned qualifier: target re-loads D_0014B168[0]->count inside the poll loop (lw in loop); plain C hoists count load out of loop, loop becomes beqz sel | attempts=1 */
s32 sceTtyRead(u8 *buf, s32 len)
{
    s32 i;
    s32 n;
    u8 *dst;
    s8 c;

    for (i = 0; i < len; i = n)
    {
        dst = buf + i;
        n = i + 1;
        while (D_0014B168[0]->count == 0)
            ;
        *dst = *D_0014B150[0].queue->rd;
        QueuePeekReadDone(D_0014B150[0].queue);
        c = *(s8 *)dst;
        if (c == '\n' || c == '\r')
        {
            return n;
        }
    }
    return i;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tty", sceTtyRead);

/* NEARMISS-STUB sceTtyInit */
#if 0 /* NEARMISS 81.1% cat=regalloc sub=- | store order/delay slot: target hoists lui D_0014B2C0 into bgez delay slot, buf in v0 not v1, unk08 store before jal and unk02 in delay slot (we swap); source or | attempts=1 */
s32 sceTtyInit(void)
{
    TtyCtl *ctl;
    TtyPacket *pkt;
    u8 *buf;

    FlushCache(0);
    D_0014B150[0].handle = sceDeci2Open(0x210, &D_0014B150[0], sceTtyHandler);
    if (((TtyCtl *)D_0014B150)->handle < 0)
    {
        return 0;
    }
    ctl = &D_0014B150[0];
    buf = (u8 *)((u32)D_0014B180 | 0x20000000);
    ctl->wrBusy = 0;
    ctl->wrLen = 0;
    ctl->rdCnt = 0;
    ctl->rdBuf = (u8 *)((u32)D_0014B2C0 | 0x20000000);
    ctl->wrBuf = buf;
    pkt = (TtyPacket *)buf;
    pkt->proto = 0x210;
    pkt->kind = 0x45;
    pkt->type = 0x48;
    pkt->unk08 = 0;
    pkt->unk02 = 0;
    ctl->queue = QueueInit(0x100);
    return 1;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tty", sceTtyInit);

void func_001129A0(s32 *a0, s32 *a1)
{
    ((s32 *)a1[7])[a0[4]] = a0[5];
}

void func_001129C0(s32 *a0, s32 *a1)
{
    a1[2] = a0[4];
}

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

void *QueueInit(s32 size);
void QueuePeekReadDone(TtyQueue *q);
void sceTtyHandler(s32 event, s32 param, void *opt);

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

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tty", sceTtyHandler);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tty", sceTtyWrite);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tty", sceTtyRead);
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
        while (((volatile TtyQueue *)D_0014B168[0])->count == 0)
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

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/tty", sceTtyInit);

void func_001129A0(s32 *a0, s32 *a1)
{
    ((s32 *)a1[7])[a0[4]] = a0[5];
}

void func_001129C0(s32 *a0, s32 *a1)
{
    a1[2] = a0[4];
}

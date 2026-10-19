#include "common.h"
#include "sdk/ee/sifrpc.h"
#include "sdk/ee/eekernel.h"
#include "sdk/ee/sif.h"

extern s32 D_00145AC0[];

/* NEARMISS-STUB sceSifInitRpc */
#if 0 /* NEARMISS 86.9% cat=regalloc sub=- | tail j sceSifSetReg fixed (early return + void proto); rest: lui/addiu base-reg order and a2v/a3v/q store scheduling differ; q 82.7, q[0] also | attempts=2 */
extern s32 D_00132388[];
extern s32 D_001442C0[];
extern s32 D_00144AC0[];
extern s32 D_001452C0[];
void func_001093F8(void *a0, void *a1);
void func_001099F0(void *a0, void *a1);
void func_001097D0(s32 *a0, void *a1);
void func_00109508(s32 *a0, s32 *a1);
void sceSifSetReg(u32 a0, s32 a1);

void sceSifInitRpc(unsigned int mode)
{
    s32 *q;
    s32 *tbl;
    s32 *r;
    s32 a2v;
    s32 a3v;
    s32 s2v;

    DIntr();
    if (D_00132388[0] != 0)
    {
        EIntr();
        return;
    }
    D_00132388[0] = 1;
    EIntr();
    sceSifInitCmd();
    DIntr();
    tbl = D_001442C0;
    q = D_00145AC0;
    a2v = (s32)D_00144AC0 | 0x20000000;
    a3v = (s32)D_001452C0 | 0x20000000;
    q[8] = 0x20;
    s2v = (s32)tbl | 0x20000000;
    D_00145AC0[0] = 1;
    q[5] = a2v;
    q[1] = s2v;
    q[7] = a3v;
    q[2] = 0x20;
    q[3] = 0;
    q[4] = 0;
    q[6] = 0x20;
    q[9] = 0;
    sceSifAddCmdHandler(0x80000008, func_001093F8, q);
    sceSifAddCmdHandler(0x80000009, func_001097D0, q);
    sceSifAddCmdHandler(0x8000000A, func_001099F0, q);
    sceSifAddCmdHandler(0x8000000C, func_00109508, q);
    EIntr();
    if (sceSifGetReg(0x80000002) != 0)
    {
        return;
    }
    r = tbl + 16;
    r[3] = 1;
    sceSifSendCmd(0x80000002, r, 0x10, 0, 0, 0);
    while (sceSifGetSreg(0) == 0)
    {
    }
    sceSifSetReg(0x80000002, 1);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", sceSifInitRpc);

extern s32 D_00132388[];

void sceSifExitCmd(void);

void sceSifExitRpc(void)
{
    sceSifExitCmd();
    D_00132388[0] = 0;
}

void *func_001092C0(s32 *obj)
{
    s32 *elem;
    s32 i;
    s32 id;
    s32 n;
    s32 t;

    DIntr();
    elem = (s32 *)obj[1];
    for (i = 0; i < obj[2]; i++, elem += 16)
    {
        if ((elem[4] & 1) == 0)
        {
            elem[4] = (i << 16) | 5;
            n = obj[0];
            t = n + 1;
            obj[0] = t;
            if (t == 1)
            {
                obj[0] = n + 2;
                id = 1;
            }
            else
            {
                id = t;
            }
            elem[5] = (s32)elem;
            elem[6] = id;
            EIntr();
            return elem;
        }
    }
    EIntr();
    return 0;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", func_00109368);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", func_00109388);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", func_001093B8);

void *func_00109388(s32 *a0);

void *func_001093B8(s32 *a0, s32 a1)
{
    if (a1 < 0 || a1 >= a0[8])
    {
        return func_00109388(a0);
    }
    return (void *)(a0[7] + (a1 << 6));
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", func_001093F8);

u_long func_001094C8(int a0, u_long a1, u_long a2, void *a3, void *a4)
{
    s32 *s;

    s = (s32 *)a3;
    return isceSifSendCmd(0x80000008, s, 0x40, (void *)s[9], (void *)s[10], s[11]) ? 0 : 0x800;
}

void func_00109508(s32 *a0, s32 *a1)
{
    s32 *s0;
    s32 t14;
    s32 t1c;

    if (a0[4] & 4)
    {
        s0 = func_001093B8(a1, (u32)a0[4] >> 16);
    }
    else
    {
        s0 = func_00109388(a1);
    }
    t14 = a0[5];
    t1c = a0[7];
    s0[5] = t14;
    s0[7] = t1c;
    s0[8] = 0x8000000C;
    s0[9] = a0[8];
    s0[10] = a0[9];
    s0[11] = a0[10];
    if (isceSifSendCmd(0x80000008, s0, 0x40, (void *)a0[8], (void *)a0[9], a0[10]) == 0)
    {
        iSetTimerAlarm(0x800, func_001094C8, s0);
    }
}
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", func_00109508);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", sceSifGetOtherData);

extern s32 D_00137FA8[];
void *func_001092C0(s32 *a0);
void func_00109368(void *a0);

int sceSifGetOtherData(sceSifReceiveData *client, void *src, void *dest, int size, unsigned int mode)
{
    s32 *rec;
    struct SemaParam sparam;
    int sema;

    rec = (s32 *)func_001092C0(D_00145AC0);
    if (rec == NULL)
    {
        return -1;
    }
    client->rpcd.paddr = rec;
    client->rpcd.pid = rec[6];
    rec[8] = (s32)src;
    rec[9] = (s32)dest;
    rec[10] = size;
    rec[5] = (s32)rec;
    rec[7] = (s32)client;
    if (!(mode & 1))
    {
        sparam.maxCount = 1;
        sparam.option = (u_int)D_00137FA8;
        sparam.initCount = 0;
        sema = CreateSema(&sparam);
        client->rpcd.tid = sema;
        if (sema < 0)
        {
            func_00109368(rec);
            return -3;
        }
        if (sceSifSendCmd(0x8000000C, rec, 0x40, 0, 0, 0) == 0)
        {
            func_00109368(rec);
            DeleteSema(client->rpcd.tid);
            return -2;
        }
        WaitSema(client->rpcd.tid);
        DeleteSema(client->rpcd.tid);
        return 0;
    }
    client->rpcd.tid = -1;
    if (sceSifSendCmd(0x8000000C, rec, 0x40, 0, 0, 0) != 0)
    {
        return 0;
    }
    func_00109368(rec);
    return -2;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", func_00109740);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", func_00109790);

s32 func_00109790(s32 a0, s32 a1, s32 a2, void *a3)
{
    if (isceSifSendCmd(0x80000008, a3, 0x40, 0, 0, 0) != 0)
    {
        return 0;
    }
    return 0x800;
}

void *func_00109740(s32 a0, void *a1);

void func_001097D0(s32 *a0, void *a1)
{
    s32 *s2;
    s32 *v;
    s32 ret;
    s32 t1c;
    s32 t14;

    s2 = (s32 *)func_00109388(a1);
    t14 = a0[5];
    t1c = a0[7];
    s2[7] = t1c;
    s2[5] = t14;
    s2[8] = 0x80000009;
    v = (s32 *)func_00109740(a0[8], a1);
    if (v == NULL)
    {
        s2[9] = 0;
        s2[10] = 0;
    }
    else
    {
        s2[9] = (s32)v;
        s2[10] = v[2];
    }
    ret = isceSifSendCmd(0x80000008, s2, 0x40, 0, 0, 0);
    if (ret == 0)
    {
        iSetTimerAlarm(0x800, func_00109790, s2);
    }
}
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", func_001097D0);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", sceSifBindRpc);

extern s32 D_00137FB8[];

int sceSifBindRpc(sceSifClientData *client, unsigned int command, unsigned int mode)
{
    s32 *rec;
    struct SemaParam sparam;
    int sema;

    client->command = 0;
    client->serve = NULL;
    rec = (s32 *)func_001092C0(D_00145AC0);
    if (rec == NULL)
    {
        return -1;
    }
    client->rpcd.paddr = rec;
    client->rpcd.pid = rec[6];
    rec[8] = command;
    rec[5] = (s32)rec;
    rec[7] = (s32)client;
    if (!(mode & 1))
    {
        sparam.maxCount = 1;
        sparam.option = (u_int)D_00137FB8;
        sparam.initCount = 0;
        sema = CreateSema(&sparam);
        client->rpcd.tid = sema;
        if (sema < 0)
        {
            func_00109368(rec);
            return -3;
        }
        if (sceSifSendCmd(0x80000009, rec, 0x40, 0, 0, 0) == 0)
        {
            func_00109368(rec);
            DeleteSema(client->rpcd.tid);
            return -2;
        }
        WaitSema(client->rpcd.tid);
        DeleteSema(client->rpcd.tid);
        return 0;
    }
    client->rpcd.tid = -1;
    if (sceSifSendCmd(0x80000009, rec, 0x40, 0, 0, 0) != 0)
    {
        return 0;
    }
    func_00109368(rec);
    return -2;
}
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", func_001099F0);

/* NEARMISS-STUB sceSifCallRpc */
#if 0 /* NEARMISS 82.9% cat=no-c-form sub=- | live gp read | attempts=1 */
extern void *_gp;
void *func_001092C0(s32 *a0);
void func_00109368(void *a0);
extern s32 D_00137FC8[];

int sceSifCallRpc(sceSifClientData *client, unsigned int command, unsigned int mode, void *sendbuff, int ssize, void *recvbuff, int rsize, sceSifEndFunc func, void *para)
{
    s32 *rec;
    struct SemaParam sparam;
    int sema;

    rec = (s32 *)func_001092C0(D_00145AC0);
    if (rec == NULL)
    {
        return -1;
    }
    client->para = para;
    client->rpcd.pid = rec[6];
    client->rpcd.paddr = rec;
    client->func = func;
    client->gp = (void *)&_gp;
    rec[8] = command;
    rec[9] = ssize;
    rec[10] = (s32)recvbuff;
    rec[11] = rsize;
    rec[5] = (s32)rec;
    rec[13] = (s32)client->serve;
    rec[7] = (s32)client;
    if (!(mode & 2))
    {
        if (sendbuff == recvbuff)
        {
            sceSifWriteBackDCache(sendbuff, (ssize < rsize) ? rsize : ssize);
        }
        else
        {
            if (ssize > 0)
            {
                sceSifWriteBackDCache(sendbuff, ssize);
            }
            if (rsize > 0)
            {
                sceSifWriteBackDCache(recvbuff, rsize);
            }
        }
    }
    if (mode & 1)
    {
        rec[12] = (func != NULL) ? 1 : 0;
        client->rpcd.tid = -1;
        if (sceSifSendCmd(0x8000000A, rec, 0x40, sendbuff, client->buff, ssize) != 0)
        {
            return 0;
        }
        func_00109368(rec);
        return -2;
    }
    sparam.maxCount = 1;
    sparam.option = (u_int)D_00137FC8;
    sparam.initCount = 0;
    sema = CreateSema(&sparam);
    client->rpcd.tid = sema;
    if (sema < 0)
    {
        func_00109368(rec);
        return -3;
    }
    rec[12] = 1;
    if (sceSifSendCmd(0x8000000A, rec, 0x40, sendbuff, client->buff, ssize) != 0)
    {
        WaitSema(client->rpcd.tid);
        DeleteSema(client->rpcd.tid);
        return 0;
    }
    DeleteSema(client->rpcd.tid);
    func_00109368(rec);
    return -2;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", sceSifCallRpc);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", sceSifCheckStatRpc);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", sceSifSetRpcQueue);
typedef struct
{
    s32 pad[10];
    sceSifQueueData *head;
} RpcState;

void sceSifSetRpcQueue(sceSifQueueData *queue, int key)
{
    sceSifQueueData *cur;
    sceSifQueueData *head;

    DIntr();
    queue->key = key;
    queue->active = 0;
    queue->link = NULL;
    queue->start = NULL;
    queue->end = NULL;
    queue->next = NULL;
    head = ((RpcState *)D_00145AC0)->head;
    if (head == NULL)
    {
        ((RpcState *)D_00145AC0)->head = queue;
    }
    else
    {
        for (cur = head; cur->next != NULL; cur = cur->next)
        {
        }
        cur->next = queue;
    }
    EIntr();
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", sceSifRegisterRpc);

void sceSifRegisterRpc(sceSifServeData *serve, unsigned int command, sceSifRpcFunc func, void *buff, sceSifRpcFunc cfunc, void *cbuff, sceSifQueueData *queue)
{
    sceSifServeData *cur;
    sceSifServeData *head;

    DIntr();
    serve->next = NULL;
    serve->link = NULL;
    serve->command = command;
    serve->func = func;
    serve->buff = buff;
    serve->cfunc = cfunc;
    serve->cbuff = cbuff;
    serve->base = queue;
    head = queue->link;
    if (head == NULL)
    {
        queue->link = serve;
    }
    else
    {
        for (cur = head; cur->link != NULL; cur = cur->link)
        {
        }
        cur->link = serve;
    }
    EIntr();
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", sceSifRemoveRpc);

sceSifServeData *sceSifRemoveRpc(sceSifServeData *serve, sceSifQueueData *queue)
{
    sceSifServeData *cur;

    DIntr();
    cur = queue->link;
    if (cur == serve)
    {
        queue->link = cur->link;
    }
    else
    {
        for (; cur != NULL; cur = cur->link)
        {
            if (cur->link == serve)
            {
                cur->link = serve->link;
                break;
            }
        }
    }
    EIntr();
    return cur;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", sceSifRemoveRpcQueue);

sceSifQueueData *sceSifRemoveRpcQueue(sceSifQueueData *queue)
{
    sceSifQueueData *cur;

    DIntr();
    cur = (sceSifQueueData *)D_00145AC0[10];
    if (cur == queue)
    {
        D_00145AC0[10] = (s32)cur->next;
    }
    else
    {
        for (; cur != NULL; cur = cur->next)
        {
            if (cur->next == queue)
            {
                cur->next = queue->next;
                break;
            }
        }
    }
    EIntr();
    return cur;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", sceSifGetNextRequest);

sceSifServeData *sceSifGetNextRequest(sceSifQueueData *queue)
{
    sceSifServeData *req;

    DIntr();
    req = queue->start;
    if (req == NULL)
    {
        queue->active = 0;
    }
    else
    {
        queue->active = 1;
        queue->start = req->next;
    }
    EIntr();
    return req;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", sceSifExecRequest);

void sceSifExecRequest(sceSifServeData *req)
{
    s32 *s0;
    void *s2;
    int s4;
    int s3;
    s32 i;
    unsigned int r;
    sceSifDmaData dma[2];

    s4 = 0;
    s2 = req->func(req->fno, req->buff, req->size);
    if (s2 != NULL)
    {
        s4 = req->rsize;
    }
    if (req->size > 0)
    {
        sceSifWriteBackDCache(req->buff, req->size);
    }
    if (s4 > 0)
    {
        sceSifWriteBackDCache(s2, s4);
    }
    DIntr();
    if (req->rid & 4)
    {
        s0 = (s32 *)func_001093B8(D_00145AC0, (u32)req->rid >> 16);
    }
    else
    {
        s0 = (s32 *)func_00109388(D_00145AC0);
    }
    EIntr();
    s0[8] = 0x8000000A;
    s0[7] = (s32)req->client;
    if (req->rmode != 0)
    {
        while (sceSifSendCmd(0x80000008, s0, 0x40, s2, req->receive, s4) == 0)
        {
        }
        return;
    }
    s0[6] = 0;
    s3 = 0;
    s0[4] = 0;
    if (s4 > 0)
    {
        s3 = 1;
        dma[0].data = (u32)s2;
        dma[0].addr = (u32)req->receive;
        dma[0].size = s4;
        dma[0].mode = 0;
    }
    dma[s3].data = (u32)s0;
    dma[s3].addr = (u32)req->paddr;
    dma[s3].size = 0x40;
    dma[s3].mode = 0;
    s3++;
    do
    {
        r = sceSifSetDma(dma, s3);
        if (r != 0)
        {
            break;
        }
        for (i = 0x100000; i != -1; i--)
        {
        }
    } while (r == 0);
}
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/sifrpc", sceSifRpcLoop);

void sceSifRpcLoop(sceSifQueueData *queue)
{
    sceSifServeData *req;

    while (1)
    {
        while ((req = sceSifGetNextRequest(queue)) != NULL)
        {
            sceSifExecRequest(req);
        }
        SleepThread();
    }
}

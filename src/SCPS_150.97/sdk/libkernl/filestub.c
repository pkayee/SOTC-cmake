#include "common.h"

struct SemaParam
{
    int currentCount;
    int maxCount;
    int initCount;
    int numWaitThreads;
    u32 attr;
    u32 option;
};

struct IobEntry
{
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
};

extern s32 D_00132414[];
extern s32 D_00132420[];
extern s32 D_00132424[];
extern s32 D_00132428[];
extern s32 D_0013241C[];
extern s32 D_0013237C[];
extern s32 D_00137FE0[];
extern s32 D_00138188[];
extern s32 D_001381A0[];
extern s32 D_00138098[];
extern s32 D_00147240[];
extern s32 D_00146780[];
extern s32 D_00145B40[];
extern s32 D_00137FF0[];
extern s32 D_00138068[];
extern s32 D_00147268[];
extern struct IobEntry D_00147040[];
extern s32 D_00138128[];
extern s32 D_001380C8[];
extern s32 D_00132390[];
extern s32 D_001380B0[];
extern s32 D_00138230[];
extern s32 D_001380E0[];
extern s32 D_00138140[];
extern s32 D_00138200[];
extern s32 D_00138170[];
extern s32 D_001381B8[];

int CreateSema(struct SemaParam *);
int DeleteSema(int);
int SignalSema(int);
int WaitSema(int);
void *memset();
int memcmp(const void *, const void *, unsigned int);
s32 func_0010BFA8(const u8 *, s32);
void _sceFsIobSemaMK(void);
void _sceFsSemInit(void);
void _sceFsSigSema(void);
int _sceFsWaitS(s32 timeout);
void sceFsInit(void);

s32 sceSifCallRpc(void *, u32, u32, void *, s32, void *, s32, void *, void *);
s32 DelayThread(u32);
void sceSifWriteBackDCache(const void *, int);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", _sceFsIobSemaMK);
void _sceFsIobSemaMK(void)
{
    struct SemaParam sp;

    if (D_00132420[0] == -1)
    {
        sp.initCount = 1;
        sp.maxCount = 1;
        sp.option = (u32)D_00137FE0;
        D_00132420[0] = CreateSema(&sp);
        sp.option = (u32)D_00137FF0;
        D_00132424[0] = CreateSema(&sp);
    }
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", func_0010A220);
s32 func_0010A220(void)
{
    s32 count;
    struct IobEntry *p;

    count = 0;
    _sceFsIobSemaMK();
    WaitSema(D_00132420[0]);
    for (p = D_00147040; p < D_00147040 + 32; p++)
    {
        if (p->unk04 != 0)
        {
            count++;
        }
    }
    SignalSema(D_00132420[0]);
    return count;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", new_iob);
struct IobEntry *new_iob(void)
{
    struct IobEntry *p;

    _sceFsIobSemaMK();
    WaitSema(D_00132420[0]);
    for (p = D_00147040; p < D_00147040 + 32; p++)
    {
        if (p->unk04 == 0)
        {
            p->unk04 = 0x10000000;
            SignalSema(D_00132420[0]);
            return p;
        }
    }
    SignalSema(D_00132420[0]);
    return NULL;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", func_0010A328);
s32 func_0010A328(void *client, u32 rpc, u32 mode, void *send, s32 ssize, void *recv, s32 rsize, void *endfunc, void *endparam, s32 noRetry)
{
    s32 delay;
    s32 ret;
    s32 i;

    delay = 1;
    i = 0;
    do
    {
        ret = (u32)sceSifCallRpc(client, rpc, mode, send, ssize, recv, rsize, endfunc, endparam) >> 31;
        if (ret == 0 || noRetry != 0)
        {
            break;
        }
        DelayThread(delay * 1000);
        if (delay < 0x7F)
        {
            delay = delay * 2;
        }
        i++;
    } while (i < 0x65);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", get_iob);
struct IobEntry *get_iob(u32 idx)
{
    struct IobEntry *ret;

    _sceFsIobSemaMK();
    WaitSema(D_00132420[0]);
    if (idx >= 0x20)
    {
        SignalSema(D_00132420[0]);
        return NULL;
    }
    ret = &D_00147040[idx];
    SignalSema(D_00132420[0]);
    return ret;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", _sceFs_Rcv_Intr);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", _sceFsSemInit);
void _sceFsSemInit(void)
{
    struct SemaParam sp;

    if (D_0013241C[0] == -1)
    {
        sp.initCount = 1;
        sp.maxCount = 1;
        sp.option = (u32)D_00138068;
        D_0013241C[0] = CreateSema(&sp);
    }
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", _sceFsWaitS);
int _sceFsWaitS(s32 timeout)
{
    _sceFsSemInit();
    WaitSema(D_0013241C[0]);
    return 0;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", _sceFsSigSema);
void _sceFsSigSema(void)
{
    SignalSema(D_0013241C[0]);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", scePowerOffHandler);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", func_0010A978);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceFsInit);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", func_0010ABC8);
s32 func_0010ABC8(void)
{
    void *a;
    void *b;
    s32 ret;

    ret = 0;
    b = D_0013237C;
    a = D_00147268;
    if (memcmp(a, b, 4) != 0 && memcmp(a, (void *)D_00132428[0], 4) != 0)
    {
        ret = memcmp(b, (void *)D_00132428[0], 4) != 0;
    }
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceFsReset);
int sceFsReset(void)
{
    s32 n;

    D_00132414[0] = 0;
    n = 4;
    memset(D_00147268, 0, n);
    return 0;
}

s32 sceFsSetIopBuf(u32 size, u32 num)
{
    s32 *buf;
    s32 status;
    s32 ret;

    _sceFsWaitS(0xFE);
    if (D_00132414[0] == 0)
    {
        sceFsInit();
    }
    if (func_0010ABC8() != 0)
    {
        _sceFsSigSema();
        return 0xFFFEFFFC;
    }
    if (func_0010A220() != 0)
    {
        _sceFsSigSema();
        return -16;
    }
    if ((size & 0x3FFF) != 0 || size == 0 || size > 0xFFFFF || num == 0 || num > 0x20)
    {
        _sceFsSigSema();
        return -22;
    }
    buf = D_00145B40;
    buf[0] = size;
    buf[1] = num;
    ret = func_0010A328(D_00147240, 0xFE, 0, buf, 8, D_00146780, 4, NULL, NULL, 0);
    if (ret < 0)
    {
        _sceFsSigSema();
        return -11;
    }
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    return status;
}

s32 sceFsSetIopPrio(s32 prio)
{
    s32 status;
    s32 ret;

    _sceFsWaitS(0xFD);
    if (D_00132414[0] == 0)
    {
        sceFsInit();
    }
    if (func_0010ABC8() != 0)
    {
        _sceFsSigSema();
        return 0xFFFEFFFC;
    }
    if (func_0010A220() != 0)
    {
        _sceFsSigSema();
        return -16;
    }
    D_00145B40[0] = prio;
    ret = func_0010A328(D_00147240, 0xFD, 0, D_00145B40, 8, D_00146780, 4, NULL, NULL, 0);
    if (ret < 0)
    {
        _sceFsSigSema();
        return -11;
    }
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    return status;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceOpen);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceClose);
s32 sceClose(s32 fd)
{
    struct SemaParam sp;
    s32 result;
    struct IobEntry *iob;
    s32 *buf;
    s32 sema;
    s32 status;
    s32 ret;
    s32 m1;

    buf = D_00145B40;
    iob = get_iob(fd);
    _sceFsWaitS(1);
    if (D_00132414[0] == 0 || iob == NULL || iob->unk04 == 0)
    {
        _sceFsSigSema();
        return -9;
    }
    buf[3] = iob->unk00;
    buf[4] = iob - D_00147040;
    sp.maxCount = 1;
    sp.option = (u32)D_00138098;
    sp.initCount = 0;
    sema = CreateSema(&sp);
    D_00145B40[0] = sema;
    buf[1] = (s32)&result;
    buf[2] = 4;
    ret = func_0010A328(D_00147240, 1, 0, buf, 0x14, D_00146780, 4, NULL, NULL, 0);
    if (ret < 0)
    {
        DeleteSema(sema);
        _sceFsSigSema();
        return -11;
    }
    iob->unk04 = 0;
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    if (status != 0)
    {
        WaitSema(sema);
        DeleteSema(sema);
    }
    else
    {
        DeleteSema(sema);
        return -11;
    }
    m1 = -1;
    if (m1 < result)
    {
        return 0;
    }
    return result;
}

/* NEARMISS-STUB sceLseek */
#if 0 /* NEARMISS 88.1% cat=regalloc sub=- | s2/s3 swap (offset/sema vs flags/noRetry); D_00132390 first-slot bne operand order and lw/negu temp reg (v0/v1) in the -1 slot store; lui s6/s0 hoist in fallthr | attempts=1 */
s32 sceLseek(s32 fd, s32 offset, s32 whence)
{
    struct SemaParam sp;
    s32 result;
    struct IobEntry *iob;
    s32 *buf;
    s32 sema;
    s32 status;
    s32 ret;
    s32 i;
    s32 retry;
    s32 noRetry;
    s32 val;

    buf = D_00145B40;
    iob = get_iob(fd);
    _sceFsWaitS(4);
    if (D_00132414[0] == 0 || iob == NULL || (noRetry = iob->unk04) == 0)
    {
        _sceFsSigSema();
        return -9;
    }
    buf[3] = iob->unk00;
    buf[4] = offset;
    buf[5] = whence;
    buf[6] = iob - D_00147040;
    sp.maxCount = 1;
    sp.option = (u32)D_001380B0;
    retry = noRetry & 0x8000;
    sp.initCount = 0;
    sema = CreateSema(&sp);
    buf[1] = (s32)&result;
    buf[2] = 4;
    buf[0] = sema;
    if (retry)
    {
        WaitSema(D_00132424[0]);
        noRetry = retry;
        if (D_00132390[0] == -1)
        {
            val = buf[0];
            D_00132390[0] = val;
            buf[0] = -val;
        }
        else
        {
            for (i = 1; i < 0x20; i++)
            {
                if (D_00132390[i] == -1)
                {
                    val = buf[0];
                    D_00132390[i] = val;
                    buf[0] = -val;
                    break;
                }
            }
        }
        SignalSema(D_00132424[0]);
    }
    else
    {
        noRetry = 0;
    }
    ret = func_0010A328(D_00147240, 4, 0, buf, 0x1C, D_00146780, 4, NULL, NULL, noRetry);
    if (ret < 0)
    {
        DeleteSema(sema);
        _sceFsSigSema();
        return -11;
    }
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    if (status == 0)
    {
        DeleteSema(sema);
        return -11;
    }
    if (noRetry != 0)
    {
        DeleteSema(sema);
        return 0;
    }
    WaitSema(sema);
    DeleteSema(sema);
    return result;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceLseek);

/* NEARMISS-STUB sceRead */
#if 0 /* NEARMISS 89.8% cat=regalloc sub=- | s2/s3/s4/s5 register mapping of sema/offset/flags/noRetry; D_00132390 slot operand order and lw/negu temp reg (v0/v1); lui s0 hoist; status/noRetry layout match | attempts=1 */
s32 sceRead(s32 fd, void *buffer, s32 count)
{
    struct SemaParam sp;
    s32 result;
    struct IobEntry *iob;
    s32 *buf;
    s32 sema;
    s32 status;
    s32 ret;
    s32 i;
    s32 flags;
    s32 retry;
    s32 noRetry;
    s32 val;

    buf = D_00145B40;
    iob = get_iob(fd);
    _sceFsWaitS(2);
    if (D_00132414[0] == 0 || iob == NULL || (flags = iob->unk04) == 0)
    {
        _sceFsSigSema();
        return -9;
    }
    buf[3] = iob->unk00;
    buf[7] = iob - D_00147040;
    sp.maxCount = 1;
    sp.option = (u32)D_001380C8;
    retry = flags & 0x8000;
    buf[4] = (s32)buffer;
    buf[5] = count;
    sp.initCount = 0;
    sema = CreateSema(&sp);
    buf[1] = (s32)&result;
    buf[2] = 4;
    buf[0] = sema;
    if (retry)
    {
        WaitSema(D_00132424[0]);
        noRetry = retry;
        if (D_00132390[0] == -1)
        {
            val = buf[0];
            D_00132390[0] = val;
            buf[0] = -val;
        }
        else
        {
            for (i = 1; i < 0x20; i++)
            {
                if (D_00132390[i] == -1)
                {
                    val = buf[0];
                    D_00132390[i] = val;
                    buf[0] = -val;
                    break;
                }
            }
        }
        SignalSema(D_00132424[0]);
    }
    else
    {
        noRetry = 0;
    }
    if (!(flags & 0x20000000))
    {
        sceSifWriteBackDCache(buffer, count);
    }
    sceSifWriteBackDCache(buf, 0x20);
    ret = func_0010A328(D_00147240, 2, 0, buf, 0x20, D_00146780, 4, NULL, NULL, noRetry);
    if (ret < 0)
    {
        DeleteSema(sema);
        _sceFsSigSema();
        return -11;
    }
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    if (status == 0)
    {
        DeleteSema(sema);
        return -11;
    }
    if (noRetry != 0)
    {
        DeleteSema(sema);
        return 0;
    }
    WaitSema(sema);
    DeleteSema(sema);
    return result;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceRead);

/* NEARMISS-STUB sceWrite */
#if 0 /* NEARMISS 86.68% cat=regalloc sub=- | hi(D_00145B40) in s3 not s8 and count/flags/sema/noRetry permuted s4-s7; first-branch -1 store and i-loop index form now match; local declaration order changes  | attempts=1 */
s32 sceWrite(s32 fd, void *buffer, s32 count)
{
    struct SemaParam sp;
    s32 result;
    struct IobEntry *iob;
    s32 *buf;
    s32 sema;
    s32 status;
    s32 ret;
    s32 i;
    s32 flags;
    s32 retry;
    s32 noRetry;
    s32 val;
    s32 head;

    buf = D_00145B40;
    iob = get_iob(fd);
    _sceFsWaitS(3);
    if (D_00132414[0] == 0 || iob == NULL || (flags = iob->unk04) == 0)
    {
        _sceFsSigSema();
        return -9;
    }
    buf[3] = iob->unk00;
    buf[11] = iob - D_00147040;
    sp.maxCount = 1;
    sp.option = (u32)D_001380E0;
    retry = flags & 0x8000;
    buf[5] = count;
    buf[4] = (s32)buffer;
    sp.initCount = 0;
    sema = CreateSema(&sp);
    buf[1] = (s32)&result;
    buf[2] = 4;
    D_00145B40[0] = sema;
    if (retry)
    {
        WaitSema(D_00132424[0]);
        noRetry = retry;
        if (D_00132390[0] == -1)
        {
            val = D_00145B40[0];
            D_00132390[0] = val;
            D_00145B40[0] = -val;
        }
        else
        {
            for (i = 1; i < 0x20; i++)
            {
                if (D_00132390[i] == -1)
                {
                    val = buf[0];
                    D_00132390[i] = val;
                    buf[0] = -val;
                    break;
                }
            }
        }
        SignalSema(D_00132424[0]);
    }
    else
    {
        noRetry = 0;
    }
    head = (u32)buffer & 0xF;
    if (head != 0)
    {
        head = 16 - head;
    }
    if (count < head)
    {
        head = count;
    }
    if (!(flags & 0x20000000))
    {
        sceSifWriteBackDCache(buffer, count);
    }
    buffer = (void *)((u32)buffer | 0x20000000);
    buf[6] = head;
    for (i = 0; i < head; i++)
    {
        ((u8 *)buf)[0x1C + i] = ((u8 *)buffer)[i];
    }
    ret = func_0010A328(D_00147240, 3, 0, buf, 0x30, D_00146780, 4, NULL, NULL, noRetry);
    if (ret < 0)
    {
        DeleteSema(sema);
        _sceFsSigSema();
        return -11;
    }
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    if (status == 0)
    {
        DeleteSema(sema);
        return -11;
    }
    if (noRetry != 0)
    {
        DeleteSema(sema);
        return 0;
    }
    WaitSema(sema);
    DeleteSema(sema);
    return result;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceWrite);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceIoctl);

extern s32 D_00138110[];
s32 sceIoctl2(s32 fd, s32 cmd, void *in, u32 inlen, void *out, u32 outlen)
{
    struct SemaParam sp;
    s32 result;
    struct IobEntry *iob;
    s32 *buf;
    s32 sema;
    s32 status;
    s32 ret;

    buf = D_00145B40;
    iob = get_iob(fd);
    _sceFsWaitS(0x1A);
    if (D_00132414[0] == 0)
    {
        sceFsInit();
    }
    if (iob == NULL || iob->unk04 == 0)
    {
        _sceFsSigSema();
        return -9;
    }
    if (inlen > 0x400 || outlen > 0x400)
    {
        _sceFsSigSema();
        return -0x16;
    }
    if (in == NULL)
    {
        buf[0x107] = 0;
    }
    else
    {
        memcpy((char *)buf + 0x14, in, inlen);
    }
    buf[3] = iob->unk00;
    buf[4] = cmd;
    buf[0x107] = inlen;
    sp.maxCount = 1;
    sp.option = (u32)D_00138110;
    sp.initCount = 0;
    sema = CreateSema(&sp);
    buf[0x106] = outlen;
    buf[1] = (s32)&result;
    buf[2] = 4;
    buf[0x105] = (s32)out;
    buf[0] = sema;
    sceSifWriteBackDCache(D_00145B40, 0x420);
    ret = func_0010A328(D_00147240, 0x1A, 0, D_00145B40, 0x420, D_00146780, 4, NULL, NULL, 0);
    if (ret < 0)
    {
        DeleteSema(sema);
        _sceFsSigSema();
        return -11;
    }
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    if (status != 0)
    {
        WaitSema(sema);
        DeleteSema(sema);
    }
    else
    {
        DeleteSema(sema);
        return -11;
    }
    return result;
}

s32 func_0010BFA8(const u8 *path, s32 rpc)
{
    struct SemaParam sp;
    s32 result;
    s32 *buf;
    s32 i;
    s32 sema;
    s32 status;
    s32 ret;

    buf = D_00145B40;
    _sceFsWaitS(rpc);
    if (D_00132414[0] == 0)
    {
        sceFsInit();
    }
    for (i = 0; i < 0x400; i++)
    {
        *((char *)buf + i + 0xC) = path[i];
        if (*((char *)buf + i + 0xC) == 0)
        {
            break;
        }
    }
    if (i == 0x400)
    {
        ((char *)buf)[0x40B] = 0;
        i = 0x3FF;
    }
    sp.maxCount = 1;
    sp.option = (u32)D_00138128;
    sp.initCount = 0;
    sema = CreateSema(&sp);
    buf[0] = sema;
    buf[1] = (s32)&result;
    buf[2] = 4;
    ret = func_0010A328(D_00147240, rpc, 0, D_00145B40, i + 0xD, D_00146780, 4, NULL, NULL, 0);
    if (ret < 0)
    {
        DeleteSema(sema);
        _sceFsSigSema();
        return -11;
    }
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    if (status != 0)
    {
        WaitSema(sema);
        DeleteSema(sema);
    }
    else
    {
        DeleteSema(sema);
        return -11;
    }
    return result;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceRemove);
s32 sceRemove(const u8 *path)
{
    return func_0010BFA8(path, 0x6);
}

extern s32 D_00138140[];
s32 sceMkdir(const u8 *path, s32 mode)
{
    struct SemaParam sp;
    s32 result;
    s32 *buf;
    s32 i;
    s32 sema;
    s32 status;
    s32 ret;

    buf = D_00145B40;
    _sceFsWaitS(7);
    if (D_00132414[0] == 0)
    {
        sceFsInit();
    }
    for (i = 0; i < 0x400; i++)
    {
        *((char *)buf + i + 0x10) = path[i];
        if (*((char *)buf + i + 0x10) == 0)
        {
            break;
        }
    }
    if (i == 0x400)
    {
        ((char *)buf)[0x40F] = 0;
        i = 0x3FF;
    }
    buf[3] = mode;
    sp.maxCount = 1;
    sp.option = (u32)D_00138140;
    sp.initCount = 0;
    sema = CreateSema(&sp);
    buf[0] = sema;
    buf[1] = (s32)&result;
    buf[2] = 4;
    ret = func_0010A328(D_00147240, 7, 0, D_00145B40, i + 0x11, D_00146780, 4, NULL, NULL, 0);
    if (ret < 0)
    {
        DeleteSema(sema);
        _sceFsSigSema();
        return -11;
    }
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    if (status != 0)
    {
        WaitSema(sema);
        DeleteSema(sema);
    }
    else
    {
        DeleteSema(sema);
        return -11;
    }
    return result;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceRmdir);
s32 sceRmdir(const u8 *path)
{
    return func_0010BFA8(path, 0x8);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceFormat);

s32 sceAddDrv(void *drv)
{
    struct SemaParam sp;
    s32 result;
    s32 *buf;
    s32 sema;
    s32 status;
    s32 ret;

    buf = D_00145B40;
    _sceFsWaitS(0xF);
    if (D_00132414[0] == 0)
    {
        sceFsInit();
    }
    buf[3] = (s32)drv;
    sp.maxCount = 1;
    sp.option = (u32)D_00138170;
    sp.initCount = 0;
    sema = CreateSema(&sp);
    buf[0] = sema;
    buf[1] = (s32)&result;
    buf[2] = 4;
    ret = func_0010A328(D_00147240, 0xF, 0, D_00145B40, 0x10, D_00146780, 4, NULL, NULL, 0);
    if (ret < 0)
    {
        DeleteSema(sema);
        _sceFsSigSema();
        return -11;
    }
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    if (status != 0)
    {
        WaitSema(sema);
        DeleteSema(sema);
    }
    else
    {
        DeleteSema(sema);
        return -11;
    }
    return result;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceDelDrv);
s32 sceDelDrv(const u8 *path)
{
    return func_0010BFA8(path, 0x10);
}

/* NEARMISS-STUB sceDopen */
#if 0 /* NEARMISS 91.4% cat=regalloc sub=- | s1 ret store vs iob-base index order: target computes lui/addiu/subu of D_00147040 before sw s1,0(iob); 2.9 keeps store first; idx local made frame 0x50 vs 0x40 | attempts=1 */
s32 sceDopen(const u8 *path)
{
    struct IobEntry *iob;
    s32 ret;

    _sceFsWaitS(9);
    if (D_00132414[0] == 0)
    {
        sceFsInit();
    }
    _sceFsSigSema();
    iob = new_iob();
    if (iob == NULL)
    {
        return -19;
    }
    ret = func_0010BFA8(path, 9);
    if (ret < 0)
    {
        WaitSema(D_00132420[0]);
        iob->unk04 = 0;
        SignalSema(D_00132420[0]);
        return ret;
    }
    WaitSema(D_00132420[0]);
    iob->unk00 = ret;
    ret = iob - D_00147040;
    SignalSema(D_00132420[0]);
    return ret;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceDopen);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceDclose);
s32 sceDclose(s32 fd)
{
    struct SemaParam sp;
    s32 result;
    struct IobEntry *iob;
    s32 *buf;
    s32 sema;
    s32 status;
    s32 ret;
    s32 m1;

    buf = D_00145B40;
    iob = get_iob(fd);
    _sceFsWaitS(10);
    if (D_00132414[0] == 0 || iob == NULL || iob->unk04 == 0)
    {
        _sceFsSigSema();
        return -9;
    }
    buf[3] = iob->unk00;
    sp.maxCount = 1;
    sp.option = (u32)D_00138188;
    sp.initCount = 0;
    sema = CreateSema(&sp);
    D_00145B40[0] = sema;
    buf[1] = (s32)&result;
    buf[2] = 4;
    ret = func_0010A328(D_00147240, 0xA, 0, buf, 0x14, D_00146780, 4, NULL, NULL, 0);
    if (ret < 0)
    {
        DeleteSema(sema);
        _sceFsSigSema();
        return -11;
    }
    iob->unk04 = 0;
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    if (status != 0)
    {
        WaitSema(sema);
        DeleteSema(sema);
    }
    else
    {
        DeleteSema(sema);
        return -11;
    }
    m1 = -1;
    if (m1 < result)
    {
        return 0;
    }
    return result;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceDread);
s32 sceDread(s32 fd, void *dirent)
{
    struct SemaParam sp;
    s32 result;
    struct IobEntry *iob;
    s32 *buf;
    s32 sema;
    s32 status;
    s32 ret;

    buf = D_00145B40;
    iob = get_iob(fd);
    _sceFsWaitS(0xB);
    if (D_00132414[0] == 0 || iob == NULL || iob->unk04 == 0)
    {
        _sceFsSigSema();
        return -9;
    }
    buf[3] = iob->unk00;
    buf[4] = (s32)dirent;
    sp.maxCount = 1;
    sp.option = (u32)D_001381A0;
    sp.initCount = 0;
    sema = CreateSema(&sp);
    D_00145B40[0] = sema;
    buf[1] = (s32)&result;
    buf[2] = 4;
    ret = func_0010A328(D_00147240, 0xB, 0, buf, 0x20, D_00146780, 4, NULL, NULL, 0);
    if (ret < 0)
    {
        WaitSema(sema);
        _sceFsSigSema();
        return -11;
    }
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    if (status == 0)
    {
        DeleteSema(sema);
        return -11;
    }
    WaitSema(sema);
    DeleteSema(sema);
    return result;
}

extern s32 D_001381B8[];
s32 sceGetstat(const u8 *path, void *stat)
{
    struct SemaParam sp;
    s32 result;
    s32 *buf;
    s32 i;
    s32 sema;
    s32 status;
    s32 ret;

    buf = D_00145B40;
    _sceFsWaitS(0xC);
    if (D_00132414[0] == 0)
    {
        sceFsInit();
    }
    for (i = 0; i < 0x400; i++)
    {
        *((u8 *)buf + i + 0x10) = path[i];
        if (*((u8 *)buf + i + 0x10) == 0)
        {
            break;
        }
    }
    if (i == 0x400)
    {
        ((char *)buf)[0x40F] = 0;
        i = 0x3FF;
    }
    buf[3] = (s32)stat;
    sp.maxCount = 1;
    sp.option = (u32)D_001381B8;
    sp.initCount = 0;
    sema = CreateSema(&sp);
    buf[0] = sema;
    buf[1] = (s32)&result;
    buf[2] = 4;
    ret = func_0010A328(D_00147240, 0xC, 0, D_00145B40, i + 0x11, D_00146780, 4, NULL, NULL, 0);
    if (ret < 0)
    {
        DeleteSema(sema);
        _sceFsSigSema();
        return -11;
    }
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    if (status != 0)
    {
        WaitSema(sema);
        DeleteSema(sema);
    }
    else
    {
        DeleteSema(sema);
        return -11;
    }
    return result;
}

struct FsStat
{
    u8 b[0x40];
};
extern s32 D_001381D0[];
s32 sceChstat(const u8 *path, struct FsStat *stat, s32 mask)
{
    struct SemaParam sp;
    s32 result;
    s32 *buf;
    s32 i;
    s32 sema;
    s32 status;
    s32 ret;

    buf = D_00145B40;
    _sceFsWaitS(0xD);
    if (D_00132414[0] == 0)
    {
        sceFsInit();
    }
    for (i = 0; i < 0x400; i++)
    {
        *((u8 *)buf + i + 0x50) = path[i];
        if (*((u8 *)buf + i + 0x50) == 0)
        {
            break;
        }
    }
    if (i == 0x400)
    {
        ((char *)buf)[0x44F] = 0;
        i = 0x3FF;
    }
    *(struct FsStat *)((u8 *)buf + 0x10) = *stat;
    buf[3] = mask;
    sp.maxCount = 1;
    sp.option = (u32)D_001381D0;
    sp.initCount = 0;
    sema = CreateSema(&sp);
    buf[0] = sema;
    buf[1] = (s32)&result;
    buf[2] = 4;
    sceSifWriteBackDCache(D_00145B40, 0x450);
    ret = func_0010A328(D_00147240, 0xD, 0, D_00145B40, i + 0x51, D_00146780, 4, NULL, NULL, 0);
    if (ret < 0)
    {
        DeleteSema(sema);
        _sceFsSigSema();
        return -11;
    }
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    if (status != 0)
    {
        WaitSema(sema);
        DeleteSema(sema);
    }
    else
    {
        DeleteSema(sema);
        return -11;
    }
    return result;
}

extern s32 D_001381E8[];
s32 sceRename(const u8 *from, const u8 *to)
{
    struct SemaParam sp;
    s32 result;
    s32 *buf;
    s32 i;
    s32 sema;
    s32 status;
    s32 ret;
    char *dst;

    buf = D_00145B40;
    _sceFsWaitS(0x11);
    if (D_00132414[0] == 0)
    {
        sceFsInit();
    }
    for (i = 0; i < 0x400; i++)
    {
        *((char *)buf + i + 0xC) = from[i];
        if (*((char *)buf + i + 0xC) == 0)
        {
            break;
        }
    }
    if (i == 0x400)
    {
        ((char *)buf)[0x40B] = 0;
    }
    for (i = 0; i < 0x400; i++)
    {
        dst = (char *)buf + 0x40C;
        dst[i] = to[i];
        if (dst[i] == 0)
        {
            break;
        }
    }
    if (i == 0x400)
    {
        ((char *)buf)[0x80B] = 0;
    }
    sp.maxCount = 1;
    sp.option = (u32)D_001381E8;
    sp.initCount = 0;
    sema = CreateSema(&sp);
    buf[0] = sema;
    buf[1] = (s32)&result;
    buf[2] = 4;
    sceSifWriteBackDCache(D_00145B40, 0x80C);
    ret = func_0010A328(D_00147240, 0x11, 0, D_00145B40, 0x80C, D_00146780, 4, NULL, NULL, 0);
    if (ret < 0)
    {
        DeleteSema(sema);
        _sceFsSigSema();
        return -11;
    }
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    if (status != 0)
    {
        WaitSema(sema);
        DeleteSema(sema);
    }
    else
    {
        DeleteSema(sema);
        return -11;
    }
    return result;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceChdir);
s32 sceChdir(const u8 *path)
{
    return func_0010BFA8(path, 0x12);
}

extern s32 D_00138200[];
s32 sceSync(const u8 *path, s32 arg)
{
    struct SemaParam sp;
    s32 result;
    s32 *buf;
    s32 i;
    s32 sema;
    s32 status;
    s32 ret;

    buf = D_00145B40;
    _sceFsWaitS(0x13);
    if (D_00132414[0] == 0)
    {
        sceFsInit();
    }
    for (i = 0; i < 0x400; i++)
    {
        *((char *)buf + i + 0x14) = path[i];
        if (*((char *)buf + i + 0x14) == 0)
        {
            break;
        }
    }
    if (i == 0x400)
    {
        ((char *)buf)[0x413] = 0;
    }
    buf[4] = arg;
    sp.maxCount = 1;
    sp.option = (u32)D_00138200;
    sp.initCount = 0;
    sema = CreateSema(&sp);
    buf[0] = sema;
    buf[1] = (s32)&result;
    buf[2] = 4;
    ret = func_0010A328(D_00147240, 0x13, 0, D_00145B40, 0x414, D_00146780, 4, NULL, NULL, 0);
    if (ret < 0)
    {
        DeleteSema(sema);
        _sceFsSigSema();
        return -11;
    }
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    if (status != 0)
    {
        WaitSema(sema);
        DeleteSema(sema);
    }
    else
    {
        DeleteSema(sema);
        return -11;
    }
    return result;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceMount);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceUmount);
s32 sceUmount(const u8 *path)
{
    return func_0010BFA8(path, 0x15);
}

/* NEARMISS-STUB sceLseek64 */
#if 0 /* NEARMISS 88.11% cat=regalloc sub=- | offset/whence and noRetry swapped across s2/s3 (target: whence s5, offset s3, noRetry s2); target hoists lui %hi(D_00147240)/D_00146780 into the -1 and loop pat | attempts=1 */
s64 sceLseek64(s32 fd, s64 offset, s32 whence)
{
    struct SemaParam sp;
    s64 result;
    struct IobEntry *iob;
    s32 *buf;
    s32 sema;
    s32 status;
    s32 ret;
    s32 i;
    s32 retry;
    s32 noRetry;
    s32 val;

    buf = D_00145B40;
    iob = get_iob(fd);
    _sceFsWaitS(0x16);
    if (D_00132414[0] == 0 || iob == NULL || (noRetry = iob->unk04) == 0)
    {
        _sceFsSigSema();
        return -9;
    }
    buf[3] = iob->unk00;
    *(s64 *)&buf[4] = offset;
    buf[6] = whence;
    buf[7] = iob - D_00147040;
    sp.maxCount = 1;
    sp.option = (u32)D_00138230;
    retry = noRetry & 0x8000;
    sp.initCount = 0;
    sema = CreateSema(&sp);
    buf[1] = (s32)&result;
    buf[2] = 8;
    D_00145B40[0] = sema;
    if (retry)
    {
        WaitSema(D_00132424[0]);
        noRetry = retry;
        if (D_00132390[0] == -1)
        {
            val = D_00145B40[0];
            D_00132390[0] = val;
            D_00145B40[0] = -val;
        }
        else
        {
            for (i = 1; i < 0x20; i++)
            {
                if (D_00132390[i] == -1)
                {
                    val = buf[0];
                    D_00132390[i] = val;
                    buf[0] = -val;
                    break;
                }
            }
        }
        SignalSema(D_00132424[0]);
    }
    else
    {
        noRetry = 0;
    }
    ret = func_0010A328(D_00147240, 0x16, 0, buf, 0x20, D_00146780, 4, NULL, NULL, noRetry);
    if (ret < 0)
    {
        DeleteSema(sema);
        _sceFsSigSema();
        return -11;
    }
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    if (status == 0)
    {
        DeleteSema(sema);
        return -11;
    }
    if (noRetry != 0)
    {
        DeleteSema(sema);
        return 0;
    }
    WaitSema(sema);
    DeleteSema(sema);
    return result;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceLseek64);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceDevctl);

extern s32 D_00138260[];
s32 sceSymlink(const u8 *from, const u8 *to)
{
    struct SemaParam sp;
    s32 result;
    s32 *buf;
    s32 i;
    s32 sema;
    s32 status;
    s32 ret;
    char *dst;

    buf = D_00145B40;
    _sceFsWaitS(0x11);
    if (D_00132414[0] == 0)
    {
        sceFsInit();
    }
    for (i = 0; i < 0x400; i++)
    {
        *((char *)buf + i + 0xC) = from[i];
        if (*((char *)buf + i + 0xC) == 0)
        {
            break;
        }
    }
    if (i == 0x400)
    {
        ((char *)buf)[0x40B] = 0;
    }
    for (i = 0; i < 0x400; i++)
    {
        dst = (char *)buf + 0x40C;
        dst[i] = to[i];
        if (dst[i] == 0)
        {
            break;
        }
    }
    if (i == 0x400)
    {
        ((char *)buf)[0x80B] = 0;
    }
    sp.maxCount = 1;
    sp.option = (u32)D_00138260;
    sp.initCount = 0;
    sema = CreateSema(&sp);
    buf[0] = sema;
    buf[1] = (s32)&result;
    buf[2] = 4;
    ret = func_0010A328(D_00147240, 0x18, 0, D_00145B40, 0x80C, D_00146780, 4, NULL, NULL, 0);
    if (ret < 0)
    {
        DeleteSema(sema);
        _sceFsSigSema();
        return -11;
    }
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    if (status != 0)
    {
        WaitSema(sema);
        DeleteSema(sema);
    }
    else
    {
        DeleteSema(sema);
        return -11;
    }
    return result;
}

extern s32 D_00138278[];
s32 sceReadlink(const u8 *path, void *out, u32 size)
{
    struct SemaParam sp;
    s32 result;
    s32 *buf;
    s32 i;
    s32 sema;
    s32 status;
    s32 ret;

    buf = D_00145B40;
    _sceFsWaitS(0x11);
    if (D_00132414[0] == 0)
    {
        sceFsInit();
    }
    for (i = 0; i < 0x400; i++)
    {
        *((char *)buf + i + 0x14) = path[i];
        if (*((char *)buf + i + 0x14) == 0)
        {
            break;
        }
    }
    if (i == 0x400)
    {
        ((char *)buf)[0x413] = 0;
    }
    if (size >= 0x400)
    {
        size = 0x3FF;
    }
    buf[4] = (s32)out;
    buf[3] = size;
    sceSifWriteBackDCache(out, size);
    sp.maxCount = 1;
    sp.option = (u32)D_00138278;
    sp.initCount = 0;
    sema = CreateSema(&sp);
    buf[0] = sema;
    buf[1] = (s32)&result;
    buf[2] = 4;
    ret = func_0010A328(D_00147240, 0x19, 0, D_00145B40, 0x80C, D_00146780, 4, NULL, NULL, 0);
    if (ret < 0)
    {
        DeleteSema(sema);
        _sceFsSigSema();
        return -11;
    }
    status = *(s32 *)((u32)D_00146780 | 0x20000000);
    _sceFsSigSema();
    if (status != 0)
    {
        WaitSema(sema);
        DeleteSema(sema);
    }
    else
    {
        DeleteSema(sema);
        return -11;
    }
    return result;
}

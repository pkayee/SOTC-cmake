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

int CreateSema(struct SemaParam *);
int DeleteSema(int);
int SignalSema(int);
int WaitSema(int);
void *memset();
int memcmp(const void *, const void *, unsigned int);
s32 func_0010BFA8(const char *, s32);
void _sceFsIobSemaMK(void);
void _sceFsSemInit(void);
void _sceFsSigSema(void);
int _sceFsWaitS(s32 timeout);

s32 sceSifCallRpc(void *, u32, u32, void *, s32, void *, s32, void *, void *);
s32 DelayThread(u32);

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

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceFsSetIopBuf);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceFsSetIopPrio);

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

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceLseek);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceRead);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceWrite);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceIoctl);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceIoctl2);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", func_0010BFA8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceRemove);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceMkdir);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceRmdir);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceFormat);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceAddDrv);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceDelDrv);

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

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceGetstat);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceChstat);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceRename);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceChdir);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceSync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceMount);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceUmount);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceLseek64);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceDevctl);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceSymlink);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/filestub", sceReadlink);

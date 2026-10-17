#include "common.h"

extern s32 D_00133B28[];
extern s32 D_00150F40[];
extern s32 D_0014EA80[];
extern s32 D_0014EB80[];
extern s32 D_00138760[];
extern s32 D_00133B2C[];
extern s32 D_00150D00[];
extern u8 D_0014EAF8[];
extern s32 D_00138888[];
extern s32 D_001388B8[];
extern s32 D_001388D8[];
extern s32 D_00138820[];
extern s32 D_001387E0[];
extern s32 D_00138800[];
extern s32 D_001387A0[];
extern s32 D_00138780[];

s32 DeleteSema(s32);
s32 WaitSema(s32);
s32 SignalSema(s32);
s32 sceCdDelayThread();
s32 sceSifCheckStatRpc(void *);
s32 sceSifCallRpc(void *, u32, u32, void *, s32, void *, s32, void *, void *);
void SyncDCache(void *, void *);
s32 DIntr(void);
s32 EIntr(void);
extern s32 D_00150E80[];
extern s32 D_00150F00[];
extern s32 D_001387C0[];
extern s32 D_00138868[];
extern s32 D_00138948[];
extern s32 D_001388F8[];
extern s32 D_00138928[];
extern s32 D_0014EAD0[];
extern s32 D_0014EC40[];

typedef struct
{
    s32 unk[16];
} SceDbcTable;

typedef struct
{
    s32 currentCount;
    s32 maxCount;
    s32 initCount;
    s32 numWaitThreads;
    u32 attr;
    u32 option;
} SceDbcSemaParam;

extern s32 D_001386C0[];
extern s32 D_001386D8[];
extern s32 D_00138700[];
extern s32 D_00138730[];
extern s32 D_00138740[];
extern s32 D_0014EAD0[];

s32 sceDbcSetWorkAddr(s32 addr);
s32 func_00115B30(void);
s32 sceSifBindRpc(void *, u32, u32);
s32 CreateSema(void *);
void scePrintf();

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdbc", sceDbcInit);

s32 sceDbcInit(void)
{
    SceDbcSemaParam sema;
    s32 i;
    s32 j;
    s32 ret;
    s32 ver;
    s32 *work;

    if (D_00133B28[0] == 1)
    {
        return 1;
    }
    D_00150F40[0] = 0;
    sceSifInitRpc(0);
    for (;;)
    {
        ret = sceSifBindRpc(D_0014EA80, 0x80001300, 0);
        if (ret < 0)
        {
            sceCdDelayThread(D_001386C0);
            return 0;
        }
        if (D_0014EA80[9] != 0)
        {
            break;
        }
        for (i = 0x10000; i != -1; i--)
            ;
    }
    ver = func_00115B30();
    if ((ver >> 4) != 0x31)
    {
        scePrintf(D_001386D8);
        scePrintf(D_00138700, 3, 0x10, ver >> 8, ver & 0xFF);
        return 0;
    }
    for (;;)
    {
        ret = sceSifBindRpc(D_0014EAD0, 0x8000131C, 0);
        if (ret < 0)
        {
            sceCdDelayThread(D_001386C0);
            return 0;
        }
        if (D_0014EAD0[9] != 0)
        {
            break;
        }
        for (i = 0x10000; i != -1; i--)
            ;
    }
    for (j = 0; j < 2; j++)
    {
        for (;;)
        {
            ret = sceSifBindRpc((u8 *)D_0014EAF8 + j * 0x28, 0x8000131E + j, 0);
            if (ret < 0)
            {
                sceCdDelayThread(D_001386C0);
                return 0;
            }
            if (*(s32 *)((u8 *)D_0014EAF8 + j * 0x28 + 0x24) != 0)
            {
                break;
            }
            for (i = 0x10000; i != -1; i--)
                ;
        }
    }
    sema.initCount = 1;
    sema.maxCount = 0x7F;
    sema.option = (u32)D_00138730;
    ret = CreateSema(&sema);
    D_00150F40[0] = ret;
    if (ret < 0)
    {
        return 0;
    }
    for (i = 15; i >= 0; i--)
    {
        D_00150F00[i] = 0;
    }
    work = D_00150E80;
    sceCdDelayThread(D_00138740, work);
    sceDbcSetWorkAddr((s32)work);
    D_00133B28[0] = 1;
    return 1;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdbc", sceDbcEnd);

s32 sceDbcEnd(void)
{
    if (D_00133B28[0] == 0)
    {
        return 0;
    }
    D_00133B28[0] = 0;
    if (D_00150F40[0] >= 0)
    {
        DeleteSema(D_00150F40[0]);
    }
    return 1;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdbc", func_00115E70);

s32 func_00115E70(void)
{
    s32 ret;

    ret = sceSifCallRpc(D_0014EA80, 0x80001305, 0, D_0014EB80, 0x90, D_0014EB80, 0x90, NULL, NULL);
    if (ret < 0)
    {
        return 0;
    }
    return D_0014EB80[1];
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdbc", sceDbcSetWorkAddr);

s32 sceDbcSetWorkAddr(s32 addr)
{
    s32 ret;

    D_0014EB80[1] = addr;
    ret = sceSifCallRpc(D_0014EA80, 0x80001304, 0, D_0014EB80, 0x90, D_0014EB80, 0x90, NULL, NULL);
    if (ret < 0)
    {
        sceCdDelayThread(D_00138760);
        return 0;
    }
    return D_0014EB80[0];
}

/* NEARMISS-STUB sceDbcCreateSocket */
#if 0 /* NEARMISS 87.8% cat=stack-frame sub=- | frame 0x60 vs 0x70, s4 missing | attempts=1 */
s32 sceDbcCreateSocket(s32 *arg, s32 a1, s32 a2)
{
    s32 i;
    u8 *src;
    u8 *dst;
    s32 result;

    if (D_00133B28[0] == 0)
    {
        return 0;
    }
    WaitSema(D_00150F40[0]);
    D_0014EB80[0] = arg[0];
    D_0014EB80[10] = a1;
    D_0014EB80[11] = a2;
    D_0014EB80[1] = arg[1];
    D_0014EB80[2] = arg[2];
    D_0014EB80[3] = arg[3];
    D_0014EB80[4] = arg[4];
    src = (u8 *)arg + 0x14;
    dst = (u8 *)D_0014EB80 + 0x14;
    for (i = 0; i < 16; i++)
    {
        dst[i] = src[i];
    }
    if (sceSifCallRpc(D_0014EA80, 0x80001301, 0, D_0014EB80, 0x90, D_0014EB80, 0x90, NULL, NULL) < 0)
    {
        sceCdDelayThread(D_00138780);
        SignalSema(D_00150F40[0]);
        return 0;
    }
    result = D_0014EB80[9];
    SignalSema(D_00150F40[0]);
    return result;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdbc", sceDbcCreateSocket);
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdbc", sceDbcDeleteSocket);

s32 sceDbcDeleteSocket(s32 arg)
{
    s32 ret;
    s32 result;

    if (D_00133B28[0] == 0)
    {
        return 0;
    }
    WaitSema(D_00150F40[0]);
    D_0014EB80[0] = arg;
    ret = sceSifCallRpc(D_0014EA80, 0x80001302, 0, D_0014EB80, 0x90, D_0014EB80, 0x90, NULL, NULL);
    if (ret < 0)
    {
        sceCdDelayThread(D_001387A0);
        SignalSema(D_00150F40[0]);
        return 0;
    }
    result = D_0014EB80[1];
    SignalSema(D_00150F40[0]);
    return result;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdbc", sceDbcGetDepNumber);

s32 sceDbcGetDepNumber(s32 arg)
{
    s32 ret;

    SyncDCache(D_00150E80, (u8 *)D_00150E80 + 0x80);
    DIntr();
    *(SceDbcTable *)D_00150F00 = *(SceDbcTable *)D_00150E80;
    EIntr();
    if (D_00150F00[arg] != 1)
    {
        return -12;
    }
    WaitSema(D_00150F40[0]);
    D_0014EB80[0] = arg;
    ret = sceSifCallRpc(D_0014EA80, 0x80001303, 0, D_0014EB80, 0x90, D_0014EB80, 0x90, NULL, NULL);
    if (ret < 0)
    {
        sceCdDelayThread(D_001387C0);
        SignalSema(D_00150F40[0]);
        return 0;
    }
    ret = D_0014EB80[1];
    SignalSema(D_00150F40[0]);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdbc", sceDbcGetConnection);

s32 sceDbcGetConnection(s32 arg)
{
    SyncDCache(D_00150E80, (u8 *)D_00150E80 + 0x80);
    DIntr();
    *(SceDbcTable *)D_00150F00 = *(SceDbcTable *)D_00150E80;
    EIntr();
    return D_00150F00[arg] == 1 ? 1 : 3;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdbc", sceDbcInitSocket);

s32 sceDbcInitSocket(s32 arg)
{
    s32 ret;
    s32 result;

    WaitSema(D_00150F40[0]);
    D_0014EB80[0] = arg;
    ret = sceSifCallRpc(D_0014EA80, 0x80001315, 0, D_0014EB80, 0x90, D_0014EB80, 0x90, NULL, NULL);
    if (ret < 0)
    {
        sceCdDelayThread(D_001387E0);
        SignalSema(D_00150F40[0]);
        return 0;
    }
    result = D_0014EB80[1];
    SignalSema(D_00150F40[0]);
    return result;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdbc", sceDbcResetSocket);

s32 sceDbcResetSocket(s32 arg)
{
    s32 ret;
    s32 result;

    WaitSema(D_00150F40[0]);
    D_0014EB80[0] = arg;
    ret = sceSifCallRpc(D_0014EA80, 0x80001316, 0, D_0014EB80, 0x90, D_0014EB80, 0x90, NULL, NULL);
    if (ret < 0)
    {
        sceCdDelayThread(D_00138800);
        SignalSema(D_00150F40[0]);
        return 0;
    }
    result = D_0014EB80[1];
    SignalSema(D_00150F40[0]);
    return result;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdbc", sceDbcGetDeviceStatus);

s32 sceDbcGetDeviceStatus(s32 status)
{
    s32 ret;
    s32 result;

    WaitSema(D_00150F40[0]);
    D_0014EB80[0] = status;
    ret = sceSifCallRpc(D_0014EA80, 0x80001317, 0, D_0014EB80, 0x90, D_0014EB80, 0x90, NULL, NULL);
    if (ret < 0)
    {
        sceCdDelayThread(D_00138820);
        SignalSema(D_00150F40[0]);
        return 0;
    }
    result = D_0014EB80[1];
    SignalSema(D_00150F40[0]);
    return result;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdbc", sceDbcSearchPortSpecific);

s32 sceDbcSearchPortSpecific(s32 *arg)
{
    s32 ret;
    s32 result;

    WaitSema(D_00150F40[0]);
    D_0014EB80[2] = 2;
    D_0014EB80[4] = arg[2];
    D_0014EB80[5] = arg[3];
    ret = sceSifCallRpc(D_0014EA80, 0x8000131D, 0, D_0014EB80, 0x90, D_0014EB80, 0x90, NULL, NULL);
    if (ret < 0)
    {
        sceCdDelayThread(D_00138820);
        SignalSema(D_00150F40[0]);
        return -1;
    }
    result = D_0014EB80[1];
    SignalSema(D_00150F40[0]);
    return result;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdbc", sceDbcSRData);

/* NEARMISS-STUB sceDbcSendData */
#if 0 /* NEARMISS 94.8% cat=regalloc sub=- | s-reg alloc: buf/len/lui s5, frame 0x80 vs 0x70 | attempts=1 */
s32 sceDbcSendData(s32 arg0, s32 arg1, s32 *len, u8 *data)
{
    s32 *buf;
    u8 *dst;
    s32 i;
    s32 ret;
    s32 result;

    WaitSema(D_00150F40[0]);
    buf = D_0014EB80;
    buf[0] = arg0;
    buf[1] = arg1;
    buf[2] = *len;
    dst = (u8 *)buf + 0xC;
    for (i = 0; i < *len; i++)
    {
        dst[i] = data[i];
    }
    ret = sceSifCallRpc(D_0014EA80, 0x80001319, 0, D_0014EB80, 0x90, D_0014EB80, 0x90, NULL, NULL);
    if (ret < 0)
    {
        sceCdDelayThread(D_00138868);
        SignalSema(D_00150F40[0]);
        return 0;
    }
    result = buf[35];
    if (result >= 0)
    {
        *len = buf[2];
    }
    SignalSema(D_00150F40[0]);
    return result;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdbc", sceDbcSendData);

/* NEARMISS-STUB sceDbcSendData2 */
#if 0 /* NEARMISS 78.95% cat=regalloc sub=- | reg mapping, idx reload after check call, 2-arg sceCdDelayThread | attempts=1 */
s32 sceDbcSendData2(s32 arg0, s32 arg1, s32 *len, u8 *data)
{
    s32 i;
    s32 *slot;
    s32 ret;

    if (*len > 0x80)
    {
        sceCdDelayThread(D_00138888, *len);
        return 0;
    }
    WaitSema(D_00150F40[0]);
    D_00133B2C[0]++;
    if (D_00133B2C[0] >= 2)
    {
        D_00133B2C[0] = 0;
    }
    slot = (s32 *)((u8 *)D_00150D00 + D_00133B2C[0] * 0xC0);
    slot[0] = arg0;
    slot[1] = arg1;
    slot[2] = *len;
    for (i = 0; i < *len; i++)
    {
        ((u8 *)slot + 0xC)[i] = data[i];
    }
    if (sceSifCheckStatRpc((u8 *)D_0014EAF8 + D_00133B2C[0] * 0x28) == 1)
    {
        sceCdDelayThread(D_001388B8);
        SignalSema(D_00150F40[0]);
        return 0;
    }
    ret = sceSifCallRpc((u8 *)D_0014EAF8 + D_00133B2C[0] * 0x28, D_00133B2C[0], 1, slot, 0x90, slot, 0x90, NULL, NULL);
    if (ret >= 0)
    {
        SignalSema(D_00150F40[0]);
        return 1;
    }
    sceCdDelayThread(D_001388D8);
    SignalSema(D_00150F40[0]);
    return 0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdbc", sceDbcSendData2);

/* NEARMISS-STUB sceDbcSendData3 */
#if 0 /* NEARMISS 95.5% cat=regalloc sub=- | lui v0 vs a3 for buf store, return layout | attempts=1 */
s32 sceDbcSendData3(s32 arg0, s32 arg1, s32 *len, u8 *data, void *arg4)
{
    s32 i;
    s32 *buf;
    s32 ret;

    if (*len > 0x2080)
    {
        sceCdDelayThread(D_001388F8, *len);
        return 0;
    }
    WaitSema(D_00150F40[0]);
    if (sceSifCheckStatRpc(D_0014EAD0) == 1)
    {
        sceCdDelayThread(D_00138928);
        SignalSema(D_00150F40[0]);
        return 0;
    }
    buf = D_0014EC40;
    buf[0] = arg0;
    buf[1] = arg1;
    buf[2] = *len;
    for (i = 0; i < *len; i++)
    {
        ((u8 *)buf + 0xC)[i] = data[i];
    }
    ret = sceSifCallRpc(D_0014EAD0, 0x8000131C, 1, buf, 0x2090, buf, 0x2090, arg4, NULL);
    if (ret < 0)
    {
        SignalSema(D_00150F40[0]);
        return 0;
    }
    SignalSema(D_00150F40[0]);
    return 1;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdbc", sceDbcSendData3);

/* NEARMISS-STUB sceDbcReceiveData */
#if 0 /* NEARMISS 96.97% cat=regalloc sub=- | copy loop address form (src ptr+i) | attempts=1 */
s32 sceDbcReceiveData(s32 arg0, s32 arg1, s32 *len, u8 *data)
{
    s32 i;
    s32 *buf;
    s32 ret;
    s32 result;

    WaitSema(D_00150F40[0]);
    buf = D_0014EB80;
    buf[0] = arg0;
    buf[1] = arg1;
    buf[2] = *len;
    ret = sceSifCallRpc(D_0014EA80, 0x8000131A, 0, buf, 0x90, buf, 0x90, NULL, NULL);
    if (ret < 0)
    {
        sceCdDelayThread(D_00138948);
        SignalSema(D_00150F40[0]);
        return 0;
    }
    result = buf[35];
    if (result >= 0)
    {
        *len = buf[2];
        for (i = 0; i < buf[2]; i++)
        {
            data[i] = ((u8 *)buf + 0xC)[i];
        }
        result = buf[35];
    }
    SignalSema(D_00150F40[0]);
    return result;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libdbc", sceDbcReceiveData);

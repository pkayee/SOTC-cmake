#include "common.h"

extern s32 D_00135A58[];

s32 _sceMcCoreAuthentication(void);
s32 _sceMcCoreCheckNewCard(void);
s32 _sceMcCoreGetCardSpec(void);
s32 _sceMcpReadUserClustOnCache(void);
s32 _sceMcpWriteUserClustOnCache(void);
s32 func_00119598(s32, s32, s32, s32, s32);
s32 func_0011B770(s32, s32, s32);
s32 sce_sync(s32);
s32 sceInetInterfaceControl(void *, void *, s32, s32, void *, s32);
s32 sceSifMBindRpcParam(void *, u32, u32, u32, u32, s32);
s32 sceSifDmaStat(u32);
void sceSifRemoveCmdHandler(u32);
void sceSifRemoveRebootNotifyHandler(u32);
extern s32 D_00135718[];
extern s32 D_00151FA0[];
s32 func_00119770(void *, void *, s32 *, s32, void *, s32);
s32 func_00119808(void *, void *, s32 *, s32, void *, s32);
s32 ChangeThreadPriority(s32, s32);
s32 iChangeThreadPriority(s32, s32);
s32 sceDbcGetConnection(s32);
s32 sce_call_rpc(void *, void *, s32);
s32 sceNetcnfifSetup(void);
s32 sceNetcnfifInit(void);
s32 sceNetcnfifFreeWorkarea(void);
void *memset(void *, s32, u32);
s32 CallRpc(void *, s32, void *, s32, s32);
s32 _sceMcCoreReadPage(s32, s32, s32, s32);
s32 _sceMcCoreWritePage(s32, s32, s32, s32);
s32 _sceMcpIsSpeckOutBlock(s32, s32);
s32 sceMc2GetInfoAsync(s32, void *);
s32 sceMc2FormatAsync(s32);
s32 sceMc2UnformatAsync(s32);
s32 sceMc2ReadFileAsync(s32, s32, s32, s32);
s32 sceMc2WriteFileAsync(s32, s32, s32, s32);
s32 sceMc2CreateFileAsync(s32, s32);
s32 sceMc2DeleteAsync(s32, s32);
s32 sceMc2RenameAsync(s32, s32, s32);
s32 sceMc2MkdirAsync(s32, s32);
s32 sceMc2ChdirAsync(s32, s32, s32);
s32 sceMc2GetDirAsync(s32, s32, s32, s32);
s32 sceMc2ChmodAsync(s32, s32, s32);
s32 sceMc2GetEntSpaceAsync(s32, s32);
s32 sceMc2SearchFileAsync(s32, s32, s32, s32);
extern s32 D_00168040[];
extern s32 D_00168080[];
extern s32 D_00135A5C[];
char *strcpy(char *, const char *);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", CallRpc);

/* NEARMISS-STUB MemcpyD */
#if 0 /* NEARMISS 74.0% cat=regalloc sub=- | dst/off<<2 CSE into v1; target dst in v1 | attempts=1 */
void *memcpy(void *dst, const void *src, u32 n);

s32 MemcpyD(s32 *obj, u8 *dst, s32 off, void *src, s32 n)
{
    s32 rem = obj[12] - (off << 2);

    if (src == NULL)
    {
        return 0;
    }
    if (n < 0 || rem < n)
    {
        return -0x21F;
    }
    memcpy(dst + (off << 2), src, n);
    return 0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", MemcpyD);

/* NEARMISS-STUB MemcpyS */
#if 0 /* NEARMISS 77.0% cat=regalloc sub=- | target src in v1, loads obj[12] before null check | attempts=1 */
void *memcpy(void *dst, const void *src, u32 n);

s32 MemcpyS(s32 *obj, u8 *dst, u8 *src, s32 off, s32 n)
{
    s32 rem = obj[12] - (off << 2);

    if (dst == NULL)
    {
        return 0;
    }
    if (n < 0 || rem < n)
    {
        return -0x21F;
    }
    memcpy(dst, src + (off << 2), n);
    return 0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", MemcpyS);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", StrcpyD);

s32 StrcpyS(char *dst, char *src, s32 n)
{
    if (dst == NULL)
    {
        return 0;
    }
    strcpy(dst, src + n * 4);
    return 0;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetPoll);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetName2Address);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetAddress2String);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetAddress2Name);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetCreate);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetOpen);
s32 sceInetOpen(void *cd, s32 *net_buf, s32 a2, s32 a3)
{
    s32 ret;

    net_buf[0] = a2;
    net_buf[1] = a3;
    ret = CallRpc(cd, 2, net_buf, 8, 4);
    if (ret < 0)
    {
        return -0x21E;
    }
    return net_buf[0];
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetClose);
s32 sceInetClose(void *cd, s32 *net_buf, s32 a2, s32 a3)
{
    s32 ret;

    net_buf[0] = a2;
    net_buf[1] = a3;
    ret = CallRpc(cd, 3, net_buf, 8, 4);
    if (ret < 0)
    {
        return -0x21E;
    }
    return net_buf[0];
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetRecv);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetRecvFrom);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetSend);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetSendTo);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetAbort);
s32 sceInetAbort(void *cd, s32 *net_buf, s32 a2, s32 a3)
{
    s32 ret;

    net_buf[0] = a2;
    net_buf[1] = a3;
    ret = CallRpc(cd, 0xF, net_buf, 8, 4);
    if (ret < 0)
    {
        return -0x21E;
    }
    return net_buf[0];
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetControl);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetGetInterfaceList);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetInterfaceControl);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetGetRoutingTable);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetGetNameServers);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetChangeThreadPriority);
s32 sceInetChangeThreadPriority(void *cd, s32 *net_buf, s32 a2)
{
    s32 ret;

    net_buf[0] = a2;
    ret = CallRpc(cd, 0xC, net_buf, 4, 4);
    if (ret < 0)
    {
        return -0x21E;
    }
    return net_buf[0];
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetGetLog);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetAbortLog);
s32 sceInetAbortLog(void *cd, s32 *net_buf)
{
    s32 ret = CallRpc(cd, 0x10, net_buf, 0, 4);
    if (ret < 0)
    {
        return -0x21E;
    }
    return net_buf[0];
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetCtlUpInterface);
s32 sceInetCtlUpInterface(void *cd, s32 *net_buf, s32 a2)
{
    s32 ret;

    net_buf[0] = a2;
    ret = CallRpc(cd, 0x32, net_buf, 4, 4);
    if (ret < 0)
    {
        return -0x21E;
    }
    return net_buf[0];
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetCtlDownInterface);
s32 sceInetCtlDownInterface(void *cd, s32 *net_buf, s32 a2)
{
    s32 ret;

    net_buf[0] = a2;
    ret = CallRpc(cd, 0x33, net_buf, 4, 4);
    if (ret < 0)
    {
        return -0x21E;
    }
    return net_buf[0];
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetCtlSetAutoMode);
s32 sceInetCtlSetAutoMode(void *cd, s32 *net_buf, s32 a2)
{
    s32 ret;

    net_buf[0] = a2;
    ret = CallRpc(cd, 0x34, net_buf, 4, 4);
    if (ret < 0)
    {
        return -0x21E;
    }
    return net_buf[0];
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetCtlGetState);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetInitialize);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetTerminate);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetRegisterHandler);
s32 sceLibnetRegisterHandler(void *cd, s32 *net_buf)
{
    s32 ret = CallRpc(cd, 0x1E, net_buf, 0, 4);
    if (ret < 0)
    {
        return -0x21E;
    }
    return net_buf[0];
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetUnregisterHandler);
s32 sceLibnetUnregisterHandler(void *cd, s32 *net_buf)
{
    s32 ret = CallRpc(cd, 0x1F, net_buf, 0, 4);
    if (ret < 0)
    {
        return -0x21E;
    }
    return net_buf[0];
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetSetConfiguration);
s32 sceLibnetSetConfiguration(void *cd, s32 *net_buf, s32 a2)
{
    s32 ret;

    net_buf[0] = a2;
    ret = CallRpc(cd, 0x20, net_buf, 4, 4);
    if (ret < 0)
    {
        return -0x21E;
    }
    return net_buf[0];
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119598);

s32 func_00119628(s32 a0, s32 a1, s32 a2, s32 a3)
{
    return func_00119598(a0, a1, a2, a3, 0x21);
}

s32 func_00119648(s32 a0, s32 a1, s32 a2, s32 a3)
{
    return func_00119598(a0, a1, a2, a3, 0x22);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119668);

s32 func_00119748(void *a0, void *a1, s32 a2, void *a3)
{
    return sceInetInterfaceControl(a0, a1, a2, 9, a3, 0x10);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119770);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119808);
s32 func_00119808(void *cd, void *net_buf, s32 *if_id, s32 n, void *addr, s32 flags)
{
    s32 ret;

    ret = func_00119648((s32)cd, (s32)net_buf, (s32)if_id, n);
    if (ret < 0)
    {
        return ret;
    }
    ret = func_00119748(cd, net_buf, if_id[0], addr);
    if (ret < 0)
    {
        return ret;
    }
    return 0;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetWaitGetInterfaceID);

/* NEARMISS-STUB sceLibnetWaitGetAddress */
#if 0 /* NEARMISS 95.4% cat=regalloc sub=- | gcc folds flags&2 to 0 in else-branch and emits daddu a5,zero,zero where target passes the andi result unchanged (nop in delay slot); no C form found yet | attempts=1 */
s32 sceLibnetWaitGetAddress(void *cd, void *net_buf, s32 *if_id, s32 n, void *addr, u32 flags)
{
    if (flags & 2)
    {
        return func_00119770(cd, net_buf, if_id, n, addr, flags & 2);
    }
    return func_00119808(cd, net_buf, if_id, n, addr, flags & 2);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetWaitGetAddress);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetWaitGetInterfaceEvent);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceSifMInitRpc);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119AA0);

void sceSifMExitRpc(void)
{
    D_00135718[0] = 0;
    sceSifRemoveCmdHandler(0x80000018);
    sceSifRemoveRebootNotifyHandler(0x80000014);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119AF8);

/* NEARMISS-STUB func_00119BA0 */
#if 0 /* NEARMISS 73.6% cat=regalloc sub=ee-gcc2.9-991111 | 73.6% best: v & -2 materialised lui/ori with different reg alloc (mask 0xFFFFFFFE); sdk segment ee-gcc2.9 -O2 -G0; attempt comment from kS10 diff | attempts=1 */
// 73.6% best (mask 0xFFFFFFFE lui/ori reg alloc)
void func_00119BA0(s32 *arg0) { s32 v = arg0[4]; arg0[6] = 0; arg0[4] = v & -2; }
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119BA0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119BC0);

s32 sceSifMBindRpc(void *cd, u32 a1, u32 a2)
{
    return sceSifMBindRpcParam(cd, a1, a2, 0x800, 0x2000, 0x20);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceSifMBindRpcParam);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceSifMUnBindRpc);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceSifMCallRpc);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2Init);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2End);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2CreateSocket);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2DeleteSocket);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2SearchSocket);

s32 sceMc2ChangeThreadPriority(s32 prio)
{
    if (prio <= 0)
    {
        return 0x81010016;
    }
    ChangeThreadPriority(D_00151FA0[0], prio);
    return 0;
}

s32 sceMc2iChangeThreadPriority(s32 prio)
{
    if (prio <= 0)
    {
        return 0x81010016;
    }
    iChangeThreadPriority(D_00151FA0[0], prio);
    return 0;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2FormatAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2UnformatAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2GetInfoAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2SearchFileAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2GetDirAllAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2ReadFileAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2WriteFileAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2CreateFileAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2DeleteAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2GetDirAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2MkdirAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2ChdirAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2ChmodAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2RenameAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2GetEntSpaceAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011B558);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011B770);

s32 sceMc2CheckAsync(s32 a0, s32 a1)
{
    return func_0011B770(1, a0, a1);
}

s32 sceMc2Sync(s32 a0, s32 a1)
{
    return func_0011B770(0, a0, a1);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2GetInfo);
s32 sceMc2GetInfo(s32 a0, void *a1)
{
    s32 ret = sceMc2GetInfoAsync(a0, a1);
    if (ret != 0)
    {
        return ret;
    }
    func_0011B770(0, 0, (s32)&ret);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2Format);
s32 sceMc2Format(s32 a0)
{
    s32 ret = sceMc2FormatAsync(a0);
    if (ret != 0)
    {
        return ret;
    }
    func_0011B770(0, 0, (s32)&ret);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2Unformat);
s32 sceMc2Unformat(s32 a0)
{
    s32 ret = sceMc2UnformatAsync(a0);
    if (ret != 0)
    {
        return ret;
    }
    func_0011B770(0, 0, (s32)&ret);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2ReadFile);
s32 sceMc2ReadFile(s32 a0, s32 a1, s32 a2, s32 a3)
{
    s32 ret = sceMc2ReadFileAsync(a0, a1, a2, a3);
    if (ret != 0)
    {
        return ret;
    }
    func_0011B770(0, 0, (s32)&ret);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2WriteFile);
s32 sceMc2WriteFile(s32 a0, s32 a1, s32 a2, s32 a3)
{
    s32 ret = sceMc2WriteFileAsync(a0, a1, a2, a3);
    if (ret != 0)
    {
        return ret;
    }
    func_0011B770(0, 0, (s32)&ret);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2CreateFile);
s32 sceMc2CreateFile(s32 a0, s32 a1)
{
    s32 ret = sceMc2CreateFileAsync(a0, a1);
    if (ret != 0)
    {
        return ret;
    }
    func_0011B770(0, 0, (s32)&ret);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2Delete);
s32 sceMc2Delete(s32 a0, s32 a1)
{
    s32 ret = sceMc2DeleteAsync(a0, a1);
    if (ret != 0)
    {
        return ret;
    }
    func_0011B770(0, 0, (s32)&ret);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2Rename);
s32 sceMc2Rename(s32 a0, s32 a1, s32 a2)
{
    s32 ret = sceMc2RenameAsync(a0, a1, a2);
    if (ret != 0)
    {
        return ret;
    }
    func_0011B770(0, 0, (s32)&ret);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2Mkdir);
s32 sceMc2Mkdir(s32 a0, s32 a1)
{
    s32 ret = sceMc2MkdirAsync(a0, a1);
    if (ret != 0)
    {
        return ret;
    }
    func_0011B770(0, 0, (s32)&ret);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2Chdir);
s32 sceMc2Chdir(s32 a0, s32 a1, s32 a2)
{
    s32 ret = sceMc2ChdirAsync(a0, a1, a2);
    if (ret != 0)
    {
        return ret;
    }
    func_0011B770(0, 0, (s32)&ret);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2GetDir);
s32 sceMc2GetDir(s32 a0, s32 a1, s32 a2, s32 a3)
{
    s32 ret = sceMc2GetDirAsync(a0, a1, a2, a3);
    if (ret != 0)
    {
        return ret;
    }
    func_0011B770(0, 0, (s32)&ret);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2Chmod);
s32 sceMc2Chmod(s32 a0, s32 a1, s32 a2)
{
    s32 ret = sceMc2ChmodAsync(a0, a1, (u16)a2);
    if (ret != 0)
    {
        return ret;
    }
    func_0011B770(0, 0, (s32)&ret);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2SearchFile);
s32 sceMc2SearchFile(s32 a0, s32 a1, s32 a2, s32 a3)
{
    s32 ret = sceMc2SearchFileAsync(a0, a1, a2, a3);
    if (ret != 0)
    {
        return ret;
    }
    func_0011B770(0, 0, (s32)&ret);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2GetEntSpace);
s32 sceMc2GetEntSpace(s32 a0, s32 a1)
{
    s32 ret = sceMc2GetEntSpaceAsync(a0, a1);
    if (ret != 0)
    {
        return ret;
    }
    func_0011B770(0, 0, (s32)&ret);
    return ret;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011BBE8);

/* NEARMISS-STUB func_0011BC48 */
#if 0 /* NEARMISS 68.0% cat=branch-layout sub=- | two separate sltiu return sequences | attempts=1 */
char *strchr(char *, s32);
char *strrchr(char *, s32);
u32 strlen(char *);

s32 func_0011BC48(char *name)
{
    u32 len;

    if (strchr(name, 0x2F) != NULL)
    {
        len = strlen(strrchr(name, 0x2F) + 1);
    }
    else
    {
        len = strlen(name);
    }
    if (len < 0x20)
    {
        return 1;
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011BC48);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011BCB8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011BD10);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011BDC8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011BF48);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C068);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C0B0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatInit);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatInit2);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C300);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C420);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C4B0);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C5C8);
s32 func_0011C4B0(s32, s32, s32, s32);

s32 func_0011C5C8(s32 a0, s32 a1, s32 *a2, s32 a3)
{
    s32 ret = func_0011C4B0(a0, a1, (s32)a2, a3);
    if (ret == 0x7FFFFFFF)
    {
        *a2 = 0x81019002;
    }
    return ret;
}

/* NEARMISS-STUB func_0011C610 */
#if 0 /* NEARMISS 62.0% cat=branch-layout sub=- | a2 reload and ret&0x7FFFFFFF path | attempts=1 */
s32 func_0011C5C8(s32, s32, s32 *, s32);

s32 func_0011C610(s32 a0, s32 a1, s32 *a2, s32 a3)
{
    s32 ret = func_0011C5C8(a0, a1, a2, a3);

    if (*a2 != 0)
    {
        return 0;
    }
    if (ret == -1)
    {
        *a2 = 0x81010059;
        return -1;
    }
    return ret & 0x7FFFFFFF;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C610);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C678);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C7A8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C8D8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C9B0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011CB30);

/* NEARMISS-STUB func_0011CBC0 */
#if 0 /* NEARMISS 88.0% cat=regalloc sub=- | target loads u16 once into a2/a3, struct base v1 | attempts=1 */
s32 _sceMcCoreSetCardSpec(s32, s32, s32, s32);

s32 func_0011CBC0(s32 a0, s32 *a1)
{
    s32 spec[4];
    s32 n = ((u16 *)a1)[0x14];
    s32 m = ((u16 *)a1)[0x16];

    spec[0] = n;
    spec[1] = m;
    spec[2] = (a1[12] << 10) / n;
    spec[3] = 1;
    return _sceMcCoreSetCardSpec(a0, (s32)spec, n, m);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011CBC0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatGetInfo);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatFormat);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatUnFormat);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011D9E0);

/* NEARMISS-STUB func_0011DA88 */
#if 0 /* NEARMISS 62.0% cat=branch-layout sub=- | target selects const via movn on callee result | attempts=1 */
s32 func_0011C0B0(s32, s32, s32, s32);
s32 func_0011BCB8(s32);
s32 func_0011BC48(char *);

s32 func_0011DA88(s32 a0, s32 a1, s32 a2, s32 a3)
{
    s32 ret;

    if (func_0011C0B0(a0, a1, a2, a3) != 0)
    {
        if (func_0011BCB8(a2) != 0)
        {
            ret = func_0011BC48((char *)a2);
            if (ret != 0)
            {
                return 0;
            }
            return 0x8101005B;
        }
    }
    return 0x81010016;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011DA88);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011DAE8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011DD60);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011E1B0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011E358);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011E488);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011E958);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatSearchFile);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatCreateFile);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatReadFile);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatWriteFile);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatDeleteFile);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatChDir);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatGetDir);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatSetAttr);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatRename);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatGetEntSpace);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpInit);

s32 _sceMcpGetCardSpec(void)
{
    return _sceMcCoreGetCardSpec();
}

s32 _sceMcpCheckNewCard(void)
{
    return _sceMcCoreCheckNewCard();
}

s32 _sceMcpAuthentication(void)
{
    return _sceMcCoreAuthentication();
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpReadSysInfo);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpWriteSysInfo);

/* NEARMISS-STUB _sceMcpReadClust */
#if 0 /* NEARMISS 90.0% cat=sched sub=- | target puts mflo a2 in jal delay slot (mult;jal;mflo); gcc 2.9 keeps mflo before jal and nop in slot; struct McpClust 0x184 with u16 2A/2C matched the rest; n*a | attempts=1 */
typedef struct
{
    u8 unk00[0x2A];
    u16 unk2A;
    u16 unk2C;
    u8 unk2E[0x184 - 0x2E];
} McpClust;

extern McpClust D_00135738[];

s32 _sceMcpReadClust(s32 a0, s32 a1, s32 a2, s32 a3)
{
    McpClust *p = &D_00135738[a0];
    u16 n = p->unk2A;
    return _sceMcCoreReadPage(a0, a1, a2 * n, n * a3);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpReadClust);

/* NEARMISS-STUB _sceMcpWriteClust */
#if 0 /* NEARMISS 90.0% cat=sched sub=- | same as ReadClust: mflo a2 belongs in jal delay slot, gcc 2.9 leaves nop | attempts=1 */
s32 _sceMcpWriteClust(s32 a0, s32 a1, s32 a2, s32 a3)
{
    McpClust *p = &D_00135738[a0];
    u16 n = p->unk2A;
    return _sceMcCoreWritePage(a0, a1, a2 * n, n * a3);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpWriteClust);

/* NEARMISS-STUB _sceMcpFlushCache */
#if 0 /* NEARMISS 73.0% cat=regalloc sub=- | mult index plus s0/s1 pointers | attempts=1 */
extern s32 D_0015F600[];

s32 _sceMcpWriteClust(s32, s32, s32, s32);

s32 _sceMcpFlushCache(s32 a0)
{
    s32 *blk = (s32 *)((u8 *)D_0015F600 + a0 * 0x2010);
    s32 ret;

    if (blk[0] == -1)
    {
        return 1;
    }
    ret = _sceMcpWriteClust(a0, (s32)(blk + 4), blk[0], blk[3]);
    blk[0] = -1;
    blk[3] = 0;
    return ret;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpFlushCache);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpWriteUserClustOnCache);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpReadUserClustOnCache);

s32 _sceMcpReadUserClust(void)
{
    return _sceMcpReadUserClustOnCache();
}

s32 _sceMcpWriteUserClust(void)
{
    return _sceMcpWriteUserClustOnCache();
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpIsSpeckOutBlock);

/* NEARMISS-STUB _sceMcpIsSpeckOutClust */
#if 0 /* NEARMISS 91.1% cat=sched sub=- | same as ReadClust: mflo a1 belongs in div/jal delay slot (target), gcc 2.9 leaves nop | attempts=1 */
s32 _sceMcpIsSpeckOutClust(s32 a0, s32 a1)
{
    McpClust *p = &D_00135738[a0];
    u16 n = p->unk2A;
    u16 m = p->unk2C;
    return _sceMcpIsSpeckOutBlock(a0, a1 * n / m);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpIsSpeckOutClust);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpMakeSpecoutBlock);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _SceMcComGetSysInfo);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00121030);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00121100);
extern s32 D_00163E40[];
extern s32 D_00165F40[];

s32 WaitSema(s32);
void SyncDCache(void *, void *);

s32 *func_00121100(void)
{
    s32 *p = D_00165F40;

    WaitSema(D_00163E40[0]);
    SyncDCache(p, (u8 *)p + 0x7F);
    if (D_00165F40[0] <= 0)
    {
        p[2] = 0;
    }
    return p;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00121158);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreInit);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreEnd);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreSetWriteBackHole);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreSetCardSpec);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreGetCardSpec);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreCheckNewCard);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreClearNewCardFlag);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreAuthentication);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreWriteBack);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreReadClock);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreReadPage2);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreReadPage);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreWritePage);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreWriteSameData);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreBlockErase);

typedef struct
{
    s32 unk00;
    s32 unk04;
    s32 unk08[7];
} McConnection;

extern McConnection D_00163E48[];

s32 _sceMcCoreGetConnection(s32 a0)
{
    return sceDbcGetConnection(D_00163E48[a0].unk04) != 3;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00121FC0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreCreateSocket);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreCheckSocket);

/* NEARMISS-STUB _sceMcCoreDeleteSocket */
#if 0 /* NEARMISS 83.0% cat=stack-frame sub=- | frame 0x40 keeps a0 in s2, 0x24 in s1 | attempts=1 */
s32 _sceMcCoreCheckSocket(s32);
s32 sceDbcDeleteSocket(s32);

s32 _sceMcCoreDeleteSocket(s32 a0)
{
    McConnection *conn;

    if (_sceMcCoreCheckSocket(a0) == 0)
    {
        return 0;
    }
    conn = &D_00163E48[a0];
    sceDbcDeleteSocket(conn->unk04);
    conn->unk00 = 0;
    return 1;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreDeleteSocket);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreChangeSocketTypeDbc2Mc);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreChangeSocketTypeMc2Dbc);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifSetup);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifInit);
s32 sceNetcnfifInit(void)
{
    s32 ret = sceNetcnfifSetup();
    memset(D_00168080, 0, 0x310);
    return ret;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifCreateCallbackThread);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifDeleteCallbackThread);
void sce_delete_callback_thread();
s32 sceSifCallRpc(void *, u32, u32, void *, s32, void *, s32, void *, void *);

s32 sceNetcnfifDeleteCallbackThread(void)
{
    s32 ret;

    sce_delete_callback_thread();
    sceNetcnfifInit();
    ret = sceSifCallRpc(D_00168040, 0xF, 0, D_00168080, 0x1000, D_00168080, 0x1000, 0, 0);
    if (ret < 0)
    {
        return ret;
    }
    return 0;
}

s32 sceNetcnfifSync(s32 a0)
{
    return sce_sync(a0);
}

s32 sceNetcnfifCheck(void)
{
    return sce_sync(1);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifGetResult);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifSetFNoDecode);
s32 sceNetcnfifSetFNoDecode(s32 arg0)
{
    D_00135A58[0] = arg0;
    return 0;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifGetCount);
s32 sceNetcnfifGetCount(char *name, s32 val)
{
    s32 *buf;

    sceNetcnfifInit();
    buf = D_00168080;
    strcpy((char *)buf + 0x10, name);
    buf[2] = val;
    return sce_call_rpc(D_00168040, buf, 0);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifGetList);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifLoadEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifLoadEntryAuto);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifAddEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifEditEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifDeleteEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifSetLatestEntry);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifDeleteAll);
s32 sceNetcnfifDeleteAll(char *name)
{
    s32 *buf;

    sceNetcnfifInit();
    buf = D_00168080;
    strcpy((char *)buf + 0x10, name);
    return sce_call_rpc(D_00168040, buf, 7);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifCheckCapacity);
s32 sceNetcnfifCheckCapacity(char *name)
{
    s32 *buf;

    sceNetcnfifInit();
    buf = D_00168080;
    strcpy((char *)buf + 0x10, name);
    return sce_call_rpc(D_00168040, buf, 8);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifCheckAdditionalAT);
s32 sceNetcnfifCheckAdditionalAT(char *name)
{
    s32 *buf;

    sceNetcnfifInit();
    buf = D_00168080;
    strcpy((char *)buf + 0x10, name);
    return sce_call_rpc(D_00168040, buf, 9);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifCheckSpecialProvider);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifGetAddr);
s32 sceNetcnfifGetAddr(void)
{
    sceNetcnfifInit();
    return sce_call_rpc(D_00168040, D_00168080, 0x64);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifAllocWorkarea);
s32 sceNetcnfifAllocWorkarea(s32 a0)
{
    sceNetcnfifInit();
    D_00168080[0] = a0;
    return sce_call_rpc(D_00168040, D_00168080, 0x65);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifFreeWorkarea);
s32 sceNetcnfifFreeWorkarea(void)
{
    sceNetcnfifInit();
    return sce_call_rpc(D_00168040, D_00168080, 0x66);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifSetEnv);
s32 sceNetcnfifSetEnv(s32 a0)
{
    sceNetcnfifInit();
    D_00168080[1] = D_00135A58[0];
    D_00168080[2] = a0;
    return sce_call_rpc(D_00168040, D_00168080, 0x67);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifTerm);
s32 sceNetcnfifTerm(void)
{
    s32 ret = sceNetcnfifFreeWorkarea();
    sce_sync(0);
    D_00135A5C[0] = 0;
    return ret;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00122FA8);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00123090);
extern s32 D_0016A090[];
extern s32 D_0016A0D8[];
extern s32 D_00169080[];

s32 sceSifInitRpc(s32);
s32 GetThreadId(void);
s32 sceSifSetRpcQueue(void *, s32);
s32 sceSifRegisterRpc(void *, u32, void *, void *, s32, s32, void *);
s32 sceSifRpcLoop(void *);
void func_00122FA8(void);

void func_00123090(void)
{
    sceSifInitRpc(0);
    sceSifSetRpcQueue(D_0016A0D8, GetThreadId());
    sceSifRegisterRpc(D_0016A090, 0x80001101, (void *)func_00122FA8, D_00169080, 0, 0, D_0016A0D8);
    sceSifRpcLoop(D_0016A0D8);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sce_create_callback_thread);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sce_delete_callback_thread);
extern s32 D_0016A090[];
extern s32 D_0016A0D8[];

s32 sceSifRemoveRpc(void *, void *);
s32 sceSifRemoveRpcQueue(void *);
s32 DeleteThread(s32);
s32 TerminateThread(s32);

void sce_delete_callback_thread(s32 thread)
{
    sceSifRemoveRpc(D_0016A090, D_0016A0D8);
    sceSifRemoveRpcQueue(D_0016A0D8);
    TerminateThread(thread);
    DeleteThread(thread);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifSendIOP);
u32 sceSifSetDma(void *, s32);
void FlushCache(s32);

s32 sceNetcnfifSendIOP(s32 a0, s32 a1, s32 a2)
{
    s32 dma[4];
    s32 low = a2 & 0x3F;

    a2 = a2 & 0xFFFFFFC0;
    dma[0] = a0;
    dma[1] = a1;
    dma[2] = (low == 0) ? a2 : a2 + 0x40;
    dma[3] = 0;
    FlushCache(0);
    return sceSifSetDma(dma, 1);
}

s32 sceNetcnfifDmaCheck(u32 id)
{
    return ((u32)~sceSifDmaStat(id)) >> 31;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00123280);

/* NEARMISS-STUB func_001232A8 */
#if 0 /* NEARMISS 76.0% cat=branch-layout sub=- | target reloads D after sw, returns via bltz delay slot; we emit movz | attempts=1 */
extern s32 D_00135A60[];
extern s32 D_00138EF0[];

s32 CreateSema(s32 *);

s32 func_001232A8(void)
{
    s32 param[8];

    if (D_00135A60[0] >= 0)
    {
        return -1;
    }
    param[1] = 1;
    param[2] = 0;
    param[5] = (s32)D_00138EF0;
    D_00135A60[0] = CreateSema(param);
    if (D_00135A60[0] < 0)
    {
        return -1;
    }
    return D_00135A60[0];
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_001232A8);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00123308);
extern s32 D_00135A60[];

s32 DIntr(void);
s32 EIntr(void);
s32 DeleteSema(s32);

s32 func_00123308(void)
{
    s32 stat = DIntr();
    s32 sema = D_00135A60[0];

    D_00135A60[0] = -1;
    if (stat != 0)
    {
        EIntr();
    }
    if (sema >= 0)
    {
        DeleteSema(sema);
    }
    return 0;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sce_call_rpc);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sce_sync);

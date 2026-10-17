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

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", MemcpyD);

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

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetOpen);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetClose);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetRecv);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetRecvFrom);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetSend);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetSendTo);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetAbort);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetControl);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetGetInterfaceList);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetInterfaceControl);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetGetRoutingTable);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetGetNameServers);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetChangeThreadPriority);

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

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetCtlUpInterface);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetCtlDownInterface);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetCtlSetAutoMode);

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

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetSetConfiguration);

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

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119808);

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

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C5C8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C610);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C678);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C7A8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C8D8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C9B0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011CB30);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011CBC0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatGetInfo);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatFormat);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatUnFormat);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011D9E0);

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

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00121100);

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

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifDeleteCallbackThread);

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

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifGetCount);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifGetList);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifLoadEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifLoadEntryAuto);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifAddEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifEditEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifDeleteEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifSetLatestEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifDeleteAll);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifCheckCapacity);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifCheckAdditionalAT);

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

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifSetEnv);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifTerm);
s32 sceNetcnfifTerm(void)
{
    s32 ret = sceNetcnfifFreeWorkarea();
    sce_sync(0);
    D_00135A5C[0] = 0;
    return ret;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00122FA8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00123090);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sce_create_callback_thread);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sce_delete_callback_thread);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifSendIOP);

s32 sceNetcnfifDmaCheck(u32 id)
{
    return ((u32)~sceSifDmaStat(id)) >> 31;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00123280);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_001232A8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00123308);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sce_call_rpc);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sce_sync);

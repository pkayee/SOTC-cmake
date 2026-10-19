#include "common.h"

extern s32 D_00135A58[];

s32 _sceMcCoreAuthentication(s32);
s32 _sceMcCoreCheckNewCard(s32);
s32 _sceMcCoreGetCardSpec();
s32 _sceMcpReadUserClustOnCache();
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
s32 _sceMcCoreReadPage2(s32, s32, s32, s32, s32);
s32 _sceMcpIsSpeckOutBlock(s32, s32);
s32 sceMc2GetInfoAsync(s32, void *);
s32 sceMc2FormatAsync(s32);
s32 sceMc2UnformatAsync(s32);
s32 sceMc2ReadFileAsync(s32, s32, s32, s32, s32);
s32 sceMc2WriteFileAsync(s32, s32, s32, s32, s32);
s32 sceMc2CreateFileAsync(s32, s32);
s32 sceMc2DeleteAsync(s32, s32);
s32 sceMc2RenameAsync(s32, s32, s32);
s32 sceMc2MkdirAsync(s32, s32);
s32 sceMc2ChdirAsync(s32, s32, s32);
s32 sceMc2GetDirAsync(s32, s32, s32, s32, s32, s32);
s32 sceMc2ChmodAsync(s32, s32, u16);
s32 sceMc2GetEntSpaceAsync(s32, s32);
s32 sceMc2SearchFileAsync(s32, s32, s32);
extern s32 D_00168040[];
extern s32 D_00168080[];
extern s32 D_00135A5C[];
char *strcpy(char *, const char *);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", CallRpc);
extern const char D_00138BC0[];
extern const char D_00138BF8[];
s32 sceSifMCallRpc(void *, u32, u32, void *, s32, void *, s32, void *, void *);
s32 scePrintf();

extern s32 D_00163EC0[];
extern s32 D_00135A44[];
s32 sceDbcSendData3(s32, s32, void *, void *, void *);
void func_00121158(void);
s32 *func_00121030(void);

typedef struct
{
    s32 lo;
    s32 hi;
} McClock8;

typedef struct
{
    s32 w[196];
} NetcnfResult;

typedef struct
{
    s16 h[5];
} McSockName;
typedef struct
{
    u32 flags;
    s32 kind;
    s32 arg1;
    s32 arg2;
    s32 arg3;
    McSockName name;
    s32 pad[4];
} McSockParam;
extern McSockName D_00138EC0;
s32 sceDbcCreateSocket(void *, void *, void *);

typedef struct
{
    s32 w[4];
} McSpec16;

extern const char D_00138E80[];

typedef struct
{
    u8 pad[0xD0];
    s32 tbl[32];
    u8 pad2[0x184 - 0x150];
} McpSys;

extern u8 D_00163640[];
typedef struct
{
    s32 w[0x61];
} McSysInfo;

extern u8 D_00165FC0[];

extern const char D_00138E90[];

typedef struct
{
    s32 w[0x100];
} McClustBuf;
typedef struct
{
    u8 pad00[0x34];
    s32 userBase;
    u8 pad38[0x184 - 0x38];
} McpSysDesc;

s32 CallRpc(void *cd, s32 cmd, void *buf, s32 ssize, s32 rsize)
{
    s32 s0;
    s32 s1;
    s32 s2;

    s1 = (ssize + 0x3F) & ~0x3F;
    s2 = (rsize + 0x3F) & ~0x3F;
    s0 = *(s32 *)((u8 *)cd + 0x30);
    if (s0 < s1 || s0 < s2)
    {
        scePrintf(D_00138BC0);
        scePrintf(D_00138BF8, cmd, s1, s2, s0);
        return -0x21F;
    }
    return sceSifMCallRpc(cd, cmd, 0, buf, s1, buf, s2, 0, 0);
}

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
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", MemcpyD);
void *memcpy(void *dst, const void *src, u32 n);

s32 MemcpyD(s32 *obj, u8 *dst, s32 off, void *src, s32 n)
{
    s32 rem = obj[12] - off * 4;

    if (src == NULL)
    {
        return 0;
    }
    if (n < 0 || rem < n)
    {
        return -0x21F;
    }
    memcpy(dst + off * 4, src, n);
    return 0;
}


void *memcpy(void *dst, const void *src, u32 n);

/* NEARMISS-STUB MemcpyS */
#if 0 /* NEARMISS 77.6% cat=regalloc sub=- | target copies src->v1 and n->a2 at entry (before lw obj[12]) and calls memcpy with addu a1,a3,v1; ours keeps src in a2 and n in a4. Tried: local copies of src/n, swapped (off<<2)+src operand order: both 77.6 | attempts=3 */
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
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", MemcpyS);
s32 MemcpyS(s32 *obj, u8 *dst, u8 *src, s32 off, s32 n)
{
    s32 rem = obj[12] - off * 4;

    if (dst == NULL)
    {
        return 0;
    }
    if (n < 0 || rem < n)
    {
        return -0x21F;
    }
    memcpy(dst, src + off * 4, n);
    return 0;
}


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", StrcpyD);
u32 strlen(char *);
char *strcpy(char *, const char *);

s32 StrcpyD(s32 *obj, char *dst, s32 off, char *src)
{
    s32 rem = obj[12] - (off << 2);
    s32 len;

    if (src == NULL)
    {
        return 0;
    }
    len = strlen(src) + 1;
    if (len < 0 || rem < len)
    {
        return -0x21F;
    }
    strcpy(dst + (off << 2), src);
    return len;
}

s32 StrcpyS(char *dst, char *src, s32 n)
{
    if (dst == NULL)
    {
        return 0;
    }
    strcpy(dst, src + n * 4);
    return 0;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetPoll);
s32 MemcpyD(s32 *, u8 *, s32, void *, s32);
s32 MemcpyS(s32 *, u8 *, u8 *, s32, s32);

s32 sceInetPoll(void *cd, void *net_buf, void *dst, s32 n, s32 flags)
{
    s32 ret;

    ((s32 *)net_buf)[0] = n;
    ((s32 *)net_buf)[1] = flags;
    ret = MemcpyD(cd, net_buf, 2, dst, n << 3);
    if (ret < 0)
    {
        return ret;
    }
    ret = CallRpc(cd, 0x14, net_buf, (n << 3) + 8, (n << 3) | 4);
    if (ret < 0)
    {
        return -0x21E;
    }
    ret = MemcpyS(cd, dst, net_buf, 2, n << 3);
    if (ret >= 0)
    {
        ret = ((s32 *)net_buf)[0];
    }
    return ret;
}

/* NEARMISS-STUB sceInetName2Address */
#if 0 /* NEARMISS 95.6% cat=no-c-form sub=- | frame 0x90 and 8th arg a7 read back from its home slot (0x88 sp): the function is variadic-style (7 named args + unnamed a7 spilled by sd); cc29 has no va_arg s | attempts=1 */
s32 sceInetName2Address(void *cd, s32 *obj, s32 flags, void *dst, char *src, s32 a5, s32 a6, s32 a7)
{
    s32 ret;

    obj[1] = a5;
    obj[2] = a6;
    obj[0] = flags;
    obj[3] = 0;
    if (flags & 0x80)
    {
        obj[3] = a7;
    }
    ret = StrcpyD(cd, (char *)obj, 5, src);
    if (ret < 0)
    {
        return ret;
    }
    obj[4] = ret;
    ret = CallRpc(cd, 6, obj, ret + 0x14, 0x14);
    if (ret < 0)
    {
        return -0x21E;
    }
    ret = MemcpyS(cd, dst, obj, 1, 0x10);
    if (ret >= 0)
    {
        ret = obj[0];
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetName2Address);

s32 MemcpyD(s32 *, u8 *, s32, void *, s32);

s32 sceInetAddress2String(void *cd, s32 *net_buf, char *str, s32 n, void *addr)
{
    s32 ret;

    net_buf[0] = n;
    ret = MemcpyD(cd, net_buf, 1, addr, 0x10);
    if (ret < 0)
    {
        return ret;
    }
    ret = CallRpc(cd, 7, net_buf, 0x14, n + 0x14);
    if (ret < 0)
    {
        return -0x21E;
    }
    ret = StrcpyS(str, (char *)net_buf, 5);
    if (ret >= 0)
    {
        ret = net_buf[0];
    }
    return ret;
}

s32 sceInetAddress2Name(void *cd, s32 *obj, s32 flags, char *dst, s32 a4, void *src, s32 a6, s32 a7, s32 a8, ...)
{
    s32 ret;

    obj[0] = flags;
    obj[1] = a4;
    obj[2] = a6;
    obj[3] = a7;
    ret = MemcpyD(cd, obj, 4, src, 0x10);
    if (ret < 0)
    {
        return ret;
    }
    obj[8] = 0;
    if (flags & 0x80)
    {
        obj[8] = a8;
    }
    ret = CallRpc(cd, 0x12, obj, 0x24, a4 + 0x20);
    if (ret < 0)
    {
        return -0x21E;
    }
    ret = StrcpyS(dst, (char *)obj, 8);
    if (ret >= 0)
    {
        ret = obj[0];
    }
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetCreate);
s32 MemcpyD(s32 *, u8 *, s32, void *, s32);
s32 CallRpc(void *, s32, void *, s32, s32);

s32 sceInetCreate(void *cd, s32 *net_buf, void *src)
{
    s32 ret;

    ret = MemcpyD(cd, net_buf, 1, src, 0x40);
    if (ret < 0)
    {
        return ret;
    }
    ret = CallRpc(cd, 1, net_buf, 0x44, 4);
    if (ret < 0)
    {
        return -0x21E;
    }
    return net_buf[0] != 0 ? net_buf[0] : -0x21C;
}

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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetRecv);
s32 sceInetRecv(void *cd, s32 *obj, s32 a2, void *dst, s32 a4, s32 *a5, s32 a6)
{
    s32 ret;

    obj[0] = a2;
    if (a5 != NULL)
    {
        obj[1] = *a5;
    }
    else
    {
        obj[1] = 0;
    }
    obj[3] = a6;
    obj[2] = a4;
    ret = CallRpc(cd, 4, obj, 0x10, a4 + 8);
    if (ret < 0)
    {
        return -0x21E;
    }
    ret = obj[0];
    if (ret < 0)
    {
        return ret;
    }
    if (a5 != NULL)
    {
        *a5 = obj[1];
    }
    ret = MemcpyS(cd, dst, obj, 2, obj[0]);
    if (ret >= 0)
    {
        ret = obj[0];
    }
    return ret;
}

s32 sceInetRecvFrom(void *cd, s32 *net_buf, s32 a2, void *a3, s32 a4, s32 *a5, void *a6, s32 *a7, s32 a8)
{
    s32 ret;

    net_buf[0] = a2;
    if (a5 != NULL)
    {
        net_buf[1] = *a5;
    }
    else
    {
        net_buf[1] = 0;
    }
    net_buf[2] = a4;
    net_buf[3] = a8;
    ret = CallRpc(cd, 0xD, net_buf, 0x10, a4 + 0x1C);
    if (ret < 0)
    {
        return -0x21E;
    }
    ret = net_buf[0];
    if (ret < 0)
    {
        return ret;
    }
    if (a5 != NULL)
    {
        *a5 = net_buf[1];
    }
    ret = MemcpyS(cd, a6, net_buf, 2, 0x10);
    if (ret < 0)
    {
        return ret;
    }
    if (a7 != NULL)
    {
        *a7 = net_buf[6];
    }
    ret = MemcpyS(cd, a3, net_buf, 7, net_buf[0]);
    if (ret >= 0)
    {
        ret = net_buf[0];
    }
    return ret;
}

s32 sceInetSend(void *cd, s32 *net_buf, s32 a2, void *a3, s32 a4, s32 *a5, s32 a6)
{
    s32 ret;

    net_buf[0] = a2;
    if (a5 != NULL)
    {
        net_buf[1] = *a5;
    }
    else
    {
        net_buf[1] = 0;
    }
    net_buf[2] = a4;
    net_buf[3] = a6;
    ret = MemcpyD(cd, net_buf, 4, a3, a4);
    if (ret < 0)
    {
        return ret;
    }
    ret = CallRpc(cd, 5, net_buf, a4 + 0x10, 8);
    if (ret < 0)
    {
        return -0x21E;
    }
    if (a5 == NULL)
    {
        return net_buf[0];
    }
    *a5 = net_buf[1];
    return net_buf[0];
}

s32 sceInetSendTo(void *cd, s32 *net_buf, s32 a2, void *a3, s32 a4, s32 *a5, void *a6, s32 a7, s32 a8)
{
    s32 ret;

    net_buf[0] = a2;
    if (a5 != NULL)
    {
        net_buf[1] = *a5;
    }
    else
    {
        net_buf[1] = 0;
    }
    net_buf[2] = a4;
    net_buf[3] = a8;
    net_buf[4] = a7;
    ret = MemcpyD(cd, net_buf, 5, a6, 0x10);
    if (ret < 0)
    {
        return ret;
    }
    ret = MemcpyD(cd, net_buf, 9, a3, a4);
    if (ret < 0)
    {
        return ret;
    }
    ret = CallRpc(cd, 0xE, net_buf, a4 + 0x24, 8);
    if (ret < 0)
    {
        return -0x21E;
    }
    if (a5 == NULL)
    {
        return net_buf[0];
    }
    *a5 = net_buf[1];
    return net_buf[0];
}

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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetControl);
s32 MemcpyS(s32 *, u8 *, u8 *, s32, s32);

s32 sceInetControl(void *cd, void *net_buf, s32 a2, s32 a3, void *a4, s32 a5)
{
    s32 ret;

    ((s32 *)net_buf)[0] = a2;
    ((s32 *)net_buf)[1] = a3;
    ((s32 *)net_buf)[2] = a5;
    ret = MemcpyD(cd, net_buf, 3, a4, a5);
    if (ret < 0)
    {
        return ret;
    }
    ret = CallRpc(cd, 0x13, net_buf, a5 + 0xC, a5 + 0xC);
    if (ret < 0)
    {
        return -0x21E;
    }
    ret = MemcpyS(cd, a4, net_buf, 3, a5);
    if (ret >= 0)
    {
        ret = ((s32 *)net_buf)[0];
    }
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetGetInterfaceList);
s32 MemcpyS(s32 *, u8 *, u8 *, s32, s32);
s32 CallRpc(void *, s32, void *, s32, s32);

s32 sceInetGetInterfaceList(void *cd, s32 *net_buf, u8 *dst, s32 n)
{
    s32 ret;

    net_buf[0] = n;
    if (CallRpc(cd, 8, net_buf, 4, n * 4 + 4) < 0)
    {
        return -0x21E;
    }
    if (net_buf[0] < 0)
    {
        return net_buf[0];
    }
    ret = MemcpyS(cd, dst, (u8 *)net_buf, 1, net_buf[0] * 4);
    if (ret < 0)
    {
        return ret;
    }
    return net_buf[0];
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetInterfaceControl);
s32 sceInetInterfaceControl(void *cd, void *net_buf, s32 a2, s32 a3, void *a4, s32 a5)
{
    s32 ret;

    ((s32 *)net_buf)[0] = a2;
    ((s32 *)net_buf)[1] = a3;
    ((s32 *)net_buf)[2] = a5;
    ret = MemcpyD(cd, net_buf, 3, a4, a5);
    if (ret < 0)
    {
        return ret;
    }
    ret = CallRpc(cd, 0x9, net_buf, a5 + 0xC, a5 + 0xC);
    if (ret < 0)
    {
        return -0x21E;
    }
    ret = MemcpyS(cd, a4, net_buf, 3, a5);
    if (ret >= 0)
    {
        ret = ((s32 *)net_buf)[0];
    }
    return ret;
}

s32 MemcpyS(s32 *, u8 *, u8 *, s32, s32);

s32 sceInetGetRoutingTable(void *cd, s32 *net_buf, void *dst, s32 n)
{
    s32 ret;

    net_buf[0] = n;
    ret = CallRpc(cd, 0xA, net_buf, 4, n * 0x48 | 4);
    if (ret < 0)
    {
        return -0x21E;
    }
    ret = net_buf[0];
    if (ret < 0)
    {
        return ret;
    }
    ret = MemcpyS(cd, dst, (u8 *)net_buf, 1, ret * 0x48);
    if (ret >= 0)
    {
        ret = net_buf[0];
    }
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetGetNameServers);
s32 MemcpyS(s32 *, u8 *, u8 *, s32, s32);
s32 CallRpc(void *, s32, void *, s32, s32);

s32 sceInetGetNameServers(void *cd, s32 *net_buf, u8 *dst, s32 n)
{
    s32 ret;

    net_buf[0] = n;
    if (CallRpc(cd, 0xB, net_buf, 4, (n << 4) | 4) < 0)
    {
        return -0x21E;
    }
    if (net_buf[0] < 0)
    {
        return net_buf[0];
    }
    ret = MemcpyS(cd, dst, (u8 *)net_buf, 1, net_buf[0] * 16);
    if (ret < 0)
    {
        return ret;
    }
    return net_buf[0];
}

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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetGetLog);
s32 MemcpyS(s32 *, u8 *, u8 *, s32, s32);
s32 CallRpc(void *, s32, void *, s32, s32);

s32 sceInetGetLog(void *cd, s32 *net_buf, u8 *dst, s32 n, s32 m)
{
    s32 ret;

    net_buf[1] = m;
    net_buf[0] = n;
    if (CallRpc(cd, 0x11, net_buf, 8, n + 4) < 0)
    {
        return -0x21E;
    }
    ret = MemcpyS(cd, dst, (u8 *)net_buf, 1, n);
    if (ret < 0)
    {
        return ret;
    }
    return net_buf[0];
}

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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetCtlGetState);
s32 sceInetCtlGetState(void *cd, s32 *buf, s32 a2, s32 *p)
{
    buf[0] = a2;
    if (p != NULL)
    {
        buf[1] = *p;
    }
    else
    {
        buf[1] = 0;
    }
    if (CallRpc(cd, 0x35, buf, 8, 8) < 0)
    {
        return -0x21E;
    }
    if (p != NULL)
    {
        *p = buf[1];
    }
    return buf[0];
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetInitialize);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetTerminate);
s32 sceSifMUnBindRpc(void *cd, s32 mode);

s32 sceLibnetTerminate(void *cd)
{
    s32 r;
    s32 i;

    while (1)
    {
        r = sceSifMUnBindRpc(cd, 0);
        if (r < 0)
        {
            return -0x21C;
        }
        if (r == 1)
        {
            break;
        }
        for (i = 0x10000; i != -1; i--)
        {
        }
    }
    return 0;
}

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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119598);
s32 func_00119598(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    s32 *net_buf = (s32 *)a1;
    s32 *dst = (s32 *)a2;
    s32 i;

    if (CallRpc((void *)a0, a4, net_buf, 0, a3 * 4 + 4) < 0)
    {
        return -0x21E;
    }
    for (i = 0; i < a3; i++)
    {
        dst[i] = net_buf[i + 1];
    }
    return net_buf[0];
}

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

s32 func_00119668(s32, s32, s32);

s32 func_00119770(void *cd, void *net_buf, s32 *if_id, s32 n, void *addr, s32 flags)
{
    s32 ret;
    s32 sentinel = -1;

    ret = func_00119668(cd, net_buf, if_id);
    if (ret < 0)
    {
        ret = func_00119648(cd, net_buf, if_id, n);
        if (ret < 0)
        {
            return ret;
        }
    }
    ret = func_00119748(cd, net_buf, *if_id, addr);
    if (sentinel < ret)
    {
        ret = 0;
    }
    return ret;
}

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

s32 func_00119668(s32, s32, s32);

s32 sceLibnetWaitGetInterfaceID(s32 a0, s32 a1, s32 a2, s32 a3)
{
    s32 ret;

    if (a2 == 0)
    {
        return -0x21C;
    }
    if (func_00119668(a0, a1, a2) < 0)
    {
        ret = func_00119628(a0, a1, a2, a3);
        if (ret < 0)
        {
            return ret;
        }
    }
    return 0;
}

s32 sceLibnetWaitGetAddress(void *cd, void *net_buf, s32 *if_id, s32 n, void *addr, u32 flags)
{
    if (flags & 2)
    {
        return func_00119770(cd, net_buf, if_id, n, addr, flags & 2);
    }
    return ((s32 (*)())func_00119808)(cd, net_buf, if_id, n, addr);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetWaitGetInterfaceEvent);
s32 sceLibnetWaitGetInterfaceEvent(void *cd, s32 *net_buf, s32 *p1, s32 *p2)
{
    if (CallRpc(cd, 0x23, net_buf, 0, 0xC) < 0)
    {
        return -0x21E;
    }
    if (p1 != NULL)
    {
        *p1 = net_buf[1];
    }
    if (p2 != NULL)
    {
        *p2 = net_buf[2];
    }
    return net_buf[0];
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceSifMInitRpc);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119AA0);
void sceSifSetSreg(s32, s32);
void func_00119AA0(s32 a)
{
    if (a == 1)
    {
        D_00135718[0] = 0;
        sceSifSetSreg(1, 0);
    }
}

void sceSifMExitRpc(void)
{
    D_00135718[0] = 0;
    sceSifRemoveCmdHandler(0x80000018);
    sceSifRemoveRebootNotifyHandler(0x80000014);
}

s32 *func_00119AF8(s32 *obj)
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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119BA0);
void func_00119BA0(s32 *p)
{
    p[6] = 0;
    p[4] = p[4] & 0xFFFFFFFEU;
}

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

/* NEARMISS-STUB sceMc2CreateSocket */
#if 0 /* NEARMISS 99.4% cat=regalloc sub=- | lui/lw base reg swapped at entry (target lui v0 + lw v1 from D_00135730; ours lui v1 + lw v0); scalar extern and split error returns no change | attempts=2 */
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2CreateSocket);
extern s32 D_00135730[];

s32 _sceMcCoreCreateSocket(void *);
s32 _sceMcFatInit2(s32);
s32 _sceMcCoreChangeSocketTypeMc2Dbc(s32);

s32 sceMc2CreateSocket(s32 *a0)
{
    s32 ret;

    if (D_00135730[0] == 0)
    {
        return 0x81018001;
    }
    if ((u32)(a0[1] - 2) >= 2 || a0[2] != 0)
    {
        return 0x81010016;
    }
    ret = _sceMcCoreCreateSocket(a0);
    if (ret < 0)
    {
        return 0x81010017;
    }
    _sceMcFatInit2(ret);
    return _sceMcCoreChangeSocketTypeMc2Dbc(ret);
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2CreateSocket);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2DeleteSocket);
extern s32 D_00135730[];
extern s32 D_00151A84[];

s32 _sceMcCoreChangeSocketTypeDbc2Mc(s32);
s32 _sceMcCoreDeleteSocket(s32);

s32 sceMc2DeleteSocket(s32 a0)
{
    s32 ret = _sceMcCoreChangeSocketTypeDbc2Mc(a0);

    if (ret < 0)
    {
        return 0x81018002;
    }
    if (D_00135730[0] == 0)
    {
        return 0x81018001;
    }
    if (D_00151A84[0] != 0)
    {
        return 0x81010010;
    }
    return _sceMcCoreDeleteSocket(ret) != 0 ? 0 : 0x81018002;
}

s32 sceDbcSearchPortSpecific(s32 *);
extern s32 D_00151FAC;
s32 WaitSema(s32);
s32 SignalSema(s32);

s32 sceMc2SearchSocket(s32 a0, s32 a1)
{
    s32 buf[12];
    s32 ret;

    if (D_00135730[0] == 0)
    {
        return 0x81018001;
    }
    if (D_00151A84[0] != 0)
    {
        return 0x81010010;
    }
    WaitSema(D_00151FAC);
    buf[2] = a0;
    buf[3] = a1;
    ret = sceDbcSearchPortSpecific(buf);
    if (ret < 0)
    {
        SignalSema(D_00151FAC);
        return 0x81018002;
    }
    SignalSema(D_00151FAC);
    return ret;
}

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

extern s32 D_00151A80[];
extern s32 D_00151FA4;
extern s32 D_00151FAC;
s32 WaitSema(s32);
s32 SignalSema(s32);

s32 sceMc2FormatAsync(s32 a0)
{
    s32 *ctl;

    if (D_00135730[0] == 0)
    {
        return 0x81018001;
    }
    a0 = _sceMcCoreChangeSocketTypeDbc2Mc(a0);
    if (a0 < 0)
    {
        return 0x81018002;
    }
    WaitSema(D_00151FAC);
    ctl = D_00151A80;
    if (ctl[1] != 0)
    {
        SignalSema(D_00151FAC);
        return 0x81010010;
    }
    ctl[0] = a0;
    ctl[1] = 3;
    SignalSema(D_00151FA4);
    SignalSema(D_00151FAC);
    return 0;
}

s32 sceMc2UnformatAsync(s32 a0)
{
    s32 *ctl;

    if (D_00135730[0] == 0)
    {
        return 0x81018001;
    }
    a0 = _sceMcCoreChangeSocketTypeDbc2Mc(a0);
    if (a0 < 0)
    {
        return 0x81018002;
    }
    WaitSema(D_00151FAC);
    ctl = D_00151A80;
    if (ctl[1] != 0)
    {
        SignalSema(D_00151FAC);
        return 0x81010010;
    }
    ctl[0] = a0;
    ctl[1] = 4;
    SignalSema(D_00151FA4);
    SignalSema(D_00151FAC);
    return 0;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2GetInfoAsync);
s32 sceMc2GetInfoAsync(s32 a0, void *a1)
{
    s32 *ctl;

    if (D_00135730[0] == 0)
    {
        return 0x81018001;
    }
    a0 = _sceMcCoreChangeSocketTypeDbc2Mc(a0);
    if (a0 < 0)
    {
        return 0x81018002;
    }
    WaitSema(D_00151FAC);
    ctl = D_00151A80;
    if (ctl[1] != 0)
    {
        SignalSema(D_00151FAC);
        return 0x81010010;
    }
    D_00151A80[0] = a0;
    ctl[1] = 2;
    ctl[3] = (s32)a1;
    SignalSema(D_00151FA4);
    SignalSema(D_00151FAC);
    return 0;
}

s32 sceMc2SearchFileAsync(s32 a0, s32 a1, s32 a2)
{
    s32 *ctl;
    char pad[512];

    if (D_00135730[0] == 0)
    {
        return 0x81018001;
    }
    a0 = _sceMcCoreChangeSocketTypeDbc2Mc(a0);
    if (a0 < 0)
    {
        return 0x81018002;
    }
    if (strlen((char *)a1) >= 0x80)
    {
        return 0x8101005B;
    }
    WaitSema(D_00151FAC);
    ctl = D_00151A80;
    if (ctl[1] != 0)
    {
        SignalSema(D_00151FAC);
        return 0x81010010;
    }
    D_00151A80[0] = a0;
    ctl[1] = 14;
    strcpy((char *)ctl + 0x41C, (char *)a1);
    *(s32 *)((char *)ctl + 3 * 4) = a2;
    SignalSema(D_00151FA4);
    SignalSema(D_00151FAC);
    return 0;
}

s32 sceMc2GetDirAllAsync(s32 a0)
{
    s32 *ctl;

    if (D_00135730[0] == 0)
    {
        return 0x81018001;
    }
    a0 = _sceMcCoreChangeSocketTypeDbc2Mc(a0);
    if (a0 < 0)
    {
        return 0x81018002;
    }
    WaitSema(D_00151FAC);
    ctl = D_00151A80;
    if (ctl[1] != 0)
    {
        SignalSema(D_00151FAC);
        return 0x81010010;
    }
    ctl[0] = a0;
    ctl[1] = 0x64;
    SignalSema(D_00151FA4);
    SignalSema(D_00151FAC);
    return 0;
}

s32 sceMc2ReadFileAsync(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    s32 *ctl;

    if (D_00135730[0] == 0)
    {
        return 0x81018001;
    }
    a0 = _sceMcCoreChangeSocketTypeDbc2Mc(a0);
    if (a0 < 0)
    {
        return 0x81018002;
    }
    if (strlen((char *)a1) >= 0x80)
    {
        return 0x8101005B;
    }
    WaitSema(D_00151FAC);
    ctl = D_00151A80;
    if (ctl[1] != 0)
    {
        SignalSema(D_00151FAC);
        return 0x81010010;
    }
    D_00151A80[0] = a0;
    ctl[1] = 5;
    strcpy((char *)ctl + 0x41C, (char *)a1);
    *(s32 *)((char *)ctl + 3 * 4) = a2;
    *(s32 *)((char *)ctl + 4 * 4) = a3;
    *(s32 *)((char *)ctl + 5 * 4) = a4;
    SignalSema(D_00151FA4);
    SignalSema(D_00151FAC);
    return 0;
}

s32 sceMc2WriteFileAsync(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    s32 *ctl;

    if (D_00135730[0] == 0)
    {
        return 0x81018001;
    }
    a0 = _sceMcCoreChangeSocketTypeDbc2Mc(a0);
    if (a0 < 0)
    {
        return 0x81018002;
    }
    if (strlen((char *)a1) >= 0x80)
    {
        return 0x8101005B;
    }
    WaitSema(D_00151FAC);
    ctl = D_00151A80;
    if (ctl[1] != 0)
    {
        SignalSema(D_00151FAC);
        return 0x81010010;
    }
    D_00151A80[0] = a0;
    ctl[1] = 6;
    strcpy((char *)ctl + 0x41C, (char *)a1);
    *(s32 *)((char *)ctl + 3 * 4) = a2;
    *(s32 *)((char *)ctl + 4 * 4) = a3;
    *(s32 *)((char *)ctl + 5 * 4) = a4;
    SignalSema(D_00151FA4);
    SignalSema(D_00151FAC);
    return 0;
}

s32 sceMc2CreateFileAsync(s32 a0, s32 a1)
{
    s32 *ctl;

    if (D_00135730[0] == 0)
    {
        return 0x81018001;
    }
    a0 = _sceMcCoreChangeSocketTypeDbc2Mc(a0);
    if (a0 < 0)
    {
        return 0x81018002;
    }
    if (strlen((char *)a1) >= 0x80)
    {
        return 0x8101005B;
    }
    WaitSema(D_00151FAC);
    ctl = D_00151A80;
    if (ctl[1] != 0)
    {
        SignalSema(D_00151FAC);
        return 0x81010010;
    }
    D_00151A80[0] = a0;
    ctl[1] = 7;
    strcpy((char *)ctl + 0x41C, (char *)a1);
    ctl[3] = 0x8417;
    SignalSema(D_00151FA4);
    SignalSema(D_00151FAC);
    return 0;
}

s32 sceMc2DeleteAsync(s32 a0, s32 a1)
{
    s32 *ctl;

    if (D_00135730[0] == 0)
    {
        return 0x81018001;
    }
    a0 = _sceMcCoreChangeSocketTypeDbc2Mc(a0);
    if (a0 < 0)
    {
        return 0x81018002;
    }
    if (strlen((char *)a1) >= 0x80)
    {
        return 0x8101005B;
    }
    WaitSema(D_00151FAC);
    ctl = D_00151A80;
    if (ctl[1] != 0)
    {
        SignalSema(D_00151FAC);
        return 0x81010010;
    }
    D_00151A80[0] = a0;
    ctl[1] = 8;
    strcpy((char *)ctl + 0x41C, (char *)a1);
    SignalSema(D_00151FA4);
    SignalSema(D_00151FAC);
    return 0;
}

s32 sceMc2GetDirAsync(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{
    s32 *ctl;

    if (D_00135730[0] == 0)
    {
        return 0x81018001;
    }
    a0 = _sceMcCoreChangeSocketTypeDbc2Mc(a0);
    if (a0 < 0)
    {
        return 0x81018002;
    }
    if (strlen((char *)a1) >= 0x80)
    {
        return 0x8101005B;
    }
    WaitSema(D_00151FAC);
    ctl = D_00151A80;
    if (ctl[1] != 0)
    {
        SignalSema(D_00151FAC);
        return 0x81010010;
    }
    D_00151A80[0] = a0;
    ctl[1] = 10;
    strcpy((char *)ctl + 0x41C, (char *)a1);
    *(s32 *)((char *)ctl + 3 * 4) = a2;
    *(s32 *)((char *)ctl + 4 * 4) = a3;
    *(s32 *)((char *)ctl + 5 * 4) = a4;
    *(s32 *)((char *)ctl + 6 * 4) = a5;
    SignalSema(D_00151FA4);
    SignalSema(D_00151FAC);
    return 0;
}

s32 sceMc2MkdirAsync(s32 a0, s32 a1)
{
    s32 *ctl;

    if (D_00135730[0] == 0)
    {
        return 0x81018001;
    }
    a0 = _sceMcCoreChangeSocketTypeDbc2Mc(a0);
    if (a0 < 0)
    {
        return 0x81018002;
    }
    if (strlen((char *)a1) >= 0x80)
    {
        return 0x8101005B;
    }
    WaitSema(D_00151FAC);
    ctl = D_00151A80;
    if (ctl[1] != 0)
    {
        SignalSema(D_00151FAC);
        return 0x81010010;
    }
    D_00151A80[0] = a0;
    ctl[1] = 11;
    strcpy((char *)ctl + 0x41C, (char *)a1);
    ctl[3] = 0x8427;
    SignalSema(D_00151FA4);
    SignalSema(D_00151FAC);
    return 0;
}

s32 sceMc2ChdirAsync(s32 a0, s32 a1, s32 a2)
{
    s32 *ctl;

    if (D_00135730[0] == 0)
    {
        return 0x81018001;
    }
    a0 = _sceMcCoreChangeSocketTypeDbc2Mc(a0);
    if (a0 < 0)
    {
        return 0x81018002;
    }
    if (strlen((char *)a1) >= 0x80)
    {
        return 0x8101005B;
    }
    WaitSema(D_00151FAC);
    ctl = D_00151A80;
    if (ctl[1] != 0)
    {
        SignalSema(D_00151FAC);
        return 0x81010010;
    }
    D_00151A80[0] = a0;
    ctl[1] = 12;
    strcpy((char *)ctl + 0x41C, (char *)a1);
    *(s32 *)((char *)ctl + 12) = a2;
    SignalSema(D_00151FA4);
    SignalSema(D_00151FAC);
    return 0;
}

s32 sceMc2ChmodAsync(s32 a0, s32 a1, u16 a2)
{
    s32 *ctl;

    if (D_00135730[0] == 0)
    {
        return 0x81018001;
    }
    a0 = _sceMcCoreChangeSocketTypeDbc2Mc(a0);
    if (a0 < 0)
    {
        return 0x81018002;
    }
    if (strlen((char *)a1) >= 0x80)
    {
        return 0x8101005B;
    }
    WaitSema(D_00151FAC);
    ctl = D_00151A80;
    if (ctl[1] != 0)
    {
        SignalSema(D_00151FAC);
        return 0x81010010;
    }
    D_00151A80[0] = a0;
    ctl[1] = 13;
    strcpy((char *)ctl + 0x41C, (char *)a1);
    *(s32 *)((char *)ctl + 12) = a2;
    SignalSema(D_00151FA4);
    SignalSema(D_00151FAC);
    return 0;
}

s32 sceMc2RenameAsync(s32 a0, s32 a1, s32 a2)
{
    s32 *ctl;

    if (D_00135730[0] == 0)
    {
        return 0x81018001;
    }
    a0 = _sceMcCoreChangeSocketTypeDbc2Mc(a0);
    if (a0 < 0)
    {
        return 0x81018002;
    }
    if (strlen((char *)a1) >= 0x80 || strlen((char *)a2) >= 0x80)
    {
        return 0x8101005B;
    }
    WaitSema(D_00151FAC);
    ctl = D_00151A80;
    if (ctl[1] != 0)
    {
        SignalSema(D_00151FAC);
        return 0x81010010;
    }
    D_00151A80[0] = a0;
    ctl[1] = 9;
    strcpy((char *)ctl + 0x41C, (char *)a1);
    strcpy((char *)ctl + 0x49C, (char *)a2);
    SignalSema(D_00151FA4);
    SignalSema(D_00151FAC);
    return 0;
}

s32 sceMc2GetEntSpaceAsync(s32 a0, s32 a1)
{
    s32 *ctl;

    if (D_00135730[0] == 0)
    {
        return 0x81018001;
    }
    a0 = _sceMcCoreChangeSocketTypeDbc2Mc(a0);
    if (a0 < 0)
    {
        return 0x81018002;
    }
    if (strlen((char *)a1) >= 0x80)
    {
        return 0x8101005B;
    }
    WaitSema(D_00151FAC);
    ctl = D_00151A80;
    if (ctl[1] != 0)
    {
        SignalSema(D_00151FAC);
        return 0x81010010;
    }
    D_00151A80[0] = a0;
    ctl[1] = 15;
    strcpy((char *)ctl + 0x41C, (char *)a1);
    SignalSema(D_00151FA4);
    SignalSema(D_00151FAC);
    return 0;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011B558);

/* NEARMISS-STUB func_0011B770 */
#if 0 /* NEARMISS 75.6% cat=regalloc sub=ee-gcc2.9-991111 | pointer locals: gcc2.9 gives the status ptr s0 and result ptr s2 and the ctl ptr s1; target keeps status=s1, result=s0, ctl=s2 (a0 mode, a1 status, a2 result).  | attempts=1 */
extern s32 D_00151A80[];
extern s32 D_00151FA8;
s32 WaitSema(s32);
s32 PollSema(s32);

s32 func_0011B770(s32 a0, s32 a1, s32 a2)
{
    s32 *ctl = D_00151A80;

    if (ctl[1] == 0)
    {
        return -1;
    }
    if (a1 != 0)
    {
        *(s32 *)a1 = ctl[1];
    }
    if (a0 == 0)
    {
        WaitSema(D_00151FA8);
    }
    else if (PollSema(D_00151FA8) < 0)
    {
        return 0;
    }
    if (a2 != 0)
    {
        *(s32 *)a2 = ctl[2];
    }
    if (a1 != 0)
    {
        *(s32 *)a1 = ctl[1];
    }
    ctl[1] = 0;
    return 1;
}
#endif
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
s32 sceMc2ReadFile(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    s32 ret = sceMc2ReadFileAsync(a0, a1, a2, a3, a4);
    if (ret != 0)
    {
        return ret;
    }
    func_0011B770(0, 0, (s32)&ret);
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2WriteFile);
s32 sceMc2WriteFile(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    s32 ret = sceMc2WriteFileAsync(a0, a1, a2, a3, a4);
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
s32 sceMc2GetDir(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{
    s32 ret = sceMc2GetDirAsync(a0, a1, a2, a3, a4, a5);
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
    s32 ret = sceMc2SearchFileAsync(a0, a1, a2);
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
#if 0 /* NEARMISS 68.0% cat=branch-layout sub=- | target has the strchr-NULL and strlen<0x20 compares duplicated per path (return 1 / return 0 in delay slots, no sltiu-merge); ours merges into one sltiu tail; p | attempts=2 */
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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011BCB8);
s32 func_0011BCB8(s32 path)
{
    char *s = (char *)path;

    while (*s != 0)
    {
        char c = *s;
        if (c == 0x3F || c == 0x2A || c < 0x20)
        {
            return 0;
        }
        s++;
    }
    return 1;
}


extern const char D_00138DF0[];
extern const char D_00138DF8[];
char *strchr(char *, s32);
char *strrchr(char *, s32);
s32 strcmp(const char *, const char *);

s32 func_0011BD10(char *path)
{
    char buf[0x20];

    if (strchr(path, 0x2F) != NULL)
    {
        if (strlen(strrchr(path, 0x2F) + 1) >= 0x20)
        {
            return 0;
        }
        strcpy(buf, strrchr(path, 0x2F) + 1);
    }
    else
    {
        if (strlen(path) >= 0x20)
        {
            return 0;
        }
        strcpy(buf, path);
    }
    if (strcmp(buf, D_00138DF0) == 0 || strcmp(buf, D_00138DF8) == 0)
    {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011BDC8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011BF48);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C068);
s32 func_0011C068(char *s)
{
    s32 n = 0;

    while (*s != 0)
    {
        if (*s == 0x2F)
        {
            n++;
        }
        s++;
    }
    return n;
}


INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C0B0);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatInit);
typedef struct
{
    s32 unk000[0x100];
    s32 unk400[0x100];
    s32 unk800;
    s32 unk804;
    char unk808[0x80];
    s32 unk888;
    s32 unk88C;
    s32 unk890;
    s32 unk894;
} McFatPort;

typedef struct
{
    char c[2];
} Str2;

extern McFatPort D_0015E0C8[];
extern char D_00135738[];
extern char D_00138E08[];
s32 _sceMcpReadClust(s32, s32, s32, s32);
s32 _sceMcpWriteClust(s32, s32, s32, s32);

s32 _sceMcFatInit(void)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        D_0015E0C8[i].unk800 = -1;
        D_0015E0C8[i].unk804 = -1;
        D_0015E0C8[i].unk894 = 0;
        D_0015E0C8[i].unk888 = 1;
        D_0015E0C8[i].unk88C = 0;
        D_0015E0C8[i].unk890 = 0;
        *(Str2 *)D_0015E0C8[i].unk808 = *(Str2 *)D_00138E08;
    }
    return 1;
}


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatInit2);
s32 _sceMcFatInit2(s32 port)
{
    D_0015E0C8[port].unk800 = -1;
    D_0015E0C8[port].unk804 = -1;
    D_0015E0C8[port].unk894 = 0;
    D_0015E0C8[port].unk888 = 1;
    D_0015E0C8[port].unk88C = 0;
    D_0015E0C8[port].unk890 = 0;
    *(Str2 *)D_0015E0C8[port].unk808 = *(Str2 *)D_00138E08;
    return 1;
}


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C300);
s32 func_0011C300(s32 port, s32 idx, s32 *err)
{
    char *mp = D_00135738 + port * 0x184;
    s32 hi = idx / 0x10000;
    s32 lo = idx / 0x100 - hi * 0x100;
    s32 val;

    if (D_0015E0C8[port].unk804 != hi)
    {
        if (_sceMcpReadClust(port, (s32)D_0015E0C8[port].unk000, *(s32 *)(mp + (hi << 2) + 0x50), 1) == 0)
        {
            *err = 0x8101006F;
            return 0;
        }
        D_0015E0C8[port].unk804 = hi;
    }
    val = D_0015E0C8[port].unk000[lo];
    if (val < 0)
    {
        *err = 0x81019001;
        return 0;
    }
    *err = 0;
    return val;
}


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C420);
s32 func_0011C420(s32 port)
{
    if (D_0015E0C8[port].unk800 > 0 && D_0015E0C8[port].unk894 == 1)
    {
        if (_sceMcpWriteClust(port, (s32)D_0015E0C8[port].unk400, D_0015E0C8[port].unk800, 1) == 0)
        {
            return 0;
        }
    }
    D_0015E0C8[port].unk894 = 0;
    return 1;
}


INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C4B0);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C5C8);
s32 func_0011C4B0(s32, s32, s32 *);

s32 func_0011C5C8(s32 a0, s32 a1, s32 *a2, s32 a3)
{
    s32 ret = func_0011C4B0(a0, a1, a2);
    if (ret == 0x7FFFFFFF)
    {
        *a2 = 0x81019002;
    }
    return ret;
}

/* NEARMISS-STUB func_0011C610 */
#if 0 /* NEARMISS 84.4% cat=regalloc sub=- | target keeps ret in a0 after call and loads *a2 first (lw v1 then daddu a0,v0); ours copies ret to v1 before lw. u32 ret + lui/ori 0xFFFFFFFF compare; signed ret variant same 84.36 | attempts=2 */
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C610);
s32 func_0011C5C8(s32, s32, s32 *, s32);

s32 func_0011C610(s32 a0, s32 a1, s32 *a2, s32 a3)
{
    u32 ret = func_0011C5C8(a0, a1, a2, a3);

    if (*a2 != 0)
    {
        return 0;
    }
    if (ret == 0xFFFFFFFF)
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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C8D8);
s32 func_0011C8D8(s32 port, s32 *err)
{
    char *mp = D_00135738 + port * 0x184;
    s32 n = 0;
    s32 i;
    u32 v;

    *err = 0;
    for (i = D_0015E0C8[port].unk890; i < *(s32 *)(mp + 0x170); i++)
    {
        v = func_0011C4B0(port, i, err);
        if (*err != 0)
        {
            return 0;
        }
        if ((v & 0x80000000) == 0)
        {
            n++;
        }
    }
    return n;
}


INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C9B0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011CB30);

s32 _sceMcCoreSetCardSpec(s32 a0, s32 *spec);

void func_0011CBC0(s32 a0, u8 *p)
{
    s32 spec[4];

    spec[0] = *(u16 *)(p + 0x28);
    spec[1] = *(u16 *)(p + 0x2C);
    spec[2] = (*(s32 *)(p + 0x30) << 10) / *(u16 *)(p + 0x28);
    spec[3] = 1;
    _sceMcCoreSetCardSpec(a0, spec);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatGetInfo);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatFormat);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatUnFormat);

/* NEARMISS-STUB func_0011D9E0 */
#if 0 /* NEARMISS 95.6% cat=struct-layout sub=ee-gcc2.9-991111 | table D_0015E0C8 stride 0x898, fields +0x888/+0x88C: gcc2.9 folds +0x888 into %hi/%lo(D+0x888) and swaps addu operands; target keeps lui/addiu of D and addu a2, | attempts=1 */
/* best 95.6% variant A: needs neighbour sigs _sceMcpCheckNewCard(s32 a0) and _sceMcpAuthentication(s32 a0) (were (void)) */
extern s32 D_0015E0C8[];
s32 _sceMcCoreGetConnection(s32);
s32 _sceMcpCheckNewCard(s32);
s32 _sceMcpAuthentication(s32);
s32 _sceMcCoreWriteBack(s32);

s32 func_0011D9E0(s32 a0)
{
    if (_sceMcCoreGetConnection(a0) == 0)
    {
        return 0x81010013;
    }
    if (_sceMcpCheckNewCard(a0) == 0)
    {
        return 0x81019003;
    }
    if (*(s32 *)((u8 *)D_0015E0C8 + a0 * 0x898 + 0x888) == 1)
    {
        return 0x81019003;
    }
    if (*(s32 *)((u8 *)D_0015E0C8 + a0 * 0x898 + 0x88C) == 0)
    {
        return 0x8101002F;
    }
    if (_sceMcpAuthentication(a0) == 0)
    {
        return 0x81010013;
    }
    _sceMcCoreWriteBack(a0);
    return 0;
}
#endif
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011D9E0);
s32 _sceMcCoreGetConnection(s32);
s32 _sceMcpCheckNewCard(s32);
s32 _sceMcpAuthentication(s32);
s32 _sceMcCoreWriteBack(s32);

s32 func_0011D9E0(s32 a0)
{
    if (_sceMcCoreGetConnection(a0) == 0)
    {
        return 0x81010013;
    }
    if (_sceMcpCheckNewCard(a0) == 0)
    {
        return 0x81019003;
    }
    if (D_0015E0C8[a0].unk888 == 1)
    {
        return 0x81019003;
    }
    if (D_0015E0C8[a0].unk88C == 0)
    {
        return 0x8101002F;
    }
    if (_sceMcpAuthentication(a0) == 0)
    {
        return 0x81010013;
    }
    _sceMcCoreWriteBack(a0);
    return 0;
}


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011DA88);
s32 func_0011C0B0(s32, s32, s32, s32);
s32 func_0011BCB8(s32);
s32 func_0011BC48(char *);

s32 func_0011DA88(s32 a0, s32 a1, s32 a2, s32 a3)
{
    s32 ret;

    if (func_0011C0B0(a0, a1, a2, a3) == 0)
    {
        return 0x81010016;
    }
    if (func_0011BCB8(a2) == 0)
    {
        return 0x81010016;
    }
    ret = func_0011BC48((char *)a2);
    return ret != 0 ? 0 : 0x8101005B;
}

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

/* NEARMISS-STUB _sceMcFatGetEntSpace */
#if 0 /* NEARMISS 96.9% cat=call-abi sub=- | target calls func_0011DA88 with 3 args (a3 left as-is); callee is defined with 4 params so the prototype forbids the 3-arg call, best uses a 0 4th arg (addiu a3 | attempts=1 */
s32 func_0011DD60(s32, s32, void *, s32, s32);
s32 func_0011E358(s32, s32, s32, s32 *);

s32 _sceMcFatGetEntSpace(s32 a0, s32 a1)
{
    u8 dir[0x200];
    s32 buf[0x20];
    s32 ret;
    s32 r;

    ret = func_0011D9E0(a0);
    if (ret != 0)
    {
        return ret;
    }
    ret = func_0011DA88(a0, a1, buf, 0);
    if (ret != 0)
    {
        return ret;
    }
    ret = func_0011DD60(a0, buf, dir, 0, 0);
    if (ret != 0x81010011)
    {
        return ret;
    }
    if ((*(u16 *)dir & 0x20) == 0)
    {
        return 0x81010014;
    }
    r = func_0011E358(a0, *(s32 *)(dir + 0x10), *(s32 *)(dir + 4), &ret);
    return ret != 0 ? ret : r;
}
#endif
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatGetEntSpace);
s32 func_0011DD60(s32, s32, void *, s32, s32);
s32 func_0011E358(s32, s32, s32, s32 *);

s32 _sceMcFatGetEntSpace(s32 a0, s32 a1)
{
    u8 dir[0x200];
    s32 buf[0x20];
    s32 ret;
    s32 r;
    extern s32 func_0011DA88();

    ret = func_0011D9E0(a0);
    if (ret != 0)
    {
        return ret;
    }
    ret = func_0011DA88(a0, a1, buf);
    if (ret != 0)
    {
        return ret;
    }
    ret = func_0011DD60(a0, buf, dir, 0, 0);
    if (ret != 0x81010011)
    {
        return ret;
    }
    if ((*(u16 *)dir & 0x20) == 0)
    {
        return 0x81010014;
    }
    r = func_0011E358(a0, *(s32 *)(dir + 0x10), *(s32 *)(dir + 4), &ret);
    return ret != 0 ? ret : r;
}


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpInit);
extern char D_0015F600[];

s32 _sceMcpInit(void)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        *(s32 *)(D_0015F600 + i * 0x2010) = -1;
        *(s32 *)(D_0015F600 + i * 0x2010 + 0xC) = 0;
    }
    return 1;
}


s32 _sceMcpGetCardSpec(void)
{
    return _sceMcCoreGetCardSpec();
}

s32 _sceMcpCheckNewCard(s32 a0)
{
    return _sceMcCoreCheckNewCard(a0);
}

s32 _sceMcpAuthentication(s32 a0)
{
    return _sceMcCoreAuthentication(a0);
}

s32 _sceMcpReadSysInfo(s32 port)
{
    if (_sceMcCoreReadPage2(port, (s32)D_00163640, 0, 1, 0) == 0)
    {
        return 0;
    }
    *(McSysInfo *)(D_00135738 + port * 0x184) = *(McSysInfo *)D_00163640;
    return 1;
}

s32 _sceMcpWriteSysInfo(s32 port)
{
    memset(D_00163640, 0xFF, 0x800);
    *(McSysInfo *)D_00163640 = *(McSysInfo *)(D_00135738 + port * 0x184);
    return _sceMcCoreWritePage(port, (s32)D_00163640, 0, 1) != 0;
}

/* NEARMISS-STUB _sceMcpReadClust */
#if 0 /* NEARMISS 90.0% cat=sdk-compiler sub=mult-mflo-template | d2r97: buildable struct-cast stub (old one clashed with extern char D_00135738[]); instruction-identical except mflo a2 in the jal slot: ee-gcc2.9-991111 emits  | attempts=2 */
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
#if 0 /* NEARMISS 74.4% cat=regalloc sub=- | target keeps -1 in s2 across call and blk in s0/s1 with byte offsets (mult 0x2010 once, then +0x10/+0xC); word-index form 74.4, byte-pointer local form 73.5 | attempts=3 | attempts=2 */
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpFlushCache);
extern s32 D_0015F600[];

s32 _sceMcpWriteClust(s32, s32, s32, s32);

s32 _sceMcpFlushCache(s32 a0)
{
    s32 ret;

    if (D_0015F600[a0 * 0x804] == -1)
    {
        return 1;
    }
    ret = _sceMcpWriteClust(a0, (s32)&D_0015F600[a0 * 0x804 + 4], D_0015F600[a0 * 0x804], D_0015F600[a0 * 0x804 + 3]);
    D_0015F600[a0 * 0x804] = -1;
    D_0015F600[a0 * 0x804 + 3] = 0;
    return ret;
}
#endif
//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpFlushCache);
s32 _sceMcpWriteClust(s32, s32, s32, s32);

s32 _sceMcpFlushCache(s32 a0)
{
    s32 ret = 1;
    s32 off = a0 * 0x2010;

    if (*(s32 *)(D_0015F600 + off) != -1)
    {
        ret = _sceMcpWriteClust(a0, (s32)(D_0015F600 + off + 0x10), *(s32 *)(D_0015F600 + off), *(s32 *)(D_0015F600 + off + 0xC));
        *(s32 *)(D_0015F600 + off) = -1;
        *(s32 *)(D_0015F600 + off + 0xC) = 0;
    }
    return ret;
}


INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpWriteUserClustOnCache);

s32 _sceMcpReadUserClustOnCache(s32 port, s32 dst, s32 clust)
{
    s32 off = port * 0x2010;
    s32 base = *(s32 *)(D_0015F600 + off);

    clust += ((McpSysDesc *)D_00135738)[port].userBase;
    if (clust >= base && clust < base + *(s32 *)(D_0015F600 + off + 0xC))
    {
        *(McClustBuf *)dst = *(McClustBuf *)(D_0015F600 + 0x10 + port * 0x2010 + (clust - base) * 0x400);
        return 1;
    }
    return _sceMcpReadClust(port, dst, clust, 1);
}

s32 _sceMcpReadUserClust(s32 a0, s32 a1, s32 a2)
{
    return _sceMcpReadUserClustOnCache(a0, a1, a2);
}

s32 _sceMcpWriteUserClust(void)
{
    return _sceMcpWriteUserClustOnCache();
}

s32 _sceMcpIsSpeckOutBlock(s32 port, s32 blk)
{
    McpSys *m = (McpSys *)D_00135738 + port;
    s32 i;

    for (i = 0; i < 0x20; i++)
    {
        if (m->tbl[i] == blk)
        {
            return 1;
        }
    }
    return 0;
}

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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _SceMcComGetSysInfo);
extern char D_00135738[];
void *_SceMcComGetSysInfo(s32 port)
{
    return &D_00135738[port * 0x184];
}

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

typedef struct
{
    s32 unk00;
    s32 unk04;
    s32 unk08[7];
} McConnection;

extern McConnection D_00163E48[];

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreInit);
extern s32 D_00138E68[];
extern s32 D_00135A40[];

s32 CreateSema(s32 *);

s32 _sceMcCoreInit(void)
{
    s32 param[8];
    s32 sema;
    McConnection *conn;

    D_00135A40[0] = 0;
    param[1] = 0x7F;
    param[2] = 0;
    param[5] = (s32)D_00138E68;
    sema = CreateSema(param);
    D_00163E40[0] = sema;
    if (sema < 0)
    {
        return 0;
    }
    conn = D_00163E48;
    do
    {
        conn->unk00 = 0;
        conn->unk08[0] = 0x200;
        conn->unk08[1] = 0x10;
        conn->unk08[2] = 0x4000;
        conn++;
    } while ((s32)conn < (s32)(D_00163E48 + 2));
    return 1;
}


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreEnd);
s32 DeleteSema(s32);
s32 sceDbcDeleteSocket(s32);

s32 _sceMcCoreEnd(void)
{
    McConnection *conn;
    McConnection *end;

    if (D_00163E40[0] >= 0)
    {
        DeleteSema(D_00163E40[0]);
    }
    conn = D_00163E48;
    end = D_00163E48 + 2;
    do
    {
        if (conn->unk00 != 0)
        {
            sceDbcDeleteSocket(conn->unk04);
            conn->unk00 = 0;
        }
        conn++;
    } while ((s32)conn < (s32)end);
    return 1;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreSetWriteBackHole);
s32 _sceMcCoreSetWriteBackHole(s32 port, s32 a, s32 b)
{
    D_00163E48[port].unk08[5] = a;
    D_00163E48[port].unk08[6] = b;
    return 1;
}

s32 _sceMcCoreSetCardSpec(s32 port, s32 *spec)
{
    McConnection *c = &D_00163E48[port];
    *(McSpec16 *)c->unk08 = *(McSpec16 *)spec;
    return 1;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreGetCardSpec);

s32 _sceMcCoreCheckNewCard(s32 port)
{
    s32 cmd[4];

    if (sceDbcGetConnection(D_00163E48[port].unk04) == 3)
    {
        return 0;
    }
    D_00163EC0[2] = D_00163E48[port].unk08[0];
    D_00163EC0[3] = D_00163E48[port].unk08[1];
    D_00163EC0[4] = D_00163E48[port].unk08[2];
    D_00163EC0[5] = 0;
    D_00163EC0[6] = 0;
    cmd[0] = 0x2080;
    memset(D_00165F40, 0, 0x100);
    D_00135A44[0] = 4;
    while (sceDbcSendData3(D_00163E48[port].unk04, D_00135A44[0], cmd, D_00163EC0, func_00121158) != 1)
    {
    }
    return func_00121030()[2];
}

s32 _sceMcCoreClearNewCardFlag(s32 port)
{
    s32 cmd[4];

    if (sceDbcGetConnection(D_00163E48[port].unk04) == 3)
    {
        return 0;
    }
    D_00163EC0[5] = 0;
    D_00163EC0[6] = 0;
    cmd[0] = 0x2080;
    memset(D_00165F40, 0, 0x100);
    D_00135A44[0] = 0xD;
    while (sceDbcSendData3(D_00163E48[port].unk04, D_00135A44[0], cmd, D_00163EC0, func_00121158) != 1)
    {
    }
    return func_00121030()[2];
}

s32 _sceMcCoreAuthentication(s32 port)
{
    s32 cmd[4];

    if (sceDbcGetConnection(D_00163E48[port].unk04) == 3)
    {
        return 0;
    }
    cmd[0] = 0x2080;
    D_00163EC0[5] = 0;
    D_00163EC0[6] = 0;
    memset(D_00165F40, 0, 0x100);
    SyncDCache(D_00165F40, (u8 *)D_00165F40 + 0xFF);
    D_00135A44[0] = 0xC;
    while (sceDbcSendData3(D_00163E48[port].unk04, D_00135A44[0], cmd, D_00163EC0, func_00121158) != 1)
    {
    }
    return func_00121030()[2] != 0;
}

s32 _sceMcCoreWriteBack(s32 port)
{
    s32 cmd[4];

    if (sceDbcGetConnection(D_00163E48[port].unk04) == 3)
    {
        return 0;
    }
    if (D_00163E48[port].unk08[0] == 0 || D_00163E48[port].unk08[1] == 0)
    {
        scePrintf(D_00138E80);
        return 0;
    }
    D_00163EC0[2] = D_00163E48[port].unk08[0];
    D_00163EC0[3] = D_00163E48[port].unk08[1];
    D_00163EC0[4] = D_00163E48[port].unk08[2];
    D_00163EC0[5] = D_00163E48[port].unk08[6];
    D_00163EC0[6] = D_00163E48[port].unk08[5];
    D_00163EC0[9] = D_00163E48[port].unk08[3];
    cmd[0] = 0x2080;
    memset(D_00165F40, 0, 0x100);
    D_00135A44[0] = 6;
    while (sceDbcSendData3(D_00163E48[port].unk04, D_00135A44[0], cmd, D_00163EC0, func_00121158) != 1)
    {
    }
    return func_00121030()[2];
}

s32 _sceMcCoreReadClock(s32 port, McClock8 *out)
{
    s32 cmd[4];
    s32 *r;

    if (sceDbcGetConnection(D_00163E48[port].unk04) == 3)
    {
        return 0;
    }
    D_00163EC0[5] = 0;
    D_00163EC0[6] = 0;
    cmd[0] = 0x2080;
    memset(D_00165F40, 0, 0x100);
    D_00135A44[0] = 10;
    while (sceDbcSendData3(D_00163E48[port].unk04, D_00135A44[0], cmd, D_00163EC0, func_00121158) != 1)
    {
    }
    r = func_00121030();
    if (r[2] == 0)
    {
        return 0;
    }
    *out = *(McClock8 *)(r + 3);
    return r[2];
}

s32 _sceMcCoreReadPage2(s32 port, s32 buf, s32 a, s32 n, s32 flag)
{
    s32 cmd[1];
    s32 *r;
    u8 *dst;
    u8 *src;
    s32 i;

    if (sceDbcGetConnection(D_00163E48[port].unk04) == 3)
    {
        return 0;
    }
    D_00163EC0[0] = a;
    D_00163EC0[2] = D_00163E48[port].unk08[0];
    D_00163EC0[3] = D_00163E48[port].unk08[1];
    D_00163EC0[4] = D_00163E48[port].unk08[2];
    cmd[0] = 0x2080;
    D_00163EC0[1] = n;
    D_00163EC0[5] = 0;
    D_00163EC0[6] = 0;
    D_00163EC0[7] = 0;
    D_00163EC0[8] = 0;
    D_00163EC0[9] = flag;
    memset(D_00165F40, 0, 0x100);
    D_00135A44[0] = 1;
    while (sceDbcSendData3(D_00163E48[port].unk04, D_00135A44[0], cmd, D_00163EC0, func_00121158) != 1)
    {
    }
    r = func_00121100();
    if (r[2] == 0)
    {
        return 0;
    }
    dst = (u8 *)buf;
    src = D_00165FC0;
    if (n > 0)
    {
        i = n;
        do
        {
            i--;
            SyncDCache(src, src + D_00163EC0[2]);
            memcpy(dst, src, D_00163EC0[2]);
            src += D_00163EC0[2];
            dst += D_00163EC0[2];
        } while (i != 0);
    }
    return n;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreReadPage);
s32 _sceMcCoreReadPage2(s32, s32, s32, s32, s32);
s32 _sceMcCoreReadPage(s32 port, s32 a, s32 b, s32 c)
{
    _sceMcCoreReadPage2(port, a, b, c, D_00163E48[port].unk08[3]);
}

s32 _sceMcCoreWritePage(s32 port, s32 buf, s32 a, s32 n)
{
    s32 cmd[1];
    s32 *r;
    u32 len;

    if (sceDbcGetConnection(D_00163E48[port].unk04) == 3)
    {
        return 0;
    }
    len = D_00163E48[port].unk08[0] * n;
    if (len > 0x2000)
    {
        scePrintf(D_00138E90);
        return 0;
    }
    D_00163EC0[0] = a;
    D_00163EC0[2] = D_00163E48[port].unk08[0];
    D_00163EC0[3] = D_00163E48[port].unk08[1];
    D_00163EC0[4] = D_00163E48[port].unk08[2];
    D_00163EC0[5] = D_00163E48[port].unk08[6];
    D_00163EC0[6] = D_00163E48[port].unk08[5];
    D_00163EC0[9] = D_00163E48[port].unk08[3];
    D_00163EC0[1] = n;
    D_00163EC0[7] = 0;
    D_00163EC0[8] = 0;
    memcpy(&D_00163EC0[10], (void *)buf, len);
    cmd[0] = 0x2080;
    memset(D_00165F40, 0, 0x100);
    SyncDCache(D_00165F40, (u8 *)D_00165F40 + 0xFF);
    D_00135A44[0] = 2;
    while (sceDbcSendData3(D_00163E48[port].unk04, D_00135A44[0], cmd, D_00163EC0, func_00121158) != 1)
    {
    }
    r = func_00121030();
    return r[2] != 0 ? n : 0;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreWriteSameData);

s32 _sceMcCoreBlockErase(s32 port, s32 a1)
{
    s32 cmd[4];

    if (sceDbcGetConnection(D_00163E48[port].unk04) == 3)
    {
        return 0;
    }
    D_00163EC0[1] = 1;
    D_00163EC0[2] = D_00163E48[port].unk08[0];
    D_00163EC0[3] = D_00163E48[port].unk08[1];
    D_00163EC0[4] = D_00163E48[port].unk08[2];
    cmd[0] = 0x2080;
    D_00163EC0[0] = 0;
    D_00163EC0[5] = 0;
    D_00163EC0[6] = 0;
    D_00163EC0[7] = 0;
    D_00163EC0[8] = a1;
    memset(D_00165F40, 0, 0x100);
    SyncDCache(D_00165F40, (u8 *)D_00165F40 + 0xFF);
    D_00135A44[0] = 9;
    while (sceDbcSendData3(D_00163E48[port].unk04, D_00135A44[0], cmd, D_00163EC0, func_00121158) != 1)
    {
    }
    return func_00121030()[2] != 0;
}


s32 _sceMcCoreGetConnection(s32 a0)
{
    return sceDbcGetConnection(D_00163E48[a0].unk04) != 3;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00121FC0);
s32 func_00121FC0(void)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        if (D_00163E48[i].unk00 == 0)
        {
            return i;
        }
    }
    return -1;
}


s32 _sceMcCoreCreateSocket(void *arg)
{
    s32 *a0 = arg;
    McSockParam p;
    s32 id;
    s32 r;

    id = func_00121FC0();
    if (id < 0)
    {
        return -1;
    }
    p.flags = a0[0];
    p.arg1 = a0[1];
    p.arg2 = a0[2];
    p.arg3 = a0[3];
    p.name = D_00138EC0;
    p.kind = 2;
    p.flags |= 1;
    memset(D_00165F40, 0, 0x100);
    r = sceDbcCreateSocket(&p, D_00165F40, (u8 *)D_00165F40 + 0x80);
    D_00163E48[id].unk04 = r;
    if (r < 0)
    {
        return -1;
    }
    D_00163E48[id].unk00 = 1;
    D_00163E48[id].unk08[5] = 0;
    D_00163E48[id].unk08[6] = 0;
    D_00163E48[id].unk08[0] = 0x200;
    D_00163E48[id].unk08[1] = 0x10;
    D_00163E48[id].unk08[2] = 0x4000;
    return id;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreCheckSocket);
s32 _sceMcCoreCheckSocket(s32 port)
{
    if ((u32)port >= 2)
    {
        return 0;
    }
    return D_00163E48[port].unk00 != 0;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreDeleteSocket);
s32 _sceMcCoreCheckSocket(s32);
s32 sceDbcDeleteSocket(s32);

s32 _sceMcCoreDeleteSocket(s32 a0)
{
    if (_sceMcCoreCheckSocket(a0) == 0)
    {
        return 0;
    }
    sceDbcDeleteSocket(D_00163E48[a0].unk04);
    D_00163E48[a0].unk00 = 0;
    return 1;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreChangeSocketTypeDbc2Mc);
s32 _sceMcCoreChangeSocketTypeDbc2Mc(s32 sock)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        if (D_00163E48[i].unk00 != 0 && D_00163E48[i].unk04 == sock)
        {
            return i;
        }
    }
    return -1;
}


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreChangeSocketTypeMc2Dbc);
s32 _sceMcCoreChangeSocketTypeMc2Dbc(s32 port)
{
    if (D_00163E48[port].unk00 == 0)
    {
        return -1;
    }
    return D_00163E48[port].unk04;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifSetup);
s32 sceNetcnfifSetup(void)
{
    s32 i;

    if (D_00135A5C[0] != 0)
    {
        return 0;
    }
    while (1)
    {
        if (sceSifBindRpc(D_00168040, 0x80001101, 1) < 0)
        {
            return -1;
        }
        while (sceSifCheckStatRpc(D_00168040) != 0)
        {
        }
        if (D_00168040[9] != 0)
        {
            break;
        }
        for (i = 0x10000; i != -1; i--)
        {
        }
    }
    D_00135A5C[0] = 1;
    return 0;
}

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

s32 sceNetcnfifGetResult(NetcnfResult *out)
{
    *out = *(NetcnfResult *)D_00168080;
    return 0;
}

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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifGetList);
s32 sceNetcnfifGetList(char *a0, s32 a1, s32 a2, s32 a3)
{
    s32 *buf;

    sceNetcnfifInit();
    buf = D_00168080;
    strcpy((char *)buf + 0x10, a0);
    buf[0] = a3;
    buf[2] = a1;
    buf[3] = a2;
    return sce_call_rpc(D_00168040, buf, 1);
}

s32 sceNetcnfifLoadEntry(char *a0, s32 a1, char *a2, s32 a3)
{
    s32 *buf;

    sceNetcnfifInit();
    buf = D_00168080;
    strcpy((char *)buf + 0x10, a0);
    buf[2] = a1;
    strcpy((char *)buf + 0x110, a2);
    buf[1] = D_00135A58[0];
    buf[3] = a3;
    return sce_call_rpc(D_00168040, buf, 2);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifLoadEntryAuto);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifAddEntry);
s32 sceNetcnfifAddEntry(char *a0, s32 a1, char *a2)
{
    s32 *buf;

    sceNetcnfifInit();
    buf = D_00168080;
    strcpy((char *)buf + 0x10, a0);
    buf[2] = a1;
    strcpy((char *)buf + 0x110, a2);
    buf[1] = D_00135A58[0];
    return sce_call_rpc(D_00168040, buf, 3);
}

s32 sceNetcnfifEditEntry(char *a0, s32 a1, char *a2, char *a3)
{
    s32 *buf;

    sceNetcnfifInit();
    buf = D_00168080;
    strcpy((char *)buf + 0x10, a0);
    buf[2] = a1;
    strcpy((char *)buf + 0x110, a2);
    strcpy((char *)buf + 0x210, a3);
    buf[1] = D_00135A58[0];
    return sce_call_rpc(D_00168040, buf, 4);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifDeleteEntry);
s32 sceNetcnfifDeleteEntry(char *a0, s32 a1, char *a2)
{
    s32 *buf;

    sceNetcnfifInit();
    buf = D_00168080;
    strcpy((char *)buf + 0x10, a0);
    buf[2] = a1;
    strcpy((char *)buf + 0x110, a2);
    return sce_call_rpc(D_00168040, buf, 5);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifSetLatestEntry);
s32 sceNetcnfifSetLatestEntry(char *a0, s32 a1, char *a2)
{
    s32 *buf;

    sceNetcnfifInit();
    buf = D_00168080;
    strcpy((char *)buf + 0x10, a0);
    buf[2] = a1;
    strcpy((char *)buf + 0x110, a2);
    return sce_call_rpc(D_00168040, buf, 6);
}

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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifCheckSpecialProvider);
s32 sceNetcnfifCheckSpecialProvider(char *a0, s32 a1, char *a2)
{
    s32 *buf;

    sceNetcnfifInit();
    buf = D_00168080;
    strcpy((char *)buf + 0x10, a0);
    buf[2] = a1;
    strcpy((char *)buf + 0x110, a2);
    buf[1] = D_00135A58[0];
    return sce_call_rpc(D_00168040, buf, 10);
}

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

/* NEARMISS-STUB sce_create_callback_thread */
#if 0 /* NEARMISS 72.36% cat=no-c-form sub=- | reads live $gp for ThreadParam.gpReg (no C form without asm; attempt uses NULL placeholder); ldl/ldr 16-byte copy and entry/stack store order already match; fun | attempts=1 */
struct Blk16
{
    char b[16];
};
struct ThreadParam
{
    s32 status;
    void (*entry)(void *);
    void *stack;
    s32 stackSize;
    void *gpReg;
    s32 initPriority;
    s32 currentPriority;
    u32 attr;
    u32 option;
};
extern s32 D_0016A080[];
extern s32 D_00138ED0[];
void func_00123090(void);
s32 CreateThread(void *);
s32 StartThread(s32, void *);
s32 DeleteThread(s32);

s32 sce_create_callback_thread(void *a0, void *a1, s32 a2, s32 a3)
{
    struct ThreadParam tp;
    s32 tid;

    tp.entry = (void (*)(void *))func_00123090;
    tp.stack = a1;
    tp.stackSize = a2;
    tp.gpReg = NULL;
    tp.initPriority = a3;
    tp.option = (u32)D_00138ED0;
    tid = CreateThread(&tp);
    if (tid <= 0)
    {
        return -1;
    }
    *(struct Blk16 *)D_0016A080 = *(struct Blk16 *)a0;
    if (StartThread(tid, NULL) >= 0)
    {
        return tid;
    }
    DeleteThread(tid);
    return -1;
}
#endif
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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_001232A8);
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
    if (((volatile s32 *)D_00135A60)[0] < 0)
    {
        return -1;
    }
    return ((volatile s32 *)D_00135A60)[0];
}
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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sce_call_rpc);
extern const char D_00138F08[];

s32 func_001232A8(void);
s32 func_00123280(void);
s32 scePrintf();

s32 sce_call_rpc(void *a0, void *a1, s32 a2)
{
    s32 id;

    id = func_001232A8();
    if (id < 0)
    {
        scePrintf(D_00138F08, a2);
        return id;
    }
    return sceSifCallRpc(a0, a2, 1, a1, 0x1000, a1, 0x1000, (void *)func_00123280, (void *)id);
}

s32 PollSema(s32);

s32 sce_sync(s32 mode)
{
    s32 ret = 1;

    if (((volatile s32 *)D_00135A60)[0] < 0)
    {
        return -1;
    }
    switch (mode)
    {
    case 0:
        WaitSema(((volatile s32 *)D_00135A60)[0]);
        ret = 0;
        func_00123308();
        break;
    case 1:
        if (PollSema(((volatile s32 *)D_00135A60)[0]) != -1)
        {
            ret = 0;
            func_00123308();
        }
        break;
    default:
        return -0x65;
    }
    return ret;
}

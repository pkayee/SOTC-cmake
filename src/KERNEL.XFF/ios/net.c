#include "common.h"

extern s32 sceInetClose(void *, void *, s32, s32);
extern s32 sceLibnetTerminate(void *);
extern s32 sceInetSend(void *, void *, s32, void *, s32, s32 *, s32);
extern s32 sceInetRecv(void *, void *, s32, void *, s32, s32 *, s32);
extern s32 LoaderSysCheckCDBootMode(void);
extern void LoaderSysInitTCP(void);
extern s32 CreateSema(void *);
extern s32 sceSifInitRpc(s32);
extern s32 sceSifBindRpc(void *, u32, s32);
extern s32 iosLoadIopModule(const char *, const char *, s32, s32);
extern void iosFree(void *);
extern s32 sceSifCallRpc(void *, u32, u32, void *, s32, void *, s32, void *, void *);
extern s32 WaitSema(s32);
extern s32 SignalSema(s32);
extern void *memcpy(void *, const void *, u32);
extern u32 strlen(const char *);
extern char *strncpy(char *, const char *, u32);

extern s32 D_40045710;
extern s32 D_4007DF28;
extern s8 D_4007CF04[];
extern s8 D_4007DF30[];
extern s8 D_40046C80[];
extern s8 D_40046CA8[];
extern s8 D_4007DF00[];
extern s32 D_4007CF00[];
extern s8 D_4007DF38[];

s32 func_40016C10(void *arg0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/net", func_40016C10);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/net", func_40016E20);
s32 func_40016E20(s32 arg0, s32 arg1)
{
    s32 off = arg0 * 68;
    s8 *slot = D_4007DF38 + off;
    void **bufp = (void **)(D_4007DF38 - 4 + off);
    s32 *cidp = (s32 *)(D_4007DF38 - 8 + off);

    sceInetClose(slot, *bufp, *cidp, arg1);
    *cidp = -1;
    sceLibnetTerminate(slot);
    iosFree(*bufp);
    *bufp = NULL;
    return 1;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/net", iosNetRecvMsg);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/net", InitNet);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/net", iosNetRecv);
s32 iosNetRecv(s32 arg0, void* arg1, s32 arg2, s32 arg3)
{
    s32 ret;

    if (D_40045710 != 0)
    {
        s32 off = arg0 * 68;
        s8* slot = D_4007DF38 + off;
        void** bufp = (void**)(D_4007DF38 - 4 + off);
        s32* cidp = (s32*)(D_4007DF38 - 8 + off);
        s32 flags;
        s32 len = (arg2 < 0x701) ? arg2 : 0x700;

        flags = 0;
        ret = sceInetRecv(slot, *bufp, *cidp, arg1, len, &flags, arg3);
    }
    else
    {
        s32 len = (arg2 < 0xF01) ? arg2 : 0xF00;
        s32* buf = D_4007CF00;
        s32* pay = buf + 1;
        s32 rlen = len + 4;
        s32 res;

        buf[0] = arg0;
        pay[0] = len;
        WaitSema(D_4007DF28);
        sceSifCallRpc(D_4007DF00, 2, 0, buf, 8, buf, rlen, NULL, NULL);
        SignalSema(D_4007DF28);
        res = buf[0];
        memcpy(arg1, pay, len);
        ret = res;
    }
    return ret;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/net", iosNetSend);
s32 iosNetSend(s32 arg0, void* arg1, s32 arg2, s32 arg3)
{
    s32 flags;
    s32 ret;

    if (D_40045710 != 0)
    {
        s32 off = arg0 * 68;
        s8* slot = D_4007DF38 + off;
        void** bufp = (void**)(D_4007DF38 - 4 + off);
        s32* cidp = (s32*)(D_4007DF38 - 8 + off);

        flags = 0;
        ret = sceInetSend(slot, *bufp, *cidp, arg1, arg2, &flags, arg3);
    }
    else
    {
        s32 total = arg2 + 8;

        D_4007CF00[0] = arg0;
        D_4007CF00[1] = arg2;
        memcpy((char*)D_4007CF00 + 8, arg1, arg2);
        WaitSema(D_4007DF28);
        sceSifCallRpc(D_4007DF00, 3, 0, D_4007CF00, total, D_4007CF00, 4, NULL, NULL);
        SignalSema(D_4007DF28);
        ret = D_4007CF00[0];
    }
    return ret;
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/net", iosNetRecvMsgWithStateCallback);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/net", iosNetClose);
s32 iosNetClose(s32 arg0)
{
    if (D_40045710 != 0)
    {
        func_40016E20(arg0, -1);
    }
    else
    {
        D_4007CF00[0] = arg0;
        WaitSema(D_4007DF28);
        sceSifCallRpc(D_4007DF00, 1, 0, D_4007CF00, 4, D_4007CF00, 4, NULL, NULL);
        SignalSema(D_4007DF28);
        return D_4007CF00[0];
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/net", iosNetOpen);
s32 iosNetOpen(char* arg0)
{
    s32 ret;
    s32 len;

    if (D_40045710 != 0)
    {
        ret = func_40016C10(arg0);
    }
    else
    {
        len = strlen(arg0);
        D_4007CF00[0] = len + 1;
        strncpy((char*)&D_4007CF00[1], arg0, len + 1);
        len += 5;
        WaitSema(D_4007DF28);
        sceSifCallRpc(D_4007DF00, 0, 0, D_4007CF00, len, D_4007CF00, 4, NULL, NULL);
        SignalSema(D_4007DF28);
        ret = D_4007CF00[0];
    }
    return ret;
}


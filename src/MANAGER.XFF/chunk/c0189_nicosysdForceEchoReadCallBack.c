#include "common.h"

extern s32 rootPtn;
void nicosysdSendDataStart(void *, s32, void *, s32);
void nicosysdSendDataWrite(void *, void *, s32);
void nicosysdExec(void *, void *, void *);
s32 nicosysdRecvDataRead(s32, void *, s32);
void func_400EC3F0(void *, s32 *);

int strlen(const char *);
typedef __builtin_va_list va_list;
int vsprintf(char *, const char *, va_list);
void iosJumpRecoverPoint(char *);
extern char D_401B4348[];
extern char D_40134FB8[];

extern char D_40134FB0[];
void iosSPrintf(char *, char *, ...);

extern s32 D_4012E310;
extern char D_401B3E88[];
extern char D_40134F60[];
extern char D_40134F90[];
s32 func_400EB788(void *, void *, s32);
void dbgPrintf(char *, ...);

extern s32 D_4012E31C;
extern s32 D_401B4274;
extern char D_401B4278[];
extern char D_401B42B8[];
extern char D_401B42F8[];
extern char D_40134DF8[];
extern char D_40134E00[];
extern char D_40134E20[];
extern char D_40134E30[];
extern char D_40134E40[];
void nicosysdRebootRequest(void);
s32 iosCreateSema(s32, s32, s32);

void nicosysdForceEchoReadCallBack(void *arg0, s32 *arg1)
{
    s32 rem;
    s32 n;
    s32 err;
    char *buf;

    if (D_4012E310 != 0) {
        rem = arg1[2];
        if (rem > 0) {
            buf = D_401B3E88;
            do {
                err = 0;
                n = rem < 0x3E9 ? rem : 1000;
                if (D_4012E310 != 0) {
                    err = func_400EB788(arg0, buf, n);
                }
                if (err != 0) {
                    iosJumpRecoverPoint(D_40134F60);
                }
                rem -= n;
                *(char *)(n + (s32)buf) = 0;
            } while (rem > 0);
        }
    }
}

void nicosysdEchoDdebugPrintReadCallBack(void *arg0, s32 *arg1)
{
    s32 rem;
    s32 n;
    s32 err;
    char *buf;

    if (D_4012E310 != 0) {
        rem = arg1[2];
        if (rem > 0) {
            buf = D_401B3E88;
            do {
                err = 0;
                n = rem < 0x3E9 ? rem : 1000;
                if (D_4012E310 != 0) {
                    err = func_400EB788(arg0, buf, n);
                }
                if (err != 0) {
                    iosJumpRecoverPoint(D_40134F60);
                }
                rem -= n;
                *(char *)(n + (s32)buf) = 0;
                dbgPrintf(D_40134F90, buf);
            } while (rem > 0);
        }
    }
}

void nicosysdInit(void)
{
    if (D_4012E310 != 0) {
        iosSPrintf(D_401B4278, D_40134DF8, D_40134E00, D_40134E20);
        iosSPrintf(D_401B42B8, D_40134DF8, D_40134E00, D_40134E30);
        iosSPrintf(D_401B42F8, D_40134DF8, D_40134E00, D_40134E40);
        nicosysdRebootRequest();
        D_4012E31C = 1;
        D_401B4274 = iosCreateSema(1, 1, 0);
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0189_nicosysdForceEchoReadCallBack", func_400EC3F0);

void func_400EC3F0(void *arg0, s32 *arg1)
{
    s32 size = arg1[2];
    u8 buf[size];

    nicosysdRecvDataRead((s32)arg0, buf, size);
}

s32 csvMakeOpen(char *name)
{
    char buf[0x20];
    s32 res[4];
    s32 cmd;
    s32 size;
    s32 tot;
    s32 len = strlen(name);
    char str[len + 0x3C];

    size = len + 0x3C;
    tot = len + 0x44;
    cmd = 1000;
    iosSPrintf(str, D_40134FB0, name);

    nicosysdSendDataStart(buf, 0x3E9, &rootPtn, tot);
    nicosysdSendDataWrite(buf, &cmd, 4);
    nicosysdSendDataWrite(buf, &size, 4);
    nicosysdSendDataWrite(buf, str, size);
    nicosysdExec(buf, res, func_400EC3F0);
    return res[1];
}

s32 csvMakeBlockWriteData(s32 id, char *fmt, ...)
{
    char buf[0x20];
    s32 res[4];
    s32 cmd;
    s32 len;
    va_list args;

    cmd = 0x7D6;
    __builtin_stdarg_start(args, fmt);
    D_401B4348[0x1000] = 0;
    vsprintf(D_401B4348, fmt, args);
    __builtin_va_end(args);
    if (D_401B4348[0x1000] != 0) {
        iosJumpRecoverPoint(D_40134FB8);
    }
    len = strlen(D_401B4348) + 1;
    nicosysdSendDataStart(buf, 0x3E9, &rootPtn, len + 12);
    nicosysdSendDataWrite(buf, &cmd, 4);
    nicosysdSendDataWrite(buf, &id, 4);
    nicosysdSendDataWrite(buf, &len, 4);
    nicosysdSendDataWrite(buf, D_401B4348, len);
    nicosysdExec(buf, res, func_400EC3F0);
    return res[1];
}

s32 csvMakeClose(s32 id)
{
    char buf[0x20];
    s32 res[4];
    s32 cmd = 2000;
    nicosysdSendDataStart(buf, 0x3E9, &rootPtn, 8);
    nicosysdSendDataWrite(buf, &cmd, 4);
    nicosysdSendDataWrite(buf, &id, 4);
    nicosysdExec(buf, res, func_400EC3F0);
    return res[1];
}

s32 csvMakeDeleteSegment(s32 id, char *name)
{
    char buf[0x20];
    s32 res[4];
    s32 cmd;
    s32 len;
    len = strlen(name) + 1;
    cmd = 2001;
    nicosysdSendDataStart(buf, 0x3E9, &rootPtn, len + 12);
    nicosysdSendDataWrite(buf, &cmd, 4);
    nicosysdSendDataWrite(buf, &id, 4);
    nicosysdSendDataWrite(buf, &len, 4);
    nicosysdSendDataWrite(buf, name, len);
    nicosysdExec(buf, res, func_400EC3F0);
    return res[1];
}

s32 csvMakeCreateNewSegment(s32 id, char *name)
{
    char buf[0x20];
    s32 res[4];
    s32 cmd;
    s32 len;
    len = strlen(name) + 1;
    cmd = 2003;
    nicosysdSendDataStart(buf, 0x3E9, &rootPtn, len + 12);
    nicosysdSendDataWrite(buf, &cmd, 4);
    nicosysdSendDataWrite(buf, &id, 4);
    nicosysdSendDataWrite(buf, &len, 4);
    nicosysdSendDataWrite(buf, name, len);
    nicosysdExec(buf, res, func_400EC3F0);
    return res[1];
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0189_nicosysdForceEchoReadCallBack", func_400EC808);

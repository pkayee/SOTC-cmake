#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0188__dsysOpen", _dsysOpen);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0188__dsysOpen", dsysClose);

extern int LoaderSysFRead(int, void *, int);
extern void iosJumpRecoverPoint(const char *);
extern const char D_40134CB0[];

int dsysRead(void *arg0, void *buffer, int size) {
    int var_s0;

    var_s0 = -1;
    if ((*(int *)((char *)(arg0) + 4)) == 0) {
        var_s0 = LoaderSysFRead((*(int *)((char *)(arg0) + 0)), buffer, size);
    } else {
        iosJumpRecoverPoint(D_40134CB0);
    }
    return var_s0;
}

extern int LoaderSysFWrite(int, void *, int);
extern const char D_40134CD0[];

int dsysWrite(void *arg0, void *buffer, int size) {
    int var_s0;

    var_s0 = -1;
    if ((*(int *)((char *)(arg0) + 4)) == 0) {
        var_s0 = LoaderSysFWrite((*(int *)((char *)(arg0) + 0)), buffer, size);
    } else {
        iosJumpRecoverPoint(D_40134CD0);
    }
    return var_s0;
}

typedef struct DsysFile {
    int a;
    int b;
    int c;
    struct DsysFile *next;
} DsysFile;
extern DsysFile *D_401B3E7C;
extern int D_401B3E80;
extern DsysFile dsysFileList[];

void dsysFileInit(void)
{
    int i;

    D_401B3E80 = 0;
    D_401B3E7C = 0;
    for (i = 0; i < 8; i++) {
        dsysFileList[i].next = D_401B3E7C;
        D_401B3E7C = &dsysFileList[i];
    }
}

void CreateEndAutoModFile(void) {
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0188__dsysOpen", func_400EB788);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0188__dsysOpen", func_400EB990);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0188__dsysOpen", func_400EBB08);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0188__dsysOpen", nicosysdRebootRequest);

typedef struct Ptn Ptn;
typedef struct { int id, b, pos; void *buf; int size; } SendBuf;
extern int D_4012E310;
extern void *iosMallocAlign(Ptn *, int, int);

void nicosysdSendDataStart(SendBuf *b, int id, Ptn *ptn, int size)
{
    if (D_4012E310 != 0) {
        b->size = size;
        if (size != 0)
            b->buf = iosMallocAlign(ptn, size, 16);
        b->id = id;
        b->pos = 0;
    }
}

extern const char D_40134F20[];
extern void *memcpy(void *, const void *, unsigned int);

void nicosysdSendDataWrite(SendBuf *b, void *src, int n)
{
    if (D_4012E310 != 0) {
        memcpy(b->buf + b->pos, src, n);
        b->pos += n;
        if (b->size < b->pos) {
            iosJumpRecoverPoint(D_40134F20);
            b = 0;
        }
    }
}

extern int func_400EB788(int, int, int);

int nicosysdRecvDataRead(int a, int b, int c)
{
    if (D_4012E310 == 0)
        return 0;
    return func_400EB788(a, b, c);
}

extern int D_401B4274;
extern void func_400EB990(int, int);
extern void func_400EBB08(int);

void nicosysdExec(int arg0, int arg1, int arg2)
{
    if (D_4012E310 != 0) {
        WaitSema(D_401B4274);
        func_400EBB08(arg0);
        func_400EB990(arg1, arg2);
        SignalSema(D_401B4274);
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0188__dsysOpen", nicosysdDummyReadCallBack);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0188__dsysOpen", nicosysdEchoReadCallBack);

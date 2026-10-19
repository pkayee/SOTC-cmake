#include "common.h"

typedef struct DsysFile {
    int a;
    int b;
    int c;
    struct DsysFile *next;
} DsysFile;
extern DsysFile *D_401B3E7C;
extern DsysFile *D_401B3E80;
extern DsysFile dsysFileList[];
extern void iosJumpRecoverPoint();

/* dsys file slot open: pop a slot off the free list D_401B3E7C onto the used list D_401B3E80, fill mode b=dev c=mode, open by name when dev is 0, give the slot back on failure */
extern const char D_40134C68[];
extern s32 func_400EA7A0(s32 *, char *, s32);
extern const char D_40134C90[];
extern s32 LoaderSysFClose(s32);

extern char D_401B3E88[];
extern char D_40134F60[];

static inline DsysFile *dsysSlotPop(void)
{
    DsysFile *f;

    f = D_401B3E7C;
    if (f != 0) {
        D_401B3E7C = f->next;
        f->next = D_401B3E80;
        D_401B3E80 = f;
    }
    return f;
}
static inline void dsysSlotFree(DsysFile *f)
{
    DsysFile *cur;
    DsysFile *prev;

    prev = 0;
    cur = D_401B3E80;
    while (cur != 0) {
        if (f == cur) {
            goto found;
        }
        prev = cur;
        cur = cur->next;
    }
    return;
found:
    if (prev != 0) {
        prev->next = cur->next;
    } else {
        D_401B3E80 = cur->next;
    }
    f->next = D_401B3E7C;
    D_401B3E7C = f;
}

DsysFile *_dsysOpen(char *name, s32 dev, s32 mode)
{
    DsysFile *f;
    DsysFile *ret;

    f = dsysSlotPop();
    if (f == 0) {
        return 0;
    }
    {
        f->c = mode;
        f->b = dev;
        ret = f;
        if (dev == 0) {
            if (func_400EA7A0((s32 *)f, name, mode) < 0) {
                ret = 0;
            }
        } else {
            iosJumpRecoverPoint(D_40134C68);
        }
        if (ret == 0) {
            dsysSlotFree(f);
        }
    }
    return ret;
}

/* close a dsys file slot: LoaderSysFClose for dev 0, then unlink it from the used list D_401B3E80 and push it back on the free list D_401B3E7C */
void dsysClose(DsysFile *f)
{
    if (f->b == 0) {
        LoaderSysFClose(f->a);
    } else {
        iosJumpRecoverPoint(D_40134C90);
    }
    dsysSlotFree(f);
}

extern int LoaderSysFRead(int, void *, int);
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
extern void func_400EB990(char *, void (*)(DsysFile *, char *));
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

/* fifo dummy read callback: drain the packet payload into D_401B3E88 in chunks of at most 1000 bytes, no terminator */
void nicosysdDummyReadCallBack(void *arg0, s32 *arg1)
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
                    err = func_400EB788((int)arg0, (int)buf, n);
                }
                if (err != 0) {
                    iosJumpRecoverPoint(D_40134F60);
                }
                rem -= n;
            } while (rem > 0);
        }
    }
}

/* fifo echo read callback: read the packet payload into D_401B3E88 in chunks of at most 1000 bytes and terminate each chunk with a zero byte */
void nicosysdEchoReadCallBack(void *arg0, s32 *arg1)
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
                    err = func_400EB788((int)arg0, (int)buf, n);
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

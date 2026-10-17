#include "common.h"

int Deci2Call(int func, void *args);

extern u8 D_0014B008[];

int sceDeci2Open(u16 protocol, void *opt, void (*handler)(int, int, void *))
{
    s32 args[4];

    args[0] = protocol;
    args[1] = (s32)opt;
    args[2] = (s32)handler;
    args[3] = (s32)D_0014B008 | 0x20000000;
    return Deci2Call(1, args);
}

int sceDeci2Close(int s)
{
    s32 args[4];

    args[0] = s;
    return Deci2Call(2, args);
}

int sceDeci2ReqSend(int s, s8 dest)
{
    s32 args[4];

    args[0] = s;
    args[1] = dest;
    return Deci2Call(3, args);
}

void sceDeci2Poll(int s)
{
    s32 args[4];

    args[0] = s;
    Deci2Call(4, args);
}

int sceDeci2GrpOpen(u8 group, void *opt, void (*handler)(int, int, void *))
{
    s32 args[8];

    args[0] = group;
    args[1] = (s32)opt;
    args[2] = (s32)handler;
    return Deci2Call(0x20, args);
}

int sceDeci2GrpClose(int s)
{
    s32 args[4];

    args[0] = s;
    return Deci2Call(0x21, args);
}

int sceDeci2ExRecv(int s, void *buf, u16 len)
{
    s32 args[4];

    args[0] = s;
    args[1] = (s32)buf;
    args[2] = len;
    return Deci2Call(-5, args);
}

int sceDeci2ExSend(int s, void *buf, u16 len)
{
    s32 args[4];

    args[0] = s;
    args[1] = (s32)buf;
    args[2] = len;
    return Deci2Call(-6, args);
}

int sceDeci2ExReqSend(int s, s8 dest)
{
    s32 args[4];

    args[0] = s;
    args[1] = dest;
    return Deci2Call(-7, args);
}

int sceDeci2ExLock(int s)
{
    s32 args[4];

    args[0] = s;
    return Deci2Call(-8, args);
}

int sceDeci2ExUnLock(int s)
{
    s32 args[4];

    args[0] = s;
    return Deci2Call(-9, args);
}

void kputs(char *str)
{
    s32 args[4];

    args[0] = (s32)str;
    Deci2Call(0x10, args);
}

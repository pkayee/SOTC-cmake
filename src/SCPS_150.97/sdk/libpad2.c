#include "common.h"

extern u32 D_00133AE8[];
extern u32 D_00133AF8[];
extern u8 D_001386B8[];
int scePad2DeleteSocket(int);
int func_00115750(int socket);
void *func_00115810(int socket);
int func_00115878(int socket);
void *memcpy(void *dst, const void *src, u32 n);
extern u8 D_0014B72C[];
u8 *func_001157A8(int socket);
void func_001156D8(int socket);
int sceDbcReceiveData(int socket, s32 flags, u8 *buf, u8 *out);
int sceDbcCreateSocket(void *param, void *buf, void *buf2);

typedef struct
{
    u32 option;
    u32 flags;
    s32 port;
    s32 slot;
    s32 number;
    u8 name[16];
} Pad2Create;

typedef struct
{
    u32 option;
    s32 port;
    s32 slot;
    s32 number;
    u8 name[16];
} Pad2SocketParam;

typedef struct
{
    u32 valid;
    u32 kind;
    u32 byte;
    u32 shift;
} Pad2Button;

typedef struct
{
    u32 w[4];
    u8 *buf;           /* 0x10: two 0x80-byte receive buffers */
    Pad2Button btn[50]; /* 0x14 */
} Pad2Slot;

extern Pad2Slot D_0014B718[];
#define PAD2SLOT(i) (D_0014B718[i])

int scePad2Init(int mode)
{
    int i;

    D_00133AE8[0] = 1;
    for (i = 0; i < 16; i++)
    {
        D_0014B718[i].w[0] = 0;
        D_0014B718[i].w[1] = 0;
        D_0014B718[i].w[2] = 0;
        D_0014B718[i].w[3] = 0;
    }
    return 1;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libpad2", scePad2End);
int scePad2End(void)
{
    s32 i;
    s32 ret;

    D_00133AE8[0] = 0;
    for (i = 0; i < 16; i++)
    {
        if (*(s32 *)((u8 *)D_0014B718 + i * 0x334) != 0)
        {
            ret = scePad2DeleteSocket(i);
            if (ret < 0)
            {
                return ret;
            }
        }
    }
    return 1;
}

extern const char D_00138660[];

int scePad2CreateSocket(Pad2SocketParam *param, void *buf)
{
    Pad2Create loc;
    s32 ret;

    if ((u32)buf & 0x3F)
    {
        scePrintf(D_00138660, buf);
        return -1;
    }
    if (param != NULL)
    {
        loc.option = param->option;
        loc.port = param->port;
        loc.slot = param->slot;
        loc.number = param->number;
        memcpy(loc.name, param->name, 16);
    }
    else
    {
        loc.option = 0;
        loc.port = 0;
        loc.slot = 0;
        loc.number = 0;
        loc.name[0] = 0;
    }
    loc.flags = 1;
    loc.option |= 1;
    ret = sceDbcCreateSocket(&loc, buf, (u8 *)buf + 0x80);
    if (ret < 0)
    {
        return ret;
    }
    *(s32 *)((u8 *)D_0014B718 + ret * 0x334) = 1;
    *(void **)((u8 *)D_0014B718 + ret * 0x334 + 0x10) = buf;
    func_001156D8(ret);
    return ret;
}

int scePad2DeleteSocket(int socket)
{
    s32 ret;

    ret = sceDbcDeleteSocket(socket);
    if (ret < 0)
    {
        return ret;
    }
    *(s32 *)((u8 *)D_0014B718 + socket * 0x334) = 0;
    *(s32 *)((u8 *)D_0014B718 + socket * 0x334 + 4) = 0;
    *(s32 *)((u8 *)D_0014B718 + socket * 0x334 + 0xC) = 0;
    return 1;
}

/* NEARMISS-STUB scePad2Read */
#if 0 /* NEARMISS 93.3% cat=branch-layout sub=- | branch-layout: target loads ptr[2] straight into a2 for memcpy (ours copies via v0); ptr+0x1C!=0 check is beql with lw in delay slot; ternary return kept (if/el | attempts=2 */
int scePad2Read(int socket, u8 *buf)
{
    u8 *ptr;

    if (D_0014B718[socket].w[0] == 0)
    {
        return -1;
    }
    if (D_0014B718[socket].w[1] == 0)
    {
        if (func_00115750(socket) < 0)
        {
            return -1;
        }
    }
    ptr = func_001157A8(socket);
    if (ptr[2] != 0 && ptr + 0x1C != 0)
    {
        memcpy(buf, ptr + 0x1C, ptr[2]);
        func_001158D8(ptr + 0x1C + ptr[2], (s32 *)(D_0014B72C + socket * 0x334));
    }
    return (*(s32 *)(ptr + 4) != 0) ? ptr[2] : -1;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libpad2", scePad2Read);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libpad2", scePad2GetButtonProfile);
int scePad2GetButtonProfile(int socket, u8 *buf)
{
    u8 *ptr;
    u8 n;

    scePad2GetState(socket);
    if (PAD2SLOT(socket).w[1] == 0)
    {
        if (func_00115750(socket) < 0)
        {
            return -1;
        }
    }
    ptr = func_00115810(socket);
    n = ptr[3];
    if (n != 0 && ptr + 0x1C != 0)
    {
        memcpy(buf, ptr + 0x1C + ptr[2], n);
        func_001158D8(ptr + (ptr[2] + 0x1C), (s32 *)(D_0014B72C + socket * 0x334));
    }
    if (*(s32 *)(ptr + 4) == 0)
        return -1;
    return ptr[3];
}


/* NEARMISS-STUB scePad2GetState */
#if 0 /* NEARMISS 81.04% cat=uncategorized sub=- | mask chain/frame differ (salvage kK43/kR48 live-C revert) | attempts=3 */
int scePad2GetState(int socket)
{
    u8 *p;
    u8 st;
    u32 rbuf[3];
    s32 flags;
    s32 ret;

    if (D_0014B718[socket].w[1] == 0)
    {
        if (func_00115750(socket) < 0)
        {
            return 0;
        }
    }
    ret = func_00115878(socket);
    if (ret != 0)
    {
        p = func_00115810(socket);
        if (*(s32 *)(p + 4) != 0 || func_00115750(socket) >= 0)
        {
            st = p[0];
            return st;
        }
    }
    else
    {
        flags = (flags & -0x4000) | 0xC;
        flags = (flags & 0xFFFF3FFF) | 0x8000;
        flags = (flags & 0xFF00FFFF) | 0x10000;
        flags = (flags & 0xFFFFFFFF00FFFFFF) | 0x1000000;
        ret = sceDbcReceiveData(socket, flags, (u8 *)rbuf, &st);
        if (ret >= 0)
        {
            return st;
        }
    }
    D_0014B718[socket].w[1] = 0;
    func_001156D8(socket);
    return 0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libpad2", scePad2GetState);

/* NEARMISS-STUB scePad2GetButtonInfo */
#if 0 /* NEARMISS 98.84% cat=branch-layout sub=- | cond-move: target keeps kind in v0 then movn v0,zero,bit; ours folds to movz with 0 preset (return bit?0:kind); switch dispatch already matches | attempts=1 */
int scePad2GetButtonInfo(int socket, u8 *buf, int idx)
{
    Pad2Button rec;
    u8 v;
    u8 *base;

    base = (u8 *)D_0014B718 + (idx * 16 + socket * 0x334);
    rec = *(Pad2Button *)(base + 0x14);
    if (rec.valid != 0)
    {
        switch (rec.kind)
        {
        case 1:
            return ((buf[rec.byte] >> rec.shift) & 1) ? 0 : rec.kind;
        case 8:
            v = buf[rec.byte] >> rec.shift;
            if (rec.shift != 0)
            {
                rec.byte++;
                v = (v | (buf[rec.byte] << (8 - rec.shift))) & 0xFF;
            }
            return v;
        }
    }
    return -1;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libpad2", scePad2GetButtonInfo);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libpad2", func_001156D8);
void func_001156D8(s32 socket)
{
    u8 *p;
    s32 i;

    p = PAD2SLOT(socket).buf;
    i = 1;
    do
    {
        p[0] = 0;
        *(s32 *)(p + 0x7C) = 0;
        p[1] = 0;
        p[3] = 0;
        i--;
        p[2] = 0;
        *(s32 *)(p + 4) = 0;
        memset(p + 0x1C, 0xFF, 0x20);
        p += 0x80;
    } while (i >= 0);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libpad2", func_00115750);
s32 func_00115750(s32 socket)
{
    s32 ret;

    ret = sceDbcGetDepNumber(socket);
    if (ret < 0)
    {
        return ret;
    }
    PAD2SLOT(socket).w[3] = ret;
    PAD2SLOT(socket).w[1] = 1;
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libpad2", func_001157A8);
u8 *func_001157A8(s32 socket)
{
    u8 *bufs[2];
    u8 *p;

    p = PAD2SLOT(socket).buf;
    bufs[0] = p;
    bufs[1] = p + 0x80;
    SyncDCache(p, p + 0xFF);
    return bufs[*(s32 *)(bufs[0] + 0x7C) < *(s32 *)(bufs[1] + 0x7C)];
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libpad2", func_00115810);
void *func_00115810(s32 socket)
{
    u8 *bufs[2];
    u8 *p;

    p = PAD2SLOT(socket).buf;
    bufs[0] = p;
    bufs[1] = p + 0x80;
    SyncDCache(p, p + 0x100);
    return bufs[*(s32 *)(bufs[0] + 0x7C) < *(s32 *)(bufs[1] + 0x7C)];
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libpad2", func_00115878);
s32 func_00115878(s32 socket)
{
    u8 *p;
    s32 val;

    p = func_001157A8(socket);
    val = *(s32 *)(p + 0x7C);
    if (val == 0)
    {
        return 0;
    }
    if (val == PAD2SLOT(socket).w[2])
    {
        return 0;
    }
    PAD2SLOT(socket).w[2] = val;
    return 1;
}

int func_001158D8(u8 *arg0, s32 *arg1)
{
    s32 t0 = 0;
    s32 t1 = 0;
    s32 n;
    s32 a3 = 0;

    for (n = 0; n < 40; n++)
    {
        if ((arg0[0] >> t0) & 1)
        {
            arg1[0] = 1;
            arg1[2] = t1;
            arg1[3] = a3;
            if ((u32)(n - 16) < 16 || (u32)(n - 35) < 4)
            {
                arg1[1] = 8;
                t1++;
            }
            else
            {
                a3++;
                arg1[1] = 1;
                if ((a3 & 7) == 0)
                {
                    t1++;
                    a3 = 0;
                }
            }
        }
        else
        {
            arg1[0] = 0;
            arg1[2] = 0;
            arg1[3] = 0;
        }
        t0++;
        if ((t0 & 7) == 0)
        {
            arg0++;
            t0 = 0;
        }
        arg1 += 4;
    }
    return 1;
}

void scePad2StateIntToStr(int state, u8 *str)
{
    if ((u32)state < 4)
    {
        strcpy((char *)str, (char *)D_00133AF8[state]);
        return;
    }
    *str = D_001386B8[0];
}

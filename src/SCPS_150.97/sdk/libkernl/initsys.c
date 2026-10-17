#include "common.h"
#include "sdk/ee/eekernel.h"

extern s32 D_00132AA0[];
extern s32 D_00132AA4[];
extern s32 D_00138350[];
extern s32 D_00138360[];

void func_0010FDC8(void);
void InitAlarm(void);
void InitTimer(s32 mode);
void StartTimerSystemTime(void);
void InitThread(void);
void InitExecPS2(void);
void InitTLBFunctions(void);
void sceSifInitRebootNotify(void);
void GetOsdConfigParam(u32 *param);
void SetOsdConfigParam(u32 *param);
void func_0010FF30(s32 a, s32 b);
void func_0010FF40(s32 a, s32 *b, s32 c);
s32 func_0010FF88(s32 a);
extern s32 D_00133250[];
extern s32 D_00132AA8[];
extern s32 D_00132A90[];
void func_0010FEC8(s32 a, s32 b);
s32 func_0010FD80(s32 a, s32 b, s32 c);
s32 func_0010FD40(s32 a, s32 b, s32 c);
s32 kCopy2(s32 *dst, s32 *src, s32 n);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", supplement_crt0);
void supplement_crt0(void)
{
    struct SemaParam sema1;
    struct SemaParam sema2;

    sema1.maxCount = 1;
    sema1.initCount = 1;
    sema1.option = (u32)D_00138350;
    sema2.maxCount = 1;
    sema2.initCount = 1;
    sema2.option = (u32)D_00138360;
    D_00132AA0[0] = CreateSema(&sema1);
    D_00132AA4[0] = CreateSema(&sema2);
}

s32 __sceKernlGetEhSemaId(void)
{
    return D_00132AA4[0];
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", Copy2);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", kCopy2);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", func_0010FD40);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", func_0010FD80);

extern s32 *D_00132A88;
void Copy2(void *dst, void *src, s32 size);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", GetSystemCallEntry);
s32 GetSystemCallEntry(s32 index)
{
    s32 entry;

    Copy2(&entry, D_00132A88 + index, 4);
    return entry;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", func_0010FDC8);
void func_0010FDC8(void)
{
    u32 s1;
    u32 s0;
    u32 s3;
    u32 s2;

    func_0010FEC8(D_00132A90[0], D_00132A90[1]);
    func_0010FEC8(D_00132A90[2], D_00132A90[3]);
    s3 = func_0010FD80(0x80000000, 0x80080000, (s32)func_0010FD40);
    s2 = func_0010FD80(0x80000000, 0x80080000, (s32)kCopy2);
    s1 = s3 - 0x20C;
    s0 = s2 - 0x168;
    while (s1 != s0)
    {
        if (s1 < s0)
        {
            s3 = func_0010FD80(s3 + 4, 0x80080000, (s32)func_0010FD40);
            s1 = s3 - 0x20C;
        }
        else
        {
            s2 = func_0010FD80(s2 + 4, 0x80080000, (s32)kCopy2);
            s0 = s2 - 0x168;
        }
    }
    D_00132A88 = (s32 *)s1;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", func_0010FEC8);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", _InitSys);
void _InitSys(void)
{
    supplement_crt0();
    func_0010FDC8();
    InitAlarm();
    InitTimer(2);
    StartTimerSystemTime();
    InitThread();
    InitExecPS2();
    InitTLBFunctions();
    sceSifInitRebootNotify();
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", func_0010FF30);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", func_0010FF40);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", func_0010FF50);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", func_0010FF88);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", func_0010FF98);
s32 func_0010FF98(void)
{
    u32 config[2];

    GetOsdConfigParam(config);
    config[1] = (config[0] & 0xFFFF1FFF) | 0x2000;
    SetOsdConfigParam(&config[1]);
    GetOsdConfigParam(&config[1]);
    SetOsdConfigParam(config);
    return ((config[1] >> 13) & 7) == 0;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/initsys", InitExecPS2);
void InitExecPS2(void)
{
    s32 *base;
    s32 *p;
    u32 i;

    if (func_0010FF98())
    {
        base = D_00133250;
        func_0010FF30(base[0], base[1]);
        func_0010FF40(0x80074000, D_00132AA8, 0x7A8);
        FlushCache(0);
        FlushCache(2);
        func_0010FF30(base[2], base[3]);
        p = base + 4;
        i = 2;
        do
        {
            s32 v = func_0010FF88(p[0]);

            i++;
            func_0010FF30(p[0], v);
            p += 2;
        } while (i < 3);
    }
}

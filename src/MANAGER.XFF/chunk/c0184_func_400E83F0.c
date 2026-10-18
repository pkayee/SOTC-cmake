#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0184_func_400E83F0", func_400E83F0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0184_func_400E83F0", func_400E8A70);

/* NEARMISS-STUB adpcmOpenChkComplete */
#if 0 /* NEARMISS 95.38% cat=regalloc sub=- | mult result and array base register assigned swapped (v0/v1) | attempts=1 */
extern s32 D_4012E018;
extern u64 D_401B2460;

u64 adpcmOpenChkComplete(s32 arg0)
{
    u64 ret;

    ret = 1;
    if (D_4012E018 != 0)
    {
        ret = (*(u64 *)((u8 *)&D_401B2460 + arg0 * 0x560) >> 36) & 1;
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0184_func_400E83F0", adpcmOpenChkComplete);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0184_func_400E83F0", adpcmPlay);
extern s32 D_4012E018;
extern u8 D_401B2428[];
extern void Sg2ExStAdpcmPlay(void *);

void adpcmPlay(s32 arg0, f32 arg1)
{
    u8 *p;

    p = D_401B2428 + arg0 * 0x560;
    if (D_4012E018 != 0)
    {
        Sg2ExStAdpcmPlay(p + 0x280);
        *(f32 *)(p + 0x4C) = arg1;
        *(u64 *)(p + 0x38) |= 0x200000000ULL;
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0184_func_400E83F0", adpcmCloseReq);
void adpcmCloseReq(s32 arg0, s32 *arg1)
{
    u8 *p;

    if (D_4012E018 != 0)
    {
        p = D_401B2428 + arg0 * 0x560;
        *(s32 **)(p + 0x44) = arg1;
        if (arg1 != 0)
        {
            *arg1 = 0;
        }
        *(u64 *)(p + 0x38) |= 0x2000000000ULL;
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0184_func_400E83F0", adpcmCloseFadeReq);
void adpcmCloseFadeReq(s32 arg0, f32 arg1, s32 *arg2)
{
    u8 *p;

    if (D_4012E018 != 0)
    {
        p = D_401B2428 + arg0 * 0x560;
        *(f32 *)(p + 0x50) = arg1;
        *(u64 *)(p + 0x38) |= 0x8000000000ULL;
        *(s32 *)(p + 0x58) = 0;
        *(s32 **)(p + 0x44) = arg2;
        if (arg2 != 0)
        {
            *arg2 = 0;
        }
        *(u64 *)(p + 0x38) |= 0x2000000000ULL;
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0184_func_400E83F0", adpcmCloseFadeSetVol);
extern s32 D_4012E018;
extern u8 D_401B2478[];

void adpcmCloseFadeSetVol(s32 arg0, f32 arg1)
{
    if (D_4012E018 != 0)
    {
        *(f32 *)(D_401B2478 + arg0 * 0x560) = arg1;
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0184_func_400E83F0", adpcmCloseChkComplete);
extern s32 D_4012E018;

s32 adpcmCloseChkComplete(s32 arg0)
{
    if (D_4012E018 == 0)
    {
        return 1;
    }
    return arg0 == 1;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0184_func_400E83F0", adpcmDeleteAdpcmSeq);
void adpcmDeleteAdpcmSeq(s32 arg0)
{
    u8 *p;

    if (D_4012E018 != 0)
    {
        p = D_401B2428 + arg0 * 0x560;
        *(u64 *)(p + 0x38) |= 0x4000000000ULL;
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0184_func_400E83F0", adpcmSetVol);
void adpcmSetVol(s32 arg0, f32 arg1, f32 arg2)
{
    u8 *p;

    if (D_4012E018 != 0)
    {
        p = D_401B2428 + arg0 * 0x560;
        if (((*(u64 *)(p + 0x38)) >> 39 & 1) == 0)
        {
            *(f32 *)(p + 0x50) = arg2;
            *(f32 *)(p + 0x58) = arg1;
        }
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0184_func_400E83F0", adpcmSetPitch);
void adpcmSetPitch(s32 arg0, f32 arg1, f32 arg2)
{
    u8 *p;

    if (D_4012E018 != 0)
    {
        p = D_401B2428 + arg0 * 0x560;
        *(f32 *)(p + 0x60) = arg1;
        *(f32 *)(p + 0x64) = arg2;
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0184_func_400E83F0", adpcmSetPan);
extern s32 D_4012E018;
extern u8 D_401B2490[];

void adpcmSetPan(s32 arg0, f32 arg1)
{
    if (D_4012E018 != 0)
    {
        *(f32 *)(D_401B2490 + arg0 * 0x560) = arg1;
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0184_func_400E83F0", adpcmMgrInit);

extern int D_4012E014;

void adpcmGamePause(int arg0)
{
    D_4012E014 = arg0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0184_func_400E83F0", func_400E8EF0);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0184_func_400E83F0", func_400E8FE8);
extern void Sg2ExStAdpcmTickProc(void *);

void func_400E8FE8(void)
{
    s32 i;
    u8 *p;

    p = D_401B2428;
    i = 2;
    do
    {
        if (*(s32 *)p != 0)
        {
            Sg2ExStAdpcmTickProc(p + 0x280);
        }
        i--;
        p += 0x560;
    } while (i >= 0);
}

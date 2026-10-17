#include "common.h"
#include "sdk/ee/sifrpc.h"

extern s32 D_0013242C[];
extern sceSifClientData D_00147340[];
extern s32 D_00147380[];
extern s32 D_001473C0[];

/* NEARMISS-STUB sceSifInitIopHeap */
#if 0 /* NEARMISS 93.8% cat=sched sub=- | bind loop, delay loop (4 nops) and serve test match; compiler schedules return-0 before the D_0013242C store (ours lui v1 + return-0 hoisted, target lui v0 stor | attempts=1 */
s32 sceSifInitIopHeap(void)
{
    s32 ret;
    s32 i;

    for (;;)
    {
        ret = sceSifBindRpc(D_00147340, 0x80000003, 0);
        if (ret < 0)
        {
            return -1;
        }
        if (D_00147340[0].serve != NULL)
        {
            break;
        }
        for (i = 0x100000; i != -1; i--)
        {
        }
    }
    D_0013242C[0] = 0;
    return 0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/iopheap", sceSifInitIopHeap);

s32 sceSifAllocIopHeap(s32 size)
{
    s32 ret;

    if (D_0013242C[0] < 0)
    {
        return 0;
    }
    D_001473C0[0] = size;
    ret = sceSifCallRpc(D_00147340, 1, 0, D_001473C0, 4, D_00147380, 4, NULL, NULL);
    if (ret < 0)
    {
        return 0;
    }
    return D_00147380[0];
}

s32 sceSifAllocSysMemory(s32 mode, s32 size, s32 addr)
{
    s32 ret;

    if (D_0013242C[0] < 0)
    {
        return 0;
    }
    D_001473C0[0] = size;
    D_001473C0[1] = mode;
    D_001473C0[2] = addr;
    ret = sceSifCallRpc(D_00147340, 4, 0, D_001473C0, 12, D_00147380, 4, NULL, NULL);
    if (ret < 0)
    {
        return 0;
    }
    return D_00147380[0];
}

s32 sceSifFreeSysMemory(void *addr)
{
    s32 ret;

    if (D_0013242C[0] < 0)
    {
        return 0;
    }
    D_001473C0[0] = (s32)addr;
    ret = sceSifCallRpc(D_00147340, 2, 0, D_001473C0, 4, D_00147380, 4, NULL, NULL);
    if (ret < 0)
    {
        return -1;
    }
    return D_00147380[0];
}

int sceSifFreeIopHeap(void *addr)
{
    return sceSifFreeSysMemory(addr);
}

/* NEARMISS-STUB sceSifLoadIopHeap */
#if 0 /* NEARMISS 83.3% cat=struct-layout sub=- | target loop reads fname[i] once (lbu, sll 24, beqz) and keeps a1 unclobbered; ours re-reads fname[i] after the store (aliasing) and peels the first iteration; a | attempts=1 */
s32 sceSifLoadIopHeap(u8 *fname, s32 arg)
{
    s32 i;
    s32 ret;

    if (D_0013242C[0] < 0)
    {
        return 0;
    }
    D_00147400[4] = fname[0];
    i = 0;
    if (fname[0] != 0)
    {
        for (i = 1; i < 0xFC; i++)
        {
            D_00147400[4 + i] = fname[i];
            if (fname[i] == 0)
            {
                break;
            }
        }
    }
    if (i == 0xFC)
    {
        i = 0xFB;
        D_00147400[0xFF] = 0;
    }
    *(s32 *)D_00147400 = arg;
    D_00147400[0xFF] = 0;
    ret = sceSifCallRpc(D_00147340, 3, 0, D_00147400, i + 5, D_00147380, 4, NULL, NULL);
    if (ret < 0)
    {
        return -1;
    }
    return D_00147380[0];
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/iopheap", sceSifLoadIopHeap);

u32 sceSifQueryMemSize(void)
{
    s32 ret;

    if (D_0013242C[0] < 0)
    {
        return 0;
    }
    ret = sceSifCallRpc(D_00147340, 5, 0, NULL, 0, D_00147380, 4, NULL, NULL);
    if (ret < 0)
    {
        return -1;
    }
    return D_00147380[0];
}

u32 sceSifQueryMaxFreeMemSize(void)
{
    s32 ret;

    if (D_0013242C[0] < 0)
    {
        return 0;
    }
    ret = sceSifCallRpc(D_00147340, 6, 0, NULL, 0, D_00147380, 4, NULL, NULL);
    if (ret < 0)
    {
        return -1;
    }
    return D_00147380[0];
}

u32 sceSifQueryTotalFreeMemSize(void)
{
    s32 ret;

    if (D_0013242C[0] < 0)
    {
        return 0;
    }
    ret = sceSifCallRpc(D_00147340, 7, 0, NULL, 0, D_00147380, 4, NULL, NULL);
    if (ret < 0)
    {
        return -1;
    }
    return D_00147380[0];
}

u32 sceSifQueryBlockTopAddress(u32 addr)
{
    s32 ret;

    if (D_0013242C[0] < 0)
    {
        return 0;
    }
    D_001473C0[0] = addr;
    ret = sceSifCallRpc(D_00147340, 8, 0, D_001473C0, 4, D_00147380, 4, NULL, NULL);
    if (ret < 0)
    {
        return -1;
    }
    return D_00147380[0];
}

u32 sceSifQueryBlockSize(u32 addr)
{
    s32 ret;

    if (D_0013242C[0] < 0)
    {
        return 0;
    }
    D_001473C0[0] = addr;
    ret = sceSifCallRpc(D_00147340, 9, 0, D_001473C0, 4, D_00147380, 4, NULL, NULL);
    if (ret < 0)
    {
        return -1;
    }
    return D_00147380[0];
}


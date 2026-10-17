#include "common.h"
//#include "sdk/ee/sifrpc.h"
#include "sdk/ee/eekernel.h"


extern int sceSifCallRpc(void *, unsigned int, unsigned int, void *, int, void *, int, void*);

// .data
static s32 D_40045EB4 = 0;
static void* D_40045EB8 = 0;
static s32 D_40045EBC = 0;
static s32 D_40045EC0 = 0;

// .bss
static s32 D_400F6DC0;
//extern sceSifClientData D_400F6DC8;
static char D_400F6DC8[56];
static char D_400F6E00[4224];
static s32 D_400F7EA0;





/* NEARMISS-STUB func_400303A8 */
#if 0 /* NEARMISS 47.7% cat=stack-frame sub=- | frame 0x1e0 in target vs 0x1d0 ours; callee-saved s-reg set/assignment and sd order differ (47.7%) | attempts=1 */
void func_40030620(void);

void func_400303A8(void)
{
    s32 ret;
    s32 count;
    s32 i;
    u8 buf0[0x80];
    u8 buf1[0x80];
    u8 buf2[0x80];

    for (;;)
    {
        do
        {
            WaitSema(D_400F6DC0);
            ret = sceSifCallRpc(D_400F6DC8, 1, 1, D_400F6E00, 32, buf0, 32, &func_40030620);
        } while (ret != 0);

        if (D_40045EB4 != 0)
        {
            WaitSema(D_400F6DC0);
            SignalSema(D_400F6DC0);
        }

        count = buf0[0];
        if (count != 0)
        {
            for (i = 0; i < count; i++)
            {
                if (buf0[2 + i] == 0)
                {
                    continue;
                }

                ret = 0;
                if (D_40045EB4 != 0)
                {
                    WaitSema(D_400F6DC0);
                    D_400F6E00[0] = 0;
                    ret = sceSifCallRpc(D_400F6DC8, 3, 1, D_400F6E00, 32, buf1, 32, &func_40030620);
                }
                if (ret != 0)
                {
                    continue;
                }

                if (D_40045EB4 != 0)
                {
                    WaitSema(D_400F6DC0);
                    SignalSema(D_400F6DC0);
                }

                for (;;)
                {
                    ret = 0;
                    if (D_40045EB4 != 0)
                    {
                        WaitSema(D_400F6DC0);
                        D_400F6E00[0] = i;
                        ret = sceSifCallRpc(D_400F6DC8, 2, 1, D_400F6E00, 32, buf2, 32, &func_40030620);
                    }
                    if (ret != 0)
                    {
                        break;
                    }

                    if (D_40045EB4 != 0)
                    {
                        WaitSema(D_400F6DC0);
                        SignalSema(D_400F6DC0);
                    }

                    if (buf2[1] == 0)
                    {
                        break;
                    }

                    if (D_40045EB8 != 0)
                    {
                        ((void (*)(void *))D_40045EB8)(buf2);
                    }
                }
            }
        }

        waitVscheduler();
    }
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dev", func_400303A8);

/* NEARMISS-STUB iosKeybdInit */
#if 0 /* NEARMISS 99.08% cat=sched sub=epilogue-loads | epilogue ld not interleaved like the target (99.08%) | attempts=2 */
// 99.08%: only diff restore order of ld ra / ld s0 (target s0 then ra)
s32 iosKeybdInit(void)
{
    D_40045EB4 = 0;
    sceSifInitRpc(0);
    return D_40045EB4;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dev", iosKeybdInit);
// The order of restoring save registers is different, functionally works though
//s32 iosKeybdInit(void)
//{
//    D_40045EB4 = 0;
//    sceSifInitRpc(0);
//    return D_40045EB4;
//}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dev", iosKeybdSetCallBackFunc);
s32 iosKeybdSetCallBackFunc(void* arg0)
{
    if (!D_40045EB4)
    {
        return 0;
    }
    {
        D_40045EB8 = arg0;
        return 1;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dev", func_40030620);
void func_40030620(void) {
    iSignalSema(D_400F6DC0);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dev", iosKeybdGetInfo);
void iosKeybdGetInfo(void* arg0)
{
    s32 sp0[2];
    WaitSema(D_400F6DC0);
    sp0[0] = 0;
    sceSifCallRpc(D_400F6DC8, 1, 1, D_400F6E00, 32, arg0, 32, &func_40030620);
}

/* NEARMISS-STUB func_400306A8 */
#if 0 /* NEARMISS 60.2% cat=uncategorized sub=- | not diffed: attempt (60.2%) references undeclared D_400F7E40/D_400F7E80/func_40030970 so it does not compile in live ios/dev.c; no diff yet | attempts=1 */
void func_400306A8(void)
{
    s32 ret;
    s32 i;
    u8 buf0[0x80];
    u8 buf1[0x80];
    s8 buf2[0x80];
    struct
    {
        s32 idx;
        s32 zero;
        s32 data[4];
    } evt;
    struct
    {
        s32 idx;
        s32 zero;
        s32 data[4];
    } tmp;

    for (;;)
    {
        do
        {
            ret = 0;
            if (D_40045EBC != 0)
            {
                WaitSema(D_400F7EA0);
                ret = sceSifCallRpc(D_400F7E40, 1, 1, D_400F7E80, 32, buf0, 32, func_40030970, 0);
            }
        } while (ret != 0);

        if (D_40045EBC != 0)
        {
            WaitSema(D_400F7EA0);
            SignalSema(D_400F7EA0);
        }

        if (buf0[0] != 0)
        {
            for (i = 0; i < buf0[0]; i++)
            {
                if (buf0[2 + i] == 0)
                {
                    continue;
                }

                ret = 0;
                if (D_40045EBC != 0)
                {
                    WaitSema(D_400F7EA0);
                    D_400F7E80[0] = 0;
                    ret = sceSifCallRpc(D_400F7E40, 3, 1, D_400F7E80, 32, buf1, 32, func_40030970, 0);
                }
                if (ret != 0)
                {
                    continue;
                }

                if (D_40045EBC != 0)
                {
                    WaitSema(D_400F7EA0);
                    SignalSema(D_400F7EA0);
                }

                for (;;)
                {
                    ret = 0;
                    if (D_40045EBC != 0)
                    {
                        WaitSema(D_400F7EA0);
                        D_400F7E80[0] = i;
                        ret = sceSifCallRpc(D_400F7E40, 2, 1, D_400F7E80, 32, buf2, 32, func_40030970, 0);
                    }
                    if (ret != 0)
                    {
                        break;
                    }

                    if (D_40045EBC != 0)
                    {
                        WaitSema(D_400F7EA0);
                        SignalSema(D_400F7EA0);
                    }

                    if (buf2[0] == 0)
                    {
                        break;
                    }

                    if (D_40045EC0 != 0)
                    {
                        tmp.idx = i;
                        tmp.zero = 0;
                        tmp.data[0] = buf2[1];
                        tmp.data[1] = buf2[2];
                        tmp.data[2] = buf2[3];
                        tmp.data[3] = buf2[4];
                        evt = tmp;
                        ((void (*)(void *))D_40045EC0)(&evt);
                    }
                }
            }
        }

        waitVscheduler();
    }
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dev", func_400306A8);

/* NEARMISS-STUB iosMouseInit */
#if 0 /* NEARMISS 80.0% cat=sched sub=- | return 0 materialised after ld ra in ours; target puts daddu v0,zero,zero before ld ra (return-value scheduling), 80.0% | attempts=2 */
// kR22 iosMouseInit 80%: target has daddu v0,zero,zero BEFORE ld ra after the jal; ours after. tried return 0, local ret=0, ret=call then 0, comma expr.
s32 iosMouseInit(void)
{
    D_40045EBC = 0;
    sceSifInitRpc(0);
    return 0;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dev", iosMouseInit);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dev", iosMouseSetCallBackFunc);
s32 iosMouseSetCallBackFunc(s32 arg0)
{
    if (!D_40045EBC)
    {
        return 0;
    }
    else {
        D_40045EC0 = arg0;
        return 1;
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dev", func_40030970);
void func_40030970(void) {
    iSignalSema(D_400F7EA0);
}




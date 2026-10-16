#include "common.h"

extern void isysInitGroup();
extern char subThreadGroup[];
typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[4];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
} SubThreadEnv;

typedef struct {
    u8 pad0[8];
    u8 type;
    u8 pad9[0x17];
    SubThreadEnv env;
} SubThread;

static inline SubThreadEnv *subthread_env(SubThread *t)
{
    switch (t->type) {
    case 6: case 9: case 11: case 12: case 13: case 14: case 22: case 29: case 33:
        return &t->env;
    default:
        return 0;
    }
}
#define SUBTHREAD_ENV(t) subthread_env(t)

extern void *memcpy();
extern void iosFree();
extern void isysSleepSubThread();
extern void *D_40045E98;
extern s32 D_40045E9C;

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", _isysCreateSubMsgQueue);
void _isysCreateSubMsgQueue(s32 *q, s32 arg1, s32 arg2, s32 arg3)
{
    q[1] = arg1;
    q[0] = arg2;
    q[2] = arg3;
    q[4] = 0;
    q[3] = 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", _isysRecvSubMsg);
s32 _isysRecvSubMsg(s32 *q, void *dst, s32 size)
{
    s32 rd;

    if (q[0] != size)
    {
        return 0;
    }
    rd = q[4];
    if (rd == q[3])
    {
        return 0;
    }
    memcpy(dst, (u8 *)q[1] + rd * q[0], size);
    {
        s32 n = q[4] + 1;
        q[4] = (n < q[2]) ? n : 0;
    }
    return 1;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", _isysSendSubMsg);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", InitSubThread);
void InitSubThread(void)
{
    isysInitGroup(&subThreadGroup);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysInitSubThreadExecEnv);
void isysInitSubThreadExecEnv(SubThread *t, s32 arg1)
{
    SubThreadEnv *e = SUBTHREAD_ENV(t);

    e->unk4 = e->unk0 = arg1;
    e->unk10 = e->unkC + e->unk14;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysStartSubThread);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysDeleteSubThread);
void isysDeleteSubThread(SubThread *t)
{
    SubThreadEnv *e = SUBTHREAD_ENV(t);

    if (e->unk18 != 0) {
        iosFree(e->unkC);
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysDumpSubThreadStatus);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysWakeupSubThread);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", func_4002EAFC);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysSleepSubThread);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", SubThreadTerminateRestorePoint);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysGetThisSubThread);
void *isysGetThisSubThread(void)
{
    return D_40045E98;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysInitSubThreadObj);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysCreateSubThreadS);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysSleepSubThreadM);
void isysSleepSubThreadM(s32 count)
{
    s32 i;

    if (count > 0) {
        i = count;
        do {
            isysSleepSubThread();
        } while (--i);
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysJumpSubThread);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", func_4002F17C);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysGetSubThreadWorkSize);
s32 isysGetSubThreadWorkSize(s32 arg0)
{
    return arg0 + 0x33;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysGetSubThreadStackUse);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysGetSubThreadStackSize);
s32 isysGetSubThreadStackSize(SubThread *t)
{
    return SUBTHREAD_ENV(t)->unk14;
}

void isysDumpSubThreadPC(void)
{}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysDebugSetSubThreadSleepProtection);
void isysDebugSetSubThreadSleepProtection(s32 arg0)
{
    D_40045E9C = arg0;
}

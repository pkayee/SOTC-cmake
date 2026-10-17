#include "common.h"

extern void isysInitGroup();
extern char subThreadGroup[];
typedef struct {
    s32 unk0;
    u32 unk4;
    u8 pad8[4];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 state;
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
extern void *iosMallocAlign(s32, s32, s32);
extern s32 rootPtn;
extern void isysSearchModuleFuncNameByAddr(void *, void *, s32);
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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysDumpSubThreadStatus);
void isysDumpSubThreadStatus(SubThread *t)
{
    SubThreadEnv *e = SUBTHREAD_ENV(t);
    void *a = iosMallocAlign((s32)&rootPtn, 0x100, 4);
    void *b = iosMallocAlign((s32)&rootPtn, 0x100, 4);

    isysSearchModuleFuncNameByAddr(a, b, e->unk0);
    iosFree(b);
    iosFree(a);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysWakeupSubThread);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", func_4002EAFC);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysSleepSubThread);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", SubThreadTerminateRestorePoint);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysGetThisSubThread);
void *isysGetThisSubThread(void)
{
    return D_40045E98;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysInitSubThreadObj);
s32 isysInitSubThreadObj(SubThread *t, s32 entry, s32 unused, s32 size)
{
    SubThreadEnv *e = SUBTHREAD_ENV(t);
    void *stack = iosMallocAlign(*(s32 *)t, size, 0x10);

    e->unkC = (s32)stack;
    if (stack == NULL)
    {
        return -1;
    }
    e->unk14 = size;
    e->unk0 = entry;
    e->unk18 = 1;
    e->unk4 = entry;
    e->unk10 = (s32)stack + size;
    isysAddGroupWithLinkParam(t, subThreadGroup, 0, 0);
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/subthread", isysCreateSubThreadS);
SubThread *isysCreateSubThreadS(s32 entry, s32 parent, s32 size)
{
    SubThread *t = _isysCreateObj(parent, 3, 0x40, size + 0x10, isysDeleteSubThread, 4);
    SubThreadEnv *e;
    void *stack;
    s32 r;

    if (t == NULL)
    {
        return NULL;
    }
    e = SUBTHREAD_ENV(t);
    stack = iosMallocAlign(*(s32 *)t, size, 0x10);
    e->unkC = (s32)stack;
    r = -1;
    if (stack != NULL)
    {
        e->unk14 = size;
        e->unk0 = entry;
        e->unk18 = 1;
        e->unk4 = entry;
        e->unk10 = (s32)stack + size;
        isysAddGroupWithLinkParam(t, subThreadGroup, 0, 0);
        r = 0;
    }
    return r == 0 ? t : NULL;
}

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

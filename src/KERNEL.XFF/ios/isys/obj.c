#include "common.h"
#include "ios/isys/obj.h"
#include "ios/memory.h"





INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysDeleteObjManager);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", func_4002AF90);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", func_4002B218);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysAddGroupWithLinkParam);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysAddGroupRelativeWithLinkParam);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", _isysDeleteGroup);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysDeleteGroupWithLinkParam);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysDeleteGroupAllObj);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysDeleteAllGroup);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysGroupForFirst);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysGroupForFirstForce);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysGroupGetObjNumForce);

typedef struct isysLink {
    isysObj* obj;
    s32 unk4;
    s32 unk8;
    u8 unkC;
    u8 unkD;
    u16 next;
    s32 unk10;
    s32 unk14;
} isysLink;

extern isysLink D_4009ACC0[];
extern isysLink* D_400F2B00;
extern s32 D_400F2B0C;
extern s32 D_40045C5C;
extern s32 D_40045C60;
extern s32 D_40045B30[];

s32 GetThreadId(void);
s32 WaitSema(s32);
s32 SignalSema(s32);
isysLink* isysAddGroupWithLinkParam();

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", _isysCreateObj);
isysObj* _isysCreateObj(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    s32 part;
    isysObj* obj;
    register void* ra asm("ra");
    void* tmp;

    tmp = ra;
    part = iosCreatePartitionWithPc(arg0, arg2 + arg3 + sizeof(isysObj) + 8, tmp);
    if (part != 0)
    {
        obj = iosMallocAlign(part, arg2, arg5);
        if (obj != NULL)
        {
            obj->partition = part;
            obj->sourceFunc = tmp;
            *(u8*)&obj->flags = arg1;
            *(u8*)(((s32)&obj->flags)+1) = 0;
            obj->flags = *(u16*)&obj->flags;
            obj->unk14 = arg4;
            obj->unkC = obj->unkE = 0;
            obj->immediateDeleteFunc = NULL;
        }
        return obj;
    }
    return NULL;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysSetObjImmediateDeleteFunc);
void isysSetObjImmediateDeleteFunc(isysObj* obj, void* func)
{
    obj->immediateDeleteFunc = func;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysRequestDeleteObj);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysInitGroup);
void isysInitGroup(u16* group)
{
    group[1] = 0;
    group[0] = 0;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysAddGroupWithLinkParamNoWait);
isysLink* isysAddGroupWithLinkParamNoWait(s32 a0, s32 a1, s32 a2, s32 a3)
{
    return isysAddGroupWithLinkParam(a0, a1, a2, a3);
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysObjDeleteLock);
void isysObjDeleteLock(isysObj* obj)
{
    u32 v = obj->flags;
    obj->flags = (v & 0x1FFFF) | ((v >> 17) + 1) << 17;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysObjDeleteUnLock);
void isysObjDeleteUnLock(isysObj* obj)
{
    u32 v = obj->flags;
    obj->flags = (v & 0x1FFFF) | ((v >> 17) - 1) << 17;
}


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysGroupForNext);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysGroupForNextForce);


INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysGroupForExit);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysInitObjSystem);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysGetLinkNum);
s32 isysGetLinkNum(void)
{
    s32 n = 0;
    isysLink* link = D_400F2B00;

    if (link != NULL)
    {
        do
        {
            n++;
            link = link->next ? &D_4009ACC0[link->next] : NULL;
        } while (link != NULL);
    }
    return 0x3A98 - n;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysGetLinkMax);
s32 isysGetLinkMax(void)
{
    return 0x3A98;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysGetObjIdentifierByObj);
s32 isysGetObjIdentifierByObj(u8* obj)
{
    s32 t = obj[8];
    return (t < 0x25) ? D_40045B30[t] : D_40045B30[0];
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysGetGroupSrhNext);
isysLink* isysGetGroupSrhNext(isysLink* link)
{
    if (link->next != 0)
    {
        return &D_4009ACC0[link->next];
    }
    return NULL;
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysObjWaitSema);
void isysObjWaitSema(void)
{
    s32 tid = GetThreadId();

    if (tid == D_40045C5C)
    {
        D_40045C60++;
    }
    else
    {
        WaitSema(D_400F2B0C);
        D_40045C5C = tid;
        D_40045C60 = 1;
    }
}


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysObjSignalSema);
void isysObjSignalSema(void)
{
    if (--D_40045C60 == 0)
    {
        D_40045C5C = -1;
        SignalSema(D_400F2B0C);
    }
}


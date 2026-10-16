#include "common.h"
#include "ios/isys/obj.h"
#include "ios/memory.h"

typedef struct isysLink {
    isysObj* obj;
    u16* group;
    s32 unk8;
    u8 unkC;
    u8 unkD;
    u16 next;
    u16 prev;
    u16 objPrev;
    u16 objNext;
    u16 pend;
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

extern isysLink* D_400F2B04;
extern isysObj* D_400F2B08;
extern char D_40048998[];
void* memset(void*, s32, u32);
s32 iosCreateSema(s32, s32, s32);
void iosJumpRecoverPoint();

#define LINK_AT(i) ((i) ? &D_4009ACC0[i] : NULL)
#define LINK_IDX(p) ((p) ? (p) - D_4009ACC0 : 0)

static inline void isysLock(void)
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

static inline void isysUnlock(void)
{
    if (--D_40045C60 == 0)
    {
        D_40045C5C = -1;
        SignalSema(D_400F2B0C);
    }
}

static inline void isysLinkReserve(isysLink* link)
{
    if (link->unkC != 1)
    {
        link->unkC = 1;
        link->pend = LINK_IDX(D_400F2B04);
        D_400F2B04 = link;
    }
}






INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysDeleteObjManager);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", func_4002AF90);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", func_4002B218);
void func_4002B218(isysLink* link)
{
    u16* group = link->group;
    isysObj* obj = link->obj;

    if (link->next)
    {
        D_4009ACC0[link->next].prev = link->prev;
    }
    else if (group != NULL)
    {
        group[1] = link->prev;
    }
    if (link->prev)
    {
        D_4009ACC0[link->prev].next = link->next;
    }
    else if (group != NULL)
    {
        group[0] = link->next;
    }
    if (link->objPrev)
    {
        D_4009ACC0[link->objPrev].objNext = link->objNext;
    }
    else
    {
        obj->unkE = link->objNext;
    }
    if (link->objNext)
    {
        D_4009ACC0[link->objNext].objPrev = link->objPrev;
    }
    else
    {
        obj->unkC = link->objPrev;
    }
    link->obj = NULL;
    link->unkC = 0;
    link->next = LINK_IDX(D_400F2B00);
    D_400F2B00 = link;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysAddGroupWithLinkParam);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysAddGroupRelativeWithLinkParam);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", _isysDeleteGroup);
void _isysDeleteGroup(isysObj* obj, u16* group, s32 flag)
{
    isysLink* link;

    isysLock();
    link = LINK_AT(obj->unkC);
    if (link != NULL)
    {
        do
        {
            if (link->group == group)
            {
                goto found;
            }
            link = LINK_AT(link->objPrev);
        } while (link != NULL);
    }
    if (flag != 0)
    {
        goto done;
    }
    iosJumpRecoverPoint("isysobj: isysDeleteGroup group not include obj .\n");
found:
    isysLinkReserve(link);
done:
    isysUnlock();
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysDeleteGroupWithLinkParam);
void isysDeleteGroupWithLinkParam(isysObj* obj, u16* group, s32 a2, s32 flag)
{
    isysLink* link;

    isysLock();
    link = LINK_AT(obj->unkC);
    if (link != NULL)
    {
        do
        {
            if (link->group == group && link->unk8 != 0)
            {
                goto found;
            }
            link = LINK_AT(link->objPrev);
        } while (link != NULL);
    }
    if (flag != 0)
    {
        goto done;
    }
    iosJumpRecoverPoint("isysobj: isysDeleteGroup group not include obj .\n");
found:
    isysLinkReserve(link);
done:
    isysUnlock();
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysDeleteGroupAllObj);
void isysDeleteGroupAllObj(u16* group)
{
    isysLink* link;

    isysLock();
    link = LINK_AT(group[0]);
    for (; link != NULL; link = LINK_AT(link->next))
    {
        isysLinkReserve(link);
        link->group = NULL;
    }
    group[1] = 0;
    group[0] = 0;
    isysUnlock();
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysDeleteAllGroup);
void isysDeleteAllGroup(isysObj* obj, s32 (*func)(s32))
{
    isysLink* link;

    isysLock();
    link = LINK_AT(obj->unkC);
    for (; link != NULL; link = LINK_AT(link->objPrev))
    {
        if (func == NULL || func(link->unk8) != 0)
        {
            isysLinkReserve(link);
        }
    }
    isysUnlock();
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysGroupForFirst);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysGroupForFirstForce);
isysLink* isysGroupForFirstForce(u16* group)
{
    isysLink* link;

    isysLock();
    link = LINK_AT(group[0]);
    if (link != NULL)
    {
        ((u8*)link->obj)[9]++;
    }
    isysUnlock();
    return link;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysGroupGetObjNumForce);
s32 isysGroupGetObjNumForce(u16* group)
{
    isysLink* link;
    s32 n;

    isysLock();
    link = LINK_AT(group[0]);
    n = 0;
    if (link != NULL)
    {
        do
        {
            link = LINK_AT(link->next);
            n++;
        } while (link != NULL);
    }
    isysUnlock();
    return n;
}

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


//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysGroupForExit);
void isysGroupForExit(isysObj* obj)
{
    isysLock();
    ((u8*)obj)[9]--;
    isysUnlock();
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/obj", isysInitObjSystem);
void isysInitObjSystem(void)
{
    s32 i;

    D_400F2B08 = NULL;
    D_400F2B04 = NULL;
    memset(D_4009ACC0, 0, 0x57E40);
    for (i = 0; i < 0x3A97; i++)
    {
        D_4009ACC0[i].next = LINK_IDX(&D_4009ACC0[i + 1]);
    }
    D_400F2B00 = &D_4009ACC0[1];
    D_400F2B0C = iosCreateSema(1, 1, 0);
}

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


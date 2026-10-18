#include "common.h"

static inline u8 *chrClass(u8 *obj)
{
    switch (obj[8])
    {
        case 9:
            return obj + 0x90;
        case 0x16:
            return obj + 0x90;
        default:
            return NULL;
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", ResetCharacterClassIKNodeInterpInfo);
void ResetCharacterClassIKNodeInterpInfo(u8 *obj)
{
    s32 i;
    s32 n;
    u8 *p;

    p = *(u8 **)(obj + 0x354);
    if (p != NULL)
    {
        n = *(s32 *)(p + 4);
        for (i = 0; i < n; i++)
        {
            *(s32 *)(*(s32 *)(obj + 0x31C) + i * 4) = 0;
            *(s32 *)(*(s32 *)(obj + 0x320) + i * 4) = 0;
        }
    }
}

u8 *GetScriptCharacterClass();

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", func_400597E0);
void func_400597E0(u8 *obj)
{
    u8 *cc = GetScriptCharacterClass();

    if (cc != NULL)
    {
        void (*fn)(u8 *) = *(void (**)(u8 *))(cc + 0x1148);

        if (fn != NULL)
        {
            fn(obj);
        }
    }
}

s32 GetOptionNodePhysicalNodeId();

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", getoptnodephysicalnodeid);
s32 getoptnodephysicalnodeid(s32 a, s32 b, s32 c, s32 d)
{
    s32 ret = -1;

    if (c != 0)
    {
        s32 q = c + 0x50;

        if (q != 0)
        {
            ret = GetOptionNodePhysicalNodeId(b, q, d);
        }
    }
    return ret;
}

extern void GetMotionMatrix(s32, s32, s32, s32, u8 *, u8 *);

void GetCharacterClassNodeMatQuaternionPos(s32 *out0, s32 *out1, s32 *out2, u8 *obj, s32 idx, s32 flag)
{
    if (flag != 0)
    {
        *out1 = *(s32 *)(obj + 0x154) + idx * 0x10;
        *out2 = *(s32 *)(obj + 0x158) + idx * 0x40 + 0x30;
    }
    else
    {
        if (*(s8 *)(obj + 0x523) == 0)
        {
            GetMotionMatrix(*(s32 *)(obj + 0x340), *(s32 *)(obj + 0x344), *(s32 *)(obj + 0x354), *(s32 *)(obj + 0x33C), obj + 0x40, obj + 0x90);
            *(u8 *)(obj + 0x523) = 1;
        }
        *out1 = *(s32 *)(obj + 0x344) + idx * 0x10;
        *out2 = *(s32 *)(obj + 0x340) + idx * 0x40 + 0x30;
    }
    if (flag != 0)
    {
        *out0 = *(s32 *)(obj + 0x158) + idx * 0x40;
    }
    else
    {
        *out0 = *(s32 *)(obj + 0x340) + idx * 0x40;
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", EnableCharacterObjAdditionMotion);
void EnableCharacterObjAdditionMotion(u8 *obj)
{
    u8 *cc = chrClass(obj);

    cc[0x51E] = 1;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", DisableCharacterObjAdditionMotion);
void DisableCharacterObjAdditionMotion(u8 *obj)
{
    u8 *cc = chrClass(obj);

    cc[0x51E] = 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", DisableCharacterObjAddParentVelocity);
void DisableCharacterObjAddParentVelocity(u8 *obj)
{
    u8 *cc = chrClass(obj);

    cc[0xA18] = 1;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", EnableCharacterObjAddParentVelocity);
void EnableCharacterObjAddParentVelocity(u8 *obj)
{
    u8 *cc = chrClass(obj);

    cc[0xA18] = 0;
}

s32 isysGroupForFirst();
s32 isysGroupForNext();
void isysRequestDeleteObj();
void isysGroupForExit();
void isysDeleteGroupAllObj();

void ReleaseCharacterClassAddMotSyncAnimAll(u8 *obj)
{
    u8 *cc = chrClass(obj);
    s32 i;
    s32 grp;
    s32 node;
    s32 item;

    for (i = 0; i < *(s32 *)(cc + 0x3EC); i++)
    {
        grp = i * 0x80 + *(s32 *)(cc + 0x308);
        item = 0;
        for (node = isysGroupForFirst(grp, 0); node != 0; node = isysGroupForNext(node, 0))
        {
            item = *(s32 *)node;
            isysRequestDeleteObj(item);
        }
        if (item != 0)
        {
            isysGroupForExit(item, 0);
        }
        isysDeleteGroupAllObj(grp);
    }
}

void func_40059AE8(u8 *obj)
{
    u8 *cc = chrClass(obj);

    if (*(s32 *)(cc + 0xC70) != 0)
    {
        DeleteTwoWayLink(cc + 0xC80);
        cc[0xD00] = 0;
        *(s32 *)(cc + 0xC70) = 0;
        cc[0xD01] = 0;
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", AddCharacterClassOptionNodeSubGeometry);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", func_40059DE0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", func_4005A1B8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", func_4005A4D0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", func_4005A718);

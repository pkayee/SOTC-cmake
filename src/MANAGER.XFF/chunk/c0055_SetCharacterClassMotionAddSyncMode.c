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

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0055_SetCharacterClassMotionAddSyncMode", SetCharacterClassMotionAddSyncMode);
extern u128 IdentityQuaternion;
extern u128 ZeroVector;
void DeleteTwoWayLink();
int AddTwoWayLinkNext();

void SetCharacterClassMotionAddSyncMode(u8 *self, u8 *obj)
{
    s32 n;
    s32 i;
    u128 *q;
    u8 *dst;
    u8 *cc;

    if (*(s32 *)(self + 0xC70) != 0)
    {
        DeleteTwoWayLink(self + 0xC80);
        *(u8 *)(self + 0xD00) = 0;
        *(s32 *)(self + 0xC70) = 0;
        *(u8 *)(self + 0xD01) = 0;
    }
    AddTwoWayLinkNext(chrClass(obj) + 0xC74, self + 0xC80);
    *(u8 *)(self + 0xD00) = 2;
    *(s32 *)(self + 0xC70) = (s32)obj;
    if (obj != NULL)
    {
        cc = chrClass(obj);
        *(u8 *)(self + 0xD01) = cc[0xFD0];
    }
    else
    {
        *(u8 *)(self + 0xD01) = 0;
    }
    *(s32 *)(self + 0x728) = 0;
    q = &IdentityQuaternion;
    n = *(s32 *)(*(s32 *)(self + 0x354) + 4);
    dst = (u8 *)*(s32 *)(self + 0x314);
    for (i = 0; i < n; i++)
    {
        *(u128 *)dst = *q;
        dst += 0x10;
    }
    *(u128 *)(self + 0xCD0) = ZeroVector;
    *(u128 *)(self + 0xCE0) = ZeroVector;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0055_SetCharacterClassMotionAddSyncMode", func_40052C68);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0055_SetCharacterClassMotionAddSyncMode", func_40052E60);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0055_SetCharacterClassMotionAddSyncMode", func_40053088);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0055_SetCharacterClassMotionAddSyncMode", func_40053270);

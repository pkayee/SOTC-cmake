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

/* NEARMISS-STUB SetCharacterClassMotionAddSyncMode */
#if 0 /* NEARMISS 91.3% cat=regalloc sub=- | first select if-chain movn with preloaded v1; loop local order | attempts=1 */
void DeleteTwoWayLink();
void AddTwoWayLinkNext();

void SetCharacterClassMotionAddSyncMode(u8 *self, u8 *obj)
{
    s32 n;
    u8 *dst;
    u8 *cc;

    if (*(s32 *)(self + 0xC70) != 0)
    {
        DeleteTwoWayLink(self + 0xC80);
        *(u8 *)(self + 0xD00) = 0;
        *(s32 *)(self + 0xC70) = 0;
        *(u8 *)(self + 0xD01) = 0;
    }
    cc = chrClass(obj);
    AddTwoWayLinkNext(cc + 0xC74, self + 0xC80);
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
    n = *(s32 *)(*(s32 *)(self + 0x354) + 4);
    dst = (u8 *)*(s32 *)(self + 0x314);
    if (n > 0)
    {
        do
        {
            n--;
            *(u128 *)dst = IdentityQuaternion;
            dst += 0x10;
        } while (n != 0);
    }
    *(u128 *)(self + 0xCD0) = ZeroVector;
    *(u128 *)(self + 0xCE0) = ZeroVector;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0055_SetCharacterClassMotionAddSyncMode", SetCharacterClassMotionAddSyncMode);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0055_SetCharacterClassMotionAddSyncMode", func_40052C68);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0055_SetCharacterClassMotionAddSyncMode", func_40052E60);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0055_SetCharacterClassMotionAddSyncMode", func_40053088);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0055_SetCharacterClassMotionAddSyncMode", func_40053270);

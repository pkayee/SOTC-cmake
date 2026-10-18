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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", ResetCharacterClassIKNodeInterpInfo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", func_400597E0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", getoptnodephysicalnodeid);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", GetCharacterClassNodeMatQuaternionPos);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", ReleaseCharacterClassAddMotSyncAnimAll);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", func_40059AE8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", AddCharacterClassOptionNodeSubGeometry);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", func_40059DE0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", func_4005A1B8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", func_4005A4D0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0062_ResetCharacterClassIKNodeInterpInfo", func_4005A718);

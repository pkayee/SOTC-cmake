#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0129_nico_SmallBatStart", nico_SmallBatStart);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0129_nico_SmallBatStart", func_400AD768);
void iosFree();
void func_400AD768(u8 *a0, u8 *a1)
{
    s32 temp_v0;

    if (a1 != NULL) {
        temp_v0 = *(s32 *)(a1 + 0x278);
        if (temp_v0 != 0) {
            iosFree(temp_v0);
        }
    }
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0129_nico_SmallBatStart", BatInitFunc);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0129_nico_SmallBatStart", func_400AD8A0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0129_nico_SmallBatStart", func_400AD9E8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0129_nico_SmallBatStart", func_400ADC78);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0129_nico_SmallBatStart", func_400ADE28);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0129_nico_SmallBatStart", func_400ADF98);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0129_nico_SmallBatStart", func_400AE0F8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0129_nico_SmallBatStart", func_400AE370);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0129_nico_SmallBatStart", func_400AE4B8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0129_nico_SmallBatStart", func_400AE810);

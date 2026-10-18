#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E0058);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E03A8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E0698);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", createSheetMenu);

void cursorLockParamMenu(void *arg0, int arg1) {
    void *temp_a0;
    void *temp_a1;

    if (arg0 != NULL) {
        temp_a0 = (*(void **)((char *)(arg0) + 0x2C));
        if (temp_a0 != NULL) {
            temp_a1 = (*(void **)((char *)(temp_a0) + 4));
            (*(long *)((char *)(temp_a1) + 0x1B8)) = (long) (((*(long *)((char *)(temp_a1) + 0x1B8)) & ~0x80) | ((arg1 & 1) << 7));
        }
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", createYesNoDialog);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", createStringInputDialog);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E0DB8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E0E10);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E0F80);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E0FC0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E1058);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E1090);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E10E8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E1128);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E1150);

void func_400E1218(void) {
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E1220);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E12A0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E1398);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E13A8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E1450);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E1550);

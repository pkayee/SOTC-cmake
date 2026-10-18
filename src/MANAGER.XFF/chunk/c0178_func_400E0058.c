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

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E0DB8);

void *func_400E0DB8(s32 ptn) {
    struct Vec12 {
        s32 x;
        s32 y;
        s32 z;
    } tmp;
    void *p;

    p = iosMallocAlign(ptn, 0xc, 4);
    memset(&tmp, 0, 0xc);
    *(struct Vec12 *)p = tmp;
    return p;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E0E10);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E0F80);

void func_400E0F80(void *arg0, void *arg1) {
    void *temp_s0;
    void (*temp_v0)(void *, void *);

    temp_s0 = *(void **)((char *)arg1 + 0x3E0);
    *(s32 *)((char *)temp_s0 + 0x20) = 0;
    temp_v0 = *(void (**)(void *, void *))((char *)temp_s0 + 0x14);
    if (temp_v0 != NULL) {
        temp_v0(arg1, temp_s0);
    }
    *(s32 *)((char *)temp_s0 + 0x28) = 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E0FC0);

void func_400E1058(void *arg0, void *arg1) {
    void (*temp_v0)(void);

    temp_v0 = *(void (**)(void))((char *)arg1 + 0x18);
    if (temp_v0 != NULL) {
        temp_v0();
    }
    iosFree(*(void **)((char *)arg1 + 0xc));
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E1090);

void *func_400E1090(s32 ptn) {
    struct Vec12 {
        s32 x;
        s32 y;
        s32 z;
    } tmp;
    void *p;

    p = iosMallocAlign(ptn, 0xc, 4);
    memset(&tmp, 0, 0xc);
    *(struct Vec12 *)p = tmp;
    return p;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E10E8);

void func_400E10E8(void *arg0, void *arg1) {
    void *temp_s0;
    void (*temp_v0)(void *, void *);

    temp_s0 = *(void **)((char *)arg1 + 0x3E0);
    temp_v0 = *(void (**)(void *, void *))((char *)temp_s0 + 0xC);
    if (temp_v0 != NULL) {
        temp_v0(arg1, temp_s0);
    }
    *(s32 *)((char *)temp_s0 + 0x30) = 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E1128);

extern void *iosMallocAlign(void *, s32, s32);

void func_400E1128(void *arg0) {
    u8 *temp_v0;

    temp_v0 = iosMallocAlign(arg0, 0x100, 4);
    *temp_v0 = 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E1150);

void func_400E1218(void) {
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E1220);

extern s32 D_4012DB50;
extern s32 D_4012DB54;
extern u8 padManagerData[];
void windowCloseRequest();

void func_400E1220(void *arg0, void *arg1) {
    s32 *flag;

    if ((*(s32 *)((char *)arg1 + 0x1C4) & 0x40040) != 0) {
        windowCloseRequest(arg1);
        flag = &D_4012DB54;
        D_4012DB50 = 1;
        *flag = 0;
    } else {
        if (*(s32 *)(padManagerData + 8) & 0xA000) {
            D_4012DB50 = 1;
            D_4012DB54 = D_4012DB54 == 0;
        }
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E12A0);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E1398);

void func_400E1398(void *arg0, void *arg1) {
    void *temp_v0;

    temp_v0 = *(void **)((char *)arg1 + 0x3E0);
    *(s32 *)((char *)temp_v0 + 0x24) = 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E13A8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0178_func_400E0058", func_400E1450);

extern void iosFree(void *);

void func_400E1550(void *arg0, void *arg1) {
    void *temp_v0;
    void *temp_a0;

    temp_v0 = *(void **)((char *)arg1 + 0x3E0);
    temp_a0 = *(void **)((char *)temp_v0 + 0x14);
    if (temp_a0 != NULL) {
        iosFree(temp_a0);
    }
}

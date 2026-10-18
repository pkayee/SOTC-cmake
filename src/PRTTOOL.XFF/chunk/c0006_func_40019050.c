#include "common.h"

extern s32 D_40019360;
extern u8 D_4001C758[];
void func_400108F8(void);
void createMenu(u8 *menu, s32 arg);

//INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0006_func_40019050", func_40019050);
extern u8 D_4001C400[];
extern u8 D_4001C470[];
void func_40019338(void);
void createParamMenu(u8 *menu, s32 arg);
void cursorLockParamMenu(u8 *menu, s32 arg);

void func_40019050(void)
{
    u8 *menu;

    menu = D_4001C400;
    if (*(s32 *)(menu + 0x30) != 0)
    {
        return;
    }
    func_40019338();
    createParamMenu(menu, 0);
    cursorLockParamMenu(menu, 1);
}

//INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0006_func_40019050", func_400190B0);
extern u8 D_4001C438[];

void func_400190B0(void)
{
    u8 *menu;

    menu = D_4001C438;
    if (*(s32 *)(menu + 0x30) != 0)
    {
        return;
    }
    func_40019338();
    createParamMenu(menu, 0);
    cursorLockParamMenu(menu, 1);
}

//INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0006_func_40019050", func_40019110);
void func_40019110(void)
{
    u8 *menu;

    menu = D_4001C470;
    if (*(s32 *)(menu + 0x30) != 0)
    {
        return;
    }
    func_40019338();
    createParamMenu(menu, 0);
    cursorLockParamMenu(menu, 1);
}

//INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0006_func_40019050", func_40019170);
extern u8 D_4001C4A8[];

void func_40019170(void)
{
    u8 *menu;

    menu = D_4001C4A8;
    if (*(s32 *)(menu + 0x30) != 0)
    {
        return;
    }
    func_40019338();
    createParamMenu(menu, 0);
    cursorLockParamMenu(menu, 1);
}

//INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0006_func_40019050", func_400191D0);
extern u8 D_4001C4E0[];

void func_400191D0(void)
{
    u8 *menu;

    menu = D_4001C4E0;
    if (*(s32 *)(menu + 0x30) != 0)
    {
        return;
    }
    func_40019338();
    createParamMenu(menu, 0);
    cursorLockParamMenu(menu, 1);
}

INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0006_func_40019050", func_40019230);

//INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0006_func_40019050", create_particle_menu);
void *create_particle_menu(void)
{
    D_40019360 = 1;
    func_400108F8();
    createMenu(D_4001C758, 0);
    return D_4001C758 + 0x20;
}

//INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0006_func_40019050", func_40019328);
extern f32 D_4001948C;

void func_40019328(f32 value)
{
    D_4001948C = value;
}

//INCLUDE_ASM("asm/PRTTOOL.XFF/nonmatchings/chunk/c0006_func_40019050", func_40019338);
void func_40019338(void)
{
    u8 *obj;

    if (*(u32 *)D_4001C758 != 0)
    {
        obj = *(u8 **)(*(u32 *)D_4001C758 + 4);
        *(u64 *)(obj + 0x1b8) &= 0xffffffffffffffdfUL;
    }
}

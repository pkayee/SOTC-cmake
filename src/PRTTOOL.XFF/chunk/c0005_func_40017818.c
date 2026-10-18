#include "common.h"

extern int D_400193C4;
extern int D_400193D0;
extern char D_4002B910[];
extern char D_4002BF08[];

/* PRTTOOL c0005: tail call, void wrapper with arg (T28 idiom: sd/ld ra frame + j, no trailing return). */
extern s32 D_400196E4;
extern void setPtclTranceMode(s32 mode);

/* PRTTOOL c0005: if (D_4001C758 != 0) set bit 0x20 in the u64 flags (+0x1B8) of the object at D_4001C758->+4. */
extern u8 *D_4001C758;

/* PRTTOOL c0005: open the param menu at D_4001C358 once (menu+0x30 == 0): same shape as c0006 func_40019050. */
extern u8 D_4001C358[];
void func_40019338(void);
void createParamMenu(u8 *menu, s32 arg);
void cursorLockParamMenu(u8 *menu, s32 arg);

/* PRTTOOL c0005: open the param menu at D_4001C390 once (menu+0x30 == 0): same shape as c0006 func_40019050. */
extern u8 D_4001C390[];

/* PRTTOOL c0005: open the param menu at D_4001C3C8 once (menu+0x30 == 0): same shape as c0006 func_40019050. */
extern u8 D_4001C3C8[];

char *func_40017818(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x268;
}

char *func_40017868(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x130;
}

char *func_400178B8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x134;
}

char *func_40017908(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x138;
}

char *func_40017958(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x13C;
}

char *func_400179A8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x140;
}

char *func_400179F8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x144;
}

char *func_40017A48(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x148;
}

char *func_40017A98(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x14C;
}

char *func_40017AE8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x150;
}

char *func_40017B38(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x154;
}

char *func_40017B88(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x158;
}

char *func_40017BD8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x15C;
}

char *func_40017C28(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x160;
}

char *func_40017C78(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x164;
}

char *func_40017CC8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x168;
}

char *func_40017D18(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x16C;
}

char *func_40017D68(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x170;
}

char *func_40017DB8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x174;
}

char *func_40017E08(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x220;
}

char *func_40017E58(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x178;
}

char *func_40017EA8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x208;
}

char *func_40017EF8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x20C;
}

char *func_40017F48(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x210;
}

char *func_40017F98(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x224;
}

char *func_40017FE8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x204;
}

char *func_40018038(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x214;
}

char *func_40018088(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x218;
}

char *func_400180D8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x21C;
}

char *func_40018128(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x17C;
}

char *func_40018178(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1F4;
}

char *func_400181C8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x180;
}

char *func_40018218(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1F8;
}

char *func_40018268(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x184;
}

char *func_400182B8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1FC;
}

char *func_40018308(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x188;
}

char *func_40018358(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x18C;
}

char *func_400183A8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x190;
}

char *func_400183F8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x194;
}

char *func_40018448(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x198;
}

char *func_40018498(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x19C;
}

char *func_400184E8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1E0;
}

char *func_40018538(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1E4;
}

char *func_40018588(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x250;
}

char *func_400185D8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x228;
}

char *func_40018628(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x22C;
}

char *func_40018678(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1A0;
}

char *func_400186C8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1A4;
}

char *func_40018718(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1A8;
}

char *func_40018768(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1AC;
}

char *func_400187B8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x26C;
}

char *func_40018808(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x270;
}

char *func_40018858(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x274;
}

char *func_400188A8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x278;
}

char *func_400188F8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1B0;
}

char *func_40018948(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1B4;
}

char *func_40018998(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1B8;
}

char *func_400189E8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1BC;
}

char *func_40018A38(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1C0;
}

char *func_40018A88(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1C4;
}

char *func_40018AD8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x234;
}

char *func_40018B28(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x238;
}

char *func_40018B78(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x23C;
}

char *func_40018BC8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x240;
}

char *func_40018C18(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x244;
}

char *func_40018C68(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1C8;
}

char *func_40018CB8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1CC;
}

char *func_40018D08(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1D0;
}

char *func_40018D58(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1D4;
}

char *func_40018DA8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1E8;
}

char *func_40018DF8(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1EC;
}

char *func_40018E48(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x1F0;
}

char *func_40018E98(void) {
    char *p;
    if (D_400193C4 == 1) {
        p = D_4002B910;
    } else {
        p = D_4002BF08;
    }
    return p + D_400193D0 * 0x1bc + 0x230;
}

void func_40018EE8(void)
{
    setPtclTranceMode(D_400196E4);
}

void func_40018F08(void)
{
    u8 *w = D_4001C758;
    if (w != 0) {
        u8 *q = *(u8 **)(w + 4);
        *(u64 *)(q + 0x1B8) |= 0x20;
    }
}

void func_40018F30(void)
{
    u8 *menu;

    menu = D_4001C358;
    if (*(s32 *)(menu + 0x30) != 0)
    {
        return;
    }
    func_40019338();
    createParamMenu(menu, 0);
    cursorLockParamMenu(menu, 1);
}

void func_40018F90(void)
{
    u8 *menu;

    menu = D_4001C390;
    if (*(s32 *)(menu + 0x30) != 0)
    {
        return;
    }
    func_40019338();
    createParamMenu(menu, 0);
    cursorLockParamMenu(menu, 1);
}

void func_40018FF0(void)
{
    u8 *menu;

    menu = D_4001C3C8;
    if (*(s32 *)(menu + 0x30) != 0)
    {
        return;
    }
    func_40019338();
    createParamMenu(menu, 0);
    cursorLockParamMenu(menu, 1);
}

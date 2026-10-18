#include "common.h"

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0183_windowDeleteControl", windowDeleteControl);

typedef struct Ctl {
    char *win;
    char pad[0xC4];
    struct Ctl *next;
} Ctl;

void iosFree(void *);

void windowDeleteControl(Ctl *c)
{
    Ctl *p = *(Ctl **)(c->win + 0x3E4);
    if (p != 0) {
        while (p->next != c) {
            p = p->next;
            if (p == 0)
                goto end;
        }
        p->next = c->next;
    }
end:
    iosFree(c);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0183_windowDeleteControl", windowInit);

typedef struct {
    int a;
    int mouse;
    char pad[0x18];
    int x20;
    int x24;
    int x28;
    int pad2C;
    int x30;
    int x34;
    int x38;
    int x3C;
} WinState;

extern WinState D_4012DFB0;
extern int D_401B2418[];
extern int usbdevMouseGetStatus(void);
void isysInitGroup(void *);

void windowInit(void)
{
    int i;

    D_4012DFB0.x20 = 0;
    D_4012DFB0.x24 = 0;
    D_4012DFB0.x28 = 0;
    D_4012DFB0.x38 = 0xFF;
    D_4012DFB0.x34 = 0xFF;
    D_4012DFB0.x30 = 0xFF;
    D_4012DFB0.x3C = 0x70;
    D_4012DFB0.mouse = usbdevMouseGetStatus();
    for (i = 0; i < 2; i++)
        isysInitGroup(&D_401B2418[i]);
}

void windowSetTex(int arg0)
{
    D_4012DFB0.a = arg0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0183_windowDeleteControl", func_400E7810);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0183_windowDeleteControl", GetWindowClass);

char *GetWindowClass(unsigned char *p)
{
    if (p[0x8] != 0xC) {
        return 0;
    }
    return (char *)p + 0x20;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0183_windowDeleteControl", CreateWindowObj);

extern int isysRequestDeleteObj();

int RequestDeleteWindowObj(int a, int b, int c, int d)
{
    return isysRequestDeleteObj(a, b, c, d);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0183_windowDeleteControl", func_400E7BE8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0183_windowDeleteControl", func_400E7C00);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0183_windowDeleteControl", func_400E7C58);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0183_windowDeleteControl", func_400E7C88);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0183_windowDeleteControl", func_400E7ED0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0183_windowDeleteControl", _adpcmOpenReq);

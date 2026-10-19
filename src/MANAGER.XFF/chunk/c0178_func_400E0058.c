#include "common.h"

typedef struct YnItems { s32 label0; s32 id0; s32 x0; s32 w0; s32 label1; s32 id1; s32 x1; s32 w1; } YnItems;
extern char D_40134678[];
extern char D_40134680[];
unsigned int strlen(const char *);
void func_400E0058(YnItems *, s32, void *, void *);

void windowSpriteMenuArrow(s32, s32, s32);

typedef struct Col32 { u64 q[4]; } Col32;
typedef struct SprRc { float v[4]; } SprRc;
extern char D_4012DAF0[];
extern char D_40134450[];
extern char D_40134470[];
void *memset(void *, int, unsigned int);
void windowSpriteNoTex(float, void *, void *, char *);
void windowFontColor(void *, void *);
void windowPrintf(float, float, void *, char *, s32);

void windowSetCursorPosOnWindow(s32, float *);
typedef struct YnCur { s32 *win; signed char kind; char pad[0x27]; float x; float y; float w; float h; } YnCur;

void windowCursorBlink(u64 *, u64 *);

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

/* builds the two-button item list (Yes label from +8 at x = -(len*7+7), No label from +0xC at x = 7, both w 0x18) on the stack and copies it (4-aligned 32-byte struct: ldl/ldr/sdl/sdr) and passes the copy pointer with n = 2 to func_400E0058 */
void createYesNoDialog(s32 *p, void *q) {
    YnItems it2;
    YnItems it;
    unsigned int n;

    it.label0 = p[2];
    it.id0 = (s32)D_40134678;
    n = strlen((char *)it.label0);
    it.x0 = -(n * 7 + 7);
    it.w1 = 0x18;
    it.w0 = 0x18;
    it.label1 = p[3];
    it.x1 = 7;
    it.id1 = (s32)D_40134680;
    it2 = it;
    func_400E0058(&it2, 2, p, q);
}

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

/* menu item draw: optional callback at +0x14, then the arrow sprite when window flag bit 2 and +0x20 are set */
void func_400E0FC0(s32 *a) {
    s32 *w = (s32 *)a[0xbc / 4];
    s32 r = a[0];
    void (*cb)(s32, s32 *, s32 *) = *(void (**)(s32, s32 *, s32 *))((char *)w + 0x14);

    if (cb != 0) {
        cb(r, a, w);
    }
    if (((int)((*(long *)(r + 0x1b8) << 30) >> 32) & 1) != 0 && w[0x20 / 4] != 0) {
        windowSpriteMenuArrow(r, (s32) * (float *)(r + 0x26c), w[1] << 4);
    }
}

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

/* dialog title/tab: no-texture sprite (colour 0x4B7FFFFF) at a rect with h 16, then the label word at +0x3E8 printed at x = width - 77 - 2 */
void func_400E1150(void *unused, char *win) {
    SprRc rc;
    Col32 col;

    memset(&rc, 0, 0x10);
    rc.v[3] = 16.0f;
    col = *(Col32 *)D_40134450;
    windowSpriteNoTex(16777215.0f, win, &rc, D_4012DAF0);
    windowFontColor(win, &col);
    windowPrintf(*(float *)(win + 0x26c) - 77.0f - 2.0f, 2.0f, win, D_40134470, *(s32 *)(win + 0x3e8));
}

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

/* yes/no cursor: moves the window cursor to the centre of the Y or N button; pos kept in a float/s32 union (T38 alias view) so lw a0 stays after the swc1 stores */
void func_400E13A8(YnCur *c) {
    union { float f[2]; s32 w[2]; } pos;

    if (D_4012DB50 != 0) {
        if (c->kind == 'Y' && D_4012DB54 != 0) {
        } else {
            if (c->kind != 'N') {
                return;
            }
            if (D_4012DB54 != 0) {
                return;
            }
        }
        pos.f[0] = c->x + c->w * 0.5f;
        pos.f[1] = c->y + c->h * 0.5f;
        windowSetCursorPosOnWindow(*(s32 *)((char *)c->win + 0x94), pos.f);
        D_4012DB50 = 0;
    }
}

/* yes/no dialog per-frame update: pick the cursor colour set (blink or plain), then on a confirm or cancel press close the window and call the Y (+0x10) or N (+0x14) callback */
void func_400E1450(s32 *a) {
    u64 *q = (u64 *)a;
    u32 fl = a[0xb4 / 4];
    s32 *d = *(s32 **)(a[0] + 0x3e0);
    void (*cb)(void);

    if (fl & 1) {
        windowCursorBlink(q + 8, q + 12);
        q[14] = q[18];
        q[15] = q[19];
        a[0xa0 / 4] = a[0xa8 / 4];
        fl = a[0xb4 / 4];
    } else {
        q[8] = q[10];
        q[9] = q[11];
        q[14] = q[16];
        q[15] = q[17];
        a[0xa0 / 4] = a[0xa4 / 4];
    }
    if (fl & 0x20020) {
        if (((signed char *)a)[4] != 'N') {
            if (((signed char *)a)[4] == 'Y') {
            windowCloseRequest(a[0]);
            cb = *(void (**)(void))((char *)d + 0x10);
            if (cb != 0) {
                cb();
            }
            }
        } else {
            windowCloseRequest(a[0]);
            cb = *(void (**)(void))((char *)d + 0x14);
            if (cb != 0) {
                cb();
            }
        }
    }
}

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

#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0182_windowCreate", windowCreate);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0182_windowCreate", windowReInit);

extern unsigned char D_4012DFF0[];

void *windowSemiTransRate(void)
{
    return D_4012DFF0;
}

extern unsigned char D_4012DFF4[];

void *windowDisplayMode(void)
{
    return D_4012DFF4;
}

void windowFontColor(void *arg0, void *arg1)
{
    (*(s64 *)((char *)(arg0) + 0x1F0)) = (s64) (*(s64 *)((char *)(arg1) + 0));
    (*(s64 *)((char *)(arg0) + 0x1F8)) = (s64) (*(s64 *)((char *)(arg1) + 8));
    (*(s64 *)((char *)(arg0) + 0x200)) = (s64) (*(s64 *)((char *)(arg1) + 0x10));
    (*(s64 *)((char *)(arg0) + 0x208)) = (s64) (*(s64 *)((char *)(arg1) + 0x18));
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0182_windowCreate", windowSpriteNoTex);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0182_windowCreate", windowSprite);

int windowCheckCursorInRect(char *window, float *rect, float *cursor)
{
    float x = rect[0];
    if (window == 0) {
        float cursorY;
        float cursorX;
        return x <= (cursorX = cursor[0]) && rect[1] <= (cursorY = cursor[1])
            && cursorX < x + rect[2] && cursorY < rect[1] + rect[3];
    }
    else {
        float y;
        float shiftedX = x + *(float *)(window + 0x198);
        return shiftedX <= cursor[0] && (y = rect[1] + *(float *)(window + 0x19C)) <= cursor[1]
            && cursor[0] < shiftedX + rect[2] && cursor[1] < y + rect[3];
    }
}

typedef int s128 __attribute__((mode(TI)));

extern s128 D_4012DFC0;

void windowGetCursorPos(s128 *out)
{
    *out = D_4012DFC0;
}

extern void mouseSetCursorPosition(float, float);

typedef union { s128 q; float f[4]; int i[4]; } Vec4;

void windowSetCursorPos(Vec4 *position)
{
    char *state = (char *)&D_4012DFC0;
    ((Vec4 *)state)->q = position->q;
    state -= 0x10;
    mouseSetCursorPosition(position->f[0], position->f[1]);
    (*(Vec4 **)(state + 4))->f[0] = position->f[0];
    (*(Vec4 **)(state + 4))->f[1] = position->f[1];
}

void windowGetCursorPosOnWindow(char *w, Vec4 *pos)
{
    char *o = *(char **)(w + 4);
    pos->q = D_4012DFC0;
    pos->f[0] -= *(float *)(o + 0x264);
    pos->f[1] -= *(float *)(o + 0x268);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0182_windowCreate", windowSetCursorPosOnWindow);

extern int D_4012DFB4;

int windowGetMouseStatus(void)
{
    return D_4012DFB4;
}

extern int D_4012DFD8;

int windowGetCurrentWindowHandle(void)
{
    return D_4012DFD8;
}

typedef struct { unsigned long pad : 3; unsigned int target : 1; unsigned long rest : 60; } WinFlags;
typedef struct Window { int a; char *obj; char pad[0x14]; struct Window *next; } Window;

Window *windowGetTargetWindowHandle(void)
{
    Window *w;
    for (w = D_4012DFD8; w != 0; w = w->next) {
        if (((WinFlags *)(w->obj + 0x1B8))->target)
            return w;
    }
    return 0;
}

typedef struct {
    int *a;
    char *d;
    int dc;
} Win;

extern void iosReleaseDC(int);

void windowDelete(Win *w)
{
    void (*f)(int, char *);
    if (w == 0)
        return;
    f = *(void (**)(int, char *))(w->d + 0x3F8);
    if (f != 0)
        f(*w->a, w->d);
    iosReleaseDC(w->dc);
}

void windowCloseRequest(char *p)
{
    if (p != 0) {
        *(int *)(p + 0x1CC) = 1;
    }
}

extern int D_401B2418[];
extern int *isysGroupForFirst(void *, int);
extern int *isysGroupForNext(int *, int);
extern void isysGroupForExit(int, int);

void windowDeleteAllObjByGroup(int grp)
{
    int o = 0;
    int *g;
    char *w;

    for (g = isysGroupForFirst(&D_401B2418[grp], 0); g != 0; g = isysGroupForNext(g, 0)) {
        o = *g;
        w = (char *)o + 0x20;
        if (w != 0)
            *(int *)(w + 0x1CC) = 1;
    }
    if (o != 0)
        isysGroupForExit(o, 0);
}

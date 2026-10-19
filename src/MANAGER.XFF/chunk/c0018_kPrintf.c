#include "common.h"

typedef __builtin_va_list va_list;
int vsprintf(char *, const char *, va_list);
typedef struct KPrintCtx {
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    f32 l;
    f32 t;
    f32 w;
    f32 h;
    f32 r;
    f32 g;
    f32 b;
    f32 a;
    s32 mode;
    s32 zero;
    s32 layer;
    f32 scale;
} KPrintCtx;
s32 iosDlGetLayer(void);
s32 getDrawScreenWidth(void);
s32 getDrawScreenHeight(void);
void func_400295B0(KPrintCtx *c, char *s, s32 (*fn)());
s32 iosGetFontIDWithEUC();
s32 iosGetFontIDWithSJIS();
void iosDlPushLayer(s32);
void iosDlPopLayer(void);
void FlushCache(s32);
void iosSyncGP(void);
s32 getDispBufferAddressTBP(void);
void iosTransTex();
void iosFree(void *);
s32 *getSpriteDispFlag(void);
void iosGetFontInfo(void *info, s32 id);
s32 iosEntryLocaleFontNoLoad();
void func_4002A2D8(void);

/* REA READY MANAGER c0018 kPrintf: varargs text printer, args x y fmt then varargs (gcc2.96 va_start). Context struct 0x40 bytes built on stack, then func_400295B0.. proven 100 in scratch with swarm/bin/score. No includes needed (va_list typedef is in the prelude). */
void kPrintf(s32 x, s32 y, char *fmt, ...)
{
    extern u8 D_40129E30[];
    extern char D_401AB8C8[];
    KPrintCtx c;
    va_list args;
    u8 *g = D_40129E30;

    if (*(s32 *)g != 0) {
        c.x1 = x;
        c.y1 = y;
        c.x0 = x;
        c.y0 = y;
        c.r = *(f32 *)(g + 0x90);
        c.g = *(f32 *)(g + 0x94);
        c.b = *(f32 *)(g + 0x98);
        c.a = *(f32 *)(g + 0x9C);
        c.mode = *(s32 *)(g + 0xA0);
        c.zero = 0;
        c.layer = iosDlGetLayer();
        c.l = -getDrawScreenWidth() - 16;
        c.t = -getDrawScreenHeight() - 16;
        c.w = getDrawScreenWidth();
        c.h = getDrawScreenHeight();
        c.scale = 1.0f;
        c.layer = iosDlGetLayer();
        __builtin_stdarg_start(args, fmt);
        vsprintf(D_401AB8C8, fmt, args);
        __builtin_va_end(args);
        func_400295B0(&c, D_401AB8C8, iosGetFontIDWithEUC);
    }
}

/* REA READY MANAGER c0018 kPrintfScale: like kPrintf, extra float scale named arg (f12), stored at ctx+0x3C.. proven 100 in scratch with swarm/bin/score. No includes needed (va_list typedef is in the prelude). */
void kPrintfScale(s32 x, s32 y, char *fmt, f32 scale, ...)
{
    extern u8 D_40129E30[];
    extern char D_401AB8C8[];
    KPrintCtx c;
    va_list args;
    u8 *g = D_40129E30;

    if (*(s32 *)g != 0) {
        c.x1 = x;
        c.y1 = y;
        c.x0 = x;
        c.y0 = y;
        c.r = *(f32 *)(g + 0x90);
        c.g = *(f32 *)(g + 0x94);
        c.b = *(f32 *)(g + 0x98);
        c.a = *(f32 *)(g + 0x9C);
        c.mode = *(s32 *)(g + 0xA0);
        c.zero = 0;
        c.layer = iosDlGetLayer();
        c.l = -getDrawScreenWidth() - 16;
        c.t = -getDrawScreenHeight() - 16;
        c.w = getDrawScreenWidth();
        c.h = getDrawScreenHeight();
        c.scale = scale;
        c.layer = iosDlGetLayer();
        __builtin_stdarg_start(args, scale);
        vsprintf(D_401AB8C8, fmt, args);
        __builtin_va_end(args);
        func_400295B0(&c, D_401AB8C8, iosGetFontIDWithEUC);
    }
}

/* REA READY MANAGER c0018 kPrintfAsSprite: like kPrintf, only when *getSpriteDispFlag() is set.. proven 100 in scratch with swarm/bin/score. No includes needed (va_list typedef is in the prelude). */
void kPrintfAsSprite(s32 x, s32 y, char *fmt, ...)
{
    extern u8 D_40129E30[];
    extern char D_401AB8C8[];
    KPrintCtx c;
    va_list args;
    u8 *g = D_40129E30;

    if (*(s32 *)g != 0) {
        if (*getSpriteDispFlag() != 0) {
            c.x1 = x;
            c.y1 = y;
            c.x0 = x;
            c.y0 = y;
            c.r = *(f32 *)(g + 0x90);
            c.g = *(f32 *)(g + 0x94);
            c.b = *(f32 *)(g + 0x98);
            c.a = *(f32 *)(g + 0x9C);
            c.mode = *(s32 *)(g + 0xA0);
            c.zero = 0;
            c.layer = iosDlGetLayer();
            c.l = -getDrawScreenWidth() - 16;
            c.t = -getDrawScreenHeight() - 16;
            c.w = getDrawScreenWidth();
            c.h = getDrawScreenHeight();
            c.scale = 1.0f;
            c.layer = iosDlGetLayer();
            __builtin_stdarg_start(args, fmt);
            vsprintf(D_401AB8C8, fmt, args);
            __builtin_va_end(args);
            func_400295B0(&c, D_401AB8C8, iosGetFontIDWithEUC);
        }
    }
}

/* REA READY MANAGER c0018 kprintfSJIS: kPrintf with iosGetFontIDWithSJIS.. proven 100 in scratch with swarm/bin/score. No includes needed (va_list typedef is in the prelude). */
void kprintfSJIS(s32 x, s32 y, char *fmt, ...)
{
    extern u8 D_40129E30[];
    extern char D_401AB8C8[];
    KPrintCtx c;
    va_list args;
    u8 *g = D_40129E30;

    if (*(s32 *)g != 0) {
        c.x1 = x;
        c.y1 = y;
        c.x0 = x;
        c.y0 = y;
        c.r = *(f32 *)(g + 0x90);
        c.g = *(f32 *)(g + 0x94);
        c.b = *(f32 *)(g + 0x98);
        c.a = *(f32 *)(g + 0x9C);
        c.mode = *(s32 *)(g + 0xA0);
        c.zero = 0;
        c.layer = iosDlGetLayer();
        c.l = -getDrawScreenWidth() - 16;
        c.t = -getDrawScreenHeight() - 16;
        c.w = getDrawScreenWidth();
        c.h = getDrawScreenHeight();
        c.scale = 1.0f;
        c.layer = iosDlGetLayer();
        __builtin_stdarg_start(args, fmt);
        vsprintf(D_401AB8C8, fmt, args);
        __builtin_va_end(args);
        func_400295B0(&c, D_401AB8C8, iosGetFontIDWithSJIS);
    }
}

/* REA READY MANAGER c0018 kprintfContext: print with caller supplied KPrintCtx (layer pushed from ctx+0x38).. proven 100 in scratch with swarm/bin/score. No includes needed (va_list typedef is in the prelude). */
void kprintfContext(KPrintCtx *c, char *fmt, ...)
{
    extern char D_401AB8C8[];
    extern u8 D_40129E30[];
    va_list args;

    if (*(s32 *)D_40129E30 != 0) {
        iosDlPushLayer(c->layer);
        __builtin_stdarg_start(args, fmt);
        vsprintf(D_401AB8C8, fmt, args);
        __builtin_va_end(args);
        func_400295B0(c, D_401AB8C8, iosGetFontIDWithEUC);
        iosDlPopLayer();
    }
}

/* REA READY MANAGER c0018 kprintfContextCentering: as kprintfContext, shifts ctx x0 by half the text width (font info words 4 and 6).. proven 100 in scratch with swarm/bin/score. No includes needed (va_list typedef is in the prelude). */
void kprintfContextCentering(KPrintCtx *c, char *fmt, ...)
{
    extern char D_401AB8C8[];
    extern u8 D_40129E30[];
    s32 info[8];
    s32 *ip = info;
    va_list args;
    char *p;
    s32 n;
    s32 ch;

    if (*(s32 *)D_40129E30 != 0) {
        iosDlPushLayer(c->layer);
        __builtin_stdarg_start(args, fmt);
        vsprintf(D_401AB8C8, fmt, args);
        __builtin_va_end(args);
        iosGetFontInfo(ip, *(s32 *)(D_40129E30 + 4));
        p = D_401AB8C8;
        n = 0;
        while ((ch = *p++) != 0 && ch != '\n')
            n++;
        c->x0 = c->x1 - (f32)(n * ((ip[4] * 2 - ip[6]) >> 1)) * 0.5f;
        func_400295B0(c, D_401AB8C8, iosGetFontIDWithEUC);
        iosDlPopLayer();
    }
}

/* REA READY MANAGER c0018 kprintfContextSJIS: kprintfContext with iosGetFontIDWithSJIS.. proven 100 in scratch with swarm/bin/score. No includes needed (va_list typedef is in the prelude). */
void kprintfContextSJIS(KPrintCtx *c, char *fmt, ...)
{
    extern char D_401AB8C8[];
    extern u8 D_40129E30[];
    va_list args;

    if (*(s32 *)D_40129E30 != 0) {
        iosDlPushLayer(c->layer);
        __builtin_stdarg_start(args, fmt);
        vsprintf(D_401AB8C8, fmt, args);
        __builtin_va_end(args);
        func_400295B0(c, D_401AB8C8, iosGetFontIDWithSJIS);
        iosDlPopLayer();
    }
}

/* REA READY MANAGER c0018 func_4002A2D8: upload the 14 font texture pages and 2 cluts via iosTransTex, free font info buffer.. proven 100 in scratch with swarm/bin/score. No includes needed (va_list typedef is in the prelude). */
void func_4002A2D8(void)
{
    extern s32 D_40129E34;
    extern u8 D_40129E40[];
    s32 info[8];
    s32 info2[8];
    s32 i;

    iosGetFontInfo(info, D_40129E34);
    for (i = 0; i < 14; i++) {
        FlushCache(0);
        iosSyncGP();
        iosTransTex(info[2] + (i << 15), getDispBufferAddressTBP() + ((i % 7) << 10), 0x100, 0x100, i / 7 ? 0x2C : 0x24);
    }
    FlushCache(0);
    iosSyncGP();
    iosTransTex(D_40129E40, 0x3FB8, 8, 2, 0);
    FlushCache(0);
    iosSyncGP();
    iosTransTex(D_40129E40 + 0x40, 0x3FB9, 8, 2, 0);
    FlushCache(0);
    iosSyncGP();
    iosGetFontInfo(info2, *(s32 *)(D_40129E40 - 0xC));
    if (info2[2] != 0) {
        iosFree((void *)info2[2]);
        info2[2] = 0;
    }
}

/* REA READY MANAGER c0018 kInit: register the kanji font, build the two 16 entry gray alpha cluts at D_40129E30+0x10 and +0x50, set colour 1.0, enable. KS block-scope struct = layout of D_40129E30.. proven 100 in scratch with swarm/bin/score. No includes needed (va_list typedef is in the prelude). */
void kInit(void)
{
    typedef struct {
        s32 enable;
        s32 font;
        s32 x8;
        s32 pad;
        u32 pal1[16];
        u32 pal2[16];
        f32 r;
        f32 g;
        f32 b;
        f32 a;
    } KS;
    extern KS D_40129E30;
    extern s32 D_40129F80;
    extern u8 D_40130540[];
    extern f32 D_40130658[];
    extern f32 D_40130698[];
    extern f32 D_401306D8[];
    s32 info[8];
    s32 i;
    info[4] = *(s32 *)(D_40130540 + 0);
    info[5] = *(s32 *)(D_40130540 + 4);
    info[6] = *(s32 *)(D_40130540 + 8);
    info[7] = *(s32 *)(D_40130540 + 12);
    D_40129E30.font = 0;
    info[2] = iosEntryLocaleFontNoLoad(D_40129F80, info);
    for (i = 0; i < 16; i++) {
        u32 x = (u32)(D_401306D8[i] * 255.0f) << 24 | (u32)(D_40130658[i] * 255.0f);
        u32 y = (u32)(D_40130658[i] * 255.0f) << 8 | (u32)(D_40130658[i] * 255.0f) << 16;
        D_40129E30.pal1[i] = x | y;
    }
    for (i = 0; i < 16; i++) {
        u32 x = (u32)(D_401306D8[i] * 255.0f) << 24 | (u32)(D_40130698[i] * 255.0f);
        u32 y = (u32)(D_40130698[i] * 255.0f) << 8 | (u32)(D_40130698[i] * 255.0f) << 16;
        D_40129E30.pal2[i] = x | y;
    }
    D_40129E30.x8 = 0;
    D_40129E30.a = 1.0f;
    D_40129E30.b = 1.0f;
    D_40129E30.g = 1.0f;
    D_40129E30.r = 1.0f;
    func_4002A2D8();
    D_40129E30.enable = 1;
}

extern s32 D_40129F80;

void kSetTex(s32 arg0)
{
    D_40129F80 = arg0;
}

typedef struct
{
    char pad0[0x90];
    f32 r;
    f32 g;
    f32 b;
    f32 a;
    s32 mode;
} KColorState;

extern KColorState D_40129E30;

void kColor(s32 mode, f32 r, f32 g, f32 b, f32 a)
{
    KColorState *k = &D_40129E30;

    k->r = r;
    k->g = g;
    k->b = b;
    k->a = a;
    k->mode = mode;
}

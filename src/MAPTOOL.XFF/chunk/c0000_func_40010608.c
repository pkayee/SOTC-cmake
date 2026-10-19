#include "common.h"

extern f32 D_40014850[];
extern u32 D_4001485C;

typedef struct LoadGrp {
    s32 type;
    s32 x;
    s32 y;
    s32 a;
    s32 b;
    s32 pad14[3];
    struct LoadGrp *next;
} LoadGrp;
extern char D_40015010[];
extern char D_40015028[];
extern char D_40015038[];
extern char D_40015058[];
extern char D_40015080[];
u8 *getSeamlessStageEnv(void);
LoadGrp *GetLoadAreaGroupData(void);
s32 iosSPrintf(char *buf, char *fmt, ...);
void *csvMakeOpen(char *name);
void csvMakeDeleteSegment(void *h, char *seg);
void *csvMakeCreateNewSegment(void *h, char *seg);
void csvMakeBlockWriteData(void *seg, char *fmt, char *b0, char *b1, s32 x, s32 y, s32 a, s32 b, char *b2);
void csvMakeClose(void *h);

typedef struct {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
} LoadRect;
typedef struct {
    u8 pad00[0x14];
    s32 nrect;
    LoadRect *rect;
} LoadArea;
void *getArea(s32 x, s32 y);
s32 *getSeamlessStageHighModelDispDistDefault(void);
s32 *getSeamlessStageMiddleModelDispDistDefault(void);
void setLoadMode(s32 x, s32 y, s32 mode);
void SetSeamlessZFogDist(s32 hi, s32 mid);

extern u8 gcGlobalVar[];
extern char D_400150C0[];
void getStageChipIDReal(void *g, s32 *x, s32 *y);
void setArea(s32 x, s32 y, s32 v);
void DeleteNoUseLoadAreaGroupData(void *a);

INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0000_func_40010608", func_40010608);

s32 func_40010868(f32 x0, f32 y0, f32 x1, f32 y1, u8 *w)
{
    f32 hw;
    f32 hh;
    hw = *(f32 *)(w + 0x26C);
    if (x0 * D_40014850[D_4001485C] < -(hw * 0.5f) && x1 * D_40014850[D_4001485C] < -(hw * 0.5f)) {
        return 0;
    }
    if (x0 * D_40014850[D_4001485C] > hw - hw * 0.5f && x1 * D_40014850[D_4001485C] > hw - hw * 0.5f) {
        return 0;
    }
    hh = *(f32 *)(w + 0x270);
    if (y0 * D_40014850[D_4001485C] < -(hh * 0.5f) && y1 * D_40014850[D_4001485C] < -(hh * 0.5f)) {
        return 0;
    }
    if (y0 * D_40014850[D_4001485C] > hh - hh * 0.5f && y1 * D_40014850[D_4001485C] > hh - hh * 0.5f) {
        return 0;
    }
    return 1;
}

void func_40010998(void)
{
    char name[256];
    char buf0[256];
    char buf1[256];
    void *seg;
    u8 *env;
    LoadGrp *g;
    void *h;
    env = getSeamlessStageEnv();
    g = GetLoadAreaGroupData();
    iosSPrintf(name, D_40015010);
    h = csvMakeOpen(D_40015028);
    csvMakeDeleteSegment(h, name);
    seg = csvMakeCreateNewSegment(h, name);
    for (; g != 0; g = g->next) {
        if (g->type == 5) {
            s32 x = g->x;
            s32 y = g->y;
            s32 a = g->a;
            s32 b = g->b;
            iosSPrintf(buf0, D_40015038, x, *(s32 *)(env + 0x4C) - y - 1);
            iosSPrintf(buf1, D_40015058, x, *(s32 *)(env + 0x4C) - y - 1);
            csvMakeBlockWriteData(seg, D_40015080, buf0, buf0, x, *(s32 *)(env + 0x4C) - y - 1, a, b, buf1);
        }
    }
    csvMakeClose(h);
}

INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0000_func_40010608", func_40010B00);

INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0000_func_40010608", func_40010CB0);

void func_40010ED0(s32 x, s32 y)
{
    s32 j;
    LoadArea *a;
    LoadRect *r;
    s32 *hi;
    s32 *mid;
    s32 n;
    s32 i;
    s32 ye;
    s32 x0;
    s32 xe;
    a = (LoadArea *)getArea(x, y);
    r = a->rect;
    hi = getSeamlessStageHighModelDispDistDefault();
    mid = getSeamlessStageMiddleModelDispDistDefault();
    n = *hi + *mid + 1;
    j = y - n;
    ye = j + n * 2;
    x0 = x - n;
    xe = x0 + n * 2;
    for (; j < ye; j++) {
        for (i = x0; i < xe; i++) {
            setLoadMode(i, j, 2);
        }
    }
    for (i = 0; i < a->nrect; i++, r++) {
        for (j = r->x; j < r->x + r->w; j++) {
            setLoadMode(j, r->y, 1);
        }
    }
    SetSeamlessZFogDist(*getSeamlessStageHighModelDispDistDefault(), *getSeamlessStageMiddleModelDispDistDefault());
}

void func_40011030(void)
{
    char buf[256];
    s32 x;
    s32 y;
    u8 *env;
    s32 *area;
    void *h;
    env = getSeamlessStageEnv();
    getStageChipIDReal(gcGlobalVar + 0x340, &x, &y);
    area = getArea(x, y);
    if (area != 0 || *area == 5) {
        iosSPrintf(buf, D_40015058, x, *(s32 *)(env + 0x4C) - y - 1);
        func_40010ED0(x, y);
        setArea(x, y, 0);
        DeleteNoUseLoadAreaGroupData(area);
        func_40010998();
        h = csvMakeOpen(D_400150C0);
        csvMakeDeleteSegment(h, buf);
        csvMakeClose(h);
    }
}

INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0000_func_40010608", func_40011110);

INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0000_func_40010608", func_400113F8);

INCLUDE_ASM("asm/MAPTOOL.XFF/nonmatchings/chunk/c0000_func_40010608", func_400118F0);

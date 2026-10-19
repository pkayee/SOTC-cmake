#include "common.h"

void Sg2ExPcmOutputSetVol(s32 arg0, s32 arg1);
void Sg2ExPcmOutputCtrl(s32 arg0);
void createYesNoDialog(u8* arg0, s32 arg1);
void iosFree(void* arg0);
void changeVolume(s32 arg0);
extern u8 D_4012EAA0[];
extern u8* D_4012E3C8;
extern s32 rootPtn;
void *iosMallocAlign(void *, s32, s32);
void sheetFileRead(void *, void *, s32);

void *setEditWorkTool(void *a, s32 b, s32 c, s32 d);
int func_400FC890(void *p);

/* MANAGER c0205 audioDecCreate: init the audio decoder work (9 words, sema at +0x20) and hook the pcm tick proc. */
void pcm_tickprocsub();
void setPcmTickProcFunc(void *fn);
s32 iosCreateSema(s32 a, s32 b, s32 c);

void EE_MixBufClear(void);
void iosDeleteSema(s32 sema);

void createMenu(void *menu, s32 arg1);
void func_400FB9A0(s32 a0, s32 a1, s32 a2);

/* MANAGER c0205 initEtiInfoWork: once, init the two node lists at D_401C4990 and chain 20 nodes (stride 0x21C) of D_401C1F60 into the second list. */
extern u8 D_401C4990[];
extern u8 D_401C1F60[];
extern s32 D_4012E3C4;
typedef struct EtiList205 {
    s32 n;
    s32 head;
    s32 tail;
} EtiList205;
static inline void etiListInit205(EtiList205 *l) /* helper */
{
    l->n = 0;
    l->head = 0;
    l->tail = 0;
}
static inline void etiListAdd205(EtiList205 *l, u8 *node) /* helper */
{
    if (node != NULL)
    {
        if (l->tail != 0)
            *(u8 **)((u8 *)l->tail + 0x8) = node;
        else
            l->head = (s32)node;
        *(u8 **)(node + 0x8) = NULL;
        l->n++;
        l->tail = (s32)node;
    }
}
typedef struct EtiWork205 {
    EtiList205 free;
    EtiList205 used;
    s32 f18;
} EtiWork205;

/* MANAGER c0205 spriteMovieImage: fullscreen textured sprite for the movie image, GS regs set from the draw screen size. Layout of the stack args follows the c0100 sibling. */
typedef struct SprQuad205 {
    u64 q[2];
} SprQuad205;
typedef struct SprMov205 {
    SprQuad205 col;
    SprQuad205 uv;
    s32 a[4];
} SprMov205;
extern const SprQuad205 D_401357F0;
extern const SprQuad205 D_40135800;
void iosDlPushLayer(s32 layer);
void iosDlPopLayer(void);
void gsRegBegin(void);
void gsRegEnd(void);
void gsReg(s32, u64);
s32 getDrawScreenWidth(void);
s32 getDrawScreenHeight(void);
s32 getDrawBufferAddressFBP(void);
s32 getTextureAreaAddressTBP(void);
s32 getTWH(s32 n);
void spriteTexFast(s32, s32, s32, s32, s32, void *, void *, s32);

int setStartEditWorkTool(void *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g)
{
    u8 *r = (u8 *)setEditWorkTool(a, b, c, f);

    if (r != NULL)
    {
        if (f == 0)
        {
            *(s32 *)(r + 0x20C) = d;
            *(s32 *)(r + 0x210) = e;
            *(s32 *)(r + 0x218) = g;
        }
        return func_400FC890(r);
    }
    return 0;
}

extern u8 D_4012EA68[];
extern u8 D_4012E468[];
extern u8 D_4012EA38[];
typedef struct EwtWin205 {
    s32 *win;
    u8 pad4[0x1C];
    s32 open;
} EwtWin205;
typedef struct EwtTool205 {
    u8 pad0[0x2C];
    s32 *win;
    s32 open;
} EwtTool205;
void windowCloseRequest(s32 arg0);
void unsetEditWorkTool(void *arg0);

void unsetEndEditWorkTool(void *arg0)
{
    if (((EwtTool205 *)D_4012EA68)->open != 0)
        windowCloseRequest(((EwtTool205 *)D_4012EA68)->win[1]);
    if (((EwtWin205 *)D_4012E468)->open != 0)
        windowCloseRequest(((EwtWin205 *)D_4012E468)->win[1]);
    if (((EwtWin205 *)D_4012EA38)->open != 0)
        windowCloseRequest(((EwtWin205 *)D_4012EA38)->win[1]);
    unsetEditWorkTool(arg0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", openEditWorkTool);

s32 func_400FC6C8(u32 idx, s32 off)
{
    s32 base = *(s32 *)D_4012E3C8;
    s32 *d = *(s32 **)(D_4012E3C8 + 4);
    s32 *e;
    s32 sum;
    u32 i;
    u32 n;

    if (base == 0 || d == 0)
        return 0;
    n = d[1];
    sum = base;
    for (i = 0, e = d + 8; i < n; i++, e += 6)
    {
        if (i == idx)
            return sum + off * 4;
        if (e[0] == 2)
            sum += e[1] << 4;
        else
            sum += e[1] << 2;
    }
    return 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", func_400FC750);
extern u8 D_4012E468[];
extern u8 D_4012EA38[];

void func_400FC750(void)
{
    u8 *b = D_4012E468;

    if (*(s32 *)(b + 0x20) != 0)
    {
        u8 *p = *(u8 **)b;
        u8 *q = *(u8 **)(p + 4);

        *(u64 *)(q + 0x1B8) |= 0x20;
    }
    b = D_4012EA38;
    if (*(s32 *)(b + 0x20) != 0)
    {
        u8 *p = *(u8 **)b;
        u8 *q = *(u8 **)(p + 4);

        *(u64 *)(q + 0x1B8) |= 0x20;
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", func_400FC7A8);
extern u8 *D_401C4994;
s32 chkEtiInfoWork(void);
void windowCloseRequest(s32 arg0);

void func_400FC7A8(void *a0, void *a1, s32 *a2)
{
    if (chkEtiInfoWork() != 0)
    {
        s32 i = 0;

        D_4012E3C8 = D_401C4994;
        if (a2[1] > 0)
        {
            do
            {
                i++;
                D_4012E3C8 = *(u8 **)(D_4012E3C8 + 8);
            } while (i < a2[1]);
        }
    }
    else
    {
        windowCloseRequest(*(s32 *)(*(u8 **)D_4012EA38 + 4));
    }
    return;
}

void func_400FC830(u8* arg0)
{
    createYesNoDialog(D_4012EAA0, *(s32*)(arg0 + 0x94));
}

void func_400FC850(u8* arg0)
{
    u8* temp = D_4012E3C8;
    void (*fn)(void*, void*, void*) = *(void (**)(void*, void*, void*))(temp + 0x218);

    if (fn != NULL)
    {
        fn(*(void**)temp, *(void**)(temp + 0x20C), *(void**)(*(u8**)(arg0 + 0x3E8) + 4));
    }
}

int func_400FC890(void *p)
{
    if (p == NULL)
        return 0;
    D_4012E3C8 = p;
    if (((EwtTool205 *)D_4012EA68)->open != 0)
        windowCloseRequest(((EwtTool205 *)D_4012EA68)->win[1]);
    if (((EwtWin205 *)D_4012E468)->open != 0)
        windowCloseRequest(((EwtWin205 *)D_4012E468)->win[1]);
    if (((EwtWin205 *)D_4012EA38)->open != 0)
        windowCloseRequest(((EwtWin205 *)D_4012EA38)->win[1]);
    createMenu(D_4012E468, 0);
    func_400FB9A0(((EwtWin205 *)D_4012E468)->win[1], 0, 0);
    return 1;
}

void initEtiInfoWork(void)
{
    u8 *node;
    u32 i;

    if (D_4012E3C4 == 0)
    {
        etiListInit205(&((EtiWork205 *)D_401C4990)->free);
        etiListInit205(&((EtiWork205 *)D_401C4990)->used);
        for (i = 0, node = D_401C1F60; i < 0x14; i++, node += 0x21C)
            etiListAdd205(&((EtiWork205 *)D_401C4990)->used, node);
        D_4012E3C4 = 1;
        ((EtiWork205 *)D_401C4990)->f18 = 0;
    }
}

void *loadPathData(void *f, void *b, int size)
{
    void *p = iosMallocAlign(&rootPtn, size, 16);
    sheetFileRead(f, p, size);
    return p;
}

void delPathData(void *arg0, void *arg1, void *arg2)
{
    iosFree(arg2);
    return;
}

u8* getPointDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x8);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getLineDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0xC);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

static inline u8* getConnectLinePoint(u8* t, s32 i)
{
    if (t == NULL || i < 0 || (u32)i >= *(u32*)t)
    {
        return NULL;
    }
    return t + i * 48 + 0x10;
}

u8* getConnectLineArray(u8* arg0, s32 arg1)
{
    u8* p = getConnectLinePoint(arg0, arg1);

    if (p != NULL)
    {
        if (*(s32*)(p + 0x10) != 0)
        {
            return arg0 + *(s32*)(p + 0x14);
        }
    }
    return NULL;
}

u8* getLineData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

u8* getRootDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x10);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getGoalDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x14);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getSubDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x18);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getRootPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

u8* getGoalPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

u8* getSubPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

static inline u8* getChildGoalPoint(u8* t, s32 i)
{
    if (t == NULL || i < 0 || (u32)i >= *(u32*)t)
    {
        return NULL;
    }
    return t + i * 48 + 0x10;
}

u8* getChildGoalPointIdxArray(u8* arg0, s32 arg1)
{
    u8* p = getChildGoalPoint(arg0, arg1);

    if (p != NULL)
    {
        if (*(s32*)(p + 0x14) != 0)
        {
            return arg0 + *(s32*)(p + 0x18);
        }
    }
    return NULL;
}

u8* getChildSubPointIdxArray(u8* arg0, s32 arg1)
{
    u8* p = getChildGoalPoint(arg0, arg1);

    if (p != NULL)
    {
        if (*(s32*)(p + 0x14) != 0)
        {
            return arg0 + *(s32*)(p + 0x18);
        }
    }
    return NULL;
}

u8* getInterestDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x20);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getInterestPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 32 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

u8* getDeadDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x24);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getDeadPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

u8* getLayoutDataHeader(u8* arg0)
{
    s32 temp = *(s32*)(arg0 + 0x28);

    if (temp == 0)
    {
        return NULL;
    }
    return arg0 + temp;
}

u8* getLayoutPointData(u8* arg0, s32 arg1)
{
    u8* temp = NULL;

    if (arg0 != NULL && arg1 >= 0)
    {
        temp = arg0 + arg1 * 48 + 0x10;
        if ((u32)arg1 < *(u32*)arg0)
        {
            return temp;
        }
        temp = NULL;
    }
    return temp;
}

s32 audioDecCreate(s32 *w, s32 a1, s32 a2, s32 a3, s32 a4)
{
    w[6] = a4;
    w[5] = a3;
    w[1] = a1;
    w[3] = a2;
    w[0] = 0;
    w[2] = 0;
    w[4] = 0;
    w[7] = 0;
    w[8] = iosCreateSema(1, 1, 0);
    setPcmTickProcFunc(pcm_tickprocsub);
    return 1;
}

s32 audioDecIsPreset(u8* arg0)
{
    if (*(s32*)(arg0 + 0x10) > 0x3FFFF)
    {
        Sg2ExPcmOutputCtrl(5);
        changeVolume(0x7F);
        return 1;
    }
    return 0;
}

void audioDecReset(s32 *w)
{
    setPcmTickProcFunc(0);
    changeVolume(0);
    EE_MixBufClear();
    w[0] = 0;
    w[2] = 0;
    w[4] = 0;
    w[7] = 0;
    iosDeleteSema(w[8]);
}

void changeVolume(s32 arg0)
{
    s32 temp = arg0 * 129;

    Sg2ExPcmOutputSetVol(temp, temp);
}

void changeVolumeDirect(s32 arg0)
{
    Sg2ExPcmOutputSetVol(arg0, arg0);
}

void spriteMovieImage(void)
{
    SprMov205 spr;
    s32 w;
    s32 h;
    s32 tbp;
    s32 twhH;
    s32 twhW;

    w = getDrawScreenWidth();
    h = getDrawScreenHeight();
    iosDlPushLayer(0x1C);
    spr.col = D_401357F0;
    spr.uv = D_40135800;
    spr.a[0] = (-w / 2) << 4;
    spr.a[1] = (-h / 2) << 4;
    spr.a[2] = w << 4;
    spr.a[3] = h << 4;
    gsRegBegin();
    gsReg(0x4C, (u64)getDrawBufferAddressFBP() | ((u64)((w >> 6) & 0x3F) << 16));
    gsReg(0x18, ((u64)((0x800 - w / 2) << 4)) | (((u64)((0x800 - h / 2) << 4)) << 32));
    gsReg(0x40, ((u64)(w - 1) << 16) | ((u64)(h - 1) << 48));
    gsReg(0x47, 0x31001);
    gsReg(0x3F, 0);
    if (w == 0x200 && h == 0x1C0)
        gsReg(0x14, 0);
    else
        gsReg(0x14, 0x60);
    tbp = getTextureAreaAddressTBP();
    twhH = getTWH(0x1C0);
    twhW = getTWH(0x200);
    gsReg(6, ((u64)tbp | 0x120000) | (((u64)twhH << 30) | ((u64)twhW << 26)) | ((u64)0x8000 << 19));
    spriteTexFast(spr.a[0], spr.a[1], spr.a[2], spr.a[3], 0xFFFFFF, &spr.uv, &spr.col, 0);
    gsRegEnd();
    iosDlPopLayer();
}

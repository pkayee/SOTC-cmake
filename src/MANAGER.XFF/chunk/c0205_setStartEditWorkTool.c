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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", func_400FC890);

/* NEARMISS-STUB initEtiInfoWork */
#if 0 /* NEARMISS 99.95% cat=sched sub=- | EtiWork{free,used,f18} struct + list inlines: only free-list init store sw zero,0(v1) sinks below move a2,a0 (target order 0,4,8); all 6 init orders 99.92-99.95 | attempts=2 */
extern u8 D_401C4990[];
extern u8 D_401C1F60[];
extern s32 D_4012E3C4;

typedef struct EtiList205 {
    s32 n;
    u8 *head;
    u8 *tail;
} EtiList205;

static inline void etiListInit205(EtiList205 *l)
{
    l->n = 0;
    l->head = NULL;
    l->tail = NULL;
}

static inline void etiListAdd205(EtiList205 *l, u8 *node)
{
    if (node != NULL)
    {
        if (l->tail != NULL)
            *(u8 **)(l->tail + 0x8) = node;
        else
            l->head = node;
        *(u8 **)(node + 0x8) = NULL;
        l->n++;
        l->tail = node;
    }
}

typedef struct EtiWork205 {
    EtiList205 free;
    EtiList205 used;
    s32 f18;
} EtiWork205;

void initEtiInfoWork(void)
{
    u8 *node;
    u32 i;

    if (D_4012E3C4 == 0)
    {
        ((EtiWork205 *)D_401C4990)->free.n = 0;
        ((EtiWork205 *)D_401C4990)->free.tail = NULL;
        ((EtiWork205 *)D_401C4990)->free.head = NULL;
        etiListInit205(&((EtiWork205 *)D_401C4990)->used);
        for (i = 0, node = D_401C1F60; i < 0x14; i++, node += 0x21C)
            etiListAdd205(&((EtiWork205 *)D_401C4990)->used, node);
        D_4012E3C4 = 1;
        ((EtiWork205 *)D_401C4990)->f18 = 0;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", initEtiInfoWork);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", audioDecCreate);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", audioDecReset);

void changeVolume(s32 arg0)
{
    s32 temp = arg0 * 129;

    Sg2ExPcmOutputSetVol(temp, temp);
}

void changeVolumeDirect(s32 arg0)
{
    Sg2ExPcmOutputSetVol(arg0, arg0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0205_setStartEditWorkTool", spriteMovieImage);

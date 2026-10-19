#include "common.h"

/* c0125 CreateScriptLwsOri: obj kind 0x16 (rest of the layout is in c0125 matched siblings); ctor = isys create + Init chain inlined as in InitScriptLwsOrientObj. arg order: (grp, extra, def) */
s32 GetLwsOrientWorkSize();
s32 GetScriptObjWorkSize();
void *_isysCreateObj(void *, s32, s32, s32, void (*)(void), s32);
void isysSetObjImmediateDeleteFunc();
void isysInitISYSLetterObj();
void InitLwsOrientObj();
void initScriptObj();
void InitChildGroupManagerObj();
void isysAddGroupWithLinkParam();
void func_400A1C08(void);
void func_400A2338(u8 *);

/* c0125 CreateSortList: list header words {items@0, count@4, scale f32@8, mode@0xC, cur@0x10}, 0x14 bytes from rootPtn. Arg order: bits in a0, mode in a1, scale in f12 */
extern s32 rootPtn;
void *iosMallocAlign(void *, s32, s32);

void isysFlushISYSLetterObj();

/* c0125 func_400A2BD8: per-frame step of a lws-orient track. o: +4 state, +8 target f32, +0xC rate f32, +0x10 timer f32, +0x34 flag f32; *o = class (kind at +0xC). Arg order: dt in f12, o in a0 */
float rintf(float);
static inline int TimerStep(u8 *o, float dt)
{
    *(float *)(o + 0x10) = *(float *)(o + 0x10) - dt;
    if (*(float *)(o + 0x10) < 0.0f) {
        *(float *)(o + 0x10) = 0.0f;
        return 0;
    }
    return 1;
}

u8 *CreateScriptLwsOri(void *grp, s32 extra, u8 *def)
{
    s32 s = (s32)def + 0x134;
    s32 a = GetLwsOrientWorkSize(def);
    s32 b = GetScriptObjWorkSize(s);
    u8 *o = _isysCreateObj(grp, 0x16, 0x11a0, extra + (a + b), (void (*)(void))func_400A2338, 0x10);
    s32 *f;
    s32 *g;
    u8 *c;

    if (o != 0) {
        isysSetObjImmediateDeleteFunc(o, func_400A1C08);
        isysInitISYSLetterObj(o);
        InitLwsOrientObj(o, def);
        initScriptObj(o, s, *(s32 *)o);
        InitChildGroupManagerObj(o);
        c = o[8] != 0x16 ? 0 : o + 0x20;
        f = (s32 *)c + 0x455;
        f[1] = 0;
        f[0] = 0;
        *(s32 *)(c + 0x1164) = 0;
        g = (s32 *)c + 0x457;
        g[0] = 0;
        g[1] = 0;
        isysAddGroupWithLinkParam(o, *(s32 *)(def + 0x120), 0, 0);
    }
    return o;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", func_400A1EA0);

u8 *GetScrLwsOriClass(u8 *p)
{
    if (p[0x8] != 0x16) {
        return 0;
    }
    return p + 0x20;
}

typedef struct {
    void (*fn)(int);
    int arg;
} LwsCb;

void flushScriptObj();
void FlushCharacterObj();
void FlushChildGroupManagerObj();
void iosFree();

void FlushScriptLwsOri(u8 *o)
{
    u8 *c = o[8] != 0x16 ? 0 : o + 0x20;
    LwsCb *cb = (LwsCb *)(c + 0x115C);

    if (cb->fn != 0) {
        cb->fn(cb->arg);
    }
    flushScriptObj(o);
    FlushCharacterObj(o);
    FlushChildGroupManagerObj(o);
    if (*(void **)(c + 0x1154) != 0) {
        iosFree(*(void **)(c + 0x1154));
    }
}

void SetScrLwsOriObjReleaseCallBackFunc(u8 *o, s32 a, s32 b)
{
    u8 *c = o[8] != 0x16 ? 0 : o + 0x20;
    s32 *f = (s32 *)(c + 0x115C);

    f[0] = a;
    f[1] = b;
}

void InitLwsOrientObj();
void initScriptObj();
void InitChildGroupManagerObj();

void InitScriptLwsOrientObj(u8 *o, s32 a)
{
    s32 *f;
    s32 *g;

    InitLwsOrientObj();
    initScriptObj(o, a + 0x134, *(s32 *)o);
    InitChildGroupManagerObj(o);
    o = o[8] != 0x16 ? 0 : o + 0x20;
    f = (s32 *)o + 0x455;
    f[1] = 0;
    f[0] = 0;
    *(s32 *)(o + 0x1164) = 0;
    g = (s32 *)o + 0x457;
    g[0] = 0;
    g[1] = 0;
}

s32 GetLwsOrientWorkSize();
s32 GetScriptObjWorkSize();

s32 GetScriptLwsOrientObjWorkSize(s32 arg0)
{
    s32 temp_s1;

    temp_s1 = GetLwsOrientWorkSize();
    return temp_s1 + GetScriptObjWorkSize(arg0 + 0x134);
}

extern int D_4012B2A4;

void SetScriptLwsOrientObjDefaultScriptFunc(int arg0)
{
    D_4012B2A4 = arg0;
}

void func_400A24A0(void);
void func_400A1EA0(int **, void *, void *);
void *_isysCreateObj(void *, s32, s32, s32, void (*)(void), s32);
int GetLwsOrientNodeNum(int);

void *CreateScriptLwsOrientDefObj(void *grp, int size, int **res)
{
    int n = GetLwsOrientNodeNum(*(int *)((char *)*res + 0x20)) * 12 + 0x33;
    void *o = _isysCreateObj(grp, 0x17, 0x80, size + n, func_400A24A0, 0x10);

    func_400A1EA0(res, o, grp);
    return o;
}

char *GetScriptLwsOrientDefinfo(unsigned char *p)
{
    if (p[0x8] != 0x17) {
        return 0;
    }
    return (char *)p + 0x20;
}

/* c0125 func_400A2338: FlushScriptLwsOri body (c0125 sibling) plus a trailing isysFlushISYSLetterObj */
void func_400A2338(u8 *o)
{
    u8 *c = o[8] != 0x16 ? 0 : o + 0x20;
    LwsCb *cb = (LwsCb *)(c + 0x115C);

    if (cb->fn != 0) {
        cb->fn(cb->arg);
    }
    flushScriptObj(o);
    FlushCharacterObj(o);
    FlushChildGroupManagerObj(o);
    if (*(void **)(c + 0x1154) != 0) {
        iosFree(*(void **)(c + 0x1154));
    }
    isysFlushISYSLetterObj(o);
}

/* DeleteScriptLwsOrientObjSubObjects: c = kind-0x16 payload; c+0x1148 = def (count at 0x30, rows at 0x54 stride 0xC), c+0x1150 = sub-object slots stride 0x50.
   The loop test re-reads c->def->count every pass (the target reloads def only after the delete calls, the count on both paths). */
s32 IsNonISysObjTypeRes(s32);
s32 delete_object_animation_camera_region(void *);
void isysRequestDeleteObj();
s32 FlushLayoutObj(u8 *);

void DeleteScriptLwsOrientObjSubObjects(u8 *o)
{
    u8 *c = o[8] != 0x16 ? 0 : o + 0x20;
    s32 *slot = *(s32 **)(c + 0x1150);
    s32 *row = *(s32 **)(*(u8 **)(c + 0x1148) + 0x54);
    int i;

    for (i = 0; i < *(s32 *)(*(u8 **)(c + 0x1148) + 0x30); i++, slot += 0x14, row += 3) {
        if (*slot != 0) {
            if (IsNonISysObjTypeRes(row[1]) == 0 && *row != 0 && row[1] < 0x2b && 0x26 < row[1]) {
                delete_object_animation_camera_region((void *)*slot);
            }
            isysRequestDeleteObj(*slot);
            FlushLayoutObj((u8 *)*slot);
            *slot = 0;
        }
    }
}


void func_400A24A0(void) {
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", AddSortObj);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", GetNextSortObj);

typedef struct {
    int *items;
    int count;
    int unused[2];
    int current;
} SortList;

void *GetFirstSortObj(SortList *list)
{
    int i = 0;
    void *found = 0;
    if (list->count > 0) {
        list->current = 0;
        for (; i < list->count; i++) {
            list->current = i;
            if (list->items[i]) {
                found = (void *)list->items[i];
                break;
            }
        }
    }
    return found;
}

void InitSortObj(char *p, int a1)
{
    *(int *)(p + 0x0) = a1;
    *(int *)(p + 0xC) = 0;
    *(int *)(p + 0x8) = 0;
}

void ClearSortList(void *list)
{
    int *words = list;
    int i;

    for (i = 0; i < words[1]; i++) {
        ((int *)words[0])[i] = 0;
    }
    words[4] = 0;
}

int *CreateSortList(u32 bits, int mode, float scale)
{
    int *w = iosMallocAlign(&rootPtn, 0x14, 4);
    int n = 1 << bits;
    int i;

    w[3] = mode;
    w[1] = n;
    *(float *)&w[2] = (float)n / scale;
    w[0] = (int)iosMallocAlign(&rootPtn, n << 2, 4);
    for (i = 0; i < w[1]; i++) {
        ((int *)w[0])[i] = 0;
    }
    w[4] = 0;
    return w;
}

void DeleteSortList(void **list)
{
    iosFree(list[0]);
    iosFree(list);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", func_400A2800);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", func_400A28D8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", func_400A2A10);

void func_400A2BD8(float dt, u8 *o)
{
    float *p;
    float d;
    float step;
    float v;

    if (TimerStep(o, dt)) return;
    p = 0;
    switch (*(s32 *)(*(u8 **)o + 0xC)) {
    case 0:
        p = (float *)(o + 0x34);
        break;
    case 2:
    case 3:
        p = (float *)(o + 0x1C);
        break;
    case 1:
    case 4:
        p = (float *)(o + 0x20);
        break;
    }
    d = *(float *)(o + 8) - *p;
    step = *(float *)(o + 0xC) * dt;
    if (*(s32 *)(*(u8 **)o + 0xC) != 0) {
        *(float *)(o + 0x34) = 1.0f;
        step = rintf(step);
        if (step < 0.0f) {
            if (!(-1.0f < step)) goto done;
        } else if (!(step < 1.0f)) {
            goto done;
        }
        if (0.0f < step) step = 1.0f;
        if (step < 0.0f) step = -1.0f;
    }
done:
    *p = *p + step;
    v = *(float *)(o + 8);
    if (d * (v - *p) <= 0.0f) {
        *p = v;
        if (v == 0.0f) {
            *(s32 *)(o + 4) = 0;
        } else {
            *(s32 *)(o + 4) = 3;
        }
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", func_400A2D58);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", func_400A3058);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0125_CreateScriptLwsOri", func_400A33D8);

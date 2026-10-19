#include "common.h"

/* ModifiedManager: p[0]=count, p[2]=flag bytes, p[3]=index width (1/2/4), p[4]=index list */
void iosJumpRecoverPoint(char *);
extern char D_40134240[];

typedef struct { char name[0x10]; s32 size; s32 pad[11]; } McDirEnt;
extern char *strrchr(const char *, int);
extern char *strcpy(char *, const char *);
extern s32 strlen(const char *);
extern s32 iosMcMkDir(s32, s32, char *);
extern s32 iosMcCreateFile(s32, s32, char *);
extern s32 iosMcGetDir(s32, s32, char *, s32, s32, void *, void *);

void FlushModifiedManager(s32 *p)
{
    s32 n = p[0];
    s32 i;

    if (n == 0)
        return;
    i = p[3];
    switch (i)
    {
    case 1:
    {
        u8 *q = (u8 *)p[4];
        for (i = 0; i < n; i++)
            *((u8 *)p[2] + *q++) = 0;
        break;
    }
    case 2:
    {
        u16 *q = (u16 *)p[4];
        for (i = 0; i < n; i++)
            *((u8 *)p[2] + *q++) = 0;
        break;
    }
    case 4:
    {
        s32 *q = (s32 *)p[4];
        for (i = 0; i < n; i++)
            *((u8 *)p[2] + *q++) = 0;
        break;
    }
    default:
        iosJumpRecoverPoint(D_40134240);
        break;
    }
    p[0] = 0;
}

/* ModifiedManager entry: append v to the index list (width p[3]) and set flag byte v */
s32 EntryModifiedManager(s32 *p, s32 v)
{
    s32 i = p[0];
    s32 w = p[3];

    p[0] = i + 1;
    switch (w)
    {
    case 1:
        *((u8 *)p[4] + i) = v;
        break;
    case 2:
        *((u16 *)p[4] + i) = v;
        break;
    case 4:
        *((s32 *)p[4] + i) = v;
        break;
    }
    *((u8 *)p[2] + v) = 1;
    return i;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", RelocateModifiedManager);
int RelocateModifiedManager(s32 *p, s32 n, s32 addr)
{
    s32 w;

    if (n <= 0xFFFF)
        w = n >= 0x100 ? 2 : 1;
    else
        w = 4;
    if (n != 0)
    {
        p[4] = addr;
        addr = addr + ((w * n + 15) & ~15);
        p[2] = addr;
        addr = addr + ((n + 15) & ~15);
    }
    return addr;
}


//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", InitModifiedManager);
void InitModifiedManager(s32 *p, s32 n)
{
    s32 i;
    s32 w;

    p[0] = 0;
    p[1] = 0;
    if (n != 0)
    {
        if (n <= 0xFFFF)
            w = n >= 0x100 ? 2 : 1;
        else
            w = 4;
        p[3] = w;
        for (i = 0; i < n; i++)
        {
            *((u8 *)p[2] + i) = 0;
        }
    }
    else
    {
        p[2] = 0;
        p[4] = 0;
    }
}

void DeleteModifiedManager(void) {
}

int GetSizeOfModifiedManagerWork(int n)
{
    int w;

    if (n == 0)
        return 0;
    if (n <= 0xFFFF)
        w = n >= 0x100 ? 2 : 1;
    else
        w = 4;
    return ((n + 15) & ~15) + ((w * n + 15) & ~15);
}

void InitTwoWayLink(char *p, int a1)
{
    *(int *)(p + 0x8) = a1;
    *(int *)(p + 0x0) = 0;
    *(int *)(p + 0x4) = 0;
}

int AddTwoWayLinkNext(int *a, int *b)
{
    int *n;
    int t = a[1];

    b[0] = (int)a;
    b[1] = t;
    n = (int *)a[1];
    if (n != 0) {
        n[0] = (int)b;
    }
    a[1] = (int)b;
    return 1;
}

typedef struct Link {
    struct Link *next;
    struct Link *prev;
} Link;

typedef struct LinkObj {
    struct LinkObj *prev;
    struct LinkObj *next;
    void *obj;
} LinkObj;

int DeleteTwoWayLink(Link *l)
{
    if (l->prev != 0)
        l->prev->next = l->next;
    if (l->next != 0)
        l->next->prev = l->prev;
    l->next = 0;
    l->prev = 0;
    return 1;
}

int DeleteAllTwoWayLink(LinkObj *l, void (*fn)(void *))
{
    LinkObj *n = l->next;
    LinkObj *next;
    while (n != 0) {
        next = n->next;
        n->prev = 0;
        n->next = 0;
        if (fn != 0)
            fn(n->obj);
        n = next;
    }
    l->next = 0;
    return 1;
}

int ScanAllTwoWayLink(LinkObj *l, void (*fn)(void *, void *), void *arg)
{
    LinkObj *n;
    for (n = l->next; n != 0; n = n->next)
        fn(n->obj, arg);
    return 1;
}

int GetTwoWayLinkNext(void *arg0)
{
    return (*(int *)((char *)(arg0) + 4));
}

void RelocateTwoWayLinkHeader(char **p)
{
    char **n = (char **)p[1];

    if (n != 0) {
        n[0] = (char *)p;
    }
}

int GetTwoWayLinkData(void *arg0)
{
    return (*(int *)((char *)(arg0) + 8));
}

typedef struct KbKey {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 rest : 28;
    s32 w1;
    s32 w2;
} KbKey;

/* keyboard state: cur = keys of the last USB report, buf = double-buffered latched keys indexed by idx */
typedef struct KbState {
    KbKey cur[256];
    s32 mod;
    KbKey buf[2][256];
    s32 latchedMod;
    s32 idx;
} KbState;

extern KbState D_401AE250;
extern KbKey D_401AFA54[];
s32 func_400D96A0();
void usbdevAddCallbackFunc();

/* latch: out.b0 = held, b1 = pressed (held now, not before), b2 = released; then flip the latch buffer and seed it with cur */
void kbGetStatus(KbKey *out, s32 *mod)
{
    s32 i;

    *mod = D_401AE250.latchedMod;
    for (i = 0; i < 256; i++) {
        out[i].b0 = D_401AE250.buf[D_401AE250.idx][i].b0;
        out[i].b1 = D_401AE250.buf[D_401AE250.idx ? 0 : 1][i].b0 ? 0 : D_401AE250.buf[D_401AE250.idx][i].b0;
        out[i].b2 = D_401AE250.buf[D_401AE250.idx][i].b0 ? 0 : D_401AE250.buf[D_401AE250.idx ? 0 : 1][i].b0;
    }
    D_401AE250.idx ^= 1;
    for (i = 0; i < 256; i++)
        D_401AE250.buf[D_401AE250.idx][i].b0 = D_401AE250.cur[i].b0;
    D_401AE250.latchedMod = D_401AE250.mod;
}

/* USB keyboard report callback: rebuild cur from the report key list, OR it into the active latch buffer */
s32 func_400D96A0(u8 *rep)
{
    s32 i;

    for (i = 0; i < 256; i++)
        D_401AE250.cur[i].b0 = 0;
    for (i = 0; i < rep[1] - 2; i++)
        D_401AE250.cur[rep[4 + i]].b0 = 1;
    D_401AE250.mod = rep[2] & 0xF;
    for (i = 0; i < 256; i++)
        D_401AE250.buf[D_401AE250.idx][i].b0 |= D_401AE250.cur[i].b0;
    D_401AE250.latchedMod |= D_401AE250.mod;
    return 1;
}

static inline void kbClearTable(KbKey *k)
{
    s32 i;

    for (i = 0; i < 256; i++) {
        k[i].b3 = 0;
        k[i].b2 = 0;
        k[i].b1 = 0;
        k[i].b0 = 0;
    }
}

void kbInit(void)
{
    D_401AE250.idx = 0;
    D_401AE250.latchedMod = 0;
    D_401AE250.mod = 0;
    kbClearTable(D_401AE250.buf[0]);
    kbClearTable(D_401AFA54);
    kbClearTable(D_401AE250.cur);
    usbdevAddCallbackFunc(func_400D96A0, 1);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", func_400D98A8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", func_400D9E70);

/* NEARMISS-STUB func_400DA5C0 */
#if 0 /* NEARMISS 83.17% cat=regalloc sub=- | d2 r96 (REA ev_0882a993): a block-local 'float *prog = &D_4012BB38; McFile172 *f = &D_401B0660;' for the task loop gives fp = hi(D_401B16CC) reused for both lis | attempts=2 */
/* memory card: run the save-task list D_401B16CC against the file descriptor D_401B0660, progress 0.1 -> 0.9 -> 1.0 */
typedef struct { s32 id; s32 (*fn)(void *); } McTask172;
typedef struct { char name[0x20]; s32 port; s32 slot; s32 size; s32 ofs; s32 x30; } McFile172;
extern McTask172 *D_401B16CC;
extern McFile172 D_401B0660;
extern float D_4012BB38;
extern s32 iosMcChDir(s32, s32, char *);
extern char D_401342D0[];
extern char D_401342F8[];

static inline void mcSetFile172(s32 port, s32 slot, char *name, s32 size, s32 ofs)
{
    D_401B0660.port = port;
    D_401B0660.slot = slot;
    strcpy(D_401B0660.name, name);
    D_401B0660.size = size;
    D_401B0660.ofs = ofs;
    D_401B0660.x30 = 0;
}

void func_400DA5C0(s32 *w)
{
    McTask172 *t;
    s32 cnt = 0;
    s32 port = w[1];
    s32 slot = w[2];
    float step;

    for (t = D_401B16CC; t->fn != 0; t++)
        cnt++;
    step = 0.8f / cnt;
    w[11] = iosMcChDir(port, slot, D_401342D0);
    if (w[11] != 0)
        return;
    D_4012BB38 = 0.1f;
    mcSetFile172(port, slot, D_401342F8, 0x5400, w[5] * 0x5800 + 0xC00);
    {
        float *prog = &D_4012BB38;
        McFile172 *f = &D_401B0660;
        for (t = D_401B16CC; t->fn != 0; t++) {
            w[11] = t->fn(f);
            if (w[11] != 0)
                return;
            *prog += step;
        }
    }
    w[11] = 0;
    D_4012BB38 = 1.0f;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", func_400DA5C0);

/* memory card: write the MCSTAT044 header (10 bytes, copied to +0 and +0x88) of entry w[5] into the save image */
typedef struct { u8 b[0x38]; } McDirParam172;
typedef struct { s64 a; u16 b; } McStat172;
extern s32 iosMcChDir(s32, s32, char *);
extern s32 iosMcWriteFile(s32, s32, char *, void *, s32, s32);
extern void *memset(void *, int, unsigned int);
extern char D_40134310[];
extern char D_401342D0[];
extern char D_401342F8[];
extern McStat172 D_401342E8;

void func_400DA750(s32 *w)
{
    const s32 n = 0x12;
    s32 cnt;
    McDirParam172 dir[n];
    s32 port = w[1];
    s32 slot = w[2];
    u8 *e;
    s32 i;
    s32 ofs;
    char *name;
    s64 a;
    u16 b;

    w[11] = iosMcGetDir(port, slot, D_40134310, 0, n, dir, &cnt);
    if (w[11] != 0)
        return;
    w[11] = iosMcChDir(port, slot, D_401342D0);
    name = D_401342F8;
    if (w[11] != 0)
        return;
    i = w[5];
    e = (u8 *)(i * 0x98 + w[10]) + 0xD8;
    ofs = i * 0x5800 + 0x800;
    memset(e, 0, 0x98);
    a = D_401342E8.a;
    b = D_401342E8.b;
    *(s64 *)e = a;
    *(u16 *)(e + 8) = b;
    *(s64 *)(e + 0x88) = a;
    *(u16 *)(e + 0x90) = b;
    w[11] = iosMcWriteFile(port, slot, name, e, ofs, 0x98);
    if (w[11] != 0)
        return;
    w[11] = 0;
}

/* memory card: create the file named at +0xC (making its directory), then read back the dir entry size into +0x18 */
void func_400DA8B0(s32 *w)
{
    McDirEnt ent;
    s32 cnt[4];
    s32 len = strlen((char *)w[3]);
    char str[len + 1];
    char *sl;

    strcpy(str, (char *)w[3]);
    sl = strrchr(str, 0x2F);
    if (sl != 0)
    {
        *sl = 0;
        iosMcMkDir(w[1], w[2], str);
    }
    w[11] = iosMcCreateFile(w[1], w[2], (char *)w[3]);
    iosMcGetDir(w[1], w[2], (char *)w[3], 0, 1, &ent, cnt);
    if (cnt[0] != 1)
        ent.size = 0;
    w[6] = ent.size;
}

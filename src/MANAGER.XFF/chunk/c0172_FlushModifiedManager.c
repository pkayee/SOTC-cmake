#include "common.h"

/* ModifiedManager: p[0]=count, p[2]=flag bytes, p[3]=index width (1/2/4), p[4]=index list */
void iosJumpRecoverPoint(char *);
extern char D_40134240[];

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", kbGetStatus);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", func_400D96A0);

/* NEARMISS-STUB kbInit */
#if 0 /* NEARMISS 94.75% cat=regalloc sub=- | REA READY drop-in scored 94.75 in-TU (apply_ready) | attempts=1 */
/* keyboard state tables: 256 entries of 3 words, low 4 flag bits cleared in the three tables */
void kbInit(void)
{
    u8 *g = (u8 *)D_401AE250;
    u32 *q;
    u32 v;
    s32 i;

    *(s32 *)(g + 0x2408) = 0;
    *(s32 *)(g + 0x2404) = 0;
    *(s32 *)(g + 0xC00) = 0;
    q = (u32 *)(g + 0xC04);
    for (i = 0xFF; i >= 0; i--)
    {
        v = *q;
        v &= ~8;
        v &= ~4;
        v &= ~2;
        v &= ~1;
        *q = v;
        q += 3;
    }
    q = D_401AFA54;
    for (i = 0xFF; i >= 0; i--)
    {
        v = *q;
        v &= ~8;
        v &= ~4;
        v &= ~2;
        v &= ~1;
        *q = v;
        q += 3;
    }
    q = D_401AE250;
    for (i = 0xFF; i >= 0; i--)
    {
        v = *q;
        v &= ~8;
        v &= ~4;
        v &= ~2;
        v &= ~1;
        *q = v;
        q += 3;
    }
    usbdevAddCallbackFunc(func_400D96A0, 1);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", kbInit);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", func_400D98A8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", func_400D9E70);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", func_400DA5C0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", func_400DA750);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", func_400DA8B0);

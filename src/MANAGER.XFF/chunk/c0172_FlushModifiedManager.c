#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", FlushModifiedManager);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", EntryModifiedManager);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", RelocateModifiedManager);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", InitModifiedManager);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", kbInit);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", func_400D98A8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", func_400D9E70);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", func_400DA5C0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", func_400DA750);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0172_FlushModifiedManager", func_400DA8B0);

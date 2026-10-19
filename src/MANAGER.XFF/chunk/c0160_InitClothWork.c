#include "common.h"

u8 *GetLayoutClass();
void *iosMallocAlign();
s32 func_400CA198();

typedef struct {
    u8 *works;
    s16 n;
    u8 f6;
    s8 sw;
    s32 f8;
    s32 fC;
    s32 f10;
} ClothWork;

typedef struct {
    u8 pad0[0x10];
    void (*cb)(s32);
    s32 f14;
    s32 f18;
    s32 f1C;
} ClothParam;

/* NEARMISS-STUB InitClothWork */
#if 0 /* NEARMISS 97.49% cat=sched sub=- | only the header store order: target sh n, sw works, sb 7, sb 6, sw lc+0x178 (delay); all 120 source orders of the 5 stores tried (best n,178,sw,f6,works), stati | attempts=1 */
ClothWork *InitClothWork(s32 heap, s32 obj, ClothParam *prm)
{
    u8 *lc = GetLayoutClass(obj);
    u8 *def = *(u8 **)(lc + 0x180);
    s32 n = 0;
    u8 *p = def;
    ClothWork *cw;
    u8 *w;
    s32 i;

    while (*(s16 *)p >= 0)
    {
        p += 0x34;
        n++;
    }
    cw = iosMallocAlign(heap, 0x14, 4);
    w = iosMallocAlign(heap, n * 0x90, 0x10);
    cw->n = n;
    *(ClothWork **)(lc + 0x178) = cw;
    cw->sw = 1;
    cw->f6 = 0;
    cw->works = w;
    for (i = 0; i < n; i++)
    {
        cw->f6 |= func_400CA198(w, heap, def, obj, prm);
        w += 0x90;
        def += 0x34;
    }
    if (prm->cb != NULL)
    {
        prm->cb(obj);
    }
    cw->f10 = prm->f14;
    cw->f8 = prm->f18;
    cw->fC = prm->f1C;
    return cw;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0160_InitClothWork", InitClothWork);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0160_InitClothWork", CheckClothChainDetect);

int GetClothWorkSize(char *c)
{
    int n = 0;
    char *p = c;
    int size;
    int i;

    while (*(short *)p >= 0) {
        p += 0x34;
        n++;
    }
    size = n * 0xC3 + 0x47;
    for (i = 0; i < n; i++) {
        size = size + (*(int *)(c + 4) * 24 + *(int *)(c + 4) * *(int *)(c + 8) * 64) + 0x33;
        c += 0x34;
    }
    return size;
}

typedef struct {
    u8 pad0[0xC];
    s32 nC;
    s32 f10;
    s32 n14;
    u8 pad18[0xC];
} ClothRes;

typedef struct {
    s16 type;
    s16 pad2;
    s32 n4;
    s32 n8;
    u8 padC[0x1C];
    ClothRes *res;
    s32 f2C;
    u8 pad30[4];
} ClothDef;

void DebugDumpClothResources(ClothDef *def)
{
    s32 i;
    s32 k;

    while (def->type >= 0)
    {
        for (i = 0; i < def->n4; i++)
        {
            for (k = 0; k < def->res[i].nC; k++)
            {
            }
            for (k = 0; k < def->res[i].n14; k++)
            {
            }
            if (def->f2C >= 0)
            {
                for (k = 0; k < def->n8; k++)
                {
                }
            }
        }
        def++;
    }
}

typedef struct {
    char *p;
    short n;
} Cloth;

extern void func_400C9E30(char *);
extern void func_400C9BE0(char *);

int DispCloth(Cloth *c)
{
    char *p = c->p;
    int n = c->n;
    int i;

    for (i = 0; i < n; i++) {
        if (p[0x81] == 0)
            func_400C9E30(p);
        else
            p[0x81] = 0;
        p += 0x90;
    }
    return 1;
}

int DebugDispCloth(Cloth *c)
{
    char *p = c->p;
    int n = c->n;
    int i;

    for (i = 0; i < n; i++) {
        func_400C9BE0(p);
        p += 0x90;
    }
    return 1;
}





s32 *isysGroupForFirst();
s32 *isysGroupForNext();
void isysGroupForExit();
void SetLayoutObjAccessSwitch();


void isysRequestDeleteObj();
void isysDeleteGroupAllObj();
void meshObjectFree();

void FlushClothWork(s32 obj)
{
    u8 *lc = GetLayoutClass(obj);
    s32 n = 0;
    u8 *def = *(u8 **)(lc + 0x180);
    u8 *w = (*(ClothWork **)(lc + 0x178))->works;
    u8 *p = def;
    s32 i;
    s32 last;
    s32 *node;

    while (*(s16 *)p >= 0)
    {
        p += 0x34;
        n++;
    }
    for (i = 0; i < n; i++)
    {
        switch (*(s16 *)def)
        {
        case 0:
        default:
            meshObjectFree(*(s32 *)(w + 0x20));
            break;
        case 1:
            node = isysGroupForFirst(w + 8, 0);
            last = 0;
            while (node != NULL)
            {
                last = *node;
                isysRequestDeleteObj(last);
                node = isysGroupForNext(node, 0);
            }
            if (last != 0)
            {
                isysGroupForExit(last, 0);
            }
            isysDeleteGroupAllObj(w + 8);
        }
        def += 0x34;
        w += 0x90;
    }
}

void SetClothAccessSwitch(ClothWork *cw, s32 sw)
{
    s32 n;
    u8 *w;
    s32 on;
    s32 obj;
    s32 *node;

    cw->sw = sw;
    n = cw->n;
    w = cw->works;
    while (n-- != 0)
    {
        on = 0;
        if (sw != 0)
        {
            on = ((s8 *)w)[0x82] != 0;
        }
        node = isysGroupForFirst(w + 8, 0);
        obj = 0;
        while (node != NULL)
        {
            obj = *node;
            SetLayoutObjAccessSwitch(obj, on);
            node = isysGroupForNext(node, 0);
        }
        if (obj != 0)
        {
            isysGroupForExit(obj, 0);
        }
        w += 0x90;
    }
}

void SetClothWorkDispFlag(ClothWork *cw, s32 idx, s32 flag)
{
    u8 *w = cw->works + idx * 0x90;
    s32 obj = 0;
    s32 on;
    s32 *node;

    w[0x82] = flag;
    on = cw->sw != 0 ? flag != 0 : 0;
    node = isysGroupForFirst(w + 8, 0);
    while (node != NULL)
    {
        obj = *node;
        SetLayoutObjAccessSwitch(obj, on);
        node = isysGroupForNext(node, 0);
    }
    if (obj != 0)
    {
        isysGroupForExit(obj, 0);
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0160_InitClothWork", GetClothQuaternion);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0160_InitClothWork", GetClothPosition);

#include "common.h"

extern int D_4012A6A4;

void func_40042528(void)
{
    int iVar1;
    int iVar2;

    iVar2 = D_4012A6A4;
    if (iVar2 != 0)
    {
        iVar1 = *(int *)(iVar2 + 4);
        while (1)
        {
            if (*(int *)(iVar1 + 0x24) == 0)
            {
                iVar2 = *(int *)(iVar2 + 0xc);
            }
            else
            {
                *(int *)(iVar1 + 0x14) = 0;
                *(int *)(iVar1 + 0x10) = 0;
                *(int *)(iVar1 + 0x1c) = 0;
                *(int *)(iVar1 + 0x18) = 0;
                iVar2 = *(int *)(iVar2 + 0xc);
            }
            if (iVar2 == 0)
            {
                break;
            }
            iVar1 = *(int *)(iVar2 + 4);
        }
    }
    return;
}

extern unsigned char D_4012A96C[];

void *getTexTransEnableFlag(void)
{
    return D_4012A96C;
}

extern int D_4012A970;

void texSetModelName(int arg0)
{
    D_4012A970 = arg0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0039_func_40042528", func_40042590);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0039_func_40042528", func_40042708);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0039_func_40042528", func_40042860);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0039_func_40042528", func_40042B08);

extern int texGetTexTBPSize(int w, int h, int psm);
extern void func_40042708();

void vramAlloc(int arg0, int psm, int w, int h, int n)
{
    int i;
    int size = 0;

    for (i = 0; i < n; i++)
    {
        size += texGetTexTBPSize(w >> i, h >> i, psm);
    }
    func_40042708(arg0, size);
}

extern s32 rootPtn;
extern void *iosMallocAlign(void *ptn, s32 size, s32 align);
extern void func_40042B08(void *blk);
extern u8 *D_4012A978;

static inline void vramListInit(s32 *l)
{
    l[0] = 0;
    l[1] = 0;
}

void *vramCreateBlock(int arg0, int type, int w, int h)
{
    u8 *b = iosMallocAlign(&rootPtn, 0x68, 4);

    *(u8 **)(b + 0x64) = D_4012A978;
    D_4012A978 = b;
    switch (type)
    {
    case 0:
        *(s32 *)(b + 0x44) = w;
        *(s32 *)(b + 0x48) = h;
        *(s32 *)(b + 0x40) = 0;
        *(s32 *)(b + 0x4C) = 0;
        break;
    case 1:
        *(s32 *)(b + 0x44) = w;
        *(s32 *)(b + 0x48) = h;
        *(s32 *)(b + 0x40) = 0;
        *(s32 *)(b + 0x4C) = 0;
        break;
    case 2:
        *(s32 *)(b + 0x44) = w;
        *(s32 *)(b + 0x40) = 1;
        *(s32 *)(b + 0x48) = h;
        *(s32 *)(b + 0x4C) = 0;
        break;
    case 3:
        *(s32 *)(b + 0x44) = w;
        *(s32 *)(b + 0x40) = 2;
        *(s32 *)(b + 0x48) = h;
        *(s32 *)(b + 0x4C) = 0;
        break;
    case 4:
        *(s32 *)(b + 0x44) = w;
        *(s32 *)(b + 0x40) = 3;
        *(s32 *)(b + 0x48) = h;
        *(s32 *)(b + 0x4C) = 0;
        break;
    }
    vramListInit((s32 *)(b + 0x54));
    vramListInit((s32 *)(b + 0x5C));
    func_40042B08(b);
    return b;
}

extern int iosFree();

int vramDeleteBlock(int a, int b, int c, int d)
{
    return iosFree(a, b, c, d);
}

/* NEARMISS-STUB vramFree */
#if 0 /* NEARMISS 88.75% cat=branch-layout sub=- | gcc picks bnel/bnezl branch-likely with ld ra in delay slot; target uses plain bne and nop delay | attempts=1 */
extern void func_40042860();

void vramFree(void *param_1)
{
    if (*(s32 *)((u8 *)param_1 + 8) == 2 && (*(u32 *)((u8 *)param_1 + 0xc) & 1) == 0)
    {
        func_40042860(param_1);
    }
    return;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0039_func_40042528", vramFree);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0039_func_40042528", vramReset);

extern int D_4012A980;

void vramEnd(void)
{
    iosFree(D_4012A980);
}

typedef struct VramNode
{
    s32 prev;
    s32 next;
    s32 type;
    u32 flags;
    s32 blk;
    s32 f14;
    s32 f18;
    s32 f1C;
} VramNode;

typedef struct
{
    s32 head;
    s32 count;
} VramList;

typedef struct
{
    s32 blocks;
    s32 unk4;
    s32 pool;
    VramList free;
} VramMgr;

extern char D_40131BD0[];
extern void memprintf(const char *fmt, ...);

static inline void vramListPush(VramList *l, VramNode *n)
{
    if (l->head != 0)
    {
        ((VramNode *)l->head)->prev = (s32)n;
    }
    n->prev = 0;
    n->next = l->head;
    l->head = (s32)n;
    l->count++;
}

void vramInit(void)
{
    VramList *fl;
    int i;

    ((VramMgr *)&D_4012A978)->blocks = 0;
    fl = &((VramMgr *)&D_4012A978)->free;
    fl->head = 0;
    fl->count = 0;
    ((VramMgr *)&D_4012A978)->pool = (s32)iosMallocAlign(&rootPtn, 0x3000, 4);
    for (i = 0; i < 0x180; i++)
    {
        ((VramNode *)((VramMgr *)&D_4012A978)->pool)->prev = ((VramNode *)((VramMgr *)&D_4012A978)->pool)->next = 0;
        vramListPush(fl, &((VramNode *)((VramMgr *)&D_4012A978)->pool)[i]);
    }
    memprintf(D_40131BD0);
}

extern void func_40042708();

void vramAllocByTBPSize(void)
{
    func_40042708();
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0039_func_40042528", zFog);

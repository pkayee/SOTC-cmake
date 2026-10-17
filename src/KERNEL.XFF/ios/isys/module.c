#include "common.h"
#include <stdarg.h>
#include "ios/kernel.h"
#include "ios/hash.h"
#include "gcc/string.h"

typedef struct MemoryInfo
{
    /* 0x00 */ void *stack_base;
    /* 0x04 */ void *stack_end;
    /* 0x08 */ void *heap_base;
    /* 0x0C */ void *heap_end;
    /* 0x10 */ void *module_stack_base;
    /* 0x14 */ void *module_stack_end;
    /* 0x18 */ void *unk18;
    /* 0x1C */ void *stack_base2;
    /* 0x20 */ struct { char path[0x40]; s32 stack_size; void *unk44; } module_info;
} MemoryInfo;

typedef struct ModPartEnt
{
    /* 0x00 */ void *ptr;
    /* 0x04 */ u32 unk4[5];
    /* 0x18 */ void *ptr18;
    /* 0x1C */ u32 unk1C;
} ModPartEnt;

typedef struct ModSymEnt
{
    /* 0x00 */ u32 nameOff;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u32 unk8;
    /* 0x0C */ u16 unkC;
    /* 0x0E */ u16 sect;
} ModSymEnt;

typedef struct ModExpEnt
{
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ void *sym;
    /* 0x0C */ u32 unkC;
} ModExpEnt;

typedef struct ModImpEnt
{
    /* 0x00 */ u32 unk0;
    /* 0x04 */ void *sym;
    /* 0x08 */ u32 unk8;
    /* 0x0C */ u32 unkC;
} ModImpEnt;

typedef struct ModHdr
{
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u32 unk8;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ void (*unk10)(void *);
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ u32 *impSymIxs;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ ModSymEnt *symTab;
    /* 0x2C */ u32 strTab;
    /* 0x30 */ u8 *table;
    /* 0x34 */ u32 unk34;
    /* 0x38 */ s32 relocNrE;
    /* 0x3C */ struct t_xffRelocEnt *relocTab;
    /* 0x40 */ s32 symBase;
} ModHdr;

typedef struct ModObj
{
    /* 0x00 */ u32 unk0[7];
    /* 0x1C */ ModHdr *hdr;
    /* 0x20 */ void *entry;
    /* 0x24 */ ModExpEnt *exp;
    /* 0x28 */ ModImpEnt *imports;
    /* 0x2C */ u32 flags;
    /* 0x30 */ u32 pendCount;
    /* 0x34 */ void *pending;
    /* 0x38 */ char *name;
    /* 0x3C */ u32 allocSize;
} ModObj;
typedef struct ModPendEnt
{
    struct t_xffRelocEnt *sec;
    u32 relIdx;
} ModPendEnt;
typedef struct ModPend
{
    u32 count;
    ModPendEnt *arr;
} ModPend;

extern char D_40047138[];
extern char D_40046EC0[]; // "dld:\tError. this file no needs for allocate memory.\n"
extern s32 D_40045820;
extern s32 D_40045828;
extern s32 D_40081A20;
extern t_hashTable D_40081A18;
extern char D_40047400[];
extern char D_400474A8[];
extern char D_40047068[];
extern char D_40047088[];
extern char D_40047090[];
extern char D_400470A8[];
extern char D_400470B8[];
extern char D_400470D8[];
extern s32 iosLoadIopModule(char *, char *, s32, s32);
extern ModObj *func_4001AD58(char *, s32, s32);
extern s32 iosLoaderGetFileSizeName(char *);
extern s32 func_4001C350(s32, char *, s32);
extern void func_4001AB68(void *, char *, void *);
extern void *_isysCreateObj(s32, s32, s32, s32, void *, s32);
extern void func_4001C5E8();
extern s32 DldSysUndefSymbol;
extern void *func_4001C3B0(s32, s32);
extern s32 func_4001C440(void);
extern void func_40019D68(void *, void *, u32, void *, void *, s32, void *, s32);
extern char D_40047058[];
extern char D_40047028[];
extern char D_40047030[];
typedef struct CdlFile
{
    /* 0x00 */ u32 lsn;
    /* 0x04 */ s32 size;
    /* 0x08 */ char name[0x20];
    /* 0x28 */ u8 date[8];
} CdlFile;
extern s32 sceCdSearchFile(CdlFile *, const char *);
extern s32 func_4001D120(s32);
typedef struct DldSlot { s32 unk0; s32 unk4; } DldSlot;
extern DldSlot D_40081A28[8];
extern void *iosMallocAlign(s32, s32, s32);
extern void iosFreeParts(void *, void *, s32);
extern void func_4001CFE0(s32);
extern s32 rootPtn;
extern s32 iosLoaderFOpen(char *, s32, s32);
extern s32 iosLoaderFRead(s32, void *, s32);
extern s32 iosLoaderFClose(s32);
extern void func_40019A00(ModObj *, s32);
extern s32 func_40019FF0(ModObj *);
extern void func_4001A2F8(ModObj *);
extern void func_4001C8F0();
extern void _isysDeleteGroup(void *obj, void *group, s32 flag);
extern void isysLaunchModule(ModObj *obj);
extern char D_40047060[];
extern s32 iosSPrintf(char *, char *, ...);
extern s32 OutputLinkerScriptFile(void *, char *, void *);
extern s32 printf(const char *, ...);
extern u16 symbolDefModuleGroup[];
extern u16 needResolveModuleGroup[];
extern u16 executableModuleGroup[];

typedef struct isysLink
{
    /* 0x00 */ void *obj;
} isysLink;
extern isysLink *isysGroupForFirst(u16 *group, s32 flag);
extern isysLink *isysGroupForNext(isysLink *link, s32 flag);
extern void isysGroupForExit(void *obj, s32 flag);
extern void isysInitGroup(u16 *group);
extern void InitStrHash(t_hashTable *hTable, void *ptn, s32 size);
extern void func_4001AE88(char *name, void *hdr, void *ptn);
extern void isysCreateExceptionThread(void);
extern s32 LoaderSysGetMemoryInfo(MemoryInfo *info);
extern MemoryInfo D_400819B0;
extern s32 LoaderSysFOpen(char *, s32, s32);
extern s32 LoaderSysFClose(s32);
extern s32 LoaderSysGetstat(char *, void *);
extern s32 func_4001CDD8(char *, char *, ModObj *, s32);
extern char D_40047170[], D_400471C0[], D_40047220[], D_40047270[], D_400472C8[], D_40047308[], D_40047388[];
extern s32 LoaderSysPrintf(const char *, ...);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_400199B0);
s32 func_400199B0(s32 arg0, ...)
{
    return 0;
}

/* NEARMISS-STUB func_40019A00 */
#if 0 /* NEARMISS 93.8% cat=regalloc sub=- | REA near-miss; pending loop n-- pre-tests | attempts=2 */
typedef struct ModImpNode
{
    u32 hash;
    struct t_xffSymEnt *sym;
    u32 prev;
    struct ModImpNode *next;
} ModImpNode;
extern void RelocateCode(struct t_xffEntPntHdr *);
extern void ResolveRelocation(struct t_xffEntPntHdr *, void *, u32);
typedef struct ModPendEnt2
{
    struct t_xffRelocEnt *sec;
    u32 relIdx;
} ModPendEnt2;
void func_40019A00(ModObj *obj, s32 mode)
{
    struct t_xffEntPntHdr *xff;
    struct t_xffSymEnt *symTab;
    struct t_xffImpSymIxs *ix;
    ModPendEnt2 *r;
    struct t_xffRelocAddrEnt *ent;
    s32 n;
    s32 m;

    if (obj->flags & 0x40000000)
    {
        return;
    }
    xff = (struct t_xffEntPntHdr *)obj->hdr;
    if (mode != 0)
    {
        RelocateCode(xff);
        if (xff->impSymIxsNrE != 0)
        {
            symTab = xff->symTab;
            ix = xff->impSymIxs;
            n = xff->impSymIxsNrE;
            n--;
            for (; n != -1; n--)
            {
                symTab[(ix++)->stIx].unk0D = 0;
            }
        }
        return;
    }
    if (xff->impSymIxsNrE != 0)
    {
        r = (ModPendEnt2 *)obj->pending;
        n = obj->pendCount;
        n--;
        for (; n != -1; n--)
        {
            ent = (struct t_xffRelocAddrEnt *)((u8 *)r->sec->addr + r->relIdx * 8);
            if (xff->symTab[ent->tyIx >> 8].unk0D)
            {
                ResolveRelocation(xff, r->sec, r->relIdx);
            }
            r++;
        }
        symTab = xff->symTab;
        ix = xff->impSymIxs;
        m = xff->impSymIxsNrE;
        m--;
        for (; m != -1; m--)
        {
            symTab[(ix++)->stIx].unk0D = 0;
        }
    }
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_40019A00);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_40019B58);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_40019D68);

/* NEARMISS-STUB func_40019FF0 */
#if 0 /* NEARMISS 84.71% cat=regalloc sub=- | symTab spill, frame 0x70 (pct +0.01 so clean attempt outranks the stored asm-containing one) | attempts=3 */
typedef struct ModImpNode
{
    /* 0x00 */ u32 hash;
    /* 0x04 */ struct t_xffSymEnt *sym;
    /* 0x08 */ u32 prev;
    /* 0x0C */ struct ModImpNode *next;
} ModImpNode;

s32 func_40019FF0(ModObj *obj)
{
    ModHdr *h = obj->hdr;
    ModImpNode *imp;
    u32 *idx;
    struct t_xffSymEnt *symTab;
    struct t_xffSymEnt *s;
    struct t_xffSymEnt *sym;
    t_hashedSym *hs;
    ModImpNode *node;
    ModImpNode *next;
    u32 prev;
    s32 n;
    s32 count = 0;

    n = h->unk1C;
    if (n != 0)
    {
        symTab = (struct t_xffSymEnt *)h->symTab;
        imp = (ModImpNode *)obj->imports;
        idx = h->impSymIxs;
        n--;
        for (; n != -1; n--, idx++, imp++)
        {
            sym = &symTab[*idx];
            if (sym->addr == (void *)DldSysUndefSymbol)
            {
                void *addr;

                hs = SearchStrHashKey(&D_40081A18, imp->hash);
                addr = hs ? hs->locSym->addr : NULL;
                if (hs != NULL)
                {
                    prev = imp->prev;
                    if (prev != 0)
                    {
                        next = imp->next;
                        if (prev & 0x80000000)
                        {
                            ((t_hashedSym *)(prev & 0x7FFFFFFF))->extSym = (struct t_xffSymEnt *)next;
                        }
                        else
                        {
                            ((ModImpNode *)prev)->next = next;
                        }
                        if (next != NULL)
                        {
                            next->prev = prev;
                        }
                        imp->next = NULL;
                        imp->prev = 0;
                        s = imp->sym;
                        s->unk0D = 1;
                        s->addr = (void *)DldSysUndefSymbol;
                    }
                    node = (ModImpNode *)hs->extSym;
                    imp->prev = (u32)hs | 0x80000000;
                    imp->next = node;
                    if (node != NULL)
                    {
                        node->prev = (u32)imp;
                    }
                    hs->extSym = (struct t_xffSymEnt *)imp;
                    sym->unk0D = 1;
                    sym->addr = addr;
                }
                if (sym->unk0D != 0)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

// kK24b clean single-function cut
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_40019FF0);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001A170);
void func_4001A170(ModPend *out, void *ptn, struct t_xffEntPntHdr *xff)
{
    struct t_xffRelocEnt *rel;
    struct t_xffRelocAddrEnt *ra;
    struct t_xffSymEnt *symTab;
    ModPendEnt *dst;
    s32 n;
    s32 m;
    s32 j;
    struct t_xffRelocEnt *rel2;
    struct t_xffRelocAddrEnt *ra2;
    s32 n2;
    s32 m2;

    out->count = 0;
    out->arr = NULL;
    if (xff->impSymIxsNrE != 0)
    {
        symTab = xff->symTab;
        rel = xff->relocTab;
        n = xff->relocTabNrE;
        n--;
        for (; n != -1; n--, rel++)
        {
            if (rel->type == 4 || rel->type == 9)
            {
                ra = rel->addr;
                m = rel->nrEnt;
                m--;
                for (; m != -1; m--, ra++)
                {
                    if (symTab[ra->tyIx >> 8].sect == 0)
                    {
                        out->count++;
                    }
                }
            }
        }
        out->arr = iosMallocAlign((s32)ptn, out->count << 3, 4);
        dst = out->arr;
        rel2 = xff->relocTab;
        n2 = xff->relocTabNrE;
        n2--;
        for (; n2 != -1; n2--, rel2++)
        {
            if (rel2->type == 4 || rel2->type == 9)
            {
                ra2 = rel2->addr;
                j = 0;
                m2 = rel2->nrEnt;
                m2--;
                for (; m2 != -1; m2--, ra2++, j++)
                {
                    if (symTab[ra2->tyIx >> 8].sect == 0)
                    {
                        dst->relIdx = j;
                        dst->sec = rel2;
                        dst++;
                    }
                }
            }
        }
    }
}

/* NEARMISS-STUB func_4001A2F8 */
#if 0 /* NEARMISS 94.63% cat=regalloc sub=- | kK24 best (+0.01 to outrank asm-containing stored copy) | attempts=3 */
typedef struct ModImpNode
{
    /* 0x00 */ u32 hash;
    /* 0x04 */ struct t_xffSymEnt *sym;
    /* 0x08 */ u32 prev;
    /* 0x0C */ struct ModImpNode *next;
} ModImpNode;
void func_4001A2F8(ModObj *obj)
{
    t_hashedSym *exp;
    ModImpNode *imp;
    ModImpNode *node;
    ModImpNode *next;
    u32 prev;
    s32 n;
    s32 m;
    struct t_xffSymEnt *s;
    struct t_xffSymEnt *s2;
    u32 flags;

    flags = obj->flags;
    if ((s32)flags < 0)
    {
        exp = (t_hashedSym *)obj->exp;
        if (exp != NULL)
        {
            n = flags & 0x1FFFFFFF;
            n--;
            for (; n != -1; n--, exp++)
            {
                if (exp->locSym != NULL)
                {
                    node = (ModImpNode *)exp->extSym;
                    exp->extSym = NULL;
                    if (node != NULL)
                    {
                        do
                        {
                            next = node->next;
                            s = node->sym;
                            s->unk0D = 1;
                            s->addr = (void *)DldSysUndefSymbol;
                            node->prev = 0;
                            node->next = NULL;
                            node = next;
                        } while (node != NULL);
                    }
                    DeleteStrHashKey(&D_40081A18, exp);
                }
            }
            iosFree(obj->exp);
            obj->exp = NULL;
        }
        imp = (ModImpNode *)obj->imports;
        if (imp != NULL)
        {
            m = obj->hdr->unk1C;
            m--;
            for (; m != -1; m--, imp++)
            {
                prev = imp->prev;
                next = imp->next;
                if (prev != 0)
                {
                    if (prev & 0x80000000)
                    {
                        ((t_hashedSym *)(prev & 0x7FFFFFFF))->extSym = (struct t_xffSymEnt *)next;
                    }
                    else
                    {
                        ((ModImpNode *)prev)->next = next;
                    }
                }
                if (next != NULL)
                {
                    next->prev = prev;
                }
                imp->next = NULL;
                imp->prev = 0;
                s2 = imp->sym;
                s2->unk0D = 1;
                s2->addr = (void *)DldSysUndefSymbol;
            }
            iosFree(obj->imports);
            obj->imports = NULL;
        }
        obj->flags &= 0x7FFFFFFF;
    }
}


// kK24b clean single-function cut
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001A2F8);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysMoveModuleObj);
void isysMoveModuleObj(ModObj *obj, ModHdr *xff)
{
    ModExpEnt *exp;
    ModSymEnt *sym;
    ModImpEnt *imp;
    u32 *idx;
    s32 adj;
    s32 n;
    ModSymEnt *tab;

    func_40019D68(xff, obj, obj->unk0[0], func_4001C3B0, func_4001C440, DldSysUndefSymbol, func_400199B0, 0);
    obj->entry = xff->unk10;
    obj->flags = obj->flags & 0xDFFFFFFF;
    obj->hdr = xff;
    if ((s32)obj->flags < 0)
    {
        exp = obj->exp;
        if (exp != NULL)
        {
            if (((u8 *)xff)[0xC] != 0)
            {
                adj = ((u8 *)xff)[0xC] + 1;
            }
            else
            {
                adj = 2;
            }
            sym = xff->symTab + adj;
            adj = xff->unk24 - adj;
            adj--;
            for (; adj != -1; adj--, sym++)
            {
                if (sym->sect != 0)
                {
                    if (exp->sym != NULL)
                    {
                        exp->sym = sym;
                    }
                    exp++;
                }
            }
        }
        tab = xff->symTab;
        imp = obj->imports;
        idx = xff->impSymIxs;
        n = xff->unk1C;
        n--;
        for (; n != -1; n--)
        {
            imp->sym = (void *)((char *)tab + (*idx << 4));
            idx++;
            imp++;
        }
    }
}
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysCreateModuleObjExisted);

s32 isysResolveAllModuleObjHasUndefSymbol(void)
{
    ModObj *obj = NULL;
    isysLink *link;
    s32 ret;

    iosGetTCount();
    link = isysGroupForFirst(needResolveModuleGroup, 0);
    while (link != NULL)
    {
        obj = link->obj;
        iosResetCpuRapCounter(2);
        ret = func_40019FF0(obj);
        iosGetCpuRapCountPar1Int();
        if (obj->flags & 0x20000000)
        {
            if (ret != 0)
            {
                func_40019A00(obj, 0);
            }
        }
        else
        {
            func_40019A00(obj, 1);
            obj->flags |= 0x20000000;
        }
        iosGetCpuRapCountPar1Int();

        link = isysGroupForNext(link, 0);
    }
    if (obj != NULL)
    {
        isysGroupForExit(obj, 0);
    }
    return 1;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001A918);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001AB68);

/* NEARMISS-STUB func_4001AD58 */
#if 0 /* NEARMISS 97.0% cat=regalloc sub=- | REA near-miss | attempts=2 */
ModObj *func_4001AD58(char *name, s32 fileSize, s32 parentPtn)
{
    s32 before = D_40045820;
    ModHdr *h = iosMallocAlign(&rootPtn, fileSize, 0x40);
    s32 adj;
    s32 nExp;
    s32 extra;
    s32 total;
    ModObj *obj;

    func_4001C350((s32)h, name, fileSize);
    adj = *(u8 *)&h->unkC != 0 ? *(u8 *)&h->unkC + 1 : 2;
    adj = h->unk24 - h->unk1C - adj;
    extra = 0;
    if (adj != 0)
        extra = adj * 16 + 0x33;
    if (h->unk1C != 0)
        total = extra + h->unk1C * 16 + 0x33;
    else
        total = extra;
    obj = _isysCreateObj(parentPtn, 2, 0x40, strlen(name) + total + 1, func_4001C5E8, 4);
    func_4001AB68(obj, name, h);
    D_40045820 += fileSize;
    obj->allocSize = D_40045820 - before;
    return obj;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001AD58);
/* NEARMISS-STUB func_4001AE88 */
#if 0 /* NEARMISS 85.28% cat=branch-layout sub=- | movn if-conversion | attempts=1 */
/* decls needed: extern ModObj *func_4001AE88(char *name, ModHdr *hdr, void *ptn); extern char *D_40045824; extern void func_40019B58(ModObj *obj, s32 arg1); extern void isysAddGroupWithLinkParam(); */
ModObj *func_4001AE88(char *name, ModHdr *hdr, void *ptn)
{
    ModObj *obj;
    s32 n;
    s32 size;
    s32 t;

    t = *(u8 *)&hdr->unkC;
    if (t == 0)
    {
        t = 2;
    }
    else
    {
        t = t + 1;
    }
    size = hdr->unk24 - hdr->unk1C - t;
    if (size != 0)
    {
        size = (size << 4) + 0x33;
    }
    else
    {
        size = 0;
    }
    if (hdr->unk1C != 0)
    {
        size = size + (hdr->unk1C << 4) + 0x33;
    }
    n = strlen(name);
    obj = _isysCreateObj((s32)ptn, 2, 0x40, n + size + 1, NULL, 4);
    obj->entry = hdr->unk10;
    obj->flags &= 0x7FFFFFFF;
    obj->hdr = hdr;
    obj->flags &= 0xBFFFFFFF;
    obj->flags &= 0xDFFFFFFF;
    if (hdr->unk24 != 0)
    {
        isysAddGroupWithLinkParam(obj, symbolDefModuleGroup, 0, 0);
    }
    if (hdr->unk1C != 0)
    {
        isysAddGroupWithLinkParam(obj, needResolveModuleGroup, 0, 0);
    }
    func_40019B58(obj, obj->unk0[0]);
    func_4001A170((ModPend *)&obj->pendCount, &rootPtn, (struct t_xffEntPntHdr *)hdr);
    if (name != NULL)
    {
        n = strlen(name);
        obj->name = iosMallocAlign(obj->unk0[0], n + 1, 1);
        strcpy(obj->name, name);
    }
    else
    {
        obj->name = D_40045824;
    }
    isysAddGroupWithLinkParam(obj, executableModuleGroup, 0, 0);
    obj->allocSize = 0;
    return obj;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001AE88);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysLaunchModule);
void isysLaunchModule(ModObj *obj)
{
    char buf[0x400];
    ModObj *cur = NULL;
    isysLink *link;
    ModHdr *hdr;
    ModHdr *h2;
    struct t_xffRelocEnt *rel;
    struct t_xffRelocEnt *rel2;
    u32 *p;
    s32 freed;
    s32 ret;
    s32 n;
    s32 sum;
    s32 i;

    link = isysGroupForFirst(needResolveModuleGroup, 0);
    while (link != NULL)
    {
        cur = link->obj;
        iosResetCpuRapCounter(2);
        ret = func_40019FF0(cur);
        iosGetCpuRapCountPar1Int();
        if (cur->flags & 0x20000000)
        {
            if (ret != 0)
            {
                func_40019A00(cur, 0);
            }
        }
        else
        {
            func_40019A00(cur, 1);
            cur->flags |= 0x20000000;
        }
        iosGetCpuRapCountPar1Int();
        link = isysGroupForNext(link, 0);
    }
    if (cur != NULL)
    {
        isysGroupForExit(cur, 0);
    }
    hdr = obj->hdr;
    iosSPrintf(buf, D_40047060, obj->name);
    OutputLinkerScriptFile(hdr, buf, printf);
    freed = 0;
    h2 = obj->hdr;
    if (h2->unk0 == D_40045828)
    {
        n = h2->relocNrE >> 1;
        sum = 0;
        if (n > 0)
        {
            rel = h2->relocTab;
            p = &rel->nrEnt;
            for (i = n; i != 0; i--)
            {
                sum += *p;
                p += 7;
            }
        }
        func_4001C8F0(h2, h2->relocTab[0].addr + sum, 0);
        for (i = 0; i < n; i++)
        {
            h2->relocTab[n + i].nrEnt = 0;
        }
        freed = h2->unk14 - ((u32)h2->relocTab[n].addr - (u32)h2);
    }
    obj->allocSize -= freed;
    D_40045820 -= freed;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", IosCdvdManagerSimulation);

/* NEARMISS-STUB isysGetXffEntryPointPreRelocation */
#if 0 /* NEARMISS 82.01% cat=branch-layout sub=- | switch tree (single-function cut) | attempts=3 */
void *isysGetXffEntryPointPreRelocation(ModHdr *xff)
{
    ModPartEnt *ent;
    s32 i;

    xff->table = (u8 *)xff + xff->secTabOff;
    ent = (ModPartEnt *)(xff->table + 0x20);
    i = 1;
    if (i < xff->symBase)
    {
        do
        {
            ent->unk4[0] = (u32)xff + ent->unk1C;
            if (ent->unk4[1] != 0)
            {
                switch (ent->unk4[3])
                {
                case 8:
                    iosJumpRecoverPoint(D_40046FC0, ent->unk4[2]);
                    break;
                case 0x7FFFF420:
                case 1:
                    if (ent->unk4[4] != 0)
                    {
                        iosJumpRecoverPoint(D_40046EF8);
                    }
                    else if ((ent->unk4[0] & (ent->unk4[2] - 1)) == 0)
                    {
                        return (void *)(ent->unk4[0] + xff->entryOff);
                    }
                    else
                    {
                        iosJumpRecoverPoint(D_40046F58, ent->unk4[2]);
                    }
                    break;
                }
            }
            i++;
            ent++;
        } while (i < xff->symBase);
    }
    return NULL;
}// kK24b clean single-function cut
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysGetXffEntryPointPreRelocation);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", InitDld);
void InitDld(void)
{
    iosCdInit();
    InitStrHash(&D_40081A18, &rootPtn, 0x10000);
    isysInitGroup(executableModuleGroup);
    isysInitGroup(needResolveModuleGroup);
    isysInitGroup(symbolDefModuleGroup);
    LoaderSysGetMemoryInfo(&D_400819B0);
    func_4001AE88(D_400819B0.module_info.path, D_400819B0.module_info.unk44, &rootPtn);
    isysCreateExceptionThread();
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", IosLoadIrxSimulation);
void IosLoadIrxSimulation(void)
{
    iosLoadIopModule(D_40047068, D_40047088, 0, 0);
    iosLoadIopModule(D_40047090, D_400470A8, 0, 0);
    iosLoadIopModule(D_400470B8, D_400470D8, 0, 0);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", IosGetMergeDataFileName);
char *IosGetMergeDataFileName(void)
{
    return D_40047138;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysSearchSymbol);
s32 isysSearchSymbol(u32 *arg0, u32 arg1)
{
    t_hashedSym *entry;

    if (arg1 == 0)
    {
        *arg0 = 0;
        return 1;
    }
    entry = SearchStrHashKey(&D_40081A18, arg1);
    if (entry != NULL)
    {
        *arg0 = (u32)entry->locSym->addr;
    }
    return entry != NULL;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysSearchModuleFuncNameByAddr);
s32 isysSearchModuleFuncNameByAddr(char *buf, char *out, u32 addr)
{
    isysLink *link;
    char *name;
    ModObj *obj = NULL;
    ModHdr *hdr;
    u32 strTab;
    ModSymEnt *sym;
    s32 i;
    s32 ret = 0;

    link = isysGroupForFirst(executableModuleGroup, 0);
    if (link != NULL)
    {
        do
        {
            obj = link->obj;
            hdr = obj->hdr;
            strTab = hdr->strTab;
            sym = hdr->symTab;
            i = hdr->unk24 - 2;
            if (i != -1)
            {
                do
                {
                    if (sym->sect != 0xFFF1 && (*(u8 *)&sym->unkC & 0xF) == 2)
                    {
                        if (sym->unk4 == addr)
                        {
                            name = (char *)(strTab + sym->nameOff);
                            goto found;
                        }
                    }
                    i--;
                    sym++;
                } while (i != -1);
            }
            name = NULL;
        found:
            if (name != NULL)
            {
                if (buf != NULL)
                {
                    strcpy(buf, obj->name);
                }
                if (out != NULL)
                {
                    strcpy(out, name);
                }
                ret = 1;
                break;
            }
            link = isysGroupForNext(link, 0);
        } while (link != NULL);
    }
    if (obj != NULL)
    {
        isysGroupForExit(obj, 0);
    }
    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysDumpExecutableModules);
void isysDumpExecutableModules(void)
{
    void *obj = NULL;
    isysLink *link = isysGroupForFirst(executableModuleGroup, 0);

    while (link != NULL)
    {
        obj = link->obj;
        link = isysGroupForNext(link, 0);
    }
    if (obj != NULL)
    {
        isysGroupForExit(obj, 0);
    }
}

/* NEARMISS-STUB isysSearchModuleSymbolByGroup */
#if 0 /* NEARMISS 83.39% cat=regalloc sub=- | spill | attempts=1 */
ModObj *isysSearchModuleSymbolByGroup(u32 *out, char *name, u16 *group, ModObj *exclude)
{
    isysLink *link;
    ModObj *obj = NULL;
    ModObj *ret = NULL;
    ModHdr *hdr;
    u32 strTab;
    ModSymEnt *sym;
    t_hashedSym *entry;
    u32 hash;
    s32 i;
    s32 found;

    link = isysGroupForFirst(group, 0);
    if (link != NULL)
    {
        do
        {
            obj = link->obj;
            if (obj != exclude)
            {
                hash = MakeStrHashValue(name);
                found = 0;
                if (obj->flags & 0x80000000)
                {
                    entry = SearchStrHashKey(&D_40081A18, hash);
                    if (entry != NULL)
                    {
                        *out = (u32)entry->locSym->addr;
                        found = 1;
                    }
                }
                else
                {
                    hdr = obj->hdr;
                    strTab = hdr->strTab;
                    sym = hdr->symTab;
                    i = hdr->unk24 - 2;
                    if (i != -1)
                    {
                        do
                        {
                            if (sym->sect != 0 && strcmp((char *)(strTab + sym->nameOff), name) == 0)
                            {
                                *out = sym->unk4;
                                found = 1;
                                break;
                            }
                            i--;
                        } while (i != -1);
                    }
                }
                if (found)
                {
                    ret = obj;
                    break;
                }
            }
            link = isysGroupForNext(link, 0);
        } while (link != NULL);
    }
    if (obj != NULL)
    {
        isysGroupForExit(obj, 0);
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysSearchModuleSymbolByGroup);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysRemoveModuleObjGroup);
void isysRemoveModuleObjGroup(ModObj *obj)
{
    if (obj->hdr->unk24)
    {
        _isysDeleteGroup(obj, &symbolDefModuleGroup, 0);
    }
    if (obj->hdr->unk1C)
    {
        _isysDeleteGroup(obj, &needResolveModuleGroup, 0);
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysResolveOneModuleObj);
s32 isysResolveOneModuleObj(ModObj *arg0)
{
    s32 ret;

    iosResetCpuRapCounter(2);
    ret = func_40019FF0(arg0);
    iosGetCpuRapCountPar1Int();
    if (arg0->flags & 0x20000000)
    {
        if (ret != 0)
        {
            func_40019A00(arg0, 0);
        }
    }
    else
    {
        func_40019A00(arg0, 1);
        arg0->flags |= 0x20000000;
    }
    iosGetCpuRapCountPar1Int();
    return ret;
}

s32 isysResolveAllProgramModule(void)
{
    ModObj *obj = NULL;
    isysLink *link;
    s32 ret;

    iosGetTCount();
    link = isysGroupForFirst(executableModuleGroup, 0);
    while (link != NULL)
    {
        obj = link->obj;
        iosResetCpuRapCounter(2);
        ret = func_40019FF0(obj);
        iosGetCpuRapCountPar1Int();
        if (obj->flags & 0x20000000)
        {
            if (ret != 0)
            {
                func_40019A00(obj, 0);
            }
        }
        else
        {
            func_40019A00(obj, 1);
            obj->flags |= 0x20000000;
        }
        iosGetCpuRapCountPar1Int();
        link = isysGroupForNext(link, 0);
    }
    if (obj != NULL)
    {
        isysGroupForExit(obj, 0);
    }
    return 1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysLaunchExecModule);
void isysLaunchExecModule(ModObj *obj)
{
    void (*entry)(void *);
    ModHdr *hdr;

    isysLaunchModule(obj);
    hdr = obj->hdr;
    entry = hdr->unk10;
    FlushCache(0);
    FlushCache(2);
    entry(obj);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysInitModuleObjExisted);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysFlushModuleObj);
s32 isysFlushModuleObj(ModObj *obj)
{
    ModPartEnt *ent;
    ModHdr *hdr;
    s32 i;
    if (obj->flags & 0x40000000)
    {
        iosFree((void *)obj->hdr->unk4);
        func_4001A2F8(obj);
    }
    else
    {
        u32 *pend = &obj->pendCount;

        if (pend[1] != 0)
        {
            iosFree((void *)pend[1]);
            pend[0] = 0;
        }
        func_4001A2F8(obj);
        hdr = obj->hdr;
        if (hdr != NULL)
        {
            ent = (ModPartEnt *)(hdr->table + 0x20);
            for (i = hdr->symBase - 2; i != -1; i--)
            {
                if (ent->ptr18 != NULL)
                {
                    ent->ptr18 = NULL;
                    iosFree(ent->ptr);
                }
                ent++;
            }
            iosFree(hdr);
        }
    }
    return 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", GetSymbolByIndex);
u32 GetSymbolByIndex(ModObj *arg0, s32 idx)
{
    ModHdr *h = arg0->hdr;
    return h->strTab + h->symTab[idx + h->symBase].nameOff;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysRelocateModuleObj);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysGetXffWorkSize);
s32 isysGetXffWorkSize(ModHdr *h)
{
    s32 adj = *(u8 *)&h->unkC != 0 ? *(u8 *)&h->unkC + 1 : 2;
    s32 nExp = h->unk24 - h->unk1C - adj;
    s32 sz;

    sz = nExp != 0 ? nExp * 16 + 0x33 : 0;
    if (h->unk1C != 0)
    {
        sz += h->unk1C * 16 + 0x33;
    }
    return sz;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysGetModuleObjMallocSize);
u32 isysGetModuleObjMallocSize(ModObj *arg0)
{
    u32 *p;
    if (arg0->flags & 0x40000000)
    {
        p = (u32 *)arg0->hdr->unk4 - 1;
    }
    else
    {
        p = (u32 *)arg0->hdr - 1;
    }
    return (*(u32 *)*p & 0xFFFFFF) << 2;
}

/* NEARMISS-STUB isysDisposeModuleObjRelocationElement */
#if 0 /* NEARMISS 99.3% cat=regalloc sub=- | REA near-miss; tail rel2+sum ordering | attempts=2 */
s32 isysDisposeModuleObjRelocationElement(ModObj *obj)
{
    ModHdr *hdr = obj->hdr;
    struct t_xffRelocEnt *rel;
    struct t_xffRelocEnt *rel2;
    s32 n;
    s32 sum;
    s32 i;
    u32 *p;

    if (hdr->unk0 != D_40045828)
    {
        return 0;
    }
    n = hdr->relocNrE >> 1;
    sum = 0;
    if (n > 0)
    {
        rel = hdr->relocTab;
        p = &rel->nrEnt;
        for (i = n; i != 0; i--)
        {
            sum += *p;
            p += 7;
        }
    }
    func_4001C8F0(hdr, hdr->relocTab[0].addr + sum, 0);
    for (i = 0; i < n; i++)
    {
        hdr->relocTab[n + i].nrEnt = 0;
    }
    rel2 = &hdr->relocTab[n];
    sum = hdr->unk14;
    return sum - ((u32)rel2->addr - (u32)hdr);
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysDisposeModuleObjRelocationElement);



//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", GetExecModuleSize);
s32 GetExecModuleSize(void)
{
    return D_40045820;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", getModuleSize);
s32 getModuleSize(ModObj *arg0)
{
    return arg0->hdr->unk14;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C220);
void *func_4001C220(s32 arg0, s32 arg1)
{
    return iosMallocAlign(D_40081A20, arg0, arg1);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C248);
void *func_4001C248(s32 arg0)
{
    return iosMallocAlign(D_40081A20, arg0, 0x10);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysGetUndefModuleObjNum);
s32 isysGetUndefModuleObjNum(void)
{
    s32 count = 0;
    void *obj = NULL;
    isysLink *link = isysGroupForFirst(needResolveModuleGroup, 0);

    while (link != NULL)
    {
        obj = link->obj;
        link = isysGroupForNext(link, 0);
        count++;
    }
    if (obj != NULL)
    {
        isysGroupForExit(obj, 0);
    }
    return count;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysGetSymdefModuleObjNum);
s32 isysGetSymdefModuleObjNum(void)
{
    s32 count = 0;
    void *obj = NULL;
    isysLink *link = isysGroupForFirst(symbolDefModuleGroup, 0);

    while (link != NULL)
    {
        obj = link->obj;
        link = isysGroupForNext(link, 0);
        count++;
    }
    if (obj != NULL)
    {
        isysGroupForExit(obj, 0);
    }
    return count;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C350);
s32 func_4001C350(s32 arg0, char *arg1, s32 arg2)
{
    s32 fd = iosLoaderFOpen(arg1, 1, 0);
    iosLoaderFRead(fd, (void *)arg0, arg2);
    return iosLoaderFClose(fd);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C3B0);
void *func_4001C3B0(s32 arg0, s32 arg1)
{
    void *p = iosMallocAlign((s32)&rootPtn, arg0, arg1);
    D_40045820 += arg0;
    return p;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C3F8);
void *func_4001C3F8(s32 arg0)
{
    void *p = iosMallocAlign((s32)&rootPtn, arg0, 0x40);
    D_40045820 += arg0;
    return p;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C440);
s32 func_4001C440(void)
{
    iosJumpRecoverPoint(D_40046EC0);
    return 0;
}

typedef struct ModPartObj
{
    /* 0x00 */ u32 unk0[12];
    /* 0x30 */ u8 *table;
    /* 0x34 */ u32 unk34[3];
    /* 0x40 */ s32 count;
} ModPartObj;

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C468);
void *func_4001C468(ModPartObj *arg0)
{
    ModPartEnt *ent;
    s32 i;

    if (arg0 != NULL)
    {
        ent = (ModPartEnt *)(arg0->table + 0x20);
        for (i = arg0->count - 2; i != -1; i--)
        {
            if (ent->ptr18 != NULL)
            {
                ent->ptr18 = NULL;
                iosFree(ent->ptr);
            }
            ent++;
        }
        iosFree(arg0);
    }
    return arg0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C4F8);
void func_4001C4F8(ModObj *obj)
{
    ModPartEnt *ent;
    ModHdr *hdr;
    s32 i;

    if (obj->flags & 0x40000000)
    {
        iosFree((void *)obj->hdr->unk4);
        func_4001A2F8(obj);
        return;
    }
    {
        u32 *pend = &obj->pendCount;

        if (pend[1] != 0)
        {
            iosFree((void *)pend[1]);
            pend[0] = 0;
        }
    }
    func_4001A2F8(obj);
    hdr = obj->hdr;
    if (hdr != NULL)
    {
        ent = (ModPartEnt *)(hdr->table + 0x20);
        for (i = hdr->symBase - 2; i != -1; i--)
        {
            if (ent->ptr18 != NULL)
            {
                ent->ptr18 = NULL;
                iosFree(ent->ptr);
            }
            ent++;
        }
        iosFree(hdr);
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C5E8);
void func_4001C5E8(ModObj *obj)
{
    ModPartEnt *ent;
    ModHdr *hdr;
    s32 i;

    if (obj->flags & 0x40000000)
    {
        iosFree((void *)obj->hdr->unk4);
        func_4001A2F8(obj);
    }
    else
    {
        u32 *pend = &obj->pendCount;

        if (pend[1] != 0)
        {
            iosFree((void *)pend[1]);
            pend[0] = 0;
        }
        func_4001A2F8(obj);
        hdr = obj->hdr;
        if (hdr != NULL)
        {
            ent = (ModPartEnt *)(hdr->table + 0x20);
            for (i = hdr->symBase - 2; i != -1; i--)
            {
                if (ent->ptr18 != NULL)
                {
                    ent->ptr18 = NULL;
                    iosFree(ent->ptr);
                }
                ent++;
            }
            iosFree(hdr);
        }
    }
    D_40045820 -= obj->allocSize;
}

s32 isysResolveAllModuleObjOfGroup(u16 *group)
{
    s32 count = 0;
    ModObj *obj = NULL;
    isysLink *link;
    s32 ret;

    link = isysGroupForFirst(group, 0);
    while (link != NULL)
    {
        obj = link->obj;
        iosResetCpuRapCounter(2);
        ret = func_40019FF0(obj);
        iosGetCpuRapCountPar1Int();
        if (obj->flags & 0x20000000)
        {
            if (ret != 0)
            {
                func_40019A00(obj, 0);
            }
        }
        else
        {
            func_40019A00(obj, 1);
            obj->flags |= 0x20000000;
        }
        iosGetCpuRapCountPar1Int();
        count++;
        link = isysGroupForNext(link, 0);
    }
    if (obj != NULL)
    {
        isysGroupForExit(obj, 0);
    }
    return count;
}

/* NEARMISS-STUB readEModule */
#if 0 /* NEARMISS 97.3% cat=regalloc sub=- | s2/s3 swap, cdrom-arm size check merged into join | attempts=2 */
ModObj *readEModule(char *name, s32 parentPtn)
{
    CdlFile cdfile;
    ModObj *r = NULL;
    char *file;
    s32 size;
    s32 t;

    if (strncmp(name, D_40047058, 7) == 0)
    {
        file = strstr(name, D_40047028) + 1;
        if (sceCdSearchFile(&cdfile, file) == 0)
        {
            iosJumpRecoverPoint(D_40047030, file);
        }
        if (cdfile.size < 0)
            goto done;
        size = cdfile.size;
    }
    else
    {
        t = iosLoaderGetFileSizeName(name);
        if (t < 0)
            goto done;
        size = t;
    }
    r = func_4001AD58(name, size, parentPtn);
done:
    return r;
}
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", readEModule);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysWriteLinkerScriptFile);
s32 isysWriteLinkerScriptFile(ModObj *obj)
{
    char buf[0x400];
    ModHdr *hdr = obj->hdr;

    iosSPrintf(buf, D_40047060, obj->name);
    return OutputLinkerScriptFile(hdr, buf, printf);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C8F0);
void func_4001C8F0(void *arg0, void *arg1)
{
    iosFreeParts(arg0, arg1, 0);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", loadtest);
s32 loadtest(char *arg0, s32 arg1)
{
    s32 ret = 0;
    s32 size = iosLoaderGetFileSizeName(arg0);

    if (size >= 0)
    {
        ret = func_4001AD58(arg0, size, arg1);
    }
    return ret;
}

/* NEARMISS-STUB iosLoaderGetFileSizeName */
#if 0 /* NEARMISS 67.81% cat=regalloc sub=- | break-0 line removed in stub (+0.01 as above) | attempts=3 */
s32 iosLoaderGetFileSizeName(char *name)
{
    s32 fd;
    s32 i;
    s32 key;
    s32 size;
    DldSlot *slot;
    s32 stat[16];

    fd = LoaderSysFOpen(name, 1, 0);
    if (fd < 0)
    {
        return -1;
    }
    key = -1;
    for (i = 0; i < 8; i++)
    {
        if (D_40081A28[i].unk0 == key)
        {
            goto found;
        }
    }
    slot = NULL;
    goto store;
found:
    slot = &D_40081A28[i];
store:
    slot->unk0 = fd;
    LoaderSysGetstat(name, (void *)stat);
    slot->unk4 = stat[2];
    slot = NULL;
    for (i = 0; i < 8; i++)
    {
        if (D_40081A28[i].unk0 == fd)
        {
            slot = &D_40081A28[i];
            break;
        }
    }
    size = 0;
    if (slot != NULL)
    {
        size = slot->unk4;
    }
    LoaderSysFClose(fd);
    for (i = 0; i < 8; i++)
    {
        if (D_40081A28[i].unk0 == fd)
        {
            D_40081A28[i].unk0 = -1;
            return size;
        }
    }
    return size;
}
// kK24b clean single-function cut
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", iosLoaderGetFileSizeName);

/* NEARMISS-STUB iosFileRead */
#if 0 /* NEARMISS 91.32% cat=regalloc sub=- | break-0 line removed in stub; alloc differs (+0.01 as above) | attempts=3 */
s32 iosFileRead(char *name, void *buf, s32 count)
{
    s32 size;
    s32 fd;
    DldSlot *slot;
    s32 i;
    s32 key;
    s32 stat[16];

    size = iosLoaderGetFileSizeName(name);
    fd = LoaderSysFOpen(name, 1, 0);
    if (fd < 0)
    {
        return -1;
    }
    key = -1;
    for (i = 0; i < 8; i++)
    {
        if (D_40081A28[i].unk0 == key)
        {
            goto found;
        }
    }
    slot = NULL;
    goto store;
found:
    slot = &D_40081A28[i];
store:
    slot->unk0 = fd;
    LoaderSysGetstat(name, (void *)stat);
    slot->unk4 = stat[2];
    if (fd >= 0)
    {
        if (count >= size)
        {
            LoaderSysFRead(fd, buf, size);
        }
        else
        {
            LoaderSysFRead(fd, buf, count);
        }
        LoaderSysFClose(fd);
        for (i = 0; i < 8; i++)
        {
            if (D_40081A28[i].unk0 == fd)
            {
                slot = &D_40081A28[i];
                goto found2;
            }
        }
        goto end;
    found2:
        slot->unk0 = -1;
    end:
        return size;
    }
    else
    {
        return -1;
    }
}
// kK24b clean single-function cut
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", iosFileRead);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", iosLoaderFOpen);
s32 iosLoaderFOpen(char *name, s32 flags, s32 mode)
{
    s32 fd;
    s32 i;
    s32 key;
    DldSlot *slot;
    s32 stat[16];

    fd = LoaderSysFOpen(name, flags, mode);
    if (fd < 0)
    {
        return fd;
    }
    key = -1;
    for (i = 0; i < 8; i++)
    {
        if (D_40081A28[i].unk0 == key)
        {
            goto found;
        }
    }
    slot = NULL;
    goto store;
found:
    slot = &D_40081A28[i];
store:
    slot->unk0 = fd;
    LoaderSysGetstat(name, (void *)stat);
    slot->unk4 = stat[2];
    return fd;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", iosLoaderFClose);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", iosLoaderFRead);
s32 iosLoaderFRead(s32 fd, void *buf, s32 count)
{
    return LoaderSysFRead(fd, buf, count);
}

s32 iosLoaderGetFileSize(s32 fd)
{
    s32 i;
    DldSlot *slot;

    for (i = 0; i < 8; i++)
    {
        if (D_40081A28[i].unk0 == fd)
        {
            goto found;
        }
    }
    slot = NULL;
    goto end;
found:
    slot = &D_40081A28[i];
end:
    return slot ? slot->unk4 : 0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", initDldSys);
void initDldSys(void)
{
    s32 i;
    for (i = 0; i < 8; i++)
    {
        D_40081A28[i].unk0 = -1;
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001CDD8);

void func_4001CFE0(s32 arg0)
{
    char buf0[0x100];
    char buf1[0x100];
    s32 ret = 0;
    ModObj *obj = NULL;
    isysLink *link;
    s32 r;
    char *p0 = buf0;

    link = isysGroupForFirst(executableModuleGroup, 0);
    while (link != NULL)
    {
        obj = link->obj;
        r = func_4001CDD8(p0, buf1, obj, arg0);
        if (r != 0)
        {
            ret = r;
            break;
        }
        link = isysGroupForNext(link, 0);
    }
    if (obj != NULL)
    {
        isysGroupForExit(obj, 0);
    }
    if (ret != 0)
    {
        if (ret == 2)
        {
            LoaderSysPrintf(D_40047170, arg0);
            LoaderSysPrintf(D_400471C0);
            LoaderSysPrintf(D_40047220);
            LoaderSysPrintf(D_40047270, arg0);
            LoaderSysPrintf(D_400472C8, arg0, arg0);
        }
        iosJumpRecoverPoint(D_40047308, arg0, buf0, buf1);
    }
    else
    {
        iosJumpRecoverPoint(D_40047388, arg0);
    }
}

/* NEARMISS-STUB func_4001D120 */
#if 0 /* NEARMISS 81.93% cat=regalloc sub=- | offset IV, 5 s-regs (+0.01 as above) | attempts=3 */
s32 func_4001D120(s32 arg0)
{
    isysLink *link;
    ModObj *obj = NULL;
    ModHdr *hdr;
    struct t_xffRelocEnt *rel;
    struct t_xffRelocEnt *ent;
    struct t_xffRelocAddrEnt *addr;
    ModSymEnt *sym;
    s32 ret = 0;
    s32 j;

    link = isysGroupForFirst(symbolDefModuleGroup, 0);
    if (link != NULL)
    {
        do
        {
            obj = link->obj;
            hdr = obj->hdr;
            rel = hdr->relocTab;
            for (ret = 0; ret < hdr->relocNrE; ret++, rel++)
            {
                if (rel->type != 4 && rel->type != 9)
                {
                    continue;
                }
                if (rel->nrEnt == 0)
                {
                    continue;
                }
                ent = &hdr->relocTab[ret];
                for (j = 0; j < ent->nrEnt; j++)
                {
                    addr = &ent->addr[j];
                    sym = &hdr->symTab[addr->tyIx >> 8];
                    if (sym->sect == 0 && (u32)((ModPartEnt *)hdr->table)[ent->sect].ptr + addr->addr == arg0)
                    {
                        ret = hdr->strTab + sym->nameOff;
                        goto check;
                    }
                }
            }
            ret = 0;
check:
            if (ret != 0)
            {
                break;
            }
            link = isysGroupForNext(link, 0);
        } while (link != NULL);
    }
    if (obj != NULL)
    {
        isysGroupForExit(obj, 0);
    }
    return ret;
}
// kK24b clean single-function cut
#endif
INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001D120);

void DldExceptionByOriginAdr(s32 arg0)
{
    s32 ret = func_4001D120(arg0);

    if (ret != 0)
    {
        iosJumpRecoverPoint(D_40047400, ret, arg0);
    }
    else
    {
        iosJumpRecoverPoint(D_400474A8, arg0);
    }
}

s32 isysSearchCalledModuleFuncNameByAddr(char *a0, char *a1, s32 a2)
{
    s32 ret = 0;
    ModObj *obj = NULL;
    isysLink *link;
    s32 r;

    link = isysGroupForFirst(executableModuleGroup, 0);
    while (link != NULL)
    {
        obj = link->obj;
        r = func_4001CDD8(a0, a1, obj, a2);
        if (r != 0)
        {
            ret = r;
            break;
        }
        link = isysGroupForNext(link, 0);
    }
    if (obj != NULL)
    {
        isysGroupForExit(obj, 0);
    }
    return ret;
}

void isysCreateExceptionThread(void)
{}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001D3A8);

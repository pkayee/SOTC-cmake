#include "common.h"

extern int iosCdStRead();
extern int iosCdStSkip();
extern int iosCdStSectorAlignSkip();
extern int IosGetMergeDataFileName();
extern void iosCdStInit(int);
extern void iosCdStStart(int);
extern void iosCdStStop(void);
extern void func_400EC808();

typedef struct {
    int offset;
    int size;
} FileEntry;

extern FileEntry *D_401B538C;

extern int D_401B534C;

typedef struct { char *name; int a, b; } SpecialFs;
typedef struct { int n; SpecialFs *tab; } SpecialFsTab;
extern SpecialFsTab D_401B5390;
extern int strcmp(const char *, const char *);

void sheetFsLoadDirectFile(int i, int off, char *dst, int size)
{
    FileEntry *f = &D_401B538C[i];
    int sec = off / 0x800;
    int rem = off % 0x800;
    iosCdStStart(f->offset + sec);
    if (rem != 0) {
        char buf[rem];

        iosCdStRead(buf, rem);
    }
    iosCdStRead(dst, size);
    iosCdStStop();
}


void sheetFsInit(void)
{
    iosCdStInit(IosGetMergeDataFileName());
    func_400EC808();
}

typedef struct { int a, b, seg; } Seg;
extern char *D_401B5350;

int sheetFsGetStageTexSegIndex(int x, int y)
{
    return (*(Seg **)(D_401B5350 + 8))[(4 - y) * 10 + (x + 5) % 10].seg;
}

typedef struct { int idx, b; } SegIdx;
extern SegIdx *D_401B5348;

int sheetFsAddStageTexSegIndex(int i)
{
    int r = D_401B5348[i].idx;

    D_401B5348[i].idx = r + 1;
    return r;
}

int sheetFsDecStageTexSegIndex(int i)
{
    return --D_401B5348[i].idx;
}

void sheetFsExistTexSegIndexCallBack(void (*cb)(int))
{
    int i;

    for (i = 0; i < D_401B534C; i++) {
        if (D_401B5348[i].idx != 0) {
            cb(i);
            D_401B5348[i].idx = 0;
        }
    }
}

void sheetFsSetStageTexSegTexSegDef(int arg0, int arg1)
{
    D_401B5348[arg0].b = arg1;
}

int sheetFsGetStageTexSegTexSegDef(int arg0)
{
    return D_401B5348[arg0].b;
}

int sheetFsDataRead(int a, int b, int c, int d)
{
    return iosCdStRead(b, c, c, d);
}

int sheetFsSkipRead(int a, int b, int c, int d)
{
    return iosCdStSkip(b, b, c, d);
}

int sheetFsSectorAlignSkip(int a, int b, int c, int d)
{
    return iosCdStSectorAlignSkip(a, b, c, d);
}

extern int D_401B5358;

void sheetFsLoadBootData(void (*cb)(int, int))
{
    iosCdStStart(D_401B5358);
    cb(0, 0);
    iosCdStStop();
}

extern int D_401B5360;

void sheetFsLoadRootSegment(void (*cb)(int, int))
{
    iosCdStStart(D_401B5360);
    cb(0, 0);
    iosCdStStop();
}

typedef struct { char c[6]; } Str6;
typedef struct { char *name; int a; short *idx; int c; int d; int *tabA; int *tabB; } SegIdxDef;
extern Str6 D_40134FF0;
extern char D_40134FF8[];
extern int D_4012E324;
extern int D_401B5368;
extern SegIdxDef *D_401B5370;
extern int sheetFsLanguageCode;
extern int strcmp(const char *, const char *);
extern void iosJumpRecoverPoint();
extern void iosCdStStart(int);
extern void iosCdStStop(void);
extern int func_400ED988();

void sheetFsLoadSegmentIndex(char *name, int unused, int idx, void (*cb)(int, int))
{
    int off = -1;
    SegIdxDef *e;
    int i;
    short v;

    if (D_4012E324 != 0) {
        char key[8];
        Str6 str = D_40134FF0;

        *(short *)(key + 4) = idx;
        if (strcmp((char *)&str, name) == 0) {
            key[0] = 0;
        } else {
            key[0] = 1;
        }
        off = func_400ED988(D_4012E324, key);
    }
    if (off < 0) {
        e = 0;
        for (i = 0; i < D_401B5368; i++) {
            e = &D_401B5370[i];
            if (strcmp(name, e->name) == 0) {
                goto found;
            }
        }
        iosJumpRecoverPoint(D_40134FF8, name);
found:
        v = e->idx[idx];
        if ((v & 0x8000) == 0) {
            off = e->tabA[v * 2];
        } else {
            v &= 0x7FFF; off = (e->tabB + (sheetFsLanguageCode - 1) * 2)[v * 2];
        }
    }
    iosCdStStart(off);
    cb(0, 0);
    iosCdStStop();
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsLoadMap);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsLoadStageTex);

extern int *D_401B5384;
extern void iosIopRead(int, int, int);

void sheetFsLoadAdpcmInt(int a, int i, int off, int buf, int size)
{
    int *t = D_401B5384 + i * 2;
    iosIopRead(*t + off, buf, size);
}

int sheetFsGetDirectFileSize(int i)
{
    return *(int *)((char *)D_401B538C + (i << 3) + 4);
}

SpecialFs *sheetFsSrhSpecialFs(char *name)
{
    int i;

    for (i = 0; i < D_401B5390.n; i++) {
        SpecialFs *e = &D_401B5390.tab[i];

        if (strcmp(e->name, name) == 0) {
            return e;
        }
    }
    return 0;
}

extern int D_4012E324;
extern void iosCdSetMode(int mode);

void sheetFsSetSpecialFs(int fs, int mode)
{
    D_4012E324 = fs;
    iosCdSetMode(fs != 0 && mode != 0);
}

typedef struct { int a, b; } SfsP8;
typedef struct { signed char type; char pad[3]; short id; short pad2; union { int off; SfsP8 lang[1]; } u; } SfsEnt;
typedef struct { int pad; int n; SfsEnt *ent; } SfsDefTab;
extern int sheetFsLanguageCode;
extern int memcmp();

int func_400ED988(SfsDefTab *t, SfsEnt *k)
{
    int i;
    SfsEnt *e = t->ent;

    for (i = 0; i < t->n; i++, e++) {
        signed char et = e->type;
        signed char kt = k->type;
        if (kt == et) {
            switch (kt) {
            case 0:
            case 1:
                if (k->id == e->id)
                    goto found;
                break;
            case 3:
            case 4:
                if (k->id == e->id)
                    goto lang;
                break;
            case 2:
                k->id = 0;
                if (memcmp(k, e, 8) == 0)
                    goto found;
                break;
            }
        }
    }
    return -1;
found:
    return e->u.off;
lang:
    return e->u.lang[sheetFsLanguageCode].a;
}

/* NEARMISS-STUB sheetFileUnloadCallBack */
#if 0 /* NEARMISS 70.1% cat=cse-hoist sub=null-check-folded | d2 r89: loops/stores right; target keeps a real null test on &D_401B5398 AFTER the 5 ctx stores (bnez s0 -> iosJumpRecoverPoint(D_401350D8,name)) and builds the | attempts=1 */
typedef struct { int d0; int d4; int d8; int dC; int d10; } UnloadCtx;
typedef struct { int pad[3]; int stride; int pad2[2]; int nEnt; int *tab; } UnloadSegDef;
typedef struct { int pad[2]; UnloadSegDef *def; int cnt; char *base; } UnloadSheet;
typedef struct { int off; int b; void (*cb)(UnloadCtx *, int, int); } UnloadEnt;
typedef struct { int name; int v; int arg; } UnloadItem;
extern UnloadCtx D_401B5398;
extern char D_401350D8[];
extern void iosJumpRecoverPoint();

void sheetFileUnloadCallBack(char *self)
{
    UnloadSheet *sh = *(UnloadSheet **)(self + 0x38);
    UnloadSegDef *def = sh->def;
    int i;
    int j;
    int cnt = sh->cnt;

    for (i = 0; i < cnt; i++) {
        char *base = sh->base + def->stride * i;

        for (j = 0; j < def->nEnt; j++) {
            UnloadEnt *e = (UnloadEnt *)((char *)def->tab + j * 12);

            if (e->cb != 0) {
                UnloadItem *it = (UnloadItem *)(base + e->off);

                if (it->name != 0) {
                    UnloadCtx *c = &D_401B5398;

                    c->dC = e->off;
                    c->d10 = it->v;
                    c->d0 = 0;
                    c->d4 = (int)sh;
                    c->d8 = i;
                    if (c == 0) {
                        iosJumpRecoverPoint(D_401350D8, it->name);
                    }
                    e->cb(c, it->name, it->arg);
                }
            }
        }
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFileUnloadCallBack);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", func_400EDBC8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", func_400EE1C8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", func_400EE428);

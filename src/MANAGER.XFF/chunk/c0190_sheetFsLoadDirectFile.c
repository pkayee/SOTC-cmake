#include "common.h"

extern int iosCdStRead();
extern int iosCdStSkip();
extern int iosCdStSectorAlignSkip();
extern int IosGetMergeDataFileName();
extern void iosCdStInit(int);
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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsLoadDirectFile);

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
extern void iosCdStStart(int);
extern void iosCdStStop(void);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsLoadSegmentIndex);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", func_400ED988);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFileUnloadCallBack);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", func_400EDBC8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", func_400EE1C8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", func_400EE428);

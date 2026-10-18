#include "common.h"

extern int iosCdStRead();
extern int iosCdStSkip();
extern int iosCdStSectorAlignSkip();
extern int IosGetMergeDataFileName();
extern void iosCdStInit(int);
extern void func_400EC808();

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsAddStageTexSegIndex);

typedef struct { int idx, b; } SegIdx;
extern SegIdx *D_401B5348;

int sheetFsDecStageTexSegIndex(int i)
{
    return --D_401B5348[i].idx;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsExistTexSegIndexCallBack);

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

typedef struct {
    int offset;
    int size;
} FileEntry;

extern FileEntry *D_401B538C;

int sheetFsGetDirectFileSize(int i)
{
    return *(int *)((char *)D_401B538C + (i << 3) + 4);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsSrhSpecialFs);

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

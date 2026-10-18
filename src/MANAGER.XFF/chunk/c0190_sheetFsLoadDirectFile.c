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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsDecStageTexSegIndex);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsExistTexSegIndexCallBack);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsSetStageTexSegTexSegDef);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsGetStageTexSegTexSegDef);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsLoadBootData);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsLoadRootSegment);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsLoadSegmentIndex);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsLoadMap);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsLoadStageTex);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsLoadAdpcmInt);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsGetDirectFileSize);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsSrhSpecialFs);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFsSetSpecialFs);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", func_400ED988);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", sheetFileUnloadCallBack);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", func_400EDBC8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", func_400EE1C8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0190_sheetFsLoadDirectFile", func_400EE428);

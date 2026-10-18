#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrInit);

extern int D_4012E334;

void iosSleepThread();

void sheetWait(void)
{
    D_4012E334 = 1;
    iosSleepThread();
}

extern char **D_4012E330;

int sheetIdToName(int i)
{
    return **(int **)(D_4012E330[i] + 0x38);
}

int sheetHeaderObjSearchSheetId(int i)
{
    return (int)D_4012E330[i];
}

typedef struct SheetDataObj {
    char pad0[0x38];
    int *header;
    char pad3C[0x18];
    struct SheetDataObj *next;
} SheetDataObj;

SheetDataObj *sheetMgrSheetHeaderSearchSheetDataObj(char *mgr, int id)
{
    SheetDataObj *obj = *(SheetDataObj **)(mgr + 0x40);

    while (obj != 0 && id != obj->header[1]) {
        obj = obj->next;
    }
    return obj;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrSearchSheetDataObj);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrAddSegLoadList);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrGetSegLoadHeader);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrAddSegInitList);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrCheckSegInitList);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrGetSegInitHeader);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrCreateStageIndexSkipInfo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrChkStageIndexResolve);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrLoadSegmentIndex);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrUnloadSegmentIndex);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrNopSegmentIndex);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrMapDataLoad);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrMapDataUnloadOneBlock);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrStageTexLoad);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrStageTexUnload);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrAdpcmIntLoad);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrDirectFileLoad);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrAllReqWait);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrSpecialFsStart);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrSpecialFsEnd);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0192_sheetMgrInit", sheetMgrSetNoWaitMode);

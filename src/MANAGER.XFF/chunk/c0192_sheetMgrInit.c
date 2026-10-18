#include "common.h"

typedef struct SheetSkipInfo192 {
    int pad0;
    char *flags;
    char *bits;
} SheetSkipInfo192;
extern SheetSkipInfo192 D_401C1030;
extern char rootPtn[];
void *iosMallocAlign(void *, int, int);
void *memset(void *, int, int);

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

extern void iosJumpRecoverPoint(const char *, int);
extern const char D_401351C8[];

char *sheetMgrSearchSheetDataObj(int idx, int hash)
{
    char *s = D_4012E330[idx];
    char *o;

    if (s == 0)
        iosJumpRecoverPoint(D_401351C8, **(int **)(s + 0x38));
    for (o = *(char **)(s + 0x40); o != 0; o = *(char **)(o + 0x54)) {
        if (hash == (*(int **)(o + 0x38))[1])
            break;
    }
    return o;
}

extern void *D_401B53DC;

void sheetMgrAddSegLoadList(void *arg0)
{
    (*(void **)((char *)(arg0) + 0x4C)) = (void *) D_401B53DC;
    D_401B53DC = arg0;
}

int sheetMgrGetSegLoadHeader(void)
{
    return (int)D_401B53DC;
}

extern char *D_401B53E4;
extern char *D_401B53E8;

void sheetMgrAddSegInitList(char *p)
{
    *(char **)(p + 0x50) = 0;
    if (D_401B53E4 != 0)
        *(char **)(D_401B53E8 + 0x50) = p;
    else
        D_401B53E4 = p;
    D_401B53E8 = p;
}

typedef struct SheetInitEntry {
    char pad[0x50];
    struct SheetInitEntry *next;
} SheetInitEntry;

int sheetMgrCheckSegInitList(SheetInitEntry *entry)
{
    SheetInitEntry *node = (SheetInitEntry *)D_401B53E4;
    int found = 0;

    while (node != 0) {
        if (node == entry) {
            found = 1;
            break;
        }
        node = node->next;
    }
    return found;
}

int sheetMgrGetSegInitHeader(void)
{
    return (int)D_401B53E4;
}

void *sheetMgrCreateStageIndexSkipInfo(int n)
{
    int sz = n - 1;
    int m;

    if (sz < 0)
        sz = n + 6;
    D_401C1030.flags = iosMallocAlign(rootPtn, n, 4);
    m = (sz >> 3) + 1;
    D_401C1030.bits = iosMallocAlign(rootPtn, m, 4);
    memset(D_401C1030.flags, 0, n);
    return memset(D_401C1030.bits, 0, m);
}

extern u8 *D_401C1038;

int sheetMgrChkStageIndexResolve(int i)
{
    return (D_401C1038[i / 8] >> (i & 7)) & 1;
}

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

extern int D_4012E338;

void sheetMgrSetNoWaitMode(int arg0)
{
    D_4012E338 = arg0;
}

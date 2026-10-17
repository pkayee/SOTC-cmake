#include "common.h"
#include <stdarg.h>
#include "ios/kernel.h"
#include "ios/hash.h"

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
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ struct { u32 nameOff; u32 unk4; u32 unk8; u32 unkC; } *symTab;
    /* 0x2C */ u32 strTab;
    /* 0x30 */ u32 unk30[4];
    /* 0x40 */ s32 symBase;
} ModHdr;

typedef struct ModObj
{
    /* 0x00 */ u32 unk0[7];
    /* 0x1C */ ModHdr *hdr;
    /* 0x20 */ u32 unk20[3];
    /* 0x2C */ u32 flags;
    /* 0x30 */ u32 unk30[2];
    /* 0x38 */ char *name;
} ModObj;

extern char D_40047138[];
extern char D_40046EC0[]; // "dld:\tError. this file no needs for allocate memory.\n"
extern s32 D_40045820;
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
extern s32 func_4001AD58(char *, s32, s32);
extern s32 iosLoaderGetFileSizeName(char *);
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
extern s32 func_40019A00(ModObj *, s32);
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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_400199B0);
s32 func_400199B0(s32 arg0, ...)
{
    return 0;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_40019A00);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_40019B58);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_40019D68);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_40019FF0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001A170);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001A2F8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysMoveModuleObj);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysCreateModuleObjExisted);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysResolveAllModuleObjHasUndefSymbol);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001A918);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001AB68);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001AD58);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001AE88);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysLaunchModule);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", IosCdvdManagerSimulation);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysSearchModuleFuncNameByAddr);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysResolveOneModuleObj);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysResolveAllProgramModule);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysFlushModuleObj);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", GetSymbolByIndex);
u32 GetSymbolByIndex(ModObj *arg0, s32 idx)
{
    ModHdr *h = arg0->hdr;
    return h->strTab + h->symTab[idx + h->symBase].nameOff;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysRelocateModuleObj);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysGetXffWorkSize);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C3B0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C3F8);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C440);
s32 func_4001C440(void)
{
    iosJumpRecoverPoint(D_40046EC0);
    return 0;
}

typedef struct ModPartEnt
{
    /* 0x00 */ void *ptr;
    /* 0x04 */ u32 unk4[5];
    /* 0x18 */ void *ptr18;
    /* 0x1C */ u32 unk1C;
} ModPartEnt;

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C4F8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C5E8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysResolveAllModuleObjOfGroup);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", iosLoaderGetFileSizeName);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", iosFileRead);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", iosLoaderFOpen);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", iosLoaderFClose);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", iosLoaderFRead);
s32 iosLoaderFRead(s32 fd, void *buf, s32 count)
{
    return LoaderSysFRead(fd, buf, count);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", iosLoaderGetFileSize);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001CFE0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001D120);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", DldExceptionByOriginAdr);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysSearchCalledModuleFuncNameByAddr);

void isysCreateExceptionThread(void)
{}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001D3A8);
void func_4001D3A8(void)
{
    register void *ra asm("ra");
    func_4001CFE0((s32)ra - 8);
}

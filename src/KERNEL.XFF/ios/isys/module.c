#include "common.h"
#include <stdarg.h>
#include "ios/kernel.h"

typedef struct ModHdr
{
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u32 unk8;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u32 unk10;
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
} ModObj;

extern char D_40047138[];
extern char D_40046EC0[]; // "dld:\tError. this file no needs for allocate memory.\n"
extern s32 D_40045820;
extern s32 D_40081A20;
typedef struct DldSlot { s32 unk0; s32 unk4; } DldSlot;
extern DldSlot D_40081A28[8];
extern void *iosMallocAlign(s32, s32, s32);
extern void iosFreeParts(void *, void *, s32);
extern void func_4001CFE0(s32);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", InitDld);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", IosLoadIrxSimulation);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", IosGetMergeDataFileName);
char *IosGetMergeDataFileName(void)
{
    return D_40047138;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysSearchSymbol);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysSearchModuleFuncNameByAddr);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysDumpExecutableModules);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysSearchModuleSymbolByGroup);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysRemoveModuleObjGroup);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysResolveOneModuleObj);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysResolveAllProgramModule);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysLaunchExecModule);

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

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysGetUndefModuleObjNum);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysGetSymdefModuleObjNum);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C350);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C3B0);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C3F8);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C440);
s32 func_4001C440(void)
{
    iosJumpRecoverPoint(D_40046EC0);
    return 0;
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C468);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C4F8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C5E8);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysResolveAllModuleObjOfGroup);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", readEModule);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", isysWriteLinkerScriptFile);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", func_4001C8F0);
void func_4001C8F0(void *arg0, void *arg1)
{
    iosFreeParts(arg0, arg1, 0);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/isys/module", loadtest);

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

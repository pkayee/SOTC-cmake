#include "common.h"

extern int sheetFsDataRead(int, int, int, int);

extern void iosJumpRecoverPoint(const char *);
extern const char D_401350B8[];

void sheetFileRead(void **arg0, int arg1, int arg2, int arg3)
{
    int temp_v0;
    void *temp_s0;

    temp_s0 = *arg0;
    sheetFsDataRead((*(int *)((char *)(temp_s0) + 0)), arg1, arg2, arg3);
    temp_v0 = (*(int *)((char *)(temp_s0) + 8)) + arg2;
    (*(int *)((char *)(temp_s0) + 8)) = temp_v0;
    if ((*(int *)((char *)(temp_s0) + 4)) < temp_v0) {
        iosJumpRecoverPoint(D_401350B8);
    }
}

int sheetFileGetDataAdrs(void *arg0)
{
    int var_a1;
    void *temp_v0;

    temp_v0 = (*(void **)((char *)(arg0) + 4));
    var_a1 = (*(int *)((char *)(temp_v0) + 0x10));
    if (var_a1 != 0) {
        var_a1 += (*(int *)((char *)((*(void **)((char *)(temp_v0) + 8))) + 0xC)) * (*(int *)((char *)(arg0) + 8));
    }
    return var_a1;
}

int sheetFileGetSize(void *arg0)
{
    return (*(int *)((char *)(arg0) + 0x10));
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", sheetFileLoadSegmentIndex);

extern void sheetFsLoadRootSegment(void (*cb)(int a, int b), int);
extern int D_401B53AC;
extern int D_401B53B0;
extern int func_400EE808(int a, int b, int c, int d);

void sheetFileLoadRootSegment(int arg0, int arg1)
{
    D_401B53AC = arg1;
    D_401B53B0 = arg0;
    sheetFsLoadRootSegment(func_400EE808, arg0);
}

extern void sheetFsLoadBootData(void (*cb)(int a, int b), int);
extern int D_401B53BC;
extern int D_401B53C0;
extern int D_401B53C4;
extern void func_400EE428(int a, int b);

void sheetFileLoadBootData(int arg0, int arg1, int arg2, int arg3)
{
    D_401B53C0 = arg1;
    D_401B53BC = arg2;
    D_401B53C4 = arg3;
    D_401B53B0 = arg0;
    sheetFsLoadBootData(&func_400EE428, arg0);
}

extern void sheetFsLoadMap(int, int, int, int, int, void *, int);
extern int D_401B53B4;
extern int D_401B53B8;
extern void func_400EE1C8();

void sheetFileLoadMap(int a, int b, int c, int d, int e, int f, int g)
{
    D_401B53AC = g;
    D_401B53B0 = f;
    D_401B53B4 = b;
    D_401B53B8 = e;
    sheetFsLoadMap(a, b, c, d, e, func_400EE1C8, f);
}

extern void sheetFsLoadStageTex(int, void (*cb)(int a, int b), int);
extern void func_400EE820(int a, int b);

void sheetFileLoadStageTex(int a, int b, int c)
{
    D_401B53AC = c;
    D_401B53B0 = b;
    sheetFsLoadStageTex(a, func_400EE820, b);
}

extern int sheetFsInit();

int sheetfileInit(int a, int b, int c, int d)
{
    return sheetFsInit(a, b, c, d);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EE7F0);

extern int func_400EDBC8();

int func_400EE7F0(int a, int b, int c, int d)
{
    return func_400EDBC8(a, 1, c, d);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EE808);

int func_400EE808(int a, int b, int c, int d)
{
    return func_400EDBC8(a, 1, c, d);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EE820);

void func_400EE820(int a, int b)
{
    func_400EDBC8(a, 0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EE838);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", sheetMgrResolve);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EEC40);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EEE08);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EEF78);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EF138);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EF3A8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EF630);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EF940);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EFAB8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0191_sheetFileRead", func_400EFB98);

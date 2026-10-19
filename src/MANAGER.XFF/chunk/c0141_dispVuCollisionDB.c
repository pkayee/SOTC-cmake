#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0141_dispVuCollisionDB", dispVuCollisionDB);

void DebugDispManualEdgeCollisionDB(s32 *e, s32 a1, s32 a2);

void DebugDispManualEdgeCollisionFinder(s32 *f, s32 a1, s32 a2) {
    s32 i = 0;
    s32 *e;

    while (i < (f[1] < f[0] ? f[1] : f[0])) {
        e = (s32 *)(i * 8 + f[2]);
        i++;
        if (*e != 0) {
            DebugDispManualEdgeCollisionDB(e, a1, a2);
        }
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0141_dispVuCollisionDB", _CalcCollisionMultiDepSurfBoundary);

extern void FlushModifiedManager(void *);

int FlushCollisionWorkByWorkStruct(void *arg0, int arg1, int arg2, int arg3)
{
    int var_s1;
    void *var_s0;

    var_s0 = (*(void **)((char *)(arg0) + 0x24));
    if (arg1 > 0)
    {
        var_s1 = arg1;
        do
        {
            var_s1 -= 1;
            FlushModifiedManager(var_s0);
            FlushModifiedManager(var_s0 + 0x30);
            FlushModifiedManager(var_s0 + 0x48);
            FlushModifiedManager(var_s0 + 0x18);
            var_s0 += 0x60;
        } while (var_s1 != 0);
    }
    if (arg3 != 0)
    {
        FlushModifiedManager(arg0 + 0x28);
        FlushModifiedManager(arg0 + 0x40);
    }
    if (arg2 != 0)
    {
        FlushModifiedManager(arg0 + 0x58);
        FlushModifiedManager(arg0 + 0x70);
    }
    (*(int *)((char *)(arg0) + 0x1C)) = 0;
    return 1;
}

void ReleaseCollisionWork(void **work)
{
    iosFree(work[0]);
    work[0] = 0;
}

extern void func_400BC798();
extern void DeleteAllTwoWayLink(void *, void *);
extern void iosMallocSetExecGarbageCallback(void *, int, int);

void FlushCollisionWorkImmediate(char *w)
{
    DeleteAllTwoWayLink(w + 0x10, func_400BC798);
    iosMallocSetExecGarbageCallback(w, -1, 0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0141_dispVuCollisionDB", Check_InVariableXZSurfJudgeFunc_LowerSurface);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0141_dispVuCollisionDB", ClipCollisionVariableXZSurfaceCB);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0141_dispVuCollisionDB", ClipCollisionFinderWithVariableKeepCB);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0141_dispVuCollisionDB", ClipCollisionFinderWithVariableKeep4DCB);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0141_dispVuCollisionDB", GetCollisionDBCallBack);

#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0148_ReconstructCollisionEdgeLinkDBVWallFinde", ReconstructCollisionEdgeLinkDBVWallFinder);

void SetCollisionEdgeLinkDBFinderVWallDirectionStatus(char *dst, char *src)
{
    *(s128 *)(dst + 0x0) = *(s128 *)(src + 0x0);
}

typedef union
{
    s128 q;
    float f[4];
    int i[4];
} Vec4;

void SetCollisionEdgeLinkDBFinderCollectStatus(char *pa0, int xa1, int xa2, char *pa3, int xt0, float f12)
{
    ((Vec4 *)(pa0 + 0x14))->i[0] = xa1;
    ((Vec4 *)(pa0 + 0x18))->f[0] = f12;
    *(char *)(pa0 + 0x12) = xa2;
    ((Vec4 *)(pa0 + 0x1C))->i[0] = xt0;
    ((Vec4 *)(pa0 + 0x0))->q = ((Vec4 *)(pa3 + 0x0))->q;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0148_ReconstructCollisionEdgeLinkDBVWallFinde", InitializeCollisionFinder);

extern void DeleteTwoWayLink(void *);

void FlushCollisionFinder(int *f)
{
    int n = f[0];
    int *e;
    char *l;

    if (f[1] < n)
        n = f[1];
    l = (char *)f[3];
    e = (int *)f[2];
    while (--n != -1) {
        if (*e != 0)
            DeleteTwoWayLink(l);
        e += 2;
        l += 12;
    }
    f[0] = 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0148_ReconstructCollisionEdgeLinkDBVWallFinde", InitCollisionFinder);

extern int AddTwoWayLinkNext(int *, int *);
extern void *GetLayoutClass(void *);
extern void InitTwoWayLink(char *, int);

void EntryCollisionFinder(void *arg0, void *arg1, int arg2)
{
    int temp_a0;
    signed char *temp_s0;
    void *temp_v0;

    temp_a0 = (*(int *)((char *)(arg0) + 0));
    if (temp_a0 < (*(int *)((char *)(arg0) + 4))) {
        temp_v0 = (*(int *)((char *)(arg0) + 0x8)) + (temp_a0 * 8);
        temp_s0 = (*(int *)((char *)(arg0) + 0xC)) + (temp_a0 * 0xC);
        (*(int *)((char *)(temp_v0) + 4)) = arg2;
        (*(void **)((char *)(temp_v0) + 0)) = arg1;
        InitTwoWayLink(temp_s0, (int) temp_v0);
        AddTwoWayLinkNext((*(int *)((char *)(GetLayoutClass(arg1)) + 0x174)) + 0x10, (int *) temp_s0);
    }
    (*(int *)((char *)(arg0) + 0)) = (int) ((*(int *)((char *)(arg0) + 0)) + 1);
}

int GetCollisionFinderWorkSize(int count)
{
    unsigned int a = count * 8;
    unsigned int b = count * 12;

    return a + b + 0x66;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0148_ReconstructCollisionEdgeLinkDBVWallFinde", CopyCollisionFinder);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0148_ReconstructCollisionEdgeLinkDBVWallFinde", ReleaseCollisionFinder);

int CheckCollisionFinderAlive(char *p)
{
    if (*(int *)(p + 0x8) != 0 && *(int *)(p + 0xC) != 0) return 1;
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0148_ReconstructCollisionEdgeLinkDBVWallFinde", CheckCollisionFinderExistData);

extern int D_4012B3A0;

void DebugSetCollisionWideAreaSearchGroup(int arg0)
{
    D_4012B3A0 = arg0;
}

typedef struct
{
    long a[30];
} WideAreaSearch;

extern WideAreaSearch D_4012B3B0;

void InitCollisionWideAreaSearchInfo(WideAreaSearch *p)
{
    *p = D_4012B3B0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0148_ReconstructCollisionEdgeLinkDBVWallFinde", GetCollisionWideAreaSearch);

void CopyGeometryPointer();

int RequestCollisionWideAreaSearch(char *s, void *a, void *b)
{
    *(int *)(s + 4) = 0;
    *(int *)(s + 0) = 0;
    CopyGeometryPointer(s + 0x20, a);
    CopyGeometryPointer(s + 0x60, b);
    return 0;
}

void CancelRequestCollisionWideAreaSearch(void) {
}

extern void GetGeometryPointerPosition(Vec4 *, void *);
extern void ClipCollisionDirect(void *, Vec4 *, Vec4 *, void *);

void DebugTestWideAreaSearch(char *s)
{
    Vec4 a, b;

    GetGeometryPointerPosition(&a, s + 0x20);
    GetGeometryPointerPosition(&b, s + 0x60);
    ClipCollisionDirect(s + 0xA0, &a, &b, D_4012B3A0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0148_ReconstructCollisionEdgeLinkDBVWallFinde", func_400BD1E0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0148_ReconstructCollisionEdgeLinkDBVWallFinde", func_400BD820);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0148_ReconstructCollisionEdgeLinkDBVWallFinde", func_400BDA68);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0148_ReconstructCollisionEdgeLinkDBVWallFinde", func_400BE0A8);

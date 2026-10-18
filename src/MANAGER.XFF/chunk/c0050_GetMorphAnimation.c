#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0050_GetMorphAnimation", GetMorphAnimation);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0050_GetMorphAnimation", resourceRot);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0050_GetMorphAnimation", func_4004EAC8);

extern void func_40043588(void *, int, int, void *);

int GetMotionRootDirInfoIntFrame(void *m, short *r, void *out)
{
    int d;
    if (r[0] >= 4) {
        d = *(int *)((char *)r + 0x24);
        if (d != 0) {
            func_40043588(m, *(int *)((char *)r + 0x20), d, out);
            return 1;
        }
    }
    return 0;
}

int GetMotionGazeDirInfoIntFrame(void *m, short *r, void *out)
{
    int d;
    if (r[0] >= 9) {
        d = *(int *)((char *)r + 0x3C);
        if (d != 0) {
            func_40043588(m, *(int *)((char *)r + 0x38), d, out);
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0050_GetMorphAnimation", GetBlendedMotion);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0050_GetMorphAnimation", GetBlendedMotionRoot);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0050_GetMorphAnimation", func_4004ED80);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0050_GetMorphAnimation", func_4004EE60);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0050_GetMorphAnimation", func_4004F048);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0050_GetMorphAnimation", func_4004F1E0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0050_GetMorphAnimation", func_4004F340);

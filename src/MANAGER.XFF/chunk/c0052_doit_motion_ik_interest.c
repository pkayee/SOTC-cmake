#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0052_doit_motion_ik_interest", doit_motion_ik_interest);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0052_doit_motion_ik_interest", func_40050478);

extern s128 ZeroVector;
extern void constructor_motion_ik_base(char *);
extern void constructor_double_spring_interp_cntrl3D(char *, float, float);
extern void func_40050A10(char *);

void constructor_motion_ik_interest(char *m)
{
    float z = 0.0f;
    constructor_motion_ik_base(m);
    *(int *)(m + 4) = 0;
    *(int *)(m + 8) = 0;
    *(int *)(m + 0xC) = 0;
    constructor_double_spring_interp_cntrl3D(m + 0x10, 0.0001f, z);
    *(s128 *)(m + 0x50) = ZeroVector;
    *(float *)(m + 0x60) = z;
    *(s128 *)(m + 0x70) = ZeroVector;
    func_40050A10(m);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0052_doit_motion_ik_interest", begin_motion_ik_interest);

void request_end_motion_ik_interest(int *p)
{
    int v = p[1];

    if (v != 1) {
        v = 0;
    }
    p[2] = v;
}

int is_doing_motion_ik_interest(void *arg0)
{
    return (*(int *)((char *)(arg0) + 4));
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0052_doit_motion_ik_interest", func_40050A10);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0052_doit_motion_ik_interest", func_40050A20);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0052_doit_motion_ik_interest", func_40050AE0);

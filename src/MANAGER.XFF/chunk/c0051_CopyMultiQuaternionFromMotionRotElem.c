#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0051_CopyMultiQuaternionFromMotionRotElem", CopyMultiQuaternionFromMotionRotElem);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0051_CopyMultiQuaternionFromMotionRotElem", func_4004F590);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0051_CopyMultiQuaternionFromMotionRotElem", func_4004F618);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0051_CopyMultiQuaternionFromMotionRotElem", func_4004F678);

void InitAnimationData(void) {
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0051_CopyMultiQuaternionFromMotionRotElem", getBlendFirstMotion);

typedef struct { char a, b, c; } Bool3;
extern void func_40045C30(void *, void *, int);

void GetMotionOptionNodeBooleanInfoFloatFrameDirectResource(Bool3 *out, char *res, int node)
{
    struct { char pad[0x20]; Bool3 b; char pad2[0xD]; } t __attribute__((aligned(16)));
    func_40045C30(&t, *(char **)(res + 0x1C) + node * 16, *(short *)(res + 4));
    *out = t.b;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0051_CopyMultiQuaternionFromMotionRotElem", get_temp_parameter_motion_ik_base);

void constructor_motion_ik_base(s32 *arg0)
{
    *arg0 = 0;
}

void init_motion_ik_base(s32 *arg0)
{
    *arg0 = 0;
}

void doit_motion_ik_base(s32 *arg0, s32 arg1)
{
    *arg0 = arg1;
}

extern s32 DldSysUndefSymbol;

char *get_type_parameter_segment_motion_ik_base(char **arg0)
{
    u32 *h = *(u32 **)(*arg0 + 0x18);
    u32 v = *h;
    s32 off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;
    char *p = (t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32 *)(*(char **)(t + 8) + 0xC) : 0;
    return p + 0xC;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0051_CopyMultiQuaternionFromMotionRotElem", update_node_by_quater_motion_ik_base);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0051_CopyMultiQuaternionFromMotionRotElem", update_node_by_rotXYZ_motion_ik_base);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0051_CopyMultiQuaternionFromMotionRotElem", get_animation_designer_node_quater_motion_ik_base);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0051_CopyMultiQuaternionFromMotionRotElem", get_animation_designer_node_rotXYZ_motion_ik_base);

extern void convert_from_quater_to_rotXYZ_direct_motion_ik_base(void *, void *, s32);

void convert_from_quater_to_rotXYZ_motion_ik_base(void *arg0, void *arg1, char **arg2)
{
    u32 *h = *(u32 **)(*arg2 + 0x18);
    u32 v = *h;
    s32 off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;
    char *p = (t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32 *)(*(char **)(t + 8) + 0xC) : 0;
    convert_from_quater_to_rotXYZ_direct_motion_ik_base(arg0, arg1, *(s32 *)(p + 0x14));
}

/* NEARMISS-STUB convert_from_quater_to_rotXYZ_direct_motion_ik_base */
#if 0 /* NEARMISS 40.8% cat=no-c-form sub=- | target has break 0 (unreachable in C; __builtin_trap unsupported); branch order differs | attempts=1 */
extern void GetEulerYXZFromQuaternion(void *, void *);
extern void GetEulerZXYFromQuaternion(void *, void *);

void convert_from_quater_to_rotXYZ_direct_motion_ik_base(void *arg0, void *arg1, s32 arg2)
{
    if (arg2 == 0)
    {
        GetEulerYXZFromQuaternion(arg0, arg1);
        return;
    }
    if (arg2 != 1)
    {
        return;
    }
    GetEulerZXYFromQuaternion(arg0, arg1);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0051_CopyMultiQuaternionFromMotionRotElem", convert_from_quater_to_rotXYZ_direct_motion_ik_base);

extern void convert_from_rotXYZ_to_quater_direct_motion_ik_base(void *, void *, s32);

void convert_from_rotXYZ_to_quater_motion_ik_base(void *arg0, void *arg1, char **arg2)
{
    u32 *h = *(u32 **)(*arg2 + 0x18);
    u32 v = *h;
    s32 off = v & 0x3FFFF;
    char *t = off != 0 ? *(char **)((char *)h - off) : 0;
    char *p = (t != 0 && t != (char *)DldSysUndefSymbol) ? *(char **)(t + 0x10) + ((v >> 18) & 0xFFF) * *(s32 *)(*(char **)(t + 8) + 0xC) : 0;
    convert_from_rotXYZ_to_quater_direct_motion_ik_base(arg0, arg1, *(s32 *)(p + 0x14));
}

/* NEARMISS-STUB convert_from_rotXYZ_to_quater_direct_motion_ik_base */
#if 0 /* NEARMISS 0.0% cat=no-c-form sub=- | target has break 0 trap on fall-through path (no C form); branch layout differs | attempts=1 */
extern void GetQuaternionByEulerYXZ(f32, f32, f32);
extern void GetQuaternionByEulerZXY(f32, f32, f32);

void convert_from_rotXYZ_to_quater_direct_motion_ik_base(void *arg0, void *arg1, s32 arg2)
{
    f32 *f = arg1;

    if (arg2 != 0)
    {
        if (arg2 == 1)
        {
            GetQuaternionByEulerZXY(f[0], f[1], f[2]);
            return;
        }
        return;
    }
    GetQuaternionByEulerYXZ(f[0], f[1], f[2]);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0051_CopyMultiQuaternionFromMotionRotElem", convert_from_rotXYZ_to_quater_direct_motion_ik_base);

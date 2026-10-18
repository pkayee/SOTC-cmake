#include "common.h"

s32 CAM_is_visible_now_target_visibility(void *param)
{
    return *(s32*)((u8*)param + 0x44) == 0;
}

s32 CAM_is_return_cam_posi_target_visibility(void *param)
{
    return *(s32*)((u8*)param + 0x130);
}

/* NEARMISS-STUB CAM_init_camera_warp_cntrl */
#if 0 /* NEARMISS 99.86% cat=sched sub=- | float store order: compiler emits swc1 0x14 before sw 0xC; expected ld ra between sw a1 and swc1 0x18 | attempts=1 */
void CAM_init_camera_warp_cntrl(void *param, s32 a1, s32 a2, s32 a3)
{
    *(s32*)((u8*)param + 0x0) = a1;
    *(f32*)((u8*)param + 0x18) = 0x1.657182p-4f;
    *(s32*)((u8*)param + 0xC) = a2;
    *(s32*)((u8*)param + 0x1C) = a3;
    *(f32*)((u8*)param + 0x14) = 0x1.657182p-4f;
    CAM_reset_camera_warp_cntrl(param);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_init_camera_warp_cntrl);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_reset_camera_warp_cntrl);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_doit_camera_warp_cntrl);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_act_warp_camera_warp_cntrl);

void CAM_set_invisible_warp_apply_range_camera_warp_cntrl(f32 a, f32 b, void *param)
{
    *(f32*)((u8*)param + 0x14) = a;
    *(f32*)((u8*)param + 0x18) = b;
}

void CAM_act_warp_order_camera_warp_cntrl(void *param)
{
    *(s32*)((u8*)param + 0x28) = 1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_reset_view_cut_avoid_cntrl);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_get_update_yaw_by_view_cut_avoid_cntrl);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_get_update_pitch_by_view_cut_avoid_cntrl);

s32 CAM_is_acting_view_cut_avoid_cntrl(s32 *param)
{
    return *param != 0;
}

void CAM_set_param_view_cut_avoid_cntrl(f32 a, f32 b, void *param)
{
    *(f32*)((u8*)param + 0x94) = a;
    *(f32*)((u8*)param + 0x98) = b;
}

void CAM_reset_obstacle_avoid_cntrl(s32 *param)
{
    param[0] = 0;
    param[1] = 0;
    param[2] = 0;
    param[3] = 0;
    param[4] = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_is_need_obstacle_avoid_ofst);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_act_avoid_rot_obstacle_avoid_cntrl);

s32 CAM_is_use_obstacle_target_ofst_interp_coe(f32 a, f32 b)
{
    return a < b;
}

/* NEARMISS-STUB CAM_constructor_base_look_at */
#if 0 /* NEARMISS 86.25% cat=float-ops sub=- | zero float stores emitted as sw $zero not mtc1+swc1; store order of lq/sq vs swc1 differs | attempts=1 */
extern u128 ZeroPoint;
extern u128 ZeroVector;

void CAM_constructor_base_look_at(void *param)
{
    *(u128*)((u8*)param + 0x0) = ZeroPoint;
    *(u128*)((u8*)param + 0x10) = ZeroPoint;
    *(u128*)((u8*)param + 0x20) = ZeroVector;
    *(u128*)((u8*)param + 0x30) = ZeroVector;
    *(f32*)((u8*)param + 0x40) = 0.0f;
    *(f32*)((u8*)param + 0x44) = 0.0f;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_constructor_base_look_at);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_doit_base_look_at);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_constructor_look_at_spring);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_doit_look_at_spring);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_reset_mode_ratio_follow_rot);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", CAM_doit_follow_rot);

f32 func_400E9498(f32 a, f32 b)
{
    if (b <= a)
    {
        return 1.0f;
    }
    return a / b;
}

void func_400E94F0(void *param);
void GAMEUTIL_reset_interp_ratio_cntrl(void *cntrl);

void func_400E94C0(void *param)
{
    func_400E94F0(param);
    *(s32*)((u8*)param + 0x20) = 0;
    GAMEUTIL_reset_interp_ratio_cntrl((u8*)param + 0x24);
}

void func_400E94F0(void *param)
{
    *(s32*)((u8*)param + 0x4) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400E94F8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400E9590);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400E9628);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400E96C0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400E9730);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400E9900);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400E99A8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400E9B30);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400E9DA0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400E9FF8);

s32 func_400EA0E8(s32 x)
{
    return (u32)(x - 3) < 2;
}

s32 func_400EA0F8(s32 x)
{
    return (u32)(x - 1) < 2;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400EA108);

/* NEARMISS-STUB func_400EA1B0 */
#if 0 /* NEARMISS 99.0% cat=regalloc sub=- | loaded int uses v1 not v0; expected reuses v0 for lw and return | attempts=1 */
s32 func_400EA1B0(f32 x, void *param)
{
    if (*(s32*)((u8*)param + 0x5D4) != 0)
    {
        return 0;
    }
    return x <= *(f32*)((u8*)param + 0xD8);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400EA1B0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400EA1D8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0180_CAM_is_visible_now_target_visibility", func_400EA298);

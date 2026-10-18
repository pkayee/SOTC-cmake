#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0175_doit_camera_target_visible_angle_manager", doit_camera_target_visible_angle_manager);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0175_doit_camera_target_visible_angle_manager", end_get_yaw_pitch_camera_target_visible_angle_manager);

void end_get_yaw_pitch_camera_target_visible_angle_manager(void *arg0)
{
    (*(int *)((char *)(arg0) + 0x3D0)) = 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0175_doit_camera_target_visible_angle_manager", func_400E3FD8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0175_doit_camera_target_visible_angle_manager", func_400E4048);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0175_doit_camera_target_visible_angle_manager", func_400E4148);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0175_doit_camera_target_visible_angle_manager", func_400E4230);

s32 func_400E4230(s32 **a, s32 **b) {
    if (*(f32 *)((u8 *)*a + 0x4) > *(f32 *)((u8 *)*b + 0x4)) {
        return 1;
    }
    return -1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0175_doit_camera_target_visible_angle_manager", CAM_get_base_space_posi_and_axisXYZ);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0175_doit_camera_target_visible_angle_manager", CAM_get_warp_position);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0175_doit_camera_target_visible_angle_manager", CAM_get_interp_cam_and_look_at_posi);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0175_doit_camera_target_visible_angle_manager", CAM_get_safety_cam_and_look_at_posi);

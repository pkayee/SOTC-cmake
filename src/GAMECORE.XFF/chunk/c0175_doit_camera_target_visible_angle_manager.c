#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0175_doit_camera_target_visible_angle_manager", doit_camera_target_visible_angle_manager);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0175_doit_camera_target_visible_angle_manager", end_get_yaw_pitch_camera_target_visible_angle_manager);

void end_get_yaw_pitch_camera_target_visible_angle_manager(void *arg0)
{
    (*(int *)((char *)(arg0) + 0x3D0)) = 0;
}

s32 func_400E4230(s32 **a, s32 **b);
void qsort(void *, s32, s32, s32 (*)(s32 **, s32 **));

void func_400E3FD8(s32 *n, s32 *list, u8 *w)
{
    s32 i;
    u8 *p = w + 0x10;

    *n = 0;
    for (i = 0; i < 20; i++, p += 0x30) {
        if (*(s32 *)p == 1) {
            list[*n] = (s32)p;
            *n = *n + 1;
        }
    }
    qsort(list, *n, 4, func_400E4230);
}

extern f32 D_401371E8;
f32 GAMEUTIL_get_difference_yaw_and_yaw(f32, f32);
s32 GAMEUTIL_is_between_yaw_and_yaw(f32, f32, f32);
s32 GAMEUTIL_is_nearly_equal_yaw(f32, f32, f32);
s32 GAMEUTIL_is_nearly_equal_pitch(f32, f32, f32);
s32 CAM_is_visible_now_target_visibility(u8 *);

s32 func_400E4048(s32 n, u8 **list, u8 *w, u8 *cam)
{
    s32 i;
    s32 best = -1;
    f32 min = D_401371E8;
    f32 yaw = *(f32 *)(cam + 0xB04);
    f32 d;

    for (i = 0; i < n; i++) {
        d = GAMEUTIL_get_difference_yaw_and_yaw(*(f32 *)(list[i] + 4), yaw);
        if (*(s32 *)(w + 0x3D0) == 1 &&
            GAMEUTIL_is_between_yaw_and_yaw(yaw, *(f32 *)(list[i] + 4), *(f32 *)(w + 0x3D4)) == 1)
            d += 0.08726646f;
        if (d < min) {
            min = d;
            best = i;
        }
    }
    return best;
}

s32 func_400E4148(u8 *tgt, u8 *w, u8 *cam, f32 yaw, f32 pitch)
{
    u8 *c;

    if (*(s32 *)(w + 0x3D0) == 1) {
        c = cam + 0x60;
        if (CAM_is_visible_now_target_visibility(cam + 0x590) == 0) {
            if (GAMEUTIL_is_nearly_equal_yaw(*(f32 *)(w + 0x3D4), *(f32 *)(c + 0x30), 0.034906584f) == 1 &&
                GAMEUTIL_is_nearly_equal_pitch(pitch, *(f32 *)(c + 0x34), 0.034906584f) == 1)
                return 0;
        }
        if (GAMEUTIL_get_difference_yaw_and_yaw(*(f32 *)(tgt + 4), *(f32 *)(w + 0x3D4)) <= *(f32 *)(w + 0x3E8) * 1.2f)
            return 1;
    }
    return 0;
}

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

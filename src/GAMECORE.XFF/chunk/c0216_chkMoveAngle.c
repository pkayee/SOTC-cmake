#include "common.h"

int chkMoveAngle(float angle, float target)
{
    int result;

    result = 1;
    if (!(fabsf(angle + target) <= 1.7453291e-02f) && (((target >= 0.0f) && (angle >= 0.0f)) || ((result = 0, (target <= 0.0f)) && (angle <= 0.0f)))) {
        result = 1;
        if (!(fabsf(angle) >= fabsf(target))) {
            result = 0;
        }
    }
    return result;
}

int chkMoveAngle2(float a, float b)
{
    if (fabsf(a + b) <= 1.7453291e-02f) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0216_chkMoveAngle", analyzeMotionProperty);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0216_chkMoveAngle", analyzeMotionPropertyXZ);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0216_chkMoveAngle", analyzeMotionProperty2);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0216_chkMoveAngle", analyzeMotionProperty2XZ);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0216_chkMoveAngle", chkLeftPointForLineXZ);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0216_chkMoveAngle", chkUpPointForLineYZ);

float adjustAngleForLimit(float angle, float limit)
{
    if (limit < angle) {
        return limit;
    }
    if (angle < -limit) {
        return -limit;
    }
    return angle;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0216_chkMoveAngle", getTurnAndPitchFromDir);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0216_chkMoveAngle", getTurnAndPitchFromQuaternion);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0216_chkMoveAngle", getBankAndPitchFromDir);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0216_chkMoveAngle", adjustQuaternionYXZForLimit);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0216_chkMoveAngle", adjustQuaternionZXYForLimit);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0216_chkMoveAngle", adjustQuaternionYXZForLimit2);

float adjustAnglePI(float a)
{
    if (a > 6.2831851f) {
        a -= 6.2831851f;
    } else if (a < -6.2831851f) {
        a += 6.2831851f;
    }
    if (a > 3.1415926f) {
        a += -6.2831851f;
    } else if (a < -3.1415926f) {
        a += 6.2831851f;
    }
    return a;
}

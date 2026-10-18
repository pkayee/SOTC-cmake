#include "common.h"

void deleteHorseCtrlWork(void) {
}

void setDashHorseCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x34)) = arg1;
}

void setWallStopHorseCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x38)) = arg1;
}

void setLimitModeHorseCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x44)) = arg1;
}

void setFinalAttainWalkHorseCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x30)) = arg1;
}

void setAllowMaxSpeedHorseCtrlWork(void *arg0, float fparg0)
{
    if (*(*(float **)((char *)(arg0) + 0x78)) < fparg0) {
        (*(float *)((char *)(arg0) + 0x40)) = fparg0;
    }
}

void setFreezeHorseCtrlWork(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x3C)) = arg1;
}

/* NEARMISS-STUB func_40111B78 */
#if 0 /* NEARMISS 98.75% cat=regalloc sub=- | full 5040-perm store sweep: best order 40,D0,34,38,30,AC,3C schedules exactly; only v0/v1 swapped (ours li v0,1 / lui v1 hi, target lui v0 / li v1,1); local one | attempts=2 */
extern float D_40137728;
extern s32 _resetBaseMoveWork(s32 arg0, void *arg1);
void func_40111BC8(void *arg0);

void func_40111B78(s32 arg0, void *arg1)
{
    _resetBaseMoveWork(arg0, arg1);
    (*(float *)((char *)(arg1) + 0x40)) = D_40137728;
    (*(int *)((char *)(arg1) + 0xD0)) = 0;
    (*(int *)((char *)(arg1) + 0x34)) = 0;
    (*(int *)((char *)(arg1) + 0x38)) = 1;
    (*(int *)((char *)(arg1) + 0x30)) = 1;
    (*(int *)((char *)(arg1) + 0xAC)) = 0;
    (*(int *)((char *)(arg1) + 0x3C)) = 0;
    func_40111BC8(arg1);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0214_deleteHorseCtrlWork", func_40111B78);

/* NEARMISS-STUB func_40111BC8 */
#if 0 /* NEARMISS 80.0% cat=struct-layout sub=- | lwc1 f0 scheduled after lq 0x10 copy; store order 0x60/0xA8 differs; compiler reuses float addr | attempts=1 */
extern f32 D_4013772C;
extern f32 D_40137730;
extern u128 fltMaxVector;

void func_40111BC8(void *arg0)
{
    f32 f1;
    f32 f0;

    f1 = D_4013772C;
    f0 = D_40137730;
    *(u128 *)((char *)arg0 + 0x50) = *(u128 *)((char *)arg0 + 0x10);
    *(f32 *)((char *)arg0 + 0xA4) = f0;
    *(f32 *)((char *)arg0 + 0x60) = f1;
    *(f32 *)((char *)arg0 + 0xA8) = f1;
    *(s32 *)((char *)arg0 + 0xA0) = 0;
    *(s32 *)((char *)arg0 + 0xB4) = 0;
    *(u128 *)((char *)arg0 + 0xC0) = fltMaxVector;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0214_deleteHorseCtrlWork", func_40111BC8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0214_deleteHorseCtrlWork", func_40111C08);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0214_deleteHorseCtrlWork", func_40111D98);
void chkEstimatCollisionCore(void *arg0, s32 arg1, void *arg2, f32 arg3, f32 arg4, f32 arg5);

void func_40111D98(void *arg0, s32 arg1, f32 arg2, f32 arg3)
{
    chkEstimatCollisionCore(arg0, arg1, (char *)arg0 + 0x120, arg2, arg3, *(f32 *)(*(char **)((char *)arg0 + 0xCC) + 0x68));
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0214_deleteHorseCtrlWork", func_40111DC0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0214_deleteHorseCtrlWork", updateHumanCtrlWork);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0214_deleteHorseCtrlWork", func_40112278);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0214_deleteHorseCtrlWork", func_40112670);

#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010DCB8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010E250);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010E368);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", sendStopKeyFastLegCtrlWork);

void deleteFastLegCtrlWork(void) {
}

void setDashFastLegCtrlWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 0x34) = arg1;
}

void setFinalAttainWalkFastLegCtrlWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 0x30) = arg1;
}

void setAllowMaxSpeedFastLegCtrlWork(void *arg0, f32 fparg0)
{
    if (*(f32 *)((u8 *)arg0 + 0x7C) < fparg0) {
        *(f32 *)((u8 *)arg0 + 0x50) = fparg0;
    }
}

void setBackFastLegCtrlWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 0x38) = arg1;
}

void setNotFastTurnFastLegCtrlWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 0x3C) = arg1;
}

void setRunStopTurnFastLegCtrlWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 0x40) = arg1;
}

void setWalkStopTurnFastLegCtrlWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 0x44) = arg1;
}

void setCurveCollisionFastLegCtrlWork(void *arg0, s32 arg1)
{
    *(s32 *)((u8 *)arg0 + 0x48) = arg1;
}

f32 getChkColWidth(void *arg0)
{
    return *(f32 *)((u8 *)arg0 + 0xCC);
}

void setRunStopTurnAngleFastLegCtrlWork(u8 *a0, f32 f12)
{
    *(f32 *)(a0 + 0x4C) = f12 * 3.1415926f / 180.0f;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", setRunStopTurnAngleFastLegCtrlWork);

/* NEARMISS-STUB func_4010E830 */
#if 0 /* NEARMISS 80.3% cat=vu0-mmi sub=- | sqc2 vf0 (0,0,0,1) store has no C form; C gives sw x4; store order and tail-call a0 setup differ | attempts=1 */
extern f32 D_4013765C;
extern void _resetBaseMoveWork(void *arg0);
extern void func_4010E8B0(void *arg0);

void func_4010E830(void *arg0, void *arg1)
{
    _resetBaseMoveWork(arg0);
    *(f32 *)((u8 *)arg1 + 0x50) = D_4013765C;
    *(s32 *)((u8 *)arg1 + 0x48) = 1;
    *(f32 *)((u8 *)arg1 + 0x4C) = 3.1415926f;
    *(f32 *)((u8 *)arg1 + 0x110) = 1.0f;
    *(s32 *)((u8 *)arg1 + 0x114) = 0;
    *(s32 *)((u8 *)arg1 + 0x34) = 0;
    *(s32 *)((u8 *)arg1 + 0x30) = 1;
    *(s32 *)((u8 *)arg1 + 0x38) = 0;
    *(s32 *)((u8 *)arg1 + 0x3C) = 0;
    *(s32 *)((u8 *)arg1 + 0x40) = 0;
    *(s32 *)((u8 *)arg1 + 0x44) = 1;
    *(s32 *)((u8 *)arg1 + 0xF0) = 0;
    *(f32 *)((u8 *)arg1 + 0x120) = 0.0f;
    *(f32 *)((u8 *)arg1 + 0x124) = 0.0f;
    *(f32 *)((u8 *)arg1 + 0x128) = 0.0f;
    *(f32 *)((u8 *)arg1 + 0x12C) = 1.0f;
    func_4010E8B0(arg1);
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010E830);

/* NEARMISS-STUB func_4010E8B0 */
#if 0 /* NEARMISS 79.875% cat=sched sub=- | lwc1 f0 hoisted before lq 0x10 copy; 0x70/0xEC store order swapped vs asm | attempts=1 */
extern f32 D_40137660;
extern f32 D_40137664;
extern u128 fltMaxVector;

void func_4010E8B0(void *arg0)
{
    f32 f1;
    f32 f0;

    f1 = D_40137660;
    f0 = D_40137664;
    *(u128 *)((char *)arg0 + 0x60) = *(u128 *)((char *)arg0 + 0x10);
    *(f32 *)((char *)arg0 + 0xE8) = f0;
    *(f32 *)((char *)arg0 + 0xEC) = f1;
    *(f32 *)((char *)arg0 + 0x70) = f1;
    *(s32 *)((char *)arg0 + 0xE4) = 0;
    *(s32 *)((char *)arg0 + 0xF4) = 0;
    *(u128 *)((char *)arg0 + 0x100) = fltMaxVector;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010E8B0);

/* NEARMISS-STUB func_4010E8F0 */
#if 0 /* NEARMISS 78.125% cat=regalloc sub=- | lw order/param reg: compiler loads target first, delay slots nop; asm fills v0=1 delays | attempts=1 */
s32 func_4010E8F0(void *arg0)
{
    u8 *p;
    s32 target;

    p = *(u8 **)((u8 *)arg0 + 0xCC);
    target = **(s32 **)((u8 *)arg0 + 0x1C);
    if (*(s32 *)(p + 0xA0) == target) return 1;
    if (*(s32 *)(p + 0xA4) == target) return 1;
    if (*(s32 *)(p + 0xAC) == target) return 1;
    if (*(s32 *)(p + 0xB0) == target) return 1;
    if (*(s32 *)(p + 0xB4) == target) return 1;
    if (*(s32 *)(p + 0xB8) == target) return 1;
    return 0;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010E8F0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010E950);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010EAE0);

/* NEARMISS-STUB func_4010EBD0 */
#if 0 /* NEARMISS 83.7% cat=regalloc sub=- | p kept in a4 then moved to a3; load order 0x14/0xCC differs from asm | attempts=1 */
s32 chkEstimatCollisionCore(void *arg0, s32 arg1, void *arg2, void *arg3, f32 arg4, f32 arg5, f32 arg6);

s32 func_4010EBD0(void *arg0, s32 arg1, f32 arg2, f32 arg3)
{
    void *p;
    s32 val;

    val = *(s32 *)(*(u8 **)((u8 *)arg0 + 0x14) + 0x740);
    p = *(void **)((u8 *)arg0 + 0xCC);
    if ((val != *(s32 *)((u8 *)p + 0x8C)) && (val != *(s32 *)((u8 *)p + 0x90)))
    {
        return 0;
    }
    return chkEstimatCollisionCore(arg0, arg1, (u8 *)arg0 + 0x120, p, arg2, arg3, *(f32 *)((u8 *)p + 0xCC));
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010EBD0);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0210_func_4010DCB8", func_4010EC20);
extern u64 *GetCollisionDBAttributeAdr();

s32 func_4010EC20(void)
{
    u64 *temp_v0;

    temp_v0 = GetCollisionDBAttributeAdr();
    return (*temp_v0 & 0x7C000000) != 0x34000000;
}

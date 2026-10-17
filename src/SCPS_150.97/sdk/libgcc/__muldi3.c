#include "common.h"

/* NEARMISS-STUB __muldi3 */
#if 0 /* NEARMISS 99.0% cat=no-c-form sub=- | umul_ppmm: one multu feeds mfhi+mflo | attempts=1 */
s64 __muldi3(s64 u, s64 v)
{
    u32 ul = (u32)u, vl = (u32)v;
    u32 w1 = (u32)(((u64)ul * vl) >> 32);
    u32 w0 = ul * vl;
    w1 += ul * (u32)((u64)v >> 32) + (u32)((u64)u >> 32) * vl;
    return ((u64)w1 << 32) | w0;
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/__muldi3", __muldi3);

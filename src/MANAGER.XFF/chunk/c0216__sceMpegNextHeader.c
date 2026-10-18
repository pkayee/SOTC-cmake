#include "common.h"

s32 _sceMpegNextBit(void *, s32);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0216__sceMpegNextHeader", _sceMpegNextHeader);

void func_40109790(void *c) {
    func_40109630(c, 0x20);
}

/* NEARMISS-STUB func_40109798 */
#if 0 /* NEARMISS 66.6% cat=stack-frame sub=- | frame 0x10 vs 0x20 (no 8-byte slot); lui/ori addr fold; a0 move scheduled earlier | attempts=1 */
extern void func_401095F8(void);
extern s32 func_40109630(void *param_1, s32 param_2);

void func_40109798(void *param_1)
{
    u32 *ipu_bp;
    u32 var_a1;

    func_401095F8();
    ipu_bp = (u32 *)0x10002020;
    var_a1 = (-(*ipu_bp & 0x7)) & 0x7;
    if (var_a1 != 0) {
        func_40109630(param_1, var_a1);
        return;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0216__sceMpegNextHeader", func_40109798);

void func_401097E8(u8 *c) {
    _sceMpegNextBit(c, 3);
    if (_sceMpegNextBit(c, 1) != 0) {
        _sceMpegNextBit(c, 8);
        _sceMpegNextBit(c, 8);
        *(s32 *)(c + 0x154) = _sceMpegNextBit(c, 8);
    }
    *(s32 *)(c + 0x158) = _sceMpegNextBit(c, 0xe);
    _sceMpegNextBit(c, 1);
    *(s32 *)(c + 0x15c) = _sceMpegNextBit(c, 0xe);
}

s32 func_40109878(void *c) {
    _sceMpegNextBit(c, 1);
    _sceMpegNextBit(c, 8);
    _sceMpegNextBit(c, 1);
    _sceMpegNextBit(c, 7);
    _sceMpegNextBit(c, 1);
    _sceMpegNextBit(c, 0x14);
    _sceMpegNextBit(c, 1);
    _sceMpegNextBit(c, 0x16);
    _sceMpegNextBit(c, 1);
    return _sceMpegNextBit(c, 0x16);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0216__sceMpegNextHeader", func_40109910);

/* NEARMISS-STUB func_40109A08 */
#if 0 /* NEARMISS 55.4% cat=volatile-alias sub=- | lui/ori constants reloaded, 0x20 frame; needs volatile reloads | attempts=1 */
extern s32 DIntr(void);
extern s32 EIntr(void);

void func_40109A08(s32 param_1)
{
    s32 intr;
    u32 *enabler;
    u32 *enablew;
    u32 *chcr;

    intr = DIntr();
    enabler = (u32 *)0x1000F520;
    enablew = (u32 *)0x1000F590;
    chcr = (u32 *)0x1000B000;
    *enablew = *enabler | 0x10000;
    *chcr = param_1;
    *enablew = *enabler & 0xFFFEFFFF;
    if (intr != 0) {
        EIntr();
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0216__sceMpegNextHeader", func_40109A08);

/* NEARMISS-STUB func_40109A80 */
#if 0 /* NEARMISS 55.4% cat=volatile-alias sub=- | addr consts folded as lui1001+offset not lui/ori regs; frame 0x10 vs 0x20; no tail j EIntr | attempts=1 */
extern s32 DIntr(void);
extern s32 EIntr(void);

void func_40109A80(s32 param_1)
{
    s32 intr;
    u32 *enabler;
    u32 *enablew;
    u32 *chcr;

    intr = DIntr();
    enabler = (u32 *)0x1000F520;
    enablew = (u32 *)0x1000F590;
    chcr = (u32 *)0x1000B400;
    *enablew = *enabler | 0x10000;
    *chcr = param_1;
    *enablew = *enabler & 0xFFFEFFFF;
    if (intr != 0) {
        EIntr();
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0216__sceMpegNextHeader", func_40109A80);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0216__sceMpegNextHeader", sceIpuStopDMA);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0216__sceMpegNextHeader", sceIpuRestartDMA);

/* NEARMISS-STUB sceIpuSync */
#if 0 /* NEARMISS 42.2% cat=volatile-alias sub=- | spin reload of 0x10002010 hoisted out of loop (no volatile); if/else layout swapped | attempts=1 */
u32 sceIpuSync(s32 param_1)
{
    s32 iVar1;
    u32 uVar2;

    if (param_1 == 0) {
        do {
            iVar1 = *(s32 *)0x10002010;
        } while (iVar1 < 0);
        uVar2 = 0;
    } else {
        uVar2 = 0;
        if (param_1 == 1) {
            uVar2 = *(u32 *)0x10002010;
            uVar2 = uVar2 >> 31;
        }
    }
    return uVar2;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0216__sceMpegNextHeader", sceIpuSync);

/* NEARMISS-STUB func_40109D98 */
#if 0 /* NEARMISS 55.4% cat=regalloc sub=- | addresses folded to lui1001+offset not lui/ori regs; frame 0x10 vs 0x20 | attempts=1 */
extern s32 DIntr(void);
extern s32 EIntr(void);

void func_40109D98(s32 param_1)
{
    s32 intr;
    u32 *enabler;
    u32 *enablew;
    u32 *chcr;

    intr = DIntr();
    enabler = (u32 *)0x1000F520;
    enablew = (u32 *)0x1000F590;
    chcr = (u32 *)0x1000B400;
    *enablew = *enabler | 0x10000;
    *chcr = param_1;
    *enablew = *enabler & 0xFFFEFFFF;
    if (intr != 0)
    {
        EIntr();
        return;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0216__sceMpegNextHeader", func_40109D98);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0216__sceMpegNextHeader", sceIpuInit);

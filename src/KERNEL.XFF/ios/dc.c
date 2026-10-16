#include "common.h"

typedef struct DC
{
    u8 pad0[0xD0];
    u8 unkD0[0x90];
    s32 unk160;
    s32 unk164;
    s16 unk168;
    s16 unk16A;
    u8 unk16C;
    u8 unk16D;
    u8 unk16E;
    u8 unk16F;
    u64 unk170;
} DC;

extern u8 D_40092688[];
extern DC *D_40092284[];
extern DC *D_40092288[];
extern DC *D_40045A00;
extern DC *D_40045A04;
extern s32 D_40045A08;

void func_40024218(DC *dc);
void iosDlChainTailCurrent();
void isysInitGroup(void *group);
void _isysDeleteGroup(void *obj, void *group, s32 flag);
void isysRequestDeleteObj(void *obj);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", func_40024218);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosCreateDC);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosReleaseDC);
void iosReleaseDC(void *dc)
{
    if (dc != NULL)
    {
        _isysDeleteGroup(dc, &D_40092688, 0);
        isysRequestDeleteObj(dc);
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosSetDCParam);
void iosSetDCParam(DC *dc, s32 a, s32 b, s16 c, s16 d)
{
    dc->unk160 = a;
    dc->unk164 = b;
    dc->unk168 = c;
    dc->unk16A = d;
    func_40024218(dc);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosSetDCClearParam);
void iosSetDCClearParam(DC *dc, u32 flag, u8 r, u8 g, u8 b, u8 a)
{
    dc->unk16C = r;
    dc->unk16D = g;
    dc->unk170 = (dc->unk170 & ~1) | (flag & 1);
    dc->unk16E = b;
    dc->unk16F = a;
    func_40024218(dc);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosSetDCViewPort);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosSetDCViewPortCenter);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosSetDC);
void iosSetDC(DC *dc)
{
    iosDlChainTailCurrent();
    if (*(u32 *)&dc->unk170 & 1)
    {
        iosDlChainTailCurrent(dc->unkD0);
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosPushDC);
void iosPushDC(DC *dc)
{
    D_40092288[D_40045A08] = dc;
    D_40045A08++;
    iosDlChainTailCurrent(dc);
    D_40045A00 = dc;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosPopDC);
void iosPopDC(void)
{
    DC *dc = D_40092284[--D_40045A08];
    iosDlChainTailCurrent(dc);
    D_40045A00 = dc;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosGetRootDC);
DC *iosGetRootDC(void)
{
    return D_40045A04;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosSetRootDC);
void iosSetRootDC(void)
{
    iosDlChainTailCurrent(D_40045A04);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosGetCurrentDC);
DC *iosGetCurrentDC(void)
{
    return D_40045A00;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosSetCurrentDC);
void iosSetCurrentDC(void)
{
    iosDlChainTailCurrent(D_40045A00);
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosResetDC);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosInitDC);
void iosInitDC(void)
{
    isysInitGroup(&D_40092688);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosGetDCGroup);
void *iosGetDCGroup(void)
{
    return &D_40092688;
}

void func_40024A30(void)
{}

void func_40024A38(void)
{}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosSetDCWithClear);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", _iosPushDC);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosPushDCWithClear);

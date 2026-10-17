#include "common.h"

typedef struct DC
{
    u8 pad0[0x60];
    u64 unk60;
    u64 unk68;
    u64 unk70;
    u64 unk78;
    u64 unk80;
    u64 unk88;
    u64 unk90;
    u64 unk98;
    u8 padA0[0x30];
    u8 unkD0[0x90];
    s32 unk160;
    s32 unk164;
    s16 unk168;
    s16 unk16A;
    u8 unk16C;
    u8 unk16D;
    u8 unk16E;
    u8 unk16F;
    union
    {
        u64 unk170;
        struct
        {
            u32 unk170lo;
            s32 unk174;
        };
    };
    s32 unk178;
    s32 unk17C;
    s32 unk180;
    void *unk184;
} DC;

extern u8 D_40092688[];
extern DC *D_40092284[];
extern DC *D_40092288[];
extern DC *D_40045A00;
extern DC *D_40045A04;
extern s32 D_40045A08;

typedef struct DCObj
{
    s32 unk0;
    u8 pad4[0x18];
    DC *unk1C;
    s32 unk20;
} DCObj;

DCObj *_isysCreateObj();
void isysSetObjImmediateDeleteFunc(void *obj, void *func);
void *iosMallocAlign(s32, s32, s32);
void isysAddGroupWithLinkParam();
void func_40024A30(void);
void func_40024A38(void);
void func_40024218(DC *dc);
void iosDlChainTailCurrent();
void iosDlPushLayer();
void iosDlPopLayer();
void isysInitGroup(void *group);
void _isysDeleteGroup(void *obj, void *group, s32 flag);
void isysRequestDeleteObj(void *obj);

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", func_40024218);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosCreateDC);
DCObj *iosCreateDC(s32 arg0, s32 n)
{
    DCObj *obj;
    s32 size = n * 0x190;

    obj = _isysCreateObj(arg0, 0x1F, 0x24, size + 0x33, func_40024A30, 0x10);
    isysSetObjImmediateDeleteFunc(obj, func_40024A38);
    obj->unk20 = n;
    obj->unk1C = iosMallocAlign(obj->unk0, size, 0x10);
    obj->unk1C->unk184 = obj;
    obj->unk1C->unk170 &= ~1;
    obj->unk1C->unk170 &= ~2;
    isysAddGroupWithLinkParam(obj, &D_40092688, 0, 0);
    return obj;
}

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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosSetDCWithClear);
void iosSetDCWithClear(DC *dc, s32 clear)
{
    iosDlChainTailCurrent(dc);
    if (*(u32 *)&dc->unk170 & 1)
    {
        if (clear != 0)
        {
            iosDlChainTailCurrent(dc->unkD0);
        }
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", _iosPushDC);
void _iosPushDC(DC *dc, s32 clear)
{
    D_40092288[D_40045A08] = dc;
    D_40045A08++;
    iosDlChainTailCurrent(dc);
    if (*(u32 *)&dc->unk170 & 1)
    {
        if (clear != 0)
        {
            iosDlChainTailCurrent(dc->unkD0);
        }
    }
    D_40045A00 = dc;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosPushDCWithClear);
void iosPushDCWithClear(DC *dc)
{
    D_40092288[D_40045A08] = dc;
    D_40045A08++;
    iosDlChainTailCurrent(dc);
    if (*(u32 *)&dc->unk170 & 1)
    {
        iosDlChainTailCurrent(dc->unkD0);
    }
    D_40045A00 = dc;
}

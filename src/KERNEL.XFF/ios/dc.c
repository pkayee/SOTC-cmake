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

/* NEARMISS-STUB func_40024218 */
#if 0 /* NEARMISS 59.8% cat=struct-layout sub=- | DCFull struct-layout suspected: attempt needs DCFull typedef with sceGifTag which live dc.c lacks; only a 59.8% attempt, never diffed | attempts=1 */
typedef struct DCFull
{
    /* 0x00 */ u64 dmatag;
    /* 0x08 */ u32 vif0;
    /* 0x0C */ u32 vif1;
    /* 0x10 */ sceGifTag giftag;
    /* 0x20 */ u64 frame1;
    /* 0x28 */ u64 frame1addr;
    /* 0x30 */ u64 frame2;
    /* 0x38 */ u64 frame2addr;
    /* 0x40 */ u64 zbuf1;
    /* 0x48 */ u64 zbuf1addr;
    /* 0x50 */ u64 zbuf2;
    /* 0x58 */ u64 zbuf2addr;
    /* 0x60 */ u64 xyoffset1;
    /* 0x68 */ u64 xyoffset1addr;
    /* 0x70 */ u64 xyoffset2;
    /* 0x78 */ u64 xyoffset2addr;
    /* 0x80 */ u64 scissor1;
    /* 0x88 */ u64 scissor1addr;
    /* 0x90 */ u64 scissor2;
    /* 0x98 */ u64 scissor2addr;
    /* 0xA0 */ u64 dthe;
    /* 0xA8 */ u64 dtheaddr;
    /* 0xB0 */ u64 prmodecont;
    /* 0xB8 */ u64 prmodecontaddr;
    /* 0xC0 */ u32 endpad[3];
    /* 0xCC */ u32 endvif;
    /* 0xD0 */ u64 cdmatag;
    /* 0xD8 */ u32 cvif0;
    /* 0xDC */ u32 cvif1;
    /* 0xE0 */ sceGifTag cgiftag;
    /* 0xF0 */ u64 test1;
    /* 0xF8 */ u64 test1addr;
    /* 0x100 */ u64 prim;
    /* 0x108 */ u64 primaddr;
    /* 0x110 */ u64 rgbaq;
    /* 0x118 */ u64 rgbaqaddr;
    /* 0x120 */ u64 xyz2a;
    /* 0x128 */ u64 xyz2aaddr;
    /* 0x130 */ u64 xyz2b;
    /* 0x138 */ u64 xyz2baddr;
    /* 0x140 */ u64 test2;
    /* 0x148 */ u64 test2addr;
    /* 0x150 */ u32 cendpad[3];
    /* 0x15C */ u32 cendvif;
    /* 0x160 */ s32 fbp;
    /* 0x164 */ s32 zbp;
    /* 0x168 */ u16 w;
    /* 0x16A */ u16 h;
    /* 0x16C */ u8 r;
    /* 0x16D */ u8 g;
    /* 0x16E */ u8 b;
    /* 0x16F */ u8 a;
    /* 0x170 */ u64 flags;
} DCFull;

void func_40024218(DC *dc)
{
    DCFull *p = (DCFull *)dc;
    s32 w = p->w;
    s32 h = p->h;

    SCE_GIF_CLEAR_TAG(&p->giftag);
    p->giftag.NLOOP = 0xA;
    p->giftag.EOP = 1;
    p->giftag.NREG = 1;
    p->giftag.REGS0 = 0xE;
    p->dmatag = (u64)(p->giftag.NLOOP + 1) | 0x60000000;
    p->vif0 = 0x11000000;
    p->vif1 = 0x50000000 | (p->giftag.NLOOP + 1);
    p->frame1 = (u64)p->fbp | ((u64)((w >> 6) & 0x3F) << 16);
    p->frame1addr = 0x4C;
    p->frame2 = p->frame1;
    p->frame2addr = 0x4D;
    p->zbuf1 = (u64)p->zbp | 0x31000000;
    p->zbuf1addr = 0x4E;
    p->zbuf2 = p->zbuf1;
    p->zbuf2addr = 0x4F;
    p->xyoffset1 = (u64)((0x800 - (w >> 1)) << 4) | ((u64)(0x800 - (h >> 1)) << 36);
    p->xyoffset1addr = 0x18;
    p->xyoffset2 = p->xyoffset1;
    p->xyoffset2addr = 0x19;
    p->scissor1 = (u64)((w - 1) << 16) | ((u64)(h - 1) << 48);
    p->scissor1addr = 0x40;
    p->scissor2 = p->scissor1;
    p->scissor2addr = 0x41;
    p->dthe = (p->flags >> 1) & 1;
    p->dtheaddr = 0x45;
    p->prmodecont = 1;
    p->prmodecontaddr = 0x1A;
    p->endpad[0] = 0;
    p->endpad[1] = 0;
    p->endpad[2] = 0;
    p->endvif = 0x11000000;
    if ((u32)p->flags & 1)
    {
        SCE_GIF_CLEAR_TAG(&p->cgiftag);
        p->cgiftag.NLOOP = 6;
        p->cgiftag.EOP = 1;
        p->cgiftag.NREG = 1;
        p->cgiftag.REGS0 = 0xE;
        p->cdmatag = (u64)(p->cgiftag.NLOOP + 1) | 0x60000000;
        p->cvif0 = 0;
        p->cvif1 = 0x50000000 | (p->cgiftag.NLOOP + 1);
        p->test1 = 0x30000;
        p->test1addr = 0x47;
        p->prim = 6;
        p->primaddr = 0;
        p->rgbaq = (u64)p->r | ((u64)p->g << 8) | ((u64)p->b << 16) | ((u64)p->a << 24);
        p->rgbaqaddr = 1;
        p->xyz2a = (u64)((-(w >> 1)) << 4) | ((u64)(-(h >> 1)) << 20);
        p->xyz2aaddr = 4;
        p->xyz2b = (u64)((w >> 1) << 4) | ((u64)(h >> 1) << 20);
        p->xyz2baddr = 4;
        p->test2 = 0x5000D;
        p->test2addr = 0x47;
        p->cendpad[0] = 0;
        p->cendpad[1] = 0;
        p->cendpad[2] = 0;
        p->cendvif = 0x11000000;
    }
}
#endif
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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosSetDCViewPort);
void iosSetDCViewPort(DC *dc, s32 x, s32 y, s32 w, s32 h)
{
    s32 oy = 0x800 - y - h / 2;
    s32 sx = x + w - 1;
    s32 ox = 0x800 - x - w / 2;
    s32 sy = y + h - 1;
    u64 xyoff = ((u64)(oy << 4) << 32) | (u64)(ox << 4);
    u64 scis = (u64)x | ((u64)sx << 16) | ((u64)y << 32) | ((u64)sy << 48);

    dc->unk68 = 0x18;
    dc->unk78 = 0x19;
    dc->unk70 = xyoff;
    dc->unk60 = xyoff;
    dc->unk88 = 0x40;
    dc->unk98 = 0x41;
    dc->unk174 = x;
    dc->unk178 = y;
    dc->unk90 = scis;
    dc->unk17C = w;
    dc->unk180 = h;
    dc->unk80 = scis;
}

/* NEARMISS-STUB iosSetDCViewPortCenter */
#if 0 /* NEARMISS 99.09% cat=sched sub=addu-order | only diff: addu a7 (y+h) scheduled before addu v0 (x+w); operand swap and decl/stmt reorder tried (98.12-99.09) | attempts=4 */
// kR22 iosSetDCViewPortCenter best 99.09%: only diff addu a7 (y+h) emitted before addu v0 (x+w). tried: decl order, stmt order, operand swap (98.12 / 99.09)
void iosSetDCViewPortCenter(DC *dc, s32 x, s32 y, s32 w, s32 h, s32 cx, s32 cy)
{
    s32 sy = y + h - 1;
    s32 oy = 0x800 + cy;
    s32 ox = 0x800 + cx;
    s32 sx = x + w - 1;
    u64 xyoff = (u64)(ox << 4) | ((u64)(oy << 4) << 32);
    u64 scis = (u64)x | ((u64)sx << 16) | ((u64)y << 32) | ((u64)sy << 48);

    dc->unk70 = xyoff;
    dc->unk68 = 0x18;
    dc->unk78 = 0x19;
    dc->unk90 = scis;
    dc->unk60 = xyoff;
    dc->unk88 = 0x40;
    dc->unk98 = 0x41;
    dc->unk174 = x;
    dc->unk178 = y;
    dc->unk17C = w;
    dc->unk180 = h;
    dc->unk80 = scis;
}
#endif
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

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/dc", iosResetDC);
static inline void PushDC_i(DC *dc)
{
    D_40092288[D_40045A08] = dc;
    D_40045A08++;
    iosDlChainTailCurrent(dc);
    D_40045A00 = dc;
}

static inline void PushDCWithClear_i(DC *dc)
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

void iosResetDC(DC *dc)
{
    D_40045A04 = dc;
    D_40045A08 = 0;
    iosDlPushLayer(0);
    if (*(u32 *)&dc->unk170 & 1)
    {
        PushDCWithClear_i(dc);
    }
    else
    {
        PushDC_i(dc);
    }
    iosDlPopLayer();
}

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

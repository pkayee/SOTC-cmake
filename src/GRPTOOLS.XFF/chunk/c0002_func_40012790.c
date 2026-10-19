#include "common.h"

extern u8 *D_40016174;
extern u8 *D_400166FC;
void *NewCreateGameLightClass();
s32 GetToolNewNameNum();
extern s32 D_400166A0;
extern s32 D_40016100;
void func_40013120();
void func_40012130();
extern s32 padManagerData;
u8 *GetLightColMan(void);
void func_40011F50();
void func_40012E28();
s32 DebugDispGameLightClass(s32 a0, s32 a1, f32 f);
s32 DebugDispGlobalLightClass(s32 a0, s32 a1, f32 f);

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40012790);
s32 func_40012790()
{
    return DebugDispGameLightClass(*(s32 *)(D_40016174 + 0x58), 0, 3.0f);
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_400127C0);
void func_400127C0(void)
{
    u8 *p = D_40016174;
    u8 *q = *(u8 **)(p + 0x58);

    if (q != NULL)
    {
        func_40011F50(q, p);
    }
    p = D_40016174;
    if (p != NULL)
    {
        iosFree(p);
    }
    D_40016174 = NULL;
    D_40016100 = 0;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40012820);
void func_40012820(void)
{
    if (((s32 *)&padManagerData)[2] & 0x20)
    {
        u8 *p = D_40016174;
        s32 n = *(s32 *)(p + 0x64);

        if (n < 0x14)
        {
            u8 *g = NewCreateGameLightClass(0, GetToolNewNameNum(n));

            if (g != NULL)
            {
                *(s32 *)(p + 0x64) = *(s32 *)(p + 0x64) + 1;
            }
        }
    }
}

void func_40012890(void)
{
    u8 *base = D_40016174;
    u8 *p = *(u8 **)(base + 0x58);

    if (p != NULL)
    {
        func_40011F50(p, base);
    }
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_400128C8);
u8 *func_400128C8(void)
{
    return GetLightColMan() + 0x520;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_400128E8);
s32 func_400128E8(void)
{
    u8 *p = *(u8 **)(D_40016174 + 0x58);

    if (p)
    {
        return *(s32 *)(p + 0x30);
    }
    return 0;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40012908);

u8 *func_40012908(void) {
    return D_40016174 + 0x20;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40012918);

u8 *func_40012918(void) {
    return D_40016174 + 0x24;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40012928);

u8 *func_40012928(void) {
    return D_40016174 + 0x28;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40012938);

u8 *func_40012938(void) {
    return D_40016174 + 0x2C;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40012948);

u8 *func_40012948(void) {
    return D_40016174 + 0x30;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40012958);
u8 *func_40012958(void)
{
    u8 *p = D_40016174;

    if (*(f32 *)(p + 0x40) < *(f32 *)(p + 0x44))
    {
        *(f32 *)(p + 0x40) = *(f32 *)(p + 0x44);
    }
    return p + 0x40;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40012980);
u8 *func_40012980(void)
{
    u8 *p = D_40016174;

    if (*(f32 *)(p + 0x40) < *(f32 *)(p + 0x44))
    {
        *(f32 *)(p + 0x44) = *(f32 *)(p + 0x40);
    }
    return p + 0x44;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_400129A8);

u8 *func_400129A8(void) {
    return D_40016174 + 0x48;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_400129B8);

u8 *func_400129B8(void) {
    return D_40016174 + 0x34;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_400129C8);

u8 *func_400129C8(void) {
    return D_40016174 + 0x38;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_400129D8);
void func_400129D8(void)
{
    u8 *p = D_40016174;
    void *a = *(void **)(p + 0x60);

    *(s32 *)(p + 0x54) = 0;
    if (a != NULL)
    {
        iosFree(a);
        *(void **)(p + 0x60) = NULL;
    }
    if (*(void **)(p + 0x5C) != NULL)
    {
        iosFree(*(void **)(p + 0x5C));
        *(void **)(p + 0x5C) = NULL;
    }
}

void func_40012A30(s32 a0, s32 a1)
{
    u8 *p = D_40016174;

    if (*(u8 **)(p + 0x60) != NULL)
    {
        u8 *s = (u8 *)a1;
        u8 *v0 = *(u8 **)(s + 0x2C);
        u8 *tbl = *(u8 **)(*(u8 **)(v0 + 0x4) + 0x3E8);
        s32 val = ((s32 *)(*(u8 **)(p + 0x5C)))[*(s32 *)(tbl + 0x4)];

        *(s32 *)(p + 0x58) = val;
        func_40011D80(p, val);
        func_40012790(a0, a1);
    }
    return;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40012AA8);
void func_40012AA8(s32 a0, s32 a1)
{
    u8 *p;

    if (((s32 *)&padManagerData)[2] & 0x20)
    {
        p = D_40016174;
        if (*(s32 *)(p + 0x54) == 0)
        {
            func_40012130(a0, a1);
        }
    }
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40012AF0);

u8 *func_40012AF0(void) {
    return D_40016174 + 0x10;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40012B00);

u8 *func_40012B00(void) {
    return D_40016174 + 0x14;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40012B10);

u8 *func_40012B10(void) {
    return D_40016174 + 0x18;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40012B20);
u8 *func_40012B20(void)
{
    return D_40016174;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40012B30);

u8 *func_40012B30(void) {
    return D_40016174 + 0x4;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40012B40);

u8 *func_40012B40(void) {
    return D_40016174 + 0x8;
}

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40012B50);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40012E28);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013120);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_400132C8);

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_400137A8);

u8 *func_400137A8(void) {
    return D_400166FC + 0x7C;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_400137B8);
s32 func_400137B8()
{
    return DebugDispGlobalLightClass(*(s32 *)(D_400166FC + 0xF8), 0, 3.0f);
}

void func_400137E8(void)
{
    u8 *base = D_400166FC;
    u8 *p = *(u8 **)(base + 0xF8);

    if (p != NULL)
    {
        func_40012E28(p, base);
    }
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013820);
u8 *func_40013820(void)
{
    return GetLightColMan() + 0x510;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013840);
s32 func_40013840(void)
{
    u8 *p = *(u8 **)(D_400166FC + 0xF8);

    if (p)
    {
        return *(s32 *)(p + 0x114);
    }
    return 0;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013860);

u8 *func_40013860(void) {
    return D_400166FC + 0x5C;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013870);

u8 *func_40013870(void) {
    return D_400166FC + 0x60;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013880);

u8 *func_40013880(void) {
    return D_400166FC + 0x64;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013890);

u8 *func_40013890(void) {
    return D_400166FC + 0x68;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_400138A0);

u8 *func_400138A0(void) {
    return D_400166FC + 0x6C;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_400138B0);

u8 *func_400138B0(void) {
    return D_400166FC + 0xA0;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_400138C0);

u8 *func_400138C0(void) {
    return D_400166FC + 0xA4;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_400138D0);

u8 *func_400138D0(void) {
    return D_400166FC + 0xA8;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_400138E0);

u8 *func_400138E0(void) {
    return D_400166FC + 0xAC;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_400138F0);

u8 *func_400138F0(void) {
    return D_400166FC + 0xC0;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013900);

u8 *func_40013900(void) {
    return D_400166FC + 0xC4;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013910);

u8 *func_40013910(void) {
    return D_400166FC + 0xC8;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013920);

u8 *func_40013920(void) {
    return D_400166FC + 0xCC;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013930);

u8 *func_40013930(void) {
    return D_400166FC + 0xE0;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013940);

u8 *func_40013940(void) {
    return D_400166FC + 0xE4;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013950);

u8 *func_40013950(void) {
    return D_400166FC + 0xE8;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013960);

u8 *func_40013960(void) {
    return D_400166FC + 0xEC;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013970);

u8 *func_40013970(void) {
    return D_400166FC + 0x80;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013980);

u8 *func_40013980(void) {
    return D_400166FC + 0x50;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013990);

u8 *func_40013990(void) {
    return D_400166FC + 0x54;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_400139A0);
void func_400139A0(void)
{
    u8 *p = D_400166FC;
    void *a = *(void **)(p + 0x100);

    *(s32 *)(p + 0xF4) = 0;
    if (a != NULL)
    {
        iosFree(a);
        *(void **)(p + 0x100) = NULL;
    }
    if (*(void **)(p + 0xFC) != NULL)
    {
        iosFree(*(void **)(p + 0xFC));
        *(void **)(p + 0xFC) = NULL;
    }
}

void func_400139F8(s32 a0, s32 a1)
{
    u8 *p = D_400166FC;

    if (*(u8 **)(p + 0x100) != NULL)
    {
        u8 *s = (u8 *)a1;
        u8 *v0 = *(u8 **)(s + 0x2C);
        u8 *tbl = *(u8 **)(*(u8 **)(v0 + 0x4) + 0x3E8);
        s32 val = ((s32 *)(*(u8 **)(p + 0xFC)))[*(s32 *)(tbl + 0x4)];

        *(s32 *)(p + 0xF8) = val;
        func_40012B50(p, val);
        func_400137B8(a0, a1);
    }
    return;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013A70);
void func_40013A70(s32 a0, s32 a1)
{
    u8 *p;

    if (((s32 *)&padManagerData)[2] & 0x20)
    {
        p = D_400166FC;
        if (*(s32 *)(p + 0xF4) == 0)
        {
            func_40013120(a0, a1);
        }
    }
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013AB8);

u8 *func_40013AB8(void) {
    return D_400166FC + 0x10;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013AC8);

u8 *func_40013AC8(void) {
    return D_400166FC + 0x14;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013AD8);

u8 *func_40013AD8(void) {
    return D_400166FC + 0x18;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013AE8);

u8 *func_40013AE8(void) {
    return D_400166FC + 0x90;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013AF8);

u8 *func_40013AF8(void) {
    return D_400166FC + 0x94;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013B08);

u8 *func_40013B08(void) {
    return D_400166FC + 0x98;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013B18);

u8 *func_40013B18(void) {
    return D_400166FC + 0xB0;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013B28);

u8 *func_40013B28(void) {
    return D_400166FC + 0xB4;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013B38);

u8 *func_40013B38(void) {
    return D_400166FC + 0xB8;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013B48);

u8 *func_40013B48(void) {
    return D_400166FC + 0xD0;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013B58);

u8 *func_40013B58(void) {
    return D_400166FC + 0xD4;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013B68);

u8 *func_40013B68(void) {
    return D_400166FC + 0xD8;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013B78);
u8 *func_40013B78(void)
{
    return D_400166FC;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013B88);

u8 *func_40013B88(void) {
    return D_400166FC + 0x4;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013B98);

u8 *func_40013B98(void) {
    return D_400166FC + 0x8;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013BA8);
u8 *func_40013BA8(void)
{
    u8 *p = D_400166FC;

    if (*(f32 *)(p + 0x30) < *(f32 *)(p + 0x20))
    {
        *(f32 *)(p + 0x20) = *(f32 *)(p + 0x30);
    }
    return p + 0x20;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013BD0);
u8 *func_40013BD0(void)
{
    u8 *p = D_400166FC;

    if (*(f32 *)(p + 0x34) < *(f32 *)(p + 0x24))
    {
        *(f32 *)(p + 0x24) = *(f32 *)(p + 0x34);
    }
    return p + 0x24;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013BF8);
u8 *func_40013BF8(void)
{
    u8 *p = D_400166FC;

    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x28))
    {
        *(f32 *)(p + 0x28) = *(f32 *)(p + 0x38);
    }
    return p + 0x28;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013C20);
u8 *func_40013C20(void)
{
    u8 *p = D_400166FC;

    if (*(f32 *)(p + 0x30) < *(f32 *)(p + 0x20))
    {
        *(f32 *)(p + 0x30) = *(f32 *)(p + 0x20);
    }
    return p + 0x30;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013C48);
u8 *func_40013C48(void)
{
    u8 *p = D_400166FC;

    if (*(f32 *)(p + 0x34) < *(f32 *)(p + 0x24))
    {
        *(f32 *)(p + 0x34) = *(f32 *)(p + 0x24);
    }
    return p + 0x34;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013C70);
u8 *func_40013C70(void)
{
    u8 *p = D_400166FC;

    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x28))
    {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x28);
    }
    return p + 0x38;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013C98);

u8 *func_40013C98(void) {
    return D_400166FC + 0x40;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013CA8);

u8 *func_40013CA8(void) {
    return D_400166FC + 0x44;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013CB8);

u8 *func_40013CB8(void) {
    return D_400166FC + 0x48;
}

//INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0002_func_40012790", func_40013CC8);
void func_40013CC8(void)
{
    u8 *p = D_400166FC;
    u8 *q = *(u8 **)(p + 0xF8);

    if (q != NULL)
    {
        func_40012E28(q, p);
    }
    p = D_400166FC;
    if (p != NULL)
    {
        iosFree(p);
    }
    D_400166FC = NULL;
    D_400166A0 = 0;
}

#include "common.h"

u8 *getlv0_h(void);
u8 *getlv1_h(void);
u8 *getlv2_h(void);
u8 *getamb_r(void);
u8 *getlc0_r(void);
u8 *getlc1_r(void);
u8 *getlc2_r(void);
void InitStageLightColMan(u8 *a0, u8 *a1, s32 a2);
void CopyAmbFromAmbdef(void);
void rotLightVector(s32 idx, u8 *v);

INCLUDE_ASM("asm/GRPTOOLS.XFF/nonmatchings/chunk/c0003_create_global_light_param_menu", create_global_light_param_menu);

void func_40013E20(void)
{
    s32 i = 0;
    u8 *h;
    u8 *c;
    h = getlv0_h();
    c = getamb_r();
    InitStageLightColMan(h, c, 3);
    for (i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            h = getlv0_h();
            c = getlc0_r();
            InitStageLightColMan(h, c, 0);
            break;
        case 1:
            h = getlv1_h();
            c = getlc1_r();
            InitStageLightColMan(h, c, 1);
            break;
        case 2:
            h = getlv2_h();
            c = getlc2_r();
            InitStageLightColMan(h, c, 2);
            break;
        }
    }
    CopyAmbFromAmbdef();
}

void func_40013F28(void)
{
    s32 i = 0;
    u8 *h;
    u8 *c;
    rotLightVector(0, getlv0_h());
    h = getlv0_h();
    c = getamb_r();
    InitStageLightColMan(h, c, 3);
    for (i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            h = getlv0_h();
            c = getlc0_r();
            InitStageLightColMan(h, c, 0);
            break;
        case 1:
            h = getlv1_h();
            c = getlc1_r();
            InitStageLightColMan(h, c, 1);
            break;
        case 2:
            h = getlv2_h();
            c = getlc2_r();
            InitStageLightColMan(h, c, 2);
            break;
        }
    }
    CopyAmbFromAmbdef();
}

void func_40014048(void)
{
    s32 i = 0;
    u8 *h;
    u8 *c;
    rotLightVector(1, getlv1_h());
    h = getlv0_h();
    c = getamb_r();
    InitStageLightColMan(h, c, 3);
    for (i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            h = getlv0_h();
            c = getlc0_r();
            InitStageLightColMan(h, c, 0);
            break;
        case 1:
            h = getlv1_h();
            c = getlc1_r();
            InitStageLightColMan(h, c, 1);
            break;
        case 2:
            h = getlv2_h();
            c = getlc2_r();
            InitStageLightColMan(h, c, 2);
            break;
        }
    }
    CopyAmbFromAmbdef();
}

void func_40014168(void)
{
    s32 i = 0;
    u8 *h;
    u8 *c;
    rotLightVector(2, getlv2_h());
    h = getlv0_h();
    c = getamb_r();
    InitStageLightColMan(h, c, 3);
    for (i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            h = getlv0_h();
            c = getlc0_r();
            InitStageLightColMan(h, c, 0);
            break;
        case 1:
            h = getlv1_h();
            c = getlc1_r();
            InitStageLightColMan(h, c, 1);
            break;
        case 2:
            h = getlv2_h();
            c = getlc2_r();
            InitStageLightColMan(h, c, 2);
            break;
        }
    }
    CopyAmbFromAmbdef();
}

extern u8 D_40017920[];
void createParamMenu(u8 *a0, s32 a1);

u8 *createLightParamMenu(void)
{
    u8 *p = D_40017920;

    if (*(s32 *)(p + 0x30) != 0) return NULL;
    createParamMenu(p, 0);
    return p + 0x30;
}

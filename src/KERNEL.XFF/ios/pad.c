#include "common.h"

typedef struct
{
    u8 unk0[0x104];
    u8 buttonsLo;
    u8 buttonsHi;
    u8 analogLVer;
    u8 analogLHor;
    u8 analogRVer;
    u8 analogRHor;
    u8 unk10A[0x118 - 0x10A];
    s32 pad2State;
} t_padSysDataK;

typedef struct
{
    u32 cur;       // 00
    u32 prev;      // 04
    u32 pressed;   // 08
    u32 released;  // 0C
    u32 repeat;    // 10
    f32 timer[16]; // 14
    u8 unk54;      // 54
    u8 unk55;      // 55
    u8 unk56;      // 56
    u8 unk57;      // 57
    u8 shock[0x20]; // 58
} t_iosPadData;

extern t_iosPadData iosDefaultPadData[];
extern void (*D_40045718)(void);
extern void *ShockVoiceSetCommon;
extern u8 D_4004578C[];

t_padSysDataK *padSysGet(s32 padId, s32 arg1);
#include "ios/system.h"
void padSysTickProc(void);
void Shock_Decode(void *, void *, void *);
void Shock_SetMotor(s32, s32, void *, s32, s32);
void padSysVibSetAcrParam(t_padSysDataK *, void *);
void Init_Shock(void);
void Shock_SetShockVoiceSet(s32, void *);
void Init_Player(void *);
void Init_Controler(void *);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/pad", iosPadTickProc);
void iosPadTickProc(void)
{
    s32 i;
    s32 j;
    f32 now;
    t_iosPadData *d;
    t_padSysDataK *pad;
    u8 *sh;
    u32 mask;

    now = iosGetSecondFromTCount(iosGetTCountExtension());
    padSysTickProc();
    for (i = 0; i < 2; i++)
    {
        d = &iosDefaultPadData[i];
        pad = padSysGet(i, 0);
        d->prev = d->cur;
        d->cur = (pad->buttonsLo << 8) | pad->buttonsHi;
        d->repeat = 0;
        d->pressed = (d->cur ^ d->prev) & d->cur;
        d->released = (d->cur ^ d->prev) & ~d->cur;
        for (j = 0; j < 16; j++)
        {
            mask = 1 << j;
            if (*(volatile u32 *)&d->pressed & mask)
            {
                d->timer[j] = now + 0.4f;
            }
            else if ((d->cur & mask) && d->timer[j] < now)
            {
                d->timer[j] = now + 0.08f;
            }
            else
            {
                continue;
            }
            d->repeat |= mask;
        }
        d->unk56 = pad->analogLVer;
        d->unk57 = pad->analogLHor;
        d->unk54 = pad->analogRVer;
        d->unk55 = pad->analogRHor;
        sh = d->shock;
        Shock_Decode(sh, sh + 0x10, sh + 0x11);
        if (pad->pad2State == 1)
        {
            Shock_SetMotor(sh[0x10], sh[0x11], sh + 0x14, i, 0);
            padSysVibSetAcrParam(pad, sh + 0x18);
        }
    }
    if (D_40045718 != 0)
    {
        D_40045718();
    }
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/pad", iosPadGetXZInputL);
void iosPadGetXZInputL(f32 *arg0, t_iosPadData *arg1)
{
    f32 x;
    f32 z;
    f32 len;
    f32 sq;
    f32 inv;
    f32 nx;
    f32 nz;
    f32 ax;
    f32 az;
    f32 dx;
    f32 dz;

    x = arg1->unk54 * 0.007843137f - 1.0f;
    arg0[1] = 0.0f;
    arg0[0] = x;
    z = arg1->unk55 * 0.007843137f - 1.0f;
    arg0[3] = 0.0f;
    sq = x * x + z * z;
    arg0[2] = z;
    if (sq < 0.4f * 0.4f)
    {
        arg0[2] = arg0[1];
        arg0[0] = arg0[1];
        return;
    }
    asm("sqrt.s %0,%1" : "=f"(len) : "f"(sq));
    inv = 1.0f / len;
    nz = z * inv;
    nx = x * inv;
    if (len > 1.0f)
    {
        arg0[0] = nx;
        arg0[2] = nz;
        return;
    }
    ax = nx;
    if (ax < arg0[1])
    {
        ax = -ax;
    }
    az = nz;
    if (az < arg0[1])
    {
        az = -az;
    }
    dx = ax * 0.4f;
    dz = az * 0.4f;
    arg0[0] = ((x < arg0[1] ? -x : x) < dx)
        ? 0.0f
        : (arg0[0] < 0.0f ? -1.0f : 1.0f) * ((((arg0[0] < 0.0f) ? -arg0[0] : arg0[0]) - dx) * (ax / (ax - dx)));
    arg0[2] = ((arg0[2] < 0.0f ? -arg0[2] : arg0[2]) < dz)
        ? 0.0f
        : (arg0[2] < 0.0f ? -1.0f : 1.0f) * ((((arg0[2] < 0.0f) ? -arg0[2] : arg0[2]) - dz) * (az / (az - dz)));
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/pad", iosPadGetXZInputLwithThreshold);
void iosPadGetXZInputLwithThreshold(f32 *arg0, t_iosPadData *arg1, f32 threshold)
{
    f32 x;
    f32 z;
    f32 len;
    f32 sq;
    f32 inv;
    f32 nx;
    f32 nz;
    f32 ax;
    f32 az;
    f32 dx;
    f32 dz;

    x = arg1->unk54 * 0.007843137f - 1.0f;
    arg0[1] = 0.0f;
    arg0[0] = x;
    z = arg1->unk55 * 0.007843137f - 1.0f;
    arg0[3] = 0.0f;
    sq = x * x + z * z;
    arg0[2] = z;
    if (sq < threshold * threshold)
    {
        arg0[2] = arg0[1];
        arg0[0] = arg0[1];
        return;
    }
    asm("sqrt.s %0,%1" : "=f"(len) : "f"(sq));
    inv = 1.0f / len;
    nz = z * inv;
    nx = x * inv;
    if (len > 1.0f)
    {
        arg0[0] = nx;
        arg0[2] = nz;
        return;
    }
    ax = nx;
    if (ax < arg0[1])
    {
        ax = -ax;
    }
    az = nz;
    if (az < arg0[1])
    {
        az = -az;
    }
    dx = threshold * ax;
    dz = threshold * az;
    arg0[0] = ((x < arg0[1] ? -x : x) < dx)
        ? 0.0f
        : (arg0[0] < 0.0f ? -1.0f : 1.0f) * ((((arg0[0] < 0.0f) ? -arg0[0] : arg0[0]) - dx) * (ax / (ax - dx)));
    arg0[2] = ((arg0[2] < 0.0f ? -arg0[2] : arg0[2]) < dz)
        ? 0.0f
        : (arg0[2] < 0.0f ? -1.0f : 1.0f) * ((((arg0[2] < 0.0f) ? -arg0[2] : arg0[2]) - dz) * (az / (az - dz)));
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/pad", iosPadGetXZInputLwithThresholdIndepAxis);
void iosPadGetXZInputLwithThresholdIndepAxis(f32 *arg0, t_iosPadData *arg1, f32 threshold)
{
    f32 x;
    f32 z;

    x = arg1->unk54 * 0.007843137f - 1.0f;
    arg0[1] = 0.0f;
    arg0[0] = x;
    z = arg1->unk55 * 0.007843137f - 1.0f;
    arg0[3] = arg0[1];
    arg0[2] = z;
    arg0[0] = ((x < arg0[1] ? -x : x) < threshold)
        ? 0.0f
        : (arg0[0] < 0.0f ? -1.0f : 1.0f) * ((((arg0[0] < 0.0f) ? -arg0[0] : arg0[0]) - threshold) * (1.0f / (1.0f - threshold)));
    arg0[2] = ((arg0[2] < 0.0f ? -arg0[2] : arg0[2]) < threshold)
        ? 0.0f
        : (arg0[2] < 0.0f ? -1.0f : 1.0f) * ((((arg0[2] < 0.0f) ? -arg0[2] : arg0[2]) - threshold) * (1.0f / (1.0f - threshold)));
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/pad", iosPadGetXZInputR);
void iosPadGetXZInputR(f32 *arg0, t_iosPadData *arg1)
{
    f32 x;
    f32 z;
    f32 len;
    f32 sq;
    f32 inv;
    f32 nx;
    f32 nz;
    f32 ax;
    f32 az;
    f32 dx;
    f32 dz;

    x = arg1->unk56 * 0.007843137f - 1.0f;
    arg0[1] = 0.0f;
    arg0[0] = x;
    z = arg1->unk57 * 0.007843137f - 1.0f;
    arg0[3] = 0.0f;
    sq = x * x + z * z;
    arg0[2] = z;
    if (sq < 0.4f * 0.4f)
    {
        arg0[2] = arg0[1];
        arg0[0] = arg0[1];
        return;
    }
    asm("sqrt.s %0,%1" : "=f"(len) : "f"(sq));
    inv = 1.0f / len;
    nz = z * inv;
    nx = x * inv;
    if (len > 1.0f)
    {
        arg0[0] = nx;
        arg0[2] = nz;
        return;
    }
    ax = nx;
    if (ax < arg0[1])
    {
        ax = -ax;
    }
    az = nz;
    if (az < arg0[1])
    {
        az = -az;
    }
    dx = ax * 0.4f;
    dz = az * 0.4f;
    arg0[0] = ((x < arg0[1] ? -x : x) < dx)
        ? 0.0f
        : (arg0[0] < 0.0f ? -1.0f : 1.0f) * ((((arg0[0] < 0.0f) ? -arg0[0] : arg0[0]) - dx) * (ax / (ax - dx)));
    arg0[2] = ((arg0[2] < 0.0f ? -arg0[2] : arg0[2]) < dz)
        ? 0.0f
        : (arg0[2] < 0.0f ? -1.0f : 1.0f) * ((((arg0[2] < 0.0f) ? -arg0[2] : arg0[2]) - dz) * (az / (az - dz)));
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/pad", iosPadEntryTickFunc);
void iosPadEntryTickFunc(void (*arg0)(void))
{
    D_40045718 = arg0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/pad", iosPadRead);
void iosPadRead(s32 arg0, t_iosPadData *arg1)
{
    *arg1 = iosDefaultPadData[arg0];
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/pad", iosPadChkConnect);
s32 iosPadChkConnect(s32 arg0)
{
    return padSysGet(arg0, 0)->pad2State == 1;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/pad", iosPadInit);
void iosPadInit(void)
{
    Init_Shock();
    Shock_SetShockVoiceSet(0, ShockVoiceSetCommon);
    Init_Controler(D_4004578C);
    Init_Controler(D_4004578C + 0x78);
    Init_Player(D_4004578C - 0x14);
    Init_Player(D_4004578C + 0x64);
}

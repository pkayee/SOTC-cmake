#include "common.h"

typedef struct Iir {
    /* 0x00 */ s32 type;
    /* 0x04 */ f32 a0;
    /* 0x08 */ f32 a1;
    /* 0x0C */ f32 a2;
    /* 0x10 */ f32 b0;
    /* 0x14 */ f32 b1;
    /* 0x18 */ f32 b2;
    /* 0x1C */ f32 z[4];
    /* 0x2C */ f32 gain;
    /* 0x30 */ f32 freq;
    /* 0x34 */ f32 nb[5];
} Iir;

float sinf(float);
float cosf(float);
float powf(float, float);
double fptodp(f32);
f32 dptofp(s64);
s64 sqrt(double);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/iir", func_40041048);
void func_40041048(Iir *iir)
{
    f32 w0 = iir->freq / 48000.0f * 2.0f * 3.14159265f;
    f32 alpha = sinf(w0) / 6.0f;

    iir->b0 = (1.0f - cosf(w0)) * 0.5f;
    iir->b1 = 1.0f - cosf(w0);
    iir->b2 = (1.0f - cosf(w0)) * 0.5f;
    iir->a0 = 1.0f + alpha;
    iir->a1 = -2.0f * cosf(w0);
    iir->a2 = 1.0f - alpha;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/iir", func_40041148);
void func_40041148(Iir *iir)
{
    f32 w0 = iir->freq / 48000.0f * 2.0f * 3.14159265f;
    f32 alpha = sinf(w0) / 6.0f;

    iir->b0 = (1.0f + cosf(w0)) * 0.5f;
    iir->b1 = -(1.0f + cosf(w0));
    iir->b2 = (1.0f + cosf(w0)) * 0.5f;
    iir->a0 = 1.0f + alpha;
    iir->a1 = -2.0f * cosf(w0);
    iir->a2 = 1.0f - alpha;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/iir", func_40041248);
void func_40041248(Iir *iir)
{
    f32 A = powf(10.0f, iir->gain / 40.0f);
    f32 w0 = iir->freq / 48000.0f * 2.0f * 3.14159265f;
    f32 alpha = sinf(w0) / 6.0f;
    f32 alphaA = alpha * A;
    f32 alphaDivA = alpha / A;

    iir->b0 = 1.0f + alphaA;
    iir->b1 = -2.0f * cosf(w0);
    iir->b2 = 1.0f - alphaA;
    iir->a0 = 1.0f + alphaDivA;
    iir->a1 = -2.0f * cosf(w0);
    iir->a2 = 1.0f - alphaDivA;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/iir", func_40041370);
void func_40041370(Iir *iir)
{
    f32 A = powf(10.0f, iir->gain / 40.0f);
    f32 w0 = iir->freq / 48000.0f * 2.0f * 3.14159265f;
    f32 x = A * A + 1.0f - (A - 1.0f) * (A - 1.0f);
    f32 sq = dptofp(sqrt(fptodp(x)));

    iir->b0 = A * ((A + 1.0f) - (A - 1.0f) * cosf(w0) + sq * sinf(w0));
    iir->b1 = (A + A) * ((A - 1.0f) - (A + 1.0f) * cosf(w0));
    iir->b2 = A * ((A + 1.0f) - (A - 1.0f) * cosf(w0) - sq * sinf(w0));
    iir->a0 = (A + 1.0f) + (A - 1.0f) * cosf(w0) + sq * sinf(w0);
    iir->a1 = -2.0f * ((A - 1.0f) + (A + 1.0f) * cosf(w0));
    iir->a2 = (A + 1.0f) + (A - 1.0f) * cosf(w0) - sq * sinf(w0);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/iir", func_40041538);
void func_40041538(Iir *iir)
{
    f32 A = powf(10.0f, iir->gain / 40.0f);
    f32 w0 = iir->freq / 48000.0f * 2.0f * 3.14159265f;
    f32 sq = dptofp(sqrt(fptodp(A * A + 1.0f - (A - 1.0f) * (A - 1.0f))));

    iir->b0 = A * ((A + 1.0f) + (A - 1.0f) * cosf(w0) + sq * sinf(w0));
    iir->b1 = (A * -2.0f) * ((A - 1.0f) + (A + 1.0f) * cosf(w0));
    iir->b2 = A * ((A + 1.0f) + (A - 1.0f) * cosf(w0) - sq * sinf(w0));
    iir->a0 = (A + 1.0f) - (A - 1.0f) * cosf(w0) + sq * sinf(w0);
    iir->a1 = 2.0f * ((A - 1.0f) - (A + 1.0f) * cosf(w0));
    iir->a2 = (A + 1.0f) - (A - 1.0f) * cosf(w0) - sq * sinf(w0);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/iir", IirInit);
void IirInit(Iir *iir)
{
    iir->z[0] = 0.0f;
    iir->z[1] = 0.0f;
    iir->z[2] = 0.0f;
    iir->z[3] = 0.0f;
    iir->freq = 0.0f;
    iir->gain = 0.0f;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/iir", IirParam);
void IirParam(Iir *iir, s32 type, f32 freq, f32 gain)
{
    iir->freq = freq;
    iir->gain = gain;
    iir->type = type;

    switch (type) {
    case 1:
        func_40041248(iir);
        break;
    case 2:
        func_40041370(iir);
        break;
    case 3:
        func_40041538(iir);
        break;
    case 4:
        func_40041048(iir);
        break;
    case 5:
        func_40041148(iir);
        break;
    }

    iir->nb[0] = iir->b0 / iir->a0;
    iir->nb[1] = iir->b1 / iir->a0;
    iir->nb[2] = iir->b2 / iir->a0;
    iir->nb[3] = iir->a1 / iir->a0;
    iir->nb[4] = iir->a2 / iir->a0;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/Sg2/iir", IirFilter);
void IirFilter(Iir *iir, s32 n, f32 *buf)
{
    s32 i;
    f32 x[3];
    f32 b0 = iir->nb[0];
    f32 b1 = iir->nb[1];
    f32 b2 = iir->nb[2];
    f32 a1 = iir->nb[3];
    f32 a2 = iir->nb[4];
    f32 y0;
    f32 y1;

    x[0] = buf[0];
    x[1] = buf[1];
    x[2] = buf[2];

    y0 = b0 * x[0] + b1 * iir->z[1] + b2 * iir->z[0] - a1 * iir->z[3] - a2 * iir->z[2];
    buf[0] = y0;
    y1 = b0 * x[1] + b1 * x[0] + b2 * iir->z[1] - a1 * y0 - a2 * iir->z[3];
    buf[1] = y1;

    for (i = 2; i < n; i++) {
        buf[i] = b0 * x[2] + b1 * x[1] + b2 * x[0] - a1 * buf[i - 1] - a2 * buf[i - 2];
        x[0] = x[1];
        x[1] = x[2];
        x[2] = buf[i + 1];
    }

    iir->z[0] = x[0];
    iir->z[1] = x[1];
    iir->z[2] = buf[n - 2];
    iir->z[3] = buf[n - 1];
}

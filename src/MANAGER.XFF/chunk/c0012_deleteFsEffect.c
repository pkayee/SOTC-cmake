#include "common.h"

/* fog parameter block at D_401AAA08 (getters return field addresses) */
typedef struct FogParam {
    /* 0x00 */ s32 mode;
    /* 0x04 */ f32 nearDist;
    /* 0x08 */ f32 farDist;
    /* 0x0C */ f32 nearRate;
    /* 0x10 */ f32 farRate;
    /* 0x14 */ f32 rate;
    /* 0x18 */ s32 offset;
    /* 0x1C */ s32 colorR;
    /* 0x20 */ s32 colorG;
    /* 0x24 */ s32 colorB;
} FogParam;

/* D_401AAA30: fog factor block, floats at +0x04..+0x14 */
typedef struct FogFactor {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ f32 a;
    /* 0x08 */ f32 b;
    /* 0x0C */ f32 c;
    /* 0x10 */ f32 d;
    /* 0x14 */ f32 e;
} FogFactor;

/* current/reset fs effect node: priority at +0x04 */
typedef struct FsEffect {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 prio;
} FsEffect;

/* SeemlessInitFogTargetParamWorldLayout argument */
typedef struct FogSrc {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ f32 nearDist;
    /* 0x24 */ f32 farDist;
    /* 0x28 */ f32 nearRate;
    /* 0x2C */ f32 farRate;
    /* 0x30 */ u8 offset;
    /* 0x31 */ u8 colorR;
    /* 0x32 */ u8 colorG;
    /* 0x33 */ u8 colorB;
} FogSrc;

extern FogParam D_401AAA08;
extern s32 D_401AAA0C;
extern s32 D_401AAA10;
extern s32 D_401AAA14;
extern s32 D_401AAA18;
extern s32 D_401AAA1C;
extern s32 D_401AAA20;
extern s32 D_401AAA24;
extern s32 D_401AAA28;
extern s32 D_401AAA2C;
extern FogFactor D_401AAA30;
extern s32 D_401AAA4C;
extern s32 D_401AAA50;
extern s32 D_4012485C;
extern s32 D_40124858;
extern f32 D_40124854;
extern s32 D_40124850;
extern f32 D_401AAA58;
extern f32 D_401AAA5C;
extern f32 D_401AAA60;
extern FsEffect *D_40124820;
extern FsEffect *FsEffect_RESET;
extern s32 DldSysUndefSymbol;
extern u8 SH_FsEffectDEFAULT[];
void setFogImmediate(void);
void iosSetBGColor(s32 r, s32 g, s32 b);
void isysSleepSubThread(void);

void deleteFsEffect(void) {
}

typedef struct FogInitSrc {
    /* 0x00 */ s32 enable;
    /* 0x04 */ f32 nearDist;
    /* 0x08 */ f32 farDist;
    /* 0x0C */ f32 nearRate;
    /* 0x10 */ f32 farRate;
    /* 0x14 */ s32 colorR;
    /* 0x18 */ s32 colorG;
    /* 0x1C */ s32 colorB;
    /* 0x20 */ s32 offset;
} FogInitSrc;

void *getFogNearDist(void);
void *getFogFarDist(void);
void *getFogNearRate(void);
void *getFogFarRate(void);
void *getFogColorR(void);
void *getFogColorG(void);
void *getFogColorB(void);
void *getFogOffset(void);
void changeFogParam(void);

void initFogEffect(s32 *a0) {
    FogInitSrc *p = (FogInitSrc *)a0[4];

    if (p->enable != 0) {
        if (p->nearDist != -1.0f) {
            *(f32 *)getFogNearDist() = p->nearDist;
        }
        if (p->farDist != -1.0f) {
            *(f32 *)getFogFarDist() = p->farDist;
        }
        if (p->nearRate != -1.0f) {
            *(f32 *)getFogNearRate() = p->nearRate;
        }
        if (p->farRate != -1.0f) {
            *(f32 *)getFogFarRate() = p->farRate;
        }
        if (p->colorR != -1) {
            *(s32 *)getFogColorR() = p->colorR;
        }
        if (p->colorG != -1) {
            *(s32 *)getFogColorG() = p->colorG;
        }
        if (p->colorB != -1) {
            *(s32 *)getFogColorB() = p->colorB;
        }
        if (p->offset != -1) {
            *(s32 *)getFogOffset() = p->offset;
        }
        changeFogParam();
    }
}

void deleteFogEffect(void) {
}

FsEffect *getCurrentFsEffect(void) {
    return D_40124820;
}

void func_40022710(void) {
    u8 *p = SH_FsEffectDEFAULT;

    if (DldSysUndefSymbol == (s32)SH_FsEffectDEFAULT) {
        p = NULL;
    }
    if (p != NULL && FsEffect_RESET != NULL) {
        if (D_40124820 == NULL) {
            D_40124820 = FsEffect_RESET;
        } else if (D_40124820->prio <= FsEffect_RESET->prio) {
            D_40124820 = FsEffect_RESET;
        }
    }
}

void func_40022768(FsEffect *p) {
    while (1) {
        if (p != NULL) {
            if (D_40124820 == NULL) {
                D_40124820 = p;
            } else if (!(p->prio < D_40124820->prio)) {
                D_40124820 = p;
            }
        }
        isysSleepSubThread();
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0012_deleteFsEffect", foginterp);

void graphSetFogParam(f32 a, f32 b, s32 c, s32 d, s32 e, s32 f);

void setFogImmediate(void) {
    FogParam *t = (FogParam *)&D_401AAA30;
    s32 r;
    s32 g;
    s32 b;

    *t = D_401AAA08;
    r = (s32)((f32)t->colorR * D_40124854);
    g = (s32)((f32)t->colorG * D_40124854);
    b = (s32)((f32)t->colorB * D_40124854);
    if (t->mode != 0) {
        graphSetFogParam(0.0f, 510.0f, r, g, b, t->offset);
    } else {
        graphSetFogParam(((t->farDist * t->nearDist) * (t->nearRate - t->farRate))
                         / (t->farDist - t->nearDist),
                         (((t->farRate - t->nearRate) * (t->farDist + t->nearDist))
                          / (t->farDist - t->nearDist) + (t->farRate + t->nearRate)) * t->rate,
                         r, g, b, t->offset);
    }
    if (D_4012485C != 0) {
        iosSetBGColor((s32)D_401AAA58, (s32)D_401AAA5C, (s32)D_401AAA60);
    } else {
        iosSetBGColor(r, g, b);
    }
    D_40124854 = 1.0f;
}

s32 GetNowFogColorR(void) {
    return D_401AAA4C;
}

s32 GetNowFogColorG(void) {
    return D_401AAA50;
}

s32 GetNowFogColorB(void) {
    return D_401AAA50;
}

void *getFogMode(void) {
    return &D_401AAA08;
}

void *getFogNearDist(void) {
    return &D_401AAA0C;
}

void *getFogFarDist(void) {
    return &D_401AAA10;
}

void *getFogNearRate(void) {
    return &D_401AAA14;
}

void *getFogFarRate(void) {
    return &D_401AAA18;
}

void *getFogRate(void) {
    return &D_401AAA1C;
}

void *getFogOffset(void) {
    return &D_401AAA20;
}

void *getFogUnderWater(void) {
    return &D_40124858;
}

void *getFogColorR(void) {
    return &D_401AAA24;
}

void *getFogColorG(void) {
    return &D_401AAA28;
}

void *getFogColorB(void) {
    return &D_401AAA2C;
}

void changeFogParam(void) {
    setFogImmediate();
}

void SetAndLockBgColor(s32 r, s32 g, s32 b) {
    D_4012485C = 1;
    D_401AAA58 = (f32)r;
    D_401AAA5C = (f32)g;
    D_401AAA60 = (f32)b;
    iosSetBGColor((s32)D_401AAA58, (s32)D_401AAA5C, (s32)D_401AAA60);
}

void UnlockBgColor(void) {
    D_4012485C = 0;
}

void SeemlessInitFogTargetParamWorldLayout(FogSrc *src) {
    FogParam *dst = &D_401AAA08;

    dst->nearDist = src->nearDist;
    dst->farDist = src->farDist;
    dst->nearRate = src->nearRate;
    dst->farRate = src->farRate;
    dst->rate = 1.0f;
    dst->offset = src->offset;
    dst->colorR = src->colorR;
    dst->colorG = src->colorG;
    dst->colorB = src->colorB;
    D_40124850 = 0x78;
}

extern FogParam D_40124828;

void setFogParamDefault(void) {
    *(FogParam *)&D_401AAA30 = D_40124828;
    D_401AAA08 = *(FogParam *)&D_401AAA30;
}

void fogSetFogColorMulRatio(f32 ratio) {
    D_40124854 = ratio;
}

f32 getFogFactor0(void) {
    FogFactor *p = &D_401AAA30;

    return (p->b * p->a) * (p->c - p->d) / (p->b - p->a);
}

f32 getFogFactor1(void) {
    FogFactor *p = &D_401AAA30;

    return ((p->d - p->c) * (p->b + p->a) / (p->b - p->a) + (p->d + p->c)) * p->e;
}

extern s32 D_40124860;

void iosDlPushLayer(s32 layer);
void iosDlPopLayer(void);
s32 gsRegBegin(void); /* int: its call_value keeps v0 busy, so the (u64)a0 << 32 temp lands in v1 */
void gsRegEnd(void);
void gsReg(s32, u64);
s32 getDispScreenWidth(void);
s32 getDispScreenHeight(void);
s32 getDrawScreenWidth(void);
s32 getDrawScreenHeight(void);
s32 getDispBufferAddressTBP(void);
s32 getTWH(s32 n);

void drawBlur(s32 a0) {
    s32 dispW = getDispScreenWidth();
    s32 dispH = getDispScreenHeight();
    s32 drawW = getDrawScreenWidth();
    s32 drawH = getDrawScreenHeight();
    s32 halfW = drawW >> 1;
    s32 halfH = drawH >> 1;
    s32 tbp;
    s32 twhH;
    s32 twhW;
    u64 lo;
    u64 hi;

    if (D_40124860 > 0) {
        D_40124860 = D_40124860 - 1;
        return;
    }
    if (a0 == 0) {
        return;
    }
    iosDlPushLayer(0x15);
    gsRegBegin();
    gsReg(0x42, ((u64)a0 << 32) | 0x64);
    gsReg(0x47, 0x31001);
    gsReg(0x49, 0);
    gsReg(0x3B, 0x0000008000000080ULL);
    gsReg(0x14, 0x20);
    tbp = getDispBufferAddressTBP();
    twhH = getTWH(dispH);
    twhW = getTWH(dispW);
    lo = (u64)tbp | ((u64)twhH << 30);
    hi = ((u64)twhW << 26) | ((u64)(dispW / 64) << 14);
    gsReg(6, lo | hi);
    gsReg(0, 0x156);
    gsReg(1, 0x3F80000080808080ULL);
    gsReg(3, 0x80008);
    gsReg(4, ((u64)((0x800 - halfH) << 4) << 16 | (u64)((0x800 - halfW) << 4)) | 0xFFFFFFFF00000000ULL);
    gsReg(3, (u64)((dispW << 4) + 8) | ((u64)((dispH << 4) + 9) << 16));
    gsReg(4, (u64)((halfW + 0x800) << 4) | ((u64)((halfH + 0x800) << 4) << 16) | 0xFFFFFFFF00000000ULL);
    gsReg(0x47, 0x5178D);
    gsRegEnd();
    iosDlPopLayer();
}

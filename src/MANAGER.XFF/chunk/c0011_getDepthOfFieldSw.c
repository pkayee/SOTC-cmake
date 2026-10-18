#include "common.h"

extern s32 D_40124800;
extern s32 D_40124804;
extern s32 D_40124808;
extern s32 D_4012480C;
extern s32 D_40124820;
extern s32 D_40124824;

s32 *getDepthOfFieldSw(void)
{
    return &D_40124800;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0011_getDepthOfFieldSw", getDepthOfFieldLevel);
s32 *getDepthOfFieldLevel(void)
{
    return &D_40124804;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0011_getDepthOfFieldSw", getDepthOfFieldPlanes);
s32 *getDepthOfFieldPlanes(void)
{
    return &D_40124808;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0011_getDepthOfFieldSw", getDepthOfFieldNearZ);
s32 *getDepthOfFieldNearZ(void)
{
    return &D_4012480C;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0011_getDepthOfFieldSw", func_40021940);

/* NEARMISS-STUB effectSet */
#if 0 /* NEARMISS 94.6% cat=regalloc sub=hi-hoist | target hoists lui %hi(D_40124820) into s1 and rematerialises addiu(s1,lo) for the +4 load; ours emits a fresh lui per access (+4 folded into %hi(sym+4)); 1 extr | attempts=1 */
typedef struct FogInitSrc {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ f32 nearDist;
    /* 0x08 */ f32 farDist;
    /* 0x0C */ f32 nearRate;
    /* 0x10 */ f32 farRate;
    /* 0x14 */ s32 colorR;
    /* 0x18 */ s32 colorG;
    /* 0x1C */ s32 colorB;
    /* 0x20 */ s32 offset;
} FogInitSrc;

void cameraBlurClearIntensityArray(void);
void func_40021940(s32 a0);
void *getFogNearDist(void);
void *getFogFarDist(void);
void *getFogNearRate(void);
void *getFogFarRate(void);
void *getFogColorR(void);
void *getFogColorG(void);
void *getFogColorB(void);
void *getFogOffset(void);
void changeFogParam(void);

void effectSet(void)
{
    s32 *g = &D_40124820;
    FogInitSrc *p;

    if (g[0] != 0) {
        if (*(s32 *)(g[0] + 4) >= 100) {
            cameraBlurClearIntensityArray();
        }
        func_40021940(g[0]);
    }
    p = *(FogInitSrc **)((u8 *)&D_40124820 + 4);
    if (p != NULL) {
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
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0011_getDepthOfFieldSw", effectSet);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0011_getDepthOfFieldSw", fsEffectSetParam);
/* current/reset fs effect node: priority at +0x04 */
typedef struct FsEffect {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 prio;
} FsEffect;

void fsEffectSetParam(FsEffect *p)
{
    FsEffect *cur;

    if (p == NULL) {
        return;
    }
    cur = (FsEffect *)D_40124820;
    if (cur == NULL) {
        D_40124820 = (s32)p;
        return;
    }
    if (!(p->prio < cur->prio)) {
        D_40124820 = (s32)p;
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0011_getDepthOfFieldSw", fsEffectSetParamSheetSeg);
extern s32 DldSysUndefSymbol;

void fsEffectSetParamSheetSeg(u32 *param_1)
{
    u32 w;
    u32 off;
    s32 *n;
    FsEffect *cur;
    s32 r;

    w = *param_1;
    off = w & 0x3ffff;
    if (off != 0) {
        n = *(s32 **)((u8 *)param_1 - off);
    } else {
        n = NULL;
    }
    if (n != NULL && (s32)n != DldSysUndefSymbol) {
        r = n[4] + ((w >> 18) & 0xfff) * ((s32 *)n[2])[3];
    } else {
        r = 0;
    }
    if (r != 0) {
        cur = (FsEffect *)D_40124820;
        if (cur == NULL) {
            D_40124820 = r;
        } else if (!(((FsEffect *)r)->prio < cur->prio)) {
            D_40124820 = r;
        }
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0011_getDepthOfFieldSw", fogEffectSetParam);
void fogEffectSetParam(s32 value)
{
    D_40124824 = value;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0011_getDepthOfFieldSw", effectReset);
void fsEffectDefault(void);

void effectReset(void)
{
    s32 *p = &D_40124820;

    p[0] = 0;
    p[1] = 0;
    fsEffectDefault();
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0011_getDepthOfFieldSw", fsEffectCreateSetScript);
extern s32 rootPtn;
void func_40022768(void);
void func_40022710(void);
s32 createScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, void *a6, s32 a7);
void SetScriptObjDeleteCallBackFunc(s32 obj, void *fn, s32 a2);

s32 fsEffectCreateSetScript(s32 a0, s32 a1, s32 a2)
{
    s32 r = createScriptObj((void *)func_40022768, a2, (void *)&rootPtn, 0x2000, 0, 8, (void *)a1, 0);

    if (r != 0)
    {
        SetScriptObjDeleteCallBackFunc(r, (void *)func_40022710, a2);
    }
    return r;
}

/* NEARMISS-STUB fsEffectManagerSetDemoParam */
#if 0 /* NEARMISS 84.02% cat=regalloc sub=- | second DLD resolve base in a1 vs a0; lui placement | attempts=1 */
void fsEffectManagerSetDemoParam(u32 *param_1)
{
    u32 *ref;
    u32 off;
    s32 *n;
    FsEffect *e;
    FsEffect *cur;
    s32 r;

    ref = &param_1[1];
    off = *ref & 0x3ffff;
    if (off != 0) {
        n = *(s32 **)((u8 *)ref - off);
    } else {
        n = NULL;
    }
    if (n == NULL || (s32)n == DldSysUndefSymbol) {
        e = NULL;
    } else {
        e = (FsEffect *)n[4];
    }

    ref = &param_1[2];
    off = *ref & 0x3ffff;
    if (off != 0) {
        n = *(s32 **)((u8 *)ref - off);
    } else {
        n = NULL;
    }
    if (n == NULL || (s32)n == DldSysUndefSymbol) {
        r = 0;
    } else {
        r = n[4];
    }

    if (e != NULL) {
        cur = (FsEffect *)D_40124820;
        if (cur == NULL) {
            D_40124820 = (s32)e;
        } else if (!(e->prio < cur->prio)) {
            D_40124820 = (s32)e;
        }
    }
    D_40124824 = r;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0011_getDepthOfFieldSw", fsEffectManagerSetDemoParam);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0011_getDepthOfFieldSw", fsEffectReset);
void skipBlur(s32 flag);
void solarFlareReset(void);

void fsEffectReset(void)
{
    skipBlur(1);
    solarFlareReset();
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0011_getDepthOfFieldSw", fsEffectDefault);
extern u8 SH_FsEffectDEFAULT[];
extern s32 DldSysUndefSymbol;
extern FsEffect D_401AA950;

void fsEffectDefault(void)
{
    u8 *p = SH_FsEffectDEFAULT;

    if (DldSysUndefSymbol == (s32)SH_FsEffectDEFAULT) {
        p = NULL;
    }
    if (p != NULL && &D_401AA950 != NULL) {
        if (D_40124820 == 0) {
            D_40124820 = (s32)&D_401AA950;
        } else if (!(D_401AA950.prio < ((FsEffect *)D_40124820)->prio)) {
            D_40124820 = (s32)&D_401AA950;
        }
    }
}

/* NEARMISS-STUB fsEffectManagerInit */
#if 0 /* NEARMISS 45.17% cat=inline-unroll sub=- | runtime-alignment struct copy (ld/sd unrolled vs ldl/ldr) inlined memcpy | attempts=1 */
extern s32 FsEffect_DEFAULT;

typedef struct FsEffectBlk {
    u64 d[22];
    u32 t;
} FsEffectBlk;

void fsEffectManagerInit(void)
{
    u8 *src;
    u8 *dst;
    u64 *s;
    u64 *d;
    u64 a;
    u64 b;
    u64 c;
    u64 e;

    if (FsEffect_DEFAULT != 0) {
        src = (u8 *)FsEffect_DEFAULT;
        dst = (u8 *)&D_401AA950;
        if ((((u32)src | (u32)dst) & 7) == 0) {
            s = (u64 *)src;
            d = (u64 *)dst;
            do {
                a = s[0];
                b = s[1];
                c = s[2];
                e = s[3];
                d[0] = a;
                d[1] = b;
                d[2] = c;
                d[3] = e;
                s += 4;
                d += 4;
            } while (s != (u64 *)(src + 0xA0));
        } else {
            *(FsEffectBlk *)dst = *(FsEffectBlk *)src;
        }
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0011_getDepthOfFieldSw", fsEffectManagerInit);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0011_getDepthOfFieldSw", initFsEffect);

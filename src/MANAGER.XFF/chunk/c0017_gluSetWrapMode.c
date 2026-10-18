#include "common.h"

typedef struct GEnv {
    /* 0x00 */ s32 vramImage;
    /* 0x04 */ s32 vramClut;
    /* 0x08 */ s32 vramEffect;
    /* 0x0C */ s32 fogR;
    /* 0x10 */ s32 fogG;
    /* 0x14 */ s32 fogB;
    /* 0x18 */ f32 fogNear;
    /* 0x1C */ f32 fogFar;
    /* 0x20 */ s32 fogMode;
    /* 0x24 */ f32 time;
} GEnv;
extern GEnv genv;

extern s32 D_40129C70;
extern s32 D_40129C74;
extern s32 D_40129C78;
extern s32 D_40129C7C;
extern f32 FBOfs;
extern f32 D_40129C84;
extern f32 D_40129C88;
extern f32 D_40129C8C;
extern u8 D_40129C90[];
extern u8 D_40129B10[];
extern u8 D_40129D20[];
extern f32 D_40129DF0;
extern s32 D_40129DF4;
extern s32 D_40129DF8;
extern s32 D_401248E0;
extern s32 D_401248F8;
extern s32 D_40124920;
extern u8 D_401248C0[];
extern const char D_40130528[];
extern const char D_40130530[];
extern const char D_40130538[];

s32 get_cur_camera_context(void);
void iosDlPushLayer(s32);
void iosDlPopLayer(void);
void iosDlChainTailCurrent(void *);
s32 iosDlGetWorkBufId(void);
s32 iosDlGetLayerNum(void);
void iosGsSetMode();
void iosGsChangeMode(void);
s32 getFrameBufferSizeTBP(void);
s32 vramCreateBlock(const char *, s32, s32, s32);
void vramDeleteBlock(s32);
void vramInit(void);
void vramEnd(void);
void shadowReInit(void);
void windowReInit(void);
void effectSet(void);
void bgBegin(void);
void shadowReset(void);
void waterRefractionBegin(f32);
void refractionBegin(f32);
void reflectionBegin(f32);
void depthOfField(void);
s32 bossDeathEffectBegin(f32);
void effectReset(void);
void texReset(s32, f32);
void glReset(void);
void windowSetMouseStatus(void);
void resetMicroCodeManager(void);
void bossDeathEffectEnd(void);
void solarFlare(void);
void reflectionEnd(void);
void refractionEnd(void);
void waterRefractionEnd(void);
void shadowDraw(void);
void bgEnd(void);
s32 *getFogMode(void);
void zFog(void);
void drawBlur(void);
void drawCameraBlur(s32, f32);
void screenBrightness(s32);
void drawFrontFog(void);
void iosSetRootDC(void);
void texInit(s32);
void modelInit(s32);
void kInit(void);
void windowInit(void);
void lineObjectInit(void);
void shadowInit(void);
void refractionInit(void);
void zFogInit(void);
void glBeginWithDlLayerNo(s32, s32);
void glEnd(void);
s32 iosDlGetLayer();
void effectSetX(void);

/* NEARMISS-STUB gluSetWrapMode */
#if 0 /* NEARMISS 92.9% cat=cse-hoist sub=dl-ptr-stores | dl pointer at D_401248C0+4: target keeps both 'sw v0,0(a1)' (q+1 stored after each push) and the second push uses addiu v0,v0,8; ours folds into one store with  | attempts=1 */
void gluSetWrapMode(s32 a, s32 b) {
    u64 v;
    u64 **pp;
    u8 *g;

    glBeginWithDlLayerNo(8, iosDlGetLayer());
    g = D_401248C0;
    pp = (u64 **)(g + 4);
    v = (a == 0);
    if (b == 0) {
        v |= 4;
    }
    {
        u64 *q = *pp;
        *q = v;
        *pp = q + 1;
    }
    {
        u64 *q = *pp;
        *q = 8;
        *pp = q + 1;
    }
    glEnd();
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0017_gluSetWrapMode", gluSetWrapMode);

void iosgluGetCameraContext(void) {
    get_cur_camera_context();
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0017_gluSetWrapMode", glSetFogFactor);

void glSetFogFactorDirect(s32 arg0) {
    D_40124920 = arg0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0017_gluSetWrapMode", gluGetLookAtPosition);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0017_gluSetWrapMode", iosgluGetViewCoordPosition);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0017_gluSetWrapMode", gluGetCameraSpaceXYZ);

void gluUpdateCameraContext(void) {
    *(s32 *)D_401248C0 = get_cur_camera_context();
}

f32 gluGetBrightness(f32 *c) {
    return c[0] * 0.299f + c[1] * 0.587f + c[2] * 0.114f;
}

void printGifTag(void) {
}

void printPrimReg(void) {
}

s32 glGetZWrite(void) {
    return D_401248F8;
}

s32 glGetLineSmooth(void) {
    return D_401248E0;
}

/* NEARMISS-STUB func_40028860 */
#if 0 /* NEARMISS 6.65% cat=sched sub=lq-sq-counter | three u128 copies via lq/sq: target stores the counter (sw t1,0x780) LAST, ours hoists it above the 2nd/3rd copy (s32 vs u128 no alias); volatile on any of the  | attempts=1 */
void func_40028860(u8 *dst, u8 *src, s32 idx) {
    s32 n = *(s32 *)(dst + 0x780);
    u8 *d = dst + n * 16;
    u8 *s = src + idx * 16;

    *(u128 *)(d + 0x180) = *(u128 *)(s + 0x180);
    *(u128 *)(d + 0x480) = *(u128 *)(s + 0x480);
    *(u128 *)(d + 0x600) = *(u128 *)(s + 0x600);
    *(volatile s32 *)(dst + 0x780) = n + 1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0017_gluSetWrapMode", func_40028860);

void setv3f(void) {
}

void glResetWithLayerNo(s32 layer) {
    iosDlPushLayer(layer);
    iosDlChainTailCurrent(D_40129B10);
    iosDlPopLayer();
}

/* NEARMISS-STUB graphFrameFinish */
#if 0 /* NEARMISS 98.94% cat=regalloc sub=blur-a0 | blur value: target keeps D_40129C70 in a0 (lw a0; blez a0; bgez a0; negu v0,a0), ours v0 + extra reload/bgezl; local var for the value did not change it | attempts=1 */
void graphFrameFinish(void) {
    s32 blur;

    if (D_40129C7C != 0) {
        if (D_40129C78 != 0 && D_40129DF8 == 0) {
            bossDeathEffectEnd();
            solarFlare();
            reflectionEnd();
            refractionEnd();
            waterRefractionEnd();
            shadowDraw();
            bgEnd();
            if (*getFogMode() != 0) {
                zFog();
            }
            blur = D_40129C70;
            if (blur > 0) {
                drawBlur();
            } else if (blur < 0) {
                D_40129C70 = -blur;
            }
            drawCameraBlur(1, D_40129DF0);
            screenBrightness(D_40129C74);
            drawFrontFog();
        }
        iosDlPushLayer(0x18);
        iosSetRootDC();
        iosDlPopLayer();
        iosDlPushLayer(0x15);
        iosSetRootDC();
        iosDlPopLayer();
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0017_gluSetWrapMode", graphFrameFinish);

void LockFullScreenEffect(void) {
    D_40129DF8 = 1;
}

void UnlockFullScreenEffect(void) {
    D_40129DF8 = 0;
}

void graphSetFogParam(s32 r, s32 g, s32 b, s32 mode, f32 near, f32 far) {
    genv.fogMode = mode;
    genv.fogNear = near;
    genv.fogFar = far;
    genv.fogG = g;
    genv.fogB = b;
    genv.fogR = r;
    *(u64 *)(D_40129D20 + iosDlGetWorkBufId() * 0xB0) = r | ((u64)g << 8) | ((u64)b << 16);
}

s32 *getMBlur(void) {
    return &D_40129C70;
}

void setMBlur(s32 arg0) {
    D_40129C70 = arg0;
}

s32 *getBrightness(void) {
    return &D_40129C74;
}

void graphFrameBufferReInitialize(void) {
    s32 a;

    if (D_40129DF4 != 0) {
        D_40129DF4 = 0;
        iosGsChangeMode();
        vramDeleteBlock(genv.vramImage);
        vramDeleteBlock(genv.vramClut);
        vramDeleteBlock(genv.vramEffect);
        vramEnd();
        vramInit();
        a = getFrameBufferSizeTBP();
        genv.vramImage = vramCreateBlock(D_40130528, 0, a, 0x3F3B - getFrameBufferSizeTBP());
        genv.vramClut = vramCreateBlock(D_40130530, 1, 0x3F3B, 0x7D);
        genv.vramEffect = vramCreateBlock(D_40130538, 0, 0x3FC0, 0x40);
        shadowReInit();
        windowReInit();
    }
}

void graphFrameBufferReInitializeRequest(void) {
    iosGsSetMode();
    D_40129DF4 = 1;
}

void graphFrameInit(f32 dt) {
    s32 i;

    if (D_40129C7C != 0) {
        effectReset();
        i = 0;
        D_40129DF0 = dt;
        genv.time += dt;
        texReset(1, dt);
        glReset();
        windowSetMouseStatus();
        resetMicroCodeManager();
        for (; i < iosDlGetLayerNum(); i++) {
            iosDlPushLayer(i);
            iosDlChainTailCurrent(D_40129C90 + iosDlGetWorkBufId() * 0xB0);
            iosDlPopLayer();
        }
    }
}

void graphFsEffectReset(void) {
    if (D_40129C7C != 0) {
        effectSet();
        if (D_40129C78 != 0 && D_40129DF8 == 0) {
            bgBegin();
            shadowReset();
            waterRefractionBegin(D_40129DF0);
            refractionBegin(D_40129DF0);
            reflectionBegin(D_40129DF0);
            depthOfField();
            bossDeathEffectBegin(D_40129DF0);
        }
    }
    return;
}

void graphInit(void) {
    s32 a;

    vramInit();
    a = getFrameBufferSizeTBP();
    genv.vramImage = vramCreateBlock(D_40130528, 0, a, 0x3F3B - getFrameBufferSizeTBP());
    genv.vramClut = vramCreateBlock(D_40130530, 1, 0x3F3B, 0x7D);
    genv.vramEffect = vramCreateBlock(D_40130538, 0, 0x3FC0, 0x40);
    texInit(iosDlGetLayerNum());
    modelInit(iosDlGetLayerNum());
    kInit();
    windowInit();
    lineObjectInit();
    shadowInit();
    refractionInit();
    zFogInit();
    D_40129C7C = 1;
}

s32 *getFullScreenEffect(void) {
    return &D_40129C78;
}

f32 *getFBOfsU(void) {
    return &FBOfs;
}

f32 *getFBOfsV(void) {
    return &D_40129C84;
}

f32 *getFBOfsX(void) {
    return &D_40129C88;
}

f32 *getFBOfsY(void) {
    return &D_40129C8C;
}

void graphInitLayer(s32 layer) {
    iosDlPushLayer(layer);
    iosDlChainTailCurrent(D_40129C90 + iosDlGetWorkBufId() * 0xB0);
    iosDlPopLayer();
}

void graphInitAllLayer(void) {
    s32 i;

    for (i = 0; i < iosDlGetLayerNum(); i++) {
        iosDlPushLayer(i);
        iosDlChainTailCurrent(D_40129C90 + iosDlGetWorkBufId() * 0xB0);
        iosDlPopLayer();
    }
}

/* NEARMISS-STUB func_40028F70 */
#if 0 /* NEARMISS 86.37% cat=branch-layout sub=- | loop 0x9/0xA dispatch: target beql out-of-line tab block + andi a0 copy of byte for sltiu; ours bne inline; prologue sd s1/ra store order differs | attempts=1 */
void gsRegBegin(void);
void gsRegEnd(void);
void iosFTOI4Vector(s32 *dst, f32 *src);
void gsReg(s32, u64);

void func_40028F70(f32 *pos, u8 *str, s32 *p) {
    f32 box[4];
    s32 dst[4];
    f32 lx = pos[0];
    f32 cx = pos[0];
    f32 cy = pos[1];
    f32 mx = pos[0];
    f32 my = pos[1];
    u8 b = *str;
    u32 c;

    while (b != 0) {
        c = b;
        if (c < 0x20) {
            if (*str == 9) {
                cx = cx + (f32)(((p[4] * 2 - p[6]) >> 1) << 2);
            } else if (*str == 10) {
                cx = lx;
                cy = cy + (f32)(p[5] - p[7]);
            }
        } else if ((u8)(b - 0x20) < 0x60) {
            if (c == 0x20) {
                cx = cx + (f32)((p[4] * 2 - p[6]) >> 1);
            } else {
                cx = cx + (f32)((p[4] * 2 - p[6]) >> 1);
            }
        } else {
            str++;
            cx = cx + (f32)(p[4] * 2 - p[6]);
        }
        str++;
        if (mx < cx) {
            mx = cx;
        }
        if (my < cy) {
            my = cy;
        }
        b = *str;
    }
    if (str[-1] != 10) {
        my = my + (f32)(p[5] - p[7]);
    }
    gsRegBegin();
    box[0] = pos[0] + 1.5f;
    box[1] = pos[1] + 1.5f;
    box[2] = mx + 1.5f;
    box[3] = my + 1.5f;
    iosFTOI4Vector(dst, box);
    gsReg(0x42, 0x8000000044ULL);
    gsReg(0, 0x4E);
    gsReg(1, 0x3F80000060000000ULL);
    gsReg(4, (u64)(dst[0] + 0x8000) | ((u64)(dst[1] + 0x8000) << 16) | 0xFFFFFFFF00000000ULL);
    gsReg(4, (u64)(dst[2] + 0x8000) | ((u64)(dst[3] + 0x8000) << 16) | 0xFFFFFFFF00000000ULL);
    gsRegEnd();
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0017_gluSetWrapMode", func_40028F70);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0017_gluSetWrapMode", func_400291B8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0017_gluSetWrapMode", func_400295B0);

#include "common.h"

extern char D_401AC8B0[];
extern void *D_4012B030;
extern int D_4012B034;

void iosSprToMemDmaAdrCopy(void *, int, void *);

void LoopExecAfterLightColMan(void)
{
    iosSprToMemDmaAdrCopy(D_401AC8B0, 0xBD, (void *)0x70000000);
    D_4012B030 = D_401AC8B0;
}

void TaskExecLightColMan(void)
{
    D_4012B030 = D_401AC8B0;
}

typedef union {
    u128 q;
    f32 f[4];
} LcmVec4;

typedef struct {
    LcmVec4 pos; /* 0x00 */
    f32 f10;
    f32 f14;
    s32 f18;
    u8 pad1C[0x530 - 0x1C];
    s32 f530;
    u8 pad534[0xC];
    u8 *f540;
} LcmGlobalLight;

extern char D_40132DC0[];
extern s32 ExecGlobalLightMan(LcmGlobalLight *, LcmGlobalLight *);
extern void soundSetRevMode(s32, s32);
extern int strncmp(const char *, const char *, int);
extern void SetWorkFromGlobalLight(LcmGlobalLight *);
extern void ExecGameLight(LcmGlobalLight *, s32, LcmGlobalLight *);
extern void func_4008AC68(LcmGlobalLight *, u8 *, LcmGlobalLight *);

void SetCameraReverbFlag(LcmVec4 *pos)
{
    LcmGlobalLight *g = D_4012B030;
    s32 r;

    g->pos.q = pos->q;
    g->f10 = 0;
    g->f14 = g->f10;
    g->pos.f[3] = 1.0f;
    g->f18 = 0;
    g->f530 = 0;
    r = ExecGlobalLightMan(g, g) > 0;
    soundSetRevMode(1, 1);
    if (r && strncmp(*(char **)(g->f540 + 0x114), D_40132DC0, 6) != 0) {
        soundSetRevMode(0, 1);
    }
    return;
}

s32 SetGeoDispClassLightColMan(u8 *gd)
{
    LcmGlobalLight *g = D_4012B030;
    u8 flag = gd[0xC0] & 1;

    if (*(s32 *)(gd + 0xEC) != 0) {
        g->pos.q = ((LcmVec4 *)(gd + 0x10))->q;
        g->f10 = 0;
        g->f14 = g->f10;
        g->pos.f[3] = 1.0f;
        g->f18 = flag;
        g->f530 = 0;
        ExecGlobalLightMan(g, g);
        SetWorkFromGlobalLight(g);
        ExecGameLight(g, flag, g);
        func_4008AC68(g, gd, g);
    }
    return 1;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0103_LoopExecAfterLightColMan", getColLightDebugSts);

int *getColLightDebugSts(void)
{
    return &D_4012B034;
}

int GetColLightDebugSts(void)
{
    return D_4012B034;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0103_LoopExecAfterLightColMan", func_4008B298);

extern u8 *GetLightColMan(void);
extern s32 isysGroupForFirst(u8 *, s32);
extern s32 isysGroupForNext(s32, s32);
extern void isysGroupForExit(u8 *, s32);
extern void isysAddGroupWithLinkParam(u8 *, u8 *, s32, s32);
extern void _isysDeleteGroup(u8 *, u8 *, s32);

static inline u8 *gameLightClass(u8 *obj)
{
    if (obj[8] != 0x1A) {
        return 0;
    }
    return obj + 0x20;
}

void DeleteGameLight(u8 *light)
{
    u8 *lcm = GetLightColMan();
    s32 node;
    u8 *item = 0;
    u8 *gl;
    u8 *m;

    for (node = isysGroupForFirst(lcm + 0x528, 0); node != 0; node = isysGroupForNext(node, 0)) {
        item = *(u8 **)node;
        gl = gameLightClass(item);
        if (gl != 0 && gl == light) {
            m = GetLightColMan();
            *(s32 *)(gl + 0x2C) = 0;
            isysAddGroupWithLinkParam(item, m + 0x524, 0, 0);
            _isysDeleteGroup(item, m + 0x528, 0);
            break;
        }
    }
    if (item != 0) {
        isysGroupForExit(item, 0);
    }
    *(s32 *)(lcm + 0x52C) |= 2;
}

typedef struct {
    LcmVec4 q0;
    LcmVec4 q10;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    f32 f34;
    f32 f38;
    f32 f3C;
    f32 f40;
} GameLightDef;

typedef struct GameLight {
    LcmVec4 q0;
    LcmVec4 q10;
    u8 c[4];
    f32 f24;
    f32 f28;
    u8 pad2C[8];
    f32 f34;
    u8 f38;
    u8 pad39[3];
    s32 f3C;
    f32 f40;
    f32 f44;
    f32 f48;
    f32 f4C;
    u8 pad50[4];
    void (*f54)(struct GameLight *);
} GameLight;

extern s32 iosCalcIcolorToBrightness(s32);

void UpdateClipGameLight(GameLight *gl, u8 *arg)
{
    GameLightDef *d = (GameLightDef *)(arg + 0x10);
    s32 col;
    f32 f;

    gl->q0.q = d->q0.q;
    gl->q10.q = d->q10.q;
    gl->c[0] = d->f28;
    gl->c[1] = d->f2C;
    gl->c[2] = d->f30;
    gl->c[3] = 0xFF;
    gl->f24 = d->f20;
    gl->f28 = d->f24;
    if (gl->f54 != 0) {
        gl->f54(gl);
    }
    col = *(s32 *)gl->c;
    gl->f3C = col;
    gl->f38 = iosCalcIcolorToBrightness(col);
    f = gl->f38 * gl->f24;
    if (f < 0.0f) {
        f = -f;
    }
    gl->f40 = f;
    gl->f34 = gl->f28 * gl->f28;
    gl->f44 = d->f3C;
    gl->f48 = d->f38;
    gl->f4C = d->f40 * d->f40;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0103_LoopExecAfterLightColMan", func_4008B868);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0103_LoopExecAfterLightColMan", ExecGameLight);

#include "common.h"

typedef struct Blk40 { u64 w[8]; } Blk40;
extern s32 D_4012E28C;
extern s32 DldSysUndefSymbol;
extern Blk40 *D_401B3E70;
extern s32 D_401B3E78;
extern s32 D_401B3E74;
extern s32 D_401B3E58;
extern s32 D_401B3E68;
extern s32 D_401B3E6C;

void sndSepStopTypeAll();
void sndSepStopReq();
void dsysFileInit();
void nicosysdInit();
void sndSepSetVol(f32 vol, void *se);
void sndSepSetDefaultParam();
s32 sndSepReq();
void func_400EA248();
void func_400EA310();
void sheetFileRead(s32, s32, s32);
void sndBDClose();
void sndVabHDClose();
void sndVabDelete();
void iosFree(s32);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", initSoundManager);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", sePlay);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", sePlaySwapSound);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", sePlaySystemSound);

void seSetVol(f32 *c, f32 v) {
    c[6] = v;
}

void seStop(s32 *c) {
    c[0x10] = 0;
    sndSepStopReq();
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", seStopLoopType);

void seSopStageTypeAll() {
    sndSepStopTypeAll(2);
}

void seSetDebugTrigFunc(s32 f) {
    D_4012E28C = f;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", seLoadHDFile);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", func_400E9FD0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", func_400EA040);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", seLoadBDFile);

void seUnloadBDFile(s32 a, s32 b, u8 *c) {
    if (c != NULL) {
        s32 h;

        **(s32 **)(c + 0x18) = 0;
        sndBDClose(c);
        h = *(s32 *)(c + 0xC);
        sndVabHDClose(c);
        iosFree(h);
        sndVabDelete(c);
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", func_400EA248);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", func_400EA310);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", func_400EA368);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", func_400EA470);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", func_400EA570);

u64 func_400EA690(void *se)
{
    void (*fn)(void *) = *(void (**)(void *))((u8 *)se + 0x3c);
    f32 v;

    if (fn != NULL)
    {
        fn(se);
    }
    v = *(f32 *)((u8 *)se + 0x18);
    *(f32 *)((u8 *)se + 0x1c) = v;
    sndSepSetVol(1.0f, se);
    return 0;
}

void func_400EA6E0(u8 *c) {
    u8 *dst = *(u8 **)(c + 0x48);

    *(Blk40 *)dst = *D_401B3E70;
    *(s32 *)(dst + 0x40) = D_401B3E78;
    *(s32 *)(dst + 0x44) = D_401B3E74;
}

void func_400EA748(u8 *c) {
    u8 *p = *(u8 **)(c + 0x48);
    void (*fn)(s32) = *(void (**)(s32))(p + 0x40);

    if (fn != NULL) {
        fn(*(s32 *)(p + 0x44));
    }
}

s32 seDelayPlay3DTest(void) {
    return 0;
}

void dsysInit() {
    dsysFileInit();
    nicosysdInit();
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", func_400EA7A0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", func_400EA850);

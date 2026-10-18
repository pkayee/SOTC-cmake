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
s32 func_400EA248();
s32 func_400EA310();
void sheetFileRead(s32, s32, s32);
void sndBDClose();
void sndVabHDClose();
void sndVabDelete();
void iosFree(s32);

typedef union SeU { s16 h[0x40]; u32 w[0x40]; f32 f[0x40]; } SeU;
extern void testGetCamPos(void *, void *);
extern void GetGeometryPointerPosition(void *, void *);
extern s32 *getFogUnderWater(void);
extern void sound3DCalc(u8 *, u8 *, void *, void *);

extern char D_40134C58[];
extern u32 strlen(char *);
extern s32 iosSPrintf(char *, const char *, ...);
extern s32 LoaderSysFOpen(char *, s32, s32);

extern void LoaderSysGetstat(char *, s32 *);

typedef struct Ptn Ptn;
extern Ptn rootPtn;
extern s32 SH_SpuLayoutDEFAULT[];
extern u8 *D_401B3E50;
extern s32 D_401B3E54;
extern u8 D_401B3450[];
extern void *iosMallocAlign(Ptn *, s32, s32);
extern void *memset(void *, s32, u32);
extern void sndSepInitTickParam(u8 *, s32, s32);

extern u8 *sheetFileGetDataAdrs(s32);
extern s32 func_400E95D8(u8 *, u8 *, s32, s32, s32, s32);

extern void *sndVabCreate(void);
extern void sndVabHDOpen(void *, void *, s32);
extern void sheetMgrDirectFileLoad(s32, s32, s32, s32, s32 *);

static inline void seStopType(u8 *c, s32 mode) {
    u8 *def = *(u8 **)(c + 0x44);

    if (((*(u32 *)(def + 8) >> 12) & 1) == mode) {
        *(s32 *)(c + 0x40) = 0;
        sndSepStopReq(c, mode);
    } else {
        *(u64 *)(c + 8) &= ~0x2000000000ULL;
        *(s32 *)(c + 0x40) = 0;
    }
}

static inline s32 sepReqSys(void *f, s32 u, s32 id) {
    if (id == u) {
        return 0;
    }
    return sndSepReq(f, 0, 0, id, 0, 1, 0);
}

static inline s32 sepReqSwap(void *f, s32 u, s32 id, s32 swap) {
    if (id == u) {
        return 0;
    }
    return sndSepReq(f, 0, 0, id, 0, 0, swap);
}

static inline u8 *dldElem(u32 *lp) {
    u8 *slot;
    u32 w = *lp;
    u32 off = w & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol)
               ? *(u8 **)(slot + 0x10) + ((w >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(slot + 8) + 0xC)
               : NULL;
}

/* se table: D_401B3E50 = array of 8-byte entries (word 1 = row pointer); n = layout word 3 (entry count), rows = layout word 4, 8 bytes per row */
void initSoundManager(void) {
    s32 n = SH_SpuLayoutDEFAULT[3];
    u8 *rows = (u8 *)SH_SpuLayoutDEFAULT[4];
    s32 i;

    D_401B3E50 = iosMallocAlign(&rootPtn, n * 8, 4);
    memset(D_401B3E50, 0, n * 8);
    for (i = 0; i < n; i++) {
        *(u8 **)(D_401B3E50 + i * 8 + 4) = rows + i * 8;
    }
    D_401B3E54 = n;
    sndSepInitTickParam(D_401B3450, 0x20, 0x50);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", sePlay);

/* swap sound request: second arg goes in the 7th sndSepReq slot */
s32 sePlaySwapSound(s32 id, s32 swap) {
    return sepReqSwap(func_400EA310, *(s32 *)DldSysUndefSymbol, id, swap);
}

/* system sound request: sndSepReq 6th arg is 1 */
s32 sePlaySystemSound(s32 id) {
    return sepReqSys(func_400EA248, *(s32 *)DldSysUndefSymbol, id);
}

void seSetVol(f32 *c, f32 v) {
    c[6] = v;
}

void seStop(s32 *c) {
    c[0x10] = 0;
    sndSepStopReq();
}

/* loop-type stop: bit 12 of the def word at +8 selects immediate stop, otherwise clear flag bit 37 */
void seStopLoopType(u8 *c) {
    seStopType(c, 1);
}

void seSopStageTypeAll() {
    sndSepStopTypeAll(2);
}

void seSetDebugTrigFunc(s32 f) {
    D_4012E28C = f;
}

/* HD load: read the HD image through sheetFileRead or the direct loader (polls a null call target until
   the status is -0xDEAF/-0xDEAE), open it as a vab and store the vab at d+0x1C */
void *seLoadHDFile(s32 sheet, s32 unused, s32 size) {
    u8 *d = sheetFileGetDataAdrs(sheet);
    void *buf = iosMallocAlign(&rootPtn, size, 0x10);
    void *vab = sndVabCreate();

    if (sheet != 0) {
        sheetFileRead(sheet, (s32)buf, size);
    } else {
        s32 st;

        sheetMgrDirectFileLoad(0, 0, (s32)buf, size, &st);
        while ((u32)(st + 0xFFFF2151) >= 2) {
            ((void (*)(void))0)();
        }
    }
    sndVabHDOpen(vab, buf, size);
    *(void **)(d + 0x1C) = vab;
    return vab;
}

/* chunked sheet read: at most 0x10000 bytes per call out of D_401B3E58 remaining */
s32 func_400E9FD0(void) {
    s32 rem = D_401B3E58;
    s32 n = rem > 0x10000 ? 0x10000 : rem;

    if (rem <= 0) {
        return 0;
    }
    sheetFileRead(D_401B3E68, D_401B3E6C, n);
    D_401B3E58 -= n;
    return n;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", func_400EA040);

/* BD load (dld link word: bits 0..17 byte distance back to the slot, bits 18..29 element index): sheet data adrs d, bd element at d+0x18, tail call func_400E95D8(d, elem, arg2, arg0, 0, 0) */
s32 seLoadBDFile(s32 sheet, s32 unused, s32 a2) {
    u8 *d = sheetFileGetDataAdrs(sheet);

    return func_400E95D8(d, dldElem((u32 *)(d + 0x18)), a2, sheet, 0, 0);
}

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

/* se play init callback: def at c+0x44, its link word at def+4 picks the voice row; store of row word 7 precedes the zero test */
s32 func_400EA248(SeU *c) {
    SeU *def = (SeU *)c->w[0x11];
    u8 *e = dldElem(&def->w[1]);
    u32 a;
    u32 b;
    f32 v;
    u32 h;

    if (e == NULL) {
        return -1;
    }
    h = *(u32 *)(e + 0x1C);
    c->w[4] = h;
    if (h == 0) {
        return -1;
    }
    a = def->w[2];
    c->h[0xA] = a & 0x1F;
    b = def->w[2];
    c->h[0xB] = (b >> 5) & 0x7F;
    v = def->f[3];
    c->f[6] = v;
    c->f[7] = v;
    sndSepSetDefaultParam(c);
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0186_initSoundManager", func_400EA310);

/* 3D se update, variant returning 3: camera pos, se pos, fog-scaled volume at c+0x1C, then sound3DCalc */
s32 func_400EA368(u8 *c) {
    struct { f32 cam[4]; f32 pos[16]; } l;
    u8 *g = *(u8 **)(c + 0x48);
    u8 *def = *(u8 **)(c + 0x44);
    f32 v;

    testGetCamPos(l.cam, l.pos);
    if ((int)(*(u64 *)(c + 8) >> 37) & 1) {
        GetGeometryPointerPosition(c + 0x50, g);
    }
    if (((*(u32 *)(def + 8) >> 28) & 1) == 0) {
        v = *(f32 *)(c + 0x18);
        *(f32 *)(c + 0x1C) = *getFogUnderWater() != 0 ? v * 0.59999998f : v;
    } else {
        if (*getFogUnderWater() == 0) {
            *(s32 *)(c + 0x1C) = 0;
        } else {
            *(f32 *)(c + 0x1C) = *(f32 *)(c + 0x18);
        }
    }
    sound3DCalc(c, c + 0x50, l.cam, l.pos);
    return 3;
}

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

/* open a file by printf-composed name (alloca buffer), fd stored through out, 0 ok / -1 fail */
s32 func_400EA7A0(s32 *out, char *name, s32 mode) {
    char buf[strlen(name) + 7];
    s32 fd;

    iosSPrintf(buf, D_40134C58, name);
    fd = LoaderSysFOpen(buf, mode, 0x1FF);
    *out = fd;
    if (fd < 0) {
        return -1;
    }
    return 0;
}

/* file size by printf-composed name (alloca buffer): stat word 2 */
s32 func_400EA850(char *name) {
    char buf[strlen(name) + 7];
    s32 st[16];

    iosSPrintf(buf, D_40134C58, name);
    LoaderSysGetstat(buf, st);
    return st[2];
}

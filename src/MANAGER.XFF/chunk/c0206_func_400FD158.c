#include "common.h"

extern void *D_4012EB10;
void *memset(void *, s32, u32);

void mpegFree(void *);
void Sg2ExPcmSetSignal(void *);
void Sg2ExPcmOutputClose(void);
void iosFreeIopHeap(void *);
extern void *muxBuff;

void iosEE2IopRequest();
s32 iosEE2IopEndChk(s32);
s32 mpegMalloc(s32);
s32 iosAllocIopHeap(s32);
void Sg2ExPcmOutputOpen(s32, void *, s32);
void Sg2ExPcmOutputSetVol(s32, s32);
void Sg2ExPcmOutputSetEffect(s32);
void Sg2ExPcmOutputCtrl(s32);
s32 func_400FD930(s32, s32, s32, s32);

extern s32 D_4012EB18;

extern s32 D_4012EE90;
extern s32 D_4012EE94;
extern u8 D_401C49B0[];
void strFileOpen(s32);
void strFileClose(void);
void playPss(void *);

extern s32 D_401C49E8;
extern s32 D_401C49EC;
extern s32 D_401C49F0;
extern s32 D_401C49F4;
extern s32 D_401C49F8;
void *memcpy(void *, const void *, u32);

void iosDlPushLayer(s32);
void iosDlChainTailCurrent(u32);
void iosDlPopLayer(void);

void setMovieSkip(s32);

void iosFree(void *);

void *iosMallocInGarbagePtn(s32, s32);

extern u8 rootPtn[];
s32 createScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, void *a6, s32 a7);
void func_400FDAB8(void);

typedef struct {
    s32 f00;
    u8 *buf;
    s32 f08;
    s32 size;
    s32 total;
    s32 f14;
    s32 f18;
    s32 pos;
    s32 sema;
} AudioDec;
extern AudioDec audioDec;
void WaitSema(s32);
void SignalSema(s32);
void func_400FD4A8(void);

void func_400FD158(s32, s32, s32, s32, s32, s32, s32);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0206_func_400FD158", func_400FD158);

void setLoadImageTags(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    func_400FD158(a0, a1, 0x400, a2, a3, a4, a5);
}

void setLoadImageTagsTile(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    func_400FD158(a0, a1, 0, a2, a3, a4, a5);
}

void loadImage(u32 a0) {
    iosDlPushLayer(0x1C);
    iosDlChainTailCurrent(a0 & 0xFFFFFFF);
    iosDlPopLayer();
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0206_func_400FD158", func_400FD4A8);

void MovieInit(s32 *a0) {
    s32 tag;
    void *p;

    muxBuff = (void *)mpegMalloc(0x4000);
    a0[0] = mpegMalloc(0xFE800);
    a0[1] = 0xFE800;
    a0[2] = mpegMalloc(0xE0000);
    a0[3] = mpegMalloc(0x2A200);
    a0[4] = mpegMalloc(0x30000);
    a0[5] = 0x30000;
    p = (void *)mpegMalloc(0x80000);
    a0[6] = (s32)p;
    a0[7] = 0x80000;
    memset(p, 0, 0x80000);
    a0[8] = iosAllocIopHeap(0x8000);
    a0[9] = 0x8000;
    D_4012EB10 = (void *)mpegMalloc(0x8000);
    memset(D_4012EB10, 0, 0x8000);
    Sg2ExPcmSetSignal((void *)func_400FD930);
    if (D_4012EB10 != NULL) {
        memset(D_4012EB10, 0, 0x8000);
    }
    iosEE2IopRequest(D_4012EB10, a0[8], 0x8000, &tag);
    while (iosEE2IopEndChk(tag) == 0) {
    }
    Sg2ExPcmOutputOpen(a0[8], D_4012EB10, 0x4000);
    Sg2ExPcmOutputSetVol(0, 0);
    Sg2ExPcmOutputSetEffect(1);
    Sg2ExPcmOutputCtrl(2);
}

void MovieExit(u8 *a0) {
    Sg2ExPcmSetSignal(NULL);
    Sg2ExPcmOutputClose();
    mpegFree(*(void **)(a0 + 0x0));
    mpegFree(*(void **)(a0 + 0x8));
    mpegFree(*(void **)(a0 + 0xC));
    mpegFree(*(void **)(a0 + 0x10));
    mpegFree(*(void **)(a0 + 0x18));
    iosFreeIopHeap(*(void **)(a0 + 0x20));
    mpegFree(D_4012EB10);
    D_4012EB10 = NULL;
    mpegFree(muxBuff);
    muxBuff = NULL;
}

s32 EE_MixBufClear(void) {
    if (D_4012EB10 == NULL) {
        return 0;
    }
    memset(D_4012EB10, 0, 0x8000);
    return 1;
}

void pcm_tickprocsub(void) {
    WaitSema(audioDec.sema);
    func_400FD4A8();
    SignalSema(audioDec.sema);
}

s32 func_400FD930(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 tag;

    if (a0 == 0) {
        iosEE2IopRequest(a1, a2, a3, &tag);
        while (iosEE2IopEndChk(tag) == 0) {
        }
    }
    return 0;
}

void PcmOutputClear(u8 *a0) {
    s32 tag;

    if (D_4012EB10 != NULL) {
        memset(D_4012EB10, 0, 0x8000);
    }
    iosEE2IopRequest(D_4012EB10, *(s32 *)(a0 + 0x20), 0x8000, &tag);
    while (iosEE2IopEndChk(tag) == 0) {
    }
}

s32 MovieSkipCheck(void) {
    return D_4012EB18;
}

void setMovieSkip(s32 a0) {
    D_4012EB18 = a0;
}

s32 mpegMalloc(s32 a0) {
    iosMallocInGarbagePtn(a0, 0x80);
}

void mpegFree(void *a0) {
    iosFree(a0);
}

void mpegStart(s32 a0) {
    D_4012EE94 = 0;
    D_4012EE90 = a0;
    setMovieSkip(0);
    createScriptObj((void *)func_400FDAB8, 0, rootPtn, 0x8000, 0, 9, 0, 0);
}

s32 mpegChkPlaying(s32 (*a0)(void)) {
    if (a0 != NULL) {
        setMovieSkip(a0());
    }
    return D_4012EE94;
}

void Sg2Init(void) {
}

void func_400FDAB8(void) {
    MovieInit((s32 *)D_401C49B0);
    strFileOpen(D_4012EE90);
    D_4012EE94 = 1;
    playPss(D_401C49B0);
    strFileClose();
    MovieExit(D_401C49B0);
    D_4012EE90 = -1;
    D_4012EE94 = -1;
}

s32 func_400FDB38(s32 a0, u8 *a1) {
    u32 avail;
    u32 n;
    s32 over;

    avail = D_401C49F4 - D_401C49F0;
    if ((s32)avail < 0) {
        avail += D_401C49EC;
    }
    if (avail == 0) {
        if (D_401C49F4 == D_401C49F8) {
            avail = D_401C49EC;
        }
    }
    n = *(s32 *)(a1 + 0xC);
    if (avail < n) {
        return 0;
    }
    over = D_401C49F0 - D_401C49E8 + n - D_401C49EC;
    if (over > 0) {
        memcpy((void *)((D_401C49F0 & 0xFFFFFFF) | 0x20000000), *(void **)(a1 + 8), n - over);
        memcpy((void *)((D_401C49E8 & 0xFFFFFFF) | 0x20000000), (void *)(*(s32 *)(a1 + 8) + (*(s32 *)(a1 + 0xC) - over)), over);
        D_401C49F0 = D_401C49E8 + over;
    } else {
        memcpy((void *)((D_401C49F0 & 0xFFFFFFF) | 0x20000000), *(void **)(a1 + 8), n);
        D_401C49F0 = D_401C49F0 + *(s32 *)(a1 + 0xC);
    }
    return 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0206_func_400FD158", func_400FDC80);

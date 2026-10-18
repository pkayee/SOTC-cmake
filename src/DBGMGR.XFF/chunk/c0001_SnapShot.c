#include "common.h"

s32 LoaderSysFOpen(const char *name, s32 flags, s32 mode);
s32 LoaderSysFClose(s32 fd);
s32 LoaderSysFSeek(s32 fd, s32 offset, s32 whence);
s32 LoaderSysFRead(s32 fd, void *buf, s32 count);

s32 LoaderSysFWrite(s32 fd, const void *buf, s32 count);

extern char debugInfo[];

typedef struct { float x, y, z, w; } V4 __attribute__((aligned(8)));
typedef struct {
    char name[8];
    int unk8;
    char pad[24];
    int unk24;
    char *unk28;
} DbgPrintInfo;
extern DbgPrintInfo D_4001DEE0;
void createPrintWindow(const char *name, s32 flag);
void windowSetCursorPosOnWindow(void *win, V4 pos);

int iosSPrintf(char *buf, const char *fmt, ...);
void nicosysdSendDataStart(void *a, int b, void *c, int d);
void nicosysdSendDataWrite(void *a, void *b, int c);
void nicosysdExec(void *a, void *b, void *c);
extern u8 rootPtn[];
extern void nicosysdEchoDdebugPrintReadCallBack();
extern char D_4001E768[];
extern char D_4001E7B0[];
extern s32 D_4001DF0C;
extern s32 D_4001DF10;
extern s32 D_4001DF14;
extern s32 D_4001DF18;
extern char *D_4001DF20[];
void ischedStop(void);
void ischedRestart(void);
void iosFree(void *p);

extern int D_4001DF04;

extern char D_4001E0C8[];

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0001_SnapShot", SnapShot);

void func_40011EF8(char *name) {
    u8 res[16];
    u8 hdr[32];
    char buf[256];
    s32 n;
    if (D_4001DF14 != 0) {
        iosSPrintf(buf, D_4001E768, D_4001DF20[D_4001DF0C], D_4001DF10, D_4001DF14, D_4001DF18, name);
    } else {
        iosSPrintf(buf, D_4001E7B0, D_4001DF20[D_4001DF0C], D_4001DF10, D_4001DF18, name);
    }
    n = strlen(buf) + 1;
    ischedStop();
    nicosysdSendDataStart(hdr, 0x3eb, rootPtn, n);
    nicosysdSendDataWrite(hdr, buf, n);
    nicosysdExec(hdr, res, nicosysdEchoDdebugPrintReadCallBack);
    iosFree(name);
    ischedRestart();
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0001_SnapShot", SnapShotHigh);

void debugFOpen(const char *a, s32 b, s32 c) {
    LoaderSysFOpen(a, b, c);
}

void debugFClose(s32 a) {
    LoaderSysFClose(a);
}

void debugFSeek(s32 a, s32 b, s32 c) {
    LoaderSysFSeek(a, b, c);
}

void debugFRead(s32 a, void *b, s32 c) {
    LoaderSysFRead(a, b, c);
}

void debugFWrite(s32 a, const void *b, s32 c) {
    LoaderSysFWrite(a, b, c);
}

void debugFOpenNew(const char *a) {
    LoaderSysFOpen(a, 0x602, 0);
}

void debugFAppend(const char *a) {
    LoaderSysFOpen(a, 0x302, 0);
}

s32 debugFExists(const char *a) {
    s32 fd = LoaderSysFOpen(a, 1, 0);
    if (fd != 0) {
        LoaderSysFClose(fd);
    }
    return fd > 0;
}

s32 checkUser(const char *a) {
    return strcmp(debugInfo, a) == 0;
}

char *username(void) {
    return debugInfo;
}

void nicoMakeData(void) {
    u8 res[16];
    u8 hdr[32];
    char buf[256];
    s32 n;
    iosSPrintf(buf, D_4001E0C8);
    n = strlen(buf) + 1;
    nicosysdSendDataStart(hdr, 0x3eb, rootPtn, n);
    nicosysdSendDataWrite(hdr, buf, n);
    nicosysdExec(hdr, res, nicosysdEchoDdebugPrintReadCallBack);
}

int *getDebugPrintWindow(void) {
    return &D_4001DF04;
}

void createDebugPrintWindowFromMenu(s32 a) {
    if (a != 0) {
        D_4001DEE0.unk8 = 1000;
        createPrintWindow(D_4001DEE0.name, 0);
    }
}

void createDebugPrintWindow(s32 a) {
    V4 pos2;
    V4 pos;
    float *p;
    if (D_4001DEE0.unk24 == 0) {
        D_4001DEE0.unk8 = a;
        D_4001DEE0.unk24 = 1;
        createPrintWindow(D_4001DEE0.name, 1);
        p = (float *)(*(int *)(D_4001DEE0.unk28 + 4) + 0x264);
        pos.x = p[2] - 12.0f;
        pos.y = p[3] - 12.0f;
        pos.z = 0;
        pos.w = 0;
        pos2 = pos;
        windowSetCursorPosOnWindow(D_4001DEE0.unk28, pos2);
    }
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0001_SnapShot", getVU1Regs);

s32 FileRead(const char *name, void *buf, s32 len) {
    s32 fd = LoaderSysFOpen(name, 1, 0);
    s32 size;
    if (fd >= 0) {
        size = LoaderSysFSeek(fd, 0, 2);
        LoaderSysFSeek(fd, 0, 0);
        if (size <= len) {
            LoaderSysFRead(fd, buf, size);
        } else {
            LoaderSysFRead(fd, buf, len);
        }
        LoaderSysFClose(fd);
        return size;
    }
    return -1;
}

s32 FileWrite(const char *name, void *buf, s32 len) {
    s32 fd = LoaderSysFOpen(name, 0x602, 0);
    s32 ret = -1;
    if (fd >= 0) {
        LoaderSysFWrite(fd, buf, len);
        LoaderSysFClose(fd);
        ret = len;
    }
    return ret;
}

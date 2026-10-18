#include "common.h"

extern u8 rootPtn[];
extern char D_40019508[];
extern char D_40019528[];
extern char D_40019530[];
extern char D_40021300[];
extern s32 D_40018F6C;
int iosSPrintf(char *buf, const char *fmt, ...);
void nicosysdSendDataStart(void *a, int b, void *c, int d);
void nicosysdSendDataWrite(void *a, void *b, int c);
void nicosysdExec(void *a, void *b, void *c);
void func_40012B48();
void debugFWrite();
void debugFClose();

extern char D_400194F0[];
char *strchr(const char *s, int c);
void nicosysdRecvDataRead(void *a, void *b, s32 c);

extern s32 D_40018F64;

extern s32 D_40018F60;

extern s32 D_40018F58;

extern char D_400194F8[];

extern s32 D_40018F5C;

extern s32 D_40018F68;

extern s32 D_40018F54;

extern char D_400194E0[];
void getUserName();
void loadDebugParam();
s32 *getLogSw();
void openLogFile();
void func_400122A0();
void gcCreateScriptObj();
void createDebugSubThreads();
void toggleSeSlotDispSw();
void SetVIF1MarkCallbackFunc();

extern char D_40019538[];
extern char D_40019558[];
char *username();
void debugFExists();
s32 debugFAppend();
static inline void runDateOpen(char *fmt)
{
    u8 res[16];
    u8 hdr[32];
    char buf[256];
    s32 n;

    iosSPrintf(buf, fmt);
    n = strlen(buf) + 1;
    nicosysdSendDataStart(hdr, 0x3eb, rootPtn, n);
    nicosysdSendDataWrite(hdr, buf, n);
    nicosysdExec(hdr, res, func_40012B48);
}
static inline void logLine(char *msg)
{
    char out[1024];

    runDateOpen(D_40019508);
    iosSPrintf(out, D_40019528, msg, D_40021300);
    if (D_40018F6C > 0) {
        debugFWrite(D_40018F6C, out, strlen(out));
    }
}

static inline void runDate(char *fmt)
{
    u8 res[16];
    u8 hdr[32];
    char buf[256];
    s32 n;

    iosSPrintf(buf, fmt);
    n = strlen(buf) + 1;
    nicosysdSendDataStart(hdr, 0x3eb, rootPtn, n);
    nicosysdSendDataWrite(hdr, buf, n);
    nicosysdExec(hdr, res, func_40012B48);
}

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", func_400122A0);

s32 *getTimeScale(void)
{
    return &D_40018F54;
}

//INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", setTimeScale);
extern s32 D_40018F54;
void ChangeGameTimeScale();

void setTimeScale(void)
{
    ChangeGameTimeScale(D_40018F54);
}

s32 *getCpuForceWeight(void)
{
    return &D_40018F58;
}

s32 *getDispTimer(void)
{
    return &D_40018F5C;
}

s32 *getAreaBoundaryDispSw(void)
{
    return &D_40018F60;
}

s32 *getAreaBoundaryDispPolySw(void)
{
    return &D_40018F64;
}

//INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", func_400127D8);
extern void seamlessstage_mallocerrorfunc(void);
extern void objectmanager_mallocerrorfunc(void);

void func_400127D8(void)
{
    seamlessstage_mallocerrorfunc();
    objectmanager_mallocerrorfunc();
}

void initgcdebug(void)
{
    getUserName();
    loadDebugParam();
    if (*getLogSw() != 0) {
        openLogFile();
    }
    gcCreateScriptObj(func_400122A0, 0, rootPtn, 0x1800, 0, 9, D_400194E0);
    createDebugSubThreads();
    toggleSeSlotDispSw();
    SetVIF1MarkCallbackFunc();
}

void openLogFile(void)
{
    char path[256];
    char *msg;

    runDateOpen(D_400194F8);
    if (strchr(D_40021300, 10) != 0) {
        *strchr(D_40021300, 10) = 0;
    }
    msg = D_40019558;
    iosSPrintf(path, D_40019538, D_40021300, username());
    debugFExists(path);
    D_40018F6C = debugFAppend(path);
    logLine(msg);
}

void addLogFile(char *msg, s32 flag)
{
    char out[1024];

    if (flag != 0) {
        runDate(D_40019508);
        iosSPrintf(out, D_40019528, msg, D_40021300);
    } else {
        iosSPrintf(out, D_40019530, msg);
    }
    if (D_40018F6C > 0) {
        debugFWrite(D_40018F6C, out, strlen(out));
    }
}

void closeLogFile(void)
{
    debugFClose(D_40018F6C);
    D_40018F6C = 0;
}

s32 *getLogSw(void)
{
    return &D_40018F68;
}

void func_40012B48(void *a, s32 *b)
{
    char buf[1008];
    s32 rem;
    s32 n;

    rem = b[2];
    while (rem > 0) {
        n = rem < 0x3e9 ? rem : 1000;
        nicosysdRecvDataRead(a, buf, n);
        rem -= n;
        iosSPrintf(D_40021300, D_400194F0, buf);
        if (strchr(D_40021300, 10) != 0) {
            *strchr(D_40021300, 10) = 0;
        }
    }
}

void getDate(void)
{
    u8 res[16];
    u8 hdr[32];
    char buf[256];
    s32 n;

    iosSPrintf(buf, D_400194F8);
    n = strlen(buf) + 1;
    nicosysdSendDataStart(hdr, 0x3eb, rootPtn, n);
    nicosysdSendDataWrite(hdr, buf, n);
    nicosysdExec(hdr, res, func_40012B48);
}

void getTime(void)
{
    u8 res[16];
    u8 hdr[32];
    char buf[256];
    s32 n;

    iosSPrintf(buf, D_40019508);
    n = strlen(buf) + 1;
    nicosysdSendDataStart(hdr, 0x3eb, rootPtn, n);
    nicosysdSendDataWrite(hdr, buf, n);
    nicosysdExec(hdr, res, func_40012B48);
}

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", func_40012D28);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", func_40012FF8);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", func_40013570);

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0001_func_400122A0", func_40013A28);

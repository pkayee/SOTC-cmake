#include "common.h"

typedef __builtin_va_list va_list;
int vsprintf(char *, const char *, va_list);

typedef struct DbgPrintInfo {
    s32 w0;
    s32 w1;
    s32 rows;
    float x;
    float y;
    s32 cols;
    s32 lines;
    s32 cur;
    s32 unk20;
    s32 open;
    u8 *win;
} DbgPrintInfo;

/* REA c0000: reads host0:username.txt into debugInfo, keeps the leading printable run (0x20..0x7F), returns debugInfo or NULL. evidence ev_05c137a6 */
s32 LoaderSysFOpen(const char *name, s32 flags, s32 mode);
s32 LoaderSysFClose(s32 fd);
s32 LoaderSysFSeek(s32 fd, s32 offset, s32 whence);
s32 LoaderSysFRead(s32 fd, void *buf, s32 count);
extern char debugInfo[];
extern char D_4001E0B0[];

char *getUserName(void) {
    s32 fd;
    s32 size;
    s32 i;

    fd = LoaderSysFOpen(D_4001E0B0, 1, 0);
    if (fd < 0) {
        debugInfo[0] = 0;
        return 0;
    }
    size = LoaderSysFSeek(fd, 0, 2);
    LoaderSysFSeek(fd, 0, 0);
    LoaderSysFRead(fd, debugInfo, size);
    debugInfo[size] = 0;
    for (i = 0; i < size; i++) {
        if ((u8)(debugInfo[i] - 32U) >= 0x60) {
            debugInfo[i] = 0;
            break;
        }
    }
    LoaderSysFClose(fd);
    return debugInfo;
}

/* REA c0000: formats into a 2 KB stack buffer and appends it (with NUL) at the cursor stored at absolute 0x02000000 (T10K dev-kit RAM). evidence ev_05c137a6 */
void T10KPrintf(char *fmt, ...) {
    char buf[2048];
    va_list args;
    s32 n;

    __builtin_stdarg_start(args, fmt);
    vsprintf(buf, fmt, args);
    __builtin_va_end(args);
    n = strlen(buf) + 1;
    memcpy(*(void **)0x2000000, buf, n);
    *(s32 *)0x2000000 += n;
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0000_getUserName", createPrintWindow);

/* REA c0000: formats one line, strips ESC[...m colour sequences and stores it in ring slot cur (256 B each) of the window text buffer (+0x3E8); win+4 = window object, +0x3E0 = DbgPrintInfo. evidence ev_05c137a6 */
void debugPrintf(u8 *win, char *fmt, ...) {
    char buf[256];
    va_list args;
    u8 *w;
    DbgPrintInfo *info;
    char *dst;
    char *src;
    s32 esc;

    w = *(u8 **)(win + 4);
    __builtin_stdarg_start(args, fmt);
    info = *(DbgPrintInfo **)(w + 0x3E0);
    vsprintf(buf, fmt, args);
    __builtin_va_end(args);
    if (info->win != 0 && w != 0) {
        dst = *(char **)(w + 0x3E8);
        if (dst != 0) {
            esc = 0;
            src = buf;
            dst += info->cur << 8;
            while (*src != 0) {
                if (*src == 0x1B && src[1] == '[') {
                    esc = 1;
                } else if (esc != 0) {
                    if (*src == 'm') {
                        esc = 0;
                    }
                } else {
                    *dst++ = *src;
                }
                src++;
            }
            *dst = 0;
            info->cur++;
            if (info->cur >= info->rows) {
                info->cur = 0;
            }
        }
    }
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0000_getUserName", func_40010DE8);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0000_getUserName", createDumpWindow);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0000_getUserName", dbgPrintf);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0000_getUserName", func_40011478);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0000_getUserName", func_40011598);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0000_getUserName", func_40011778);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0000_getUserName", func_40011960);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0000_getUserName", func_40011BF8);

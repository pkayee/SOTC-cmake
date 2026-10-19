#include "common.h"

typedef struct DsysFile {
    int a;
    int b;
    int c;
    struct DsysFile *next;
} DsysFile;
extern DsysFile *D_401B3E7C;
extern DsysFile *D_401B3E80;
extern void iosJumpRecoverPoint();
extern const char D_40134C68[];
extern s32 func_400EA7A0(s32 *, char *, s32);
static inline DsysFile *dsysSlotPop(void)
{
    DsysFile *f;

    f = D_401B3E7C;
    if (f != 0) {
        D_401B3E7C = f->next;
        f->next = D_401B3E80;
        D_401B3E80 = f;
    }
    return f;
}
static inline void dsysSlotFree(DsysFile *f)
{
    DsysFile *cur;
    DsysFile *prev;

    prev = 0;
    cur = D_401B3E80;
    while (cur != 0) {
        if (f == cur) {
            goto found;
        }
        prev = cur;
        cur = cur->next;
    }
    return;
found:
    if (prev != 0) {
        prev->next = cur->next;
    } else {
        D_401B3E80 = cur->next;
    }
    f->next = D_401B3E7C;
    D_401B3E7C = f;
}
extern char D_40134D20[];
extern char D_40134D28[];
extern void iosSPrintf(char *, char *, ...);
extern s32 func_400EA850(char *);
extern void LoaderSysFClose(s32);
extern const char D_40134C90[];
extern char D_40134D88[];
extern s32 rootPtn;
extern s32 strlen(const char *);
extern void nicosysdSendDataStart(void *, s32, void *, s32);
extern void nicosysdSendDataWrite(void *, void *, s32);
extern void nicosysdExec(void *, void *, void *);
extern void nicosysdEchoReadCallBack();
static inline void dsysCloseInl(DsysFile *f)
{
    DsysFile *cur;
    DsysFile *prev;

    if (f->b == 0) {
        LoaderSysFClose(f->a);
    } else {
        iosJumpRecoverPoint(D_40134C90);
    }
    prev = 0;
    cur = D_401B3E80;
    while (cur != 0) {
        if (f == cur) {
            goto found;
        }
        prev = cur;
        cur = cur->next;
    }
    return;
found:
    if (prev != 0) {
        prev->next = cur->next;
    } else {
        D_401B3E80 = cur->next;
    }
    f->next = D_401B3E7C;
    D_401B3E7C = f;
}
static inline DsysFile *dsysOpenInl(char *name, s32 dev, s32 mode)
{
    DsysFile *f;
    DsysFile *ret;

    f = dsysSlotPop();
    if (f == 0) {
        return 0;
    }
    {
        f->c = mode;
        f->b = dev;
        ret = f;
        if (dev == 0) {
            if (func_400EA7A0((s32 *)f, name, mode) < 0) {
                ret = 0;
            }
        } else {
            iosJumpRecoverPoint(D_40134C68);
        }
        if (ret == 0) {
            dsysSlotFree(f);
        }
    }
    return ret;
}

/* open an existing file for read mode 1, optionally report its size through out */
DsysFile *dsysExistFileOpen(s32 *out, char *name)
{
    DsysFile *f;

    f = dsysOpenInl(name, 0, 1);
    if (out != 0) {
        if (f != 0) {
            *out = func_400EA850(name);
        } else {
            *out = 0;
        }
    }
    return f;
}

/* excel auto mod file init: format the file name, create it (mode 0x602) and close it again at once */
void InitExcelAutoModFile(char *name)
{
    char buf[208];

    iosSPrintf(buf, D_40134D28, name);
    dsysCloseInl(dsysOpenInl(buf, 0, 0x602));
}

/* open a csv temp file by formatted name for write mode 0x602 */
DsysFile *OpenCsvModChkTempFile(char *name)
{
    char buf[208];

    iosSPrintf(buf, D_40134D20, name);
    return dsysOpenInl(buf, 0, 0x602);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0187_dsysExistFileOpen", WriteMemberCsvModChkTempFile);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0187_dsysExistFileOpen", AddSegmentCsvModChkTempFile);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0187_dsysExistFileOpen", CloseCsvModChkTempFile);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0187_dsysExistFileOpen", CreateCsvModChkTempFileIppatu);

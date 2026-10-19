#include "common.h"

void func_400EEE08(void *param, void (*func)(void));
void func_400F14E0(void *p);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", func_400F10E8);
/* READY draft c0193 func_400F11E8: create a sheet-data object (0x58 bytes, type 5) for sheet index a2.
 * Fields (REA ev_51d739a5ad7faa65a0cf47b2d9759a18cedbd23140ffc423bdde7f65fdbe8585): +0x3C = sheet header ptr from table D_4012E330[a2]
 * (NULL -> iosJumpRecoverPoint with the "...sheet header %d not found" string D_401352D8), +0x40 = data ptr (0 when a0==0),
 * +0x44 = flags (mask 0xC007FFFF clears bits 19..29), +0x48 = isysInit group.  a0 = xff data pointer (or 0), a1 = name/arg.
 * The mask is two separate AND statements (0xC00FFFFF then 0xFFF7FFFF): a single 0xC007FFFF scores 78 percent, the if/else order must be a0 != 0 first (88 to 100). */
extern void iosJumpRecoverPoint(const char *, s32);
extern const char D_401352D8[];
extern s32 isysGetXffWorkSize(s32);
extern void *_isysCreateObj(void *, s32, s32, s32, s32, s32);
extern void isysInitGroup(void *);
extern void func_400EF138(s32, s32, void *);

/* READY draft c0193 func_400F12D0: as func_400F11E8, then sets flag 0x80000 (bit 19) in obj+0x44 after the data hookup.
 * Ghidra labels it as a non-matching (ELF symbol name) but shows the plain shape (ev_51d739a5ad7faa65a0cf47b2d9759a18cedbd23140ffc423bdde7f65fdbe8585). */
extern void iosJumpRecoverPoint(const char *, s32);

typedef struct { char s[10]; } NicoStr10;
extern const NicoStr10 D_401353A0;

/* READY draft c0193 sheetExecCommit: same shape as the matched sheetExecUpdate (nicosysd echo request 0x3EB).
 * Stack string copy of 11 bytes from rodata D_401353B0 (REA ev_51d739a5ad7faa65a0cf47b2d9759a18cedbd23140ffc423bdde7f65fdbe8585).
 * Callers: none resolved (called through a table).  Return is res[1] (lw 4(sp)).  Alt: char array copy. */
void nicosysdSendDataStart(void *, s32, void *, s32);
void nicosysdSendDataWrite(void *, void *, s32);
void nicosysdExec(void *, void *, void *);
void nicosysdEchoDdebugPrintReadCallBack(void);
typedef struct { char s[11]; } NicoStr11;
extern const NicoStr11 D_401353B0;

/* READY draft c0193 sheetExecMake: same shape as the matched sheetExecUpdate (nicosysd echo request 0x3EB).
 * Stack string copy of 11 bytes from rodata D_40135388 (REA ev_51d739a5ad7faa65a0cf47b2d9759a18cedbd23140ffc423bdde7f65fdbe8585).
 * Callers: none resolved (called through a table).  Return is res[1] (lw 4(sp)).  Alt: char array copy. */
void nicosysdSendDataStart(void *, s32, void *, s32);
extern const NicoStr11 D_40135388;

void func_400F10E8(void *chara)
{
    func_400EEE08(chara, func_400F14E0);
}

s32 func_400EEC40(s32 a, s32 b);
extern s32 D_4012E330;

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", func_400F1108);
void func_400F1108(s32 a0, s32 a1)
{
    s32 uVar1;

    uVar1 = func_400EEC40(a1, a0);
    *(s32 *)(a1 * 4 + D_4012E330) = uVar1;
    return;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", func_400F1148);
extern s32 D_401B53D0;
extern s32 rootPtn;
void *iosMallocAlign(void *, s32, s32);
extern void *memset(void *, s32, u32);

void func_400F1148(s32 a0, s32 a1, s32 a2)
{
    s32 uVar1;

    D_401B53D0 = a2 + 1;
    D_4012E330 = (s32)iosMallocAlign(&rootPtn, D_401B53D0 * 4, 0x10);
    memset((void *)D_4012E330, 0, D_401B53D0 << 2);
    uVar1 = func_400EEC40(a1, a0);
    *(s32 *)(a1 * 4 + D_4012E330) = uVar1;
    return;
}

void *func_400F11E8(s32 a0, s32 a1, s32 a2)
{
    s32 sheet;
    u8 *obj;

    sheet = *(s32 *)(a2 * 4 + D_4012E330);
    if (sheet == 0) {
        iosJumpRecoverPoint(D_401352D8, a2);
    }
    obj = _isysCreateObj(&rootPtn, 5, 0x58, isysGetXffWorkSize(a0), 0, 8);
    *(s32 *)(obj + 0x3C) = sheet;
    *(u32 *)(obj + 0x44) &= 0xC00FFFFF;
    *(u32 *)(obj + 0x44) &= 0xFFF7FFFF;
    isysInitGroup(obj + 0x48);
    if (a0 != 0) {
        func_400EF138(a0, a1, obj);
    } else {
        *(s32 *)(obj + 0x40) = 0;
    }
    return obj;
}

void *func_400F12D0(s32 a0, s32 a1, s32 a2)
{
    s32 sheet;
    u8 *obj;

    sheet = *(s32 *)(a2 * 4 + D_4012E330);
    if (sheet == 0) {
        iosJumpRecoverPoint(D_401352D8, a2);
    }
    obj = _isysCreateObj(&rootPtn, 5, 0x58, isysGetXffWorkSize(a0), 0, 8);
    *(s32 *)(obj + 0x3C) = sheet;
    *(u32 *)(obj + 0x44) &= 0xC00FFFFF;
    *(u32 *)(obj + 0x44) &= 0xFFF7FFFF;
    isysInitGroup(obj + 0x48);
    if (a0 != 0) {
        func_400EF138(a0, a1, obj);
    } else {
        *(s32 *)(obj + 0x40) = 0;
    }
    *(u32 *)(obj + 0x44) |= 0x80000;
    return obj;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", func_400F13C8);

extern unsigned char D_4012E32C[];

void *getSheetDebugNoLoadMode(void)
{
    return D_4012E32C;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", func_400F14E0);
void sheetFileUnloadCallBack(void *p);

void func_400F14E0(void *p)
{
    void (*fn)(void *);

    if ((*(s32 *)((u8 *)p + 0x44) & 0x3FF00000) == 0)
    {
        fn = (void (*)(void *))*(s32 *)(*(s32 *)(*(s32 *)((u8 *)p + 0x3C) + 0x38) + 8);
        if (fn != NULL)
        {
            fn(*(void **)((u8 *)p + 0x38));
        }
        if ((*(s32 *)((u8 *)p + 0x44) & 0x3FF00000) == 0)
        {
            sheetFileUnloadCallBack(p);
        }
    }
}

s32 sheetExecMake(void)
{
    s32 res[4];
    char buf[0x20];
    NicoStr11 str;
    s32 len;

    str = D_40135388;
    len = strlen(str.s) + 1;
    nicosysdSendDataStart(buf, 0x3EB, &rootPtn, len);
    nicosysdSendDataWrite(buf, str.s, len);
    nicosysdExec(buf, res, nicosysdEchoDdebugPrintReadCallBack);
    return res[1];
}

s32 sheetExecCommit(void)
{
    s32 res[4];
    char buf[0x20];
    NicoStr11 str;
    s32 len;

    str = D_401353B0;
    len = strlen(str.s) + 1;
    nicosysdSendDataStart(buf, 0x3EB, &rootPtn, len);
    nicosysdSendDataWrite(buf, str.s, len);
    nicosysdExec(buf, res, nicosysdEchoDdebugPrintReadCallBack);
    return res[1];
}

void nicosysdSendDataStart(void *, s32, void *, s32);
void nicosysdSendDataWrite(void *, void *, s32);
void nicosysdExec(void *, void *, void *);
void nicosysdEchoDdebugPrintReadCallBack(void);

typedef struct { char s[8]; } NicoStr;
extern const NicoStr D_40135398;

s32 sheetExecUpdate(void)
{
    s32 res[4];
    char buf[0x20];
    NicoStr str;
    s32 len;

    str = D_40135398;
    len = strlen(str.s) + 1;
    nicosysdSendDataStart(buf, 0x3EB, &rootPtn, len);
    nicosysdSendDataWrite(buf, str.s, len);
    nicosysdExec(buf, res, nicosysdEchoDdebugPrintReadCallBack);
    return res[1];
}

s32 sheetExecClean(void)
{
    s32 res[4];
    char buf[0x20];
    NicoStr10 str;
    s32 len;

    str = D_401353A0;
    len = strlen(str.s) + 1;
    nicosysdSendDataStart(buf, 0x3EB, &rootPtn, len);
    nicosysdSendDataWrite(buf, str.s, len);
    nicosysdExec(buf, res, nicosysdEchoDdebugPrintReadCallBack);
    return res[1];
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", getDebPcWinSw);
extern int D_4012E348;

void *getDebPcWinSw(void)
{
    return &D_4012E348;
}

extern int D_4012E348;

int GetDebPcWinSw(void)
{
    return D_4012E348;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", getDebPcWinType);
extern int D_4012E34C;

void *getDebPcWinType(void)
{
    return &D_4012E34C;
}

extern int D_4012E34C;

int GetDebPcWinType(void)
{
    return D_4012E34C;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", getDebPcWinCategory);
extern int D_4012E350;

void *getDebPcWinCategory(void)
{
    return &D_4012E350;
}

extern int D_4012E350;

int GetDebPcWinCategory(void)
{
    return D_4012E350;
}

void toggleDebPcWinWindow(void) {
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", func_400F1868);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", update_camera_context);

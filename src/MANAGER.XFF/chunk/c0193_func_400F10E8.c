#include "common.h"

void func_400EEE08(void *param, void (*func)(void));
void func_400F14E0(void *p);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", func_400F10E8);
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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", func_400F11E8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", func_400F12D0);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", sheetExecMake);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", sheetExecCommit);

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

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0193_func_400F10E8", sheetExecClean);

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

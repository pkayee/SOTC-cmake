#include "common.h"
#include "loaderSysFileIO.h"

typedef struct
{
    void* unk0;
    s32 socket;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14[5];
} McSlot; // size 0x28

typedef struct
{
    s32 code;
    s32 value;
    char* name;
} McErrEntry;

typedef struct
{
    s32 socket;
    s32 pad[9];
} McSockPad; // D_4007CE84 = &D_4007CE80[0].socket

extern McErrEntry D_40045608[22];
extern char D_40046B08[];
extern char D_40046BB0[];
extern char D_40046BF0[];
extern McSlot D_4007CE80[];
extern McSockPad D_4007CE84[];
extern u8 D_4007CC80[];

extern void iosLoaderResetEntry(void* func);
extern s32 sceMc2Init(s32 arg0);
extern s32 sceMc2CreateSocket(void* param, void* buf);
extern s32 sceMc2DeleteSocket(s32 socket);
extern s32 sceMc2Sync(s32 arg0, s32 arg1);
extern void sceMc2End(void);
extern s32 sceMc2GetInfo(s32 socket, void* info);
extern s32 sceMc2Chdir(s32 socket, void* path, void* arg2);
extern s32 sceMc2Mkdir(s32 socket, void* path);
extern s32 sceMc2CreateFile(s32 socket, void* path);
extern s32 sceMc2Delete(s32 socket, void* path);
extern s32 sceMc2ReadFile(s32 socket, void* a1, void* a2, void* a3, void* a4);
extern s32 sceMc2WriteFile(s32 socket, void* a1, void* a2, void* a3, void* a4);
extern s32 sceMc2Format(s32 socket);
extern s32 sceMc2Unformat(s32 socket);
extern s32 sceMc2GetDir(s32 socket, void* a1, void* a2, void* a3, void* a4, void* a5);

void func_400167B0(void);

static inline s32 iosMcErrConv(u16 code)
{
    s32 ret = 8;
    u32 i = 0;

    do
    {
        if (code == D_40045608[i].code)
        {
            ret = D_40045608[i].value;
            break;
        }
        i++;
    } while (i < 22);
    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/mc", iosMcInit);
void iosMcInit(void)
{
    s32 i;
    u8* buf;
    McSlot* slot;

    for (i = 1; i >= 0; i--)
    {
        D_4007CE80[i].socket = -1;
    }
    iosLoaderResetEntry(func_400167B0);
    if (sceMc2Init(0) != 0)
    {
        LoaderSysPrintf(D_40046BF0);
    }
    for (i = 0; i < 2; i++)
    {
        slot = &D_4007CE80[i];
        buf = D_4007CC80 + i * 0x100;
        slot->unk0 = buf;
        slot->unk8 = 2;
        slot->unkC = (i == 0) ? 2 : 3;
        slot->unk10 = 0;
        slot->socket = sceMc2CreateSocket(&slot->unk8, buf);
        sceMc2Sync(0, 0);
    }
}

INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/mc", iosMcGetInfo);

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/mc", iosMcChDir);
s32 iosMcChDir(s32 slot, s32 arg1, void* arg2)
{
    s32 i;
    s32 res;

    if (arg1)
    {
        LoaderSysPrintf(D_40046B08);
    }
    res = sceMc2Chdir(D_4007CE84[slot].socket, arg2, 0);
    return iosMcErrConv(res);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/mc", iosMcMkDir);
s32 iosMcMkDir(s32 slot, s32 arg1, void* arg2)
{
    s32 i;
    s32 res;

    if (arg1)
    {
        LoaderSysPrintf(D_40046B08);
    }
    res = sceMc2Mkdir(D_4007CE84[slot].socket, arg2) & 0xFFFF;
    return iosMcErrConv(res);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/mc", iosMcCreateFile);
s32 iosMcCreateFile(s32 slot, s32 arg1, void* arg2)
{
    s32 i;
    s32 res;

    if (arg1)
    {
        LoaderSysPrintf(D_40046B08);
    }
    res = sceMc2CreateFile(D_4007CE84[slot].socket, arg2) & 0xFFFF;
    return iosMcErrConv(res);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/mc", iosMcDeleteFile);
s32 iosMcDeleteFile(s32 slot, s32 arg1, void* arg2)
{
    s32 i;
    s32 res;

    if (arg1)
    {
        LoaderSysPrintf(D_40046B08);
    }
    res = sceMc2Delete(D_4007CE84[slot].socket, arg2) & 0xFFFF;
    return iosMcErrConv(res);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/mc", iosMcReadFile);
s32 iosMcReadFile(s32 slot, s32 arg1, void* arg2, void* arg3, void* arg4, void* arg5)
{
    u32 i;
    s32 ret;
    s32 res;

    if (arg1)
    {
        LoaderSysPrintf(D_40046B08);
    }
    res = sceMc2ReadFile(D_4007CE84[slot].socket, arg2, arg3, arg4, arg5);
    if (res >= 0)
    {
        return 0;
    }
    ret = 8;
    i = 0;
    do
    {
        if ((u16)res == D_40045608[i].code)
        {
            ret = D_40045608[i].value;
            break;
        }
        i++;
    } while (i < 22);
    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/mc", iosMcWriteFile);
s32 iosMcWriteFile(s32 slot, s32 arg1, void* arg2, void* arg3, void* arg4, void* arg5)
{
    u32 i;
    s32 ret;
    s32 res;

    if (arg1)
    {
        LoaderSysPrintf(D_40046B08);
    }
    res = sceMc2WriteFile(D_4007CE84[slot].socket, arg2, arg3, arg4, arg5);
    if (res >= 0)
    {
        return 0;
    }
    ret = 8;
    i = 0;
    do
    {
        if ((u16)res == D_40045608[i].code)
        {
            ret = D_40045608[i].value;
            break;
        }
        i++;
    } while (i < 22);
    return ret;
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/mc", iosMcFormat);
s32 iosMcFormat(s32 slot, s32 arg1)
{
    if (arg1)
    {
        LoaderSysPrintf(D_40046B08);
    }
    return sceMc2Format(D_4007CE84[slot].socket);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/mc", iosMcUnformat);
s32 iosMcUnformat(s32 slot, s32 arg1)
{
    if (arg1)
    {
        LoaderSysPrintf(D_40046B08);
    }
    return sceMc2Unformat(D_4007CE84[slot].socket);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/mc", iosMcGetDir);
s32 iosMcGetDir(s32 slot, s32 arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6)
{
    s32 res;

    if (arg1)
    {
        LoaderSysPrintf(D_40046B08);
    }
    res = sceMc2GetDir(D_4007CE84[slot].socket, arg2, arg3, arg4, arg5, arg6);
    res &= 0xFFFF;
    return iosMcErrConv(res);
}

//INCLUDE_ASM("asm/KERNEL.XFF/nonmatchings/ios/mc", func_400167B0);
void func_400167B0(void)
{
    s32 i;
    s32 res;
    McSlot* slot;

    slot = D_4007CE80;
    for (i = 0; i < 2; i++, slot++)
    {
        if (slot->socket >= 0)
        {
            sceMc2Sync(0, 0);
            res = sceMc2DeleteSocket(slot->socket);
            if (res != 0)
            {
                LoaderSysPrintf(D_40046BB0, i, slot->socket, res);
            }
            slot->socket = -1;
        }
    }
    sceMc2Sync(0, 0);
    sceMc2End();
}

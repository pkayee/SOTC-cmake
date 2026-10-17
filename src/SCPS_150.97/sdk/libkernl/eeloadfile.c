#include "common.h"
#include "sdk/ee/sifrpc.h"

s32 _sceSifLoadModuleBuffer(const void *ptr, s32 size, const void *args, s32 *modres);
s32 func_0010EB10(const char *path, s32 size, const void *args, s32 *modres, s32 mode);
s32 func_0010ED78(const char *path, const char *arg, void *elf, s32 mode);
extern s8 D_00138298[];
extern s32 D_00132430;
extern u8 D_00147728[];
extern u8 D_0013237C[];
extern s32 D_00132434;
extern s32 D_00147500[];
extern u8 D_00147508[];
extern sceSifClientData D_00147700[];

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", _lf_bind);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", _lf_version);
s32 _lf_version(void)
{
    s32 ret;
    u8 *p;

    p = D_0013237C;
    ret = 0;
    if (memcmp(D_00147728, p, 4) != 0)
    {
        if (memcmp(D_00147728, (void *)D_00132434, 4) != 0)
        {
            ret = memcmp(p, (void *)D_00132434, 4) != 0;
        }
    }
    return ret;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", sceSifLoadFileReset);
s32 sceSifLoadFileReset(void)
{
    D_00132430 = -1;
    memset(D_00147728, 0, 4);
    return 0;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", _sceSifLoadModuleBuffer);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", sceSifStopModule);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", sceSifUnloadModule);
s32 sceSifUnloadModule(s32 id)
{
    s32 ret;

    ret = _lf_bind();
    if (ret < 0)
    {
        return 0xFFFF0000;
    }
    if (_lf_version() != 0)
    {
        return 0xFFFEFFFC;
    }
    D_00147500[0] = id;
    ret = sceSifCallRpc(D_00147700, 8, 0, D_00147500, 4, D_00147500, 4, NULL, NULL);
    if (ret < 0)
    {
        return 0xFFFEFFFF;
    }
    return D_00147500[0];
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", sceSifSearchModuleByName);
s32 sceSifSearchModuleByName(const char *name)
{
    s32 ret;
    u8 *p;
    u8 *q;

    ret = _lf_bind();
    if (ret < 0)
    {
        return 0xFFFF0000;
    }
    if (_lf_version() != 0)
    {
        return 0xFFFEFFFC;
    }
    p = D_00147508;
    strncpy(p, name, 0xFC);
    q = p - 8;
    q[0x103] = 0;
    ret = sceSifCallRpc(D_00147700, 9, 0, q, 0x200, q, 4, NULL, NULL);
    if (ret < 0)
    {
        return 0xFFFEFFFF;
    }
    return ((s32 *)q)[0];
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", sceSifSearchModuleByAddress);
s32 sceSifSearchModuleByAddress(s32 addr)
{
    s32 ret;

    ret = _lf_bind();
    if (ret < 0)
    {
        return 0xFFFF0000;
    }
    if (_lf_version() != 0)
    {
        return 0xFFFEFFFC;
    }
    D_00147500[0] = addr;
    ret = sceSifCallRpc(D_00147700, 0xA, 0, D_00147500, 4, D_00147500, 4, NULL, NULL);
    if (ret < 0)
    {
        return 0xFFFEFFFF;
    }
    return D_00147500[0];
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", sceSifLoadModuleBuffer);
s32 sceSifLoadModuleBuffer(const void *ptr, s32 size, const void *args)
{
    s32 modres;

    return _sceSifLoadModuleBuffer(ptr, size, args, &modres);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", sceSifLoadStartModuleBuffer);
s32 sceSifLoadStartModuleBuffer(const void *ptr, s32 size, const void *args, s32 *modres)
{
    return _sceSifLoadModuleBuffer(ptr, size, args, modres);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", func_0010EB10);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", sceSifLoadModule);
s32 sceSifLoadModule(const char *path, s32 size, const void *args)
{
    s32 modres;

    return func_0010EB10(path, size, args, &modres, 0);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", sceSifLoadStartModule);
s32 sceSifLoadStartModule(const char *path, s32 size, const void *args, s32 *modres)
{
    return func_0010EB10(path, size, args, modres, 0);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", func_0010ED78);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", sceSifLoadElfPart);
s32 sceSifLoadElfPart(const char *path, const char *arg, void *elf)
{
    return func_0010ED78(path, arg, elf, 1);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", sceSifLoadElf);
s32 sceSifLoadElf(const char *path, void *elf)
{
    return func_0010ED78(path, (const char *)D_00138298, elf, 1);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", sceSifGetIopAddr);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", sceSifSetIopAddr);


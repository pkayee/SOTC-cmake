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

/* NEARMISS-STUB _lf_bind */
#if 0 /* NEARMISS 49.0% cat=branch-layout sub=- | bind retry loop layout: bgez shared return-0 exit, serve load in bgezl delay slot | attempts=1 */
s32 _lf_bind(void)
{
    s32 ret;
    s32 i;

    if (D_00132430 >= 0)
    {
        return 0;
    }
    for (;;)
    {
        ret = sceSifBindRpc(D_00147700, 0x80000006, 0);
        if (ret < 0)
        {
            return -1;
        }
        if (D_00147700->serve != NULL)
        {
            break;
        }
        for (i = 0x100000; i != -1; i--)
        {
        }
    }
    D_00132430 = 0;
    ret = sceSifCallRpc(D_00147700, 0xFF, 0, NULL, 0, D_00147500, 4, NULL, NULL);
    if (ret < 0)
    {
        return 0xFFFEFFFF;
    }
    memcpy(D_00147728, D_00147500, 4);
    return 0;
}
#endif
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

/* NEARMISS-STUB _sceSifLoadModuleBuffer */
#if 0 /* NEARMISS 88.6% cat=regalloc sub=- | ldl/ldr 0xFC copy loop regalloc, extra s-reg frame 0x90 vs 0x80 | attempts=1 */
s32 _sceSifLoadModuleBuffer(const void *ptr, s32 size, const void *args, s32 *modres)
{
    s32 ret;
    s32 *p;

    ret = _lf_bind();
    if (ret < 0)
    {
        return 0xFFFF0000;
    }
    if (_lf_version() != 0)
    {
        return 0xFFFEFFFC;
    }
    p = D_00147500;
    p[0] = (s32)ptr;
    if (args != NULL)
    {
        if (size >= 0xFD)
        {
            memcpy((u8 *)p + 0x104, args, 0xFC);
            p[1] = 0xFC;
        }
        else
        {
            memcpy((u8 *)p + 0x104, args, size);
            p[1] = size;
        }
    }
    else
    {
        p[1] = 0;
    }
    ret = sceSifCallRpc(D_00147700, 6, 0, p, 0x200, p, 8, NULL, NULL);
    if (ret < 0)
    {
        return 0xFFFEFFFF;
    }
    *modres = p[1];
    return p[0];
}
#endif
INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", _sceSifLoadModuleBuffer);

/* NEARMISS-STUB sceSifStopModule */
#if 0 /* NEARMISS 99.99% cat=sdk-compiler sub=- | sole diff: same dead hoisted lui a1 constant 0x14 (no reloc) in unaligned copy path vs ours %hi(D_00147700) | attempts=1 */
s32 sceSifStopModule(s32 id, s32 size, const void *args, s32 *modres)
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
    if (args != NULL)
    {
        if (size >= 0xFD)
        {
            memcpy((u8 *)D_00147500 + 0x104, args, 0xFC);
            D_00147500[1] = 0xFC;
        }
        else
        {
            memcpy((u8 *)D_00147500 + 0x104, args, size);
            D_00147500[1] = size;
        }
    }
    else
    {
        D_00147500[1] = 0;
    }
    ret = sceSifCallRpc(D_00147700, 7, 0, D_00147500, 0x200, D_00147500, 8, NULL, NULL);
    if (ret < 0)
    {
        return 0xFFFEFFFF;
    }
    ret = D_00147500[0];
    *modres = D_00147500[1];
    return ret;
}
#endif
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

/* NEARMISS-STUB func_0010EB10 */
#if 0 /* NEARMISS 99.99% cat=sdk-compiler sub=- | sole diff: dead hoisted lui a1 at unaligned 0xFC copy path is constant 0x14 (no reloc) in expected, ours %hi(D_00147700); constant-address client arg (sceSifCli | attempts=1 */
s32 func_0010EB10(const char *path, s32 size, const void *args, s32 *modres, s32 mode)
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
    strncpy(p, path, 0xFC);
    q = p - 8;
    q[0x103] = 0;
    if (args != NULL)
    {
        if (size >= 0xFD)
        {
            memcpy(p + 0xFC, args, 0xFC);
            D_00147500[0] = 0xFC;
        }
        else
        {
            memcpy(p + 0xFC, args, size);
            *(s32 *)q = size;
        }
    }
    else
    {
        q[0x104] = 0;
        *(s32 *)q = 0;
    }
    ret = sceSifCallRpc(D_00147700, mode, 0, D_00147500, 0x200, D_00147500, 8, NULL, NULL);
    if (ret < 0)
    {
        return 0xFFFEFFFF;
    }
    ret = D_00147500[0];
    *modres = D_00147500[1];
    return ret;
}
#endif
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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", func_0010ED78);
s32 func_0010ED78(const char *path, const char *arg, void *elf, s32 mode)
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
    strncpy(p, path, 0xFC);
    q = p - 8;
    q[0x103] = 0;
    strncpy(p + 0xFC, arg, 0xFC);
    q[0x1FF] = 0;
    ret = sceSifCallRpc(D_00147700, mode, 0, q, 0x200, q, 0x10, NULL, NULL);
    if (ret < 0)
    {
        return 0xFFFEFFFF;
    }
    if (((s32 *)q)[0] == 0)
    {
        return 0xFFFEFFFD;
    }
    ((s32 *)elf)[0] = ((s32 *)q)[0];
    ((s32 *)elf)[1] = ((s32 *)q)[1];
    return 0;
}

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

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", sceSifGetIopAddr);
s32 sceSifGetIopAddr(s32 addr, void *dst, s32 type)
{
    s32 ret;

    ret = _lf_bind();
    if (ret < 0)
    {
        return 0xFFFF0000;
    }
    if ((u32)type >= 3)
    {
        return 0xFFFEFFFE;
    }
    D_00147500[0] = addr;
    D_00147500[1] = type;
    ret = sceSifCallRpc(D_00147700, 3, 0, D_00147500, 0x20, D_00147500, 0x20, NULL, NULL);
    if (ret < 0)
    {
        return 0xFFFEFFFF;
    }
    if (type == 0)
    {
        *(u8 *)dst = *(u8 *)&D_00147500[0];
    }
    else if (type == 1)
    {
        *(u16 *)dst = *(u16 *)&D_00147500[0];
    }
    else if (type == 2)
    {
        *(s32 *)dst = D_00147500[0];
    }
    else
    {
        return 0xFFFEFFFE;
    }
    return 0;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/eeloadfile", sceSifSetIopAddr);
s32 sceSifSetIopAddr(s32 addr, const void *src, s32 type)
{
    s32 ret;

    ret = _lf_bind();
    if (ret < 0)
    {
        return 0xFFFF0000;
    }
    D_00147500[0] = addr;
    D_00147500[1] = type;
    if (type == 0)
    {
        *(u8 *)&D_00147500[2] = *(const u8 *)src;
    }
    else if (type == 1)
    {
        *(u16 *)&D_00147500[2] = *(const u16 *)src;
    }
    else if (type == 2)
    {
        D_00147500[2] = *(const s32 *)src;
    }
    else
    {
        return 0xFFFEFFFE;
    }
    ret = sceSifCallRpc(D_00147700, 2, 0, D_00147500, 0x20, D_00147500, 0x10, NULL, NULL);
    if (ret < 0)
    {
        return 0xFFFEFFFF;
    }
    return 0;
}

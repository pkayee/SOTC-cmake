#include "common.h"

void InitTLB(void);
void _Exit(int status);
extern char *D_001327B0;
extern s32 D_00133268[];
extern char D_00138370[];
s32 func_001100B0(void *dst, void *src, s32 n);
void setup(s32 a, s32 b);
u32 strlen(const char *s);
void func_00110218(void);
char *SetArg(char *name, s32 argc, char **argv);
void _ExecOSD(s32 argc, char *p);
s32 _ExecPS2(void *entry, void *gp, s32 argc, char *p);
void _LoadExecPS2(char *r, s32 argc, char *p);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/exit", func_001100B0);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/exit", func_001100C0);
s32 func_001100C0(u8 *dst, u8 *src, u32 n)
{
    u32 i;

    for (i = 0; i < n; i++)
    {
        *dst++ = *src++;
    }
    return 0;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libkernl/exit", setup);

char *SetArg(char *name, s32 argc, char **argv)
{
    char *base;
    char *p;
    char *ret;
    char **ap;
    s32 len;

    base = D_001327B0;
    ret = p = base + 0x40;
    setup(D_00133268[0], D_00133268[1]);
    if (argc >= 0x10)
    {
        argc = 0xF;
    }
    func_001100B0(base, &p, 4);
    base += 4;
    len = strlen(name) + 1;
    func_001100B0(p, name, len);
    p += len;
    if (argc > 0)
    {
        ap = argv;
        do
        {
            func_001100B0(base, &p, 4);
            base += 4;
            argc--;
            len = strlen(*ap) + 1;
            func_001100B0(p, *ap, len);
            ap++;
            p += len;
        } while (argc != 0);
    }
    return ret;
}

void func_00110218(void)
{
    InitTLB();
}

s32 ExecPS2(void *entry, void *gp, s32 argc, char **argv)
{
    SetArg(D_00138370, argc, argv);
    func_00110218();
    return _ExecPS2(entry, gp, argc, D_001327B0 + 4);
}

void LoadExecPS2(char *name, s32 argc, char **argv)
{
    char *r;

    r = SetArg(name, argc, argv);
    func_00110218();
    _LoadExecPS2(r, argc, D_001327B0 + 4);
}

void Exit(int status)
{
    func_00110218();
    _Exit(status);
}

void ExecOSD(s32 argc, char **argv)
{
    SetArg(D_00138370, argc, argv);
    func_00110218();
    _ExecOSD(argc, D_001327B0 + 4);
}

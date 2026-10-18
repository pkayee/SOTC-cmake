#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0121_ExecObjectAnimation", ExecObjectAnimation);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0121_ExecObjectAnimation", ExecMotionSyncAnimation);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0121_ExecObjectAnimation", SetScriptAnimationGlobalBaseInfo);

extern u8 info[];

void *GetScriptAnimationGlobalBaseInfo(void)
{
    return info;
}

typedef union
{
    s128 q;
    float f[4];
    int i[4];
} Vec4;

extern void GetGeometryPointerQuaternion(void *, char *);
extern void GetGeometryPointerPosition(void *, char *);
extern void *GetGeometryPointerObject(char *);
extern char *GetLayoutClass(unsigned char *);

int GetScriptAnimationWindParam(char *out, char *source)
{
    char *geometry = source + 0x10;
    char *layout;

    ((Vec4 *)out)->i[0] = **(signed char **)source;
    ((Vec4 *)out)->f[1] = **(float **)(source + 4);
    ((Vec4 *)out)->f[2] = **(float **)(source + 8) * 0.5f;
    ((Vec4 *)out)->f[3] = **(float **)(source + 12) * 0.5f;
    GetGeometryPointerQuaternion(out + 0x20, geometry);
    GetGeometryPointerPosition(out + 0x10, geometry);
    layout = GetLayoutClass(GetGeometryPointerObject(geometry));
    ((Vec4 *)(out + 0x30))->q = ((Vec4 *)(layout + 0x90))->q;
    return *(int *)out;
}

void CopyScriptAnimationWindParam(void *arg0, void *arg1)
{
    (*(long *)((char *)(arg0) + 0)) = (long) (*(long *)((char *)(arg1) + 0));
    (*(long *)((char *)(arg0) + 8)) = (long) (*(long *)((char *)(arg1) + 8));
    (*(long *)((char *)(arg0) + 0x10)) = (long) (*(long *)((char *)(arg1) + 0x10));
    (*(long *)((char *)(arg0) + 0x18)) = (long) (*(long *)((char *)(arg1) + 0x18));
    (*(long *)((char *)(arg0) + 0x20)) = (long) (*(long *)((char *)(arg1) + 0x20));
    (*(long *)((char *)(arg0) + 0x28)) = (long) (*(long *)((char *)(arg1) + 0x28));
    (*(long *)((char *)(arg0) + 0x30)) = (long) (*(long *)((char *)(arg1) + 0x30));
    (*(long *)((char *)(arg0) + 0x38)) = (long) (*(long *)((char *)(arg1) + 0x38));
}

typedef struct
{
    long d[10];
} WindGeom;

void CopyScriptAnimationWindGeometryPointer(WindGeom *dst, WindGeom *src)
{
    *dst = *src;
}

extern unsigned char D_4012B1D0[];

void *getLWSDebugMode(void)
{
    return D_4012B1D0;
}

char *GetScriptAnimationClass(unsigned char *p)
{
    if (p[0x8] != 0xD)
    {
        return 0;
    }
    return (char *)p + 0x20;
}

extern void *CreateScriptAnimationSequence(void *);
extern void PlayScriptAnimationSequence(void *, int, int, int);

void *SetScriptAnimationSinglePlay(char *a)
{
    void *s = CreateScriptAnimationSequence(a);
    if (s != 0)
        PlayScriptAnimationSequence(s, *(int *)(a + 0x24), -1, 3);
    return s;
}

int SetScriptAnimationObjGeometryOverrideCallBackFunc(unsigned char *p, int func, int arg)
{
    unsigned char *c = p[8] != 0xD ? 0 : p + 0x20;
    if (*(int *)(c + 0x36C) == 0)
    {
        *(int *)(c + 0x36C) = func;
        *(int *)(c + 0x370) = arg;
        return 1;
    }
    return 0;
}

void SetScriptAnimationObjChildEntryGroup(unsigned char *p, int a)
{
    char *c = p[8] != 0xD ? 0 : (char *)p + 0x20;

    *(int *)(c + 0x374) = a;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0121_ExecObjectAnimation", updateLayoutGeo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0121_ExecObjectAnimation", updateCamVibGeo);

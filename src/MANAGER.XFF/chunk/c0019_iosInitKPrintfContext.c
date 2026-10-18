#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0019_iosInitKPrintfContext", iosInitKPrintfContext);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0019_iosInitKPrintfContext", iosInitKPrintfContext3D);

void iosSetKPrintfColorContext(char *p, int c, float r, float g, float b, float a)
{
    *(float *)(p + 0x20) = r;
    *(float *)(p + 0x24) = g;
    *(float *)(p + 0x28) = b;
    *(float *)(p + 0x2C) = a;
    *(int *)(p + 0x30) = c;
}

void iosSetKPrintfLocateContext(char *p, float f1, float f2)
{
    *(float *)(p + 0x8) = f1;
    *(float *)(p + 0x0) = f1;
    *(float *)(p + 0xC) = f2;
    *(float *)(p + 0x4) = f2;
}

void iosSetKPrintfLocateContextRelativePosition(void *arg0, float fparg0, float fparg1)
{
    (*(float *)((char *)(arg0) + 0)) = (float) ((*(float *)((char *)(arg0) + 0)) - fparg0);
    (*(float *)((char *)(arg0) + 8)) = (float) ((*(float *)((char *)(arg0) + 8)) - fparg0);
    (*(float *)((char *)(arg0) + 4)) = (float) ((*(float *)((char *)(arg0) + 4)) - fparg1);
    (*(float *)((char *)(arg0) + 0xC)) = (float) ((*(float *)((char *)(arg0) + 0xC)) - fparg1);
}

void iosSetKPrintfDynamicsContext(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x34)) = arg1;
}

void iosSetKPrintfDlContext(void *arg0, int arg1)
{
    (*(int *)((char *)(arg0) + 0x38)) = arg1;
}

void iosSetKPrintfScaleContext(void *arg0, float fparg0)
{
    (*(float *)((char *)(arg0) + 0x3C)) = fparg0;
}

extern char D_40129E38[];

void *getFontBoard(void)
{
    return D_40129E38;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0019_iosInitKPrintfContext", func_4002A9B0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0019_iosInitKPrintfContext", setLightParam);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0019_iosInitKPrintfContext", setLight);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0019_iosInitKPrintfContext", getAmbientColorC);

extern unsigned char D_40129F90[];

void *getSpecularity(void)
{
    return D_40129F90;
}

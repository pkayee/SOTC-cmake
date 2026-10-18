#include "common.h"

extern char *iosGetPacketPtrPath1(void);
extern void iosSetPacketPtrPath1(char *);
extern char *iosDlGetEndAdrs(void);

void ptclDisplayListPut(s32 n)
{
    char *p = iosGetPacketPtrPath1();
    p += n * 48;
    iosSetPacketPtrPath1(p);
    return;
}

char *ptclDisplayListGet(s32 n)
{
    char *p = iosGetPacketPtrPath1();
    if (iosDlGetEndAdrs() < p + n * 48)
        return 0;
    return p;
}

extern unsigned char D_401ABDC8[];

void ptclmanBegin(void)
{
    (*(int *)((char *)(D_401ABDC8) + 0)) = (int)iosGetPacketPtrPath1();
    (*(int *)((char *)(D_401ABDC8) + 4)) = 0;
}

extern int *ptclmanGet(void);
extern void ptclmanPut(int);
extern void iosDlChainTailCurrent(int);

void ptclmanEnd(void)
{
    int *p = ptclmanGet();
    p[0] = 0x60000000;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0x13000000;
    ptclmanPut(1);
    iosSetPacketPtrPath1((char *)ptclmanGet());
    iosDlChainTailCurrent(*(int *)D_401ABDC8);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0027_ptclDisplayListPut", ptclmanBuildEnvPacket);

int *ptclmanGet(void)
{
    return (int *)((*(int *)((char *)(D_401ABDC8) + 0)) + ((*(int *)((char *)(D_401ABDC8) + 4)) * 0x10));
}

void ptclmanPut(int a)
{
    int *p = (int *)D_401ABDC8;

    p[1] += a;
}

extern int iosgluGetCameraContext(int, int, int, int);
extern void iosCopyMatrix(void *, int);
extern unsigned char D_401ABDE0[];
extern int D_4012A510;
extern void *D_4012A514;

void ptclmanFrameInit(int arg0, int arg1, int arg2, int arg3)
{
    int temp_a1;
    int temp_s1;
    int temp_v1;
    void *temp_v0;

    temp_s1 = iosgluGetCameraContext(arg0, arg1, arg2, arg3);
    temp_a1 = temp_s1 + 0x1A0;
    temp_v1 = D_4012A510 ^ 1;
    D_4012A510 = temp_v1;
    temp_v0 = D_401ABDE0 + (temp_v1 * 0x120);
    D_4012A514 = temp_v0;
    iosCopyMatrix(temp_v0, temp_a1);
    iosCopyMatrix(D_4012A514 + 0x40, temp_s1 + 0x460);
    iosCopyMatrix(D_4012A514 + 0x80, temp_s1 + 0x5E0);
    iosCopyMatrix(D_4012A514 + 0xC0, temp_s1 + 0x520);
    (*(s128 *)((char *)(D_4012A514) + 0x100)) = (s128) (*(s128 *)((char *)(temp_s1) + 0x140));
    (*(s128 *)((char *)(D_4012A514) + 0x110)) = (s128) (*(s128 *)((char *)(temp_s1) + 0x150));
}

void ptclCounterInit(void) {
}

s32 ptclCounterGet(void)
{
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0027_ptclDisplayListPut", meshDispInstance);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0027_ptclDisplayListPut", meshCreate);

char *GetMeshClass(unsigned char *p)
{
    if (p[0x8] != 0x23)
    {
        return 0;
    }
    return (char *)p + 0x20;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0027_ptclDisplayListPut", meshTransMatrix);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0027_ptclDisplayListPut", meshTransLightMatrix);

extern void iosDlLockObj(unsigned char *);
extern void iosDlChainTailCurrent(int);

void meshDisp(unsigned char *p)
{
    int *m;
    iosDlLockObj(p);
    m = (int *)(p[8] != 0x23 ? 0 : p + 0x20);
    m += m[4];
    iosDlChainTailCurrent(*m);
}

void meshFlip(unsigned char *p)
{
    char *c;

    if (p[0x8] != 0x23)
    {
        c = 0;
    }
    else
    {
        c = (char *)p + 0x20;
    }
    *(s32 *)(c + 0x10) = *(s32 *)(c + 0x10) == 0;
}

extern int iosFree();

int meshInstanceFree(int a, int b, int c, int d)
{
    return iosFree(a, b, c, d);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0027_ptclDisplayListPut", meshCreateInstanceCopy);

int meshGetWorkSize(int count, int nodes)
{
    int size = (nodes * 64 + 16) * count;

    return (size << 1) + 0x289;
}

extern int isysRequestDeleteObj();

int meshObjectFree(int a, int b, int c, int d)
{
    return isysRequestDeleteObj(a, b, c, d);
}

void func_40033840(void) {
}

void func_40033848(void) {
}

extern void *_isysCreateObj(void *, s32, s32, void *, void *, s32);
extern void isysSetObjImmediateDeleteFunc(void *, void *);

void *CreateMeshObj(void *heap, s32 a, void *b)
{
    void *o = _isysCreateObj(heap, 0x23, 0x90, b, func_40033840, 0x10);
    isysSetObjImmediateDeleteFunc(o, func_40033848);
    return o;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0027_ptclDisplayListPut", reflectionBegin);

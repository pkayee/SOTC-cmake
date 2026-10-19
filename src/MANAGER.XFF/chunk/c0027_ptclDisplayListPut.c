#include "common.h"

extern char *iosGetPacketPtrPath1(void);
extern void iosSetPacketPtrPath1(char *);
extern char *iosDlGetEndAdrs(void);

typedef struct { u64 d[12]; } MeshBlk60;
extern void *iosMallocAlign(void *, s32, s32);
extern void iosUnitMatrix(void *);

extern void iosDlLockObj(unsigned char *);

extern void iosCopyMatrix(void *, int);
extern void *D_4012A514;
extern u128 D_4012A500;
extern f32 getFogFactor0(void);
extern f32 getFogFactor1(void);

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

/* READY MANAGER c0027 ptclmanBuildEnvPacket: 100.0 via try-score (rea-mgr-c0027, 2026-10-19). Env GIF packet appended at D_401ABDC8 (s32 view g: g[0]=buffer base, g[1]=quad index, g[2]=mode word); args (fog, color quad, mode, matrix, optional quad a, optional quad b) per caller func_400D0048 (REA ev_b626512c...). The 4 trailing const stores must be written in address order A0,A4,A8,AC (AC first = 99.78, only const-reg order differs); D_4012A500 quad copied through the pointer form (lui/addiu/lq). */
void ptclmanBuildEnvPacket(f32 fog, u128 *col, s32 mode, s32 mtx, u128 *a, u128 *b) {
    s32 *g;
    u8 *p;
    u8 *q;
    u32 *w;

    g = (s32 *)D_401ABDC8;
    p = (u8 *)g[0] + g[1] * 0x10;
    w = (u32 *)p;
    q = p + 0x20;
    g[2] = mode;
    w[0] = 0x30000012;
    w[1] = (u32)D_4012A514 & 0xFFFFFFF;
    w[2] = 0x13000000;
    w[3] = 0x6C120000;
    w[4] = 0x1000000B;
    w[5] = 0;
    w[6] = 0;
    w[7] = 0x6C0A0012;
    iosCopyMatrix(q, mtx);
    *(u128 *)(q + 0x50) = D_4012A500;
    *(u128 *)(q + 0x60) = *col;
    *(f32 *)(q + 0x70) = getFogFactor0();
    *(f32 *)(q + 0x7C) = getFogFactor1() * fog;
    *(s32 *)(q + 0x40) = mode;
    if (a != 0) {
        *(u128 *)(q + 0x80) = *a;
    }
    if (b != 0) {
        *(u128 *)(q + 0x90) = *b;
    }
    *(u32 *)(q + 0xA0) = 0x15000000;
    *(u32 *)(q + 0xA4) = 0x3000028;
    *(u32 *)(q + 0xA8) = 0x200018C;
    *(u32 *)(q + 0xAC) = 0x1000101;
    g[1] += 0xD;
}

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

/* READY MANAGER c0027 meshDispInstance: 100.0 via try-score (rea-mgr-c0027, 2026-10-19). Mesh class pointer n = o + 0x20 kept in its own var (m = 0 then conditional copy gives movz; n = 0 conditional gives movn); a single shared var or n[n[4]] gives 80-87. Uses iosDlChainTailCurrent(int) already declared in the TU. */
void meshDispInstance(u8 *p) {
    u8 *o = *(u8 **)(p + 0xC0);
    s32 *m = 0;
    s32 *n;

    n = (s32 *)(o + 0x20);
    if (o[8] == 0x23) {
        m = n;
    }
    iosDlLockObj(o);
    iosDlChainTailCurrent((s32)(p + m[4] * 0x60));
    if (o[8] != 0x23) {
        n = 0;
    }
    n += n[4];
    iosDlChainTailCurrent(*n);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0027_ptclDisplayListPut", meshCreate);

char *GetMeshClass(unsigned char *p)
{
    if (p[0x8] != 0x23)
    {
        return 0;
    }
    return (char *)p + 0x20;
}

extern void *iosAllocPacketPtrPath1(s32);

void meshTransMatrix(s32 mtx)
{
    u8 *packet;

    packet = iosAllocPacketPtrPath1(0x60);
    *(u64 *)packet = 0x60000005;
    *(u32 *)(packet + 0x8) = 0x1000101;
    *(u32 *)(packet + 0xC) = 0x6C048000;
    iosCopyMatrix(packet + 0x10, mtx);
    *(u32 *)(packet + 0x50) = 0x15000006;
    *(u32 *)(packet + 0x54) = 0;
    *(u32 *)(packet + 0x58) = 0;
    *(u32 *)(packet + 0x5C) = 0;
    iosDlChainTailCurrent((s32)packet);
}

/* READY MANAGER c0027 meshTransLightMatrix: 100.0 via try-score (rea-mgr-c0027, 2026-10-19). Twin of the matched meshTransMatrix: packet 0xA0 bytes, two matrices at +0x10 and +0x50, EOP tag at +0x90. Needs iosAllocPacketPtrPath1 and iosCopyMatrix declared earlier in the TU (they are). */
void meshTransLightMatrix(s32 m1, s32 m2) {
    u8 *packet;

    packet = iosAllocPacketPtrPath1(0xA0);
    *(u64 *)packet = 0x60000009;
    *(u32 *)(packet + 0x8) = 0x1000101;
    *(u32 *)(packet + 0xC) = 0x6C0803D8;
    iosCopyMatrix(packet + 0x10, m1);
    iosCopyMatrix(packet + 0x50, m2);
    *(u32 *)(packet + 0x90) = 0x14000002;
    *(u32 *)(packet + 0x94) = 0;
    *(u32 *)(packet + 0x98) = 0;
    *(u32 *)(packet + 0x9C) = 0;
    iosDlChainTailCurrent((s32)packet);
}

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

/* READY MANAGER c0027 meshCreateInstanceCopy: 100.0 via try-score (rea-mgr-c0027, 2026-10-19). The 0x60-byte copy of the header packet to +0x60 is a struct of 12 u64 (gives the 3-pass ld/sd x4 loop); the sd of the 64-bit tag must be written AFTER the 0xC0 store so it lands in the iosUnitMatrix delay slot (tag first = 97). */
void *meshCreateInstanceCopy(void *heap, s32 a) {
    u8 *p;

    p = iosMallocAlign(heap, 0xD0, 0x10);
    *(u32 *)(p + 0x8) = 0x1000101;
    *(u32 *)(p + 0xC) = 0x6C048000;
    *(s32 *)(p + 0xC0) = a;
    *(u64 *)p = 0x60000005;
    iosUnitMatrix(p + 0x10);
    *(u32 *)(p + 0x50) = 0x15000006;
    *(u32 *)(p + 0x54) = 0;
    *(u32 *)(p + 0x58) = 0;
    *(u32 *)(p + 0x5C) = 0;
    *(MeshBlk60 *)(p + 0x60) = *(MeshBlk60 *)p;
    return p;
}

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

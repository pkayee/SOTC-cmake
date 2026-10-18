#include "common.h"

typedef struct {
    u8 pad00[0x14];
    void *p14;      /* 0x14 */
    void *p18;      /* 0x18 */
    u8 pad1c[4];
    s32 f20;        /* 0x20 */
    s32 f24;        /* 0x24 */
    void *p28;      /* 0x28 */
    s32 f2c;        /* 0x2c */
    void *p30;      /* 0x30 */
    s32 f34;        /* 0x34 */
    void *p38;      /* 0x38 */
    s32 f3c;        /* 0x3c */
} PathFree;
extern PathFree D_4002DF80;
void iosFree();

void glColor4fv(float *c);

extern s32 D_4002E058;
void DebugDispWideLineNotBlendVU1();
void DebugDispWideLineHalfVU1();

void DebugDispArrowNotBlendVU1();
void DebugDispArrowHalfVU1();

extern char D_40021050[];
void iosDlPushLayer(s32 a);
void iosDlPopLayer(void);
s32 iosInitKPrintfContext3D(float r, float g, float b, float a, void *ctx, s32 x, s32 y, s32 z);
void kprintfContextCentering(void *ctx, char *fmt, s32 v);

typedef struct {
    s32 id;     /* 0x00 */
    u16 val;    /* 0x04 */
} InterestEdit;
typedef struct {
    u8 pad00[0x10];
    u16 val;    /* 0x10 */
} InterestPoint;
extern s32 D_4002DFA8;
extern InterestEdit D_4002F028;
InterestPoint *getInterestPointData(s32 h, s32 idx);

typedef struct {
    s32 id;     /* 0x00 */
    u16 v0;     /* 0x04 */
    u16 pad06;
    u16 v1;     /* 0x08 */
    u16 pad0a;
    u16 v2;     /* 0x0c */
    u16 pad0e;
    u16 v3;     /* 0x10 */
    u16 pad12;
    u16 v4;     /* 0x14 */
} DeadEdit;
typedef struct {
    u8 pad00[0x10];
    u16 v0;     /* 0x10 */
    u16 v1;     /* 0x12 */
    u16 v2;     /* 0x14 */
    u16 v3;     /* 0x16 */
    u16 v4;     /* 0x18 */
} DeadPoint;
extern s32 D_4002DFB0;
extern DeadEdit D_4002F038;
DeadPoint *getDeadPointData(s32 h, s32 idx);

void func_4001AB18(s32 a, s32 b);
void func_40011780(s32 a);

void func_4001C278(void) {
    if (D_4002DF80.f20 != 0) {
        iosFree(D_4002DF80.p14);
    }
    D_4002DF80.p14 = 0;
    D_4002DF80.f20 = 0;
}

extern u8 padManagerData[];
void func_40018E78();

void func_4001C2B8(void)
{
    if (*(s32 *)(padManagerData + 8) & 0x20)
    {
        func_40018E78();
    }
    return;
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001C2E8);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001C3F0);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001C4C8);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001C548);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001C660);

void func_4001C738(void) {
    if (D_4002DF80.f24 != 0) {
        iosFree(D_4002DF80.p18);
    }
    D_4002DF80.p18 = 0;
    D_4002DF80.f24 = 0;
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001C778);

void func_4001C898(float *col) {
    float v[4];
    v[0] = 1.0f - col[0];
    v[1] = 1.0f - col[1];
    v[2] = 1.0f - col[2];
    v[3] = col[3];
    glColor4fv(v);
}

//INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001C8F0);
void DebugDispTriangularPyramidNotBlendVU1();

void func_4001C8F0(void)
{
    DebugDispTriangularPyramidNotBlendVU1();
}

void func_4001C908(void) {
    if (D_4002E058 != 0) {
        DebugDispWideLineNotBlendVU1();
        return;
    }
    DebugDispWideLineHalfVU1();
}

void func_4001C938(void) {
    if (D_4002E058 != 0) {
        DebugDispArrowNotBlendVU1();
        return;
    }
    DebugDispArrowHalfVU1();
}

void func_4001C968(s32 a, s32 b) {
    u8 ctx[0x40];
    func_4001C8F0();
    iosDlPushLayer(0x19);
    if (iosInitKPrintfContext3D(1.0f, 1.0f, 1.0f, 1.0f, ctx, a, 0, 1)) {
        kprintfContextCentering(ctx, D_40021050, b);
    }
    iosDlPopLayer();
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001C9F0);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001CBD8);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001CC50);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001CD00);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001CDB0);

void func_4001CE88(void) {
    if (D_4002DF80.f2c != 0) {
        iosFree(D_4002DF80.p28);
    }
    D_4002DF80.p28 = 0;
    D_4002DF80.f2c = 0;
}

void func_4001CEC8(void) {
    InterestPoint *p;
    if (D_4002DFA8 != 0) {
        p = getInterestPointData(D_4002DFA8, D_4002F028.id);
        p->val = D_4002F028.val;
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001CF10);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001CFE0);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001D0A8);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001D148);

void func_4001D220(void) {
    if (D_4002DF80.f34 != 0) {
        iosFree(D_4002DF80.p30);
    }
    D_4002DF80.p30 = 0;
    D_4002DF80.f34 = 0;
}

void func_4001D260(void) {
    DeadPoint *p;
    if (D_4002DFB0 != 0) {
        p = getDeadPointData(D_4002DFB0, D_4002F038.id);
        p->v0 = D_4002F038.v0;
        p->v1 = D_4002F038.v1;
        p->v2 = D_4002F038.v2;
        p->v3 = D_4002F038.v3;
        p->v4 = D_4002F038.v4;
    }
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001D2C8);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001D3B0);

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001D4C0);

void func_4001D598(void) {
    if (D_4002DF80.f3c != 0) {
        iosFree(D_4002DF80.p38);
    }
    D_4002DF80.p38 = 0;
    D_4002DF80.f3c = 0;
}

INCLUDE_ASM("asm/PATHTOOL.XFF/nonmatchings/chunk/c0007_func_4001C278", func_4001D5D8);

void func_4001D668(void) {
    func_4001AB18(0, 0);
    if (*(s32 *)(padManagerData + 8) & 0x20) {
        func_40011780(1);
    }
}

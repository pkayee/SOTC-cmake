#include "common.h"

extern s32 D_4001E060;
extern float D_4001EC00[];
void iosSetCurrentMatrix();
void iosTransCurrentMatrix(void *v);
void iosGetCurrentMatrix(void *m);
void glLoadMatrixf(void *m);
void iosDlPushLayer(s32 l);
void iosDlPopLayer(void);
void glBegin(s32 m);
void glEnd(void);
void glBlendFunc(s32 s, s32 d);
void glZOffset(float z);
void glEnable(s32 c);
void glVertex4fv(float *v);
typedef struct { s32 pad0; s32 mode; s32 n; float *v; } DbgPrim;
typedef struct { s32 pad0; s32 count; DbgPrim *prims; } DbgShape;
extern DbgShape *D_400289CC;

typedef struct { float x, y, z, w; } V4 __attribute__((aligned(8)));
typedef union { u64 d; u32 w[2]; float f[2]; u8 b[8]; } PW;
extern float D_4001E088;
extern float D_4001E08C;
extern float D_4001E090;
extern float D_4001E094;
extern V4 D_4001EBA0;
extern float UnitMatrix[];
PW *iosAllocPacketPtrPath1(s32 size);
void iosDlChainTailCurrent(void *p);
void glDisable(s32 c);
void glColor4f(float r, float g, float b, float a);
void triangleDispAttribute();

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0006_func_40017C10", func_40017C10);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0006_func_40017C10", func_40017F00);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0006_func_40017C10", triangleDispSetup);

void triangleDispAttribute(float *a, float *b) {
    PW *p;
    if (D_4001E060 != 0) {
        p = iosAllocPacketPtrPath1(0x20);
        p[0].d = 0x60000001;
        p[1].w[1] = 0x6E028000;
        p[1].w[0] = 0;
        p[2].b[0] = a[0];
        p[2].b[1] = a[1];
        p[2].b[2] = a[2];
        p[2].b[3] = a[3];
        p[2].b[4] = b[0];
        p[2].b[5] = b[1];
        p[2].b[6] = b[2];
        p[2].b[7] = b[3];
        p[3].w[1] = 0;
        p[3].w[0] = 0x14000002;
        iosDlPushLayer(0x18);
        iosDlChainTailCurrent(p);
        iosDlPopLayer();
    }
}

void DebugDispTriangleVectorPointerArray(float r, float g, float b, float a, float **vp, s32 force) {
    float v[4];
    V4 col;
    float *c;
    float *e;
    float *f;
    PW *p;
    if (D_4001E060 != 0) {
        if (force != 0) {
            if (r != D_4001E088 || g != D_4001E08C || b != D_4001E090 || a != D_4001E094) {
                v[0] = r * 255.0f;
                v[1] = g * 255.0f;
                v[2] = b * 255.0f;
                v[3] = a * 128.0f;
                col = D_4001EBA0;
                triangleDispAttribute(v, &col);
                D_4001E088 = r;
                D_4001E08C = g;
                D_4001E090 = b;
                D_4001E094 = a;
            }
            e = vp[0];
            f = vp[1];
            c = vp[2];
            if (D_4001E060 != 0) {
                p = iosAllocPacketPtrPath1(0x40);
                p[0].d = 0x60000003;
                p[1].w[1] = 0x68038000;
                p[1].w[0] = 0;
                p[2].f[0] = e[0];
                p[2].f[1] = e[1];
                p[3].f[0] = e[2];
                p[3].f[1] = f[0];
                p[4].f[0] = f[1];
                p[4].f[1] = f[2];
                p[5].f[0] = c[0];
                p[5].f[1] = c[1];
                p[6].f[0] = c[2];
                p[6].w[1] = 0x17000000;
                p[7].w[0] = 0;
                p[7].w[1] = 0;
                iosDlPushLayer(0x18);
                iosDlChainTailCurrent(p);
                iosDlPopLayer();
            }
        } else {
            glLoadMatrixf(UnitMatrix);
            glEnable(3);
            iosDlPushLayer(0x18);
            glBegin(2);
            glBlendFunc(5, 6);
            glZOffset(1.08f);
            glEnd();
            glBegin(8);
            glBlendFunc(5, 1);
            glEnd();
            glColor4f(r, g, b, a);
            glEnable(7);
            glDisable(8);
            glBegin(5);
            glVertex4fv(vp[0]);
            glVertex4fv(vp[1]);
            glVertex4fv(vp[2]);
            glEnd();
            glBegin(8);
            glZOffset(1.0f);
            glEnable(8);
            glBlendFunc(5, 6);
            glEnd();
            iosDlPopLayer();
        }
    }
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0006_func_40017C10", DebugDispArc);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0006_func_40017C10", DebugDispRadiusIndicatorNoLayerVU1);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0006_func_40017C10", DebugDispRadiusIndicatorForce);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0006_func_40017C10", DebugDispTriangularPyramid);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0006_func_40017C10", DebugDispTriangularPyramidNotBlend);

void DebugDispCylinder(float *m) {
    DbgShape *s;
    s32 i;
    s32 j;
    if (D_4001E060 == 0) {
        return;
    }
    iosSetCurrentMatrix();
    iosTransCurrentMatrix(D_4001EC00);
    iosGetCurrentMatrix(m);
    glLoadMatrixf(m);
    glEnable(3);
    iosDlPushLayer(0x18);
    glBegin(2);
    glBlendFunc(5, 6);
    glZOffset(1.08f);
    glEnd();
    s = D_400289CC;
    if (D_4001E060 != 0 && (i = 0) < s->count) {
        do {
            glBegin(s->prims[i].mode);
            for (j = 0; j < s->prims[i].n; j++) {
                glVertex4fv(s->prims[i].v + j * 4);
            }
            i++;
            glEnd();
        } while (i < s->count);
    }
    glBegin(8);
    glZOffset(1.0f);
    glEnable(8);
    glBlendFunc(5, 6);
    glEnd();
    iosDlPopLayer();
    glEnable(3);
}

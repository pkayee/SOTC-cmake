#include "common.h"

extern s32 D_4001E060;
void glLoadMatrixf();
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
extern DbgShape *D_400289DC;

extern int func_40017C10();

extern DbgShape *D_400289D0;

extern float UnitMatrix[];
void glDisable(s32 c);
void glColor4f(float r, float g, float b, float a);

void DebugDispRadiusIndicatorForce();

void DebugDispRadiusIndicatorNoLayerVU1();

extern DbgShape *D_400289C0[];

typedef union { u64 d; u32 w[2]; float f[2]; } PW;
PW *iosAllocPacketPtrPath1(s32 size);
void iosDlChainTailCurrent(void *p);

typedef struct { float x, y, z, w; } V4 __attribute__((aligned(8)));
extern float D_4001E088;
extern float D_4001E08C;
extern float D_4001E090;
extern float D_4001E094;
extern V4 D_4001EBA0;
void triangleDispAttribute();

void func_40016CD8(s32 a, s32 b, s32 c, float w);

void trianglePolyColor(float r, float g, float b, float a, s32 force) {
    float v[4];
    V4 col;
    if (force != 0 || r != D_4001E088 || g != D_4001E08C || b != D_4001E090 || a != D_4001E094) {
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
}

void triangleDisp(float *a, float *b, float *c) {
    PW *p;
    if (D_4001E060 != 0) {
        p = iosAllocPacketPtrPath1(0x40);
        p[0].d = 0x60000003;
        p[1].w[1] = 0x68038000;
        p[1].w[0] = 0;
        p[2].f[0] = a[0];
        p[2].f[1] = a[1];
        p[3].f[0] = a[2];
        p[3].f[1] = b[0];
        p[4].f[0] = b[1];
        p[4].f[1] = b[2];
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
}

void DebugDispRadiusIndicator(void) {
    if (D_4001E060 != 0) {
        DebugDispRadiusIndicatorForce();
    }
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispRadiusIndicatorNoLayer);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispTriangle);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispVectorTriangle);

/* DBGMGR c0009: wide line draw, float is the FIRST param (f12 stays w, ints a0..a2) while the callee prototype keeps w last (arg schedule); ev_85315f23c5e6ec4e0f761112955f943aea828d9efd02b59a0cd611bb1ba00b10 */
void DebugDispWideLineHalf(float w, s32 a, s32 b, s32 c) {
    if (D_4001E060 != 0) {
        iosDlPushLayer(0x18);
        glBegin(2);
        glBlendFunc(5, 6);
        glZOffset(1.08f);
        glEnd();
        glEnable(3);
        glBegin(8);
        glBlendFunc(5, 6);
        glEnd();
        func_40016CD8(a, b, c, w);
        glBegin(8);
        glZOffset(1.0f);
        glEnable(8);
        glBlendFunc(5, 6);
        glEnd();
        iosDlPopLayer();
    }
}

/* DBGMGR c0009: wide line draw, float is the FIRST param (f12 stays w, ints a0..a2) while the callee prototype keeps w last (arg schedule); ev_85315f23c5e6ec4e0f761112955f943aea828d9efd02b59a0cd611bb1ba00b10 */
void DebugDispWideLineNotBlend(float w, s32 a, s32 b, s32 c) {
    if (D_4001E060 != 0) {
        iosDlPushLayer(0x18);
        glBegin(2);
        glBlendFunc(5, 6);
        glZOffset(1.08f);
        glEnd();
        glDisable(3);
        func_40016CD8(a, b, c, w);
        glBegin(8);
        glZOffset(1.0f);
        glEnable(8);
        glBlendFunc(5, 6);
        glEnd();
        iosDlPopLayer();
    }
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispArrowNoLayer);

void DebugDispBox(void) {
    DbgShape *s;
    s32 i;
    s32 j;
    if (D_4001E060 == 0) {
        return;
    }
    glLoadMatrixf();
    glEnable(3);
    iosDlPushLayer(0x18);
    glBegin(2);
    glBlendFunc(5, 6);
    glZOffset(1.08f);
    glEnd();
    s = D_400289D0;
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

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispDocileArrow);

void DebugDispSelectDrawType(void *m, s32 idx) {
    DbgShape *s;
    s32 i;
    s32 j;
    if (D_4001E060 != 0) {
        iosDlPushLayer(0x18);
        glBegin(2);
        glBlendFunc(5, 6);
        glZOffset(1.08f);
        glEnd();
        glLoadMatrixf(m);
        glEnable(3);
        s = D_400289C0[idx];
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
    }
}

void DebugDispLine(float *p0, float *p1, float *col) {
    if (D_4001E060 != 0) {
        glLoadMatrixf(UnitMatrix);
        iosDlPushLayer(0x18);
        glBegin(2);
        glBlendFunc(5, 6);
        glZOffset(1.08f);
        glEnd();
        glColor4f(col[0], col[1], col[2], col[3]);
        glEnable(7);
        glDisable(8);
        glBegin(1);
        glVertex4fv(p0);
        glVertex4fv(p1);
        glEnd();
        glBegin(8);
        glZOffset(1.0f);
        glEnable(8);
        glBlendFunc(5, 6);
        glEnd();
        iosDlPopLayer();
    }
}

void DebugDispSmoothLine(float *p0, float *p1, float *col0, float *col1) {
    if (D_4001E060 != 0) {
        glLoadMatrixf(UnitMatrix);
        iosDlPushLayer(0x18);
        glBegin(2);
        glBlendFunc(5, 6);
        glZOffset(1.08f);
        glEnd();
        glColor4f(col0[0], col0[1], col0[2], col0[3]);
        glEnable(7);
        glDisable(8);
        glBegin(1);
        glVertex4fv(p0);
        glColor4f(col1[0], col1[1], col1[2], col1[3]);
        glVertex4fv(p1);
        glEnd();
        glBegin(8);
        glZOffset(1.0f);
        glEnable(8);
        glBlendFunc(5, 6);
        glEnd();
        iosDlPopLayer();
    }
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispOctagon);

void DebugDetailsDispBox(void) {
    DbgShape *s;
    s32 i;
    s32 j;
    if (D_4001E060 == 0) {
        return;
    }
    glLoadMatrixf();
    glEnable(3);
    iosDlPushLayer(0x18);
    glBegin(2);
    glBlendFunc(5, 6);
    glZOffset(1.08f);
    glEnd();
    s = D_400289DC;
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

void func_40019C18(void *arg0, void *arg1, s32 arg2);

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispGeometryPointer);
void DebugDispGeometryPointer(void *arg0, void *arg1)
{
    func_40019C18(arg0, arg1, 0);
}

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispGeometryPointerForce);
void DebugDispGeometryPointerForce(void *arg0, void *arg1)
{
    func_40019C18(arg0, arg1, 1);
}

void DebugDispArrowHalfVU1(int a, int b, int c) {
    func_40017C10(a, b, c, 1, 1);
}

extern int func_40017C10();

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispArrowHalfNoFrameVU1);
int DebugDispArrowHalfNoFrameVU1(int a, int b, int c)
{
    return func_40017C10(a, b, c, 0, 1);
}

void DebugDispArrowNotBlendVU1(int a, int b, int c) {
    func_40017C10(a, b, c, 1, 0);
}

void DebugDispArrowNotBlendNoFrameVU1(int a, int b, int c) {
    func_40017C10(a, b, c, 1, 0);
}

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispWideLineHalfVU1);

extern int func_40017F00();

int DebugDispWideLineHalfVU1(int a, int b, int c)
{
    return func_40017F00(a, b, c, 1);
}

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispWideLineNotBlendVU1);
int DebugDispWideLineNotBlendVU1(int a, int b, int c)
{
    return func_40017F00(a, b, c, 0);
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugSetTurnFront);

void DebugDispRadiusIndicatorVU1(void) {
    if (D_4001E060 != 0) {
        DebugDispRadiusIndicatorNoLayerVU1();
    }
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispTriangularPyramidHalfVU1);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0009_trianglePolyColor", DebugDispTriangularPyramidNotBlendVU1);

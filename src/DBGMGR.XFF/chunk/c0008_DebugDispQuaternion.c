#include "common.h"

extern s32 D_4001E060;

typedef struct GluPrim { void *pool; s32 mode; s32 n; void *v; } GluPrim;
typedef struct GluPrimObj { void *pool; s32 count; GluPrim *prims; } GluPrimObj;
void glLoadMatrixf();
void glBegin(s32 m);
void glEnd(void);
void glBlendFunc(s32 s, s32 d);
void glEnable(s32 c);
void glDisable(s32 c);
void glColor4fv(float *c);
void glVertex4fv(float *v);
typedef struct Pts40 { float f[40]; } Pts40 __attribute__((aligned(8)));
extern Pts40 D_4001E970;
void iosUnitCurrentMatrix(void);
void iosTransCurrentMatrix(void *v);
void iosRotCurrentMatrixX(float a);
void iosRotCurrentMatrixY(float a);
void iosRotCurrentMatrixZ(float a);
void iosScaleCurrentMatrix(float x, float y, float z);
void iosGetCurrentMatrix(void *m);
void glDrawFan(float *pts, s32 n, float *m, float *col, s32 solid);

static inline void GluDrawObjectInl(GluPrimObj *o)
{
    s32 i;
    s32 j;

    if (D_4001E060 != 0) {
        for (i = 0; i < o->count; i++) {
            glBegin(o->prims[i].mode);
            for (j = 0; j < o->prims[i].n; j++) {
                glVertex4fv((float *)o->prims[i].v + j * 4);
            }
            glEnd();
        }
    }
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", DebugDispQuaternion);

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", GetGlDebugSw);
extern s32 D_4001E060;

s32 *GetGlDebugSw(void)
{
    return &D_4001E060;
}

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", gluNewQuadric);
u64 gluNewQuadric()
{
    return 0;
}

void gluDeleteQuadric(void) {
}

//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", gluCylinder);
void _gluCylinder(u64 a, u64 b);

void gluCylinder(u64 a, u64 b, u64 c)
{
    _gluCylinder(b, c);
}

extern void *iosReallocAlign(void *ptn, void *oldUser, s32 size, s32 align);
typedef union { f32 f[4]; u128 q; } GluV4;
typedef struct { void *pool; s32 b; s32 n; GluV4 *v; } GluObj;

void iosgluAddVertex4fv(GluObj *o, GluV4 *p)
{
    o->v = iosReallocAlign(o->pool, o->v, o->n * 16 + 16, 16);
    o->v[o->n].q = p->q;
    o->n++;
}

void iosgluAddVertex3f(f32 x, f32 y, f32 z, GluObj *o)
{
    GluV4 t;

    t.f[0] = x; t.f[1] = y; t.f[2] = z; t.f[3] = 1.0f;
    o->v = iosReallocAlign(o->pool, o->v, o->n * 16 + 16, 16);
    o->v[o->n].q = t.q;
    o->n++;
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", iosgluAddPrim);

typedef struct IosgluDefaultObj {
    s32 a;
    s32 b;
    s32 c;
} IosgluDefaultObj;

extern IosgluDefaultObj D_4001E078;
extern void *iosMallocAlign(s32, s32, s32);

IosgluDefaultObj *iosgluCreateObject(s32 param_1)
{
    IosgluDefaultObj *p;

    p = iosMallocAlign(param_1, 0xc, 4);
    *p = D_4001E078;
    p->a = param_1;
    return p;
}
//INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", iosgluDeleteObject);
typedef struct IosgluEntry {
    s32 a;
    s32 b;
    s32 c;
    void *ptr;
} IosgluEntry;

typedef struct IosgluObj {
    s32 pad0;
    s32 count;
    IosgluEntry *entries;
} IosgluObj;

extern void iosFree(void *ptr);

void iosgluDeleteObject(IosgluObj *obj)
{
    s32 i;

    for (i = 0; i < obj->count; i++) {
        iosFree(obj->entries[i].ptr);
    }
    iosFree(obj->entries);
    iosFree(obj);
}

/* iosgluDrawObject: for each prim glBegin(mode); glVertex4fv per vertex; glEnd. ev_e5b5655a368a6dabe5767b8787f89b649c4a274c770fa85ecb206c2bf4ef5226 */
void iosgluDrawObject(GluPrimObj *o)
{
    s32 i;
    s32 j;

    if (D_4001E060 != 0) {
        for (i = 0; i < o->count; i++) {
            glBegin(o->prims[i].mode);
            for (j = 0; j < o->prims[i].n; j++) {
                glVertex4fv((float *)o->prims[i].v + j * 4);
            }
            glEnd();
        }
    }
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", iosgluAddLineCircleObject);

/* glDrawLineStrip(verts, n, mat, col, solid): ev_e5b5655a368a6dabe5767b8787f89b649c4a274c770fa85ecb206c2bf4ef5226 */
void glDrawLineStrip(float *v, s32 n, float *mat, float *col, s32 solid)
{
    float *p;
    s32 k;

    if (D_4001E060 != 0) {
        glLoadMatrixf(mat);
        glDisable(9);
        glDisable(0);
        glEnable(3);
        glEnable(7);
        if (solid != 0) {
            glEnable(1);
        } else {
            glDisable(1);
        }
        glBegin(8);
        glBlendFunc(5, 6);
        glEnd();
        glBegin(2);
        glColor4fv(col);
        if (n > 0) {
            p = v;
            k = n;
            do {
                k--;
                glVertex4fv(p);
                p += 4;
            } while (k != 0);
        }
        glEnd();
        glDisable(3);
        glDisable(7);
        glEnable(1);
    }
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", glDrawLineCircle);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", glDrawNull);

/* glDrawLight(base, spin, pos, col, solid, n): n rotating fans. glDrawFan prototype is a guess from the call site (a0,a1=10,a2,a3,t0). ev_e5b5655a368a6dabe5767b8787f89b649c4a274c770fa85ecb206c2bf4ef5226 */
void glDrawLight(float base, float spin, void *pos, float *col, s32 solid, s32 n)
{
    Pts40 pts;
    float m[16];
    s32 i;
    float s;
    float u;

    pts = D_4001E970;
    if (D_4001E060 != 0) {
        for (i = 0; i < n; i++) {
            u = (float)(i * 2);
            iosUnitCurrentMatrix();
            iosTransCurrentMatrix(pos);
            s = (base + u) * 0.02f;
            iosRotCurrentMatrixZ(spin * ((float)(i * 13) + 11.7f));
            iosRotCurrentMatrixY(spin * ((float)(i * 3) + 32.3f));
            iosRotCurrentMatrixX(spin * ((float)(i * 7) + 23.5f));
            iosScaleCurrentMatrix(s, s, s);
            iosGetCurrentMatrix(m);
            glDrawFan(pts.f, 10, m, col, solid);
        }
    }
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", glDrawLineArrow);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", glDrawLineArrowPosition);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", glDrawBox);

/* glDrawGLUObj(obj, mat, col, solid): inlined iosgluDrawObject. ev_e5b5655a368a6dabe5767b8787f89b649c4a274c770fa85ecb206c2bf4ef5226 */
void glDrawGLUObj(GluPrimObj *obj, float *mat, float *col, s32 solid)
{
    if (D_4001E060 != 0) {
        glDisable(9);
        glDisable(0);
        glEnable(3);
        glEnable(7);
        if (solid != 0) {
            glEnable(1);
        } else {
            glDisable(1);
        }
        glBegin(8);
        glBlendFunc(5, 6);
        glEnd();
        glLoadMatrixf(mat);
        glColor4fv(col);
        GluDrawObjectInl(obj);
        glDisable(3);
        glDisable(7);
        glEnable(1);
    }
}

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", glDrawSpaceAxisQuaternion);

INCLUDE_ASM("asm/DBGMGR.XFF/nonmatchings/chunk/c0008_DebugDispQuaternion", glDrawViewFrustum);

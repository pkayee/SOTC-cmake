#include "common.h"

typedef union {
    s128 q;
    f32 f[4];
    s32 w[4];
} Q4;
extern void *memset(void *, s32, u32);
extern s32 func_400B2058(void *, void *, void *, void *, void *);

extern u8 *GetLayoutClass();
typedef struct {
    u8 pad0[8];
    u8 flag8;
    u8 pad9[0xB];
    u8 *tbl14;
    u8 pad18[0x3C];
    s32 *ref54;
    u8 pad58[0x38];
} ColChunk;
typedef struct {
    u8 pad0[4];
    s32 mode4;
    ColChunk *chunks;
    u8 pad0c[0xC];
    u8 *ents18;
    u8 pad1c[0x4];
    u8 *obj20;
    u8 pad24[0x10];
    u8 *attr34;
} ColSet;

typedef union {
    s64 d[10];
    f32 f[20];
} CPoint;

void triangleDispSetup(void);
void trianglePolyColor(s32, float, float, float, float);
void func_400B40C0(void *, s32, float, float, float, float, float, float, s32, float);

void iosDlPushLayer(s32);
void iosDlPopLayer(void);
void func_400B38A8(void *, float, float, float, float, float, float, float, float, float, float, float);

s32 CollisionPlaneJudgeCallbackParticle(s32 *ref)
{
    u32 w;
    u32 chunk;
    u32 idx;
    ColSet *cs0;
    ColSet *cs;
    ColChunk *c;
    u32 id;
    u64 attr;

    cs0 = *(ColSet **)(*(u8 **)(GetLayoutClass(ref[0]) + 0x184) + 0x20);
    w = ref[1];
    chunk = (w >> 24) & 0x7F;
    id = w & 0xFFFFFF;
    cs = *(ColSet **)(*(u8 **)(GetLayoutClass(ref[0]) + 0x184) + 0x20);
    if (ref[1] < 0) {
        c = &cs->chunks[chunk];
        if (c->flag8 != 0) {
            idx = *(u16 *)(c->tbl14 + id * 20);
        } else {
            idx = *(u32 *)(c->tbl14 + id * 52 + 0x30);
        }
    } else {
        idx = *(u32 *)(*(s32 *)(cs->chunks[chunk].ref54 + id) * 64 + cs->ents18 + 0x3C);
    }
    attr = *(u64 *)(cs0->attr34 + (idx << 4));
    return (attr & (0xF800UL << 20)) != (0xE000UL << 18);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", CollisionPlaneJudgeCallbackArrow);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", CollisionPlaneJudgeCallbackCameraMove);

u64 CollisionPlaneJudgeCallbackCameraVisibility(s32 *ref)
{
    u32 w;
    u32 chunk;
    u32 idx;
    ColSet *cs0;
    ColSet *cs;
    ColChunk *c;
    u32 id;
    u64 attr;
    u64 flags;
    u64 material;
    u64 mode;

    cs0 = *(ColSet **)(*(u8 **)(GetLayoutClass(ref[0]) + 0x184) + 0x20);
    w = ref[1];
    chunk = (w >> 24) & 0x7F;
    id = w & 0xFFFFFF;
    cs = *(ColSet **)(*(u8 **)(GetLayoutClass(ref[0]) + 0x184) + 0x20);
    if (ref[1] < 0) {
        c = &cs->chunks[chunk];
        if (c->flag8 != 0) {
            idx = *(u16 *)(c->tbl14 + id * 20);
        } else {
            idx = *(u32 *)(c->tbl14 + id * 52 + 0x30);
        }
    } else {
        idx = *(u32 *)(*(s32 *)(cs->chunks[chunk].ref54 + id) * 64 + cs->ents18 + 0x3C);
    }
    attr = *(u64 *)(cs0->attr34 + (idx << 4));
    material = attr & 0x7C000000UL;
    flags = attr & (0xF800UL << 20);
    mode = attr & (0xF000UL << 30);

    if (mode == (0x8000UL << 27)) {
        return 0;
    }
    if (flags == (0xA000UL << 18)) {
        return 1;
    }
    if (material == 0x30000000UL || material == 0x34000000UL || material == 0x64000000UL ||
        material == 0x68000000UL || material == 0x6C000000UL) {
        goto zero;
    }
    if (material == 0x24000000UL || flags == (0xC000UL << 18) || flags == (0xA000UL << 19) ||
        flags == (0x8000UL << 18) || flags == (0xB800UL << 20) || flags == (0x8000UL << 16) ||
        flags == (0xA000UL << 18)) {
        flags = 0;
        goto end;
    }
    if (mode != (0x8000UL << 28)) {
        flags = 1;
        goto end;
    }
zero:
    flags = 0;
end:
    return flags;
}

s32 CollisionPlaneJudgeCallbackCameraLeave(s32 *ref)
{
    u32 w;
    u32 chunk;
    u32 idx;
    ColSet *cs0;
    ColSet *cs;
    ColChunk *c;
    u32 id;
    u64 attr;

    cs0 = *(ColSet **)(*(u8 **)(GetLayoutClass(ref[0]) + 0x184) + 0x20);
    w = ref[1];
    chunk = (w >> 24) & 0x7F;
    id = w & 0xFFFFFF;
    cs = *(ColSet **)(*(u8 **)(GetLayoutClass(ref[0]) + 0x184) + 0x20);
    if (ref[1] < 0) {
        c = &cs->chunks[chunk];
        if (c->flag8 != 0) {
            idx = *(u16 *)(c->tbl14 + id * 20);
        } else {
            idx = *(u32 *)(c->tbl14 + id * 52 + 0x30);
        }
    } else {
        idx = *(u32 *)(*(s32 *)(cs->chunks[chunk].ref54 + id) * 64 + cs->ents18 + 0x3C);
    }
    attr = *(u64 *)(cs0->attr34 + (idx << 4));
    return (attr & (0xF000UL << 30)) == (0x8000UL << 28);
}

s32 ClipEdgeLinkDBFinder(u8 *self, void *b, Q4 *c, s32 *list, f32 f)
{
    s32 n;
    s32 i;
    u8 *e;
    u8 *p;
    Q4 cur;
    Q4 buf;

    n = 0;
    i = list[8];
    e = (u8 *)list[9];
    if (i != 0) {
        memset(&buf, 0, 0x10);
        buf.f[1] = f;
        cur.q = c->q;
        if (i > 0) {
            do {
                p = e;
                e += 0x14;
                if (func_400B2058(self, b, &cur, p, &buf) != 0) {
                    cur.q = ((Q4 *)self)->q;
                    n++;
                }
            } while (--i != 0);
        }
    }
    return n != 0;
}

void ConstructorCollisionPoint(CPoint *dst)
{
    CPoint local;

    memset(&local, 0, 0x50);
    local.f[3] = 1.0f;
    local.f[7] = 1.0f;
    local.f[19] = 1.0f;
    *dst = local;
}

/* NEARMISS-STUB ConstructorCollisionDynamics */
#if 0 /* NEARMISS 85.28% cat=cse-hoist sub=- | dead float 1.0 stores to memset local dropped; const hoist and store order differ | attempts=1 */
void ConstructorCollisionDynamics(s64 *param_1)
{
    s64 local[6];
    float *fl;
    s64 a;
    s64 b;
    s64 c;
    s64 d;
    s64 e;
    s64 f;

    memset(local, 0, 0x30);
    fl = (float *)local;
    a = local[0];
    b = local[1];
    c = local[2];
    d = local[3];
    e = local[4];
    f = local[5];
    fl[5] = 1.0f;
    param_1[0] = a;
    param_1[1] = b;
    param_1[2] = c;
    param_1[3] = d;
    param_1[4] = e;
    param_1[5] = f;
    fl[3] = 1.0f;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", ConstructorCollisionDynamics);

void CopyGeometryPointer();

void CopyCollisionPoint(char *dst, char *src)
{
    CopyGeometryPointer(dst, src);
    *(s128 *)(dst + 0x40) = *(s128 *)(src + 0x40);
}

void CopyCollisionDynamics(char *dst, char *src)
{
    s32 *s;
    s32 *d;

    s = (s32 *)(src + 0x20);
    d = (s32 *)(dst + 0x20);
    ((Q4 *)dst)->q = ((Q4 *)src)->q;
    ((Q4 *)(dst + 0x10))->q = ((Q4 *)(src + 0x10))->q;
    d[0] = s[0];
    d[1] = s[1];
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0140_CollisionPlaneJudgeCallbackParticle", FilterCopyCollisionDynamics);

typedef union
{
    s128 q;
    float f[4];
    s32 i[4];
} Vec4;

float *GetGeometryPointerSurfacePlane(char *);

void ConvertFromCollisionPointToDynamics(char *out, char *point)
{
    Vec4 *plane;
    s32 *tail;

    ((Vec4 *)out)->q = ((Vec4 *)(point + 0x40))->q;
    plane = (Vec4 *)GetGeometryPointerSurfacePlane(point);
    tail = (s32 *)(out + 0x20);
    ((Vec4 *)(out + 0x10))->q = plane->q;

    tail[0] = *(s32 *)point;
    tail[1] = *(s32 *)(point + 4);
}

extern s32 D_4012B328;

void ResetCollisionDebug(void)
{
    D_4012B328 = 0;
}

void DebugDispCollisionDB(void *db, s32 a)
{
    triangleDispSetup();
    trianglePolyColor(1, -1.0f, -1.0f, -1.0f, -1.0f);
    func_400B40C0(db, a, 0.6f, 0.8f, 1.0f, 1.0f, 0.7f, 0.5f, -1, 0.2f);
}

void triangleDispSetup(void);
void trianglePolyColor(s32, float, float, float, float);
void func_400B40C0(void *, s32, float, float, float, float, float, float, s32, float);

void DebugDispCollisionDBShine(void *db, float f)
{
    triangleDispSetup();
    trianglePolyColor(1, -1.0f, -1.0f, -1.0f, -1.0f);
    func_400B40C0(db, 0, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, -1, f);
}

void DebugDispCollisionFinderKeep(s32 *list, float f)
{
    s32 n;
    s32 i;

    n = list[0];
    if (list[1] < n) {
        n = list[1];
    }
    iosDlPushLayer(0x18);
    triangleDispSetup();
    trianglePolyColor(1, -1.0f, -1.0f, -1.0f, -1.0f);
    for (i = 0; i < n; i++) {
        s32 *e = (s32 *)(i * 8 + list[2]);
        if (*e != 0) {
            func_400B38A8(e, 0.5f, 0.7f, 0.5f, 0.5f, 0.7f, 0.5f, 0.5f, 0.7f, 0.7f, 0.1f, f);
        }
    }
    iosDlPopLayer();
}

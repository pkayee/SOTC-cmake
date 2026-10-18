#include "common.h"

extern s32 ClipCollisionDB();

typedef union { s128 q; s32 w[4]; } Q4;

extern s32 func_400AB528();
extern s32 func_400BC638(void *, void *, void *, void *, void *, f32);
typedef struct {
    u8 pad[0x40];
    Q4 v;
} KeepOut;

extern s32 func_400BC558(void *, void *, void *, void *, void *, f32);

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

extern s32 func_400B09E8(void *, void *, void *, void *, void *, f32, void *);

static inline s32 clipTransFar4D(u8 *self, Q4 *cur, void *d, s32 *e)
{
    Q4 tmp;

    func_400AB528(&tmp, e, cur, 1);
    return ClipCollisionDB(self, &tmp, d, e);
}

static inline s32 clipTrans4D(u8 *self, s32 m, Q4 *cur, s32 *e)
{
    Q4 tmp;

    func_400AB528(&tmp, e, m, 1);
    return ClipCollisionDB(self, &tmp, cur, e);
}

void GetCollisionDBAttribute(Q4 *out, s32 *ref)
{
    u32 w;
    u32 chunk;
    u32 idx;
    ColSet *cs0;
    ColSet *cs;
    ColChunk *c;
    u32 id;

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
    out->q = ((Q4 *)(cs0->attr34 + (idx << 4)))->q;
}

u8 *GetCollisionDBAttributeAdr(s32 *ref)
{
    u32 w;
    u32 chunk;
    u32 idx;
    ColSet *cs0;
    ColSet *cs;
    ColChunk *c;
    u32 id;

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
    return cs0->attr34 + idx * 16;
}

s32 ClipCollisionDBDoubleSide(s32 a, s32 b, s32 c, s32 d)
{
    s32 r;

    r = 0;
    if (ClipCollisionDB(a, b, c, d) || ClipCollisionDB(a, c, b, d)) {
        r = 1;
    }
    return r;
}

s32 *ClipCollisionFinderCallBack(u8 *self, void *b, Q4 *c, s32 *list, s32 (*cb)(), s32 arg)
{
    s32 n;
    s32 i;
    s32 *e;
    s32 *best;
    Q4 cur;

    n = list[0];
    if (list[1] < n) {
        n = list[1];
    }
    if (n != 0) {
        cur.q = c->q;
        best = 0;
        e = (s32 *)list[2];
        i = n;
        while (i--) {
            if (e[0] != 0 && cb(e, arg) && ClipCollisionDB(self, b, &cur, e)) {
                cur.q = ((Q4 *)(self + 0x40))->q;
                best = e;
            }
            e += 2;
        }
        if (best != 0) {
            *(s32 *)self = best[0];
            *(s32 *)(self + 4) = best[1];
        }
        return best;
    }
    return 0;
}

s32 *ClipCollisionFinder(u8 *self, void *b, Q4 *c, s32 *list)
{
    s32 n;
    s32 i;
    s32 *e;
    s32 *best;
    Q4 cur;

    n = list[0];
    if (list[1] < n) {
        n = list[1];
    }
    if (n != 0) {
        cur.q = c->q;
        best = 0;
        e = (s32 *)list[2];
        i = n;
        while (i--) {
            if (e[0] != 0 && ClipCollisionDB(self, b, &cur, e)) {
                cur.q = ((Q4 *)(self + 0x40))->q;
                best = e;
            }
            e += 2;
        }
        if (best != 0) {
            *(s32 *)self = best[0];
            *(s32 *)(self + 4) = best[1];
        }
        return best;
    }
    return 0;
}

s32 ClipCollisionFinder4D(u8 *self, s32 m, Q4 *c, s32 *list)
{
    s32 n;
    s32 i;
    s32 *e;
    s32 *best;
    Q4 cur;

    n = list[0];
    if (list[1] < n) {
        n = list[1];
    }
    e = (s32 *)list[2];
    if (n != 0) {
        cur.q = c->q;
        best = 0;
        i = n;
        while (i--) {
            if (e[0] != 0) {
                if (clipTrans4D(self, m, &cur, e)) {
                    cur.q = ((Q4 *)(self + 0x40))->q;
                    best = e;
                }
            }
            e += 2;
        }
        if (best != 0) {
            *(s32 *)self = best[0];
            *(s32 *)(self + 4) = best[1];
        }
        return 0;
    }
    return 0;
}

s32 ClipCollisionFinderWithKeep(u8 *self, void *b, Q4 *c, s32 *list, f32 f)
{
    s32 n;
    s32 hit;
    s32 *e;
    s32 *dst;
    Q4 v;
    KeepOut o;

    n = list[0];
    if (list[1] < n) {
        n = list[1];
    }
    if (n != 0) {
        e = (s32 *)list[2];
        ((Q4 *)self)->q = c->q;
        hit = 0;
        while (n--) {
            if (e[0] != 0 && func_400BC638(&o, &v, b, self, e, f)) {
                hit = 1;
                ((Q4 *)self)->q = o.v.q;
                ((Q4 *)(self + 0x10))->q = v.q;
                dst = (s32 *)(self + 0x20);
                dst[0] = e[0];
                dst[1] = e[1];
            }
            e += 2;
        }
        if (hit) {
            return 1;
        }
    }
    return 0;
}

s32 ClipCollisionFinderWithKeep4D(u8 *self, void *b, Q4 *c, s32 *list, f32 f)
{
    s32 n;
    s32 hit;
    s32 *e;
    s32 *dst;
    Q4 v;
    KeepOut o;

    n = list[0];
    if (list[1] < n) {
        n = list[1];
    }
    if (n != 0) {
        e = (s32 *)list[2];
        ((Q4 *)self)->q = c->q;
        hit = 0;
        while (n--) {
            if (e[0] != 0 && func_400BC558(&o, &v, b, self, e, f)) {
                hit = 1;
                ((Q4 *)self)->q = o.v.q;
                ((Q4 *)(self + 0x10))->q = v.q;
                dst = (s32 *)(self + 0x20);
                dst[0] = e[0];
                dst[1] = e[1];
            }
            e += 2;
        }
        if (hit) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", NippingCheckCollisionFindetWithKeep4D);

s32 ClipCollisionFinderWithKeep_VWallOnly(u8 *self, Q4 *c, Q4 *d, u8 *obj, f32 f)
{
    s32 hit;
    s32 n;
    s32 code;
    u8 *e;
    s32 *dst;
    Q4 cur;
    Q4 t;
    KeepOut o;

    hit = 0;
    ((Q4 *)self)->q = d->q;
    n = *(s32 *)(obj + 0x20);
    if (n != 0) {
        cur.q = c->q;
        e = *(u8 **)(obj + 0x24);
        while (n--) {
            code = func_400B09E8(&o, &t, &cur, self, e, f, obj);
            if (code != 0) {
                if ((u32)(code - 5) < 2) {
                    cur.q = o.v.q;
                }
                ((Q4 *)self)->q = o.v.q;
                ((Q4 *)(self + 0x10))->q = t.q;
                dst = (s32 *)(self + 0x20);
                dst[0] = *(s32 *)e;
                dst[1] = *(s32 *)(e + 4);
                hit = code;
            }
            e += 0x14;
        }
    }
    return hit;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", ClipCollisionFinderWithKeepSlopeLimit);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0143_GetCollisionDBAttribute", ClipCollisionFinderWithKeepSlopeLimitCB);

s32 ClipCollisionFinderFarPlane(u8 *self, Q4 *c, void *d, s32 *list)
{
    s32 n;
    s32 i;
    s32 cnt;
    s32 *e;
    s32 *best;
    Q4 cur;

    cnt = 0;
    n = list[0];
    if (list[1] < n) {
        n = list[1];
    }
    e = (s32 *)list[2];
    if (n != 0) {
        cur.q = c->q;
        best = 0;
        if (n > 0) {
            i = n;
            do {
                if (e[0] != 0 && ClipCollisionDB(self, &cur, d, e)) {
                    cur.q = ((Q4 *)(self + 0x40))->q;
                    cnt++;
                    best = e;
                }
                i--;
                e += 2;
            } while (i != 0);
        }
        if (best != 0) {
            *(s32 *)self = best[0];
            *(s32 *)(self + 4) = best[1];
        }
        return cnt != 0;
    }
    return 0;
}

s32 ClipCollisionFinderFarPlane4D(u8 *self, Q4 *c, void *d, s32 *list)
{
    s32 n;
    s32 i;
    s32 cnt;
    s32 *e;
    s32 *best;
    Q4 cur;

    cnt = 0;
    n = list[0];
    if (list[1] < n) {
        n = list[1];
    }
    e = (s32 *)list[2];
    if (n != 0) {
        cur.q = c->q;
        best = 0;
        if (n > 0) {
            i = n;
            do {
                if (e[0] != 0 && clipTransFar4D(self, &cur, d, e)) {
                    cur.q = ((Q4 *)(self + 0x40))->q;
                    cnt++;
                    best = e;
                }
                i--;
                e += 2;
            } while (i != 0);
        }
        if (best != 0) {
            *(s32 *)self = best[0];
            *(s32 *)(self + 4) = best[1];
        }
        return cnt != 0;
    }
    return 0;
}

s32 ClipCollisionFinderFarPlaneWithKeep(u8 *self, Q4 *c, void *d, s32 *list, f32 f)
{
    s32 n;
    s32 hit;
    s32 *e;
    s32 *dst;
    Q4 v;
    KeepOut o;

    hit = 0;
    n = list[0];
    if (list[1] < n) {
        n = list[1];
    }
    e = (s32 *)list[2];
    if (n != 0) {
        ((Q4 *)self)->q = c->q;
        while (n--) {
            if (e[0] != 0 && func_400BC638(&o, &v, self, d, e, f)) {
                hit = 1;
                ((Q4 *)self)->q = o.v.q;
                ((Q4 *)(self + 0x10))->q = v.q;
                dst = (s32 *)(self + 0x20);
                dst[0] = e[0];
                dst[1] = e[1];
            }
            e += 2;
        }
        if (hit) {
            return 1;
        }
    }
    return 0;
}

s32 ClipCollisionFinderFarPlaneWithKeep4D(u8 *self, Q4 *c, void *d, s32 *list, f32 f)
{
    s32 n;
    s32 hit;
    s32 *e;
    s32 *dst;
    Q4 v;
    KeepOut o;

    hit = 0;
    n = list[0];
    if (list[1] < n) {
        n = list[1];
    }
    e = (s32 *)list[2];
    if (n != 0) {
        ((Q4 *)self)->q = c->q;
        while (n--) {
            if (e[0] != 0 && func_400BC558(&o, &v, self, d, e, f)) {
                hit = 1;
                ((Q4 *)self)->q = o.v.q;
                ((Q4 *)(self + 0x10))->q = v.q;
                dst = (s32 *)(self + 0x20);
                dst[0] = e[0];
                dst[1] = e[1];
            }
            e += 2;
        }
        if (hit) {
            return 1;
        }
    }
    return 0;
}

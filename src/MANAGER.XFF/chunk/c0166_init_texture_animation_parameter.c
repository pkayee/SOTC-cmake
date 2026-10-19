#include "common.h"

typedef struct PartSeg { /* g_ainParticleSegment[50], stride 0x10 */
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} PartSeg;
extern PartSeg g_ainParticleSegment[50];
extern s32 D_401AD580[];
extern s32 D_4012B514;
extern s32 D_401AD590[];
extern s32 D_4012B4F0;
extern s32 DldSysUndefSymbol;

void func_400CBA98();
void iosUnitMatrix();
s32 sheetFileGetDataAdrs(s32);
s32 func_400D3F70(s32, s32);
s32 is_emitter_need_disp(u8 *, u8 *);
void func_400CCE58();
void disp_particle_emitter();
s32 func_400D27D8(u8 *, u8 *, u8 *);
u8 *malloc_from_src_partition(s32, s32, const char *, s32);
void func_400D2658();
extern const char D_40134168[];
s32 GetWaterSurfacePositionY(f32 *, f32 *, s32, f32, f32);

static inline u8 *dldRef(u32 *lp, s32 fld) {
    u8 *slot;
    u32 off = *lp & 0x3FFFF;

    slot = off ? *(u8 **)((u8 *)lp - off) : NULL;
    return (slot != NULL && slot != (u8 *)DldSysUndefSymbol) ? *(u8 **)(slot + fld) : NULL;
}

void init_texture_animation_parameter(u8 *p) {
    s32 w = *(s32 *)(p + 0x7C);
    s32 h = *(s32 *)(p + 0x80);
    s32 n = w * h;

    *(s32 *)(p + 0x120) = n;
    if (n < 2) {
        *(f32 *)(p + 0x124) = 1.0f;
        *(f32 *)(p + 0x128) = 1.0f;
        *(f32 *)(p + 0x12C) = 1.0f;
        *(f32 *)(p + 0x130) = 1.0f;
    } else {
        f32 fw = (f32)w;
        f32 fh = (f32)h;
        f32 fn = (f32)n;

        *(f32 *)(p + 0x128) = fw;
        *(f32 *)(p + 0x124) = fn;
        *(f32 *)(p + 0x12C) = 1.0f / fw;
        *(f32 *)(p + 0x130) = 1.0f / fh;
    }
}

s32 *get_particle_geodispobj_group(void) {
    return D_401AD580;
}

s32 *get_set_limit_gl_draw_particle_flag(void) {
    return &D_4012B514;
}

s32 create_particle_texture(u8 *a) {
    u8 *p = dldRef((u32 *)(a + 4), 0x10);

    return *(s32 *)(p + 0xC);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0166_init_texture_animation_parameter", func_400D1F30);

PartSeg *func_400D1FA8(void) {
    s32 i;

    for (i = 0; i < 50; i++) {
        if (g_ainParticleSegment[i].f4 == 0) {
            return &g_ainParticleSegment[i];
        }
    }
    return NULL;
}

void free_particle_segment() {
    func_400CBA98();
}

void load_npe_file_main(s32 sheet, s32 unused, s32 size) {
    u8 *d = (u8 *)sheetFileGetDataAdrs(sheet);

    *(s32 *)(d + 0xC) = func_400D3F70(sheet, size);
}

void load_npe_file_sub(s32 sheet, s32 unused, s32 size) {
    u8 *d = (u8 *)sheetFileGetDataAdrs(sheet);

    *(s32 *)(d + 0x1C) = func_400D3F70(sheet, size);
}

void unload_npe_file_main(void) {
}

void unload_npe_file_sub(void) {
}

s32 func_400D20B8(s32 a) {
    return a;
}

/* NEARMISS-STUB func_400D20C0 */
#if 0 /* NEARMISS 99.64% cat=regalloc sub=- | d2 r94: CALLEE-ARG-PROTO isysGroupForNext(node, 0) + real prototypes 97.59->99.64; left: params p1/p2 swapped in s4/s7 (target p1=s4, p2=s7); voids32/s64 param  | attempts=2 */
extern void GetGeometryPointerPosition(s32 *);
extern s32 *isysGroupForFirst(s32 *, s32);
extern s32 *isysGroupForNext(s32 *, s32);
extern void isysGroupForExit(s32, s32);
extern s32 *get_top_emitter_list_from_particle_geodisp(s32);
extern s32 *create_and_boot_particle_geodisp(u8 *, u8 *, u8 *, u8 *, u8 *);
extern void isysAddGroupWithLinkParam(s32 *, s32 *, s32, s32);
s32 func_400D2320(s32 *, s32 *, u8 *, u8 *, u8 *, u8 *, u8 *);

s32 func_400D20C0(u8 *p0, u8 *p1, u8 *p2, u8 *p3, u8 *p4) {
    s32 buf[4];
    s32 *node;
    s32 geo;
    s32 ret = 0;

    if (*(s32 *)(p0 + 0x2C) != 0) {
        geo = 0;
        GetGeometryPointerPosition(buf);
        node = isysGroupForFirst(D_401AD580, 0);
        while (node != NULL) {
            geo = *node;
            ret = func_400D2320(get_top_emitter_list_from_particle_geodisp(geo), buf, p0, p1, p2, p3, p4);
            if (ret != 0) {
                break;
            }
            node = isysGroupForNext(node, 0);
        }
        if (geo != 0) {
            isysGroupForExit(geo, 0);
        }
    }
    if (ret != 0) {
        return ret;
    }
    node = create_and_boot_particle_geodisp(p0, p1, p2, p3, p4);
    if (node != NULL) {
        isysAddGroupWithLinkParam(node, D_401AD580, 0, 0);
        ret = *get_top_emitter_list_from_particle_geodisp((s32)node);
    }
    return ret;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0166_init_texture_animation_parameter", func_400D20C0);

void func_400D2210(void) {
    iosUnitMatrix(D_401AD590);
    iosUnitMatrix(D_401AD590 + 0x10);
    D_401AD590[0x20] = 0;
    D_401AD590[0x21] = 0;
    D_401AD590[0x22] = 0;
    D_401AD590[0x23] = 0;
    D_401AD590[0x24] = 0;
}

/* NEARMISS-STUB func_400D2258 */
#if 0 /* NEARMISS 60.66% cat=regalloc sub=- | no cause recorded | attempts=1 */
extern s32 D_4012B50C;
extern s32 D_4012B510;

s32 func_400D2258(u8 *a0, u8 *a1) {
    s32 r = 0;
    s32 ok = 1;
    u8 *e = *(u8 **)(a1 + 0xD4) + *(s32 *)(a0 + 0x118) * 0x1BC;
    u32 k;

    if (D_4012B50C == 0) {
        return 0;
    }
    k = *(u32 *)(e + 0xC);
    if (k == 2) {
        ok = 0;
    } else if (k < 3) {
        if (k == 1 && *(s32 *)(e + 0x18C) == 0) {
            ok = 0;
        }
    } else if (k == 3) {
        ok = 0;
    }
    if (ok) {
        D_4012B510 += *(s32 *)(a0 + 0x124);
        if (D_4012B514 != 1 || D_4012B510 < 0x80) {
            r = 1;
        }
    } else {
        r = 1;
    }
    return r;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0166_init_texture_animation_parameter", func_400D2258);

/* NEARMISS-STUB func_400D2320 */
#if 0 /* NEARMISS 63.95% cat=vu0-mmi sub=- | no cause recorded | attempts=1 */
static inline u8 *allocListEntry(void) {
    return (u8 *)malloc_from_src_partition(get_fast_get_malloc_partition(), 0x1C0, &D_40134168, 1);
}

s32 func_400D2320(u8 *head, f32 *pos, u8 *obj, void *q3, void *q4, void *q5, void *q6) {
    u8 *node = *(u8 **)head;
    u8 *s0;
    u8 *s3 = NULL;
    u8 *p;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d2;
    f32 r;
    s32 key;

    if (node == NULL) {
        return 0;
    }
    if (*(s32 *)(obj + 0x2C) == 0) {
        return 0;
    }
    if (*(s32 *)(obj + 0x2C) != *(s32 *)(*(u8 **)node + 0x2C)) {
        return 0;
    }
    dx = pos[0] - *(f32 *)(node + 0x20);
    dy = pos[1] - *(f32 *)(node + 0x24);
    dz = pos[2] - *(f32 *)(node + 0x28);
    d2 = dx * dx + dy * dy;
    d2 = d2 + dz * dz;
    r = *(f32 *)(obj + 0x30);
    if (!(d2 <= r * r)) {
        return 0;
    }

    s0 = node;
    s3 = NULL;
    key = *(s32 *)(obj + 0x34);
    while (key >= *(s32 *)(*(u8 **)s0 + 0x34)) {
        s3 = s0;
        s0 = *(u8 **)(s0 + 0x1B0);
        if (s0 == NULL) {
            p = allocListEntry();
            if (p != NULL) {
                *(u8 **)p = obj;
                func_400D2658(p + 0x10, q3, q4, q5, q6, *(s32 *)(obj + 0x48));
                *(s32 *)(p + 0x1B0) = 0;
            }
            *(u8 **)(s3 + 0x1B0) = p;
            return (s32)p;
        }
    }
    p = allocListEntry();
    if (p == NULL) {
        return 0;
    }
    *(u8 **)p = obj;
    func_400D2658(p + 0x10, q3, q4, q5, q6, *(s32 *)(obj + 0x48));
    *(s32 *)(p + 0x1B0) = 0;
    if (s3 == NULL) {
        *(u8 **)head = p;
    } else {
        *(u8 **)(s3 + 0x1B0) = p;
    }
    *(u8 **)(p + 0x1B0) = s0;
    return (s32)p;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0166_init_texture_animation_parameter", func_400D2320);

u8 *func_400D24E8(s32 a0, u8 *a1, s32 a2, s32 a3, s32 t0, s32 t1) {
    u8 *p = malloc_from_src_partition(a0, 0x1C0, D_40134168, 1);

    if (p != NULL) {
        *(u8 **)p = a1;
        func_400D2658(p + 0x10, a2, a3, t0, t1, *(s32 *)(a1 + 0x48));
        *(s32 *)(p + 0x1B0) = 0;
    }
    return p;
}

/* NEARMISS-STUB func_400D2588 */
#if 0 /* NEARMISS 85.5% cat=branch-layout sub=movz-order | loop returning 1 if any emitter need_disp==1: target stores e->0x164 before the next-node lw and xors into v0; ours loads next first and xors into v1; 8 source  | attempts=1 */
s32 func_400D2588(u8 *n) {
    s32 r = 0;

    if (n != NULL) {
        do {
            u8 *e = n + 0x10;
            s32 v = is_emitter_need_disp(e, *(u8 **)(*(u8 **)n + 0x48));

            *(s32 *)(e + 0x164) = v;
            if (v == 1) {
                r = 1;
            }
            n = *(u8 **)(n + 0x1B0);
        } while (n != NULL);
    }
    return r;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0166_init_texture_animation_parameter", func_400D2588);

s32 func_400D25F8(u8 *n) {
    if (n != NULL) {
        do {
            u8 *v = *(u8 **)n;
            u8 *w = *(u8 **)(v + 0x48);

            if (func_400D27D8(n + 0x10, w, *(u8 **)(w + 0xD4)) == 1) {
                return 1;
            }
            n = *(u8 **)(n + 0x1B0);
        } while (n != NULL);
    }
    return 0;
}

/* NEARMISS-STUB func_400D2658 */
#if 0 /* NEARMISS 81.92% cat=regalloc sub=- | no cause recorded | attempts=1 */
void func_400D2658(u8 *a0, void *a1, void *a2, void *a3, void *a4, s32 a5) {
    u8 *g = (u8 *)a5;
    s32 w = *(s32 *)(g + 0xD4);

    *(s32 *)(a0 + 0xC0) = (s32)a4;
    *(s32 *)(a0 + 0xC4) = 1;
    CopyGeometryPointer(a0 + 0xD0, a1);
    *(u128 *)a0 = ZeroVector;
    func_400CC948(a0, g, 1);
    *(s32 *)(a0 + 0x110) = 0;
    *(u128 *)(a0 + 0x70) = *(u128 *)&All1Vector;
    *(u128 *)(a0 + 0x80) = *(u128 *)&All1Vector;
    *(u128 *)(a0 + 0x90) = *(u128 *)&ZUnitVector;
    *(s32 *)(a0 + 0x114) = 0;
    *(s32 *)(a0 + 0x118) = 0;
    *(s32 *)(a0 + 0x11C) = 0;
    *(s32 *)(a0 + 0x120) = 0;
    *(s32 *)(a0 + 0x124) = 0;
    *(s32 *)(a0 + 0x128) = 0;
    *(s32 *)(a0 + 0x12C) = 0;
    *(f32 *)(a0 + 0x144) = 1.0f;
    *(s32 *)(a0 + 0x130) = 0;
    *(s32 *)(a0 + 0x134) = 0;
    *(f32 *)(a0 + 0x138) = 1.0f;
    *(f32 *)(a0 + 0x13C) = 1.0f;
    *(f32 *)(a0 + 0x140) = 1.0f;
    *(s32 *)(a0 + 0x148) = func_400D28C8((f32 *)(a0 + 0x14C), a0, (u8 *)w, g);
    if (*(s32 *)(g + 0xCC) == 0) {
        if (func_400D2950(a0, (u8 *)w) == 0) {
            *(s32 *)(a0 + 0x114) = 1;
            *(s32 *)(a0 + 0xC4) = 0;
        }
    }
    w = 1;
    *(s32 *)(a0 + 0x15C) = (s32)a2;
    *(s32 *)(a0 + 0x160) = (s32)a3;
    *(s32 *)(a0 + 0x158) = w;
    *(s32 *)(a0 + 0x168) = w;
    *(s32 *)(a0 + 0x164) = 0;
    CopyCollisionFinder(a0 + 0x170, InitialCollisionFinder);
    *(s32 *)(a0 + 0x16C) = 0;
    *(s32 *)(a0 + 0x180) = 0;
    *(s32 *)(a0 + 0x184) = 0;
    *(s32 *)(a0 + 0x18C) = w;
    *(s32 *)(a0 + 0x188) = *(s32 *)(g + 0xD8);
    *(s32 *)(a0 + 0x194) = 0;
    *(s32 *)(a0 + 0x190) = 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0166_init_texture_animation_parameter", func_400D2658);

s32 func_400D27D8(u8 *a, u8 *b, u8 *c) {
    if (*(s32 *)(a + 0x110) == 0) {
        if (*(s32 *)(b + 0x64) != 0 || *(s32 *)(b + 0xB0) == 1 || *(s32 *)(c + 0x164) == 2) {
            return 1;
        }
    }
    return 0;
}

s32 func_400D2820(s32 **a, s32 **b) {
    if (*(f32 *)((u8 *)*a + 0x144) < *(f32 *)((u8 *)*b + 0x144)) {
        return 1;
    }
    return -1;
}

void func_400D2848(u8 *n, s32 a, s32 b) {
    u8 *e = n + 0x10;
    u8 *v = *(u8 **)n;
    u8 *w = *(u8 **)(v + 0x48);

    func_400CCE58(e, w, *(s32 *)(w + 0xD4), a, b);
    if (*(s32 *)(e + 0x164) == 1) {
        v = *(u8 **)n;
        disp_particle_emitter(e, *(s32 *)(v + 0x48), *(s32 *)(v + 0x4C));
    }
}

s32 func_400D28C8(f32 *out, u8 *e, u8 *a, u8 *b) {
    if (*(s32 *)(a + 0x15C) == 3 || *(s32 *)(a + 0x160) == 3 || *(s32 *)(b + 0xC8) == 1) {
        if (GetWaterSurfacePositionY(out, (f32 *)(e + 0x10), D_4012B4F0, 100.0f, -500.0f) == 1) {
            return 1;
        }
    }
    *out = *(f32 *)(e + 0x14);
    return 0;
}

/* NEARMISS-STUB func_400D2950 */
#if 0 /* NEARMISS 44.29% cat=branch-layout sub=- | no cause recorded | attempts=1 */
s32 func_400D2950(u8 *a0, u8 *a1) {
    f32 f;
    s32 k = *(s32 *)(a1 + 0x15C);

    if (k == 1) {
        f = *(f32 *)(a1 + 0xB4);
        goto S1;
    }
    if (k == 0) {
        *(f32 *)(a0 + 0x150) = 10000000.0f;
        goto H2;
    }
    if (k == 2) {
        f = *(f32 *)(a0 + 0x14);
    } else {
        f = *(f32 *)(a0 + 0x14C);
    }
    f = *(f32 *)(a1 + 0xB4) + f;
S1:
    *(f32 *)(a0 + 0x150) = f;
H2:
    k = *(s32 *)(a1 + 0x160);
    if (k == 1) {
        f = *(f32 *)(a1 + 0x140);
        goto S2;
    }
    if (k == 0) {
        *(f32 *)(a0 + 0x154) = -10000000.0f;
        return 1;
    }
    if (k == 2) {
        f = *(f32 *)(a0 + 0x14);
    } else {
        f = *(f32 *)(a0 + 0x14C);
    }
    f = *(f32 *)(a1 + 0x140) + f;
S2:
    *(f32 *)(a0 + 0x154) = f;
    return 1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0166_init_texture_animation_parameter", func_400D2950);

s32 func_400D29F8(u8 *a) {
    return *(s32 *)(a + 0xC8) == 2;
}

void func_400D2A08(u8 *a, u8 *b) {
    f32 t = *(f32 *)(a + 0x130);
    f32 x = *(f32 *)(b + 0x28);

    if (t < x) {
        *(f32 *)(a + 0x13C) = t / x;
    } else if (t < *(f32 *)(b + 0x2C)) {
        *(f32 *)(a + 0x13C) = 1.0f;
    } else if (t < *(f32 *)(b + 0x30)) {
        *(f32 *)(a + 0x13C) = (*(f32 *)(b + 0x30) - t) / (*(f32 *)(b + 0x30) - *(f32 *)(b + 0x2C));
    } else {
        *(s32 *)(a + 0x13C) = 0;
    }
    *(f32 *)(a + 0x140) = *(f32 *)(a + 0x138) * *(f32 *)(a + 0x13C);
}

f32 get_particle_lod_base_size(void *);

void func_400D2A88(u8 *a0, u8 *a1) {
    if (*(s32 *)(a1 + 8) == 0) {
        *(s32 *)(a0 + 0x118) = 0;
    } else {
        f32 lod = get_particle_lod_base_size(a0);
        s32 old = *(s32 *)(a0 + 0x118);

        if (*(s32 *)(a1 + 8) == 1) {
            if (lod < *(f32 *)(a1 + 0x14)) {
                *(s32 *)(a0 + 0x118) = 1;
            } else if (lod < *(f32 *)(a1 + 0x18)) {
                *(s32 *)(a0 + 0x118) = old;
            } else {
                *(s32 *)(a0 + 0x118) = 0;
            }
        } else if (lod < *(f32 *)(a1 + 0xC)) {
            *(s32 *)(a0 + 0x118) = 2;
        } else if (lod < *(f32 *)(a1 + 0x10)) {
            *(s32 *)(a0 + 0x118) = old;
        } else if (lod < *(f32 *)(a1 + 0x14)) {
            *(s32 *)(a0 + 0x118) = 1;
        } else if (lod < *(f32 *)(a1 + 0x18)) {
            *(s32 *)(a0 + 0x118) = old;
        } else {
            *(s32 *)(a0 + 0x118) = 0;
        }
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0166_init_texture_animation_parameter", func_400D2B68);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0166_init_texture_animation_parameter", func_400D2D38);

#include "common.h"

extern s32 DldSysUndefSymbol;
typedef struct PartSeg { s32 f0; s32 f4; s32 f8; s32 fC; } PartSeg;
extern PartSeg *func_400D1FA8(void);
extern s32 create_particle_texture_and_get_id(u8 *);
extern s32 func_400D1F30(u8 *, s32, u8 *, u8 *);

signed char CheckClothChainExist(void *arg0)
{
    return (*(signed char *)((char *)(arg0) + 6));
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", ResetClothDynamics);

extern void CopyGeometryPointer(char *, int, int, int);

void SetClothSingleFixedChainLeafFixGeometryPointer(char *p, int a, int b, int c)
{
    char *g = p + 0x30;
    g[0x40] = 1;
    CopyGeometryPointer(g, a, b, c);
    g[0x41] = 0;
}

void SetClothSingleFixedChainLeafFixNodeOffset(void *arg0, signed char arg1)
{
    (*(signed char *)((char *)(arg0) + 0x71)) = arg1;
}

/* NEARMISS-STUB getClothDynamics */
#if 0 /* NEARMISS 91.93% cat=regalloc sub=- | d2 r87: o[0x80] = (o[0x80]+1)&1; if (o[0x80]) (store then re-test = the move v1,v0 copy) fixes the head (90.30 -> 91.93); left: loop -1 const in a2 (target a3)  | attempts=1 */
extern void func_400C8FA0(u8 *, s32, f32, f32);
extern void func_400C9710(u8 *, s32, s32);
extern void func_400C94F8(u8 *, s32, f32, f32);

/* getClothDynamics: args are (f12 dt, f13 w, a0 cloth, a1, a2 unused, a3 callback, t0 cbarg) */
s32 getClothDynamics(f32 dt, f32 w, u8 *o, s32 a1, s32 unused, void (*cb)(u8 *, s32, s32), s32 cbarg)
{
    s32 n;
    s32 *hdr;
    s32 *p;
    s32 f;

    if (dt != 0.0f) {
        hdr = *(s32 **)o;
        p = *(s32 **)(o + 0xC);
        n = hdr[1];
        o[0x80] = (o[0x80] + 1) & 1;
        if (o[0x80]) {
            while (--n != -1) {
                p[4] = p[1];
                p[5] = p[0];
                p += 6;
            }
        } else {
            while (--n != -1) {
                p[4] = p[0];
                p[5] = p[1];
                p += 6;
            }
        }
        func_400C8FA0(o, a1, dt, w);
        if (cb != 0) {
            cb(o, a1, cbarg);
        } else {
            func_400C9710(o, a1, 0);
        }
        func_400C94F8(o, a1, dt, w);
    }
    return 1;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", getClothDynamics);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", clothmath_doubleTensionMove);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", create_particle_texture_and_get_id);

/* add_particle_segment: fill a free PartSeg from a npe file, then resolve each 0x54-byte emitter's texture links (dld link word at +0x20) */
void add_particle_segment(u8 *src)
{
    PartSeg *dst;
    s32 i;
    u8 *e;
    u8 *slot;
    u8 *tex;
    u32 d;
    u32 *lp;
    s32 n;

    if (src != 0) {
        i = 0;
        dst = func_400D1FA8();
        dst->f0 = *(s32 *)src;
        dst->f4 = (s32)src;
        n = *(s32 *)(src + 0xC);
        dst->f8 = n;
        dst->fC = *(s32 *)(src + 0x10);
        if (n > 0) {
            do {
                e = (u8 *)dst->fC + i * 0x54;
                lp = (u32 *)(e + 0x20);
                d = *lp & 0x3FFFF;
                slot = d ? *(u8 **)((u8 *)lp - d) : 0;
                if (slot != 0 && slot != (u8 *)DldSysUndefSymbol) {
                    tex = *(u8 **)(slot + 0x10) + ((*lp >> 18) & 0xFFF) * *(s32 *)(*(u8 **)(slot + 8) + 0xC);
                } else {
                    tex = 0;
                }
                i++;
                *(s32 *)(e + 0x48) = func_400D1F30(e + 0xC, create_particle_texture_and_get_id(tex), src, e);
                *(s32 *)(e + 0x4C) = func_400D1F30(e + 0x1C, -1, src, e);
            } while (i < dst->f8);
        }
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CBA98);

extern void *malloc_from_root_partition(s32, const char *);
extern const char D_40134150[];
extern void isysInitGroup(void *);
extern s32 D_401AD580[];
extern char g_sPtclNullName[];
extern void func_400D2210(void);
extern u8 *D_4012B4EC;
typedef struct PtclPool { s32 cnt; s32 head; s32 tail; } PtclPool;
extern PtclPool D_401AD570;
typedef struct PtclTex { s32 name; s32 f4; s32 f8; } PtclTex;
extern PtclTex g_ainParticleTextureStore[40];
typedef struct PtclSegE { s32 name; s32 f4; s32 f8; s32 fC; } PtclSegE;
extern PtclSegE g_ainParticleSegment[50];

/* particle pool: 0xB0-byte nodes linked through +0xA8 */
static inline void ptclPoolPush(PtclPool *pl, u8 *e)
{
    if (e != 0) {
        if (pl->tail != 0) {
            *(s32 *)(pl->tail + 0xA8) = (s32)e;
        } else {
            pl->head = (s32)e;
        }
        *(s32 *)(e + 0xA8) = 0;
        pl->tail = (s32)e;
        pl->cnt++;
    }
}
void init_particle_manager(void)
{
    s32 i;
    u8 *e;

    D_4012B4EC = malloc_from_root_partition(0x22600, D_40134150);
    D_401AD570.cnt = 0;
    D_401AD570.head = 0;
    D_401AD570.tail = 0;
    for (i = 0; i < 800; i++) {
        ptclPoolPush(&D_401AD570, D_4012B4EC + i * 0xB0);
    }
    isysInitGroup(D_401AD580);
    for (i = 0; i < 40; i++) {
        g_ainParticleTextureStore[i].name = (s32)g_sPtclNullName;
        g_ainParticleTextureStore[i].f4 = 0;
        g_ainParticleTextureStore[i].f8 = 0;
    }
    for (i = 0; i < 50; i++) {
        g_ainParticleSegment[i].name = (s32)g_sPtclNullName;
        g_ainParticleSegment[i].f4 = 0;
        g_ainParticleSegment[i].f8 = 0;
        g_ainParticleSegment[i].fC = 0;
    }
    func_400D2210();
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", doit_particle_manager);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CC058);

extern s32 CheckCollisionFinderAlive();
extern void ReleaseCollisionFinder();
extern void iosFree(void *);

static inline void ptclListRemove(s32 *l, s32 n)
{
    s32 cur;
    s32 prev;

    if (n != 0) {
        cur = n;
        prev = 0;
        do {
            if (cur == n) {
                if (prev != 0) {
                    *(s32 *)(prev + 0xA8) = *(s32 *)(n + 0xA8);
                }
                if (l[1] == n) {
                    l[1] = *(s32 *)(n + 0xA8);
                }
                if (l[2] == n) {
                    l[2] = prev;
                }
                l[0]--;
                break;
            }
            prev = cur;
            cur = *(s32 *)(cur + 0xA8);
        } while (cur != 0);
    }
}

/* func_400CC1E8: free every emitter of a list (node + 0x10 is the emitter), returning its sub-nodes (list at emitter+0x124) to the particle pool */
void func_400CC1E8(s32 *list)
{
    u8 *node = (u8 *)*list;
    u8 *em;
    u8 *next;
    s32 *l;
    s32 n;

    while (node != 0) {
        em = node + 0x10;
        next = *(u8 **)(node + 0x1B0);
        if (em != 0) {
            *(s32 *)(em + 0x114) = 1;
            if (*(s32 *)(em + 0x158) == 1 && *(void (**)(s32))(em + 0x15C) != 0) {
                (*(void (**)(s32))(em + 0x15C))(*(s32 *)(em + 0x160));
            }
            l = (s32 *)(em + 0x124);
            while (l[1] != 0) {
                n = l[1];
                ptclListRemove(l, n);
                ptclPoolPush(&D_401AD570, n);
            }
            if (CheckCollisionFinderAlive(em + 0x170) != 0) {
                ReleaseCollisionFinder(em + 0x170);
            }
        }
        iosFree(node);
        node = next;
    }
    *list = 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CC348);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CC510);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CC6E8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CC948);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0161_CheckClothChainExist", func_400CCC28);

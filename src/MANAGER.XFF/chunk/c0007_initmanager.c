#include "common.h"

typedef struct PartEnt {
    s32 f0;
    s32 size;
    s32 handle;
} PartEnt;
typedef struct PartConf {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 count;
    PartEnt *ents;
} PartConf;

typedef struct InterpRatio {
    /* 0x00 */ s32 act;
    /* 0x04 */ s32 maxZeroClip;
    /* 0x08 */ s32 one8;
    /* 0x0C */ f32 timer;
    /* 0x10 */ f32 ratio;
    /* 0x14 */ f32 start;
    /* 0x18 */ f32 step;
    /* 0x1C */ f32 one;
} InterpRatio;

extern s32 D_40124790;
extern s32 D_40124794;
extern s32 rootPtn;

void *iosMallocAlign(void *, s32, s32);
void *iosMallocAlignNoCheck(s32, s32, s32);
s32 iosCreatePartition();
void dsysInit();
void InitBinarySize();
void sheetMgrInit();
void initSoundManager();
void adpcmMgrInit();
void init_camera_context_manager();
void init_wind_manager();
void init_particle_manager();
void InitDamageLetter();
s32 func_4001E0F0(f32);
void func_4001E138();
f32 powf(f32, f32);
void GAMEUTIL_set_param_interp_ratio_cntrl(InterpRatio *, f32, f32);

void initmanager(void) {
    dsysInit();
    InitBinarySize();
    sheetMgrInit();
    initSoundManager();
    adpcmMgrInit();
    D_40124790 = iosCreatePartition(&rootPtn, 0x19999);
    init_camera_context_manager();
    init_wind_manager();
    init_particle_manager();
    InitDamageLetter();
}

s32 get_fast_get_malloc_partition(void) {
    return D_40124790;
}

void *malloc_from_src_partition(s32 part, s32 size, s32 unused, s32 fallback) {
    void *p = NULL;

    if (part != 0) {
        p = iosMallocAlignNoCheck(part, size, 0x10);
    }
    if (p == NULL && fallback == 1) {
        p = iosMallocAlign(&rootPtn, size, 0x10);
    }
    return p;
}

s64 malloc_from_root_partition(s32 size)
{
    return (s64)iosMallocAlign(&rootPtn, size, 0x10);
}

void *malloc_from_fast_get_partition(s32 size, s32 unused, s32 fallback) {
    s32 part = D_40124790;
    void *p = NULL;

    if (part != 0) {
        p = iosMallocAlignNoCheck(part, size, 0x10);
    }
    if (p == NULL && fallback == 1) {
        p = iosMallocAlign(&rootPtn, size, 0x10);
    }
    return p;
}

void entrymanager(void) {
}

/* NEARMISS-STUB initmanagerPartitionConf */
#if 0 /* NEARMISS 93.75% cat=sched sub=prologue-save-order | body identical; only prologue save order (s1 vs s2 first, i=1 init and D_40124794 store placement) | attempts=1 */
void initmanagerPartitionConf(PartConf *cfg) {
    PartEnt *e = cfg->ents;
    s32 i = 1;

    D_40124794 = (s32)cfg;
    e->handle = (s32)&rootPtn;
    for (; i < cfg->count; i++) {
        e++;
        e->handle = iosCreatePartition(&rootPtn, e->size);
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0007_initmanager", initmanagerPartitionConf);

/* NEARMISS-STUB getPartitionByName */
#if 0 /* NEARMISS 94.74% cat=sched sub=- | no cause recorded | attempts=1 */
void *getPartitionByName(char *name) {
    PartConf *cfg;
    PartEnt *e;
    s32 i;

    cfg = (PartConf *)D_40124794;
    if (cfg != 0) {
        e = cfg->ents;
        i = 1;
        if (i < cfg->count) {
            e++;
            do {
                if (strcmp((char *)e->f0, name) == 0) {
                    return (void *)e->handle;
                }
                i++;
                e++;
            } while (i < ((PartConf *)D_40124794)->count);
        }
    }
    return &rootPtn;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0007_initmanager", getPartitionByName);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0007_initmanager", GAMEUTIL_get_spring_interpolate_value3D_extend);

/* NEARMISS-STUB GAMEUTIL_doit_interp_ratio_cntrl */
#if 0 /* NEARMISS 53.66% cat=regalloc sub=- | no cause recorded | attempts=1 */
f32 GAMEUTIL_doit_interp_ratio_cntrl(InterpRatio *c, f32 t) {
    f32 ratio;

    if (c->act == 1) {
        if (0.0f < c->timer) {
            c->one8 = 0;
        }
        if (0.0f <= t) {
        } else {
            t = t * c->one;
        }
        c->timer = c->timer + t;
        if (c->maxZeroClip == 1) {
            if (c->timer < 0.0f) {
                c->timer = 0.0f;
            }
            if (c->start + c->step < c->timer) {
                c->timer = c->start + c->step;
            }
        }
        if (c->timer <= c->start) {
            ratio = 0.0f;
        } else if (c->start + c->step <= c->timer) {
            ratio = 1.0f;
        } else {
            ratio = (c->timer - c->start) / ((c->start + c->step) - c->start);
        }
        c->ratio = ratio;
        return ratio;
    } else {
        c->one8 = 1;
        c->ratio = 1.0f;
        c->timer = 0.0f;
        return 1.0f;
    }
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0007_initmanager", GAMEUTIL_doit_interp_ratio_cntrl);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0007_initmanager", doit_double_spring_interp_cntrl);

f32 GAMEUTIL_get_dist_ratio(f32 v, f32 lo, f32 hi) {
    if (v <= lo) {
        return 0.0f;
    }
    if (hi <= v) {
        return 1.0f;
    }
    return (v - lo) / (hi - lo);
}

/* NEARMISS-STUB GAMEUTIL_get_dist_ratio_by_dist_squ */
#if 0 /* NEARMISS 3.42% cat=no-c-form sub=- | no cause recorded | attempts=1 */
f32 sqrtf(f32);

f32 GAMEUTIL_get_dist_ratio_by_dist_squ(f32 v, f32 lo, f32 hi) {
    if (v <= lo * lo) {
        return 0.0f;
    }
    if (hi * hi <= v) {
        return 1.0f;
    }
    return (sqrtf(v) - lo) / (hi - lo);
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0007_initmanager", GAMEUTIL_get_dist_ratio_by_dist_squ);

f32 GAMEUTIL_get_cos_ratio(f32 param_1, f32 param_2, f32 param_3, f32 param_4) {
    f32 r = 0.0f;

    if (!(param_2 <= param_3)) {
        r = 1.0f;
        if (!(param_4 <= param_2)) {
            r = (param_2 - param_3) / (param_4 - param_3);
        }
    }
    if (param_1 != 1.0f && 0.0f < r && r < 1.0f) {
        if (r <= 0.5f) {
            r = powf(r + r, param_1) * 0.5f;
        } else {
            r = (1.0f - powf(1.0f - ((r - 0.5f) + (r - 0.5f)), param_1)) * 0.5f + 0.5f;
        }
    }
    return r;
}

f32 GAMEUTIL_get_interp_value(f32 a, f32 b, f32 t) {
    if (t <= 0.0f) {
        return b;
    }
    if (1.0f <= t) {
        return a;
    }
    if (a == b) {
        return a;
    }
    return t * a + (1.0f - t) * b;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0007_initmanager", GAMEUTIL_get_interp_value3D);

/* NEARMISS-STUB GAMEUTIL_get_interp_value_ratio_pow */
#if 0 /* NEARMISS 90.0% cat=sched sub=const-load-order | powf result compare: target loads 0.0 and 1.0 after the call (mtc1 zero before lui), ours hoists one | attempts=1 */
f32 GAMEUTIL_get_interp_value_ratio_pow(f32 a, f32 b, f32 t, f32 e) {
    f32 r = powf(t, e);

    if (r <= 0.0f) {
        return b;
    }
    if (1.0f <= r) {
        return a;
    }
    if (a == b) {
        return a;
    }
    return r * a + (1.0f - r) * b;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0007_initmanager", GAMEUTIL_get_interp_value_ratio_pow);

/* NEARMISS-STUB GAMEUTIL_get_spring_damp_offset */
#if 0 /* NEARMISS 68.68% cat=regalloc sub=- | no cause recorded | attempts=1 */
f32 GAMEUTIL_get_spring_damp_offset(f32 param_1, f32 param_2, f32 param_3, f32 param_4, f32 param_5, f32 param_6, f32 param_7, f32 param_8, f32 param_9) {
    f32 fVar2;
    f32 fVar3;
    f32 fVar4;
    f32 fVar5;
    f32 fVar6;

    param_4 = param_4 - param_2;
    param_3 = param_3 * 0.5f;
    fVar5 = 0.0f;
    if (param_3 < param_4) {
        fVar6 = param_4 - param_3;
    } else {
        fVar6 = 0.0f;
        if (param_4 < -param_3) {
            fVar6 = param_4 - -param_3;
        }
    }
    if (GAMEUTIL_is_nearly_equal_zero(fVar6, param_8) == 0) {
        fVar3 = -fVar6;
        fVar4 = fVar3;
        if (0.0f <= param_1) {
            fVar4 = fVar3 * param_1 * param_9;
        }
        fVar2 = fVar4;
        if (fVar4 < 0.0f) {
            fVar2 = -fVar4;
        }
        if (fVar6 < 0.0f) {
            if (fVar2 <= fVar3) {
                fVar5 = fVar5 + fVar4;
                goto done;
            }
        } else if (fVar2 <= fVar6) {
            fVar5 = fVar5 + fVar4;
            goto done;
        }
        if (fVar4 == 0.0f) {
            fVar5 = fVar5 + fVar4;
        } else {
            fVar6 = fVar6 / fVar4;
            if (fVar6 < 0.0f) {
                fVar6 = -fVar6;
            }
            fVar5 = fVar5 + fVar4 * fVar6;
        }
    }
done:
    if (param_5 != 0.0f) {
        fVar5 = fVar5 + param_5 * param_6 * param_9;
    }
    fVar6 = fVar5;
    if (0.0f < param_7) {
        param_7 = param_7 * param_9;
        if (0.0f <= fVar5) {
            fVar6 = param_7;
            if (fVar5 <= param_7) {
                return fVar5;
            }
        } else if (param_7 < -fVar5) {
            fVar6 = -param_7;
        }
    }
    return fVar6;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0007_initmanager", GAMEUTIL_get_spring_damp_offset);

/* NEARMISS-STUB GAMEUTIL_get_spring_interpolate_offset */
#if 0 /* NEARMISS 74.4% cat=regalloc sub=- | no cause recorded | attempts=1 */
f32 GAMEUTIL_get_spring_interpolate_offset(f32 param_1, f32 param_2, f32 param_3, f32 param_4, f32 param_5, f32 param_6) {
    f32 fVar2;
    f32 fVar3;
    f32 fVar4;
    f32 fVar5;
    f32 fVar6;

    param_3 = param_3 - param_4;
    fVar5 = 0.0f;
    if (0.0f < param_3) {
        fVar6 = param_3 - 0.0f;
    } else {
        fVar6 = 0.0f;
        if (param_3 < -0.0f) {
            fVar6 = param_3 - -0.0f;
        }
    }
    if (GAMEUTIL_is_nearly_equal_zero(fVar6, param_5) == 0) {
        fVar3 = -fVar6;
        fVar4 = fVar3;
        if (0.0f <= param_1) {
            fVar4 = fVar3 * param_1 * param_6;
        }
        fVar2 = fVar4;
        if (fVar4 < 0.0f) {
            fVar2 = -fVar4;
        }
        if (fVar6 < 0.0f) {
            if (fVar2 <= fVar3) {
                fVar5 = fVar5 + fVar4;
                goto done;
            }
        } else if (fVar2 <= fVar6) {
            fVar5 = fVar5 + fVar4;
            goto done;
        }
        if (fVar4 == 0.0f) {
            fVar5 = fVar5 + fVar4;
        } else {
            fVar6 = fVar6 / fVar4;
            if (fVar6 < 0.0f) {
                fVar6 = -fVar6;
            }
            fVar5 = fVar5 + fVar4 * fVar6;
        }
    }
done:
    fVar6 = fVar5;
    if (0.0f < param_2) {
        param_2 = param_2 * param_6;
        if (0.0f <= fVar5) {
            fVar6 = param_2;
            if (fVar5 <= param_2) {
                return fVar5;
            }
        } else if (param_2 < -fVar5) {
            fVar6 = -param_2;
        }
    }
    return fVar6;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0007_initmanager", GAMEUTIL_get_spring_interpolate_offset);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0007_initmanager", GAMEUTIL_get_spring_interpolate_value_extend);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0007_initmanager", GAMEUTIL_get_spring_interpolate_offset3D);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0007_initmanager", GAMEUTIL_get_spring_interpolate_value3D);

void GAMEUTIL_constructor_interp_ratio_cntrl(InterpRatio *c) {
    c->timer = 0;
    c->act = 1;
    c->one8 = 1;
    c->maxZeroClip = 0;
    c->ratio = 0;
    GAMEUTIL_set_param_interp_ratio_cntrl(c, c->timer, 1.0f);
}

void GAMEUTIL_reset_interp_ratio_cntrl(InterpRatio *c) {
    c->one8 = 1;
    c->timer = 0;
    if (c->act == 1) {
        c->ratio = 0;
    } else {
        c->ratio = 1.0f;
    }
}

void GAMEUTIL_forward_timer_still_one_ratio_time_interp_ratio_cntrl(InterpRatio *c) {
    c->timer = c->start + c->step;
}

f32 GAMEUTIL_get_interp_ratio_interp_ratio_cntrl(InterpRatio *c) {
    return c->ratio;
}

f32 GAMEUTIL_get_interp_timer_interp_ratio_cntrl(InterpRatio *c) {
    return c->timer;
}

void GAMEUTIL_set_act_interp_flag_interp_ratio_cntrl(InterpRatio *c, s32 v) {
    c->act = v;
}

void GAMEUTIL_set_act_max_zero_clip_flag_interp_ratio_cntrl(InterpRatio *c, s32 v) {
    c->maxZeroClip = v;
}

void GAMEUTIL_set_param_interp_ratio_cntrl(InterpRatio *c, f32 t, f32 d) {
    if (t < 0.0f) {
        t = 0.0f;
    }
    {
        s32 v = func_4001E0F0(t);

        c->start = t;
        c->step = d;
        c->one = 1.0f;
        func_4001E138(c, v);
    }
}

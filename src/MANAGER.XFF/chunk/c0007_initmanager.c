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

/* c0007 partition table conf: PartConf header (count at 0xC, ents at 0x10), PartEnt stride 0xC (size 4, handle 8) */
void initmanagerPartitionConf(PartConf *cfg) {
    PartEnt *e;
    s32 i = 1;

    e = cfg->ents;
    D_40124794 = (s32)cfg;
    e->handle = (s32)&rootPtn;
    for (e++; i < cfg->count; i++, e++) {
        e->handle = iosCreatePartition(&rootPtn, e->size);
    }
}

void *getPartitionByName(char *name)
{
    PartConf *cfg = (PartConf *)D_40124794;
    PartEnt *e;
    s32 i;

    if (cfg != NULL)
    {
        e = cfg->ents;
        e++;
        for (i = 1; i < ((PartConf *)D_40124794)->count; i++, e++)
        {
            if (strcmp((char *)e->f0, name) == 0)
            {
                return (void *)e->handle;
            }
        }
    }
    return &rootPtn;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0007_initmanager", GAMEUTIL_get_spring_interpolate_value3D_extend);

/* c0007 interp ratio cntrl tick: InterpRatio act/maxZeroClip/one8/timer/ratio/start/step/one, TU typedef */
f32 GAMEUTIL_doit_interp_ratio_cntrl(InterpRatio *c, f32 t) {
    f32 timer;
    f32 ratio;
    f32 sum;

    if (c->act == 1) {
        timer = c->timer;
        if (0.0f < timer) {
            c->one8 = 0;
        }
        if (0.0f <= t) {
            c->timer = timer + t;
        } else {
            c->timer = timer + t * c->one;
        }
        timer = c->timer;
        if (c->maxZeroClip == 1) {
            if (timer < 0.0f) {
                c->timer = 0.0f;
                timer = 0.0f;
            }
            if (c->start + c->step < timer) {
                c->timer = c->start + c->step;
                timer = c->start + c->step;
            }
        }
        sum = c->start + c->step;
        if (timer <= c->start) {
            ratio = 0.0f;
        } else if (sum <= timer) {
            ratio = 1.0f;
        } else {
            ratio = (timer - c->start) / (sum - c->start);
        }
        c->ratio = ratio;
        return ratio;
    } else {
        c->one8 = 1;
        c->timer = 0.0f;
        c->ratio = 1.0f;
        return 1.0f;
    }
}

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

f32 GAMEUTIL_get_interp_value_ratio_pow(f32 a, f32 b, f32 t, f32 power)
{
    f32 ratio = powf(t, power);
    f32 result;

    if (ratio <= 0.0f) {
        result = b;
        goto done;
    }
    if (ratio >= 1.0f) {
        result = a;
        goto done;
    }
    if (a == b) {
        result = a;
        goto done;
    }
    result = (ratio * a) + ((1.0f - ratio) * b);

done:
    return result;
}

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

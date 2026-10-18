#include "common.h"

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F5468);
/* GAMECORE c0190 func_400F5530: 100 in scratch; Ghidra param order is wrong (dst a0, arr a1, n a2, float val f12); `for (i=0;i<n;i++) arr[i]=val` is what makes gcc copy a1/a2 for the loop */
extern void *memset(void *, int, unsigned int);

/* GAMECORE c0190 func_400F5A68: 100 in scratch; `dst->q = src->q` on the Q4 union keeps lq/sq (whole-union assign gives ld/sd); return via if/return 1/return 0 (lay != 0 gives sltu) */
typedef union { s128 q; float f[4]; } Q4;
extern u8 *GetLayoutClass(s32);

/* GAMECORE c0190 func_400F5AB0: 100 in scratch; re-read *(p+0x80) in the while test and the if, do -=/+= on memory (local-var form got 90.2: CSE removed the reload) */
extern void gameModeSet(u32);
extern void gameModeCls(u32);

extern void boot_camera_lws_animation_by_script(s32);
extern void *get_camera_obj(void *);
extern void *get_camera_position(void *);
extern s32 get_main_type_camera_lws_animation(void *);

f32 func_400F5468(u8 *p)
{
    return *(f32 *)(p + 0x250);
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F5470);
f32 func_400F5470(u8 *p)
{
    return *(f32 *)(p + 0x258);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F5478);

void *func_400F5530(void *dst, float *arr, s32 n, float val)
{
    void *r = memset(dst, 0, n << 2);
    s32 i; for (i = 0; i < n; i++) arr[i] = val;
    return r;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F55A8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F5650);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F57D8);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F5890);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F5978);

s32 func_400F5A68(Q4 *dst, u8 *obj)
{
    u8 *lay = GetLayoutClass(*(s32 *)(obj + 0x124));
    if (lay != 0) {
        dst->q = (*(Q4 **)(lay + 0x134))->q;
        return 1;
    }
    return 0;
}

void func_400F5AB0(u8 *p)
{
    while (*(s32 *)(p + 0x80) != 0) { if (*(s32 *)(p + 0x80) > 0) { gameModeCls(1); *(s32 *)(p + 0x80) -= 1; } else { gameModeSet(1); *(s32 *)(p + 0x80) += 1; } }
}

s32 func_400F5B20(u8 *p, void *cam)
{
    if (*(s32 *)(p + 0x90) == 0 && *(s32 *)(p + 0xf8) != 0) {
        boot_camera_lws_animation_by_script(*(s32 *)(p + 0xf8));
        *(s32 *)(p + 0x90) = get_main_type_camera_lws_animation(get_camera_position(get_camera_obj(cam)));
        return 1;
    }
    return 0;
}

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F5B90);
int func_400F5B90(int t)
{
    switch (t) {
    case 2 ... 3:
    case 7 ... 8:
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F5BD0);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F5CC0);

void *func_400F5D68(u8 *p)
{
    *(s32 *)p = 0;
    memset(p + 0x4, 0, 0x48);
    memset(p + 0x4c, 0, 0x1b4);
    memset(p + 0x200, 0, 0xcc);
    memset(p + 0x2cc, 0, 0x84);
    memset(p + 0x350, 0, 0xd0);
    memset(p + 0x420, 0, 0xe4);
    memset(p + 0x504, 0, 0xe4);
    return memset(p + 0x5e8, 0, 0x8c);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F5E08);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0190_func_400F5468", func_400F6438);

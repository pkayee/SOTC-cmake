#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0194_GetScreenRadius", GetScreenRadius);

typedef struct
{
    char pad0[8];
    float far;
    float near;
    float vs10;
    float vs14;
    float vs18;
} ViewScreen;

extern void func_400F1868(ViewScreen *);

void SetVSMatrix(ViewScreen *vs)
{
    vs->vs10 = vs->near;
    vs->vs14 = 1.0f;
    vs->vs18 = vs->far;
    func_400F1868(vs);
}

typedef struct
{
    int width;
    int height;
    float aspect;
    int pad0C;
    float dist;
    int pad14[2];
    float unk1C;
    float unk20;
    float unk24;
    float far;
    float near;
    float unk30;
} ViewContext;

void SetDefaultViewContext(ViewContext *v, int width, int height)
{
    v->width = width;
    v->height = height;
    v->aspect = 0.94f;
    v->dist = 500.0f;
    v->unk1C = 2048.0f;
    v->unk20 = 2048.0f;
    v->unk24 = 0.25f;
    v->far = 16770000.0f;
    v->near = 0.05f;
    v->unk30 = 65536.0f;
}

void SetViewContext(void *arg0, int arg1, int arg2, float fparg0, float fparg1, float fparg2, float fparg3, float fparg4)
{
    (*(float *)((char *)(arg0) + 0x30)) = fparg4;
    (*(float *)((char *)(arg0) + 0xC)) = fparg0;
    (*(float *)((char *)(arg0) + 0x24)) = fparg1;
    (*(float *)((char *)(arg0) + 0x28)) = fparg2;
    (*(float *)((char *)(arg0) + 0x2C)) = fparg3;
    (*(int *)((char *)(arg0) + 0)) = arg1;
    (*(int *)((char *)(arg0) + 4)) = arg2;
    (*(float *)((char *)(arg0) + 8)) = (float) ((float) arg1 / (float) arg2);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0194_GetScreenRadius", create_camera_context);

void iosFree(void *);

void release_camera_context(void *p)
{
    if (p != 0) {
        iosFree(p);
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0194_GetScreenRadius", constructor_camera_context);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0194_GetScreenRadius", GetScreenRadiusParticle);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0194_GetScreenRadius", init_camera_context_manager);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0194_GetScreenRadius", push_camera_context);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0194_GetScreenRadius", pop_camera_context);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0194_GetScreenRadius", get_cur_camera_context);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0194_GetScreenRadius", func_400F2588);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0194_GetScreenRadius", func_400F2730);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0194_GetScreenRadius", func_400F2990);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0194_GetScreenRadius", get_blend_sub_camera_lws_animation);

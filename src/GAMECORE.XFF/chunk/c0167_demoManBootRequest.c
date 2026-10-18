#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0167_demoManBootRequest", demoManBootRequest);

void *GetScriptLayoutClass(void *);

s32 demoManBootChk(void *actor)
{
    return (*(s32 *)((char *)((*(void **)((char *)(GetScriptLayoutClass(actor)) + 0x2D8))) + 8));
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0167_demoManBootRequest", demoManStart);

int demoManChkStart(void *actor)
{
    return (*(int *)((char *)((*(void **)((char *)(GetScriptLayoutClass(actor)) + 0x2D8))) + 0x3C)) != 0;
}

/* NEARMISS-STUB demoManEnd */
#if 0 /* NEARMISS 99.0% cat=linker-pad sub=- | in-TU: 99.23, rootPtn+0x278 reloc addend on lui vs addiu; second symbol func_400DCD30 at same addr for callback addiu | attempts=1 */
extern u8 rootPtn[];
extern void demoManBootRequest(void);
extern s32 createScriptObj(void *fn, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, void *a6, s32 a7);
extern void CancelCaptionSubThreadAll(void);
extern void SetDisplayModelNearClippingSwitch(s32);

void demoManEnd(void *o)
{
    char *w = *(char **)((char *)GetScriptLayoutClass(o) + 0x2D8);

    if (*(s32 *)(w + 0x20) > 0)
        createScriptObj(demoManBootRequest, *(s32 *)(w + 0x20), &rootPtn[0x278], 0x1000, 0, 1, 0, 0);
    if (*(s32 *)(w + 0x2C) > 0)
        createScriptObj(demoManBootRequest, *(s32 *)(w + 0x2C), &rootPtn[0x278], 0x1000, 0, 1, 0, 0);
    *(s32 *)(w + 0x10) = 1;
    CancelCaptionSubThreadAll();
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0167_demoManBootRequest", demoManEnd);

int demoManChkLoadFinish(void *actor)
{
    int *d = *(int **)((char *)GetScriptLayoutClass(actor) + 0x2D8);

    if (d[0x44/4] < d[0x48/4] - 1) return 1;
    return d[0] == 6;
}

/* NEARMISS-STUB demoManSkip */
#if 0 /* NEARMISS 80.0% cat=call-abi sub=- | in-TU: plain form tail-calls last jal (80); 100 only with dead store l=0 (rule 13 REVIEW) | attempts=1 */
void demoManSkip(void *a, void *b)
{
    void *l = GetScriptLayoutClass(a);
    SkipCutDemoCameraOrient(b);
    CancelCaptionSubThreadAll();
    l = 0;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0167_demoManBootRequest", demoManSkip);

int IsForwardTime__DemoMan(void *context, float time)
{
    void *work = *(void **)((char *)GetScriptLayoutClass(context) + 0x2D8);

    if (*(int *)((char *)work + 0x2C) <= 0) {
        return 1;
    }
    if (*(float *)((char *)work + 0x34) <= time && time <= *(float *)((char *)work + 0x38)) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0167_demoManBootRequest", ForwardTime__DemoMan);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0167_demoManBootRequest", func_400DCD30);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0167_demoManBootRequest", player_collision_check_direct_water_surface_plus);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0167_demoManBootRequest", get_camera_collision_data);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0167_demoManBootRequest", func_400DD350);

s32 acted_camera_warp(s32 arg0)
{
    return arg0 == 1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0167_demoManBootRequest", camera_collision_check_direct);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0167_demoManBootRequest", camera_invisible_collision_check_direct_by_exception_obj);

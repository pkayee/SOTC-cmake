#include "common.h"

extern s32 D_401247D0;
extern s32 D_401247D4;
extern s32 D_401247D8;
extern s32 D_401247DC;
extern s32 D_401247E0;
extern s32 D_401247E4;
extern s32 D_401247E8;
extern s32 D_401247F0;
extern s32 D_401247F4;
extern f32 D_401AA940[];

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0010_getNowBossEffect", getNowBossEffect);

s32 getNowBossEffect(void) {
    return D_401247D0;
}

/* NEARMISS-STUB setBossDeathEffect */
#if 0 /* NEARMISS 84.05% cat=sched sub=- | u32->f32 pair with p=&D_401AA940: ours keeps p in a0 before bltz and sw D_401247D8 in delay slot; target has sw before bltz, p in v0 copied to a0 in delay; andi | attempts=1 */
void setBossDeathEffect(u32 param_1, u32 param_2) {
    f32 *p;

    D_401247D0 |= 1;
    p = &D_401AA940;
    D_401247D8 = 0;
    p[0] = (f32)param_1 * 0.000244140625f;
    p[1] = (f32)param_2 * 0.000244140625f;
}
#endif
//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0010_getNowBossEffect", setBossDeathEffect);

void setBossDeathEffect(u32 a, u32 b) {
    D_401247D0 |= 1;
    D_401247D8 = 0;
    D_401AA940[0] = (f32)a * 0.000244140625f;
    D_401AA940[1] = (f32)b * 0.000244140625f;
}

void setShadowEffect(void) {
    D_401247D4 = 1;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0010_getNowBossEffect", endBossDeathEffect);

void endBossDeathEffect(void) {
    D_401247D0 &= -2;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0010_getNowBossEffect", getBossEffectBlurLevel);

s32 *getBossEffectBlurLevel(void) {
    return &D_401247DC;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0010_getNowBossEffect", getBossEffectColorR);

s32 *getBossEffectColorR(void) {
    return &D_401247E0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0010_getNowBossEffect", getBossEffectColorG);

s32 *getBossEffectColorG(void) {
    return &D_401247E4;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0010_getNowBossEffect", getBossEffectColorB);

s32 *getBossEffectColorB(void) {
    return &D_401247E8;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0010_getNowBossEffect", getBossEffectBlendRatio);

s32 *getBossEffectBlendRatio(void) {
    return &D_401247F0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0010_getNowBossEffect", getBossEffectOutLine);

s32 *getBossEffectOutLine(void) {
    return &D_401247F4;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0010_getNowBossEffect", clipBySphere);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0010_getNowBossEffect", clipByMinMaxCube);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0010_getNowBossEffect", getZ);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0010_getNowBossEffect", depthOfField);

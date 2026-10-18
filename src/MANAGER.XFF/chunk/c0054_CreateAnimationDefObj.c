#include "common.h"

static inline u8 *chrClass(u8 *obj)
{
    switch (obj[8])
    {
        case 9:
            return obj + 0x90;
        case 0x16:
            return obj + 0x90;
        default:
            return NULL;
    }
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0054_CreateAnimationDefObj", CreateAnimationDefObj);
u8 *_isysCreateObj(s32, s32, s32, s32, void (*)(void *), s32);
void func_40051B90(void);
void func_40051478();

u8 *CreateAnimationDefObj(u8 *parent, s32 ofs, u8 *src)
{
    u8 *p = *(u8 **)src;
    u8 *q = *(u8 **)(p + 0x20);
    u8 *obj = _isysCreateObj((s32)parent, 0x12, 0x38, *(s32 *)(q + 0x14) * 12 + ofs + 0x43, (void (*)(void *))func_40051B90, 0x10);

    func_40051478(src, obj, parent);
    return obj;
}

void func_40051B90(void) {
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0054_CreateAnimationDefObj", InitAnimationDefObj);
void func_40051478();

void InitAnimationDefObj(s32 a, s32 b, s32 c)
{
    func_40051478(c, a, b);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0054_CreateAnimationDefObj", GetAnimationDefObjWorkSize);
s32 GetAnimationDefObjWorkSize(u8 *obj)
{
    u8 *p = *(u8 **)obj;
    u8 *q = *(u8 **)(p + 0x20);

    return *(s32 *)(q + 0x14) * 12 + 0x33;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0054_CreateAnimationDefObj", CalcNodeInterp);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0054_CreateAnimationDefObj", CalcNodeQuaternionWithIK);

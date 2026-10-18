#include "common.h"

extern int func_40066C60();
extern void *D_4012AF20;
extern int D_4012AF24;
extern void func_400633C8(void);
extern void func_40064A20(int, int, float);
extern char *GetCharacterClass(int);

typedef struct {
    int id;

} SubAnim;

void SetCharacterObjMotionJumpSpeedLimit(void *obj, int limit)
{
    D_4012AF20 = func_40066C60;
    D_4012AF24 = limit;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0072_SetCharacterObjMotionJumpSpeedLimit", GetMainAnimation);

int GetSubAnimation(int obj, float t)
{
    char *chara;
    SubAnim *sub;
    int n;

    if (t == 0.0f) {
        return 0;
    }
    func_400633C8();
    chara = GetCharacterClass(obj);
    n = *(signed char *)(chara + 0xC14);
    sub = *(SubAnim **)(chara + 0x304);
    while (n--) {
        func_40064A20(obj, sub->id, t);
        sub++;
    }
    *(signed char *)(chara + 0xC14) = 0;
    return 1;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0072_SetCharacterObjMotionJumpSpeedLimit", func_40069C28);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0072_SetCharacterObjMotionJumpSpeedLimit", charrootdyn_acceptMotionRootOffset);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0072_SetCharacterObjMotionJumpSpeedLimit", func_4006A4B8);

#include "common.h"

extern void *_impure_ptr;

void srand(long arg0)
{
    (*(unsigned long *)((char *)(_impure_ptr) + 0xA8)) = (unsigned long) ((unsigned long) (arg0 << 0x20) >> 0x20);
}

int rand(void)
{
    struct { char pad[0xA8]; unsigned long next; } *r = _impure_ptr;

    r->next = r->next * 0x5851F42D4C957F2DUL + 1;
    return (int)((r->next >> 32) & 0x7FFFFFFF);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208_srand", rintf);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208_srand", func_400FF4E8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208_srand", sceMpegCreate);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208_srand", func_400FF7F0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208_srand", func_400FF8F0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208_srand", func_400FF9B8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208_srand", func_400FFB70);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208_srand", func_400FFE28);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0208_srand", func_400FFF98);

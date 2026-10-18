#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0169_func_400D6728", func_400D6728);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0169_func_400D6728", func_400D6760);
void func_400D6760(char *pa0)
{
    *(float *)(pa0 + 0xa4) = 1.0f;
    *(int *)(pa0 + 0xa0) = 0;
    *(int *)(pa0 + 0xa8) = 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0169_func_400D6728", func_400D6778);
void func_400D6778(void *arg0)
{
    (*(int *)((char *)(arg0) + 0x1b4)) = 0;
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0169_func_400D6728", func_400D6780);
void func_400D6780(char *pa0)
{
    *(float *)(pa0 + 0xb4) = 1.0f;
    *(int *)(pa0 + 0xb0) = 0;
    *(int *)(pa0 + 0xb8) = 0;
}

/* NEARMISS-STUB func_400D6798 */
#if 0 /* NEARMISS 99.5% cat=struct-layout sub=- | compiler emits zero stores in offset order 0xc8,0xbc,0xc0,0xc4; target order 0xc4,0xbc,0xc8,0xc0; statement order ignored | attempts=1 */
void func_400D6798(int *arg0)
{
    *(int *)((char *)arg0 + 0xc4) = 0;
    *(int *)((char *)arg0 + 0xbc) = 3;
    *(int *)((char *)arg0 + 0xc8) = 0;
    *(int *)((char *)arg0 + 0xc0) = 0;
}
#endif
INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0169_func_400D6728", func_400D6798);

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0169_func_400D6728", func_400D67B0);
void func_400D67B0(void *arg0)
{
    (*(int *)((char *)(arg0) + 0xcc)) = 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0169_func_400D6728", func_400D67B8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0169_func_400D6728", get_particle_parameter_blend_doit);

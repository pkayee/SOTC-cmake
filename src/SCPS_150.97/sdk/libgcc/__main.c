#include "common.h"

/* gcc 2.96 libgcc2.c L__main (EH_FRAME_SECTION_ASM_OP, no init section).
   libgcc was built -G0: its statics live in .data/.bss and are reached
   through their unsized D_ symbols. */

typedef void (*func_ptr)(void);

struct object;

void __register_frame_info(void *begin, struct object *ob);
void *__deregister_frame_info(void *begin);
int atexit(void (*func)(void));
void __do_global_dtors(void);

extern func_ptr D_001361CC[]; /* __CTOR_LIST__ */
#define __CTOR_LIST__ D_001361CC
extern char D_001361E0[]; /* __EH_FRAME_BEGIN__ */
#define __EH_FRAME_BEGIN__ D_001361E0

extern char D_0016A0F0[];      /* __do_global_ctors: static struct object object; */
extern s32 D_0016A108[];       /* __main: static int initialized; */

extern func_ptr *D_00135A64[]; /* __do_global_dtors: static func_ptr *p = __DTOR_LIST__ + 1; */
#define dtor_p (D_00135A64[0])
extern s32 D_00135A68[];       /* __do_global_dtors: static int completed; */

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/__main", __do_global_dtors);
void __do_global_dtors(void)
{
    while (*dtor_p)
    {
        dtor_p++;
        (*(dtor_p - 1))();
    }
    if (D_00135A68[0])
    {
        return;
    }
    D_00135A68[0] = 1;
    __deregister_frame_info(__EH_FRAME_BEGIN__);
}

/* Run all the global constructors on entry to the program.  */

#define DO_GLOBAL_CTORS_BODY \
    do \
    { \
        unsigned long nptrs = (unsigned long)__CTOR_LIST__[0]; \
        unsigned i; \
        if (nptrs == (unsigned long)-1) \
            for (nptrs = 0; __CTOR_LIST__[nptrs + 1] != 0; nptrs++) \
                ; \
        for (i = nptrs; i >= 1; i--) \
            __CTOR_LIST__[i](); \
    } while (0)

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/__main", __do_global_ctors);
void __do_global_ctors(void)
{
    {
        __register_frame_info(__EH_FRAME_BEGIN__, (struct object *)D_0016A0F0);
    }
    DO_GLOBAL_CTORS_BODY;
    atexit(__do_global_dtors);
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/__main", __main);
void __main(void)
{
    if (D_0016A108[0])
    {
        return;
    }
    D_0016A108[0] = 1;
    __do_global_ctors();
}

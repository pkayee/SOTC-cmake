#include "common.h"

typedef struct dwarf_fde
{
    s32 length;
    s32 CIE_delta;
    u32 pc_begin;
    u32 pc_range;
} dwarf_fde;

typedef struct fde_vector
{
    dwarf_fde **array;
    u32 count;
} fde_vector;

typedef struct fde_accumulator
{
    fde_vector linear;
    fde_vector erratic;
} fde_accumulator;

struct object
{
    void *pc_begin;
    void *pc_end;
    dwarf_fde *fde_begin;
    dwarf_fde **fde_array;
    u32 count;
    struct object *next;
};

extern s32 D_00132AA4[];
extern struct object *D_0016A110[];

s32 WaitSema(s32 sema);
s32 SignalSema(s32 sema);
void *malloc(u32 size);
void free(void *ptr);
void abort(void);

void __register_frame_info(void *begin, struct object *ob);
void __register_frame_info_table(void *begin, struct object *ob);
struct object *__deregister_frame_info(void *begin);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", __register_frame_info);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", __register_frame);
void __register_frame(void *begin)
{
    __register_frame_info(begin, malloc(sizeof(struct object)));
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", __register_frame_info_table);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", __register_frame_table);
void __register_frame_table(void *begin)
{
    __register_frame_info_table(begin, malloc(sizeof(struct object)));
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", __deregister_frame_info);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", __deregister_frame);
void __deregister_frame(void *begin)
{
    free(__deregister_frame_info(begin));
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", func_001263B8);
u32 func_001263B8(dwarf_fde *this_fde)
{
    u32 count;

    count = 0;
    while (this_fde->length != 0)
    {
        if (this_fde->CIE_delta != 0)
        {
            if (this_fde->pc_begin != 0)
            {
                count++;
            }
        }
        this_fde = (dwarf_fde *)((u8 *)this_fde + this_fde->length + 4);
    }
    return count;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", func_001263F8);


//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", func_00126488);
dwarf_fde *func_00126488(dwarf_fde *this_fde, u32 pc)
{
    while (this_fde->length != 0)
    {
        if (this_fde->CIE_delta != 0)
        {
            if (this_fde->pc_begin != 0)
            {
                if (pc - this_fde->pc_begin < this_fde->pc_range)
                {
                    return this_fde;
                }
            }
        }
        this_fde = (dwarf_fde *)((u8 *)this_fde + this_fde->length + 4);
    }
    return 0;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", func_001264E0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", func_00126648);

typedef struct unaligned_u32
{
    u32 value;
} __attribute__((packed)) unaligned_u32;

typedef struct frame_state
{
    char *augmentation;
    u32 eh_ptr;
    u32 code_align;
    s32 data_align;
    u32 retaddr_column;
} frame_state;

extern char D_00139350[];
extern char D_00139358[];

s32 strcmp(const char *s1, const char *s2);
u32 strlen(const char *s);
u8 *func_00125A98(u8 *p, u32 *out);
u8 *func_00125AE0(u8 *p, s32 *out);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", func_001267F0);
u8 *func_001267F0(dwarf_fde *fde, frame_state *state)
{
    u32 len;
    u8 *end;
    u8 *p;
    u32 size;

    state->augmentation = (char *)((u8 *)fde - fde->CIE_delta + 0xD);
    if (strcmp(state->augmentation, D_00139350) != 0 && strcmp(state->augmentation, D_00139358) != 0 && state->augmentation[0] != 'z')
    {
        return 0;
    }
    len = strlen(state->augmentation);
    end = (u8 *)state->augmentation + len;
    p = end + 1;
    if (strcmp(state->augmentation, D_00139358) == 0)
    {
        state->eh_ptr = ((unaligned_u32 *)p)->value;
        p += 4;
    }
    else
    {
        state->eh_ptr = 0;
    }
    p = func_00125A98(p, &state->code_align);
    p = func_00125AE0(p, &state->data_align);
    state->retaddr_column = *p;
    p++;
    if (state->augmentation[0] == 'z')
    {
        p = func_00125A98(p, &size);
        p += size;
    }
    return p;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", func_00126900);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", func_00126A20);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", __frame_state_for);

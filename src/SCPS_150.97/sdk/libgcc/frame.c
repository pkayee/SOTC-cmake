#include "common.h"

/* gcc 2.96 frame.c (DWARF 2 call frame unwinder), EE build. */

typedef int sword __attribute__((mode(SI)));
typedef unsigned int uword __attribute__((mode(SI)));
typedef unsigned int uaddr __attribute__((mode(pointer)));
typedef int saddr __attribute__((mode(pointer)));
typedef unsigned char ubyte;
typedef unsigned int size_t;

#define DWARF_FRAME_REGISTERS 122

typedef struct frame_state
{
    void *cfa;
    void *eh_ptr;
    long cfa_offset;
    long base_offset;
    long args_size;
    long reg_or_offset[DWARF_FRAME_REGISTERS + 1];
    unsigned short cfa_reg;
    unsigned short retaddr_column;
    char saved[DWARF_FRAME_REGISTERS + 1];
    char indirect;
} frame_state;

/* Values for 'saved' above.  */
#define REG_UNSAVED 0
#define REG_SAVED_OFFSET 1
#define REG_SAVED_REG 2

struct object
{
    void *pc_begin;
    void *pc_end;
    struct dwarf_fde *fde_begin;
    struct dwarf_fde **fde_array;
    size_t count;
    struct object *next;
};

enum dwarf_call_frame_info
{
    DW_CFA_advance_loc = 0x40,
    DW_CFA_offset = 0x80,
    DW_CFA_restore = 0xc0,
    DW_CFA_nop = 0x00,
    DW_CFA_set_loc = 0x01,
    DW_CFA_advance_loc1 = 0x02,
    DW_CFA_advance_loc2 = 0x03,
    DW_CFA_advance_loc4 = 0x04,
    DW_CFA_offset_extended = 0x05,
    DW_CFA_restore_extended = 0x06,
    DW_CFA_undefined = 0x07,
    DW_CFA_same_value = 0x08,
    DW_CFA_register = 0x09,
    DW_CFA_remember_state = 0x0a,
    DW_CFA_restore_state = 0x0b,
    DW_CFA_def_cfa = 0x0c,
    DW_CFA_def_cfa_register = 0x0d,
    DW_CFA_def_cfa_offset = 0x0e,
    DW_CFA_def_cfa_expression = 0x0f,

    /* SGI/MIPS specific */
    DW_CFA_MIPS_advance_loc8 = 0x1d,

    /* GNU extensions */
    DW_CFA_GNU_window_save = 0x2d,
    DW_CFA_GNU_args_size = 0x2e,
    DW_CFA_GNU_negative_offset_extended = 0x2f
};

enum dwarf_location_atom
{
    DW_OP_deref = 0x06,
    DW_OP_plus_uconst = 0x23,
    DW_OP_reg0 = 0x50,
    DW_OP_reg31 = 0x6f,
    DW_OP_breg0 = 0x70,
    DW_OP_breg31 = 0x8f,
    DW_OP_regx = 0x90,
    DW_OP_bregx = 0x92
};

/* The PS2 thread hooks: the mutex is a semaphore id.  */
typedef int __gthread_mutex_t;

int WaitSema(int sema);
int SignalSema(int sema);
void *malloc(size_t size);
void free(void *ptr);
void abort(void);
void *memset(void *s, int c, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
int strcmp(const char *s1, const char *s2);
size_t strlen(const char *s);

static inline int __gthread_mutex_lock(__gthread_mutex_t *mutex)
{
    return WaitSema(*mutex);
}

static inline int __gthread_mutex_unlock(__gthread_mutex_t *mutex)
{
    return SignalSema(*mutex);
}

#define init_object_mutex_once()

/* libgcc was built with -G0: its statics are outside small data, so they are
   declared here as unsized arrays (see objects below).  */
extern __gthread_mutex_t D_00132AA4[];
#define object_mutex (*D_00132AA4)

/* Some types used by the DWARF 2 spec.  */

struct dwarf_cie
{
    uword length;
    sword CIE_id;
    ubyte version;
    char augmentation[0];
} __attribute__((packed, aligned(__alignof__(void *))));

struct dwarf_fde
{
    uword length;
    sword CIE_delta;
    void *pc_begin;
    uaddr pc_range;
} __attribute__((packed, aligned(__alignof__(void *))));

typedef struct dwarf_fde fde;

/* Objects to be searched for frame unwind info.  */
extern struct object *D_0016A110[];
#define objects (*D_0016A110)

/* The information we care about from a CIE.  */

struct cie_info
{
    char *augmentation;
    void *eh_ptr;
    int code_align;
    int data_align;
    unsigned ra_regno;
};

/* The current unwind state, plus a saved copy for DW_CFA_remember_state.  */

struct frame_state_internal
{
    struct frame_state s;
    struct frame_state_internal *saved_state;
};

/* decode_uleb128 / decode_sleb128 (func_00125A98 / func_00125AE0) */
#define decode_uleb128 func_00125A98
#define decode_sleb128 func_00125AE0
void *decode_uleb128(unsigned char *buf, unsigned *r);
void *decode_sleb128(unsigned char *buf, int *r);

/* Read unaligned data from the instruction buffer.  */

union unaligned
{
    void *p;
    unsigned b2 __attribute__((mode(HI)));
    unsigned b4 __attribute__((mode(SI)));
    unsigned b8 __attribute__((mode(DI)));
} __attribute__((packed));

static inline void *read_pointer(void *p)
{
    union unaligned *up = p;
    return up->p;
}

static inline unsigned read_1byte(void *p)
{
    return *(unsigned char *)p;
}

static inline unsigned read_2byte(void *p)
{
    union unaligned *up = p;
    return up->b2;
}

static inline unsigned read_4byte(void *p)
{
    union unaligned *up = p;
    return up->b4;
}

static inline unsigned long read_8byte(void *p)
{
    union unaligned *up = p;
    return up->b8;
}

/* Return the address of the FDE after P.  */

static inline fde *next_fde(fde *p)
{
    return (fde *)(((char *)p) + p->length + sizeof(p->length));
}

typedef struct fde_vector
{
    fde **array;
    size_t count;
} fde_vector;

typedef struct fde_accumulator
{
    fde_vector linear;
    fde_vector erratic;
} fde_accumulator;

static inline int start_fde_sort(fde_accumulator *accu, size_t count)
{
    accu->linear.array = count ? (fde **)malloc(sizeof(fde *) * count) : NULL;
    accu->erratic.array = accu->linear.array ? (fde **)malloc(sizeof(fde *) * count) : NULL;
    accu->linear.count = 0;
    accu->erratic.count = 0;

    return accu->linear.array != NULL;
}

static inline void fde_insert(fde_accumulator *accu, fde *this_fde)
{
    if (accu->linear.array)
        accu->linear.array[accu->linear.count++] = this_fde;
}

/* end_fde_sort (func_00125C30) */
#define end_fde_sort func_00125C30
fde **end_fde_sort(fde_accumulator *accu, size_t count);

#define count_fdes func_001263B8
#define add_fdes func_001263F8
#define search_fdes func_00126488
#define frame_init func_001264E0
#define find_fde func_00126648
#define extract_cie_info func_001267F0
#define decode_stack_op func_00126900
#define execute_cfa_insn func_00126A20

size_t count_fdes(fde *this_fde);
void add_fdes(fde *this_fde, fde_accumulator *accu, void **beg_ptr, void **end_ptr);
fde *search_fdes(fde *this_fde, void *pc);
void frame_init(struct object *ob);
fde *find_fde(void *pc);
void *extract_cie_info(fde *f, struct cie_info *c);
void *decode_stack_op(unsigned char *buf, struct frame_state *state);
void *execute_cfa_insn(void *p, struct frame_state_internal *state, struct cie_info *info, void **pc);

void __register_frame_info(void *begin, struct object *ob);
void __register_frame_info_table(void *begin, struct object *ob);

/* Called from crtbegin.o to register the unwind info for an object.  */

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", __register_frame_info);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", __register_frame);
void __register_frame(void *begin)
{
    struct object *ob = (struct object *)malloc(sizeof(struct object));
    __register_frame_info(begin, ob);
}

/* Similar, but BEGIN is actually a pointer to a table of unwind entries
   for different translation units.  Called from the file generated by
   collect2.  */

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", __register_frame_info_table);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", __register_frame_table);
void __register_frame_table(void *begin)
{
    struct object *ob = (struct object *)malloc(sizeof(struct object));
    __register_frame_info_table(begin, ob);
}

/* Called from crtbegin.o to deregister the unwind info for an object.  */

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", __deregister_frame_info);
void *__deregister_frame_info(void *begin)
{
    struct object **p;

    init_object_mutex_once();
    __gthread_mutex_lock(&object_mutex);

    p = &objects;
    while (*p)
    {
        if ((*p)->fde_begin == begin)
        {
            struct object *ob = *p;
            *p = (*p)->next;

            /* If we've run init_frame for this object, free the FDE array.  */
            if (ob->fde_array && ob->fde_array != begin)
                free(ob->fde_array);

            __gthread_mutex_unlock(&object_mutex);
            return (void *)ob;
        }
        p = &((*p)->next);
    }

    __gthread_mutex_unlock(&object_mutex);
    abort();
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", __deregister_frame);
void __deregister_frame(void *begin)
{
    free(__deregister_frame_info(begin));
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", func_001263B8);
size_t count_fdes(fde *this_fde)
{
    size_t count;

    for (count = 0; this_fde->length != 0; this_fde = next_fde(this_fde))
    {
        /* Skip CIEs and linked once FDE entries.  */
        if (this_fde->CIE_delta == 0 || this_fde->pc_begin == 0)
            continue;

        ++count;
    }

    return count;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", func_001263F8);
void add_fdes(fde *this_fde, fde_accumulator *accu, void **beg_ptr, void **end_ptr)
{
    void *pc_begin = *beg_ptr;
    void *pc_end = *end_ptr;

    for (; this_fde->length != 0; this_fde = next_fde(this_fde))
    {
        /* Skip CIEs and linked once FDE entries.  */
        if (this_fde->CIE_delta == 0 || this_fde->pc_begin == 0)
            continue;

        fde_insert(accu, this_fde);

        if (this_fde->pc_begin < pc_begin)
            pc_begin = this_fde->pc_begin;
        if (this_fde->pc_begin + this_fde->pc_range > pc_end)
            pc_end = this_fde->pc_begin + this_fde->pc_range;
    }

    *beg_ptr = pc_begin;
    *end_ptr = pc_end;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", func_00126488);
fde *search_fdes(fde *this_fde, void *pc)
{
    for (; this_fde->length != 0; this_fde = next_fde(this_fde))
    {
        /* Skip CIEs and linked once FDE entries.  */
        if (this_fde->CIE_delta == 0 || this_fde->pc_begin == 0)
            continue;

        if ((uaddr)((char *)pc - (char *)this_fde->pc_begin) < this_fde->pc_range)
            return this_fde;
    }
    return NULL;
}

/* Set up a sorted array of pointers to FDEs for a loaded object.  We
   count up the entries before allocating the array because it's likely to
   be faster.  We can be called multiple times, should we have failed to
   allocate a sorted fde array on a previous occasion.  */

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", func_001264E0);
void frame_init(struct object *ob)
{
    size_t count;
    fde_accumulator accu;
    void *pc_begin, *pc_end;
    fde **array;

    if (ob->pc_begin)
        count = ob->count;
    else if (ob->fde_array)
    {
        fde **p = ob->fde_array;
        for (count = 0; *p; ++p)
            count += count_fdes(*p);
    }
    else
        count = count_fdes(ob->fde_begin);
    ob->count = count;

    if (!start_fde_sort(&accu, count) && ob->pc_begin)
        return;

    pc_begin = (void *)(uaddr)-1;
    pc_end = 0;

    if (ob->fde_array)
    {
        fde **p = ob->fde_array;
        for (; *p; ++p)
            add_fdes(*p, &accu, &pc_begin, &pc_end);
    }
    else
        add_fdes(ob->fde_begin, &accu, &pc_begin, &pc_end);

    array = end_fde_sort(&accu, count);
    if (array)
        ob->fde_array = array;
    ob->pc_begin = pc_begin;
    ob->pc_end = pc_end;
}

/* Return a pointer to the FDE for the function containing PC.  */

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", func_00126648);
fde *find_fde(void *pc)
{
    struct object *ob;
    size_t lo, hi;

    init_object_mutex_once();
    __gthread_mutex_lock(&object_mutex);

    /* Linear search through the objects, to find the one containing the pc. */
    for (ob = objects; ob; ob = ob->next)
    {
        if (ob->pc_begin == 0)
            frame_init(ob);
        if (pc >= ob->pc_begin && pc < ob->pc_end)
            break;
    }

    if (ob == 0)
    {
        __gthread_mutex_unlock(&object_mutex);
        return 0;
    }

    if (!ob->fde_array || (void *)ob->fde_array == (void *)ob->fde_begin)
        frame_init(ob);

    if (ob->fde_array && (void *)ob->fde_array != (void *)ob->fde_begin)
    {
        __gthread_mutex_unlock(&object_mutex);

        /* Standard binary search algorithm.  */
        for (lo = 0, hi = ob->count; lo < hi;)
        {
            size_t i = (lo + hi) / 2;
            fde *f = ob->fde_array[i];

            if (pc < f->pc_begin)
                hi = i;
            else if (pc >= f->pc_begin + f->pc_range)
                lo = i + 1;
            else
                return f;
        }
    }
    else
    {
        /* Long slow labourious linear search, cos we've no memory.  */
        fde *f;

        if (ob->fde_array)
        {
            fde **p = ob->fde_array;

            do
            {
                f = search_fdes(*p, pc);
                if (f)
                    break;
                p++;
            } while (*p);
        }
        else
            f = search_fdes(ob->fde_begin, pc);
        __gthread_mutex_unlock(&object_mutex);
        return f;
    }
    return 0;
}

static inline struct dwarf_cie *get_cie(fde *f)
{
    return ((void *)&f->CIE_delta) - f->CIE_delta;
}

/* Extract any interesting information from the CIE for the translation
   unit F belongs to.  */

/* The strings "" and "eh" live in the SDK .rodata.  */
extern char D_00139350[];
extern char D_00139358[];

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", func_001267F0);
void *extract_cie_info(fde *f, struct cie_info *c)
{
    void *p;
    int i;

    c->augmentation = get_cie(f)->augmentation;

    if (strcmp(c->augmentation, D_00139350) != 0 && strcmp(c->augmentation, D_00139358) != 0 && c->augmentation[0] != 'z')
        return 0;

    p = c->augmentation + strlen(c->augmentation) + 1;

    if (strcmp(c->augmentation, D_00139358) == 0)
    {
        c->eh_ptr = read_pointer(p);
        p += sizeof(void *);
    }
    else
        c->eh_ptr = 0;

    p = decode_uleb128(p, &c->code_align);
    p = decode_sleb128(p, &c->data_align);
    c->ra_regno = *(unsigned char *)p++;

    /* If the augmentation starts with 'z', we now see the length of the
       augmentation fields.  */
    if (c->augmentation[0] == 'z')
    {
        p = decode_uleb128(p, &i);
        p += i;
    }

    return p;
}

/* Decode a DW_OP stack operation.  */

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", func_00126900);
void *decode_stack_op(unsigned char *buf, struct frame_state *state)
{
    enum dwarf_location_atom op;
    int offset;

    op = *buf++;
    switch (op)
    {
    case DW_OP_reg0 ... DW_OP_reg31:
        state->cfa_reg = op - DW_OP_reg0;
        break;
    case DW_OP_regx:
        buf = decode_sleb128(buf, &offset);
        state->cfa_reg = offset;
    case DW_OP_breg0 ... DW_OP_breg31:
        state->cfa_reg = op - DW_OP_breg0;
        buf = decode_sleb128(buf, &offset);
        state->base_offset = offset;
        break;
    case DW_OP_bregx:
        buf = decode_sleb128(buf, &offset);
        state->cfa_reg = offset;
        buf = decode_sleb128(buf, &offset);
        state->base_offset = offset;
        break;
    case DW_OP_deref:
        state->indirect = 1;
        break;
    case DW_OP_plus_uconst:
        buf = decode_uleb128(buf, &offset);
        state->cfa_offset = offset;
        break;
    default:
        abort();
    }
    return buf;
}

/* Decode one instruction's worth of DWARF 2 call frame information.
   Used by __frame_state_for.  Takes pointers P to the instruction to
   decode, STATE to the current register unwind information, INFO to the
   current CIE information, and PC to the current PC value.  Returns a
   pointer to the next instruction.  */

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", func_00126A20);

/* Called from __throw to find the registers to restore for a given
   PC_TARGET.  The caller should allocate a local variable of `struct
   frame_state' (declared in frame.h) and pass its address to STATE_IN.  */

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libgcc/frame", __frame_state_for);
struct frame_state *__frame_state_for(void *pc_target, struct frame_state *state_in)
{
    fde *f;
    void *insn, *end, *pc;
    struct cie_info info;
    struct frame_state_internal state;

    f = find_fde(pc_target);
    if (f == 0)
        return 0;

    insn = extract_cie_info(f, &info);
    if (insn == 0)
        return 0;

    memset(&state, 0, sizeof(state));
    state.s.retaddr_column = info.ra_regno;
    state.s.eh_ptr = info.eh_ptr;

    /* First decode all the insns in the CIE.  */
    end = next_fde((fde *)get_cie(f));
    while (insn < end)
        insn = execute_cfa_insn(insn, &state, &info, 0);

    insn = ((fde *)f) + 1;

    if (info.augmentation[0] == 'z')
    {
        int i;
        insn = decode_uleb128(insn, &i);
        insn += i;
    }

    /* Then the insns in the FDE up to our target PC.  */
    end = next_fde(f);
    pc = f->pc_begin;
    while (insn < end && pc <= pc_target)
        insn = execute_cfa_insn(insn, &state, &info, &pc);

    memcpy(state_in, &state.s, sizeof(state.s));
    return state_in;
}

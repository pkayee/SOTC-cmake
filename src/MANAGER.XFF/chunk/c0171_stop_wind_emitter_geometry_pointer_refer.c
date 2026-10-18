#include "common.h"

extern int *D_401AD640[];
extern char D_4012BA68[];
extern char D_401AD780[];

typedef struct {
    int a;
    int b;
    int c;
    int d;
    int e;
    void *data;
} WindEffectData;

static inline int is_valid_emitter_id(unsigned int i)
{
    return i < 80;
}

int stop_wind_emitter_geometry_pointer_reference(unsigned int i)
{
    int *e = is_valid_emitter_id(i) == 1 ? D_401AD640[i] : 0;
    if (e != 0) {
        e[2] = 0;
        if (e[0] == 2)
            e[64] = 0;
        return 1;
    }
    return 0;
}

int stop_wind_emitter_callback(unsigned int i)
{
    char *e = is_valid_emitter_id(i) == 1 ? (char *)D_401AD640[i] : 0;
    if (e != 0) {
        *(int *)(e + 0xF0) = 0;
        return 1;
    }
    return 0;
}

int end_wind_emitter(unsigned int i)
{
    char *e = is_valid_emitter_id(i) == 1 ? (char *)D_401AD640[i] : 0;
    if (e != 0) {
        *(int *)(e + 0xA0) = 0;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0171_stop_wind_emitter_geometry_pointer_refer", GetWindVector);

void constructor_wind_effect_data(WindEffectData *w)
{
    w->a = 0;
    w->b = 0;
    w->c = 0;
    w->d = 0;
    w->e = 0;
    w->data = D_4012BA68;
}

int is_ambient_directional_wind_emitter(void *arg0)
{
    return (*(int *)((char *)((*(void **)((char *)(arg0) + 4))) + 4)) == 0;
}

int get_wind_emitter_direct(int i)
{
    return ((int *)D_401AD640)[i];
}

int get_wind_effect_data_direct(int i)
{
    return ((int *)D_401AD780)[i];
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0171_stop_wind_emitter_geometry_pointer_refer", func_400D8598);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0171_stop_wind_emitter_geometry_pointer_refer", func_400D85E8);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0171_stop_wind_emitter_geometry_pointer_refer", func_400D8638);

extern int func_400D8A78();

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0171_stop_wind_emitter_geometry_pointer_refer", func_400D8688);
int func_400D8688(int a, int b, int c, int d)
{
    return func_400D8A78(a, 0, c, d);
}

extern int func_400D7650();

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0171_stop_wind_emitter_geometry_pointer_refer", func_400D86A0);
int func_400D86A0(int a, int b, int c, int d)
{
    return func_400D7650(a, 0, c, d);
}

//INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0171_stop_wind_emitter_geometry_pointer_refer", func_400D86B8);
extern int func_400D8BD0();

int func_400D86B8(int a)
{
    return func_400D8BD0(a, 0);
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0171_stop_wind_emitter_geometry_pointer_refer", func_400D86D0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0171_stop_wind_emitter_geometry_pointer_refer", func_400D87E0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0171_stop_wind_emitter_geometry_pointer_refer", func_400D88E0);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0171_stop_wind_emitter_geometry_pointer_refer", func_400D8998);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0171_stop_wind_emitter_geometry_pointer_refer", func_400D8A78);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0171_stop_wind_emitter_geometry_pointer_refer", func_400D8BD0);

void add_wind_segment(void) {
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0171_stop_wind_emitter_geometry_pointer_refer", free_wind_segment);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0171_stop_wind_emitter_geometry_pointer_refer", FlushModifiedManagerCB);

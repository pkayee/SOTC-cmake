#include "common.h"

extern int D_40218510;
extern int D_40218514;

int get_main_cameraman(void)
{
    return (*(int *)((char *)(&(&D_40218510)[D_40218510]) + 8));
}

struct CameraSelectionView {
    int selected;
    char pad04[4];
    void *managers[0];
};

extern void *get_camera_obj(void *);

void *get_main_cameraman_camera_obj(void)
{
    return get_camera_obj(((struct CameraSelectionView *)&D_40218510)->managers[((struct CameraSelectionView *)&D_40218510)->selected]);
}

extern void *D_40218518[];
extern void func_400EBD98();

void *get_cameraman(int i)
{
    func_400EBD98(i);
    return D_40218518[i];
}

void *get_cameraman_camera_obj(int i)
{
    func_400EBD98(i);
    return get_camera_obj(D_40218518[i]);
}

/* NEARMISS-STUB employ_cameraman */
#if 0 /* NEARMISS 73.0% cat=no-c-form sub=- | missing break 0 (trap) tail; regalloc view/p regs a3/a2 vs a2/v1 | attempts=1 */
int employ_cameraman(void *param_1)
{
    int i;
    void **p;
    int *view;

    i = 0;
    view = (int *)&D_40218510;
    p = (void **)(view + 2);
    do {
        if (*p == 0) {
            *p = param_1;
            view[1] += 1;
            return i;
        }
        i++;
        p++;
    } while (i < 5);
    return -1;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0183_get_main_cameraman", employ_cameraman);

void change_main_cameraman(int arg0)
{
    func_400EBD98();
    D_40218510 = arg0;
}

int get_main_cameraman_id(void)
{
    return D_40218510;
}

int is_main_cameraman_exist(void)
{
    return ~D_40218510 != 0;
}

int get_total_cameraman(void)
{
    return D_40218514;
}

int get_max_cameraman(void)
{
    return 5;
}

void func_400EBD98(void) {
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0183_get_main_cameraman", doit_debug_camera);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0183_get_main_cameraman", DebugGetCameraWithManual);

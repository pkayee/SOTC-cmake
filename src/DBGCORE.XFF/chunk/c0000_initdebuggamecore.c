#include "common.h"

extern s32 rootPtn;
s32 createScriptObj();
void func_400116E0();

void func_40011838();

void func_40011348();

void func_40011510();

extern u8 gcGlobalVar[];
extern s32 D_40018F10;
s32 loadToolModule();
void unloadToolModule();
void scrRun();
s32 modelToolWithoutDeleteRequest();

s32 modelToolDisplayOnly();

extern s32 D_40018F14;
s32 texTool();

s32 texToolDisplayOnly();

extern s32 D_40018F18;
s32 create_particle_menu();
void doit_particle_customize_mode();
void disp_particle_customize_mode();

extern s32 D_40018F1C;
s32 initPathTool();
void drawPathData(float);
void deleteDataForPathTool();

extern s32 D_40018F20;
s32 create_game_light_param_menu();

extern s32 D_40018F24;
s32 create_global_light_param_menu();

extern s32 D_40018F28;
s32 create_fog_col_param_menu();

extern s32 D_40018F2C;
s32 createLightParamMenu();

extern s32 D_40018F30;
s32 swordEffectTool();

extern s32 D_40018F34;
s32 fullScreenEffectTool();

extern s32 D_40018F38;
s32 createLayerMenu();

extern s32 D_40018F3C;
void scrRunM();
s32 CreateMapWindow();

extern s32 D_40018F40;
s32 create_cameraman_menu();
void doit_cameraman_tool(float);
void disp_cameraman_tool();

extern s32 D_40018F44;
s32 create_wind_param_menu();
void doit_wind_tool_mode();
void disp_wind_tool_mode();

extern s32 D_40018F48;
s32 create_collision_menu();
void doit_collision_tool(float);
void disp_collision_tool();

extern s32 D_40018F4C;
s32 create_script_anim_param_menu();
void *get_main_cameraman_camera_obj(void);
void *get_camera_position(void *);
void GetStageCenter(void *, void *);
void doit_script_anim_tool();
void disp_script_anim_tool();

extern s32 D_40018F50;
s32 create_sheet_edit_menu();
void doit_sheet_edit_tool(float);
void disp_sheet_edit_tool();

s32 initdebuggamecore(void)
{
    return 0;
}

/* NEARMISS-STUB modelToolBegin */
#if 0 /* NEARMISS 0.0% cat=regalloc sub=- | REA READY drop-in scored -1.00 in-TU (apply_ready) | attempts=1 */
void modelToolBegin(void)
{
    createScriptObj(func_40010E60, 0, &rootPtn, 0x4000, 0, 1, 0, 0);
}
#endif
INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0000_initdebuggamecore", modelToolBegin);

/* NEARMISS-STUB modelTool2Begin */
#if 0 /* NEARMISS 0.0% cat=regalloc sub=- | REA READY drop-in scored -1.00 in-TU (apply_ready) | attempts=1 */
void modelTool2Begin(void)
{
    createScriptObj(func_40010EF8, 0, &rootPtn, 0x4000, 0, 1, 0, 0);
}
#endif
INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0000_initdebuggamecore", modelTool2Begin);

/* NEARMISS-STUB texToolBegin */
#if 0 /* NEARMISS 0.0% cat=regalloc sub=- | REA READY drop-in scored -1.00 in-TU (apply_ready) | attempts=1 */
void texToolBegin(void)
{
    createScriptObj(func_40010F90, 0, &rootPtn, 0x4000, 0, 1, 0, 0);
}
#endif
INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0000_initdebuggamecore", texToolBegin);

/* NEARMISS-STUB texTool2Begin */
#if 0 /* NEARMISS 0.0% cat=regalloc sub=- | REA READY drop-in scored -1.00 in-TU (apply_ready) | attempts=1 */
void texTool2Begin(void)
{
    createScriptObj(func_40011028, 0, &rootPtn, 0x4000, 0, 1, 0, 0);
}
#endif
INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0000_initdebuggamecore", texTool2Begin);

/* NEARMISS-STUB particleToolBegin */
#if 0 /* NEARMISS 0.0% cat=regalloc sub=- | REA READY drop-in scored -1.00 in-TU (apply_ready) | attempts=1 */
void particleToolBegin(void)
{
    createScriptObj(func_400110C0, 0, &rootPtn, 0x4000, 0, 8, 0, 0);
}
#endif
INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0000_initdebuggamecore", particleToolBegin);

/* NEARMISS-STUB pathToolBegin */
#if 0 /* NEARMISS 0.0% cat=regalloc sub=- | REA READY drop-in scored -1.00 in-TU (apply_ready) | attempts=1 */
void pathToolBegin(void)
{
    createScriptObj(func_40011168, 0, &rootPtn, 0x4000, 0, 8, 0, 0);
}
#endif
INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0000_initdebuggamecore", pathToolBegin);

/* NEARMISS-STUB gameLightToolBegin */
#if 0 /* NEARMISS 0.0% cat=regalloc sub=- | REA READY drop-in scored -1.00 in-TU (apply_ready) | attempts=1 */
void gameLightToolBegin(void)
{
    createScriptObj(func_40011218, 0, &rootPtn, 0x4000, 0, 8, 0, 0);
}
#endif
INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0000_initdebuggamecore", gameLightToolBegin);

/* NEARMISS-STUB globalLightToolBegin */
#if 0 /* NEARMISS 0.0% cat=regalloc sub=- | REA READY drop-in scored -1.00 in-TU (apply_ready) | attempts=1 */
void globalLightToolBegin(void)
{
    createScriptObj(func_400112B0, 0, &rootPtn, 0x4000, 0, 8, 0, 0);
}
#endif
INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0000_initdebuggamecore", globalLightToolBegin);

void fogCollisionToolBegin(void)
{
    createScriptObj(func_40011348, 0, &rootPtn, 0x4000, 0, 8, 0, 0);
}

/* NEARMISS-STUB lightToolBegin */
#if 0 /* NEARMISS 0.0% cat=regalloc sub=- | REA READY drop-in scored -1.00 in-TU (apply_ready) | attempts=1 */
void lightToolBegin(void)
{
    createScriptObj(func_400113E0, 0, &rootPtn, 0x4000, 0, 8, 0, 0);
}
#endif
INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0000_initdebuggamecore", lightToolBegin);

/* NEARMISS-STUB swordEffectToolBegin */
#if 0 /* NEARMISS 0.0% cat=regalloc sub=- | REA READY drop-in scored -1.00 in-TU (apply_ready) | attempts=1 */
void swordEffectToolBegin(void)
{
    createScriptObj(func_40011478, 0, &rootPtn, 0x4000, 0, 8, 0, 0);
}
#endif
INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0000_initdebuggamecore", swordEffectToolBegin);

void fullScreenEffectToolBegin(void)
{
    createScriptObj(func_40011510, 0, &rootPtn, 0x4000, 0, 8, 0, 0);
}

/* NEARMISS-STUB layerDebugToolBegin */
#if 0 /* NEARMISS 0.0% cat=regalloc sub=- | REA READY drop-in scored -1.00 in-TU (apply_ready) | attempts=1 */
void layerDebugToolBegin(void)
{
    createScriptObj(func_400115A8, 0, &rootPtn, 0x4000, 0, 8, 0, 0);
}
#endif
INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0000_initdebuggamecore", layerDebugToolBegin);

/* NEARMISS-STUB mapToolBegin */
#if 0 /* NEARMISS 0.0% cat=regalloc sub=- | REA READY drop-in scored -1.00 in-TU (apply_ready) | attempts=1 */
void mapToolBegin(void)
{
    createScriptObj(func_40011640, 0, &rootPtn, 0x4000, 0, 8, 0, 0);
}
#endif
INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0000_initdebuggamecore", mapToolBegin);

void cameramanToolBegin(void)
{
    createScriptObj(func_400116E0, 0, &rootPtn, 0x4000, 0, 8, 0, 0);
}

/* NEARMISS-STUB windToolBegin */
#if 0 /* NEARMISS 0.0% cat=regalloc sub=- | REA READY drop-in scored -1.00 in-TU (apply_ready) | attempts=1 */
void windToolBegin(void)
{
    createScriptObj(func_40011790, 0, &rootPtn, 0x4000, 0, 8, 0, 0);
}
#endif
INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0000_initdebuggamecore", windToolBegin);

void collisionToolBegin(void)
{
    createScriptObj(func_40011838, 0, &rootPtn, 0x4000, 0, 8, 0, 0);
}

/* NEARMISS-STUB scriptAnimToolBegin */
#if 0 /* NEARMISS 0.0% cat=regalloc sub=- | REA READY drop-in scored -1.00 in-TU (apply_ready) | attempts=1 */
void scriptAnimToolBegin(void)
{
    createScriptObj(func_400118E8, 0, &rootPtn, 0x4000, 0, 8, 0, 0);
}
#endif
INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0000_initdebuggamecore", scriptAnimToolBegin);

/* NEARMISS-STUB sheetEditToolBegin */
#if 0 /* NEARMISS 0.0% cat=regalloc sub=- | REA READY drop-in scored -1.00 in-TU (apply_ready) | attempts=1 */
void sheetEditToolBegin(void)
{
    createScriptObj(func_400119B8, 0, &rootPtn, 0x4000, 0, 8, 0, 0);
}
#endif
INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0000_initdebuggamecore", sheetEditToolBegin);

void func_40010E60(void)
{
    s32 *p;

    if (D_40018F10 == 0) {
        if (loadToolModule(1, 0) != 0) {
            p = (s32 *)modelToolWithoutDeleteRequest(&gcGlobalVar[0x1CC]);
            D_40018F10 = 1;
            if (p != 0) {
                while (*p != 0) {
                    scrRun();
                }
            }
            unloadToolModule(1);
        }
        D_40018F10 = 0;
    }
}

void func_40010EF8(void)
{
    s32 *p;

    if (D_40018F10 == 0) {
        if (loadToolModule(1, 0) != 0) {
            p = (s32 *)modelToolDisplayOnly(&gcGlobalVar[0x1CC]);
            D_40018F10 = 1;
            if (p != 0) {
                while (*p != 0) {
                    scrRun();
                }
            }
            unloadToolModule(1);
        }
        D_40018F10 = 0;
    }
}

void func_40010F90(void)
{
    s32 *p;

    if (D_40018F14 == 0) {
        if (loadToolModule(1, 0) != 0) {
            p = (s32 *)texTool(0, 0, 0);
            D_40018F14 = 1;
            if (p != 0) {
                while (*p != 0) {
                    scrRun();
                }
            }
            unloadToolModule(1);
        }
        D_40018F14 = 0;
    }
}

void func_40011028(void)
{
    s32 *p;

    if (D_40018F14 == 0) {
        if (loadToolModule(1, 0) != 0) {
            p = (s32 *)texToolDisplayOnly(0, 0);
            D_40018F14 = 1;
            if (p != 0) {
                while (*p != 0) {
                    scrRun();
                }
            }
            unloadToolModule(1);
        }
        D_40018F14 = 0;
    }
}

void func_400110C0(void)
{
    s32 *p;

    if (D_40018F18 == 0) {
        if (loadToolModule(2, 0) != 0) {
            p = (s32 *)create_particle_menu(0);
            D_40018F18 = 1;
            if (p != 0) {
                while (*p != 0) {
                    doit_particle_customize_mode();
                    disp_particle_customize_mode();
                    scrRun();
                }
            }
            unloadToolModule(2);
        }
        D_40018F18 = 0;
    }
}

void func_40011168(void)
{
    s32 *p;
    u8 *g;

    if (D_40018F1C == 0) {
        if (loadToolModule(3, 0) != 0) {
            p = (s32 *)initPathTool(0, 0, 0);
            D_40018F1C = 1;
            if (p != 0 && *p != 0) {
                g = gcGlobalVar;
                do {
                    drawPathData(*(float *)(g + 0x168));
                    scrRun();
                } while (*p != 0);
            }
            deleteDataForPathTool();
            unloadToolModule(3);
        }
        D_40018F1C = 0;
    }
}

void func_40011218(void)
{
    s32 *p;

    if (D_40018F20 == 0) {
        if (loadToolModule(0, 0) != 0) {
            p = (s32 *)create_game_light_param_menu(0, 0, 0);
            D_40018F20 = 1;
            if (p != 0) {
                while (*p != 0) {
                    scrRun();
                }
            }
            unloadToolModule(0);
        }
        D_40018F20 = 0;
    }
}

void func_400112B0(void)
{
    s32 *p;

    if (D_40018F24 == 0) {
        if (loadToolModule(0, 0) != 0) {
            p = (s32 *)create_global_light_param_menu(0, 0, 0);
            D_40018F24 = 1;
            if (p != 0) {
                while (*p != 0) {
                    scrRun();
                }
            }
            unloadToolModule(0);
        }
        D_40018F24 = 0;
    }
}

void func_40011348(void)
{
    s32 *p;

    if (D_40018F28 == 0) {
        if (loadToolModule(0, 0) != 0) {
            p = (s32 *)create_fog_col_param_menu(0, 0, 0);
            D_40018F28 = 1;
            if (p != 0) {
                while (*p != 0) {
                    scrRun();
                }
            }
            unloadToolModule(0);
        }
        D_40018F28 = 0;
    }
}

void func_400113E0(void)
{
    s32 *p;

    if (D_40018F2C == 0) {
        if (loadToolModule(0, 0) != 0) {
            p = (s32 *)createLightParamMenu(0, 0, 0);
            D_40018F2C = 1;
            if (p != 0) {
                while (*p != 0) {
                    scrRun();
                }
            }
            unloadToolModule(0);
        }
        D_40018F2C = 0;
    }
}

void func_40011478(void)
{
    s32 *p;

    if (D_40018F30 == 0) {
        if (loadToolModule(0, 0) != 0) {
            p = (s32 *)swordEffectTool(0, 0, 0);
            D_40018F30 = 1;
            if (p != 0) {
                while (*p != 0) {
                    scrRun();
                }
            }
            unloadToolModule(0);
        }
        D_40018F30 = 0;
    }
}

void func_40011510(void)
{
    s32 *p;

    if (D_40018F34 == 0) {
        if (loadToolModule(0, 0) != 0) {
            p = (s32 *)fullScreenEffectTool(0, 0, 0);
            D_40018F34 = 1;
            if (p != 0) {
                while (*p != 0) {
                    scrRun();
                }
            }
            unloadToolModule(0);
        }
        D_40018F34 = 0;
    }
}

void func_400115A8(void)
{
    s32 *p;

    if (D_40018F38 == 0) {
        if (loadToolModule(0, 0) != 0) {
            p = (s32 *)createLayerMenu(0, 0, 0);
            D_40018F38 = 1;
            if (p != 0) {
                while (*p != 0) {
                    scrRun();
                }
            }
            unloadToolModule(0);
        }
        D_40018F38 = 0;
    }
}

void func_40011640(void)
{
    s32 *p;

    if (D_40018F3C == 0) {
        if (loadToolModule(4, 0) != 0) {
            D_40018F3C = 1;
            scrRunM(0x3c);
            p = (s32 *)CreateMapWindow();
            if (p != 0) {
                while (*p != 0) {
                    scrRun();
                }
            }
            unloadToolModule(4);
        }
        D_40018F3C = 0;
    }
}

void func_400116E0(void)
{
    s32 *p;
    u8 *g;

    if (D_40018F40 == 0) {
        if (loadToolModule(5, 0) != 0) {
            p = (s32 *)create_cameraman_menu(0, 0, 0);
            D_40018F40 = 1;
            if (p != 0 && *p != 0) {
                g = gcGlobalVar;
                do {
                    doit_cameraman_tool(*(float *)(g + 0x180));
                    disp_cameraman_tool();
                    scrRun();
                } while (*p != 0);
            }
            unloadToolModule(5);
        }
        D_40018F40 = 0;
    }
}

void func_40011790(void)
{
    s32 *p;

    if (D_40018F44 == 0) {
        if (loadToolModule(6, 0) != 0) {
            p = (s32 *)create_wind_param_menu(0);
            D_40018F44 = 1;
            if (p != 0) {
                while (*p != 0) {
                    doit_wind_tool_mode();
                    disp_wind_tool_mode();
                    scrRun();
                }
            }
            unloadToolModule(6);
        }
        D_40018F44 = 0;
    }
}

void func_40011838(void)
{
    s32 *p;
    u8 *g;

    if (D_40018F48 == 0) {
        if (loadToolModule(7, 0) != 0) {
            p = (s32 *)create_collision_menu(0, 0, 0);
            D_40018F48 = 1;
            if (p != 0 && *p != 0) {
                g = gcGlobalVar;
                do {
                    doit_collision_tool(*(float *)(g + 0x180));
                    disp_collision_tool();
                    scrRun();
                } while (*p != 0);
            }
            unloadToolModule(7);
        }
        D_40018F48 = 0;
    }
}

void func_400118E8(void)
{
    s32 *p;
    float pos[4];
    float center[4];

    if (D_40018F4C == 0) {
        if (loadToolModule(8, 0) != 0) {
            p = (s32 *)create_script_anim_param_menu(0, 0, 0);
            D_40018F4C = 1;
            while (p != 0) {
                *(s128 *)pos = *(s128 *)get_camera_position(get_main_cameraman_camera_obj());
                GetStageCenter(&center, &pos);
                if (*p == 0) {
                    break;
                }
                doit_script_anim_tool(&center);
                disp_script_anim_tool();
                scrRun();
            }
            unloadToolModule(8);
        }
        D_40018F4C = 0;
    }
}

void func_400119B8(void)
{
    s32 *p;
    u8 *g;

    if (D_40018F50 == 0) {
        if (loadToolModule(9, 0) != 0) {
            p = (s32 *)create_sheet_edit_menu(0, 0, 0);
            D_40018F50 = 1;
            if (p != 0 && *p != 0) {
                g = gcGlobalVar;
                do {
                    doit_sheet_edit_tool(*(float *)(g + 0x180));
                    disp_sheet_edit_tool();
                    scrRun();
                } while (*p != 0);
            }
            unloadToolModule(9);
        }
        D_40018F50 = 0;
    }
}

INCLUDE_ASM("asm/DBGCORE.XFF/nonmatchings/chunk/c0000_initdebuggamecore", func_40011A68);

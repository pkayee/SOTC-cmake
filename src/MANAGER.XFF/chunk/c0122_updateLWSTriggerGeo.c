#include "common.h"

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0122_updateLWSTriggerGeo", updateLWSTriggerGeo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0122_updateLWSTriggerGeo", updateLightGeo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0122_updateLWSTriggerGeo", updateParticleDissolveGeo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0122_updateLWSTriggerGeo", update_camera_region_geometry);

extern int ExecEff();

int kickEffect(int a, int b, int c, int d)
{
    return ExecEff(a, b, c, d);
}

extern int SequenceKickParticle();

int kickParticle(int a, int b, int c, int d, int e)
{
    return SequenceKickParticle(a, e);
}

extern int KickParticleGetResourceId(char *);
extern int set_generate_particle_flag(int, int, int);

int particleOnOff(char *name, int a, int b)
{
    if (name == 0)
        return 0;
    return set_generate_particle_flag(a, KickParticleGetResourceId(name), b);
}

extern int strcmp(const char *, const char *);

typedef struct
{
    int word0;
    char *name;
    int word8;
} SubObjectName;

typedef struct
{
    void *object;
    int value;
} SubObject;

typedef struct
{
    char pad[0x10];
    SubObjectName *names;
} NameResource;

typedef struct
{
    char pad[0x328];
    int *counts;
    int word32c;
    int word330;
    NameResource *names;
    SubObject *children;
} ScriptAnimation;

static inline ScriptAnimation *getScriptAnimation(unsigned char *object)
{
    if (object[8] == 13)
    {
        return (ScriptAnimation *)(object + 0x20);
    }
    return 0;
}

void *GetScriptAnimationObjChildObjWithName(unsigned char *object, const char *name)
{
    ScriptAnimation *animation = getScriptAnimation(object);
    int *counts = animation->counts;
    int i = 0;

    if (*counts > 0)
    {
        int offset = 0;

        do
        {
            SubObjectName *entry = (SubObjectName *)(offset + (int)animation->names->names);

            if (strcmp(entry->name, name) == 0)
            {
                return animation->children[i].object;
            }
            offset += 12;
            ++i;
        } while (i < *counts);
    }
    return 0;
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0122_updateLWSTriggerGeo", updateGameLightGeo);

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0122_updateLWSTriggerGeo", updateClipGameLightGeo);

int IsNonISysObjTypeRes(int t)
{
    switch (t) {
    case 15 ... 28:
    case 32 ... 35:
        return 1;
    }
    return 0;
}

extern void DeleteCollMan(void *);
extern void DeleteGlobalLight(void *);
extern void DeleteGameLight(void *);

void SubCallDeleteFuncNonISysObjTypeRes(void *o, int type)
{
    switch (type) {
    case 15:
    case 16:
        break;
    case 17:
        DeleteCollMan(o);
        break;
    case 24:
        DeleteGlobalLight(o);
        break;
    case 27:
    case 28:
    case 33:
    case 34:
    case 35:
        DeleteGameLight(o);
        o = 0;
        break;
    }
}

INCLUDE_ASM("asm/MANAGER.XFF/nonmatchings/chunk/c0122_updateLWSTriggerGeo", EntryScriptAnimationObjJudgeVolumeGroup);

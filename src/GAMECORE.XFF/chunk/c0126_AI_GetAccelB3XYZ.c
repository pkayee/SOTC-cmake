#include "common.h"

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0126_AI_GetAccelB3XYZ", AI_GetAccelB3XYZ);

float AI_GetAccelC3(float fparg0, float fparg1, float fparg2, float fparg3, float fparg4, float fparg5)
{
    float var_f17;

    var_f17 = fparg5;
    if (var_f17 < 0.0333667f) {
        var_f17 = 0.0333667f;
    }
    return ((((12.0f / var_f17) * (fparg3 - fparg2)) - ((fparg1 + fparg0) * 6.0f)) + (fparg4 * var_f17)) / var_f17;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0126_AI_GetAccelB3XYZ", AI_GetAccelC3XYZ);

/* NEARMISS-STUB AI_GetTimeFromAccelC3 */
#if 0 /* NEARMISS 39.56% cat=no-c-form sub=- | ee-gcc emits sqrt NaN check + jal sqrtf; target inline sqrt.s leaf, no frame | attempts=1 */
float AI_GetTimeFromAccelC3(float fparg0, float fparg1, float fparg2, float fparg3)
{
    float fVar1;
    float fVar2;

    if (fparg3 < 0.1f) {
        fparg3 = 0.1f;
    }
    fparg1 = fparg1 + fparg0;
    fVar1 = 0.0f;
    if (fparg2 < 0.0f) {
        fparg2 = -fparg2;
    }
    fVar2 = fparg1 * 9.0f * fparg1 + fparg3 * 12.0f * fparg2;
    if (0.0f <= fVar2) {
        fVar1 = (fparg1 * -3.0f + __builtin_sqrtf(fVar2)) / fparg3;
    }
    return fVar1;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0126_AI_GetAccelB3XYZ", AI_GetTimeFromAccelC3);

float AI_GetVelocity2(float fparg0, float fparg1, float fparg2, float fparg3)
{
    return fparg2 + (fparg0 * 0.5f * fparg3 * fparg3) + (fparg1 * fparg3);
}

float AI_GetVelocity3(float fparg0, float fparg1, float fparg2, float fparg3, float fparg4)
{
    return fparg3 + ((fparg0 / 3.0f) * fparg4 * fparg4 * fparg4) + (fparg1 * 0.5f * fparg4 * fparg4) + (fparg2 * fparg4);
}

/* NEARMISS-STUB AI_GetVelocity3XYZ */
#if 0 /* NEARMISS 6.125% cat=vu0-mmi sub=- | VU0 lqc2/qmtc2.ni/vmulx/vadd/sqc2 body; plain float C cannot emit VU0 | attempts=1 */

void AI_GetVelocity3XYZ(float t, float *out, float *a1, float *a2, float *a3, float *a4)
{
    float v0;
    float v1;
    int i;

    v0 = (t * t * t) / 3.0f;
    for (i = 0; i < 4; i++) {
        out[i] = a1[i] * v0;
    }
    v1 = (t * t) * 0.5f;
    for (i = 0; i < 4; i++) {
        out[i] = out[i] + a2[i] * v1;
    }
    for (i = 0; i < 4; i++) {
        out[i] = out[i] + a3[i] * t;
    }
    for (i = 0; i < 4; i++) {
        out[i] = out[i] + a4[i];
    }
    return;
}
#endif
INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0126_AI_GetAccelB3XYZ", AI_GetVelocity3XYZ);

float AI_GetPosition3(float fparg0, float fparg1, float fparg2, float fparg3, float fparg4, float fparg5)
{
    float temp_f1;
    float temp_f2;

    temp_f2 = fparg5 * fparg5;
    temp_f1 = temp_f2 * fparg5;
    return fparg3 + ((fparg0 * (temp_f1 * fparg5)) / 12.0f) + ((fparg1 * temp_f1) / 6.0f) + (fparg2 * 0.5f * temp_f2) + (fparg4 * fparg5);
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0126_AI_GetAccelB3XYZ", AI_GetPosition3XYZ);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0126_AI_GetAccelB3XYZ", AI_GetRotVelocity);

typedef struct {
    char pad0[0x50];
    char frames[0xC];
    int fps;
} MotionResource;

typedef struct {
    MotionResource *res;
    char pad4[0x28];
    float rate;
} MotionState;

typedef struct {
    char pad0[0x44];
    float speed;
} MotionCtrl;

typedef struct {
    char pad0[0x1C0];
    MotionState motion;
    char pad1F0[0xEA8];
    MotionCtrl *ctrl;
} AIObj;

extern int GetMotionResourceFrames(void *);

float AI_GetTimeOfCurrMotion(AIObj *obj, float scale)
{
    MotionState *m = &obj->motion;
    MotionResource *res = m->res;

    if (res != 0) {
        float speed = obj->ctrl->speed;

        return GetMotionResourceFrames(res->frames) * m->rate / (res->fps * speed * scale);
    }
    return 0.0f;
}

u8 *GetCharacterClass(void *chara);

int AI_GetCurMotionKind(void *actor)
{
    return (*(int *)((char *)(GetCharacterClass(actor)) + 0x1C0));
}

int AI_GetCurControlMode(void *actor)
{
    return (*(int *)((char *)(GetCharacterClass(actor)) + 0x740));
}

float AI_GetInterRatio(float x, float start, float end, float low, float high)
{
    end -= start;
    if (end == 0.0f) return low;
    return ((x - start) * (high - low)) / end + low;
}

float AI_GetInterRatioOutCut(float value, float low, float high, float start, float end)
{
    float span;
    float result;

    if (value <= low) {
        result = start;
    } else if (high <= value) {
        result = end;
    } else {
        span = high - low;
        if (span == 0.0f) {
            result = start;
        } else {
            return (((value - low) * (end - start)) / span) + start;
        }
    }
    return result;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0126_AI_GetAccelB3XYZ", AI_GetHitPosPerpendicular);

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0126_AI_GetAccelB3XYZ", AI_GetLengthSquarePerpendicular);

float AI_GetAreaDistScale(float fparg0, float fparg1)
{
    float temp_f0;
    float var_f0;

    var_f0 = fparg0;
    if (!(fparg0 < fparg1)) {
        var_f0 = fparg1;
    }
    temp_f0 = var_f0 / fparg0;
    return temp_f0 * temp_f0;
}

float AI_GetAreaDistScale2(float fparg0, float fparg1)
{
    float var_f0;

    var_f0 = fparg0;
    if (!(fparg0 < fparg1)) {
        var_f0 = fparg1;
    }
    return var_f0 / fparg0;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0126_AI_GetAccelB3XYZ", AI_GetTrgDir);

int GetGeometryPointerObject(int);
int GetLayoutClass(int);

int AI_PlayerParentFlag(int arg0, int arg1)
{
    return GetGeometryPointerObject(GetLayoutClass(arg1) + 0xC0) == arg0;
}

int AI_CheckNormZero(float *v)
{
    if (v[0] < 0.0f) {
        if (!(-0.0001f < v[0]))
            goto nonzero;
    } else if (!(v[0] < 0.0001f)) {
        goto nonzero;
    }
    if (v[1] < 0.0f) {
        if (!(-0.0001f < v[1]))
            goto nonzero;
    } else if (!(v[1] < 0.0001f)) {
        goto nonzero;
    }
    if (v[2] < 0.0f) {
        if (!(-0.0001f < v[2]))
            goto nonzero;
    } else if (!(v[2] < 0.0001f)) {
        goto nonzero;
    }
    return 0;
nonzero:
    return 1;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0126_AI_GetAccelB3XYZ", AI_GetSideSignalFromDirLev);

//INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0126_AI_GetAccelB3XYZ", AI_GetRandomCircleOfsXZ);

extern float iosGetRandom(void);
extern float iosGetTableCos(short);
extern float iosGetTableSin(short);

void AI_GetRandomCircleOfsXZ(float *out, float min, float max)
{
    float a;
    float r;
    short ang;
    float sn;
    float cs;

    a = iosGetRandom() * 2.0f * 3.1415926f;
    r = min + (max - min) * iosGetRandom();
    ang = (int)(a * 32768.0f / 3.1415926f);

    sn = iosGetTableSin(ang);
    out[1] = 0.0f;
    out[0] = sn * r;
    cs = iosGetTableCos(ang);
    out[3] = 0.0f;
    out[2] = cs * r;
}

extern float iosGetRandom(void);
extern float iosGetTableCos(short);
extern float iosGetTableSin(short);

void AI_GetRandomCircleOfsXY(float *out, float min, float max)
{
    float a = iosGetRandom() * 2.0f * 3.1415926f;
    float r = min + (max - min) * iosGetRandom();
    short ang = (int)(a * 32768.0f / 3.1415926f);

    out[0] = iosGetTableCos(ang) * r;
    out[1] = -iosGetTableSin(ang) * r;
    out[2] = 0.0f;
    out[3] = 0.0f;
}

INCLUDE_ASM("asm/GAMECORE.XFF/nonmatchings/chunk/c0126_AI_GetAccelB3XYZ", AI_GetRandomRectOfsXY);

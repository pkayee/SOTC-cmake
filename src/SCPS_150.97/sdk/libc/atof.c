#include "common.h"

double strtod(const char *s, char **endptr);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/atof", atof);
double atof(const char *s)
{
    return strtod(s, NULL);
}

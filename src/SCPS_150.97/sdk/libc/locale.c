#include "common.h"
#include <sys/reent.h>

extern struct _reent *D_00135D60[];
extern char D_00139C48[];
extern char D_00139C38[];
extern char D_00139C08[];
int strcmp(const char *s1, const char *s2);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/locale", _setlocale_r);
char *_setlocale_r(struct _reent *ptr, int category, char *locale)
{
    if (locale != NULL)
    {
        if (strcmp(locale, D_00139C48) != 0 && strcmp(locale, D_00139C38) != 0)
        {
            return NULL;
        }
        ptr->_current_category = category;
        ptr->_current_locale = locale;
    }
    return D_00139C48;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/locale", func_0012E620);
char *func_0012E620(struct _reent *ptr)
{
    return D_00139C08;
}

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/locale", setlocale);
char *setlocale(int category, char *locale)
{
    return _setlocale_r(D_00135D60[0], category, locale);
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libc/locale", localeconv);

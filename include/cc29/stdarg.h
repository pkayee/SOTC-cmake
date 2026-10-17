/* ee-gcc2.9-991111 shim: the 2.96 stdarg.h in include/gcc spells va_list as __builtin_va_list, which gcc 2.9 does not have.
 * Only the typedef is provided (enough for the SDK prototypes); a function that really uses va_start/va_arg stays on ee-gcc2.96. */
#ifndef _STDARG_H_CC29_SHIM
#define _STDARG_H_CC29_SHIM
typedef char *__cc29_va_list;
#define __builtin_va_list __cc29_va_list
#include_next <stdarg.h>
#undef __builtin_va_list
#endif

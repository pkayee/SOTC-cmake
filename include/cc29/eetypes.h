/* Shim for ee-gcc2.9-991111 (per-segment second compiler, see configure.py `cc=`): gcc 2.9 rejects the duplicate
 * `typedef ... u_long128` that common.h and the SDK's eetypes.h both carry (2.96 accepts it). When common.h came first,
 * give the SDK copy another name for the duration of the SDK header. Put before -Iinclude; only used with cc=ee-gcc2.9-991111. */
#ifndef _EETYPES_H_CC29_SHIM
#define _EETYPES_H_CC29_SHIM
#ifdef COMMON_H
#define u_long128 u_long128_sdk_dup
#endif
#include_next <eetypes.h>
#ifdef COMMON_H
#undef u_long128
#endif
#endif

/* see include/cc29/eetypes.h (same shim for the `#include "sdk/ee/eetypes.h"` spelling) */
#ifndef _EETYPES_H_CC29_SHIM
#define _EETYPES_H_CC29_SHIM
#ifdef COMMON_H
#define u_long128 u_long128_sdk_dup
#endif
#include_next <sdk/ee/eetypes.h>
#ifdef COMMON_H
#undef u_long128
#endif
#endif

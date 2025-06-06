#pragma once

#include "libc/stdio.h"
#include "lunaix/tty/tty.hpp"

#ifdef __LUNAIXOS_DEBUG__
#define assert(cond)                                                           \
    if (!(cond))                                                               \
    {                                                                          \
        __assert_fail(#cond, __FILE__, __LINE__);                              \
    }
#else
#define assert(cond) // nothing
#endif

extern "C" void __assert_fail(const char *expr, const char *file,
                              unsigned int line)
    __attribute__((noinline, noreturn));

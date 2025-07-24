#pragma once

#include <stdarg.h>

#ifdef __LUNAIX_LIBC
void __sprintf_internal(char *buffer, const char *fmt, va_list args);
#endif

void sprintf(char *buffer, const char *fmt, ...);
void printf(const char *fmt, ...);

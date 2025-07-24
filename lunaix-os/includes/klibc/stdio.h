#ifndef __LUNAIX_STDIO_H
#define __LUNAIX_STDIO_H
#include <stdarg.h>
#include <stddef.h>

void __sprintf_internal(char *buffer, const char *fmt, size_t max_len,
                        va_list vargs);

void sprintf(char *buffer, const char *fmt, ...);
void snprintf(char *buffer, size_t n, const char *fmt, ...);
#endif /* __LUNAIX_STDIO_H */

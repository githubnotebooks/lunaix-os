#define __LUNAIX_LIBC
#include "libc/stdio.h"
#include "lunaix/tty/tty.hpp"
#include <stdarg.h>

void printf(const char *fmt, ...)
{
    char buffer[1024];
    va_list args;
    va_start(args, fmt);
    __sprintf_internal(buffer, fmt, args);
    va_end(args);

    // 啊哈，直接操纵framebuffer。日后须改进（FILE* ?）
    tty_put_str(buffer);
}

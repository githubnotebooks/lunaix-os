#include "libc/stdio.h"
#include "lunaix/arch/gdt.h"
#include "lunaix/arch/idt.h"
#include "lunaix/tty/tty.h"

extern "C"
{
    void _kernel_init()
    {
        _init_gdt();
        _init_idt();
    }

    void _kernel_main([[maybe_unused]] void *info_table)
    {
        tty_set_theme(VGA_COLOR_GREEN, VGA_COLOR_BLACK);
        printf("Hello kernel world!\nThis is second line.");
        __asm__ __volatile__("int $0");
    }
}

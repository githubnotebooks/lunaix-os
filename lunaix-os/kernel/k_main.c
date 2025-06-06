#include "hal/cpu.hpp"
#include "libc/stdio.h"
#include "lunaix/mm/vmm.hpp"
#include <stdint.h>

extern uint8_t __kernel_start;
void cpu_get_brand(char *brand_out);

extern "C" void _kernel_main()
{
    char buf[64];

    printf("Hello higher half kernel world!\nWe are now running in virtual "
           "address space!\n\n");

    cpu_get_brand(buf);
    printf("CPU: %s\n\n", buf);

    uintptr_t k_start = reinterpret_cast<uintptr_t>(vmm_v2p(&__kernel_start));
    printf("The kernel's base address mapping: %p->%p\n", &__kernel_start,
           k_start);
}

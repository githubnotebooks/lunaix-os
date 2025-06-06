#include "hal/cpu.hpp"
#include "libc/stdio.h"
#include "lunaix/mm/dmm.hpp"
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

    void *k_start = vmm_v2p(&__kernel_start);
    printf("The kernel's base address mapping: %p->%p\n", &__kernel_start,
           k_start);

    dmm_init();

    // test malloc & free

    uint32_t **arr = (uint32_t **)lx_malloc(10 * sizeof(uint32_t *));

    for (size_t i = 0; i < 10; i++)
    {
        arr[i] = (uint32_t *)lx_malloc((i + 1) * 2);
    }

    void* big_ = lx_malloc(8192);

    for (size_t i = 0; i < 10; i++)
    {
        lx_free(arr[i]);
    }

    lx_free(arr);
    lx_free(big_);
    // assert(0);
}

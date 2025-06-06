#include "arch/x86/interrupts.hpp"
#include "libc/stdio.h"
#include "lunaix/tty/tty.hpp"

void isr0([[maybe_unused]] isr_param *param)
{
    printf("[PANIC] Exception (%d) CS=0x%X, EIP=0x%X", param->vector, param->cs,
           param->eip);
}

extern "C"
{
    void interrupt_handler(isr_param *param)
    {
        switch (param->vector)
        {
        case 0:
            isr0(param);
            break;
        }
    }
}

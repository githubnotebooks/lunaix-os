#include "lunaix/mm/dmm.hpp"
#include "lunaix/mm/vmm.hpp"

// This is a temporary design.
//  We can do better when we are ready for multitasking
void lxsbrk(void *current, void *next)
{
    // TODO: sbrk
}

void lxmalloc(size_t size)
{
    // TODO: Malloc
}

void lxfree(size_t size)
{
    // TODO: Free
}

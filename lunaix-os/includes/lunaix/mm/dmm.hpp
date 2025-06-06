#pragma once
// Dynamic Memory (i.e., heap) Manager

#include <stddef.h>

void lxsbrk(void *current, void *next);

void lxmalloc(size_t size);

void lxfree(size_t size);

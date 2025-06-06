#pragma once

#define IDT_ATTR(dpl) ((0x70 << 5) | (dpl & 3) << 13 | 1 << 15)

extern "C" void _init_idt();

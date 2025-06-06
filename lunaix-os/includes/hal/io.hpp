#pragma once

#include <stdint.h>

inline void io_port_wb(uint8_t port, uint8_t value)
{
    asm volatile("movb %0, %%al\n"
                 "movb %1, %%dx\n"
                 "out %%al, %%dx\n" ::"r"(value),
                 "r"(port));
}

inline void io_port_wl(uint8_t port, uint32_t value)
{
    asm volatile("movl %0, %%eax\n"
                 "movb %1, %%dx\n"
                 "out %%eax, %%dx\n" ::"r"(value),
                 "r"(port));
}

inline uint8_t io_port_rb(uint8_t port)
{
    uint8_t result;
    asm volatile("inb %1, %0"
                 : "=a"(result) // 输出：result ← al
                 : "Nd"(port)   // 输入：port → dx or imm8
    );
    return result;
}

inline uint32_t io_port_rl(uint8_t port)
{
    uint32_t result;
    asm volatile("inl %1, %0"
                 : "=a"(result) // 输出：result ← eax
                 : "Nd"(port)   // 输入：port → dx or imm8
    );
    return result;
}

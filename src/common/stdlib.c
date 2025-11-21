#include <stdint.h>
#include <stddef.h>
#include "common/stdlib.h"


void memcpy(void* dest, const void* src, size_t bytes)
{
    char* d = dest;
    const char* s = src;
    while(bytes--) {
        *d++ = *s++;
    }
}

void bzero(void* dest, size_t bytes)
{
    memset(dest, 0, bytes);
}

void memset(void* dest, uint8_t c, size_t bytes)
{
    uint8_t* d = dest;
    while(bytes--) {
        *d++ = c;
    }
}

char* itoa(int num, int base) 
{    
    static char intbuf[33];
    char* ptr = &intbuf[32];
    *ptr = '\0';

    uint32_t is_neg = 0;
    uint32_t i;

    if (0 == num) {
        intbuf[31] = '0';
        return &intbuf[31];
    }

    if (num < 0 && base == 10) {
        is_neg = 1;
        num = -num;
    }

    i = (uint32_t) num;

    // NOT SUPPORTED BY MODEL 1 PI
    // Have to implement divide function
    while (i != 0) {
        uint32_t mod = i % base;
        *(--ptr) = (mod < 10) ? ('0' + mod) : ('A' + mod - 10);
        i = i / base;
    }

    if (is_neg) *(--ptr) = '-';

    if (base == 16) {
        *(--ptr) = 'x';
        *(--ptr) = '0';
    }
    else if (base == 8) {
        *(--ptr) = '0';
    }
    else if (base == 2) {
        *(--ptr) = 'b';
        *(--ptr) = '0';
    }

    return ptr;
}
#pragma once

#include <stdint.h>

void memcpy(void* dest, const void* src, size_t bytes);

void bzero(void* dest, size_t bytes);
void memset(void* dest, uint8_t c, size_t bytes);

char* itoa(int i, int base);

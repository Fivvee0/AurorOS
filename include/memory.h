#pragma once

#include <types.h>

extern void *memcpy(void *dest, const void *src, size_t n);
extern void *malloc(size_t size);
extern void init_memory();
extern void free(void *ptr);
extern void *memset(void *s, int c, size_t n);

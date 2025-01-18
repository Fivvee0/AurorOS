#pragma once

#include <types.h>
#include <string.h>

extern void print_error(const string str);
extern void print_info(const string str);
extern void print_ok(const string str);
extern void print_warn(const string str);
extern void print_custom(const string str, uint8_t color, uint8_t scolor);
extern void print(const char* str , uint8_t color);
extern void println(const string str, uint8_t color);

#pragma once

#include <types.h>

extern int terminal_main();
extern void kernelpanic(const char *errcode);

extern void sprint(const char *str);
extern void sprintchar(char c);

extern void serial_init();
#pragma once

#include <types.h>
#include <screen.h>
#include <string.h>

void cowsay(char message[1024]);
void map();
void help();
extern int tinypad_main(uint8_t color, uint8_t barcolor);
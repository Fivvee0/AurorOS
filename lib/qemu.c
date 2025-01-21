#include <ports.h>

#include <hardware/qemu.h>
void sprintchar(char c) {
    outb(0x3F8, c);
}

void sprint(const char *str) {
    while (*str) {
        sprintchar(*str++);
    }
}

void sprintln(const char *str) {
    sprint(str);
    sprintchar('\n');
}

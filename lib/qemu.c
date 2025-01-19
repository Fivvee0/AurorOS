#include <types.h>
#include <ports.h>

#include <hardware/qemu.h>

#define SERIAL_PORT 0x3F8

void serial_init() {
    outb(SERIAL_PORT + 1, 0x00);
    outb(SERIAL_PORT + 3, 0x80);
    outb(SERIAL_PORT + 0, 0x03);
    outb(SERIAL_PORT + 1, 0x00);
    outb(SERIAL_PORT + 3, 0x03);
    outb(SERIAL_PORT + 2, 0xC7);
    outb(SERIAL_PORT + 4, 0x0B);
}

int serial_is_transmit_fifo_empty() {
    return inb(SERIAL_PORT + 5) & 0x20;
}

void sprintchar(char c) {
    while (!serial_is_transmit_fifo_empty());
    outb(SERIAL_PORT, c);
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

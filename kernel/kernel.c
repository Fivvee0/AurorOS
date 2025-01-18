#include <types.h>

extern int terminal_main(uint16_t theme);
extern void kernelpanic(const char *errcode);

void main() {
    terminal_main(0x0B);
    kernelpanic("KERNEL_MAIN_LOOP_EXITED");
}

#include "kernel.h"

void main() {
    terminal_main(0x0B);
    kernelpanic("KERNEL_MAIN_LOOP_EXITED");
}

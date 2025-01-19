#include "kernel.h"

void main() {
    terminal_main();
    kernelpanic("KERNEL_MAIN_LOOP_EXITED");
}

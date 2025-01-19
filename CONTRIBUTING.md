## Code writing standards

There are standards in writing code for FevOS and to not make ten next useless commits reverting the change.

1. Use [snake case](https://en.wikipedia.org/wiki/Snake_case) style.
2. Do not use `#include "../include/something_there.h"`. Instead, use `#include <something_there.h>`.
3. Do not make any C or other non-header files in `include` directory.
4. Make sure that your code is not breaking the OS.

Your pull request will be **rejected** if any of standards above is not used in your code.

## Compiling and running FevOS

### Compilation

> [!CAUTION]
> You will do this only at your own risk. We don't officially support any OS builds compiled by the user.

To clone, compile and run virtually AurorOS you will need `git`, `make`, `lld`, `clang`, `nasm` and `qemu-system-x86_64` installed.

Clone the repository.

Run this command in FevOS repo to build the OS:

`make`

### Running OS in virtual machine

Run this command to run the OS:

`make run`

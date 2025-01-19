#include <msg.h>
#include <constants.h>
#include <string.h>
#include <input.h>
#include <asm/power.h>
#include <types.h>
#include <panic.h>
#include <screen.h>
#include <hardware/cpu.h>
#include <hardware/qemu.h>

#include "commands.h"

void printprefix(const char* user, const char* pcname) {
    print(" [ ", 0x07);
    print(user, 0x09);
    print("@", 0x0F);
    print(pcname, 0x02);
    print(" ]", 0x07);
    print(" $ ", 0x0F);
}

int terminal_main() {
    clearscreen();

    print_info(NAME);

    char user[8];
    strcpy(user, "root");

    char buffer[128];
    char *args[10];
    while (1) {
        printprefix(user, PC_NAME);
        read_str(buffer, sizeof(buffer), 0, 0x07);

        int arg_count = split_str(buffer, ' ', args, 10);

        if (arg_count > 0) {
            char farg[1024] = "";
            for (int i = 1; i < arg_count; i++) {
                strcat(farg, args[i]);
                strcat(farg, " ");
            }

            if (streql(args[0], "ver")) {
                print(" ", 0x07);
                print(NAME, 0x07);
                print(" ", 0x07);
                println(VERSION, 0x07);
            } else if (streql(args[0], "print")) {
                println(farg ,0x07);
            } else if (streql(args[0], "cowsay")) {
                cowsay(farg);
            } else if (streql(args[0], "map")) {
                map();
            } else if (streql(args[0], "clear")) {
                clearscreen();
            } else if (streql(args[0], "reboot")) {
                reboot();
            } else if (streql(args[0], "shutdown")) {
                shutdown();
            } else if (streql(args[0], "chuser")) {
                if (strlen(farg) < 1 || strlen(farg) > 8) {
                    print_error("User name must be between 1 and 8 characters long!");
                } else {
                    strcpy(user, farg);
                }
            } else if (streql(args[0], "cpu")) {
                println(get_cpu_name(), 0x07);
            } else if (streql(args[0], "tinypad")) {
                tinypad_main(0x07, 0x9F);
            } else if (streql(args[0], "debug_panic")) {
                kernelpanic("DEBUG_KERNEL_PANIC");
            } else if (streql(args[0], "debug_sprint")) {
                sprint(farg);
            } else if (streql(args[0], "debug_init_sprint")) {
                serial_init();
            } else if (streql(args[0], "help")) {
                help();
            } else {
                printstr(" ERROR ", 0x04);
                printstr(": ", 0x07);
                printstr(args[0], 0x07);
                printstr(" is not a valid command!", 0x07);
            }
        }
    }
}


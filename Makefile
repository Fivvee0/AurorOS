CC = clang
CXX = clang++
AS = nasm
LD = ld.lld

CFLAGS = --target=i686-elf -Wall -Wextra -m32 -ffreestanding -Iinclude -nostdlib -fno-stack-protector -c
ASFLAGS = -f elf32
LDFLAGS = -m elf_i386 --entry=main --strip-all -T link.ld

KERNEL_SOURCES = \
	kernel/kernel.c \
	drivers/hardware/ports.c \
	kernel/panic.c \
	drivers/keyboard/input.c \
	drivers/misc/memory.c \
	drivers/vga/screen.c \
	lib/msg.c lib/string.c \
	lib/qemu.c \
	core/tty/terminal.c \
	core/tty/commands.c \
	app/tinypad/tinypad.c \
	drivers/hardware/cpu.c \

KERNEL_SOURCES_ASM = boot/boot.asm

KERNEL_OBJECTS = $(foreach src,$(KERNEL_SOURCES),bin/$(notdir $(src:.c=.o)))
KERNEL_OBJECTS_ASM = $(foreach src,$(KERNEL_SOURCES_ASM),bin/$(notdir $(src:.asm=.o)))

all: bin $(KERNEL_OBJECTS) $(KERNEL_OBJECTS_ASM) kernel.elf

bin:
	mkdir bin

kernel.elf: $(KERNEL_OBJECTS) $(KERNEL_OBJECTS_ASM)
	$(LD) $(LDFLAGS) -o $@ $^
	llvm-objcopy --remove-section=.comment $@ $@

bin/%.o: */%.c
	$(CC) $(CFLAGS) $< -o $@

bin/%.o: */*/%.c
	$(CC) $(CFLAGS) $< -o $@

bin/%.o: */*/*/%.c
	$(CC) $(CFLAGS) $< -o $@


bin/%.o: */%.asm
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf bin kernel.elf

run:
	qemu-system-x86_64 -kernel kernel.elf -serial stdio

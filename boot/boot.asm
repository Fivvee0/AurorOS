bits 32

section .multiboot
    align 4
    dd 0x1BADB002
    dd 0x00
    dd -(0x1BADB002 + 0x00)

section .text
    global start
    extern main

section .os
    os db "FevOS", 0

start:
    cli
    call main
    hlt
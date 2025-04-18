;; kernel.asm
bits 32                     ;nasm directive - 32 bits
section .text
        ;multiboot spec
        align 4
        dd 0x1BADB002            ;Magic number to identify header
        dd 0x00                  ;Flags - not needed
        dd - (0x1BADB002 + 0x00) ;Checksum. m+f+c should be zero

global start
extern kmain                ;extern the kmain function defined in a .c file

start:
    cli                     ;block/clear interrupts
    mov esp, stack_space    ;set stack pointer
    call kmain              ;exec the function
    hlt                     ;halt the CPU

section .bss
resb 8192                   ;8KB for stack - Reserve Mem in Bytes
stack_space:

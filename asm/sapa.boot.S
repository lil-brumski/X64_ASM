.intel_syntax noprefix
.code32

.section .multiboot
.align 4
.long 0x1BADB002
.long 0
.LONG -(0x1BADB002)

.section .text
.global _start
.type _start, @function
_start:
    mov esp, 0x90000
    call Sapa_Main
    cli
1:
    hlt
    jmp 1b
bits 64
default rel

section .data
    name: db "Tamaratare",0x0a

section .text
global _start

_start:
    mov rax, 1
    mov rdi, 1
    lea rsi, [rel name]
    mov rdx, 11
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall

    ;jmp name
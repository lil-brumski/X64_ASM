.intel_syntax noprefix
.global _start

.data
name:
    .ascii "Tamaratare\n"
dept:
    .ascii "Computer Engineering\n"

.text

_start:
    mov rax, 1
    mov rdi, 1
    lea rsi, [rip + name]
    mov rdx, 11
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall
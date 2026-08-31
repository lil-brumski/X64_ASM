#!/bin/bash

nasm -felf64 asm/hello.asm -o asm/hello.o
ld asm/hello.o -o hello

nasm -felf64 asm/registers.asm -o asm/registers.o
ld asm/registers.o -o registers
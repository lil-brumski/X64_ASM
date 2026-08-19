#!/bin/bash

nasm -felf64 hello.asm
ld hello.o -o hello

nasm -felf64 registers.asm
ld registers.o -o registers
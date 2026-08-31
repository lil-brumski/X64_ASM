cmake_minimum_required(VERSION 4.0)

project(LearnCMake 
        LANGUAGES CXX ASM
        VERSION 2026.8.31
        DESCRIPTION "For learning CMake, Git and Doxygen among other stuff"
        )

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_language(ASM)

#C++
add_executable(${PROJECT_NAME}_cpp src/hello.cpp)

#Assembly 
add_executable(${PROJECT_NAME}_asm asm/hello.S)

#target_compile_options(${PROJECT_NAME}_asm PRIVATE $<$<COMPILE_LANGUAGE:ASM>:-masm=intel>)

target_link_options(${PROJECT_NAME}_asm PRIVATE -nostdlib -Wno-unused-command-line-argument) #-static -no-pie -Wl,-e,_start )
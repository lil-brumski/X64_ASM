cmake_minimum_required(VERSION 4.0)

project(LearnCMake 
        LANGUAGES CXX ASM
        VERSION 2026.8.31
        DESCRIPTION "For learning CMake, Git and Doxygen among other stuff"
        HOMEPAGE_URL "https://github.com/lil-brumski/X64_ASM.git"
        )

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(AUTHOR "David Tamaratare Oghenebrume" CACHE STRING "Author's name" FORCE)

enable_language(ASM)

#C++
add_executable(${PROJECT_NAME}_cpp EXCLUDE_FROM_ALL src/hello.cpp)

#Assembly 
add_executable(${PROJECT_NAME}_asm asm/hello.S)

target_link_options(${PROJECT_NAME}_asm PRIVATE -nostdlib -static -Wno-unused-command-line-argument) 
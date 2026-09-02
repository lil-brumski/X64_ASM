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
set(BUILT_ON "Monday" CACHE STRING "What day of the week was it built on")
set_property(CACHE BUILT_ON PROPERTY STRINGS "Monday" "Tuesday" "Wednesday" "Thursday" "Friday")
message("${AUTHOR} uses ${CMAKE_C_COMPILER} and ${CMAKE_CXX_COMPILER} for this project. \nHe also uses C++${CMAKE_CXX_STANDARD} and x64 Intel Assembly")
string(FIND ${AUTHOR} "a" POSofA REVERSE)
message("POSofA = ${POSofA}")

#C++
add_executable(${PROJECT_NAME}_cpp EXCLUDE_FROM_ALL src/hello.cpp)

add_executable(${PROJECT_NAME}_cpp_2 EXCLUDE_FROM_ALL src/Template_Horrors.cpp)

#Assembly 
enable_language(ASM)
add_executable(${PROJECT_NAME}_asm asm/hello.S)

target_link_options(${PROJECT_NAME}_asm PRIVATE -nostdlib -static -Wno-unused-command-line-argument)
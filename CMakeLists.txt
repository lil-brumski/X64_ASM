cmake_minimum_required(VERSION 4.0)

project(LearnCMake 
        LANGUAGES CXX ASM
        VERSION 2026.9.5
        DESCRIPTION "For learning CMake, Git and Doxygen among other stuff"
        HOMEPAGE_URL "https://github.com/lil-brumski/X64_ASM.git"
        )

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ZeroMQ REQUIRED COMPONENTS)
find_package(cppzmq REQUIRED COMPONENTS)
find_package(termcolor REQUIRED)

include(cmake/x64a.cmake)
include_directories(${ZeroMQ_INCLUDE_DIR})

set(BROs "Brume;Tare")
list(APPEND BROs "David")
FuncAppend(BROs "Me")

foreach(X IN LISTS BROs)
    message("See: ${X}")
endforeach()

message("")

macro(PRINT_RUBBISH)
endmacro()

##C++
#Target 1
add_executable(${PROJECT_NAME}_cpp EXCLUDE_FROM_ALL)
target_sources(${PROJECT_NAME}_cpp
    PRIVATE
        src/hello.cpp
)

#Target 2
add_executable(${PROJECT_NAME}_cpp_2 EXCLUDE_FROM_ALL)
target_sources(${PROJECT_NAME}_cpp_2
    PRIVATE
        src/Template_Horrors.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/Template_Horrors.hpp
)

#Target 3
add_executable(Sapa EXCLUDE_FROM_ALL)
target_sources(Sapa
    PRIVATE
        src/sapa.cpp
)

#Target 4
add_executable(Naija99)
target_sources(Naija99
    PRIVATE
        src/naija.cpp
)
target_link_libraries(Naija99 PRIVATE cppzmq libzmq termcolor::termcolor)

#Target 5
add_executable(Brume99)
target_sources(Brume99
    PRIVATE
        src/brume99.cpp
)
target_link_libraries(Brume99 PRIVATE cppzmq libzmq termcolor::termcolor)

#Assembly 
#Target 6
enable_language(ASM)
add_executable(${PROJECT_NAME}_asm)
target_sources(${PROJECT_NAME}_asm
    PRIVATE
        asm/hello.S
)

target_link_options(${PROJECT_NAME}_asm PRIVATE -nostdlib -static -Wno-unused-command-line-argument)

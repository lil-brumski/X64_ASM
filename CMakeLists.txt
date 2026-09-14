cmake_minimum_required(VERSION 4.0)

include(cmake/x64a.cmake)

project(LearnCMake 
        LANGUAGES CXX ASM
        VERSION "${LearnCMake_VERSION_MAJOR}.${LearnCMake_VERSION_MINOR}.${LearnCMake_VERSION_PATCH}"
        DESCRIPTION "For learning CMake, Git and Doxygen among other stuff"
        HOMEPAGE_URL "https://github.com/lil-brumski/X64_ASM.git"
        )

find_package(ZeroMQ REQUIRED COMPONENTS)
find_package(cppzmq REQUIRED COMPONENTS)
find_package(termcolor REQUIRED)

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

include_directories(${ZeroMQ_INCLUDE_DIR})

#Target 4
add_executable(Naija99)
target_sources(Naija99
    PRIVATE
        src/naija.cpp
)
target_link_libraries(Naija99 PRIVATE cppzmq libzmq termcolor::termcolor)
target_compile_features(Naija99 PRIVATE cxx_std_20)
target_compile_definitions(Naija99
    PRIVATE
        AUTHOR_LEARN_CMAKE="${AUTHOR_LEARN_CMAKE}"
        LearnCMake_VERSION_MAJOR="${CMAKE_PROJECT_VERSION_MAJOR}"
        LearnCMake_VERSION_MINOR="${CMAKE_PROJECT_VERSION_MINOR}"
        LearnCMake_VERSION_PATCH="${CMAKE_PROJECT_VERSION_PATCH}"
)

#Target 5
add_executable(Brume99)
target_sources(Brume99
    PRIVATE
        src/brume99.cpp
    PRIVATE
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/LearnCMake.hpp
)
target_link_libraries(Brume99 PRIVATE cppzmq libzmq termcolor::termcolor)
target_compile_features(Brume99 PRIVATE cxx_std_20)
target_compile_definitions(Brume99
    PRIVATE
        AUTHOR_LEARN_CMAKE="${AUTHOR_LEARN_CMAKE}"
        LearnCMake_VERSION_MAJOR="${CMAKE_PROJECT_VERSION_MAJOR}"
        LearnCMake_VERSION_MINOR="${CMAKE_PROJECT_VERSION_MINOR}"
        LearnCMake_VERSION_PATCH="${CMAKE_PROJECT_VERSION_PATCH}"
)

#Assembly 
#Target 6
enable_language(ASM)
add_executable(${PROJECT_NAME}_asm)
target_sources(${PROJECT_NAME}_asm
    PRIVATE
        asm/hello.S
)
target_link_options(${PROJECT_NAME}_asm PRIVATE -nostdlib -static -Wno-unused-command-line-argument)
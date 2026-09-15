message("Hey, I'm Tare\nHappy to meet you!\n")

set(SIGMA "Boy;Girl")
list(APPEND SIGMA "Man;Woman")

foreach(SI IN LISTS SIGMA)
        message("Sigma child: ${SI}")
endforeach()

macro(MacroAppend ListVar Value)
  set(${ListVar} "${${ListVar}};${Value}")
  #message("${ListVar}")
endmacro()

MacroAppend(SIGMA "Me")

message("${SIGMA}")

function(FuncAppend ListVar Value)
    MacroAppend(${ListVar} ${Value})
    set(${ListVar} "${${ListVar}}" PARENT_SCOPE)
endfunction()

FuncAppend(SIGMA "Brume")
#message(${SIGMA})

foreach(SI IN LISTS SIGMA)
    message("${SI}")
endforeach()

message("")

if(NOT DEFINED SIGMA)
    message("It's not defined yo :(")
else()
   message("It's defined yo :)")
endif()

set(AUTHOR_LEARN_CMAKE "David Tamaratare Oghenebrume" CACHE STRING "Author's name")

set(BUILT_ON "Monday" CACHE STRING "What day of the week was it built on")
set_property(CACHE BUILT_ON PROPERTY STRINGS "Monday" "Tuesday" "Wednesday" "Thursday" "Friday")

set(BROs "Brume;Tare")
list(APPEND BROs "David")
FuncAppend(BROs "Me")

foreach(X IN LISTS BROs)
    message("See: ${X}")
endforeach()

option(BUILD_LEARN_CMAKE_CPP "Build the first C++ target" OFF)
option(BUILD_LEARN_CMAKE_CPP_2 "Build the second C++ target" OFF)
option(BUILD_LEARN_CMAKE_ASM "Build the first Assembly target" OFF)

#Not My Project
include(CheckIncludeFiles)
check_include_files(sys/socket.h HAVE_SYS_SOCKET_H LANGUAGE CXX)

include(CheckSourceCompiles)
check_source_compiles(CXX
"
auto main(int argc, char** argv) -> int{
    int a, b, c;
    __builtin_add_overflow(a, b, &c);
}
"
HAVE_CHECKED_ADD
)

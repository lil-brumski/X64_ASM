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

set(AUTHOR "David Tamaratare Oghenebrume" CACHE STRING "Author's name" FORCE)

set(BUILT_ON "Monday" CACHE STRING "What day of the week was it built on")
set_property(CACHE BUILT_ON PROPERTY STRINGS "Monday" "Tuesday" "Wednesday" "Thursday" "Friday")

message("${AUTHOR} uses ${CMAKE_C_COMPILER} and ${CMAKE_CXX_COMPILER} for this project. \nHe also uses C++${CMAKE_CXX_STANDARD} and x64 Intel Assembly")
string(FIND ${AUTHOR} "a" POSofA REVERSE)
message("POSofA = ${POSofA}\n")

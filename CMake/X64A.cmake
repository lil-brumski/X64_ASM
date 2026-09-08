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

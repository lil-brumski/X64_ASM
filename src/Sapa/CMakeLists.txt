add_executable(Sapa.elf)
target_sources(Sapa.elf
    PRIVATE
        src/sapa.cpp
        ${PROJECT_SOURCE_DIR}/asm/sapa.boot.S
)
target_compile_options(Sapa.elf
    PRIVATE
        -m32 -ffreestanding -nostdlib
        -fno-exceptions -fno-rtti -fno-pie
)
target_link_options(Sapa.elf
    PRIVATE
        -m32 -ffreestanding -nostdlib
        -fno-exceptions -fno-rtti
        -fno-pie -Wl,--entry,_start
        -T "${CMAKE_SOURCE_DIR}/asm/sapa.ld"
)
target_compile_features(Sapa.elf PRIVATE cxx_std_26)
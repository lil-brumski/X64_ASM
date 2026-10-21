#Assembly
enable_language(ASM)
add_executable(${PROJECT_NAME}_asm)
target_sources(${PROJECT_NAME}_asm
    PRIVATE
        ${PROJECT_SOURCE_DIR}/asm/hello.S
)
target_link_options(${PROJECT_NAME}_asm PRIVATE -nostdlib -static -Wno-unused-command-line-argument)
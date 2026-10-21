add_executable(Brume99)
target_sources(Brume99
    PRIVATE
        src/brume99.cpp
    #[[PRIVATE
        FILE_SET CXX_MODULES
        TYPE CXX_MODULES
        FILES
            modules/src/LearnMod.cppm]]
)
target_link_libraries(Brume99
    PRIVATE
        cppzmq libzmq-static termcolor::termcolor
        Learn++::Learn++ protobuf::libprotobuf
)
target_compile_features(Brume99 PRIVATE cxx_std_23)
set_target_properties(Brume99
    PROPERTIES
        EXPORT_COMPILE_COMMANDS ON
        ENABLE_EXPORTS ON
        #CXX_SCAN_FOR_MODULES ON
)
protobuf_generate(
    TARGET
        Brume99
    LANGUAGE
        cpp
    OUT_VAR
        PROTO_FILES
    PROTOC_OUT_DIR
        ${PROJECT_BINARY_DIR}/generated
    IMPORT_DIRS
        ${PROJECT_SOURCE_DIR}/scripts
    PROTOS
       ${PROJECT_SOURCE_DIR}/scripts/x64_asm.proto
)
target_include_directories(Brume99 PRIVATE ${PROJECT_BINARY_DIR}/generated)
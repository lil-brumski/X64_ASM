add_executable(Naija99)
target_sources(Naija99
    PRIVATE
        src/naija.cpp
        ${PROJECT_BINARY_DIR}/generated/x64_asm.pb.cc
)
target_link_libraries(Naija99
    PRIVATE
        cppzmq libzmq-static
        termcolor::termcolor protobuf::libprotobuf
)
target_compile_features(Naija99 PRIVATE cxx_std_20)
# protobuf_generate(
#     TARGET
#         Naija99
#     LANGUAGE
#         cpp
#     OUT_VAR
#         PROTO_FILES
#     PROTOC_OUT_DIR
#         ${PROJECT_BINARY_DIR}/generated
#     IMPORT_DIRS
#         ${PROJECT_SOURCE_DIR}/scripts
#     PROTOS
#         ${PROJECT_SOURCE_DIR}/scripts/x64_asm.proto
# )
target_include_directories(Naija99 PRIVATE ${PROJECT_BINARY_DIR}/generated)
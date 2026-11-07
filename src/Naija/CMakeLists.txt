add_executable(Naija99)
target_sources(Naija99
    PRIVATE
        src/naija.cpp
)
target_link_libraries(Naija99
    PRIVATE
        cppzmq libzmq-static
        termcolor::termcolor
        sfml-audio sfml-graphics
        sfml-network sfml-system
        sfml-window
)
target_compile_features(Naija99 PRIVATE cxx_std_20)
# target_include_directories(Naija99 PRIVATE ${PROJECT_BINARY_DIR}/generated)
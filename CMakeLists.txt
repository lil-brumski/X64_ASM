cmake_minimum_required(VERSION 4.0)

project(LearnCMake 
        LANGUAGES CXX ASM
        VERSION 2026.9.21
        DESCRIPTION "For learning CMake, Git and Doxygen among other stuff"
        HOMEPAGE_URL "https://github.com/lil-brumski/X64_ASM.git"
        )

#My Project
include(cmake/x64a.cmake)

if(ENABLE_IPO)
    include(CheckIPOSupported)
    check_ipo_supported(RESULT result OUTPUT output)

    if(result)
        message(NOTICE "IPO is supported on this system, hurray")
    else()
        message(WARNING "IPO is not supported on this system: ${output}")
    endif(result)

endif(ENABLE_IPO)

#find_package(ZeroMQ REQUIRED COMPONENTS)
find_package(cppzmq REQUIRED COMPONENTS)
find_package(termcolor REQUIRED)
find_package(Protobuf CONFIG REQUIRED)
find_package(ftxui REQUIRED COMPONENTS screen dom)
find_package(Slint CONFIG REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(FONTCONFIG REQUIRED fontconfig)

##C++
add_library(Learnplusplus OBJECT)
add_library(Learn++::Learn++ ALIAS Learnplusplus)
target_sources(Learnplusplus
    PRIVATE
        src/LearnCMake.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/LearnCMake.hpp
)
target_compile_definitions(Learnplusplus
    PUBLIC
        AUTHOR_LEARN_CMAKE="${AUTHOR_LEARN_CMAKE}"
        LearnCMake_VERSION_MAJOR="${CMAKE_PROJECT_VERSION_MAJOR}"
        LearnCMake_VERSION_MINOR="${CMAKE_PROJECT_VERSION_MINOR}"
        LearnCMake_VERSION_PATCH="${CMAKE_PROJECT_VERSION_PATCH}"
)

if(BUILD_LEARN_CMAKE_CPP)
    message(NOTICE "Building ${PROJECT_NAME}_cpp")
    #Target 1
    add_executable(${PROJECT_NAME}_cpp)
    target_sources(${PROJECT_NAME}_cpp
        PRIVATE
            src/hello.cpp
    )
endif(BUILD_LEARN_CMAKE_CPP)

if(BUILD_LEARN_CMAKE_CPP_2)
    message(NOTICE "Building ${PROJECT_NAME}_cpp_2")
    #Target 2
    add_executable(${PROJECT_NAME}_cpp_2)
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
endif(BUILD_LEARN_CMAKE_CPP_2)


#Target 3
add_executable(Sapa EXCLUDE_FROM_ALL)
target_sources(Sapa
    PRIVATE
        src/sapa.cpp
)
target_link_libraries(Sapa PRIVATE Learn++::Learn++)

include_directories(${ZeroMQ_INCLUDE_DIR})

#Target 4
add_executable(Naija99)
target_sources(Naija99
    PRIVATE
        src/naija.cpp
)
target_link_libraries(Naija99
    PRIVATE
        cppzmq libzmq-static
        termcolor::termcolor protobuf::libprotobuf
)
target_compile_features(Naija99 PRIVATE cxx_std_20)
protobuf_generate(
    TARGET
        Naija99
    LANGUAGE
        cpp
    OUT_VAR
        PROTO_FILES
    PROTOC_OUT_DIR
        ${CMAKE_CURRENT_BINARY_DIR}/generated
    IMPORT_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/scripts
    PROTOS
        scripts/x64_asm.proto
)
target_include_directories(Naija99 PRIVATE ${CMAKE_BINARY_DIR}/generated)

#Target 5
add_executable(Brume99)
target_sources(Brume99
    PRIVATE
        src/brume99.cpp
    PRIVATE
        FILE_SET CXX_MODULES
        TYPE CXX_MODULES
        FILES
            modules/src/LearnMod.cppm
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
        CXX_SCAN_FOR_MODULES ON
)
protobuf_generate(
    TARGET
        Brume99
    LANGUAGE
        cpp
    OUT_VAR
        PROTO_FILES
    PROTOC_OUT_DIR
        ${CMAKE_CURRENT_BINARY_DIR}/generated
    IMPORT_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/scripts
    PROTOS
        scripts/x64_asm.proto
)
target_include_directories(Brume99 PRIVATE ${CMAKE_BINARY_DIR}/generated)

#Assembly 
#Target 6
enable_language(ASM)
add_executable(${PROJECT_NAME}_asm)
target_sources(${PROJECT_NAME}_asm
    PRIVATE
        asm/hello.S
)
target_link_options(${PROJECT_NAME}_asm PRIVATE -nostdlib -static -Wno-unused-command-line-argument)

#C++
#Target 7
add_executable(bmtlgb1)
target_sources(bmtlgb1
    PRIVATE
        src/ui/bmtlgb-src.cpp
)
target_link_libraries(bmtlgb1 PRIVATE Slint::Slint ${FONTCONFIG_LIBRARIES})
slint_target_sources(bmtlgb1 src/ui/bmtlgb-src.slint)

if((CMAKE_CXX_COMPILER_ID STREQUAL "Clang") AND (NOT CMAKE_BUILD_TYPE MATCHES "Debug"))
    message("Using LTO")
    target_compile_options(bmtlgb1 PRIVATE -flto=thin)
    target_link_options(bmtlgb1 PRIVATE -flto=thin -fuse-ld=lld)
    set_target_properties(bmtlgb1 PROPERTIES INTERPROCEDURAL_OPTIMIZATION ON)
endif()

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif(BUILD_TESTING)


include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/LearnCMakeConfigVersion.cmake
    COMPATIBILITY AnyNewerVersion
)
configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/LearnCMakeConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/LearnCMakeConfig.cmake
  INSTALL_DESTINATION lib/cmake/LearnCMake
)


include(GNUInstallDirs)
install(
    TARGETS LearnCMake_asm Brume99 Naija99 Learnplusplus
    EXPORT LearnCMake
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/LearnCMake
)
install(
    EXPORT LearnCMake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/LearnCMake
    NAMESPACE LearnCMake::
)
install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/LearnCMakeConfigVersion.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/LearnCMakeConfig.cmake
    DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/cmake/LearnCMake
)
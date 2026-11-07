cmake_minimum_required(VERSION 4.0)

project(LearnCMake 
        LANGUAGES C CXX ASM
        VERSION 2026.10.21
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

include(FetchContent)
FetchContent_Declare(
    FTXUI
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
    GIT_TAG main
    GIT_SHALLOW true
)
FetchContent_MakeAvailable(FTXUI)

find_package(ZeroMQ REQUIRED COMPONENTS)
find_package(cppzmq REQUIRED COMPONENTS)
find_package(termcolor REQUIRED)
find_package(Protobuf CONFIG REQUIRED)
find_package(Slint CONFIG REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(FONTCONFIG REQUIRED fontconfig)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
find_package(OpenCV REQUIRED COMPONENTS core highgui imgproc imgcodecs videoio)
find_package(SFML REQUIRED COMPONENTS system window graphics audio network )

add_subdirectory(src/LearnCMake)
add_subdirectory(src/Sapa)
add_subdirectory(src/Naija)
# add_subdirectory(src/Brume99)
add_subdirectory(src/LearnCMake_asm)
add_subdirectory(src/LearnCV)


#C++
#Target 7
add_executable(bmtlgb1)
target_sources(bmtlgb1
    PRIVATE
        src/ui/bmtlgb-src.cpp
)
target_link_libraries(bmtlgb1 PRIVATE Slint::Slint ${FONTCONFIG_LIBRARIES})
slint_target_sources(bmtlgb1
    src/ui/bmtlgb-src.slint
    LIBRARY_PATHS
        BMK-ONE=${CMAKE_CURRENT_SOURCE_DIR}/src/ui/bmk-rec-src.slint
)
target_include_directories(bmtlgb1 PRIVATE ${PROJECT_BINARY_DIR})

if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Using LTO")
    target_compile_options(bmtlgb1 PRIVATE -flto)
    target_link_options(bmtlgb1 PRIVATE -flto)
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
    TARGETS LearnCMake_asm Learnplusplus #[[Brume99 Naija99 ]]
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
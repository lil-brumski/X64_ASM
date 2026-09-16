cmake_minimum_required(VERSION 4.0)

project(LearnCMake_Tests)

find_package(GTest REQUIRED)

add_executable(LearnPPTests)
target_sources(LearnPPTests
    PRIVATE
        Test_1_LC.cpp
        ../src/LearnCMake.cpp
    PRIVATE
        FILE_SET HEADERS
        BASE_DIRS
            ../include
        FILES
            ../include/LearnCMake.hpp
)
target_link_libraries(LearnPPTests PRIVATE GTest::GTest)
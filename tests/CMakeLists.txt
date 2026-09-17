#cmake_minimum_required(VERSION 4.0)

#project(LearnCMake_Tests)

find_package(GTest REQUIRED)

add_executable(LearnPPTests)
target_sources(LearnPPTests
    PRIVATE
        Test_1_LC.cpp
)
target_link_libraries(LearnPPTests PRIVATE GTest::gtest_main Learn++::Learn++)

include(GoogleTest)
gtest_discover_tests(LearnPPTests)
#include <tuple>

#include <gtest/gtest.h>

#include "LearnCMake.hpp"

TEST(LearnPP, VersionTest)
{
    EXPECT_EQ(Learn::Version(),  std::string{"2026" "." "9"  "." "15"});
}

auto main(int argc, char** argv) -> int {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

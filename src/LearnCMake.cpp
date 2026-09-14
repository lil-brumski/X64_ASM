#include <LearnCMake.hpp>

static std::tuple<std::string, std::string, std::string> LearnCMake_VERSION(){
    return {LearnCMake_VERSION_MAJOR, LearnCMake_VERSION_MINOR, LearnCMake_VERSION_PATCH};
}

std::string Learn::Version()
{
    auto [mj, mn, pt] = LearnCMake_VERSION();
    return (mj + "." + mn + "." + pt);
}

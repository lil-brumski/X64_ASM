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
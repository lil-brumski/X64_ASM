#include <slint.h>
#include <bmtlgb-src.h>
#include <cstdio>

auto main(void) -> int {
    ::setenv("SLINT_APP_ID", "Bmtlgb", 1);

    auto app = bmtlgb::create();
    app->run();

    return EXIT_SUCCESS;
}
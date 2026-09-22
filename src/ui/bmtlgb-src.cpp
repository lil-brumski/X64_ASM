#include <iostream>
#include <slint.h>
#include <bmtlgb-src.h>

auto main(void) -> int {
    auto app = bmtlgb::create();
    app->run();

    return EXIT_SUCCESS;
}
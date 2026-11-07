#include <slint.h>
#include <bmtlgb-src.h>

auto main(void) -> int {
    auto App = bmtlgb::create();
    App->run();

    return EXIT_SUCCESS;
}
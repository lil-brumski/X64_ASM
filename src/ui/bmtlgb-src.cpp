#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/app.hpp>
#include <ftxui/component/component.hpp>

auto main(void) -> int {
    std::vector<std::string> entries = {"About", "License", "Version"};
    int select = 0;
    auto bmtlgbTextColor = ftxui::color(ftxui::Color::RGB(155, 255, 55));

    ftxui::Element document = ftxui::window(ftxui::text("Bmtlgb") | ftxui::center | ftxui::bold | bmtlgbTextColor,
        ftxui::vbox({
            ftxui::text("Welcome to the Course Registration Portal") | ftxui::bold | ftxui::center | bmtlgbTextColor,
            ftxui::separator(),

            ftxui::hbox({
                ftxui::text("Username:") | ftxui::border | ftxui::bold | bmtlgbTextColor,
                ftxui::text("brume.brume") | ftxui::border | ftxui::flex,
            }),

            ftxui::hbox({
                ftxui::text("University:") | ftxui::border | ftxui::bold | bmtlgbTextColor,
                ftxui::text("Rivers State University") | ftxui::border | ftxui::flex,
            }),

            ftxui::hbox({
                ftxui::text("Password") | ftxui::border | ftxui::bold | bmtlgbTextColor,
                ftxui::text("123456") | ftxui::border | ftxui::flex,
            }),

            ftxui::hbox({
                ftxui::text("Log In") | ftxui::border | ftxui::flex | bmtlgbTextColor,
                ftxui::text("Sign Up") | ftxui::border | ftxui::flex | bmtlgbTextColor,
            }),

            ftxui::gauge(0.00) | ftxui::border,
        })
    );

    document |= ftxui::border;
    document |= ftxui::bgcolor(ftxui::Color::RGB(255, 65, 0));

    ftxui::Screen screen = ftxui::Screen::Create(ftxui::Dimension::Full(), ftxui::Dimension::Fit(document));
    ftxui::Render(screen, document);
    screen.Print();

    return EXIT_SUCCESS;
}
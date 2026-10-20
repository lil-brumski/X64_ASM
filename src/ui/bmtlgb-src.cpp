#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/app.hpp>
#include <ftxui/component/component.hpp>

auto main(void) -> int {
    std::vector<std::string> entries = {"About", "License", "Version"};
    int select = 0;

    ftxui::Element document = ftxui::vbox({
        ftxui::text("Welcome to the Course Registration Portal") | ftxui::bold | ftxui::center,
        ftxui::separator(),

        ftxui::hbox({
            ftxui::text("Username:") | ftxui::border | ftxui::bold,
            ftxui::text("brume.brume") | ftxui::border | ftxui::flex,
        }),

        ftxui::hbox({
            ftxui::text("University:") | ftxui::border | ftxui::bold,
            ftxui::text("Rivers State University") | ftxui::border | ftxui::flex,
        }),

        ftxui::hbox({
            ftxui::text("Password") | ftxui::border | ftxui::bold,
            ftxui::text("123456") | ftxui::border | ftxui::flex,
        }),
    });

    ftxui::Screen screen = ftxui::Screen::Create(ftxui::Dimension::Full(), ftxui::Dimension::Fit(document));
    ftxui::Render(screen, document);
    screen.Print();

    // ftxui::Component menu = ftxui::Menu(&entries, &select);
    // ftxui::Component component = menu | ftxui::border;
    // ftxui::App app = ftxui::App::TerminalOutput();
    // app.Loop(component);

    return EXIT_SUCCESS;
}
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

#include <iostream>

int main(){
    sf::Window MyApplication( sf::VideoMode( 800, 600 ), "Naija: Brumski sha is the best", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);

    while( MyApplication.isOpen() ){ //1
        sf::Event event;

        while( MyApplication.pollEvent(event) ) { //2
            switch( event.type ){
                case sf::Event::Closed:
                    MyApplication.close();
                    break;
                case sf::Event::Resized:
                    std::cout << "Window size: {" << event.size.width << ", " << event.size.height << "}" << std::endl;
                    break;
                case sf::Event::MouseMoved:
                    std::cout << "Mouse position: {" << event.touch.finger << ", " << event.touch.x << "}" << std::endl;
                    break;
                default:
                    std::cout << "Sup homie" << std::endl;
            }
        } //2

    } //1

    return EXIT_SUCCESS;
}
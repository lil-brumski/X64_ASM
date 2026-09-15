#include <iostream>
#include <cstdint>

#include <LearnCMake.hpp>

class Header {
public:
    std::uint8_t  version;
    std::uint32_t length;
    std::uint16_t flags;
};

int main(){
    std::cout << sizeof(std::uint8_t) << std::endl;
    std::cout << sizeof(std::uint16_t) << std::endl;
    std::cout << sizeof(std::uint32_t) << std::endl;

    std::cout << sizeof(Header) << std::endl;
    std::cout << sizeof(Gang) << std::endl;

    Gang omo;
}
#include <concepts>
#include <cstdint>

namespace Sapa {
    template<std::integral T>
    consteval T do_calculations( T aNum1, T aNum2 ){
        return aNum1 + aNum2;
    }
}

extern "C" {
    void Sapa_Main(){
        std::uint32_t tmpVar = Sapa::do_calculations<std::uint32_t>( 5, 15 );
        volatile char* vga = (volatile char*)0xB8000;
        const char* message = "Hey, my name is Brumski";

        for(std::size_t i{}; message[i] != 0; i++){
            vga[i*2] = message[i];
            vga[i*2 + 1] = 0x0F;
        }

        while( true ){
            asm volatile( "hlt" );
        }
    }
}
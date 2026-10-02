#include <concepts>
#include <type_traits>
#include <cstdint>

extern "C" {
    void Sapa_Main(){
        while(true){
            asm volatile("hlt");
        }
    }
}
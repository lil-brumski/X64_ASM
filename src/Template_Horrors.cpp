#include <iostream>

///@brief This function can take any number of arguments
/**
* @param aValues
*/
template<typename... Lmao>
void brochaho( Lmao&&... aValues ){
    constexpr std::size_t si = sizeof...(aValues) - 1;
    for(const auto& hehe: (aValues, ...)){
        std::cout << hehe << std::endl;
    }

    ((std::cout << "The values are ") << ... << aValues) << std::endl;
}

int main(){
    //brochaho(2, ' ', 3, ' ', "Tare");
    brochaho(3, " ", 4, " ", "Omo");
}
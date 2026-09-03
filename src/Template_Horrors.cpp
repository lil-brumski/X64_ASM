#include <iostream>

namespace Brume {
/**
 * @brief function can take any number of arguments
 *
 * @param aValues
 */
template <class... Lmao> void brochaho(Lmao &&...aValues) {
  constexpr std::size_t si = sizeof...(aValues) - 1;
  
  ((std::cout << "The values are ") << ... << aValues) << std::endl;
}
}

int main(){
    //brochaho(2, ' ', 3, ' ', "Tare");
    Brume::brochaho(3, " ", 4, " ", "Omo");
}
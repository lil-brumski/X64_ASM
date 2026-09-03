#include <iostream>

/**
 * @file Template_Horrors.cpp
 * 
 * @brief I don't know man
 * 
 * Blah blah blah gang
 */

/**
 * @fn void<Lmao...> brochaho( Lmao&&... aValues )
 * 
 * @brief Function can take any number of arguments
 *
 * @param aValues
 */
template <class... Lmao> void brochaho( Lmao&&... aValues ) {
  constexpr std::size_t si = sizeof...(aValues) - 1;
  
  ((std::cout << "The values are ") << ... << aValues) << std::endl;
}

int main(){
    brochaho(3, " ", 4, " ", "Omo");
}
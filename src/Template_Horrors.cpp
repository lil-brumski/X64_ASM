#include <iostream>
#include <functional>
/**
 * @file Template_Horrors.cpp
 * 
 * @brief I don't know man
 * 
 * Blah blah blah gang
 */

 /**
  * @requirement REQ-TEMP-101 Multiple Arguments Function
  * @brief We need a function that can take any number of arguments
  * 
  * How can we do this gang?
  */

/**
 * @fn void brochaho( Lmao&&... aValues )
 * 
 * @brief Function can take any number of arguments
 *
 * @param aValues
 * 
 * Examples of some data types allowed:
 *  -# int
 *  -# float
 *  -# double
 * 
 * @satisfies REQ-TEMP-101 Implements a Function that can take n arguments (n = 1, 2, 3...)
 */
template <class... Lmao> void brochaho( Lmao&&... aValues ) {
  constexpr std::size_t si = sizeof...(aValues) - 1;
  
  ((std::cout << "The values are ") << ... << aValues) << std::endl;
}

/**
 * @fn void TestMultFunc()
 * 
 * @brief I don't know gang
 * 
 * Oh boy stand up and be counted
 * 
 * @verifies REQ-TEMP-101 Good Boy
 */
void TestMultFunc(){
  std::cout << "Gang" << std::endl;
}

/**
 * @brief Just your average global variable
 * 
 * Sup homie?
 */
const std::function<void()>& TMF = TestMultFunc;

int main()
{
  TMF();
}
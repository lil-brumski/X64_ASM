#include <iostream>
#include <functional>
/**
 * @defgroup GRP1 Group 1 Gang
 * Hehehehehehehe
 * @{
 * @file Template_Horrors.cpp
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

 namespace Brume {

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
 *
 * @}
 */
const std::function<void()>& TMF = TestMultFunc;

 }

/**
* Here is an inline summation: sike.
*
* The distance between \f$(x_1,y_1)\f$ and \f$(x_2,y_2)\f$ is \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.
*
*/
int main()
{
  Brume::TMF();
}

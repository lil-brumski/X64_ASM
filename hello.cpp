#include <iostream>
#include <typeinfo> // Required for std::type_info

/**
*...Learning Docs...
*/
namespace Brume{

    /** 
    *...Base Class...
    *
    * That's right
    */
    class Base {
    public:

        /// @brief Virtual method
        /**
         * @param volume
         */
        virtual void speak(int volume) { std::cout << "Base branch\n"; } 

        /// @brief Default destructor
        /**
         * @see Brume::Base::speak()
         */
        virtual ~Base() = default;
    };

    class Derived : public Base {
    public:
        void speak(int volume) override { std::cout << "Derived branch\n"; }
         void uniqueAction() { std::cout << "Derived-only feature code\n"; }
    };
}


int main() {
  Brume::Base *basePtr = new Brume::Derived();

  // 1. Using typeid to query the exact runtime type
  std::cout << "Runtime type: " << typeid(*basePtr).name() << "\n";

  // 2. Using dynamic_cast for safe downcasting
  Brume::Derived *derivedPtr = dynamic_cast<Brume::Derived *>(basePtr);

  if (derivedPtr != nullptr) {
    derivedPtr->uniqueAction(); // Safe to execute
  } else {
    std::cout << "Invalid type conversion sequence\n";
  }

  delete basePtr;
  return 0;
}

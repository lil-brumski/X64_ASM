#include <iostream>
#include <typeinfo> // Required for std::type_info

/**
 *Brumski's doxygen learning journey begins here!
 */
namespace Brume{

    /** 
    *Base Class obviously...
    *
    * That's right
    */
    class Base {
    public:

        /** 
         * @brief Virtual method
         * @param volume
         * @return Nothing, this is a void function duh.
         */
        virtual void speak(int volume) { std::cout << "Base branch\n"; } 

        /// @brief Default destructor
        /**
         * @see speak()
         */
        virtual ~Base() = default;

        int id; ///<This is a comment obviously

    private:
        int d; ///<Private comment, mad oh
    };

    /**
     * Child class
     */
    class Derived : public Base {
    public:

      /// @brief Overridden method
      /**
       * @param volume
       */
      [[deprecated("Lmao, figure it out yourself gang :)")]]
      void speak(int volume) override {
        std::cout << "Derived branch\n"; }
        
      /**
       * @brief boring function
       */
      void uniqueAction() { std::cout << "Derived-only feature code\n"; }

      /// @brief Default destructor
      /**
       * @see speak()
       */
      virtual ~Derived() override = default;
    };
}


int main() {
  Brume::Base *basePtr = new Brume::Derived();

  // 1. Using typeid to query the exact runtime type
  std::cout << "Runtime type: " << typeid(*basePtr).name() << "\n";

  // 2. Using dynamic_cast for safe downcasting
  Brume::Derived *derivedPtr = dynamic_cast<Brume::Derived *>(basePtr);
  std::cout << "Runtime type: " << typeid(*derivedPtr).name() << "\n";

  if (derivedPtr != nullptr) {
    derivedPtr->uniqueAction(); // Safe to execute
    derivedPtr->speak(23);
  }
  else
  {
    std::cout << "Invalid type conversion sequence\n";
  }

  delete basePtr;
  return 0;
}
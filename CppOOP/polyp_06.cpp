// The override specifier
//     > We can override Base class virtual functions
//     > The function signature and return must be EXACTLY the same
//     > If they are different then we have redefinition NOT overriding
//     > Redefinition is statically bound
//     > Overriding is dynamically bound
//     > C++11 provides an override specifier to have the compiler ensure overriding


//   g++ -o a.exe polyp_06.cpp
//  .\a.exe

// Using override

#include <iostream>

class Base {
    public:
        virtual void say_hello() const {
            std::cout << "Hello - I'm a Base class object" << std::endl;
        }
        virtual ~Base() {}
};

class Derived: public Base {
    public:
        virtual void say_hello()  const override {             // without const  -- it will be overloaded
            std::cout << "Hello - I'm a Derived class object" << std::endl;
        }
        virtual ~Derived() {}
}; 

int main() {
    
    Base *p1 = new Base();      // Base::say_hello()
    p1->say_hello();
    
    Derived *p2 = new Derived();    // Derived::say_hello()
    p2->say_hello();
    
    Base *p3 = new Derived();   //  Base::say_hello()   ?????   I wanted Derived::say_hello()
    p3->say_hello();
    
    return 0;
}
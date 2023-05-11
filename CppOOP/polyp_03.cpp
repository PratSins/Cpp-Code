/*
Virtual functions
    > Redefined functions are bound statically
    > Overridden functions are bound dynamically
    > Virtual functions are overridden
    > Allow us to treat all objects generally as objects of the Base class

Declaring virtual functions
    + Override the function in the Derived classes
    + Function signature and return type must match EXACTLY
    + Virtual keyword not required but is best practice
    + If you don't provide an overridden version it is inherited from it’s base class

*/
// Virtual functions
#include <iostream>

//   g++ -o a.exe polyp_03.cpp
//  .\a.exe

// This class uses dynamic polymorphism for the withdraw method
class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
};

class Savings: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
};

int main() {
    std::cout << "\n === Pointers ==== " << std::endl;
    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();
    
    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);
    

    std::cout << "\n === Clean up ==== " << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
        
    return 0;
}

/*
A virtual function in C++ helps ensure you call the correct function via a reference or pointer. 
The C++ programming language allows you only to use a single pointer to refer to all the derived class objects. 
Since the pointer refers to all the derived objects, calling it will consistently execute the function in the base class. 

You can overcome this challenge with a virtual function in C++ 
as it helps execute the virtual version of the derived class, which is done at the run-time.
*/
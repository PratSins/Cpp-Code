#include <iostream>

using namespace std;

//   g++ -o a.exe 04_inheritance.cpp
//  .\a.exe

class Base {
private:
    int value;
public:
   Base() : value {0}  { 
            cout << "Base no-args constructor" << endl; 
    }
    Base(int x)  : value {x} { 
            cout << "Base (int) overloaded constructor" << endl;
    }
   ~Base() { 
       cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
private:
    int doubled_value;
public:
    Derived()
        :Base {}, doubled_value {0} {
            cout << "Derived no-args constructor " << endl; 
    }
    Derived(int x) 
        :  Base{x},  doubled_value {x * 2} { 
            cout << "Derived (int) constructor" << endl; 
    }
    ~Derived() { 
        cout << "Derived destructor " << endl; 
    } 
};

int main() {
   //  Derived d;
   Derived d {1000};
    return 0;
}

/*
Constructors and class initialization
                                  --OUTPUT--
Base base;                        Base no-args constructor

Base base{100};                   int Base constructor
 
Derived derived;                  Base no-args constructor
                                  Derived no-args constructor

Derived derived{100};             int Base constructor
                                  int Derived constructor

*/
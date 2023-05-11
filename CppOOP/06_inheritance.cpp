// Section 15
// Redefining and Using Base Class Methods
#include <iostream>
#include "Savings_Account2.h"

using namespace std;

//   g++ -o a.exe 06_inheritance.cpp Savings_Account2.cpp Account2.cpp
//  .\a.exe

int main() {
    cout << "\n===== Account2 class ===================" << endl;
    Account2 a1 {1000.0};
    cout << a1 << endl;         // Account2 balance: 1000
    
    a1.deposit(500.0);
    cout << a1 << endl;         // Account2 balance: 1500
    
    a1.withdraw(1000);            // Account2 balance: 500
    cout << a1 << endl;
    
    a1.withdraw(5000.0);         // Insufficient funds
    cout << a1 << endl;         // Account2 balance: 500

 cout << "\n===== Savings Account2 class ===========" << endl;
    Savings_Account2 s1 {1000, 5.0}; 
    cout << s1 << endl;         // Savings Account2 balance: 1000, Interest rate: 5
    
    s1.deposit(1000);
    cout << s1 << endl;          // Savings Account2 balance: 2050, Interest rate: 5
    
    s1.withdraw(2000);
    cout << s1 << endl;          // Savings Account2 balance: 50, Interest rate: 5
    
    s1.withdraw(1000);            // Insufficient funds
    cout << s1 << endl;         // Savings Account2 balance: 50, Interest rate: 5
    
    
    return 0;
}




#include "Account2.h"
// Simple Account2 class

Account2::Account2() 
    : Account2(0.0) {    // delegating constructor
}
        
Account2::Account2(double balance)
    : balance(balance) { 
}
            
void Account2::deposit(double amount) {   
    balance += amount;
}
    
void Account2::withdraw(double amount) {
    if (balance-amount >= 0)
        balance-=amount;
    else    
        std::cout << "Insufficient funds" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Account2 &Account2) {
    os <<  "Account2 balance: " << Account2.balance;
    return os;
}

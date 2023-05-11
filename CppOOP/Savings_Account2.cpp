#include "Savings_Account2.h"

Savings_Account2::Savings_Account2(double balance, double int_rate)
    : Account2(balance), int_rate{int_rate} {
        
    }

Savings_Account2::Savings_Account2() 
    : Savings_Account2{0.0, 0.0} {
        
    }
    
void Savings_Account2::deposit(double amount) {
    amount = amount + (amount * int_rate/100);
    Account2::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Savings_Account2 &Account2) {
    os << "Savings Account2 balance: " << Account2.balance << " Interest rate: " << Account2.int_rate;
    return os;
}
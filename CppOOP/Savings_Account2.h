#ifndef _SAVINGS_Account2_H_
#define _SAVINGS_Account2_H_
#include "Account2.h"

// Savings Account2 class 
// Deposit method increments amount to be deposited by amount * int_rate percentage!!
// So a 1000 deposit at 5% interest rate will deposit 1000 + 50 = 1050

// Withdraw method does not specialize

class Savings_Account2: public Account2 {
    friend std::ostream &operator<<(std::ostream &os, const Savings_Account2 &Account2);
protected:
    double int_rate;
public:
    Savings_Account2();
    Savings_Account2(double balance, double int_rate);
    void deposit(double amount);
    // Withdraw is inherited
};

#endif // _SAVINGS_Account2_H_

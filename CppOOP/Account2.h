#ifndef _ACCOUNT2_H_
#define _ACCOUNT2_H_
#include <iostream>

// Simple Account class
class Account2 {
    friend std::ostream &operator<<(std::ostream &os, const Account2 &account);
protected:
    double balance;
public:
    Account2();
    Account2(double balance);            
    void deposit(double amount); 
    void withdraw(double amount);
};

#endif // _ACCOUNT2_H_

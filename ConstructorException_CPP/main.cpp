#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"

using namespace std;

// g++ -o a.exe main.cpp Account.cpp Checking_Account.cpp Trust_Account.cpp Savings_Account.cpp I_Printable.cpp Account_Util.cpp 

int main() {
    try {
        // unique_ptr<Account> moes_account = make_unique<Checking_Account>("Moe", -10.0);
        unique_ptr<Account> moes_account = make_unique<Checking_Account>("Moe", 10.0);
        cout << *moes_account << endl;
    }
    catch (const IllegalBalanceException &ex)
    {
        cerr << "Couldn't create account - negative balance" << endl;
    }
    cout << "Program completed successfully" << endl;
    return 0;
}


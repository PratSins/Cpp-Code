// Smart Pointers
// Unique Pointers 
#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Savings_Account.h"
//   g++ -o a.exe uniquePtr_main.cpp Account.cpp Checking_Account.cpp Trust_Account.cpp Savings_Account.cpp I_Printable.cpp

using namespace std;

class Test 
{
    private:
        int data;
    public:
        Test() : data{0} {  cout << "Test constructor (" << data << ")" <<  endl; }

        Test(int data) : data {data} {  cout << "Test constructor (" << data << ")" <<  endl; }

        int get_data() const {return data; }
        
        ~Test() { cout << "Test destructor (" << data << ")" <<  endl; }
};



int main() 
{
    // Test *t1 = new Test {1000};
    // delete t1;
    unique_ptr<Test> t1 {new Test{100}};
    unique_ptr<Test> t2 = make_unique<Test>(1000);
  
    unique_ptr<Test> t3;
    t3 = move(t1);

    if (!t1) 
       cout << "t1 is nullptr" <<  endl;
    

    unique_ptr<Account> a1 =  make_unique<Checking_Account>("Moe", 5000);
    cout << *a1 <<  endl;
    a1->deposit(5000);
    cout << *a1 <<  endl;
    vector< unique_ptr<Account>> accounts;
    accounts.push_back( make_unique<Checking_Account>("James", 1000));
    accounts.push_back( make_unique<Savings_Account>("Billy", 4000, 5.2));
    accounts.push_back( make_unique<Trust_Account>("Bobby", 5000, 4.5));
    
    cout<<"\nLoop\n";
    for (const auto &acc: accounts)
        cout << *acc <<  endl;
    
    return 0;
}


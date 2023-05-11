// Section 14 ---> Mystring - starting point
#include <iostream>
#include "Mystring.h"

using namespace std;
// g++ -o ovld.exe OptrOvrld.cpp Mystring.cpp
// .\ovld.exe
int main()
{
    Mystring empty;
    //Mystring larry("Larry");
    Mystring larry {"Larry"}; // change in brackets {} and () from previous line..
    Mystring stooge {larry};

    empty.display();
    larry.display();
    stooge.display();

    return 0;
}
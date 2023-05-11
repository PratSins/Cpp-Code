#include <iostream>
#include <vector>
#include "Mystring2.h"

using namespace std;

//   g++ -o a.exe OptrOvld_4.cpp Mystring2.cpp
//  .\a.exe

int main() {
    
    Mystring2 larry {"Larry"};
    larry.display();                                        // Larry
    
    larry = -larry;
    larry.display();                                        // larry
    
    cout << boolalpha << endl;
    Mystring2 moe{"Moe"};
    Mystring2 stooge = larry;
    
    cout << (larry == moe) << endl;             // false
    cout << (larry == stooge) << endl;          // true
        
  //  Mystring2 stooges = larry + "Moe";   
    Mystring2 stooges = "Larry" + moe;           // Now OK with non-member function
    stooges.display();                                      // LarryMoe
    
    Mystring2 two_stooges = moe + " " + "Larry";     
    two_stooges.display();                               // Moe Larry
    Mystring2 three_stooges = moe + " " + larry + " " +  "Curly";
    three_stooges.display();                            // Moe larry Curly             

    return 0;
}
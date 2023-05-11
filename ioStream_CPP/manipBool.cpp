// Stream manipulators - Boolean
// boolalpha and Noboolalpha

#include <iostream>
#include <iomanip>  // Must include for manipulators

using namespace std;

int main()
{
  
    cout << "Noboolalpha - default  (10 == 10) : " << (10 == 10)  << endl;
    cout << "Noboolalpha - default  (10 == 20) : " << (10 == 20)  << endl << endl;
    
    // Set to true/false formatting
    cout << boolalpha;    // change to true/false
    cout << "boolalpha   (10 == 10) : " << (10 == 10)  << endl;
    cout << "boolalpha   (10 == 20) : " << (10 == 20)  << endl << endl;
    
     // setting still stays for future boolean insertions
    cout << "boolalpha   (10 == 10) : " << (10 == 10)  << endl;
    cout << "boolalpha   (10 == 20) : " << (10 == 20)  << endl << endl;
    
    // Toggle to 0/1
    cout << noboolalpha;
    cout << "Noboolalpha  (10 == 10) : " << (10 == 10)  << endl;
    cout << "Noboolalpha  (10 == 20) : " << (10 == 20)  << endl << endl;
    
    // Set back to true/false using setf method
    cout.setf(ios::boolalpha);
    cout << "boolalpha   (10 == 10) : " << (10 == 10)  << endl;
    cout << "boolalpha   (10 == 20) : " << (10 == 20)  << endl << endl;
    
    // resets to default which is 0/1
    cout << resetiosflags(ios::boolalpha);
    cout << "Default  (10 == 10) : " << (10 == 10)  << endl;
    cout << "Default  (10 == 20) : " << (10 == 20)  << endl << endl;
    return 0;
}


// Continuous read of 3 data items in a loop
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() 
{
    ifstream in_file;
    string line;
    int num;
    double total;
    
    in_file.open("./test2.txt");
    if (!in_file) {
        cerr << "Problem opening file" << endl;
        return 1;
    }
    while (in_file >> line >> num >> total) {
        cout << setw(10) << left << line 
                       << setw(10) << num 
                       << setw(10)  << total
                       << endl;
    }
    in_file.close();
    return 0;
}


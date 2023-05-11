// Read and display Shakespeare Sonnet 18 poem using getline
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cout<<endl;
    ifstream in_file;
    in_file.open("./poem.txt");
    if (!in_file) {
        cerr << "Problem opening file" << endl;
        return 1;
    }
    string line{};
    while (getline(in_file, line)) {
        cout << line << endl;
    }
    
    // Alternate method to execute
    // char c {};
    // while (in_file.get(c)) {
    //     std::cout << c;
    // }
    
    in_file.close();
    cout<<endl;

    return 0;
}
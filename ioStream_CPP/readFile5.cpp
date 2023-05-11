// Word counter
#include <iostream>
#include <fstream>

using namespace std;

// return true if the string word_to_find is in the target string
bool find_substring(const string &word_to_find, const string &target) 
{
    size_t found = target.find(word_to_find);
    if (found == string::npos)
        return false;
    else
        return true;
}

int main() {
    ifstream in_file {};
    string word_to_find {};
    string word_read {};
    int word_count {0};
    int match_count {0};
    
    // in_file.open("./romeoandjuliet.txt");
    in_file.open("./poem.txt");
    if (!in_file) 
    {
        cerr << "Problem opening file" << endl;
        return 1;
    }
   
    cout << "Enter the substring to search for: ";
    cin >> word_to_find;
    while (in_file >> word_read) 
    {
        ++word_count;
        if (find_substring(word_to_find, word_read)) 
        {
           ++match_count;
        //    cout << word_read << " ";
        }        
    }

    cout << word_count << " words were searched..." << endl;
    cout << "The substring " << word_to_find << " was found " << match_count << " times " << endl;
    
    in_file.close();
    cout << endl;
    return 0;
}

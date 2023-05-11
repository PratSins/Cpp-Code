#include <iostream>
#include <map> // std::map
#include <set>

using namespace std;

void display(const map<string, set<int>> &m) {
    cout << "[ ";
    for (const auto &elem: m) {
        cout << elem.first << ": [ " ;
            for (const auto &set_elem : elem.second)
                 cout << set_elem <<  " ";
            cout << "] " ;
    }
    cout << "]  " << endl;
}

template <typename T1, typename T2>
void display(const map<T1, T2> &l) {
    cout << "[ ";
    for (const auto &elem: l) {
        cout << elem.first << ":" << elem.second << " ";
    }
    cout << "]  " << endl;
}

void test1() {
    // Maps
    cout << "\nTest1 =========================" << endl;
    map<string, int> m {
        {"Larry", 3},
        {"Moe", 1},
        {"Curly", 2}
    };
    display(m);      
    
    m.insert( pair<string, int>("Anna", 10));
    display(m);
    
    m.insert(make_pair("Joe", 5));
    display(m);
    
    m["Frank"] = 18;
    display(m);
    
    m["Frank"] += 10;               
    display(m);
    
    m.erase("Frank");
    display(m);
    
    cout << "Count for Joe: " << m.count("Joe") << endl;
    cout << "Count for Frank: " << m.count("Frank") << endl;
    
    auto it = m.find("Larry");
    if (it != m.end())
        cout << "Found: " << it->first << " : " << it->second << endl;    
        
    m.clear();
    
    display(m);

}

void test2() {
    cout << "\nTest2 =========================" << endl;
    
    map<string, set<int>> grades  {
        {"Larry", {100, 90} },
        {"Moe",  {94} },
        {"Curly", {80, 90, 100} }
    };
    
    display(grades);
    
    grades["Larry"].insert(95);                 // insert 95 into the set of grades for "Larry"
    
    display(grades);
    
    auto it = grades.find("Moe");
    if (it != grades.end())                         // found "Moe"
    {
            it->second.insert(1000);            // insert 1000 into Moe's set of grades
    }                                                         // it->first is the key, it->second is the value (set)
    display(grades);
}

void test3()
{
    cout << "\nTest3 =========================" << endl;
     map<string, int> m {
        {"Larry", 3},
        {"Moe", 1},
        {"Curly", 2}
    };

    cout << m.size()<<endl;
    cout << m.max_size() << endl;
}


int main() {
    test1();
    test2();
    test3();
    return 0;
}

/*
std::multimap
#include <map>
    • Ordered by key
    • Allows duplicate elements
    • All iterators are available

std:: unordered_map
#include <unordered_map>
    • Elements are unordered
    • No duplicate elements allowed
    • No reverse iterators are allowed

std::unordered_multimap
#include <unordered_map>
    • Elements are unordered
    •Allows duplicate elements
    • No reverse iterators are allowed
*/
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator> // for advance
#include <forward_list>

using namespace std;

class Person 
{
        friend ostream &operator<<(ostream &os, const Person &p);
        string name;
        int age;
    public:
        Person() : name{"Unknown"}, age{0} {}
        Person(string name, int age) 
            : name{name}, age{age}  {}

        bool operator<(const Person &rhs) const {
            return this->age < rhs.age;
        }
        
        bool operator==(const Person &rhs) const {
            return (this->name == rhs.name && this->age == rhs.age);
        }
};

ostream &operator<<(ostream &os, const Person &p) 
{
    os << p.name << ":" << p.age;
    return os;
}


template <typename T>
void display(const list<T> &l) 
{
    cout << "[ ";
    for (const auto &elem: l) {
        cout << elem << " ";
    }
    cout << "]" << endl;
}

template <typename T>
void display2(const forward_list<T> &l) 
{
    cout << "[ ";
    for (const auto &elem: l) {
        cout << elem << " ";
    }
    cout << "]" << endl;
}

void test1() 
{
    cout << "\nTest1 =========================" << endl;

    list<int> l1 {1,2,3,4,5};
    display(l1);
    
    list<string> l2;
    l2.push_back("A");
    l2.push_back("B");
    l2.push_back("BC");
    l2.push_back("Back");
    l2.push_front("D");
    l2.push_front("E");
    l2.push_front("Front");
    display(l2);

    l2.pop_back();
    l2.pop_front();
    display(l2);

    l2.emplace_back("Larry");
    l2.emplace_front("Moe");
    
    list<int> l3;
    l3 = {1,2,3,4,5,6,7,8,9,10};
    display(l3);
    
    list<int> l4 (10, 100);
    display(l4);
}

void test2() 
{
    cout << "\nTest2 =========================" << endl;

    list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);
    cout << "Size: " << l.size() << endl;
    
    cout << "Front : " << l.front() << endl;
    cout << "Back  : " << l.back() << endl;
    
    l.clear();
    display(l);
    cout << "Size: " << l.size() << endl;
    cout << "Max_Size: " << l.max_size() << endl;
}

void test3() 
{
    cout << "\nTest3 =========================" << endl;

    list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);
    
    l.resize(5);
    display(l);
    
    l.resize(10);
    display(l);
    
    list<Person> persons;
    persons.resize(5);             // uses the Person default constructor
    display(persons);
    
}
void test4() 
{
    cout << "\nTest4 =========================" << endl;

    list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);
    // auto - std::list<int>::iterator &
    auto it = find(l.begin(), l.end(), 5);
    if (it != l.end()) {
        l.insert(it, 100);
    }
    display(l);
    
    list<int> l2 {1000,2000,3000};
    l.insert(it, l2.begin(), l2.end());
    display(l);
    
    advance(it, -4);       // point to the 100
    // works on bidirectional iterator only - in this case it is
    cout << *it << endl;
    
    l.erase(it);                    // remove the 100 - iterator becomes invalid
    display(l);
    
}

void test5() 
{
    cout << "\nTest5 =========================" << endl;

    list<Person>  stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 17}
    };
    
    display(stooges);
    string name;
    int age{};
    cout << "\nEnter the name of the next stooge: ";
    getline(cin, name);
    cout << "Enter their age: ";
    cin >> age;
    
    // stooges.emplace_back(name, age);
    stooges.emplace_back(Person{name, age});
    // both works
    
    display(stooges);
    
    // Insert Frank before Moe
    auto it = find(stooges.begin(), stooges.end(), Person{"Moe", 25});
    if (it != stooges.end())
        stooges.emplace(it, "Frank", 18);
    display(stooges);    
}

void test6() 
{
    cout << "\nTest6 =========================" << endl;
    
    list<Person>  stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 17}
    };
    
    display(stooges);
    stooges.sort();
    display(stooges);
}

void test7()
{
    cout << "\nTest7 =========================" << endl;
    forward_list<int> l {1,2,3,4,5};
    // std::cout << l.size (); --- NOT AVAILABLE
    cout << l.max_size()<< endl;
    
    cout << l.front()<<endl;
    // std::cout << l.back(); --- NOT AVAILABLE

    display2(l);

    l.push_front(6);
    l.push_front(7);
    display2(l);
    l.emplace_front(9);
    display2(l);

    auto it = find(l.begin(), l.end(), 3);
    l.insert_after(it, 10);
    display2(l);

    l.emplace_after(it, 100);
    display2(l);

    l.erase_after(it);
    display2(l);

    l.resize(2);
    display2(l);

    l.resize(5);
    display2(l);

}

int main() {
    
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    cout << endl;
    return 0;
}
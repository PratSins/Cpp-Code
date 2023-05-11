// Stateless lambda expressions
// [] - empty capture lists
#include <iostream>
#include <string>
#include <vector>
#include <functional>   // for function
#include <algorithm>
using namespace std;

class Person 
{
        friend ostream &operator<<(ostream &os, const Person &rhs);
    private:
        string name;
        int age;
    public:
        Person(string name, int age) : name{name}, age{age} {};
        Person(const Person &p): name{p.name}, age{p.age} { }
        ~Person() = default;

        string get_name() const { return name; }

        void set_name(string name) {this->name = name; };

        int get_age() const {return age; }
        
        void set_age(int age) {this->age = age; }
};

ostream &operator<<(ostream &os, const Person &rhs) 
{
    os << "[Person: " <<rhs.name << " : " <<rhs.age << "]";
    return os;
}

void test1() 
{
    cout << "\n---Test1 --------------------------" << endl;

    [] () {cout << "Hi" << endl; }();
    
    [] (int x) { cout << x << endl;}(100);
    
    [](int x, int y) { cout << x+y << endl; }(100,200);
}

// Using values and references as lambda parameters 
void test2() 
{
    cout << "\n---Test2 --------------------------" << endl;
    
    auto l1 =   [] () {cout << "Hi" << endl;};
    l1();
    
    int num1 {100};
    int num2 {100};

    auto l2 = [](int x, int y) { cout << x+y << endl; };
    l2(10,20);
    l2(num1, num2);
    
    auto l3 = [](int &x, int y) {
        cout << "x: " << x << " y: " << y << endl;
        x = 1000;
        y = 2000;
    };
    
    l3(num1, num2);
    cout << "num1: " << num1 << " num2: " << num2 << endl;
}

// Using value and reference objects as lambda parameters
void test3() 
{
    cout << "\n---Test3 --------------------------" << endl;
    Person stooge {"Larry", 18};
    cout << stooge << endl;
    
    auto l4 = [] (Person p) {
        cout << p << endl; 
    };
    l4(stooge);
    
    auto l5 = [] (const Person &p) {
        cout << p << endl; 
    };
    l5(stooge);
    
    auto l6 = [] (Person &p) {
        p.set_name("Frank");
        p.set_age(25);
        cout << p << endl; 
    };
    l6(stooge);
    
    cout << stooge << endl;
    
}

// used for test4 using function as a parameter in C++14 and greater or auto as parameter type in C++20

//void filter_vector (const vector<int>  &vec, auto func) {
void filter_vector(const vector<int> &vec, function<bool(int)> func)   
{
    cout <<"[ ";
    for (int i: vec) 
    {
        if (func(i)) 
            cout << i  << " ";
    }
    cout << "]" << endl;
}

// passing a lambda to a function
void test4() 
{
    cout << "\n---Test4 --------------------------" << endl;
    vector<int> nums {10,20,30,40,50,60,70,80,90,100};
    
    filter_vector(nums, [](int x) {return x>50;});
    
    filter_vector(nums, [](int x) {return x<=30;});
    
    filter_vector(nums, [](int x) {return x>= 30 && x <=60;});
}

// used for test5
auto make_lambda() 
{
	return [] () {cout << "This lambda was made using the make_lambda function!" << endl;};
}

// returning a lambda from a function
void test5() 
{
	cout << "\n---Test5 --------------------------" << endl;
	
	auto l5 = make_lambda();
	
	l5();
}

// using auto in the lambda parameter list
void test6() 
{
    cout << "\n---Test6 --------------------------" << endl;
    auto l6 = [](auto x, auto y) {
        cout << "x: " << x << " y: " << y << endl;
    };
    
    l6(10,20);
    l6(100.3, 200);
    l6(12.5, 15.54);
    
    l6 (Person("Larry", 18), Person("Curly", 22));
}

// Simple lambda examples with sort and for_each
void test7() 
{
      cout << "\n---Test7 --------------------------" << endl;

    vector<Person> stooges {
        {"Larry", 18},
        {"Moe", 30},
        {"Curly", 25}
    };
    sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2) {
        return p1.get_name() < p2.get_name();
    });
    
    for_each(begin(stooges), end(stooges), [](const Person &p) {
        cout << p << endl;
    });
    
    cout << endl;
    
     sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2) {
        return p1.get_age()< p2.get_age();
    });
    
    for_each(begin(stooges), end(stooges), [](const Person &p) {
        cout << p << endl;
    });
}

int main()
{
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

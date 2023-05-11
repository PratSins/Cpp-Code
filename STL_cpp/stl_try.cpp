#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define SQUARE(a) ((a)* (a)) // note the parenthesis

using namespace std;

struct Square_Functor {
    void operator() (int x) { // overload () operator
        cout << x * x << " ";
    }
};

void sq(int x) {
        cout << x * x << " ";
}

int main()
{
    vector<int> v{1,5,3,2,8,6};

    reverse(v.begin(), v.end());//<algorithm>
    for(auto i: v)
        cout<<i<<" ";
    cout<<endl;

    sort(v.begin(), v.end());//<algorithm>
    for(auto i: v)
        cout<<i<<" ";
    cout<<endl;

    int sum{};
    sum = accumulate(v.begin(), v.end(), 0); //<numeric>
    cout << "\nSum of elements of vector - " << sum<<endl;

    cout<<"\n======Using #define==========\n";
    cout << "\nSquare(a)  -  " << SQUARE(5) ;
    cout << "\n((5)*(5))  -  " << ((5)*(5)) ;

    cout<<"\n\n======ITERATORS==========\n";
    vector<int> vec {1,2,3};
    vector<int>::iterator it = vec.begin();
    while ( it != vec.end () ) 
    {
        cout << *it << " ";
        ++it;
    }
    // for (auto it = vec.begin (); it != vec.end(); it++) {
    //     cout << *it << " ";
    // }
    cout<<endl<<"Reverse Iterator - ";
    vector<int> v1 {1,2,3};
    vector<int>::reverse_iterator it1 = v1.rbegin();
    while ( it1 != v1.rend() ) 
    {
        cout << *it1 << " ";
        ++it1;
    }
    cout<<endl;

    cout<<"\n====Using std::find()====\n";
    vector<int> v3 {1,2,3,5,7,9,12,23,4};
    auto loc = find(v3.begin(), v3.end(), 10); //loc points at the end of the vector if it element is not found
    cout<<"-";
    if( loc != v3.end() )
        cout << *loc <<endl;
    auto loc1 = find(v3.begin(), v3.end(), 7);
    cout<<"\n-";
    if( loc1 != v3.end() )
        cout << *loc1 <<endl;
    
    cout<<"\n\n====Using for_each - using a Functor====\n";
    Square_Functor square;  // Function object
    vector<int> v2 {1, 2, 3, 4};
    for_each(v2.begin(), v2.end(), square);

    cout<<"\n\n====Using for_each - using a function pointer====\n";
    vector<int> v4 {5, 6, 7, 8};
    for_each(v4.begin(), v4.end(), sq);

    cout<<"\n\n====Using for_each - using a Lambda function====\n";
    vector<int> v5 {9, 10, 11, 12};
    for_each(v5.begin(), v5.end(),  [] (int x) { cout << x*x << " ";  }  );

    return 0;
}
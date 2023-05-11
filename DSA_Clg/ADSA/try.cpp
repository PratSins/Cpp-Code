#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[] {0,1,2,3,4};
    for(int &x:a)
       x+=5;

    for(int x:a)
        cout<<x<<endl;

    int p{10};
    cout<<"shit "<<&p<<endl;
    return 0;





}
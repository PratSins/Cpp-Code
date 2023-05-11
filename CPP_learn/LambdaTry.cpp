#include <iostream>
#include <vector>
using namespace std;

void print_if(vector<int> nums, bool (*predicate) (int)) 
{
    for (int i: nums){
        if (predicate (i))
            cout << i << " ";
    }
    cout<<endl;
}

int main()
{
    // Simple Stateless Lambda Expression
    const int n = 31;
    int nums [n] {10,20, 30};
    auto sum = [] (int nums [], int n) {
        int sum {0};
        for (int i = 0; i < n; i++)
            sum += nums [i];
        return sum;
    };
    cout << sum (nums, 3)<< endl;

    int test_score1 = 88;
    int test_score2 = 75;
    auto bonus = [] (int &score1, int &score2, int bonus_points) {
                score1 += bonus_points;
                score2 += bonus_points;
            };
    bonus(test_score1, test_score2, 5);

    // auto bonus = [] (int *score1, int *score2, int bonus_points) {
    //             *score1 += bonus_points;
    //             *score2 += bonus_points;
    //         };
    // bonus(&test_score1, &test_score2, 5);

    cout << "test score1: " << test_score1 << endl;
    cout << "test score2: " << test_score2 << endl;

    vector<int> test_scores {93,88, 75, 68,65};
    auto bonus1 = [] (vector<int> &scores, int bonus_points) {
                            for (int &score: scores)
                                score += bonus_points;
                        };
    bonus1(test_scores, 5);
    cout << "test scores:"<< endl;
    for(auto x: test_scores)
        cout << x << endl;
    
    
    cout << endl;
    vector<int> n1 {1,2,3};
    
    print_if(n1, [] (auto x) {return x % 2 == 0;} );
    print_if(n1, [] (auto x) {return x % 2 != 0;} );
    
    return 0;
}
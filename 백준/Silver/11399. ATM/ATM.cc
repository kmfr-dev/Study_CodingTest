#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> Person(N, 0);

    for (int i = 0; i < N; ++i)
        cin >> Person[i];

    sort(Person.begin(), Person.end());
    
    int Sum = 0;
    int MinVal = 0;

    for (int i = 0; i < N; ++i)
    {
        Sum += Person[i];
        MinVal += Sum;
    }

    cout << MinVal;

    return 0;
}
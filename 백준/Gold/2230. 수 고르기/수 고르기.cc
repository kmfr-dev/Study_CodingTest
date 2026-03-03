#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N + 5, 0);

    for (int i = 0; i < N; ++i)
        cin >> A[i];

    sort(A.begin(), A.begin() + N);

    int Start = 0; 
    int End = 0;
    int Min = INT_MAX;

    while(End < N)
    {
        int Value = A[End] - A[Start];

        if (Value >= M)
        {
            Min = min(Min, Value);
            ++Start;
            
            if(Start > End)
                ++End;
        }
        else
        {
            ++End;
        }
    }
    

    cout << Min;

    return 0;
}
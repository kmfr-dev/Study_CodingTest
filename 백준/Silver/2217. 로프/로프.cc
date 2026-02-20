#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> weight(N + 1, 0);

    for (int i = 0; i < N; ++i)
        cin >> weight[i];

    sort(weight.begin(), weight.begin() + N);

    int Result = 0;
    for (int k = 1; k <= N; ++k)
    {
        Result = max(Result, weight[N - k] * k);
    }

    cout << Result;

    return 0;
}
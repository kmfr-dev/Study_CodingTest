#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> DP(N + 1, INT_MAX);
    DP[0] = 0;

    for (int i = 1; i <= N; ++i)
    {
        DP[i] = i;
        for (int j = 1; j * j <= i; ++j)
            DP[i] = min(DP[i], DP[i - j * j] + 1);
    }

    cout << DP[N];

    return 0;
}
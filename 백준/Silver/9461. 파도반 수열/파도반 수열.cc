#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long > DP(101, 0);
    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;
    DP[4] = 2;
    DP[5] = 2;
    
    for(int i = 6; i <= 100; ++i)
        DP[i] = DP[i - 2] + DP[i - 3];
    
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        cout << DP[N] << '\n';
    }

    return 0;
}
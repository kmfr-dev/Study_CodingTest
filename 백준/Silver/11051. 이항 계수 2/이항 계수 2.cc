#include <iostream>
using namespace std;

int DP[1002][1002];
int MOD = 10007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 1; i <= 1000; ++i)
    {
        DP[i][0] = DP[i][i] = 1;
        for(int j = 1; j < i; ++j)
            DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j]) % MOD;
    }
    
    
    int N, K;
    cin >> N >> K;
    
    cout << DP[N][K];
   
    return 0;
}
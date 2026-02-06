#include <bits/stdc++.h>
using namespace std;

int dp[20];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for(int i = 4; i < 11; ++i)
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    
    int Case;
    cin >> Case;
    
    while(Case--)
    {
        int N;
        cin >> N;
        
        cout << dp[N] << '\n';
    }
    
    return 0;
}
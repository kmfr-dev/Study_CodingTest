#include <iostream>
#include <vector>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T; 
    
    while(T--)
    {
        int N;
        cin >> N;
        
        vector<pair<int,int>> DP(N + 1, {0, 0});
        
        DP[0] = {1, 0};
        
        if(N >= 1) 
            DP[1] = {0, 1};
        
        for(int i = 2; i <= N; ++i)
        { 
            DP[i].first = DP[i - 1].first + DP[i - 2].first;
            DP[i].second = DP[i - 1].second + DP[i - 2].second;
        }
        
        cout << DP[N].first << ' ' << DP[N].second << '\n'; 
    }

    
    return 0;
}
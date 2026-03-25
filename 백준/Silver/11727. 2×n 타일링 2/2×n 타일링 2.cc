#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<int> DP(N + 1, 0);
    DP[1] = 1;
    DP[2] = 3;
    
    for(int i = 3; i <= N; ++i)
        DP[i] = (DP[i - 1] + 2 * DP[i - 2]) % 10007;
    
    cout << DP[N];
    
    
    return 0;
}
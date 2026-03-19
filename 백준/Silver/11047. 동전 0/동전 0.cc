#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> Coins(N + 2, 0);
    for(int i = 0; i < N; ++i)
        cin >> Coins[i];
    
    int Answer = 0;
    for(int i = N - 1; i >= 0; --i)
    {
        Answer += K / Coins[i];
        K %= Coins[i];
    }
    
    cout << Answer;
    
    return 0;
}
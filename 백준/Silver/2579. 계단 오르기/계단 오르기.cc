#include <bits/stdc++.h>
using namespace std;

int Stair[305][5];
int Score[305];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    for(int i = 1; i <= N; ++i)
        cin >> Score[i];
    
    if(N == 1)
    {
        cout << Score[1];
        return 0;
    }
    
    // 계단 초기값 설정
    
    // 첫번째로 첫계단을 밟았다면 점수는 S[1];
    // 두번째로 첫계단을 밟았을 일은 없으므로 0
    Stair[1][1] = Score[1];
    Stair[1][2] = 0;
    
    // 2번째 계단
    // 첫번째로 두번째 계단을 밟았다면 점수는 S[2];
    // 두번째로 두번째 계단을 밟았다면 첫계단 점수 + 두번째 계단 점수
    Stair[2][1] = Score[2];
    Stair[2][2] = Score[1] + Score[2];
    
    for(int i = 3; i <= N; ++i)
    {
        Stair[i][1] = max(Stair[i - 2][1], Stair[i - 2][2]) + Score[i];
        Stair[i][2] = Stair[i - 1][1] + Score[i];
    }
    
    cout << max(Stair[N][1], Stair[N][2]);
    
    return 0;
}
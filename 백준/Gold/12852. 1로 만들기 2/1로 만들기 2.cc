#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    // DP[i] = i를 1로 만들기 위한 최소 연산 횟수를 저장
    vector<int> DP(N + 1, 0);
    // PreDP[i] = i에서 최적 경로로 이동했을 때 이전 숫자
    vector<int> PreDP(N + 1, 0);

    
    for (int i = 2; i <= N; ++i)
    {
        int Index = i - 1;
        DP[i] = DP[Index] + 1;
        
        // 3으로 나누어 떨어지면, 나누는 것이 더 좋은지 확인
        if (i % 3 == 0)
        {
            if (DP[i] > DP[i / 3] + 1)
            {
                DP[i] = DP[i / 3] + 1;
                Index = i / 3;
            }
        }
        
        // 2로 나누어 떨어지면, 나누는 것이 더 좋은지 확인
        if (i % 2 == 0)
        {
            if (DP[i] > DP[i / 2] + 1)
            {
                DP[i] = DP[i / 2] + 1;
                Index = i / 2;
            }
        }
        
        // i에서 최적으로 선택한 다음 숫자 저장
        PreDP[i] = Index;
    }
    
    // 최소 연산 횟수 출력   
    cout << DP[N] << '\n';
    
    // PreDP를 따라가며 경로 역추적
    int Cur = N;
    while (Cur != 0)
    {
        cout << Cur << ' ';
        Cur = PreDP[Cur];
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N, M;
int Arr[10];
bool IsUsed[10];

void Recursion(int K)
{
    // 만약 M개의 수를 모두 택했을 시
    if(K == M)
    {
        // 기록해둔 수 출력
        for(int i = 0; i < M; ++i)
            cout << Arr[i] << ' ';
        cout << '\n';
        return;
    }
    
    for(int i = 1; i <=N; ++i)
    {
        if(!IsUsed[i])
        {
            Arr[K] = i;
            IsUsed[i] = true;
            Recursion(K + 1);
            IsUsed[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    Recursion(0);
    
    return 0;
}
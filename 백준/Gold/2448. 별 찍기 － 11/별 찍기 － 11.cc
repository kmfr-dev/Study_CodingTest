#include <bits/stdc++.h>
using namespace std;

int N;
char Board[3100][6200];

void Recursion(int R, int C, int H)
{
    if(H == 3)
    {
        for(int i = 0; i < 3; ++i)
        {
            for(int j = -i; j <= i; ++j)
            {
                if(i == 2 || j == -i || j == i)
                    Board[R + i][C + j] = '*';
            }
        }
        return;
    }
    
    else
    {
        // 중앙 위
        Recursion(R, C, H/2);
        // 왼쪽 아래
        Recursion(R + H/2, C - H/2, H/2);
        // 오른쪽 아래
        Recursion(R + H/2, C + H/2, H/2);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    fill(&Board[0][0], &Board[0][0] + 3100 * 6200, ' ');
    
    cin >> N;
    
    // 중앙에서 재귀시작
    Recursion(0, N - 1, N);
    
    // 출력
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < 2 * N - 1; ++j)
            cout << Board[i][j];
        cout << '\n'; 
    }
    
    return 0;
}
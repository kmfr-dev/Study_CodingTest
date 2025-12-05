#include <bits/stdc++.h>
using namespace std;

int Board[1002][1002];
int Dist[2][1002][1002];

int DirX[4] {1, 0, -1, 0};
int DirY[4] {0, 1, 0, -1}; 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    fill(&Board[0][0], &Board[0][0] + 1002 * 1002, 0);
    fill(&Dist[0][0][0], &Dist[0][0][0] + 2 * 1002 * 1002, -1);
    
    int N, M;
    cin >> N >> M;
    
    string S;
    for(int i = 0; i < N; i++)
    {
        cin >> S;
        for(int j = 0; j < M; j++)
            Board[i][j] = S[j] - '0';
    }
    
    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 0});
    Dist[0][0][0] = 1;
    

    while(!Q.empty())
    {
        tuple<int, int, int> Cur = Q.front();
        
        int CurBroken = get<0>(Cur);
        int CurY = get<1>(Cur);
        int CurX = get<2>(Cur);
        
        Q.pop();
        
        for(int Dir = 0; Dir < 4; ++Dir)
        {
            int NextDirY = CurY + DirY[Dir];
            int NextDirX = CurX + DirX[Dir];
            
            if(NextDirY < 0 || NextDirY >= N ||
                  NextDirX < 0 || NextDirX >= M)
                continue;
            
            // 벽을 부수지 않고 이동할 때,
            if(Board[NextDirY][NextDirX] == 0 && Dist[CurBroken][NextDirY][NextDirX] == -1)
            {
                Dist[CurBroken][NextDirY][NextDirX] = Dist[CurBroken][CurY][CurX] + 1;
                Q.push({CurBroken, NextDirY, NextDirX});
            }
            
            if(Board[NextDirY][NextDirX] == 1 && CurBroken == 0 && Dist[1][NextDirY][NextDirX] == -1)
            {
                Dist[1][NextDirY][NextDirX] = Dist[CurBroken][CurY][CurX] + 1;
                Q.push({1, NextDirY, NextDirX});
            }    
              
        }
    }
    
    int Result0 = Dist[0][N - 1][M - 1];
    int Result1 = Dist[1][N - 1][M - 1];
    
    if(Result0 == -1 && Result1 == -1)
        cout << -1;
    else if(Result0 == -1)
        cout << Result1;
    else if(Result1 == -1)
        cout << Result0;
    else
        cout << min(Result0, Result1);
    
    
    return 0;
}
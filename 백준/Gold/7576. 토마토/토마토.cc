#include <bits/stdc++.h>
using namespace std;

int Board[1002][1002];
int Dist[1002][1002];

int DirX[4] { 1, 0, -1, 0 };
int DirY[4] { 0, -1, 0, 1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int M, N;
    cin >> M >> N;

    queue<pair<int, int>> Q;
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            // 좌표에 입력받는다.
            cin >> Board[i][j];
            // 익은 토마토면 큐에 삽입
            if(Board[i][j] == 1)
                Q.push({i, j});
            // 익지 않았다면 아직 방문하지 않은것으로 처리
            if(Board[i][j] == 0)
                Dist[i][j] = -1;
        }
    }
    
    while(!Q.empty())
    {
        pair<int, int> CurTomato = Q.front();
        Q.pop();
        
        for(int Dir = 0; Dir < 4; ++Dir)
        {
            int NextDirX = CurTomato.first + DirX[Dir];
            int NextDirY = CurTomato.second + DirY[Dir];
            
            if(NextDirX < 0 || NextDirX >= N ||
                  NextDirY < 0 || NextDirY >= M)
                continue;
            
            // 다음좌표에 방문했거나, 
            // 해당좌표에 토마토가 들어있지 않거나, 익은 토마토라면 건너뜀
            if(Dist[NextDirX][NextDirY] != -1)
                continue;
            
            Dist[NextDirX][NextDirY] = Dist[CurTomato.first][CurTomato.second] + 1;
            Q.push({NextDirX, NextDirY});
        }
    }
    
    int Answer = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
             if(Dist[i][j] == -1)
             {
                 cout << -1 << "\n";
                 return 0;
             }
            
            Answer = max(Answer, Dist[i][j]);
        }
    }
    
    cout << Answer << "\n";
    
    return 0;
}
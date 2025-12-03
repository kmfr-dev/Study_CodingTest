#include <bits/stdc++.h>
using namespace std;

int Board[302][302];
int Dist[302][302];

int DirX[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int DirY[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while(T--)
    {
        // 체스판 사이즈
        int BoardSize;
        cin >> BoardSize;
        
        // 배열 초기화
        fill(&Dist[0][0], &Dist[0][0] + 302 * 302, -1);
        fill(&Board[0][0], &Board[0][0] + 302 * 302, 0);
        
        // 시작위치, 목표위치
        int StartCol, StartRow;
        int GoalCol, GoalRow;
        
        cin >> StartCol >> StartRow;
        cin >> GoalCol >> GoalRow;
        
        // 만약 시작지점과 목표지점이 같은경우 
        // 다음 케이스로
        if(StartCol == GoalCol &&
              StartRow == GoalRow)
        {
            cout << 0 << "\n";
            continue;
        }
        
        // 보드판에 목표지점 마킹
        Board[GoalRow][GoalCol] = 1;
        // 시작지점 방문처리
        Dist[StartRow][StartCol] = 0;
      
        queue<pair<int, int>> Q;
        // 큐에 삽입
        Q.push({StartRow, StartCol});
        
        bool IsFound = false;
        // BFS 시작
        while(!Q.empty())
        {
            pair<int, int> Cur = Q.front();
            Q.pop();
            
            for(int Dir = 0; Dir < 8; ++Dir)
            {
                int NextDirX = Cur.second + DirX[Dir];
                int NextDirY = Cur.first + DirY[Dir];
                
                if(NextDirX < 0 || NextDirX >= BoardSize ||
                      NextDirY < 0 || NextDirY >= BoardSize)
                    continue;
                
                if(Dist[NextDirY][NextDirX] != -1)
                    continue;
                
                if(Board[NextDirY][NextDirX] == 1)
                {
                    Dist[NextDirY][NextDirX] = Dist[Cur.first][Cur.second] + 1;
                    cout << Dist[NextDirY][NextDirX] << "\n";
                    IsFound = true;
                    break;
                }
                
                Dist[NextDirY][NextDirX] = Dist[Cur.first][Cur.second] + 1;
                Q.push({NextDirY, NextDirX});
            }
            
            if(IsFound)
                break;
        }
    }
    
    return 0;
}
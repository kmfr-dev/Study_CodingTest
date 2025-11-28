#include <bits/stdc++.h>
using namespace std;

char Maze[1002][1002];
int FireDist[1002][1002];
int JihunDist[1002][1002];

int DirX[4] {1, 0, -1, 0};
int DirY[4] {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int R,C;
    cin >> R >> C;
   
    fill(&FireDist[0][0], &FireDist[0][0] + 1002 * 1002, -1);
    fill(&JihunDist[0][0], &JihunDist[0][0] + 1002 * 1002, -1);
    
    queue<pair<int, int>> Q;
    pair<int, int> Jihun;
    
    for(int i = 0; i < R; ++i)
    {
        for(int j = 0; j < C; ++j)
        {
            cin >> Maze[i][j];
            
            // 불일 경우 큐에 삽입
            if(Maze[i][j] == 'F')
            {
                Q.push({i, j});
                FireDist[i][j] = 0;
            }       
            // 지훈이일 경우 좌표 저장
            if(Maze[i][j] == 'J')
            {
                Jihun = make_pair(i , j);
                JihunDist[i][j] = 0;
            }
        }
    }
        
    // 불에대한 BFS 시작
    while(!Q.empty())
    {
        pair<int, int> Cur = Q.front();
        Q.pop();
        
        for(int Dir = 0; Dir < 4; ++Dir)
        {
            // 다음좌표 계산
            int NextDirX = Cur.first + DirX[Dir];
            int NextDirY = Cur.second + DirY[Dir];
            
            // 좌표 유효성 검사
            if(NextDirX < 0 || NextDirX >= R ||
                  NextDirY < 0 || NextDirY >= C)
                continue;
            
            // 벽일 경우 continue
            if(Maze[NextDirX][NextDirY] == '#')
                continue;
            
            // 방문했을 경우
            if(FireDist[NextDirX][NextDirY] != -1)
                continue;
            
            FireDist[NextDirX][NextDirY] = FireDist[Cur.first][Cur.second] + 1;
            Q.push({NextDirX, NextDirY});
        }
    }
         
    // 지훈이에 대한 BFS 시작
    Q.push({Jihun.first, Jihun.second});
    while(!Q.empty())
    {
        pair<int, int> Cur = Q.front();
        Q.pop();
        
        for(int Dir = 0; Dir < 4; ++Dir)
        {
            int NextDirX = Cur.first + DirX[Dir];
            int NextDirY = Cur.second + DirY[Dir];
            
            if(NextDirX < 0 || NextDirX >= R ||
                  NextDirY < 0 || NextDirY >= C)
            {
                cout << JihunDist[Cur.first][Cur.second] + 1 << "\n";
                return 0;
            }
            // 벽일 경우 continue
            if(Maze[NextDirX][NextDirY] == '#')
                continue;
            
            // 방문 했을 경우 continue
            if(JihunDist[NextDirX][NextDirY] != -1)
                continue;
            
            JihunDist[NextDirX][NextDirY] = JihunDist[Cur.first][Cur.second] + 1;
            
            // 만약 다음좌표가 불이 올수 있는 칸이고,
            // 불 길이보다 지훈이의 길이가 크다면 불보다 늦게오는곳이므로 갈 수 없다고 판단.
            if(FireDist[NextDirX][NextDirY] != -1 && JihunDist[NextDirX][NextDirY] >= FireDist[NextDirX][NextDirY])
                continue;
            
            Q.push({NextDirX, NextDirY});
        }
    }
    
   cout << "IMPOSSIBLE" << "\n";
    
    
    return 0;
}
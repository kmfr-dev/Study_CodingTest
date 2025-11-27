#include <bits/stdc++.h>
using namespace std;

int Board[500][500] = { 0 };
bool Visited[500][500] = { false };

int DirX[4] {1, 0, -1, 0};
int DirY[4] {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            cin >> Board[i][j];
   
    queue<pair<int, int>> Q;
    int Num = 0, Max = 0;
      
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(Board[i][j] == 1 && Visited[i][j] == false)
            {   
                ++Num;
                int Area = 0;
                Visited[i][j] = true;
                Q.push({i , j});
                
                while(!Q.empty())
                {
                    pair<int, int> Cur = Q.front();
                    Q.pop();
                    ++Area;
                    
                    for(int Dir = 0; Dir < 4; ++Dir)
                    {
                        int NextDirX = Cur.first + DirX[Dir];
                        int NextDirY = Cur.second + DirY[Dir];
            
                        if(NextDirX < 0 || NextDirX >= N ||
                              NextDirY < 0 || NextDirY >= M)
                            continue;
            
                        if(Visited[NextDirX][NextDirY] == true || Board[NextDirX][NextDirY] != 1)
                            continue;
            
                        Visited[NextDirX][NextDirY] = true;
                        Q.push({NextDirX, NextDirY});
                    } 
                }
                
                Max = max(Max, Area);
            }
        }
    }
  
    cout << Num << "\n";
    cout << Max << "\n";
        
    return 0;
}
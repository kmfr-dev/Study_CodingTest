#include <bits/stdc++.h>
using namespace std;

char Board[102][102];
bool Visited[102][102];

int DirX[4] = {1, 0, -1, 0};
int DirY[4] = {0, 1, 0, -1};

int main()
{
    fill(&Visited[0][0], &Visited[0][0] + 102 * 102, false);
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N; 
    cin >> N;
    
    for(int i = 0; i < N; ++i)
    {
        string S;
        cin >> S;
        for(int j = 0; j < S.length(); ++j)
            Board[i][j] = S[j];
    }
    
    queue<pair<int, int>> Q;
    int Count = 0;
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(Visited[i][j] != true)
            {
                ++Count;
                Visited[i][j] = true; 
                Q.push({i, j});
                
                
                char CurColor = Board[i][j];
                while(!Q.empty())
                {
                    pair<int, int> Cur = Q.front();
                    Q.pop();
                    
                    for(int Dir = 0; Dir < 4; ++Dir)
                    {
                        int NextDirX = Cur.second + DirX[Dir];
                        int NextDirY = Cur.first + DirY[Dir];
                        
                        if(NextDirX < 0 || NextDirX >= N ||
                              NextDirY < 0 || NextDirY >= N)
                            continue;
                        
                        if(Visited[NextDirY][NextDirX] != false)
                            continue;
                        
                        if(CurColor != Board[NextDirY][NextDirX])
                            continue;
                        
                        Visited[NextDirY][NextDirX] = true;
                        Q.push({NextDirY, NextDirX});
                        
                    }
                }
            }
        }
    }
    
    cout << Count << ' ';
    
    // 카운트와 방문여부 배열 초기화
    Count = 0;
    fill(&Visited[0][0], &Visited[0][0] + 102 * 102, false);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            if(Board[i][j] == 'G')
                Board[i][j] = 'R';
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(Visited[i][j] != true)
            {
                ++Count;
                Visited[i][j] = true; 
                Q.push({i, j});
                
                char CurColor = Board[i][j];
                while(!Q.empty())
                {
                    pair<int, int> Cur = Q.front();
                    Q.pop();
                    
                    for(int Dir = 0; Dir < 4; ++Dir)
                    {
                        int NextDirX = Cur.second + DirX[Dir];
                        int NextDirY = Cur.first + DirY[Dir];
                        
                        if(NextDirX < 0 || NextDirX >= N ||
                              NextDirY < 0 || NextDirY >= N)
                            continue;
                        
                        if(Visited[NextDirY][NextDirX] != false)
                            continue;
                        
                        if(CurColor != Board[NextDirY][NextDirX])
                            continue;
                        
                        Visited[NextDirY][NextDirX] = true;
                        Q.push({NextDirY, NextDirX});
                        
                    }
                }
            }
        }
    }
    
     cout << Count;
    
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int Board[102][102];
bool Visited[102][102];

int DirX[4] {1, 0, -1, 0};
int DirY[4] {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    // 건물 최대 높이를 찾는다.
    int MaxHeight = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> Board[i][j];
            MaxHeight = max(MaxHeight, Board[i][j]);
        }
    }
    
    queue<pair<int, int>> Q;
    
    int SafeZone = 0;
    
    // 비높이 0부터 체크
    for(int i = 0; i < MaxHeight; ++i)
    {
        // 방문여부 초기화
        fill(&Visited[0][0], &Visited[0][0] + 102 * 102, false);
        
        int Area = 0;
        
        for(int j = 0; j < N; ++j)
        {
           for(int k = 0; k < N; ++k)
           { 
               // 비에 잠기지 않았거나 방문하지 않았을 때만 
               if(i < Board[j][k] && Visited[j][k] == false)
               {
                   ++Area;
                   Visited[j][k] = true;
                   Q.push({j, k});
                   
                   while(!Q.empty())
                   {
                       pair<int, int> Cur = Q.front();
                       Q.pop();
                       
                       for(int Dir = 0; Dir < 4; ++Dir)
                       {
                           int NextY = Cur.first + DirY[Dir];
                           int NextX = Cur.second + DirX[Dir];
                           
                           // 좌표 유효성 검사
                           if(NextY < 0 || NextY >= N || 
                                 NextX < 0 || NextX >=N)
                               continue;
                           
                           // 1. 다음좌표가 물에 잠겼는지 확인
                           // 2. 방문했는지 확인
                           if(Board[NextY][NextX] <= i ||
                                 Visited[NextY][NextX] == true)
                               continue;
                           
                           Visited[NextY][NextX] = true;
                           Q.push({NextY, NextX});
                       }
                   }   
               }
           }
        }
        SafeZone = max(SafeZone, Area);
    }
    
   
    
    cout << SafeZone;
    
    return 0;
}
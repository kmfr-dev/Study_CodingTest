#include <bits/stdc++.h>
using namespace std;

char Building[32][32][32];
int Dist[32][32][32];

int DirZ[6] {1, -1, 0, 0, 0, 0};
int DirY[6] {0, 0, 1, -1, 0, 0};
int DirX[6] {0, 0, 0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true)
    {
        int L, R, C;
        cin >> L >> R >> C;
        
        // 셋다 0을 입력받으면 종료
        if(L == 0 && R == 0 && C == 0)
            break;
        
        queue<tuple<int, int, int>> Q;
        fill(&Dist[0][0][0], &Dist[0][0][0] + 32 * 32 * 32, -1);
        
        // 빌딩 초기화 및 좌표 지정
        for(int Z = 0; Z < L; ++Z)
        {
            for(int Y = 0; Y < R; ++Y)
            {
                for(int X = 0; X < C; ++X)
                {
                    cin >> Building[Z][Y][X];
                    // 상범이라면 큐에 삽입 및 방문처리
                    if(Building[Z][Y][X] == 'S')
                    {
                        Dist[Z][Y][X] = 0;
                        Q.push({Z, Y, X});
                    }
                }
            }
        }
        
        // 탈출했는지에 대한 bool값
        bool IsEscape = false;
        
        // 빌딩 BFS 시작
        while(!Q.empty())
        {
            tuple<int, int, int> Cur = Q.front();
            
            int CurZ = get<0>(Cur);
            int CurY = get<1>(Cur);
            int CurX = get<2>(Cur);
            
            Q.pop();
            
            if(Building[CurZ][CurY][CurX] == 'E')
            {
                cout << "Escaped in " << Dist[CurZ][CurY][CurX] << " minute(s).\n";
                IsEscape = true;
                break;
            }
            
            for (int Dir = 0; Dir < 6; ++Dir) 
            {
                int NextZ = CurZ + DirZ[Dir];
                int NextY = CurY + DirY[Dir];
                int NextX = CurX + DirX[Dir];

                if(NextZ < 0 || NextY < 0 || NextX < 0 ||
                      NextZ >= L || NextY >= R || NextX >= C)
                    continue;
                
                // 벽이거나, 방문하지 않았으면 continue;
                if(Building[NextZ][NextY][NextX] == '#' || Dist[NextZ][NextY][NextX] != -1)
                    continue;
                
                Dist[NextZ][NextY][NextX] = Dist[CurZ][CurY][CurX] + 1;
                Q.push({NextZ, NextY, NextX});
            }
        
        }
        
        if(!IsEscape)
                cout << "Trapped!\n";
    }
    
    return 0;
}
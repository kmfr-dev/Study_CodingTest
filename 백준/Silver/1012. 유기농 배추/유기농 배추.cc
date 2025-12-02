#include <bits/stdc++.h>
using namespace std;

int Board[52][52];
bool Visited[52][52];

int DirX[4] = {1, 0, -1, 0};
int DirY[4] = {0, 1, 0, -1};

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int T;
    cin >> T;
 
    for(int i = 0; i < T; ++i)
    {
        fill(&Board[0][0], &Board[0][0] + 52 * 52, 0);
        fill(&Visited[0][0], &Visited[0][0] + 52 * 52, false);
        
        int M, N, K;
        cin >> M >> N >> K;
   
        while(K--)
        {
            int X, Y;
            cin >> X >> Y;
            
            Board[Y][X] = 1;
        }
        
        queue<pair<int, int>> Q;
        int Answer = 0;
        
        // 시작점을 찾는다.
        for(int j = 0; j < N; ++j)
        {
            for(int k = 0; k < M; ++k)
            {
                // 방문하지 않은 배추에서 BFS 시작
                if(Visited[j][k] != true && Board[j][k] == 1)
                {
                    Visited[j][k] = true;
                    ++Answer;
                    
                    Q.push({j, k});
                    
                    while(!Q.empty())
                    {
                        pair<int, int> Cur = Q.front();
                        Q.pop();
                        
                        for(int Dir = 0; Dir < 4; ++Dir)
                        {
                            int NextDirX = Cur.second + DirX[Dir];
                            int NextDirY = Cur.first + DirY[Dir];
                            
                            // 유효 좌표 검사
                            if(NextDirX < 0 || NextDirX >= M ||
                                  NextDirY < 0 || NextDirY >= N)
                                continue;
                            
                            // 방문 여부 체크 및 배추가 아닌경우 체크
                            if(Visited[NextDirY][NextDirX] != false || Board[NextDirY][NextDirX] != 1)
                                continue;
                            
                            // 다음 좌표 방문처리
                            Visited[NextDirY][NextDirX] = true;
                            // 다음 좌표 큐에 삽입
                            Q.push({NextDirY, NextDirX});
                        }
                    }
                }
            }
        }
        
        cout << Answer << "\n";
        
    }  
    return 0;
}
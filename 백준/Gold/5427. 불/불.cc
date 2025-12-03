#include <bits/stdc++.h>
using namespace std;

char Building[1002][1002];

int DirX[4] {1, 0, -1, 0};
int DirY[4] {0, 1, 0, -1};

int FireDist[1002][1002];
int PersonDist[1002][1002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while(T--)
    {
        int Width, Height;
        cin >> Width >> Height;
        
        // 배열 초기화
        fill(&FireDist[0][0], &FireDist[0][0] + 1002 * 1002, -1);
        fill(&PersonDist[0][0], &PersonDist[0][0] + 1002 * 1002, -1);
        
        queue<pair<int, int>> Q;
        
        pair<int, int> PersonPos;
        vector<pair<int, int>> FirePos;
        
        // 빌딩 채우기 및 사람, 불 위치 구하기
        for(int i = 0; i < Height; ++i)
        {
            string Str;
            cin >> Str;
            for(int j = 0; j < Width; ++j)
            {
                Building[i][j] = Str[j];
                if(Str[j] == '@')
                    PersonPos = make_pair(i, j);
                if(Str[j] == '*')
                {
                     FirePos.push_back({i, j});
                    // 방문처리
                    FireDist[i][j] = 0;
                    Q.push({i, j});
                }
            }
        }
        
        // 불 BFS 시작
        while(!Q.empty())
        {
            pair<int, int> Cur = Q.front();
            Q.pop();
            
            for(int Dir = 0; Dir < 4; ++Dir)
            {
                int NextWidth = Cur.second + DirX[Dir];
                int NextHeight = Cur.first + DirY[Dir];
                
                // 유효 좌표 검사
                if(NextWidth < 0 || NextWidth >= Width ||
                      NextHeight < 0 || NextHeight >= Height)
                    continue;
                
                // 벽이거나 방문했다면 continue;
                if(Building[NextHeight][NextWidth] == '#' 
                   || FireDist[NextHeight][NextWidth] != -1)
                    continue;
                
                FireDist[NextHeight][NextWidth] = FireDist[Cur.first][Cur.second] + 1;
                Q.push({NextHeight, NextWidth});
            }   
        }
        
        PersonDist[PersonPos.first][PersonPos.second] = 0;
        Q.push(PersonPos);
        
        bool IsEscape = false;
        
        while(!Q.empty())
        {
            pair<int, int> Cur = Q.front();
            Q.pop();
            
            for(int Dir = 0; Dir < 4; ++Dir)
            {
                int NextWidth = Cur.second + DirX[Dir];
                int NextHeight = Cur.first + DirY[Dir];
                
                 // 밖으로 나갔는지 확인
                if(NextWidth < 0 || NextWidth >= Width ||
                      NextHeight < 0 || NextHeight >= Height)
                {
                   // 밖으로 나갔으면 최단시간 출력,
                    // 탈출 플래그 변경 후 break
                    int Best = PersonDist[Cur.first][Cur.second] + 1;
                    cout << Best << '\n';
                    
                    IsEscape = true;
                    break;
                    
                }
                
                // 다음 좌표가 벽인지 확인
                if(Building[NextHeight][NextWidth] == '#')
                    continue;
              
                // 방문했다면 continue
                if(PersonDist[NextHeight][NextWidth] != -1)
                    continue;
               
                // 다음 칸에 도달하는 상근이의 시간과
                // 다음 칸에 도달하는 불의 시간을 비교
                int NextPersonTime = PersonDist[Cur.first][Cur.second] + 1;
                int NextFireTime = FireDist[NextHeight][NextWidth];
                
                // 만약 불이 일찍도달했거나 같이 도달했을 경우 못가는 곳
                if(NextFireTime != -1 && NextPersonTime >= NextFireTime)
                    continue;
                
                PersonDist[NextHeight][NextWidth] = NextPersonTime; 
                Q.push({NextHeight, NextWidth});
            }   
            
            if(IsEscape)
                break;
        }
        
        if(!IsEscape)
            cout << "IMPOSSIBLE" << "\n";
        
    }
   
    return 0;
}
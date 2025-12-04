#include <bits/stdc++.h>
using namespace std;

int Map[27][27];
bool Visited[27][27];

int DirX[4] { 1, 0, -1, 0 };
int DirY[4] { 0, 1, 0, -1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    fill(&Map[0][0], &Map[0][0] + 27 * 27, 0);
    fill(&Visited[0][0], &Visited[0][0] + 27 * 27, false);
    
    int N;
    cin  >> N;
    
    // 맵 채우기
    for(int i = 0; i < N; ++i)
    {
        string Str;
        cin >> Str;
        
        for(int j = 0; j < N; ++j)
            Map[i][j] = Str[j] - '0';
    }
    
    
    queue<pair<int, int>> Q;
    vector<int> Areas;
    int AllArea = 0;
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(Map[i][j] == 1 && Visited[i][j] == false)
            {
                ++AllArea;
                
                Visited[i][j] = true;
                Q.push({i, j});
                
                int Area = 0;
                while(!Q.empty())
                {
                    pair<int, int> Cur = Q.front();
                    Q.pop();
                    ++Area;
                    
                    for(int Dir = 0; Dir < 4; ++Dir)
                    {
                        int NextY = Cur.first + DirY[Dir];
                        int NextX = Cur.second + DirX[Dir];
                        
                        if(NextY < 0 || NextY >= N ||
                              NextX < 0 || NextX >= N)
                            continue;
                        
                        if(Map[NextY][NextX] == 0 || Visited[NextY][NextX] != false)
                            continue;
                        
                        Visited[NextY][NextX] = true;
                        Q.push({NextY, NextX});
                    }
                }
                
                Areas.emplace_back(Area);
            }
        }
    }
    
    cout << AllArea << "\n";
    
    sort(Areas.begin(), Areas.end());
    
    for(int Area : Areas)
        cout << Area << "\n";
    
    return 0;
}
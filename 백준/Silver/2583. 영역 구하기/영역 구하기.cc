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

    fill(&Board[0][0], &Board[0][0] + 102 * 102, 0);
    fill(&Visited[0][0], &Visited[0][0] + 102 * 102, false);
    
    int Width, Height, Case;
    cin >> Height >> Width >> Case;
    
    while(Case--)
    {
        int MinX, MaxX, MinY, MaxY;
        cin >> MinX >> MinY >> MaxX >> MaxY;
        
        // 모눈종이에 막힌부분을 마킹
        for(int Y = MinY; Y < MaxY; ++Y)
            for(int X = MinX; X < MaxX; ++X)
                Board[Y][X] = 1;
    }
    
    int AllArea = 0;
    vector<int> Areas;
    
    queue<pair<int, int>> Q;
    
    for(int Y = 0; Y < Height; ++Y)
    {
        for(int X = 0; X < Width; ++X)
        {
            if(Board[Y][X] == 0 && Visited[Y][X] == false)
            {
                ++AllArea;
                Visited[Y][X] = true;
                Q.push({Y, X});
                
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
                        
                        if(NextY < 0 || NextY >= Height ||
                              NextX < 0 || NextX >= Width)
                            continue;
                        
                        // 벽에 막혀있거나 방문했다면 continue;
                        if(Board[NextY][NextX] == 1 || Visited[NextY][NextX] == true)
                            continue;
                        
                        Visited[NextY][NextX] = true;
                        Q.push({NextY, NextX});
                    }
                }
                
                Areas.emplace_back(Area);
            }
        }
    }
    
    sort(Areas.begin(), Areas.end());
    
    cout << AllArea << "\n";
    for(int Area : Areas)
        cout << Area << ' ';
    
    return 0;
}
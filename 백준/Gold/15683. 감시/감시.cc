#include <bits/stdc++.h>
using namespace std;

int N, M;
int Arr[10][10];
vector<pair<int, int>> CCTVVec;
vector<vector<vector<int>>> CCTVDir =
{
    {},
    {{0}, {1}, {2}, {3}},
    {{0,2}, {1, 3}},
    {{0, 1}, {0, 3}, {2, 1}, {2, 3}},
    {{0,2,3}, {0,1,2}, {1,2,3}, {0, 1, 3}},
    {{0, 1, 2, 3}}
};

int Answer = INT_MAX;

int DirX[4] { 1, 0, -1, 0 };
int DirY[4] { 0, -1, 0, 1 };

void Watch(int X, int Y, int Dir)
{
    int NextX = X;
    int NextY = Y;
    
    while(true)
    {
        NextX += DirX[Dir];
        NextY += DirY[Dir];
        
        if(NextX < 0 || NextY < 0 || NextX >= M || NextY >= N)
            break;
        
        if(Arr[NextY][NextX] == 6)
            break;
        if(Arr[NextY][NextX] == 0)
            Arr[NextY][NextX] = -1;
    }
}

void DFS(int Idx)
{
    if(Idx == CCTVVec.size())
    {
        int Count = 0;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                if(Arr[i][j] == 0)
                    ++Count;
        
        Answer = min(Answer, Count);
        return;
    }
    
    int X = CCTVVec[Idx].second;
    int Y = CCTVVec[Idx].first;
    int Type = Arr[Y][X];
    
    for(auto& Dirs : CCTVDir[Type])
    {
        int BackUp[10][10];
        memcpy(BackUp, Arr, sizeof(Arr));
        
        for(int Dir : Dirs)
            Watch(X, Y, Dir);
        
        DFS(Idx + 1);
        
        memcpy(Arr, BackUp, sizeof(Arr));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M; 
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            cin >> Arr[i][j];
            if(Arr[i][j] != 0 && Arr[i][j] != 6)
                CCTVVec.emplace_back(i, j);
        }
    }
    
    DFS(0);
    cout << Answer;
     
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(const vector<vector<int>>& _Map, vector<vector<int>>& _Dist, 
    pair<int, int> _Start, int _Width, int Height)
{
    int DirY[4] = { 0, -1, 0, 1 };
    int DirX[4] = { 1, 0, -1, 0 };

    queue<pair<int, int>> Q;
    Q.push(_Start);
    _Dist[_Start.first][_Start.second] = 0;

    while (!Q.empty())
    {
        pair<int, int> Cur = Q.front();
        Q.pop();

        for (int Dir = 0; Dir < 4; ++Dir)
        {
            int NextY = Cur.first + DirY[Dir];
            int NextX = Cur.second + DirX[Dir];

            if (NextY < 0 || NextX < 0 ||
                NextY >= Height || NextX >= _Width)
                continue;

            if (_Map[NextY][NextX] == 0 || _Dist[NextY][NextX] != -1)
                continue;

            Q.push({ NextY, NextX });
            _Dist[NextY][NextX] = _Dist[Cur.first][Cur.second] + 1;
        }
    }
}

void Print(const vector<vector<int>>& _Map, const vector<vector<int>>& _Dist, 
    int _Width, int _Height)
{
    for (int i = 0; i < _Height; ++i)
    {
        for (int j = 0; j < _Width; ++j)
        {
            if (_Map[i][j] == 0)
                cout << 0 << ' ';
            else if (_Map[i][j] == 1 && _Dist[i][j] == -1)
                cout << -1 << ' ';
            else
                cout << _Dist[i][j] << ' ';
        }

        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> Map(N, vector<int>(M, 0));
    vector<vector<int>> Dist(N, vector<int>(M, -1));

    pair<int, int> Start;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> Map[i][j];
            if (Map[i][j] == 2)
                Start = { i, j };
        }
    }

    BFS(Map, Dist, Start, M, N);
    Print(Map, Dist, M, N);

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

void BFS(const vector<vector<int>>& _Adj, vector<bool>& _Visited, int _Start)
{
    fill(_Visited.begin(), _Visited.end(), false);

    queue<int> Q;
    Q.push(_Start);
    _Visited[_Start] = true;

    cout << _Start << ' ';

    while (!Q.empty())
    {
        int Cur = Q.front();
        Q.pop();

        for (int Vertex : _Adj[Cur])
        {
            if (_Visited[Vertex])
                continue;

            Q.push(Vertex);
            _Visited[Vertex] = true;

            cout << Vertex << ' ';
        }
    }

    cout << '\n';
}

void DFS(const vector<vector<int>>& _Adj, vector<bool>& _Visited, int _Cur)
{
    _Visited[_Cur] = true;
    cout << _Cur << ' ';
    
    for (int Next : _Adj[_Cur]) 
    {
        if (!_Visited[Next])
            DFS(_Adj, _Visited, Next);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> Adj(N + 1);
    vector<bool> Visited(N + 1, false);


    for (int i = 1; i <= M; ++i)
    {
        int Vertex, ToVertex;
        cin >> Vertex >> ToVertex;

        Adj[Vertex].push_back(ToVertex);
        Adj[ToVertex].push_back(Vertex);
    }

    for (int i = 1; i <= N; ++i)
        sort(Adj[i].begin(), Adj[i].end());

    DFS(Adj, Visited, V);

    cout << '\n';
    fill(Visited.begin(), Visited.end(), false);
    
    BFS(Adj, Visited, V);

    return 0;
}
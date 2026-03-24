#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector <vector<int>> Computer(N + 1);
    bool Visited[101] = { false };

    for (int i = 0; i < M; ++i)
    {
        int Num, Connected;
        cin >> Num >> Connected;

        Computer[Num].push_back(Connected);
        Computer[Connected].push_back(Num);
    }

    queue<int> Q;
    Q.push(1);
    Visited[1] = true;
    
    int Total = 0;
    while (!Q.empty())
    {
        int Cur = Q.front();
        Q.pop();

        for (int i = 0; i < Computer[Cur].size(); ++i)
        {
            int ConnectCom = Computer[Cur][i];

            if (true == Visited[ConnectCom])
                continue;

            Visited[ConnectCom] = true;
            Q.push(ConnectCom);
            ++Total;
        }
    }

    cout << Total;

    return 0;
}
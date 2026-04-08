#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, H;
    cin >> M >> N >> H;

    // 토마토
    vector<vector<vector<int>>> Tomato
        (H, vector<vector<int>>(N, vector<int>(M, 0)));
    // 거리
    vector<vector<vector<int>>> Dist
        (H, vector<vector<int>>(N, vector<int>(M, -1)));

    // 6방향 BFS를 위한 배열
    int DirH[6] = { 0, 0, 0, 0, 1, -1 };
    int DirY[6] = { 0, -1, 0, 1, 0, 0 };
    int DirX[6] = { 1, 0, -1, 0, 0, 0 };


    queue<tuple<int, int, int>> Q;

    // 상자에 토마토를 채우면서 익은 토마토는 큐에 저장
    for (int Height = 0; Height < H; ++Height)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
                cin >> Tomato[Height][i][j];
                if (Tomato[Height][i][j] == 1)
                {
                    Q.push({ Height, i, j });
                    Dist[Height][i][j] = 0;
                }
            }

    // BFS
    while (!Q.empty())
    {
        tuple<int, int, int> Cur = Q.front();
        Q.pop();

        for (int Dir = 0; Dir < 6; ++Dir)
        {
            int NextH = get<0>(Cur) + DirH[Dir];
            int NextY = get<1>(Cur) + DirY[Dir];
            int NextX = get<2>(Cur) + DirX[Dir];

            // 다음칸이 유효좌표인지 확인
            if (NextH < 0 || NextY < 0 || NextX < 0 ||
                NextH >= H || NextY >= N || NextX >= M)
                continue;

            // 다음칸이 익지 않은 토마토가 아니거나,
            // 이미 방문한 토마토면 패스
            if (Tomato[NextH][NextY][NextX] != 0 ||
                Dist[NextH][NextY][NextX] != -1)
                continue;

            // 다음좌표 큐에 저장 및 거리 갱신
            Q.push({ NextH, NextY, NextX });
            Dist[NextH][NextY][NextX] = Dist[get<0>(Cur)][get<1>(Cur)][get<2>(Cur)] + 1;
        }
    }

    int Answer = 0;
    for (int Height = 0; Height < H; ++Height)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                // 만약 현재칸이 익지 않은 토마토이고, 방문하지 않은 칸이라면
                // 토마토가 모두 익지 못하는 상황이므로 -1출력후 리턴
                if (Tomato[Height][i][j] == 0 && Dist[Height][i][j] == -1)
                {
                    cout << -1;
                    return 0;
                }
                
                // 토마토가 모두 익는 시간을 체크하는 것이기 때문에 최대값 갱신
                Answer = max(Answer, Dist[Height][i][j]);
            }
        }
    }

    cout << Answer;

    return 0;
}
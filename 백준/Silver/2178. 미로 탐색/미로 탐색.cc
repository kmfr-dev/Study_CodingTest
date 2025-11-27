#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int Maze[100][100];
int Dist[100][100];

int DirX[4]{ 1, 0, -1, 0 };
int DirY[4]{ 0, -1, 0, 1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Maze는 0으로 초기화
    fill(&Maze[0][0], &Maze[0][0] + 100 * 100, 0);
    // Dist 배열은 -1로 초기화, -1로 방문 여부를 알수있게 설정
    fill(&Dist[0][0], &Dist[0][0] + 100 * 100, -1);

    int N, M;
    cin >> N >> M;

    string S;
    // 미로판을 입력받는다
    for (int i = 0; i < N; ++i)
    {
        cin >> S;
        for (int j = 0; j < M; ++j)
            Maze[i][j] = S[j] - '0';
    }


    queue<pair<int, int>> Q;
    // 시작지점을 큐에 삽입
    Q.push({ 0, 0 });
    // 시작지점은 거리가 0
    Dist[0][0] = 0;

    // BFS 시작
    while (!Q.empty())
    {
        pair<int, int> Current = Q.front();
        Q.pop();

        for (int Dir = 0; Dir < 4; ++Dir)
        {
            // 현재 좌표에서 다음 좌표 계산
            int NextDirX = Current.first + DirX[Dir];
            int NextDirY = Current.second + DirY[Dir];

            // 먼저, 다음 좌표가 유효한지 검사
            if (NextDirX < 0 || NextDirX >= N ||
                NextDirY < 0 || NextDirY >= M)
                continue;

            // 다음 좌표가 벽에 막혀있거나,
            // Dist배열이 -1인지를 검사, -1이면 방문하지 않은것 
            if (Maze[NextDirX][NextDirY] == 0 || Dist[NextDirX][NextDirY] != -1)
                continue;

            // 다음 좌표의 길이에 현재 좌표 길이 + 1을 저장
            Dist[NextDirX][NextDirY] = Dist[Current.first][Current.second] + 1;
            Q.push({ NextDirX, NextDirY });
        }
    }

    cout << Dist[N - 1][M - 1] + 1 << '\n';

    return 0;
}
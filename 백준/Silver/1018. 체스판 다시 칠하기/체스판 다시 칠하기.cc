#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<char>> Board(N, vector<char>(M));

    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); ++j)
            Board[i][j] = str[j];
    }

    char StartChar = Board[0][0];
    int Answer = INT_MAX;

    for (int i = 0; i <= N - 8; ++i)
    {
        for (int j = 0; j <= M - 8; ++j)
        {
            int CountW = 0;
            int CountB = 0;

            for (int x = i; x < i + 8; ++x)
            {
                for (int y = j; y < j + 8; ++y)
                {
                    if ((x + y) % 2 == 0)
                    {
                        if (Board[x][y] == 'W')
                            ++CountB;
                        else if (Board[x][y] == 'B')
                            ++CountW;
                    }

                    else
                    {
                        if (Board[x][y] == 'W')
                            ++CountW;
                        else if (Board[x][y] == 'B')
                            ++CountB;
                    }
                }
            }

            Answer = min(Answer, min(CountW, CountB));
        }
    }

    cout << Answer;

    return 0;
}
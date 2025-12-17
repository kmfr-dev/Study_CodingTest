#include <bits/stdc++.h>
using namespace std;

int N;
char Board[2187][2187];

void Recursion(int R, int C, int Size)
{
    if (Size == 3)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (i == 1 && j == 1)
                    continue;
                    
                Board[R + i][C + j] = '*';
            }
        }
        
        return;
    }
    else
    {
        int NewSize = Size / 3;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (i == 1 && j == 1)
                    continue;

                Recursion(R + i * NewSize, C + j * NewSize, NewSize);
            }
        }
    }

};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(&Board[0][0], &Board[0][0] + 2187 * 2187, ' ');

    cin >> N;

    Recursion(0, 0, N);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << Board[i][j];

        cout << '\n';
    }

    return 0;
}
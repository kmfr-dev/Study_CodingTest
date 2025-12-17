#include <bits/stdc++.h>
using namespace std;

int N;
int Tree[66][66];

bool CheckSquare(int R, int C, int Size)
{
    int Cur = Tree[R][C];
    for (int i = R; i < R + Size; ++i)
        for (int j = C; j < C + Size; ++j)
            if (Cur != Tree[i][j]) return false;

    return true;
}

void Recursion(int R, int C, int Size)
{
    if (CheckSquare(R, C, Size))
        cout << Tree[R][C];
    else
    {
        cout << '(';
        int NewSize = Size / 2;

        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                Recursion(R + i * NewSize, C + j * NewSize, NewSize);

        cout << ')';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j)
            Tree[i][j] = s[j] - '0';
    }

    Recursion(0, 0, N);

    return 0;
}
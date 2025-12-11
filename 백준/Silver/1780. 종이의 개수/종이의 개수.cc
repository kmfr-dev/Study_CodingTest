#include <bits/stdc++.h>
using namespace std;

int N;
int Paper[2200][2200];

int CountMinusOne = 0;
int CountZero = 0;
int CountOne = 0;

bool CheckPaper(int R, int C, int Size)
{
    int CurPaper = Paper[R][C];
    
    for(int i = R; i < R + Size; ++i)
    {
        for(int j = C; j < C + Size; ++j)
        {
            if(CurPaper != Paper[i][j])
                return false;
        }
    }
    
    return true;
}

void Recursion(int R, int C, int Size)
{
    if(CheckPaper(R, C, Size))
    {
        int CurPaper = Paper[R][C];
        
        if(CurPaper == -1)
            ++CountMinusOne;
        else if(CurPaper == 0)
            ++CountZero;
        else
            ++CountOne;
        
        return;
    }
    
    else
    {
        int NewSize = Size / 3;
        
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                Recursion(R + i * NewSize, C + j * NewSize, NewSize);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    
    for(int i = 0; i < N; ++i)
         for(int j = 0; j < N; ++j)
             cin >> Paper[i][j];
    
    Recursion(0, 0, N);
    
    cout << CountMinusOne << '\n';
    cout << CountZero << '\n';
    cout << CountOne << '\n';
    
    return 0;
}
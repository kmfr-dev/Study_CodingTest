#include <bits/stdc++.h>
using namespace std;


int Paper[130][130];
int N;
int White = 0;
int Blue = 0;

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
        int Val = Paper[R][C];
        
        if(Val == 0)
            ++White;
        else
            ++Blue;
    }
    
    else
    {
        int NewSize = Size / 2;
        
        for(int i = 0; i < 2; ++i)
        {
            for(int j = 0; j < 2; ++j)
                Recursion(R + i * NewSize, C + j * NewSize, NewSize);
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
    
    cout << White << '\n';
    cout << Blue << '\n';
    
    return 0;
}
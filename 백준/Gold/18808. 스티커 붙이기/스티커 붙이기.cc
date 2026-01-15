#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int Row, Col;
int NoteBook[42][42];
int Rotated[12][12];
int Sticker[12][12];

void Rotate(int R, int C)
{
    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
            Rotated[j][R - 1 - i] = Sticker[i][j];
    
    Row = C;
    Col = R;
    memcpy(Sticker, Rotated, sizeof(Sticker));
}

bool CanAttach(int X, int Y)
{
    for(int i = 0; i < Row; ++i)
    {
        for(int j = 0; j < Col; ++j)
        {
            if(Y + i < 0 || Y + i >= N || X + j < 0 || X + j >= M)
                return false;
            if(Sticker[i][j] == 1 && NoteBook[Y + i][X + j] == 1)
                return false;
        }
    }
    
    return true;
}

void Attach(int X, int Y)
{
    for(int i = 0; i < Row; ++i)
        for(int j = 0; j < Col; ++j)
            if(Sticker[i][j] == 1)
                NoteBook[Y + i][X + j] = 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> K;
    
    while(K--)
    {
        fill(&Rotated[0][0], &Rotated[0][0] + 12 * 12, 0);
        fill(&Sticker[0][0], &Sticker[0][0] + 12 * 12, 0);
        
        cin >> Row >> Col;
        
        for(int i = 0; i < Row; ++i)
            for(int j = 0; j < Col; ++j)
                cin >> Sticker[i][j];
        
        
        bool IsAttach = false;
        for(int i = 0; i < 4; ++i)
        {
            for(int Y = 0; Y <= N - Row; ++Y)
            {
                for(int X = 0; X <= M - Col; ++X)
                {
                    if(CanAttach(X, Y))
                    {
                        IsAttach = true;
                        Attach(X, Y);
                        break;
                    }
                }
                if(IsAttach)
                    break;
            }
            if(IsAttach)
                break;
            
            Rotate(Row, Col);
        }
        
    }
    
    int Answer = 0;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            if(NoteBook[i][j] == 1)
                ++Answer;
    
    cout << Answer;
    
    return 0;
}
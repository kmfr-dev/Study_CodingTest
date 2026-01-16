#include <bits/stdc++.h>
using namespace std;

int N;
int Count = 0;
int Answer = 0;
int Board[22][22];
    
vector<int> Get_Pushed_Line(vector<int>& Line)
{
    vector<int> Temp;
    for(int Num : Line)
        if(Num != 0)
            Temp.emplace_back(Num);
    
    vector<int> Result;
    
    for(int i = 0; i < Temp.size(); ++i)
    {
        if(i + 1 < Temp.size() && Temp[i] == Temp[i + 1])
        {
            Result.emplace_back(Temp[i] * 2);
            ++i;
        }
        
        else
            Result.emplace_back(Temp[i]);
    }
    
    while(Result.size() < N)
       Result.emplace_back(0);  
    
    return Result;
}

void Move(int Dir)
{   
    for(int i = 0; i < N; ++i)
    {
        vector<int> Line;
        for(int j = 0; j < N; ++j)
        {
            if(Dir == 0)
                Line.emplace_back(Board[i][N - 1 - j]);
            else if(Dir == 1)
                Line.emplace_back(Board[N - 1 - j][i]);
            else if(Dir == 2)
                Line.emplace_back(Board[i][j]);
            else if(Dir == 3)
                Line.emplace_back(Board[j][i]);
        }
        
        vector<int> Pushed = Get_Pushed_Line(Line);
        for(int j = 0; j < N; ++j)
        {
            if(Dir == 0)
                Board[i][N - 1 - j] = Pushed[j];
            else if(Dir == 1)
                Board[N - 1 - j][i] = Pushed[j];
            else if(Dir == 2)
                Board[i][j] = Pushed[j];
            else if(Dir == 3)
                Board[j][i] = Pushed[j];
        }
    }
}

void Recursion(int Cnt)
{ 
    for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                Answer = max(Answer, Board[i][j]);
    
    if(Cnt == 5)
    {
        return;
    }
    
    int BackUp[22][22];
    // 백업 배열에 원본을 memcpy
    memcpy(BackUp, Board, sizeof(Board));
    
    for(int Dir = 0; Dir < 4; ++Dir)
    {
        // 해당 방향으로 이동
        Move(Dir);
        // 재귀
        Recursion(Cnt + 1);
        // 재귀 후 되돌리기
        memcpy(Board, BackUp, sizeof(Board));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> Board[i][j];
    
    Recursion(Count);
    cout << Answer;
    
    return 0;
}
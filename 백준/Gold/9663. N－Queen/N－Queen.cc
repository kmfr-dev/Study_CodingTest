#include <bits/stdc++.h>
using namespace std;

int N;
int Count = 0;

bool IsUsed1[17];
bool IsUsed2[17];
bool IsUsed3[17];

void Recursion(int CurCount)
{
    if(CurCount == N)
    {
        ++Count;
        return;
    }
    
    for(int i = 0; i < N; ++i)
    {
        if(IsUsed1[i] || IsUsed2[i + CurCount] || IsUsed3[i - CurCount + N - 1])
            continue;
        
        IsUsed1[i] = true;
        IsUsed2[CurCount + i] = true;
        IsUsed3[i - CurCount + N - 1] = true;
        
        Recursion(CurCount + 1);
        
        IsUsed1[i] = false;
        IsUsed2[CurCount + i] = false;
        IsUsed3[i - CurCount + N - 1] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;    
    
    Recursion(0);
    
    cout << Count;
    
    return 0;
}
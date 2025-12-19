#include <bits/stdc++.h>
using namespace std;

int N, S;
int Arr[25];
int Count = 0;

void Recursion(int Cur, int Total)
{
    if(Cur == N)
    {
        if(Total == S)
            ++Count;
        return;
    }
    
    Recursion(Cur + 1, Total);
    Recursion(Cur + 1, Total + Arr[Cur]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> S;
    
    for(int i = 0; i < N; ++i)
        cin >> Arr[i];
    
    Recursion(0, 0);
    
    if(S == 0)
        --Count;
    
    cout <<  Count;
    
    return 0;
}
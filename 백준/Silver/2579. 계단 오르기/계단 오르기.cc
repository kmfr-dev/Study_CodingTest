#include <iostream>
using namespace std;

int Score[305];
int Stair[305];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    int Total = 0;
    
    for(int i = 1; i <= N; ++i)
    {
        cin >> Score[i];
        Total += Score[i];
    }
    
    if(N <= 2)
    {
        cout << Total;
        return 0;
    }
    
    Stair[1] = Score[1];
    Stair[2] = Score[2];
    Stair[3] = Score[3];
   
    for(int i = 4; i <= N; ++i)
    {
        Stair[i] = min(Stair[i - 2], Stair[i - 3]) + Score[i];
    }
    
    cout << Total - min(Stair[N - 1], Stair[N - 2]);
    
    return 0;
}
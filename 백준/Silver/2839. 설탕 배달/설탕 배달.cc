#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    int Count = 0;
    
    while(N >= 0)
    {
        if(N % 5 == 0)
        {
            Count += N / 5;
            cout << Count;
            return 0;
        }
        
        N -= 3;
        ++Count;
    }
    
    cout << -1;
    
    return 0;
}
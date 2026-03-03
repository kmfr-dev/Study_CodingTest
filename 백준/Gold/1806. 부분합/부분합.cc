#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, S;
    cin >> N >> S;
    
    vector<int> A(N + 5, 0);
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    
    int Start = 0;
    int End = 0;
    int length = INT_MAX;
    
    int Value = 0;
    
    while(End < N)
    {
         Value += A[End];    
        ++End;
        
        while(Value >= S)
        {
            length = min(length, End - Start);
            Value -= A[Start];
            ++Start;
        }
    }
    
    if(length == INT_MAX)
        cout << 0;
    else
        cout << length;
    
    return 0;
}
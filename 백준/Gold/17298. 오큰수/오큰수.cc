#include <iostream>
#include <stack>
using namespace std;

int Arr[1000000];
int Answer[1000000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    stack<int> NumStack;    
    
    for(int i = 0; i < N; ++i)
        cin >> Arr[i]; 
    
    for(int i = N - 1; i >= 0; --i)
    {
        while(!NumStack.empty() && NumStack.top() <= Arr[i])
            NumStack.pop();
        
        if(NumStack.empty())
            Answer[i] = -1;
        else
            Answer[i] = NumStack.top();
        
        NumStack.push(Arr[i]);
    }
    
    for(int i = 0; i < N; ++i)
        cout << Answer[i] << ' ';
 
    return 0;
}

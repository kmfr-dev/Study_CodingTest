#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);    
    
    int N;
    long long Result = 0;
    stack<int> Building;
    
    cin >> N;
    int CurNum;
    while(N--)
    {
        cin >> CurNum;
        while(!Building.empty() && Building.top() <= CurNum)
            Building.pop();
        
        Result += Building.size();
        Building.push(CurNum);
    }
    
    cout << Result << "\n";
    
    return 0;
}
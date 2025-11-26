#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> Cards;
    
    int N;
    cin >> N;
    
    for(int i = 1; i <= N; ++i)
        Cards.push(i);
    
    while(true)
    {
        if(Cards.size() == 1)
            break;
        
        Cards.pop();
       
        if(Cards.size() == 1)
            break;
        
        int Front = Cards.front();
        Cards.pop();
        Cards.push(Front);
    }
    
    cout << Cards.front();
    
    return 0;
}